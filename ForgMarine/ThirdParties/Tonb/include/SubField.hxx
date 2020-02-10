#pragma once
#ifndef _SubField_Header
#define _SubField_Header

#include <SubList.hxx>
#include <Field.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	//- Pre-declare SubField and related Field type
	template<class Type> class Field;
	template<class Type> class SubField;

	/*---------------------------------------------------------------------------*\
							   Class SubField Declaration
	\*---------------------------------------------------------------------------*/

	template<class Type>
	class SubField
		: public refCount
		, public SubList<Type>
	{

	public:

		//- Component type
		typedef typename pTraits<Type>::cmptType cmptType;


		// Static Member Functions

			//- Return a null SubField
			//  Dangerous, but no null constructor.  Reconsider.  HJ, 10/Apr/2013
		static const SubField<Type>& null();


		// Constructors

			//- Construct from a SubList
		SubField(const SubList<Type>&);

		//- Construct from a UList\<Type\>, using the entire size
		explicit SubField(const UList<Type>&);

		//- Construct from a UList\<Type\> with a given size
		SubField
		(
			const UList<Type>& list,
			const label subSize
		);

		//- Construct from a UList\<Type\> with a given size and start index
		SubField
		(
			const UList<Type>& list,
			const label subSize,
			const label startIndex
		);

		//- Construct as copy
		SubField(const SubField<Type>&);


		// Member functions

			//- Return a component field of the field
		tmp<Field<cmptType> > component(const direction) const;

		//- Return the field transpose (only defined for second rank tensors)
		tmp<Field<Type> > T() const;


		// Member operators

			//- Assignment via UList operator. Takes linear time.
		void operator=(const SubField<Type>&);

		//- Allow cast to a const Field\<Type\>&
		operator const Field<Type>&() const;
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include <SubFieldI.hxx>

#endif // !_SubField_Header
