#pragma once
#include <iostream>
#include <iomanip>
template<class T>
inline void AutLib::debug::controlSwitches<T>::operator=(const T& rhs)
{
	switchValue_ = rhs;
}


template<class T>
inline const T AutLib::debug::controlSwitches<T>::operator&(const T& rhs)
{
	return switchValue_ & rhs;
}

template<class T>
inline bool AutLib::operator==(const debug::controlSwitches<T>& lhs, const debug::controlSwitches<T>& rhs)
{
	return lhs() == rhs();
}


template<class T>
inline bool AutLib::operator==(const T& lhs, const debug::controlSwitches<T>& rhs)
{
	return lhs == rhs();
}


template<class T>
inline bool AutLib::operator==(const debug::controlSwitches<T>& lhs, const T& rhs)
{
	return lhs() == rhs;
}


template<class T>
inline bool AutLib::operator!=(const debug::controlSwitches<T>& lhs, const debug::controlSwitches<T>& rhs)
{
	return lhs() != rhs();
}


template<class T>
inline bool AutLib::operator!=(const T& lhs, const debug::controlSwitches<T>& rhs)
{
	return lhs != rhs();
}


template<class T>
inline bool AutLib::operator!=(const debug::controlSwitches<T>& lhs, const T& rhs)
{
	return lhs() != rhs;
}


template<class T>
inline bool AutLib::operator>=(const debug::controlSwitches<T>& lhs, const debug::controlSwitches<T>& rhs)
{
	return lhs() >= rhs();
}


template<class T>
inline bool AutLib::operator>=(const T& lhs, const debug::controlSwitches<T>& rhs)
{
	return lhs >= rhs();
}


template<class T>
inline bool AutLib::operator>=(const debug::controlSwitches<T>& lhs, const T& rhs)
{
	return lhs() >= rhs;
}


template<class T>
inline bool AutLib::operator>(const debug::controlSwitches<T>& lhs, const debug::controlSwitches<T>& rhs)
{
	return lhs() > rhs();
}


template<class T>
inline bool AutLib::operator>(const T& lhs, const debug::controlSwitches<T>& rhs)
{
	return lhs > rhs();
}


template<class T>
inline bool AutLib::operator>(const debug::controlSwitches<T>& lhs, const T& rhs)
{
	return lhs() > rhs;
}


template<class T>
inline bool AutLib::operator<=(const debug::controlSwitches<T>& lhs, const debug::controlSwitches<T>& rhs)
{
	return lhs() <= rhs();
}


template<class T>
inline bool AutLib::operator<=(const T& lhs, const debug::controlSwitches<T>& rhs)
{
	return lhs <= rhs();
}


template<class T>
inline bool AutLib::operator<=(const debug::controlSwitches<T>& lhs, const T& rhs)
{
	return lhs() <= rhs;
}


template<class T>
inline bool AutLib::operator<(const debug::controlSwitches<T>& lhs, const debug::controlSwitches<T>& rhs)
{
	return lhs() < rhs();
}


template<class T>
inline bool AutLib::operator<(const T& lhs, const debug::controlSwitches<T>& rhs)
{
	return lhs < rhs();
}


template<class T>
inline bool AutLib::operator<(const debug::controlSwitches<T>& lhs, const T& rhs)
{
	return lhs() < rhs;
}

template<class T>
inline AutLib::debug::controlSwitches<T>::controlSwitches
(
	const std::string & switchName,
	const T & switchValue, 
	const std::string & switchDescription,
	globalControlDictSwitchSet switchSet, 
	std::map<std::string, std::list<controlSwitches<T>*>>** switchValuesTable
)
	: switchSet_(switchSet)
	, switchName_(switchName)
	, switchValue_(switchValue)
	, switchDescription_(switchDescription)
{
	// Register the switch in its list
	if (*switchValuesTable == NULL)
	{
		*switchValuesTable =
			new std::map<std::string, std::list<controlSwitches<T> *> >();
	}

	switchValuesTable_ = *switchValuesTable;
	std::map<std::string, std::list<controlSwitches<T> *> >& switchValues = *switchValuesTable_;

	// Memorize this switch object address
	if (switchValues.find(switchName) != switchValues.end())
	{
		switchValues[switchName].push_back(this);
	}
	else
	{
		std::list<controlSwitches<T>* > pList;
		pList.push_back(this);

		switchValues.insert
		(
			std::pair<std::string, std::list<controlSwitches<T>*>> (switchName, pList)
		);
	}
}

template<class T>
inline AutLib::debug::controlSwitches<T>::~controlSwitches()
{
	// Unregister the switch from its list
	if (switchValuesTable_)
	{
		std::map<std::string, std::list<controlSwitches<T> *>>& switchValuesTable = *switchValuesTable_;

		// Remove entry or key if pointers list is empty
		switchValuesTable[switchName_].remove(this);

		// Replace the updated list
		if (switchValuesTable[switchName_].empty())
		{
			switchValuesTable.erase(switchName_);
		}
	}

	if (switchValuesTable_->empty()) delete switchValuesTable_;
}

namespace AutLib
{
	namespace debug
	{
		template<class T>
		void printControlSwitches
		(
			const std::string& dictName,
			const std::map<std::string, std::list<debug::controlSwitches<T>*>>* mapListSwitchesPtr, const char* commsTypesNames[]
		)
		{
			std::cout << dictName << "\n{\n";

			if (mapListSwitchesPtr)
			{
				const std::map<std::string, std::list<debug::controlSwitches<T> *>>& mapListSwitches = *mapListSwitchesPtr;

				typename std::map<std::string, std::list<debug::controlSwitches<T>*>>::const_iterator it;

				// Compute the maximum length of the switches names.
				// Trying to make things pretty with std::setw by lining-up the values.
				// Useful for the debugSwitches because non-zero flags will be much
				// easier to spot.
				std::size_t maxLengthKey = 0;

				for (it = mapListSwitches.begin(); it != mapListSwitches.end(); it++)
				{
					std::string switchName = it->first;
					maxLengthKey = std::max(maxLengthKey, switchName.length());
				}

				// Still, we clip at 60 characters max.
				maxLengthKey = std::min(maxLengthKey, size_t(60));

				for (it = mapListSwitches.begin(); it != mapListSwitches.end(); it++)
				{
					// Switch name
					std::string switchName = it->first;

					// Switches list, all identical values, but from
					// different instances.
					// So we only need to echo the first switch of the list.
					std::list<debug::controlSwitches<T> *> swList = it->second;
					debug::controlSwitches<T>& value = *(swList.front());

					std::cout
						<< "    " << std::left << std::setw(maxLengthKey)
						<< switchName << " ";

					// Special handling for commsTypes from optimisationSwitches
					if (commsTypesNames && switchName.compare("commsType") == 0)
					{
						int valEnumAsIndex = (int)value();

						std::cout << commsTypesNames[valEnumAsIndex] << ";";
					}
					else
					{
						std::cout << value() << ";";
					}

					// Now, for the switch description, since numerous switches might
					// be defined with identical names, but different descriptions
					// eg: ggi debugSwitch, we will concatenate all the non-empty
					// switches descriptions for a given switch

					std::string switchDescription("");

					typename std::list<debug::controlSwitches<T> *>::iterator itL;

					for (itL = swList.begin(); itL != swList.end(); itL++)
					{
						debug::controlSwitches<T>& sw = *(*itL);
						std::string thisSwitchDescr = sw.switchDescription();

						if (!thisSwitchDescr.empty() && switchDescription.find(thisSwitchDescr) == std::string::npos)
						{
							switchDescription += thisSwitchDescr + ". ";
						}
					}

					if (!switchDescription.empty())
					{
						std::cout << "\t// " << switchDescription;
					}
					std::cout << std::endl;
				}
			}
			else
			{
				std::cout
					<< "    // No switches of this type for this application"
					<< std::endl;
			}

			std::cout << "}\n\n";
		}
	}
}