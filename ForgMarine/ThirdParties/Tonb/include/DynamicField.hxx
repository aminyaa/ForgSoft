#pragma once
#ifndef _DynamicField_Header
#define _DynamicField_Header

#include <Field.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// Forward declaration of friend functions and operators

	template<class T, unsigned SizeInc, unsigned SizeMult, unsigned SizeDiv>
	class DynamicField;

	template<class T, unsigned SizeInc, unsigned SizeMult, unsigned SizeDiv>
	Ostream& operator<<
		(
			Ostream&,
			const DynamicField<T, SizeInc, SizeMult, SizeDiv>&
			);
	template<class T, unsigned SizeInc, unsigned SizeMult, unsigned SizeDiv>
	Istream& operator>>
		(
			Istream&,
			DynamicField<T, SizeInc, SizeMult, SizeDiv>&
			);


	/*---------------------------------------------------------------------------*\
							   Class DynamicField Declaration
	\*---------------------------------------------------------------------------*/

	template<class T, unsigned SizeInc = 0, unsigned SizeMult = 2, unsigned SizeDiv = 1>
	class DynamicField
		: public Field<T>
	{
		// Private data

			//- The capacity (allocated size) of the underlying field.
		label capacity_;


	public:

		// Static Member Functions

			//- Return a null field
		static const DynamicField<T, SizeInc, SizeMult, SizeDiv>& null()
		{
			return *reinterpret_cast
				<
				DynamicField<T, SizeInc, SizeMult, SizeDiv>*
				>(0);
		}


		// Constructors

			//- Construct null
		DynamicField();

		//- Construct given size.
		explicit DynamicField(const label);

		//- Construct from UList. Size set to UList size.
		//  Also constructs from DynamicField with different sizing parameters.
		explicit DynamicField(const UList<T>&);

		//- Construct by transferring the parameter contents
		explicit DynamicField(const Xfer<List<T> >&);

		//- Construct by 1 to 1 mapping from the given field
		DynamicField
		(
			const UList<T>& mapF,
			const labelList& mapAddressing
		);

		//- Construct by interpolative mapping from the given field
		DynamicField
		(
			const UList<T>& mapF,
			const labelListList& mapAddressing,
			const scalarListList& weights
		);

		//- Construct by mapping from the given field
		DynamicField
		(
			const UList<T>& mapF,
			const FieldMapper& map
		);

		//- Construct copy
		DynamicField(const DynamicField<T, SizeInc, SizeMult, SizeDiv>&);

		//- Construct by transferring the Field contents
		DynamicField
		(
			const Xfer<DynamicField<T, SizeInc, SizeMult, SizeDiv> >&
		);

		//- Construct from Istream. Size set to size of list read.
		explicit DynamicField(Istream&);

		//- Clone
		tmp<DynamicField<T, SizeInc, SizeMult, SizeDiv> > clone() const;


		// Member Functions

			// Access

				//- Size of the underlying storage.
		label capacity() const;

		// Edit

			//- Alter the size of the underlying storage.
			//  The addressed size will be truncated if needed to fit, but will
			//  remain otherwise untouched.
			//  Use this or reserve() in combination with append().
		void setCapacity(const label);

		//- Alter the addressed list size.
		//  New space will be allocated if required.
		//  Use this to resize the list prior to using the operator[] for
		//  setting values (as per List usage).
		void setSize(const label);

		//- Alter the addressed list size and fill new space with a
		//  constant.
		void setSize(const label, const T&);

		//- Alter the addressed list size.
		//  New space will be allocated if required.
		//  Use this to resize the list prior to using the operator[] for
		//  setting values (as per List usage).
		void resize(const label);

		//- Alter the addressed list size and fill new space with a
		//  constant.
		void resize(const label, const T&);

		//- Reserve allocation space for at least this size.
		//  Never shrinks the allocated size, use setCapacity() for that.
		void reserve(const label);

		//- Clear the addressed list, i.e. set the size to zero.
		//  Allocated size does not change
		void clear();

		//- Clear the list and delete storage.
		void clearStorage();

		//- Shrink the allocated space to the number of elements used.
		//  Returns a reference to the DynamicField.
		DynamicField<T, SizeInc, SizeMult, SizeDiv>& shrink();

		//- Transfer contents to the Xfer container as a plain List
		Xfer<List<T> > xfer();


		// Member Operators

			//- Append an element at the end of the list
		DynamicField<T, SizeInc, SizeMult, SizeDiv>& append
		(
			const T&
		);

		//- Append a List at the end of this list
		DynamicField<T, SizeInc, SizeMult, SizeDiv>& append
		(
			const UList<T>&
		);

		//- Remove and return the top element
		T remove();

		//- Return non-const access to an element, resizing list if
		//  necessary
		T& operator()(const label);

		//- Assignment of all addressed entries to the given value
		void operator=(const T&);

		//- Assignment from DynamicField
		void operator=
			(
				const DynamicField<T, SizeInc, SizeMult, SizeDiv>&
				);

		//- Assignment from UList
		void operator=(const UList<T>&);


		// IOstream operators

			//HJ, this does not compile with Icc.  Cannot figure it out
			// HJ, 11/Nov/2010

//             //- Write DynamicField to Ostream.
//             friend Ostream& operator<< <T, SizeInc, SizeMult, SizeDiv>
//             (
//                 Ostream&,
//                 const DynamicField<T, SizeInc, SizeMult, SizeDiv>&
//             );

//             //- Read from Istream, discarding contents of existing DynamicField.
//             friend Istream& operator>> <T, SizeInc, SizeMult, SizeDiv>
//             (
//                 Istream&,
//                 DynamicField<T, SizeInc, SizeMult, SizeDiv>&
//             );
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include <DynamicFieldI.hxx>

#endif // !_DynamicField_Header
