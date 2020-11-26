#pragma once
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

	template<class Type, class GeoMesh>
	const DimensionedField<Type, GeoMesh>&
		DimensionedField<Type, GeoMesh>::null()
	{
		// Dangerous, but no null constructor.  Reconsider.  HJ, 10/Apr/2013
		return *reinterpret_cast<DimensionedField<Type, GeoMesh>*>(0);
	}


	template<class Type, class GeoMesh>
	const typename GeoMesh::Mesh&
		DimensionedField<Type, GeoMesh>::mesh() const
	{
		return mesh_;
	}


	template<class Type, class GeoMesh>
	const dimensionSet& DimensionedField<Type, GeoMesh>::dimensions() const
	{
		return dimensions_;
	}

	template<class Type, class GeoMesh>
	dimensionSet& DimensionedField<Type, GeoMesh>::dimensions()
	{
		return dimensions_;
	}


	template<class Type, class GeoMesh>
	const Field<Type>& DimensionedField<Type, GeoMesh>::field() const
	{
		return *this;
	}

	template<class Type, class GeoMesh>
	Field<Type>& DimensionedField<Type, GeoMesh>::field()
	{
		return *this;
	}


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// ************************************************************************* //