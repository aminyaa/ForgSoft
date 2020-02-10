#pragma once
#ifndef _FieldField_Header
#define _FieldField_Header

#include <tmp.hxx>
#include <PtrList.hxx>
#include <scalar.hxx>
#include <direction.hxx>
#include <VectorSpace.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// Forward declaration of friend functions and operators

	template<template<class> class Field, class Type>
	class FieldField;

	template<template<class> class Field, class Type>
	Ostream& operator<<
		(
			Ostream&,
			const FieldField<Field, Type>&
			);

	template<template<class> class Field, class Type>
	Ostream& operator<<
		(
			Ostream&,
			const tmp<FieldField<Field, Type> >&
			);


	/*---------------------------------------------------------------------------*\
							   Class FieldField Declaration
	\*---------------------------------------------------------------------------*/

	template<template<class> class Field, class Type>
	class FieldField
		: public refCount
		, public PtrList<Field<Type> >
	{

	public:

		//- Component type
		typedef typename pTraits<Type>::cmptType cmptType;


		// Constructors

			//- Construct null
			//  Used for temporary fields which are initialised after construction
		FieldField();

		//- Construct given size
		//  Used for temporary fields which are initialised after construction
		explicit FieldField(const label);

		//- Construct using the Field sizes from the given FieldField
		//  and the given Field type.
		//  Used for temporary fields which are initialised after construction
		FieldField(const word&, const FieldField<Field, Type>&);

		//- Construct as copy
		FieldField(const FieldField<Field, Type>&);

		//- Construct as copy or re-use as specified.
		FieldField(FieldField<Field, Type>&, bool reUse);

		//- Construct as copy of a PtrList<Field, Type>
		FieldField(const PtrList<Field<Type> >&);

		//- Construct as copy of tmp<FieldField>
#       ifdef ConstructFromTmp
		FieldField(const tmp<FieldField<Field, Type> >&);
#       endif

		//- Construct from Istream
		FieldField(Istream&);

		//- Clone
		tmp<FieldField<Field, Type> > clone() const;

		//- Return a pointer to a new calculatedFvPatchFieldField created on
		//  freestore without setting patchField values
		template<class Type2>
		static tmp<FieldField<Field, Type> > NewCalculatedType
		(
			const FieldField<Field, Type2>& ff
		)
#       ifdef __INTEL_COMPILER
		{
			FieldField<Field, Type>* nffPtr
			(
				new FieldField<Field, Type>(ff.size())
			);

			forAll(*nffPtr, i)
			{
				nffPtr->set(i, Field<Type>::NewCalculatedType(ff[i]).ptr());
			}

			return tmp<FieldField<Field, Type> >(nffPtr);
		}
#       else
			;
#       endif

		// Member functions

			//- Negate this field
		void negate();

		//- Return a component field of the field
		tmp<FieldField<Field, cmptType> > component(const direction) const;

		//- Replace a component field of the field
		void replace(const direction, const FieldField<Field, cmptType>&);

		//- Replace a component field of the field
		void replace(const direction, const cmptType&);

		//- Return the field transpose (only defined for second rank tensors)
		tmp<FieldField<Field, Type> > T() const;


		// Member operators

		void operator=(const FieldField<Field, Type>&);
		void operator=(const tmp<FieldField<Field, Type> >&);
		void operator=(const Type&);

		void operator+=(const FieldField<Field, Type>&);
		void operator+=(const tmp<FieldField<Field, Type> >&);

		void operator-=(const FieldField<Field, Type>&);
		void operator-=(const tmp<FieldField<Field, Type> >&);

		void operator*=(const FieldField<Field, scalar>&);
		void operator*=(const tmp<FieldField<Field, scalar> >&);

		void operator/=(const FieldField<Field, scalar>&);
		void operator/=(const tmp<FieldField<Field, scalar> >&);

		void operator+=(const Type&);
		void operator-=(const Type&);

		void operator*=(const scalar&);
		void operator/=(const scalar&);


		// IOstream operators

#ifndef SWIG
		friend Ostream& operator<< <Field, Type>
			(
				Ostream&,
				const FieldField<Field, Type>&
				);

		friend Ostream& operator<< <Field, Type>
			(
				Ostream&,
				const tmp<FieldField<Field, Type> >&
				);
#endif
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //


#include <FieldFieldReuseFunctions.hxx>

#ifdef NoRepository
#   include <FieldField.cxx>
#endif

#endif // !_FieldField_Header
