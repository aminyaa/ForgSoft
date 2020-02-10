#pragma once
#ifndef _SlipPointPatchField_Header
#define _SlipPointPatchField_Header

#include <BasicSymmetryPointPatchField.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
						  Class SlipPointPatchField Declaration
	\*---------------------------------------------------------------------------*/

	template
		<
		template<class> class PatchField,
		class Mesh,
		class PointPatch,
		template<class> class MatrixType,
		class Type
		>
		class SlipPointPatchField
		:
		public BasicSymmetryPointPatchField
		<PatchField, Mesh, PointPatch, MatrixType, Type>
	{

	public:

		//- Runtime type information
		TypeName("slip");


		// Constructors

			//- Construct from patch and internal field
		SlipPointPatchField
		(
			const PointPatch&,
			const DimensionedField<Type, Mesh>&
		);

		//- Construct from patch, internal field and dictionary
		SlipPointPatchField
		(
			const PointPatch&,
			const DimensionedField<Type, Mesh>&,
			const dictionary&
		);

		//- Construct by mapping given patchField<Type> onto a new patch
		SlipPointPatchField
		(
			const SlipPointPatchField
			<PatchField, Mesh, PointPatch, MatrixType, Type>&,
			const PointPatch&,
			const DimensionedField<Type, Mesh>&,
			const PointPatchFieldMapper&
		);

		//- Construct as copy
		SlipPointPatchField
		(
			const SlipPointPatchField
			<PatchField, Mesh, PointPatch, MatrixType, Type>&
		);

		//- Construct and return a clone
		virtual autoPtr<PatchField<Type> > clone() const
		{
			return autoPtr<PatchField<Type> >
				(
					new SlipPointPatchField
					<PatchField, Mesh, PointPatch, MatrixType, Type>(*this)
					);
		}

		//- Construct as copy setting internal field reference
		SlipPointPatchField
		(
			const SlipPointPatchField
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
					new SlipPointPatchField
					<PatchField, Mesh, PointPatch, MatrixType, Type>(*this, iF)
					);
		}
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#    include <SlipPointPatchField.cxx>
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_SlipPointPatchField_Header
