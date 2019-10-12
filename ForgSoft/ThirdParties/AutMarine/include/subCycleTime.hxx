#pragma once
#ifndef _subCycleTime_Header
#define _subCycleTime_Header

#include <autTime.hxx>

namespace AutLib
{

	class subCycleTime
	{
		// Private data

		Time& time_;

		label nSubCycles_;
		label subCycleIndex_;

	public:

		// Constructors

		//- Construct from original time and number of sub-cycles
		subCycleTime(Time&, const label nSubCycles);


		// Destructor

		~subCycleTime();


		// Member functions

		//- Return true if the number of sub-cycles has been reached
		bool end() const;

		//- End the sub-cycling and reset the time-state
		void endSubCycle();


		// Member operators

		//- Prefix increment
		subCycleTime& operator++();

		//- Postfix increment
		subCycleTime& operator++(int);
	};
}

#endif // !_subCycleTime_Header
