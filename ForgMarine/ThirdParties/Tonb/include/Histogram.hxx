#pragma once
#ifndef _Histogram_Header
#define _Histogram_Header

#include <labelList.hxx>

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
						  Class Histogram Declaration
\*---------------------------------------------------------------------------*/

	template<class List>
	class Histogram
	{
		// Private data

			//- Counts per bin
		labelList counts_;

		//- Number of <= lowest bin
		label nLow_;

		//- Number of > highest bin
		label nHigh_;


		// Private Member Functions

		void count(const List& bins, const List& l);

		//- Disallow default bitwise copy construct
		Histogram(const Histogram&);

		//- Disallow default bitwise assignment
		void operator=(const Histogram&);


	public:

		// Constructors

			//- Construct given bin values and input list
		Histogram(const List& bins, const List& l);

		//- Construct given min, max, number of bins and input list
		Histogram
		(
			const typename List::const_reference min,
			const typename List::const_reference max,
			const label nBins,
			const List& l
		);


		// Access

			//- Return the counts per bin
		const labelList& counts() const
		{
			return counts_;
		}

		//- Return the number of elements <= bins[0]
		//  (so inclusive lowest bin value)
		label nLow() const
		{
			return nLow_;
		}

		//- Return the number of elements > bins[bins.size()-1]
		//  (so exclusive highest bin value)
		label nHigh() const
		{
			return nHigh_;
		}
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
}

#include <HistogramI.hxx>

#ifdef NoRepository
#   include <Histogram.cxx>
#endif

#endif // !_Histogram_Header
