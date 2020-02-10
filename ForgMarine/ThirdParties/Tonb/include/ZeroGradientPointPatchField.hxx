#pragma once
#ifndef _ZeroGradientPointPatchField_Header
#define _ZeroGradientPointPatchField_Header

#include <PointPatchFieldTemplate.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
					 Class ZeroGradientPointPatchField Declaration
	\*---------------------------------------------------------------------------*/

	template
		<
		template<class> class PatchField,
		class Mesh,
		class PointPatch,
		template<class> class MatrixType,
		class Type
		>
		class ZeroGradientPointPatchField
		:
		public PatchField<Type>
	{

	public:

		//- Runtime type information
		TypeName("zeroGradient");


		// Constructors

			//- Construct from patch and internal field
		ZeroGradientPointPatchField
		(
			const PointPatch&,
			const DimensionedField<Type, Mesh>&
		);

		//- Construct from patch, internal field and dictionary
		ZeroGradientPointPatchField
		(
			const PointPatch&,
			const DimensionedField<Type, Mesh>&,
			const dictionary&
		);

		//- Construct by mapping given patchField<Type> onto a new patch
		ZeroGradientPointPatchField
		(
			const ZeroGradientPointPatchField
			<PatchField, Mesh, PointPatch, MatrixType, Type>&,
			const PointPatch&,
			const DimensionedField<Type, Mesh>&,
			const PointPatchFieldMapper&
		);

		//- Construct as copy
		ZeroGradientPointPatchField
		(
			const ZeroGradientPointPatchField
			<PatchField, Mesh, PointPatch, MatrixType, Type>&
		);

		//- Construct and return a clone
		virtual autoPtr<PatchField<Type> > clone() const
		{
			return autoPtr<PatchField<Type> >
				(
					new ZeroGradientPointPatchField
					<PatchField, Mesh, PointPatch, MatrixType, Type>(*this)
					);
		}

		//- Construct as copy setting internal field reference
		ZeroGradientPointPatchField
		(
			const ZeroGradientPointPatchField
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
					new ZeroGradientPointPatchField
					<PatchField, Mesh, PointPatch, MatrixType, Type>(*this, iF)
					);
		}


		// Member functions

	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#    include <ZeroGradientPointPatchField.cxx>
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_ZeroGradientPointPatchField_Header
