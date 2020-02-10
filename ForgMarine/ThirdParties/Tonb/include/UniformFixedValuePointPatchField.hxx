#pragma once
#ifndef _UniformFixedValuePointPatchField_Header
#define _UniformFixedValuePointPatchField_Header

#include <FixedValuePointPatchField.hxx>
#include <tnbTime.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
				Class UniformFixedValuePointPatchField Declaration
	\*---------------------------------------------------------------------------*/

	template
		<
		template<class> class PatchField,
		class Mesh,
		class PointPatch,
		template<class> class MatrixType,
		class Type
		>
		class UniformFixedValuePointPatchField
		:
		public FixedValuePointPatchField
		<PatchField, Mesh, PointPatch, MatrixType, Type>
	{

		// Private data

		Type uniformValue_;


	public:

		//- Runtime type information
		TypeName("uniformFixedValue");


		// Constructors

			//- Construct from patch and internal field
		UniformFixedValuePointPatchField
		(
			const PointPatch&,
			const DimensionedField<Type, Mesh>&
		);

		//- Construct from patch, internal field and dictionary
		UniformFixedValuePointPatchField
		(
			const PointPatch&,
			const DimensionedField<Type, Mesh>&,
			const dictionary&
		);

		//- Construct by mapping given patchField<Type> onto a new patch
		UniformFixedValuePointPatchField
		(
			const UniformFixedValuePointPatchField
			<PatchField, Mesh, PointPatch, MatrixType, Type>&,
			const PointPatch&,
			const DimensionedField<Type, Mesh>&,
			const PointPatchFieldMapper&
		);

		//- Construct as copy
		UniformFixedValuePointPatchField
		(
			const UniformFixedValuePointPatchField
			<PatchField, Mesh, PointPatch, MatrixType, Type>&
		);

		//- Construct and return a clone
		virtual autoPtr<PatchField<Type> > clone() const
		{
			return autoPtr<PatchField<Type> >
				(
					new UniformFixedValuePointPatchField
					<PatchField, Mesh, PointPatch, MatrixType, Type>(*this)
					);
		}

		//- Construct as copy setting internal field reference
		UniformFixedValuePointPatchField
		(
			const UniformFixedValuePointPatchField
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
					new UniformFixedValuePointPatchField
					<PatchField, Mesh, PointPatch, MatrixType, Type>(*this, iF)
					);
		}


		// Member functions

			// Access

				//- Return the uniform value
		const Type& uniformValue() const
		{
			return uniformValue_;
		}

		//- Return reference to the uniform value to allow adjustment
		Type& uniformValue()
		{
			return uniformValue_;
		}



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
#    include <UniformFixedValuePointPatchField.cxx>
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_UniformFixedValuePointPatchField_Header
