#pragma once
#ifndef _ValuePointPatchField_Header
#define _ValuePointPatchField_Header

#include <PointPatchFieldTemplate.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
					   Class ValuePointPatchField Declaration
	\*---------------------------------------------------------------------------*/

	template
		<
		template<class> class PatchField,
		class Mesh,
		class PointPatch,
		template<class> class MatrixType,
		class Type
		>
		class ValuePointPatchField
		:
		public PatchField<Type>,
		public Field<Type>
	{
		// Private member functions

		void checkFieldSize() const;


	public:

		//- Runtime type information
		TypeName("value");


		// Constructors

			//- Construct from patch and internal field
		ValuePointPatchField
		(
			const PointPatch&,
			const DimensionedField<Type, Mesh>&
		);

		//- Construct from patch, internal field and dictionary
		ValuePointPatchField
		(
			const PointPatch&,
			const DimensionedField<Type, Mesh>&,
			const dictionary&
		);

		//- Construct by mapping given patchField<Type> onto a new patch
		ValuePointPatchField
		(
			const ValuePointPatchField
			<PatchField, Mesh, PointPatch, MatrixType, Type>&,
			const PointPatch&,
			const DimensionedField<Type, Mesh>&,
			const PointPatchFieldMapper&
		);

		//- Construct as copy
		ValuePointPatchField
		(
			const ValuePointPatchField
			<PatchField, Mesh, PointPatch, MatrixType, Type>&
		);

		//- Construct and return a clone
		virtual autoPtr<PatchField<Type> > clone() const
		{
			return autoPtr<PatchField<Type> >
				(
					new ValuePointPatchField
					<PatchField, Mesh, PointPatch, MatrixType, Type>(*this)
					);
		}

		//- Construct as copy setting internal field reference
		ValuePointPatchField
		(
			const ValuePointPatchField
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
					new ValuePointPatchField
					<PatchField, Mesh, PointPatch, MatrixType, Type>(*this, iF)
					);
		}


		// Member functions

			// Access

				//- Return size
		label size() const
		{
			return Field<Type>::size();
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


		// Evaluation functions

			//- Does it store field data
		virtual bool storesFieldData() const
		{
			return true;
		}

		//- Update the coefficients associated with the patch field
		virtual void updateCoeffs();

		//- Evaluate the patch field
		virtual void evaluate
		(
			const Pstream::commsTypes commsType = Pstream::blocking
		);

		//- Update boundary value
		virtual void updateBoundaryField()
		{}

		//- Set boundary condition to matrix
		virtual void setBoundaryCondition
		(
			Map<typename MatrixType<Type>::ConstraintType> &
		) const
		{}


		//- Write
		virtual void write(Ostream&) const;


		// Member operators

			//- Assignment operators

		virtual void operator=
			(
				const ValuePointPatchField
				<PatchField, Mesh, PointPatch, MatrixType, Type>&
				);

		virtual void operator=
			(
				const PointPatchField
				<PatchField, Mesh, PointPatch, MatrixType, Type>&
				);

		virtual void operator=(const Field<Type>&);
		virtual void operator=(const Type&);


		// Force an assignment irrespective of form of patch

		virtual void operator==
			(
				const ValuePointPatchField
				<PatchField, Mesh, PointPatch, MatrixType, Type>&
				);

		virtual void operator==
			(
				const PointPatchField
				<PatchField, Mesh, PointPatch, MatrixType, Type>&
				);

		virtual void operator==(const Field<Type>&);
		virtual void operator==(const Type&);
	};


	// This function is added to overide the hack in PointPatchField.H which
	//  enables simple backward compatability with versions using referenceLevel
	// in GeometricField
	template
		<
		template<class> class PatchField,
		class Mesh,
		class PointPatch,
		template<class> class MatrixType,
		class Type
		>
		tmp<Field<Type> > operator+
		(
			const ValuePointPatchField
			<PatchField, Mesh, PointPatch, MatrixType, Type>& vsppf,
			const Type& t
			)
	{
		return static_cast<const Field<Type>&>(vsppf) + t;
	}


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#    include <ValuePointPatchField.cxx>
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_ValuePointPatchField_Header
