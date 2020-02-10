#pragma once
#ifndef _CyclicPointPatchField_Header
#define _CyclicPointPatchField_Header

#include <CoupledPointPatchField.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
						Class CyclicPointPatchField Declaration
	\*---------------------------------------------------------------------------*/

	template
		<
		template<class> class PatchField,
		class Mesh,
		class PointPatch,
		class CyclicPointPatch,
		template<class> class MatrixType,
		class Type
		>
		class CyclicPointPatchField
		:
		public CoupledPointPatchField
		<
		PatchField,
		Mesh,
		PointPatch,
		typename CyclicPointPatch::CoupledPointPatch,
		MatrixType,
		Type
		>
	{
		// Private data

			//- Local reference cast into the cyclic patch
		const CyclicPointPatch& cyclicPatch_;


	public:

		//- Runtime type information
		TypeName(CyclicPointPatch::typeName_());


		// Constructors

			//- Construct from patch and internal field
		CyclicPointPatchField
		(
			const PointPatch&,
			const DimensionedField<Type, Mesh>&
		);

		//- Construct from patch, internal field and dictionary
		CyclicPointPatchField
		(
			const PointPatch&,
			const DimensionedField<Type, Mesh>&,
			const dictionary&
		);

		//- Construct by mapping given patchField<Type> onto a new patch
		CyclicPointPatchField
		(
			const CyclicPointPatchField
			<PatchField, Mesh, PointPatch, CyclicPointPatch, MatrixType, Type>&,
			const PointPatch&,
			const DimensionedField<Type, Mesh>&,
			const PointPatchFieldMapper&
		);

		//- Construct as copy setting internal field reference
		CyclicPointPatchField
		(
			const CyclicPointPatchField
			<PatchField, Mesh, PointPatch, CyclicPointPatch, MatrixType, Type>&
		);

		//- Construct and return a clone
		virtual autoPtr<PatchField<Type> > clone() const
		{
			return autoPtr<PatchField<Type> >
				(
					new CyclicPointPatchField
					<
					PatchField,
					Mesh,
					PointPatch,
					CyclicPointPatch,
					MatrixType,
					Type
					>(*this)
					);
		}

		//- Construct as copy setting internal field reference
		CyclicPointPatchField
		(
			const CyclicPointPatchField
			<PatchField, Mesh, PointPatch, CyclicPointPatch, MatrixType, Type>&,
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
					new CyclicPointPatchField
					<
					PatchField,
					Mesh,
					PointPatch,
					CyclicPointPatch,
					MatrixType,
					Type
					>(*this, iF)
					);
		}


		// Member functions

			//- Cyclic coupled interface functions

				//- Does the patch field perform the transfromation
		virtual bool doTransform() const
		{
			return !(cyclicPatch_.parallel() || pTraits<Type>::rank == 0);
		}

		//- Return face transformation tensor
		virtual const tensorField& forwardT() const
		{
			return cyclicPatch_.forwardT();
		}

		//- Return neighbour-cell transformation tensor
		virtual const tensorField& reverseT() const
		{
			return cyclicPatch_.reverseT();
		}


		//- Evaluate the patch field
		virtual void evaluate
		(
			const Pstream::commsTypes commsType = Pstream::blocking
		)
		{}

		//- Add field to internal field
		virtual void addField(Field<Type>&) const
		{}


		// Matrix construction (completion) functionality.  Currently faked
		// HJ, 31/May/2007

			//- Add diagonal/source contributions
		virtual void addDiag(scalarField&) const
		{}

		virtual void addSource(scalarField&) const
		{}

		//- Add upper/lower contributions
		virtual void addUpperLower(scalarField&) const
		{}

		virtual void eliminateUpperLower(scalarField&) const
		{}

		//- Get the cut edge coefficients in Amul order
		virtual tmp<scalarField> cutBouCoeffs(const lduMatrix&) const
		{
			return tmp<scalarField>(new scalarField(this->size(), 0));
		}

		//- Get the cut edge coefficients in Tmul order
		virtual tmp<scalarField> cutIntCoeffs(const lduMatrix&) const
		{
			return tmp<scalarField>(new scalarField(this->size(), 0));
		}

		// Coupled interface functionality

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
		) const
		{}
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#    include <CyclicPointPatchField.cxx>
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_CyclicPointPatchField_Header
