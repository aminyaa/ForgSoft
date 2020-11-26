#pragma once
#ifndef _SymmetryPointPatchField_Header
#define _SymmetryPointPatchField_Header

#include <BasicSymmetryPointPatchField.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
					  Class SymmetryPointPatchField Declaration
	\*---------------------------------------------------------------------------*/

	template
		<
		template<class> class PatchField,
		class Mesh,
		class PointPatch,
		class SymmetryPointPatch,
		template<class> class MatrixType,
		class Type
		>
		class SymmetryPointPatchField
		:
		public BasicSymmetryPointPatchField
		<PatchField, Mesh, PointPatch, MatrixType, Type>
	{

	public:

		//- Runtime type information
		TypeName(SymmetryPointPatch::typeName_());


		// Constructors

			//- Construct from patch and internal field
		SymmetryPointPatchField
		(
			const PointPatch&,
			const DimensionedField<Type, Mesh>&
		);

		//- Construct from patch, internal field and dictionary
		SymmetryPointPatchField
		(
			const PointPatch&,
			const DimensionedField<Type, Mesh>&,
			const dictionary&
		);

		//- Construct by mapping given patchField<Type> onto a new patch
		SymmetryPointPatchField
		(
			const SymmetryPointPatchField
			<
			PatchField,
			Mesh,
			PointPatch,
			SymmetryPointPatch,
			MatrixType,
			Type
			>&,
			const PointPatch&,
			const DimensionedField<Type, Mesh>&,
			const PointPatchFieldMapper&
		);

		//- Construct as copy
		SymmetryPointPatchField
		(
			const SymmetryPointPatchField
			<
			PatchField,
			Mesh,
			PointPatch,
			SymmetryPointPatch,
			MatrixType,
			Type
			>&
		);

		//- Construct and return a clone
		virtual autoPtr<PatchField<Type> > clone() const
		{
			return autoPtr<PatchField<Type> >
				(
					new SymmetryPointPatchField
					<
					PatchField,
					Mesh,
					PointPatch,
					SymmetryPointPatch,
					MatrixType,
					Type
					>(*this)
					);
		}

		//- Construct as copy setting internal field reference
		SymmetryPointPatchField
		(
			const SymmetryPointPatchField
			<
			PatchField,
			Mesh,
			PointPatch,
			SymmetryPointPatch,
			MatrixType,
			Type
			>&,
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
					new SymmetryPointPatchField
					<
					PatchField,
					Mesh,
					PointPatch,
					SymmetryPointPatch,
					MatrixType,
					Type
					>(*this, iF)
					);
		}
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#    include <SymmetryPointPatchField.cxx>
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_SymmetryPointPatchField_Header
