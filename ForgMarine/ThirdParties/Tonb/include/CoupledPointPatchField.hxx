#pragma once
#ifndef _CoupledPointPatchField_Header
#define _CoupledPointPatchField_Header

#include <lduInterfaceField.hxx>
#include <PointPatchFieldTemplate.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
						 Class CoupledPointPatchField Declaration
	\*---------------------------------------------------------------------------*/

	template
		<
		template<class> class PatchField,
		class Mesh,
		class PointPatch,
		class CoupledPointPatch,
		template<class> class MatrixType,
		class Type
		>
		class CoupledPointPatchField
		:
		public lduInterfaceField,
		public PatchField<Type>
	{

	public:

		//- Runtime type information
		TypeName(CoupledPointPatch::typeName_());


		// Constructors

			//- Construct from patch and internal field
		CoupledPointPatchField
		(
			const PointPatch&,
			const DimensionedField<Type, Mesh>&
		);

		//- Construct by mapping given patchField<Type> onto a new patch
		CoupledPointPatchField
		(
			const CoupledPointPatchField
			<
			PatchField,
			Mesh,
			PointPatch,
			CoupledPointPatch,
			MatrixType,
			Type
			>&,
			const PointPatch&,
			const DimensionedField<Type, Mesh>&,
			const PointPatchFieldMapper&
		);

		//- Construct as copy
		CoupledPointPatchField
		(
			const CoupledPointPatchField
			<
			PatchField,
			Mesh,
			PointPatch,
			CoupledPointPatch,
			MatrixType,
			Type
			>&
		);

		//- Construct and return a clone
		virtual autoPtr<PatchField<Type> > clone() const = 0;

		//- Construct as copy setting internal field reference
		CoupledPointPatchField
		(
			const CoupledPointPatchField
			<
			PatchField,
			Mesh,
			PointPatch,
			CoupledPointPatch,
			MatrixType,
			Type
			>&,
			const DimensionedField<Type, Mesh>&
		);

		//- Construct and return a clone setting internal field reference
		virtual autoPtr<PatchField<Type> > clone
		(
			const DimensionedField<Type, Mesh>& iF
		) const = 0;


		// Member functions

			// Access

				//- Return true if this patch field is derived from
				//  CoupledPointPatchField
		virtual bool coupled() const
		{
			return true;
		}

		//- Evaluate the patch field
		virtual void evaluate
		(
			const Pstream::commsTypes commsType = Pstream::blocking
		) = 0;

		//- Add field to internal field
		virtual void addField(Field<Type>&) const = 0;


		// Matrix construction (completion) functionality

			//- Add diagonal/source contributions
		virtual void addDiag(scalarField&) const = 0;
		virtual void addSource(scalarField&) const = 0;

		//- Add upper/lower contributions
		virtual void addUpperLower(scalarField&) const = 0;

		virtual void eliminateUpperLower(scalarField&) const = 0;

		//- Get the cut edge coefficients in Amul order
		virtual tmp<scalarField> cutBouCoeffs(const lduMatrix&) const = 0;

		//- Get the cut edge coefficients in Tmul order
		virtual tmp<scalarField> cutIntCoeffs(const lduMatrix&) const = 0;


		// Coupled interface functionality

			//- Transform neighbour field
		virtual void transformCoupleField
		(
			scalarField& pnf,
			const direction cmpt
		) const
		{}

		//- Initialise neighbour matrix update
		virtual void initInterfaceMatrixUpdate
		(
			const scalarField&,
			scalarField&,
			const lduMatrix&,
			const scalarField&,
			const direction,
			const Pstream::commsTypes commsType,
			const bool switchToLhs
		) const
		{}

		//- Update result field based on interface functionality
		virtual void updateInterfaceMatrix
		(
			const scalarField&,
			scalarField&,
			const lduMatrix&,
			const scalarField&,
			const direction,
			const Pstream::commsTypes commsType,
			const bool switchToLhs
		) const = 0;
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#    include <CoupledPointPatchField.cxx>
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_CoupledPointPatchField_Header
