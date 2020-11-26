#pragma once
#ifndef _mapClouds_Header
#define _mapClouds_Header

#include <cloud.hxx>
#include <objectRegistry.hxx>
#include <polyMesh.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	//- Generic Geometric field mapper.
	//  For "real" mapping, add template specialisations for mapping of internal
	//  fields depending on mesh type.
	inline void mapClouds(const objectRegistry& db, const mapPolyMesh& mapper)
	{
		HashTable<const cloud*> clouds(db.lookupClass<cloud>());

		for
			(
				HashTable<const cloud*>::iterator iter = clouds.begin();
				iter != clouds.end();
				++iter
				)
		{
			cloud& c = const_cast<cloud&>(*iter());

			if (polyMesh::debug)
			{
				Info << "Mapping cloud " << c.name() << endl;
			}

			c.autoMap(mapper);
		}
	}


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_mapClouds_Header
