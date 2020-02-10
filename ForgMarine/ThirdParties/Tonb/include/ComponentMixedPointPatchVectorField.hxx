#pragma once
#ifndef _ComponentMixedPointPatchVectorField_Header
#define _ComponentMixedPointPatchVectorField_Header

#include <PointPatchFieldTemplate.hxx>
#include <vectorField.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
				Class ComponentMixedPointPatchVectorField Declaration
	\*---------------------------------------------------------------------------*/

	template
		<
		template<class> class PatchField,
		class Mesh,
		class PointPatch,
		template<class> class MatrixType
		>
		class ComponentMixedPointPatchVectorField
		:
		public PatchField<vector>
	{
		// Private data

			//- Fraction vector of value used for boundary condition
		vectorField refValue_;

		//- Fraction vector of value used for boundary condition
		vectorField valueFraction_;


		// Private member functions

		void checkFieldSize() const;


	public:

		//- Runtime type information
		TypeName("componentMixed");


		// Constructors

			//- Construct from patch and internal field
		ComponentMixedPointPatchVectorField
		(
			const PointPatch&,
			const DimensionedField<vector, Mesh>&
		);

		//- Construct from patch, internal field and dictionary
		ComponentMixedPointPatchVectorField
		(
			const PointPatch&,
			const DimensionedField<vector, Mesh>&,
			const dictionary&
		);

		//- Construct by mapping given patchVectorField onto a new patch
		ComponentMixedPointPatchVectorField
		(
			const ComponentMixedPointPatchVectorField
			<PatchField, Mesh, PointPatch, MatrixType>&,
			const PointPatch&,
			const DimensionedField<vector, Mesh>&,
			const PointPatchFieldMapper&
		);

		//- Construct as copy setting internal field reference
		ComponentMixedPointPatchVectorField
		(
			const ComponentMixedPointPatchVectorField
			<PatchField, Mesh, PointPatch, MatrixType>&
		);

		//- Construct and return a clone
		virtual autoPtr<PatchField<vector> > clone() const
		{
			return autoPtr<PatchField<vector> >
				(
					new ComponentMixedPointPatchVectorField
					<PatchField, Mesh, PointPatch, MatrixType>(*this)
					);
		}

		//- Construct as copy setting internal field reference
		ComponentMixedPointPatchVectorField
		(
			const ComponentMixedPointPatchVectorField
			<PatchField, Mesh, PointPatch, MatrixType>&,
			const DimensionedField<vector, Mesh>&
		);

		//- Construct and return a clone setting internal field reference
		virtual autoPtr<PatchField<vector> > clone
		(
			const DimensionedField<vector, Mesh>& iF
		) const
		{
			return autoPtr<PatchField<vector> >
				(
					new ComponentMixedPointPatchVectorField
					<PatchField, Mesh, PointPatch, MatrixType>(*this, iF)
					);
		}


		// Member functions

			// Return defining fields

		virtual vectorField& refValue()
		{
			return refValue_;
		}

		virtual const vectorField& refValue() const
		{
			return refValue_;
		}


		virtual vectorField& valueFraction()
		{
			return valueFraction_;
		}

		virtual const vectorField& valueFraction() const
		{
			return valueFraction_;
		}


		// Mapping functions

			//- Map (and resize as needed) from self given a mapping object
		virtual void autoMap
		(
			const PointPatchFieldMapper&
		);

		//- Reverse map the given PointPatchVectorField onto
		//  this PointPatchVectorField
		virtual void rmap
		(
			const PointPatchField
			<PatchField, Mesh, PointPatch, MatrixType, vector>&,
			const labelList&
		);


		// Evaluation functions

			//- Insert boundary value into the internal field
		virtual void evaluate
		(
			const Pstream::commsTypes commsType = Pstream::blocking
		);

		//- Set boundary condition to matrix
		virtual void setBoundaryCondition
		(
			Map<typename MatrixType<vector>::ConstraintType>&
		) const;


		//- Write
		virtual void write(Ostream&) const;

	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#    include <ComponentMixedPointPatchVectorField.cxx>
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_ComponentMixedPointPatchVectorField_Header
