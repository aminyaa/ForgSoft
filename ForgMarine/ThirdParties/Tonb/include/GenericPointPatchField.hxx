#pragma once
#ifndef _GenericPointPatchField_Header
#define _GenericPointPatchField_Header

#include <CalculatedPointPatchField.hxx>
#include <HashPtrTable.hxx>
#include <primitiveFieldsFwd.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
					 Class GenericPointPatchField Declaration
	\*---------------------------------------------------------------------------*/

	template
		<
		template<class> class PatchField,
		class Mesh,
		class PointPatch,
		template<class> class MatrixType,
		class Type
		>
		class GenericPointPatchField
		:
		public CalculatedPointPatchField
		<PatchField, Mesh, PointPatch, MatrixType, Type>
	{
		// Private data

		word actualTypeName_;
		dictionary dict_;

		HashPtrTable<scalarField> scalarFields_;
		HashPtrTable<vectorField> vectorFields_;
		HashPtrTable<sphericalTensorField> sphericalTensorFields_;
		HashPtrTable<symmTensorField> symmTensorFields_;
		HashPtrTable<tensorField> tensorFields_;
		HashPtrTable<symmTensor4thOrderField> symmTensor4thOrderFields_;
		HashPtrTable<diagTensorField> diagTensorFields_;

	public:

		//- Runtime type information
		TypeName("generic");


		// Constructors

			//- Construct from patch and internal field
		GenericPointPatchField
		(
			const PointPatch&,
			const DimensionedField<Type, Mesh>&
		);

		//- Construct from patch, internal field and dictionary
		GenericPointPatchField
		(
			const PointPatch&,
			const DimensionedField<Type, Mesh>&,
			const dictionary&
		);

		//- Construct by mapping given patchField<Type> onto a new patch
		GenericPointPatchField
		(
			const GenericPointPatchField
			<PatchField, Mesh, PointPatch, MatrixType, Type>&,
			const PointPatch&,
			const DimensionedField<Type, Mesh>&,
			const PointPatchFieldMapper&
		);

		//- Construct as copy
		GenericPointPatchField
		(
			const GenericPointPatchField
			<PatchField, Mesh, PointPatch, MatrixType, Type>&
		);

		//- Construct and return a clone
		virtual autoPtr<PatchField<Type> > clone() const
		{
			return autoPtr<PatchField<Type> >
				(
					new GenericPointPatchField
					<PatchField, Mesh, PointPatch, MatrixType, Type>(*this)
					);
		}

		//- Construct as copy setting internal field reference
		GenericPointPatchField
		(
			const GenericPointPatchField
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
					new GenericPointPatchField
					<PatchField, Mesh, PointPatch, MatrixType, Type>(*this, iF)
					);
		}


		// Member functions

			// Mapping functions

				//- Map (and resize as needed) from self given a mapping object
		virtual void autoMap
		(
			const PointPatchFieldMapper&
		);

		//- Reverse map the given pointPatchField onto this PointPatchField
		virtual void rmap
		(
			const PointPatchField
			<PatchField, Mesh, PointPatch, MatrixType, Type>&,
			const labelList&
		);


		//- Write
		virtual void write(Ostream&) const;
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#    include <GenericPointPatchField.cxx>
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_GenericPointPatchField_Header
