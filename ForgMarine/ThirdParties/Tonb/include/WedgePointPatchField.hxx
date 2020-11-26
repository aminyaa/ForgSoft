#pragma once
#ifndef _WedgePointPatchField_Header
#define _WedgePointPatchField_Header

#include <ZeroGradientPointPatchField.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
						Class WedgePointPatchField Declaration
	\*---------------------------------------------------------------------------*/

	template
		<
		template<class> class PatchField,
		class Mesh,
		class PointPatch,
		class WedgePointPatch,
		template<class> class MatrixType,
		class Type
		>
		class WedgePointPatchField
		:
		public PatchField<Type>
	{

	public:

		//- Runtime type information
		TypeName(WedgePointPatch::typeName_());


		// Constructors

			//- Construct from patch and internal field
		WedgePointPatchField
		(
			const PointPatch&,
			const DimensionedField<Type, Mesh>&
		);

		//- Construct from patch, internal field and dictionary
		WedgePointPatchField
		(
			const PointPatch&,
			const DimensionedField<Type, Mesh>&,
			const dictionary&
		);

		//- Construct by mapping given patchField<Type> onto a new patch
		WedgePointPatchField
		(
			const WedgePointPatchField
			<PatchField, Mesh, PointPatch, WedgePointPatch, MatrixType, Type>&,
			const PointPatch&,
			const DimensionedField<Type, Mesh>&,
			const PointPatchFieldMapper&
		);

		//- Construct as copy
		WedgePointPatchField
		(
			const WedgePointPatchField
			<PatchField, Mesh, PointPatch, WedgePointPatch, MatrixType, Type>&
		);

		//- Construct and return a clone
		virtual autoPtr<PatchField<Type> > clone() const
		{
			return autoPtr<PatchField<Type> >
				(
					new WedgePointPatchField
					<
					PatchField,
					Mesh,
					PointPatch,
					WedgePointPatch,
					MatrixType,
					Type
					>(*this)
					);
		}

		//- Construct as copy setting internal field reference
		WedgePointPatchField
		(
			const WedgePointPatchField
			<PatchField, Mesh, PointPatch, WedgePointPatch, MatrixType, Type>&,
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
					new WedgePointPatchField
					<
					PatchField,
					Mesh,
					PointPatch,
					WedgePointPatch,
					MatrixType,
					Type
					>(*this, iF)
					);
		}


		// Member functions

			//- Update the patch field
		virtual void evaluate
		(
			const Pstream::commsTypes commsType = Pstream::blocking
		);
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#    include <WedgePointPatchField.cxx>
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_WedgePointPatchField_Header
