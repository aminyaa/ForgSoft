#pragma once
#ifndef _TimeVaryingUniformFixedValuePointPatchField_Header
#define _TimeVaryingUniformFixedValuePointPatchField_Header

#include <FixedValuePointPatchField.hxx>
#include <interpolationTable.hxx>
#include <tnbTime.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
				Class TimeVaryingUniformFixedValuePointPatchField Declaration
	\*---------------------------------------------------------------------------*/

	template
		<
		template<class> class PatchField,
		class Mesh,
		class PointPatch,
		template<class> class MatrixType,
		class Type
		>
		class TimeVaryingUniformFixedValuePointPatchField
		:
		public FixedValuePointPatchField
		<PatchField, Mesh, PointPatch, MatrixType, Type>
	{

		// Private data

			//- Yhe time series being used, including the bounding treatment
		interpolationTable<Type> timeSeries_;


	public:

		//- Runtime type information
		TypeName("timeVaryingUniformFixedValue");


		// Constructors

			//- Construct from patch and internal field
		TimeVaryingUniformFixedValuePointPatchField
		(
			const PointPatch&,
			const DimensionedField<Type, Mesh>&
		);

		//- Construct from patch, internal field and dictionary
		TimeVaryingUniformFixedValuePointPatchField
		(
			const PointPatch&,
			const DimensionedField<Type, Mesh>&,
			const dictionary&
		);

		//- Construct by mapping given patchField<Type> onto a new patch
		TimeVaryingUniformFixedValuePointPatchField
		(
			const TimeVaryingUniformFixedValuePointPatchField
			<PatchField, Mesh, PointPatch, MatrixType, Type>&,
			const PointPatch&,
			const DimensionedField<Type, Mesh>&,
			const PointPatchFieldMapper&
		);

		//- Construct as copy
		TimeVaryingUniformFixedValuePointPatchField
		(
			const TimeVaryingUniformFixedValuePointPatchField
			<PatchField, Mesh, PointPatch, MatrixType, Type>&
		);

		//- Construct and return a clone
		virtual autoPtr<PatchField<Type> > clone() const
		{
			return autoPtr<PatchField<Type> >
				(
					new TimeVaryingUniformFixedValuePointPatchField
					<PatchField, Mesh, PointPatch, MatrixType, Type>(*this)
					);
		}

		//- Construct as copy setting internal field reference
		TimeVaryingUniformFixedValuePointPatchField
		(
			const TimeVaryingUniformFixedValuePointPatchField
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
					new TimeVaryingUniformFixedValuePointPatchField
					<PatchField, Mesh, PointPatch, MatrixType, Type>(*this, iF)
					);
		}


		// Member functions

			// Access

				//- Return the time series used
		const interpolationTable<Type>& timeSeries() const
		{
			return timeSeries_;
		}


		// Evaluation functions

		//- Insert boundary value into the internal field
		//  Fixed values need to be inserted first. In the second go,
		//  there's nothing to do
		virtual void initEvaluate
		(
			const Pstream::commsTypes commsType
		);


		//- Write
		virtual void write(Ostream&) const;
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#    include <TimeVaryingUniformFixedValuePointPatchField.cxx>
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_TimeVaryingUniformFixedValuePointPatchField_Header
