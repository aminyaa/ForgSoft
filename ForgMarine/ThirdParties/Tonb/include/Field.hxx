#pragma once
#ifndef _Field_Header
#define _Field_Header

#include <tmp.hxx>
#include <direction.hxx>
#include <VectorSpace.hxx>
#include <scalarList.hxx>
#include <labelList.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// Forward declaration of friend functions and operators

	template<class Type>
	class Field;

	//- Pre-declare related SubField type
	template<class Type>
	class SubField;

	template<class Type>
	Ostream& operator<<(Ostream&, const Field<Type>&);

	template<class Type>
	Ostream& operator<<(Ostream&, const tmp<Field<Type>>&);

	class FieldMapper;
	class dictionary;

	/*---------------------------------------------------------------------------*\
							   Class Field Declaration
	\*---------------------------------------------------------------------------*/

	template<class Type>
	class Field
		: public refCount
		, public List<Type>
	{

	public:

		typedef List<Type> base;

		//- Component type
		typedef typename pTraits<Type>::cmptType cmptType;

		//- Declare type of subField
		typedef SubField<Type> subField;


		// Static data members

		static const char* const typeName;

		//- Empty field
		static const Field<Type> zero;


		// Static Member Functions

			//- Return a null field
		inline static const Field<Type>& null()
		{
			return zero;
		}


		// Constructors

			//- Construct null
			//  Used for temporary fields which are initialised after construction
		Field();

		//- Construct given size
		//  Used for temporary fields which are initialised after construction
		explicit Field(const label);

		//- Construct given size and initial value
		Field(const label, const Type&);

		//- Construct as copy of a UList\<Type\>
		explicit Field(const UList<Type>&);

		//- Construct by transferring the List contents
		explicit Field(const Xfer<List<Type>>&);

		//- Construct by 1 to 1 mapping from the given field
		Field
		(
			const UList<Type>& mapF,
			const unallocLabelList& mapAddressing
		);

		//- Construct by 1 to 1 mapping from the given tmp field
		Field
		(
			const tmp<Field<Type>>& tmapF,
			const unallocLabelList& mapAddressing
		);

		//- Construct by interpolative mapping from the given field
		Field
		(
			const UList<Type>& mapF,
			const labelListList& mapAddressing,
			const scalarListList& weights
		);

		//- Construct by interpolative mapping from the given tmp field
		Field
		(
			const tmp<Field<Type>>& tmapF,
			const labelListList& mapAddressing,
			const scalarListList& weights
		);

		//- Construct by mapping from the given field
		Field
		(
			const UList<Type>& mapF,
			const FieldMapper& map
		);

		//- Construct by mapping from the given tmp field
		Field
		(
			const tmp<Field<Type>>& tmapF,
			const FieldMapper& map
		);

		//- Construct as copy
		Field(const Field<Type>&);

		//- Construct as copy or re-use as specified.
		Field(Field<Type>&, bool reUse);

		//- Construct by transferring the Field contents
		Field(const Xfer<Field<Type>>&);

		//- Construct as copy of subField
		Field(const typename Field<Type>::subField&);

		//- Construct as copy of tmp<Field>
#       ifdef ConstructFromTmp
		Field(const tmp<Field<Type>>&);
#       endif

		//- Construct from Istream
		Field(Istream&);

		//- Construct from a dictionary entry
		Field(const word& keyword, const dictionary& dict, const label size);

		//- Clone
		tmp<Field<Type>> clone() const;

		//- Return a pointer to a new Field created on freestore
		static autoPtr<Field<Type>> New(Istream& is)
		{
			return autoPtr<Field<Type>>(new Field<Type>(is));
		}

		//- Return a pointer to a new calculatedFvPatchFieldField created on
		//  freestore without setting patchField values
		template<class Type2>
		static tmp<Field<Type>> NewCalculatedType(const Field<Type2>& f)
		{
			return tmp<Field<Type>>(new Field<Type>(f.size()));
		}


		// Member Functions

			//- 1 to 1 map from the given field
		void map
		(
			const UList<Type>& mapF,
			const unallocLabelList& mapAddressing
		);

		//- 1 to 1 map from the given tmp field
		void map
		(
			const tmp<Field<Type>>& tmapF,
			const unallocLabelList& mapAddressing
		);

		//- Interpolative map from the given field
		void map
		(
			const UList<Type>& mapF,
			const labelListList& mapAddressing,
			const scalarListList& weights
		);

		//- Interpolative map from the given tmp field
		void map
		(
			const tmp<Field<Type>>& tmapF,
			const labelListList& mapAddressing,
			const scalarListList& weights
		);

		//- Map from the given field
		void map
		(
			const UList<Type>& mapF,
			const FieldMapper& map
		);

		//- Map from the given tmp field
		void map
		(
			const tmp<Field<Type>>& tmapF,
			const FieldMapper& map
		);

		//- Map from self
		void autoMap
		(
			const FieldMapper& map
		);

		//- 1 to 1 reverse-map from the given field
		void rmap
		(
			const UList<Type>& mapF,
			const unallocLabelList& mapAddressing
		);

		//- 1 to 1 reverse-map from the given tmp field
		void rmap
		(
			const tmp<Field<Type>>& tmapF,
			const unallocLabelList& mapAddressing
		);

		//- Interpolative reverse map from the given field
		void rmap
		(
			const UList<Type>& mapF,
			const unallocLabelList& mapAddressing,
			const scalarList& weights
		);

		//- Interpolative reverse map from the given tmp field
		void rmap
		(
			const tmp<Field<Type>>& tmapF,
			const unallocLabelList& mapAddressing,
			const scalarList& weights
		);

		//- Negate this field
		void negate();

		//- Return a component field of the field
		tmp<Field<cmptType>> component(const direction) const;

		//- Replace a component field of the field
		void replace(const direction, const UList<cmptType>&);

		//- Replace a component field of the field
		void replace(const direction, const tmp<Field<cmptType>>&);

		//- Replace a component field of the field
		void replace(const direction, const cmptType&);

		//- Return the field transpose (only defined for second rank tensors)
		tmp<Field<Type>> T() const;

		//- Write the field as a dictionary entry
		void writeEntry(const word& keyword, Ostream& os) const;


		// Member operators

		void operator=(const Field<Type>&);
		void operator=(const UList<Type>&);
		void operator=(const SubField<Type>&);
		void operator=(const tmp<Field<Type>>&);
		void operator=(const Type&);

		template<class Form, class Cmpt, int nCmpt>
		void operator=(const VectorSpace<Form, Cmpt, nCmpt>&);

		void operator+=(const UList<Type>&);
		void operator+=(const tmp<Field<Type>>&);

		void operator-=(const UList<Type>&);
		void operator-=(const tmp<Field<Type>>&);

		void operator*=(const UList<scalar>&);
		void operator*=(const tmp<Field<scalar>>&);

		void operator/=(const UList<scalar>&);
		void operator/=(const tmp<Field<scalar>>&);

		void operator+=(const Type&);
		void operator-=(const Type&);

		void operator*=(const scalar&);
		void operator/=(const scalar&);


		// IOstream operators

#ifndef SWIG
		friend Ostream& operator<< <Type>
			(Ostream&, const Field<Type>&);

		friend Ostream& operator<< <Type>
			(Ostream&, const tmp<Field<Type>>&);
#endif
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include <FieldFunctions.hxx>

#endif // !_Field_Header
