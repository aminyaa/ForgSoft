#pragma once
#ifndef _BasicSymmetryPointPatchField_Header
#define _BasicSymmetryPointPatchField_Header

#include <ValuePointPatchField.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
					  Class BasicSymmetryPointPatchField Declaration
	\*---------------------------------------------------------------------------*/

	template
		<
		template<class> class PatchField,
		class Mesh,
		class PointPatch,
		template<class> class MatrixType,
		class Type
		>
		class BasicSymmetryPointPatchField
		:
		public ValuePointPatchField<PatchField, Mesh, PointPatch, MatrixType, Type>
	{
		// Private memeber functions

			//- Calculate implicitness matrix
		Type fixFlagMatrix(const vector&) const;


	public:

		// Constructors

			//- Construct from patch and internal field
		BasicSymmetryPointPatchField
		(
			const PointPatch&,
			const DimensionedField<Type, Mesh>&
		);

		//- Construct from patch, internal field and dictionary
		BasicSymmetryPointPatchField
		(
			const PointPatch&,
			const DimensionedField<Type, Mesh>&,
			const dictionary&
		);

		//- Construct by mapping given patchField<Type> onto a new patch
		BasicSymmetryPointPatchField
		(
			const BasicSymmetryPointPatchField
			<PatchField, Mesh, PointPatch, MatrixType, Type>&,
			const PointPatch&,
			const DimensionedField<Type, Mesh>&,
			const PointPatchFieldMapper&
		);

		//- Construct as copy
		BasicSymmetryPointPatchField
		(
			const BasicSymmetryPointPatchField
			<PatchField, Mesh, PointPatch, MatrixType, Type>&
		);

		//- Construct and return a clone
		virtual autoPtr<PatchField<Type> > clone() const
		{
			return autoPtr<PatchField<Type> >
				(
					new BasicSymmetryPointPatchField
					<PatchField, Mesh, PointPatch, MatrixType, Type>(*this)
					);
		}

		//- Construct as copy setting internal field reference
		BasicSymmetryPointPatchField
		(
			const BasicSymmetryPointPatchField
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
					new BasicSymmetryPointPatchField
					<PatchField, Mesh, PointPatch, MatrixType, Type>(*this, iF)
					);
		}


		// Member functions

			//- Update the patch field
		virtual void updateBoundaryField();

		//- Set boundary condition to matrix
		virtual void setBoundaryCondition
		(
			Map<typename MatrixType<Type>::ConstraintType>&
		) const;


		//- Write
		virtual void write(Ostream&) const;
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#    include <BasicSymmetryPointPatchField.cxx>
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_BasicSymmetryPointPatchField_Header
