#pragma once
#ifndef _OscillatingFixedValuePointPatchField_Header
#define _OscillatingFixedValuePointPatchField_Header

#include <FixedValuePointPatchField.hxx>
#include <tnbTime.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
				Class OscillatingFixedValuePointPatchField Declaration
	\*---------------------------------------------------------------------------*/

	template
		<
		template<class> class PatchField,
		class Mesh,
		class PointPatch,
		template<class> class MatrixType,
		class Type
		>
		class OscillatingFixedValuePointPatchField
		:
		public FixedValuePointPatchField
		<PatchField, Mesh, PointPatch, MatrixType, Type>
	{

		// Private data

			//- Reference value
		Field<Type> refValue_;

		//- Amplitude
		Field<Type> amplitude_;

		//- Frequency
		scalar frequency_;

		//- Current time index
		label curTimeIndex_;


		// Private member functions

			//- Return current scale
		scalar currentScale() const;


	public:

		//- Runtime type information
		TypeName("oscillatingFixedValue");


		// Constructors

			//- Construct from patch and internal field
		OscillatingFixedValuePointPatchField
		(
			const PointPatch&,
			const DimensionedField<Type, Mesh>&
		);

		//- Construct from patch, internal field and dictionary
		OscillatingFixedValuePointPatchField
		(
			const PointPatch&,
			const DimensionedField<Type, Mesh>&,
			const dictionary&
		);

		//- Construct by mapping given patchField<Type> onto a new patch
		OscillatingFixedValuePointPatchField
		(
			const OscillatingFixedValuePointPatchField
			<PatchField, Mesh, PointPatch, MatrixType, Type>&,
			const PointPatch&,
			const DimensionedField<Type, Mesh>&,
			const PointPatchFieldMapper&
		);

		//- Construct as copy
		OscillatingFixedValuePointPatchField
		(
			const OscillatingFixedValuePointPatchField
			<PatchField, Mesh, PointPatch, MatrixType, Type>&
		);

		//- Construct and return a clone
		virtual autoPtr<PatchField<Type> > clone() const
		{
			return autoPtr<PatchField<Type> >
				(
					new OscillatingFixedValuePointPatchField
					<PatchField, Mesh, PointPatch, MatrixType, Type>(*this)
					);
		}

		//- Construct as copy setting internal field reference
		OscillatingFixedValuePointPatchField
		(
			const OscillatingFixedValuePointPatchField
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
					new OscillatingFixedValuePointPatchField
					<PatchField, Mesh, PointPatch, MatrixType, Type>(*this, iF)
					);
		}


		// Member functions

			// Access

				//- Return the ref value
		const Field<Type>& refValue() const
		{
			return refValue_;
		}

		//- Return reference to the ref value to allow adjustment
		Field<Type>& refValue()
		{
			return refValue_;
		}

		//- Return amplitude
		scalar amplitude() const
		{
			return amplitude_;
		}

		scalar& amplitude()
		{
			return amplitude_;
		}

		//- Return frequency
		scalar frequency() const
		{
			return frequency_;
		}

		scalar& frequency()
		{
			return frequency_;
		}


		// Mapping functions

			//- Map (and resize as needed) from self given a mapping object
		virtual void autoMap
		(
			const PointPatchFieldMapper&
		);

		//- Reverse map the given PointPatchField onto
		//  this PointPatchField
		virtual void rmap
		(
			const PointPatchField
			<PatchField, Mesh, PointPatch, MatrixType, Type>&,
			const labelList&
		);


		//- Insert boundary value into the internal field
		//  Fixed values need to be inserted first. In the second go,
		//  there's nothing to do
		virtual void initEvaluate
		(
			const Pstream::commsTypes commsType = Pstream::blocking
		);

		//- Write
		virtual void write(Ostream&) const;
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#    include <OscillatingFixedValuePointPatchField.cxx>
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_OscillatingFixedValuePointPatchField_Header
