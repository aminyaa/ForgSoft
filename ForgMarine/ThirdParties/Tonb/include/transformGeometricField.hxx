#pragma once
#ifndef _transformGeometricField_Header
#define _transformGeometricField_Header

#include <transform.hxx>
#include <GeometricField.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	template<class Type, template<class> class PatchField, class GeoMesh>
	void transform
	(
		GeometricField<Type, PatchField, GeoMesh>&,
		const GeometricField<tensor, PatchField, GeoMesh>&,
		const GeometricField<Type, PatchField, GeoMesh>&
	);

	template<class Type, template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<Type, PatchField, GeoMesh> > transform
	(
		const GeometricField<tensor, PatchField, GeoMesh>&,
		const GeometricField<Type, PatchField, GeoMesh>&
	);

	template<class Type, template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<Type, PatchField, GeoMesh> > transform
	(
		const GeometricField<tensor, PatchField, GeoMesh>&,
		const tmp<GeometricField<Type, PatchField, GeoMesh> >&
	);

	template<class Type, template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<Type, PatchField, GeoMesh> > transform
	(
		const tmp<GeometricField<tensor, PatchField, GeoMesh> >&,
		const GeometricField<Type, PatchField, GeoMesh>&
	);

	template<class Type, template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<Type, PatchField, GeoMesh> > transform
	(
		const tmp<GeometricField<tensor, PatchField, GeoMesh> >&,
		const tmp<GeometricField<Type, PatchField, GeoMesh> >&
	);


	template<class Type, template<class> class PatchField, class GeoMesh>
	void transform
	(
		GeometricField<Type, PatchField, GeoMesh>&,
		const dimensionedTensor&,
		const GeometricField<Type, PatchField, GeoMesh>&
	);

	template<class Type, template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<Type, PatchField, GeoMesh> > transform
	(
		const dimensionedTensor&,
		const GeometricField<Type, PatchField, GeoMesh>&
	);

	template<class Type, template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<Type, PatchField, GeoMesh> > transform
	(
		const dimensionedTensor&,
		const tmp<GeometricField<Type, PatchField, GeoMesh> >&
	);


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#   include <transformGeometricField.cxx>
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_transformGeometricField_Header
