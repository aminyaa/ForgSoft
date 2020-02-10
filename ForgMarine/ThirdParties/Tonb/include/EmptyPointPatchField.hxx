#pragma once
#ifndef _EmptyPointPatchField_Header
#define _EmptyPointPatchField_Header

#include <PointPatchFieldTemplate.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
						 Class EmptyPointPatchField Declaration
	\*---------------------------------------------------------------------------*/

	template
		<
		template<class> class PatchField,
		class Mesh,
		class PointPatch,
		class EmptyPointPatch,
		template<class> class MatrixType,
		class Type
		>
		class EmptyPointPatchField
		:
		public PatchField<Type>
	{

	public:

		//- Runtime type information
		TypeName(EmptyPointPatch::typeName_());


		// Constructors

			//- Construct from patch and internal field
		EmptyPointPatchField
		(
			const PointPatch&,
			const DimensionedField<Type, Mesh>&
		);

		//- Construct from patch, internal field and dictionary
		EmptyPointPatchField
		(
			const PointPatch&,
			const DimensionedField<Type, Mesh>&,
			const dictionary&
		);

		//- Construct by mapping given patchField<Type> onto a new patch
		EmptyPointPatchField
		(
			const EmptyPointPatchField
			<PatchField, Mesh, PointPatch, EmptyPointPatch, MatrixType, Type>&,
			const PointPatch&,
			const DimensionedField<Type, Mesh>&,
			const PointPatchFieldMapper&
		);

		//- Construct as copy setting internal field reference
		EmptyPointPatchField
		(
			const EmptyPointPatchField
			<PatchField, Mesh, PointPatch, EmptyPointPatch, MatrixType, Type>&
		);

		//- Construct and return a clone
		virtual autoPtr<PatchField<Type> > clone() const
		{
			return autoPtr<PatchField<Type> >
				(
					new EmptyPointPatchField
					<
					PatchField,
					Mesh,
					PointPatch,
					EmptyPointPatch,
					MatrixType,
					Type
					>(*this)
					);
		}

		//- Construct as copy setting internal field reference
		EmptyPointPatchField
		(
			const EmptyPointPatchField
			<PatchField, Mesh, PointPatch, EmptyPointPatch, MatrixType, Type>&,
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
					new EmptyPointPatchField
					<
					PatchField,
					Mesh,
					PointPatch,
					EmptyPointPatch,
					MatrixType,
					Type
					>(*this, iF)
					);
		}
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#    include <EmptyPointPatchField.cxx>
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_EmptyPointPatchField_Header
