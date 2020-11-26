#pragma once
#ifndef _FixedValuePointPatchField_Header
#define _FixedValuePointPatchField_Header

#include <ValuePointPatchField.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
					  Class FixedValuePointPatchField Declaration
	\*---------------------------------------------------------------------------*/

	template
		<
		template<class> class PatchField,
		class Mesh,
		class PointPatch,
		template<class> class MatrixType,
		class Type
		>
		class FixedValuePointPatchField
		:
		public ValuePointPatchField<PatchField, Mesh, PointPatch, MatrixType, Type>
	{

	public:

		//- Runtime type information
		TypeName("fixedValue");


		// Constructors

			//- Construct from patch and internal field
		FixedValuePointPatchField
		(
			const PointPatch&,
			const DimensionedField<Type, Mesh>&
		);

		//- Construct from patch, internal field and dictionary
		FixedValuePointPatchField
		(
			const PointPatch&,
			const DimensionedField<Type, Mesh>&,
			const dictionary&
		);

		//- Construct by mapping given patchField<Type> onto a new patch
		FixedValuePointPatchField
		(
			const FixedValuePointPatchField
			<PatchField, Mesh, PointPatch, MatrixType, Type>&,
			const PointPatch&,
			const DimensionedField<Type, Mesh>&,
			const PointPatchFieldMapper&
		);

		//- Construct as copy
		FixedValuePointPatchField
		(
			const FixedValuePointPatchField
			<PatchField, Mesh, PointPatch, MatrixType, Type>&
		);

		//- Construct and return a clone
		virtual autoPtr<PatchField<Type> > clone() const
		{
			return autoPtr<PatchField<Type> >
				(
					new FixedValuePointPatchField
					<PatchField, Mesh, PointPatch, MatrixType, Type>(*this)
					);
		}

		//- Construct as copy setting internal field reference
		FixedValuePointPatchField
		(
			const FixedValuePointPatchField
			<PatchField, Mesh, PointPatch, MatrixType, Type>&,
			const DimensionedField<Type, Mesh>&
		);

		//- Construct and return a clone setting internal field reference
		virtual autoPtr<PatchField<Type> > clone
		(
			const DimensionedField<Type, Mesh>& iF
		) const
		{
			return autoPtr<PatchField<Type> >
				(
					new FixedValuePointPatchField
					<PatchField, Mesh, PointPatch, MatrixType, Type>(*this, iF)
					);
		}


		// Member functions

			//- Insert boundary value into the internal field
			//  Fixed values need to be inserted first. In the second go,
			//  there's nothing to do
		virtual void initEvaluate
		(
			const Pstream::commsTypes commsType = Pstream::blocking
		)
		{
			ValuePointPatchField
				<PatchField, Mesh, PointPatch, MatrixType, Type>::
				evaluate(commsType);
		}

		virtual void evaluate
		(
			const Pstream::commsTypes commsType = Pstream::blocking
		)
		{}

		virtual void setBoundaryCondition
		(
			Map<typename MatrixType<Type>::ConstraintType>&
		) const;


		// Member operators

			//- Disable assignment operators
		virtual void operator=(const Field<Type>&) {}
		virtual void operator=(const Type&) {}

		// Force an assignment irrespective of form of patch

		virtual void operator==
			(
				const ValuePointPatchField
				<PatchField, Mesh, PointPatch, MatrixType, Type>&
				);

		virtual void operator==(const Field<Type>&);
		virtual void operator==(const Type&);

	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#    include <FixedValuePointPatchField.cxx>
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_FixedValuePointPatchField_Header
