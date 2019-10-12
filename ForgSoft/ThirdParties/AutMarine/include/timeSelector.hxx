#pragma once
#ifndef _timeSelector_Header
#define _timeSelector_Header

#include <scalarRanges.hxx>

namespace AutLib
{

	// Forward declaration of classes
	class instant;
	class argList;
	class Time;

	class timeSelector
		: public scalarRanges
	{
	
	public:

		// Constructors

		//- Construct Null
		timeSelector();

		//- Construct from Istream
		timeSelector(Istream&);


		// Member Functions

		//- Return true if the given instant is within the ranges
		bool selected(const instant&) const;

		//- Return the set of selected instants in the given list that are
		//  within the ranges
		List<bool> selected(const List<instant>&) const;

		//- Select a list of Time values that are within the ranges
		List<instant> select(const List<instant>&) const;

		//- Select a list of Time values that are within the ranges
		void inplaceSelect(List<instant>&) const;

		//- Add the options handled by timeSelector to argList::validOptions
		//
		// @param constant
		//   Add the @b -constant option to include the @c constant/ directory
		//
		// @param zeroTime
		//   Enable the @b -zeroTime option and alter the normal time selection
		//   behaviour (and @b -latestTime behaviour) to exclude the @c 0/
		//   directory. The @c 0/ directory will only be included when
		//   @b -zeroTime is specified.
		//   The @b -noZero option has precedence over the @b -zeroTime option.
		static void addOptions
		(
			const bool constant = true,
			const bool zeroTime = false
		);

		//- Return the set of times selected based on the argList options
		static List<instant> select
		(
			const List<instant>&,
			const argList& args
		);

		//- Return the set of times selected based on the argList options
		//  also set the runTime to the first instance
		static List<instant> select0
		(
			Time& runTime,
			const argList& args
		);
	};
}

#endif // !_timeSelector_Header
