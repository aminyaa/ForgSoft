#pragma once
// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

template<class Type, template<class> class PatchField, class GeoMesh>
inline const tnbLib::GeometricField<Type, PatchField, GeoMesh>&
tnbLib::GeometricField<Type, PatchField, GeoMesh>::null()
{
	return *reinterpret_cast<GeometricField<Type, PatchField, GeoMesh>*>(0);
}


template<class Type, template<class> class PatchField, class GeoMesh>
inline
const typename
tnbLib::GeometricField<Type, PatchField, GeoMesh>::DimensionedInternalField&
tnbLib::GeometricField<Type, PatchField, GeoMesh>::
dimensionedInternalField() const
{
	return *this;
}


template<class Type, template<class> class PatchField, class GeoMesh>
inline
const typename
tnbLib::GeometricField<Type, PatchField, GeoMesh>::InternalField&
tnbLib::GeometricField<Type, PatchField, GeoMesh>::internalField() const
{
	return *this;
}


template<class Type, template<class> class PatchField, class GeoMesh>
inline const typename tnbLib::GeometricField<Type, PatchField, GeoMesh>::
GeometricBoundaryField&
tnbLib::GeometricField<Type, PatchField, GeoMesh>::boundaryField() const
{
	return boundaryField_;
}


template<class Type, template<class> class PatchField, class GeoMesh>
inline tnbLib::label
tnbLib::GeometricField<Type, PatchField, GeoMesh>::timeIndex() const
{
	return timeIndex_;
}


template<class Type, template<class> class PatchField, class GeoMesh>
inline tnbLib::label&
tnbLib::GeometricField<Type, PatchField, GeoMesh>::timeIndex()
{
	return timeIndex_;
}


// ************************************************************************* //