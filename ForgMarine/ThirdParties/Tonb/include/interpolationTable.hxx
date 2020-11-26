#pragma once
#ifndef _interpolationTable_Header
#define _interpolationTable_Header

#include <List.hxx>
#include <Tuple2.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
						Class interpolationTable Declaration
	\*---------------------------------------------------------------------------*/

	template<class Type>
	class interpolationTable
		: public List<Tuple2<scalar, Type> >
	{
	public:

		// Public data types

			//- Enumeration for handling out-of-bound values
		enum boundsHandling
		{
			EXIT,          /*!< Exit with a FatalError */
			WARN,           /*!< Issue warning and clamp value (default) */
			CLAMP,          /*!< Clamp value to the start/end value */
			REPEAT          /*!< Treat as a repeating list */
		};


	private:

		// Private data

			//- Enumeration for handling out-of-bound values
		boundsHandling boundsHandling_;

		//- File name
		fileName fileName_;


		// Private Member Functions

			//- Read the table of data from file
		void readTable();


	public:

		// Constructors

			//- Construct null
		interpolationTable();

		//- Construct from components
		interpolationTable
		(
			const List<Tuple2<scalar, Type> >& values,
			const boundsHandling bounds,
			const fileName& fName
		);

		//- Construct given the name of the file containing the table of data
		interpolationTable(const fileName& fName);

		//- Construct by reading the fileName and boundsHandling
		//  from dictionary and read the table from that file.
		//  This is a specialised constructor used by patchFields
		interpolationTable(const dictionary& dict);

		//- Construct copy
		interpolationTable(const interpolationTable& interpTable);


		// Member Functions

			//- Return the out-of-bounds handling as a word
		word boundsHandlingToWord(const boundsHandling& bound) const;

		//- Return the out-of-bounds handling as an enumeration
		boundsHandling wordToBoundsHandling(const word& bound) const;

		//- Set the out-of-bounds handling from enum, return previous setting
		boundsHandling outOfBounds(const boundsHandling& bound);

		//- Check that list is monotonically increasing
		//  Exit with a FatalError if there is a problem
		void check() const;

		//- Write
		void write(Ostream& os) const;


		// Member Operators

			//- Return an element of constant Tuple2<scalar, Type>
		const Tuple2<scalar, Type>& operator[](const label) const;

		//- Return an interpolated value
		Type operator()(const scalar) const;
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#   include <interpolationTable.cxx>
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_interpolationTable_Header
