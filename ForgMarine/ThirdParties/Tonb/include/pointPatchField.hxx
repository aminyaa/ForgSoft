#pragma once
#ifndef _pointPatchField_Header
#define _pointPatchField_Header

#include <PointPatchFieldTemplate.hxx>
#include <pointPatch.hxx>
#include <DummyMatrix.hxx>
#include <pointMesh.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
						   Class pointPatchField Declaration
	\*---------------------------------------------------------------------------*/

	template<class Type>
	class pointPatchField
		:
		public PointPatchField
		<
		pointPatchField,
		pointMesh,
		pointPatch,
		DummyMatrix,
		Type
		>
	{

	public:

		// Constructors

			//- Construct from patch and internal field
		pointPatchField
		(
			const pointPatch&,
			const DimensionedField<Type, pointMesh>&
		);

		//- Construct as copy
		pointPatchField(const pointPatchField<Type>&);

		//- Construct and return a clone
		virtual autoPtr<pointPatchField<Type> > clone() const
		{
			return autoPtr<pointPatchField<Type> >
				(
					new pointPatchField<Type>(*this)
					);
		}

		//- Construct as copy setting internal field reference
		pointPatchField
		(
			const pointPatchField<Type>&,
			const DimensionedField<Type, pointMesh>&
		);

		//- Construct and return a clone setting internal field reference
		virtual autoPtr<pointPatchField<Type> > clone
		(
			const DimensionedField<Type, pointMesh>& iF
		) const
		{
			return autoPtr<pointPatchField<Type> >
				(
					new pointPatchField<Type>(*this, iF)
					);
		}


		// Destructor

		virtual ~pointPatchField()
		{}


		// Member operators

		virtual void operator=(const Type& t)
		{
			PointPatchField
				<
				tnbLib::pointPatchField,
				pointMesh,
				pointPatch,
				DummyMatrix,
				Type
				>::operator=(t);
		}
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#   include <pointPatchField.cxx>
#endif


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_pointPatchField_Header
