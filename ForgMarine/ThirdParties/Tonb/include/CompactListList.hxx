#pragma once
#ifndef _CompactListList_Header
#define _CompactListList_Header

#include <labelList.hxx>

namespace tnbLib
{

	// Forward declaration of friend functions and operators

	template<class T> class CompactListList;

	template<class T> Istream& operator>>(Istream&, CompactListList<T>&);
	template<class T> Ostream& operator<<(Ostream&, const CompactListList<T>&);


	/*---------------------------------------------------------------------------*\
						   Class CompactListList Declaration
	\*---------------------------------------------------------------------------*/

	template<class T>
	class CompactListList
	{
		// Private data

			//- Offset table
		List<label> offsets_;

		//- Packed matrix of data
		List<T> m_;


	public:

		// Static Member Functions

			//- Return a null CompactListList
		static const CompactListList<T>& null();

		// Constructors

			//- Null constructor.
		CompactListList();

		//- Construct by converting given List<List<T>>
		CompactListList(const List<List<T>>&);

		//- Construct given size of offset table (number of rows)
		//  and number of data.
		CompactListList(const label nRows, const label nData);

		//- Construct given size of offset table (number of rows),
		//  the number of data and a value for all elements.
		CompactListList(const label nRows, const label nData, const T&);

		//- Construct given list of row-sizes.
		CompactListList(const UList<label>& rowSizes);

		//- Construct given list of row-sizes
		CompactListList(const UList<label>& rowSizes, const T&);

		//- Construct by transferring the parameter contents
		CompactListList(const Xfer<CompactListList<T>>&);

		//- Construct as copy or re-use as specified.
		CompactListList(CompactListList<T>&, bool reUse);

		//- Construct from Istream.
		CompactListList(Istream&);

		//- Clone
		autoPtr<CompactListList<T>> clone() const;


		// Member Functions

			// Access

				//- Return the primary size, i.e. the number of rows
		label size() const;

		//- Return true if the number of rows is zero
		bool empty() const;

		//- Return the offset table
		const List<label>& offsets() const;

		//- Return non-const access to the offset table
		List<label>& offsets();

		//- Return the packed matrix of data
		const List<T>& m() const;

		//- Return non-const access to the packed matrix of data
		List<T>& m();


		// Edit

			//- Reset size of CompactListList.
			//  This form only allows contraction of the CompactListList.
		void setSize(const label nRows);

		//- Reset size of CompactListList.
		void setSize(const label nRows, const label nData);

		//- Reset sizes of CompactListList and value for new elements.
		void setSize(const label nRows, const label nData, const T&);

		//- Reset size of CompactListList.
		void setSize(const UList<label>& rowSizes);

		//- Reset size of CompactListList.
		//  This form only allows contraction of the CompactListList.
		void resize(const label nRows);

		//- Reset size of CompactListList.
		void resize(const label nRows, const label nData);

		//- Reset sizes of CompactListList and value for new elements.
		void resize(const label nRows, const label nData, const T&);

		//- Reset size of CompactListList.
		void resize(const UList<label>& rowSizes);

		//- Clear the CompactListList, i.e. set sizes to zero.
		void clear();

		//- Return sizes (to be used e.g. for construction)
		labelList sizes() const;

		//- Transfer the contents of the argument CompactListList
		//  into this CompactListList and annull the argument list.
		void transfer(CompactListList<T>&);

		//- Transfer the contents to the Xfer container
		Xfer<CompactListList<T>> xfer();

		// Other

			//- Return index into m
		label index(const label row, const label col) const;

		//- Get row for index into m.
		label whichRow(const label index) const;

		//- Get column index (j) given above row
		label whichColumn(const label row, const label index) const;


		// Member operators

			//- Return subscript-checked row as UList.
		UList<T> operator[](const label i);

		//- Return const subscript-checked row as UList.
		const UList<T> operator[](const label i) const;

		//- Return subscript-checked element.
		T& operator()(const label i, const label j);

		//- Return const subscript-checked element.
		const T& operator()(const label i, const label j) const;

		//- Return as List<List<T>>
		List<List<T>> operator()() const;

		//- Assignment of all entries to the given value
		void operator=(const T&);


		// Istream operator

			//- Read CompactListList from Istream, discarding contents
			//  of existing CompactListList.
		friend Istream& operator>> <T>(Istream&, CompactListList<T>&);

		// Write CompactListList to Ostream.
		friend Ostream& operator<< <T>(Ostream&, const CompactListList<T>&);
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
}

#include <CompactListListI.hxx>

#ifdef NoRepository
#   include <CompactListList.cxx>
#endif

#endif // !_CompactListList_Header
