#pragma once
#ifndef _SubDimensionedField_Header
#define _SubDimensionedField_Header

#include <Field.hxx>
#include <SubField.hxx>
#include <DimensionedField.hxx>
#include <regIOobject.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
						  Class SubDimensionedField Declaration
	\*---------------------------------------------------------------------------*/

	template<class Type, class GeoMesh>
	class SubDimensionedField
		: public regIOobject
		, public SubField<Type>
	{

	public:

		// Public typedefs

		typedef typename GeoMesh::Mesh Mesh;
		typedef typename Field<Type>::cmptType cmptType;


		// Static Member Functions

			//- Return a null SubDimensionedField
			//  Dangerous, but no null constructor.  Reconsider.  HJ, 10/Apr/2013
		static const SubDimensionedField<Type, GeoMesh>& null();


		// Constructors

			//- Construct from a SubField
		SubDimensionedField
		(
			const SubField<Type>& slist
		);

		//- Construct from a UList and size
		SubDimensionedField
		(
			const UList<Type>& list,
			const label subSize
		);

		//- Construct from a UList start and end indices
		SubDimensionedField
		(
			const UList<Type>& list,
			const label subSize,
			const label startIndex
		);

		//- Construct as copy
		SubDimensionedField
		(
			const SubDimensionedField<cmptType, GeoMesh>& sfield
		);


		// Member functions

			//- Return a component field of the field
		tmp<DimensionedField<cmptType, GeoMesh> > component
		(
			const direction
		) const;

		//- Return the field transpose (only defined for second rank tensors)
		tmp<DimensionedField<Type, GeoMesh> > T() const;


		// Member operators

			//- Assignment
		void operator=(const SubDimensionedField<Type, GeoMesh>&);

		//- Allow cast to a const DimensionedField<Type, GeoMesh>&
		operator const DimensionedField<Type, GeoMesh>&() const;
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include <SubDimensionedFieldI.hxx>

#endif // !_SubDimensionedField_Header
