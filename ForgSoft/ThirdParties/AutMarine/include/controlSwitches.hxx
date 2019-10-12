#pragma once
#ifndef _controlSwitches_Header
#define _controlSwitches_Header

#include <scalar.hxx>
#include <debug.hxx>
#include <safeBool.hxx>

#include <map>
#include <list>
#include <string>

namespace AutLib
{

	// Forward declaration of classes
	namespace debug
	{
		template<class T> class controlSwitches;
	}

	template<class T>
	inline bool operator==
		(
			const debug::controlSwitches<T>& lhs,
			const debug::controlSwitches<T>& rhs
			);

	template<class T>
	inline bool operator==
		(
			const T& lhs,
			const debug::controlSwitches<T>& rhs
			);

	template<class T>
	inline bool operator==
		(
			const debug::controlSwitches<T>& lhs,
			const T& rhs
			);

	template<class T>
	inline bool operator!=
		(
			const debug::controlSwitches<T>& lhs,
			const debug::controlSwitches<T>& rhs
			);

	template<class T>
	inline bool operator!=
		(
			const T& lhs,
			const debug::controlSwitches<T>& rhs
			);

	template<class T>
	inline bool operator!=
		(
			const debug::controlSwitches<T>& lhs,
			const T& rhs
			);

	template<class T>
	inline bool operator>=
		(
			const debug::controlSwitches<T>& lhs,
			const debug::controlSwitches<T>& rhs
			);

	template<class T>
	inline bool operator>=
		(
			const T& lhs,
			const debug::controlSwitches<T>& rhs
			);

	template<class T>
	inline bool operator>=
		(
			const debug::controlSwitches<T>& lhs,
			const T& rhs
			);

	template<class T>
	inline bool operator>
		(
			const debug::controlSwitches<T>& lhs,
			const debug::controlSwitches<T>& rhs
			);

	template<class T>
	inline bool operator>
		(
			const T& lhs,
			const debug::controlSwitches<T>& rhs
			);

	template<class T>
	inline bool operator>
		(
			const debug::controlSwitches<T>& lhs,
			const T& rhs
			);

	template<class T>
	inline bool operator<=
		(
			const debug::controlSwitches<T>& lhs,
			const debug::controlSwitches<T>& rhs
			);

	template<class T>
	inline bool operator<=
		(
			const T& lhs,
			const debug::controlSwitches<T>& rhs
			);

	template<class T>
	inline bool operator<=
		(
			const debug::controlSwitches<T>& lhs,
			const T& rhs
			);

	template<class T>
	inline bool operator<
		(
			const debug::controlSwitches<T>& lhs,
			const debug::controlSwitches<T>& rhs
			);

	template<class T>
	inline bool operator<
		(
			const T& lhs,
			const debug::controlSwitches<T>& rhs
			);

	template<class T>
	inline bool operator<
		(
			const debug::controlSwitches<T>&lhs,
			const T& rhs
			);

	namespace debug
	{

		template<class T>
		class controlSwitches
			: public safeBool<controlSwitches<T>>
		{

			// Private data

			//- Switch section
			globalControlDictSwitchSet switchSet_;

			//- Switch name
			std::string switchName_;

			//- Switch value
			T switchValue_;

			//- Switch Description
			std::string switchDescription_;

			//- Handle to runTime switches list
			std::map<std::string, std::list<controlSwitches<T> *> >*
				switchValuesTable_;


			// Private member functions

			//- Disallow construct as copy
			controlSwitches(const controlSwitches<T>&) = delete;

			//- Disallow default bitwise assignment
			void operator=(const controlSwitches<T>&) = delete;

		public:

			controlSwitches
			(
				const std::string& switchName,
				const T& switchValue,
				const std::string& switchDescription,
				globalControlDictSwitchSet switchSet,
				std::map<std::string, std::list<controlSwitches<T> *> >**
				switchesValues
			);


			//- Destructor
			~controlSwitches();


			// Member Functions

			// Check
			bool test() const
			{
				// Perform Boolean logic here
				return switchValue_ != 0;
			}


			// Member Operators

			//- Assignement operator
			void operator=(const T&);

			//- & operator
			const T operator&(const T&);

			//- Return value
			inline T operator()() const
			{
				return switchValue_;
			}

			// Return switch name
			inline std::string switchName()
			{
				return switchName_;
			}

			//- Return switch description
			inline std::string switchDescription()
			{
				return switchDescription_;
			}
		};


		// Print the content of a controlSwitches list to the console.
		// We are forced to pass the string descriptions of the Pstream::commsTypes
		// when dealing with the optimisationSwitches group because this switch is in
		// fact an enum but we need to specify its corresponding string equivalent in
		// a controlDict dictionary. And at the low level we are playing, including
		// Pstream.H is out of the question.
		// MB 2015
		template<class T>
		void printControlSwitches
		(
			const std::string&,
			const std::map<std::string, std::list<debug::controlSwitches<T> *> >*,
			const char* commsTypesNames[] = NULL

		);
	}
}

#include <controlSwitchesI.hxx>

#endif // !_controlSwitches_Header
