#pragma once
/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | foam-extend: Open Source CFD
   \\    /   O peration     | Version:     4.0
	\\  /    A nd           | Web:         http://www.foam-extend.org
	 \\/     M anipulation  | For copyright notice see file Copyright
-------------------------------------------------------------------------------
License
	This file is part of foam-extend.

	foam-extend is free software: you can redistribute it and/or modify it
	under the terms of the GNU General Public License as published by the
	Free Software Foundation, either version 3 of the License, or (at your
	option) any later version.

	foam-extend is distributed in the hope that it will be useful, but
	WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
	General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with foam-extend.  If not, see <http://www.gnu.org/licenses/>.

Class
	tnbLib::timeSelector

Description
	A List of scalarRange for selecting times.

	The timeSelector provides a convenient means of selecting multiple
	times. A typical use would be the following:

	@verbatim
	timeSelector::addOptions();
	// add other options
	#include "setRootCase.H"
	#include "createTime.H"
	instantList timeDirs = timeSelector::select0(runTime, args);
	...
	forAll(timeDirs, timeI)
	{
		...
	}
	@endverbatim

	The result program would receive @b -time, @b -latestTime, @b -constant
	and @b -noZero options. The @b -constant option explicitly includes the
	@c constant/ directory in the time list and the @b -noZero option
	explicitly excludes the @c 0/ directory from the time list.

	There may however also be many cases in which neither the @c constant/
	directory nor the @c 0/ directory contain particularly relevant
	information. This might occur, for example, when post-processing
	results. In this case, addOptions is called with optional boolean
	arguments.

	@verbatim
	timeSelector::addOptions(false, true);
	@endverbatim

	The first argument avoids adding the @b -constant option. The second
	argument adds an additional @b -zeroTime option and also prevents the
	@c 0/ directory from being included in the default time range and in the
	@b -latestTime selection.

SourceFiles
	timeSelector.C

\*---------------------------------------------------------------------------*/
#ifndef _timeSelector_Header
#define _timeSelector_Header

#include <scalarRanges.hxx>
#include <instant.hxx>

namespace tnbLib
{

	// Forward declaration of classes
	class argList;
	class Time;

	/*---------------------------------------------------------------------------*\
							Class timeSelector Declaration
	\*---------------------------------------------------------------------------*/

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


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
}

#endif // !_timeSelector_Header