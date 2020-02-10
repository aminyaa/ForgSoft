#pragma once
#ifndef _GlobalPointPatchField_Header
#define _GlobalPointPatchField_Header

#include <CoupledPointPatchField.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
						 Class GlobalPointPatchField Declaration
	\*---------------------------------------------------------------------------*/

	template
		<
		template<class> class PatchField,
		class Mesh,
		class PointPatch,
		class GlobalPointPatch,
		template<class> class MatrixType,
		class Type
		>
		class GlobalPointPatchField
		:
		public CoupledPointPatchField
		<
		PatchField,
		Mesh,
		PointPatch,
		typename GlobalPointPatch::CoupledPointPatch,
		MatrixType,
		Type
		>
	{
		// Private data

			//- Local reference to processorPoint patch
		const GlobalPointPatch& globalPointPatch_;


		// Private member functions

			//- Reduce the field and extract the local values
		template<class Type2>
		tmp<Field<Type2> > reduceExtractPoint(const tmp<Field<Type2> >&) const;

		template<class Type2>
		tmp<Field<Type2> > reduceExtractEdge(const tmp<Field<Type2> >&) const;

		template<class Type2>
		void addFieldTempl(Field<Type2>&) const;


	public:

		//- Runtime type information
		TypeName(GlobalPointPatch::typeName_());


		// Constructors

			//- Construct from patch and internal field
		GlobalPointPatchField
		(
			const PointPatch&,
			const DimensionedField<Type, Mesh>&
		);

		//- Construct from patch, internal field and dictionary
		GlobalPointPatchField
		(
			const PointPatch&,
			const DimensionedField<Type, Mesh>&,
			const dictionary&
		);

		//- Construct by mapping given patchField<Type> onto a new patch
		GlobalPointPatchField
		(
			const GlobalPointPatchField
			<PatchField, Mesh, PointPatch, GlobalPointPatch, MatrixType, Type>&,
			const PointPatch&,
			const DimensionedField<Type, Mesh>&,
			const PointPatchFieldMapper&
		);

		//- Construct as copy
		GlobalPointPatchField
		(
			const GlobalPointPatchField
			<PatchField, Mesh, PointPatch, GlobalPointPatch, MatrixType, Type>&
		);

		//- Construct and return a clone
		virtual autoPtr<PatchField<Type> > clone() const
		{
			return autoPtr<PatchField<Type> >
				(
					new GlobalPointPatchField
					<
					PatchField,
					Mesh,
					PointPatch,
					GlobalPointPatch,
					MatrixType,
					Type
					>(*this)
					);
		}

		//- Construct as copy setting internal field reference
		GlobalPointPatchField
		(
			const GlobalPointPatchField
			<PatchField, Mesh, PointPatch, GlobalPointPatch, MatrixType, Type>&,
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
					new GlobalPointPatchField
					<
					PatchField,
					Mesh,
					PointPatch,
					GlobalPointPatch,
					MatrixType,
					Type
					>(*this, iF)
					);
		}


		// Destructor

		~GlobalPointPatchField();


		// Member functions

			// Access

				//- Evaluate the patch field
		virtual void evaluate
		(
			const Pstream::commsTypes commsType = Pstream::blocking
		);

		//- Add field to internal field
		virtual void addField(Field<Type>&) const;

		//- Set boundary condition to matrix.  Used to save the processor
		//  patch off-diagonal coefficients
		virtual void setBoundaryCondition
		(
			Map<typename MatrixType<Type>::ConstraintType> &
		) const;


		// Matrix construction (completion) functionality

		virtual void addDiag(scalarField&) const;
		virtual void addSource(scalarField&) const;

		//- Add upper/lower contributions
		virtual void addUpperLower(scalarField&) const;

		virtual void eliminateUpperLower(scalarField&) const;

		//- Get the cut edge coefficients in Amul order
		virtual tmp<scalarField> cutBouCoeffs(const lduMatrix&) const;

		//- Get the cut edge coefficients in Tmul order
		virtual tmp<scalarField> cutIntCoeffs(const lduMatrix&) const;


		// Coupled interface functionality

			//- Update result field based on interface functionality
		virtual void updateInterfaceMatrix
		(
			const scalarField& psiInternal,
			scalarField& result,
			const lduMatrix& m,
			const scalarField& coeffs,
			const direction cmpt,
			const Pstream::commsTypes commsType,
			const bool switchToLhs
		) const;

	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#    include <GlobalPointPatchField.cxx>
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_GlobalPointPatchField_Header
