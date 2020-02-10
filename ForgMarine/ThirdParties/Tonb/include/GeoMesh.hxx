#pragma once
#ifndef _GeoMesh_Header
#define _GeoMesh_Header

#include <objectRegistry.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
							   Class GeoMesh Declaration
	\*---------------------------------------------------------------------------*/

	template<class MESH>
	class GeoMesh
	{

	protected:

		// Protected data

			//- Reference to Mesh
		const MESH& mesh_;


	public:

		// Public typedefs

		typedef MESH Mesh;
		typedef typename MESH::BoundaryMesh BoundaryMesh;


		// Constructors

			//- Construct from MESH
		explicit GeoMesh(const MESH& mesh)
			:
			mesh_(mesh)
		{}


		// Member Functions

			//- Return the object registry
		const objectRegistry& thisDb() const
		{
			return mesh_;
		}


		// Member Operators

			//- Return reference to polyMesh
		const MESH& operator()() const
		{
			return mesh_;
		}
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_GeoMesh_Header
