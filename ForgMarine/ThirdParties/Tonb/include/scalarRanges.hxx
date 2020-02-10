#pragma once
#ifndef _scalarRanges_Header
#define _scalarRanges_Header

#include <scalarRange.hxx>
#include <List.hxx>

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
					   Class scalarRanges Declaration
\*---------------------------------------------------------------------------*/

	class scalarRanges
		: public List<scalarRange>
	{
	public:

		// Constructors

			//- Construct Null
		scalarRanges();

		//- Construct from Istream.
		//  The list items are comma-delimited.
		scalarRanges(Istream&);

		// Member Functions

			//- Return true if the given value is within the ranges
		bool selected(const scalar&) const;

		//- Return the set of selected entries in the given list
		//  that are within the ranges
		List<bool> selected(const List<scalar>&) const;

		//- Select a list of values that are within the ranges
		List<scalar> select(const List<scalar>&) const;

		//- Select a list of values that are within the ranges
		void inplaceSelect(List<scalar>&) const;
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
}

#endif // !_scalarRanges_Header
