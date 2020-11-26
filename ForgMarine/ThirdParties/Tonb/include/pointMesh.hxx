#pragma once
#ifndef _pointMesh_Header
#define _pointMesh_Header

#include <GeoMesh.hxx>
#include <MeshObject.hxx>
#include <polyMesh.hxx>
#include <pointBoundaryMesh.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
							   Class pointMesh Declaration
	\*---------------------------------------------------------------------------*/

	class pointMesh
		: public MeshObject<polyMesh, pointMesh>
		, public GeoMesh<polyMesh>
	{
		// Permanent data

			//- Boundary mesh
		pointBoundaryMesh boundary_;


		// Private Member Functions

			//- Disallow default bitwise copy construct
		pointMesh(const pointMesh&);

		//- Disallow default bitwise assignment
		void operator=(const pointMesh&);

		//- Map all fields
		void mapFields(const mapPolyMesh&) const;


	public:

		// Declare name of the class and its debug switch
		TypeName("pointMesh");

		typedef pointMesh Mesh;
		typedef pointBoundaryMesh BoundaryMesh;


		// Constructors

			//- Construct from polyMesh
		explicit pointMesh
		(
			const polyMesh& pMesh,
			bool alwaysConstructGlobalPatch = false
		);


		// Member Functions

			//- Return number of points
		label size() const
		{
			return size(*this);
		}

		//- Return number of points
		static label size(const Mesh& mesh)
		{
			return mesh.GeoMesh<polyMesh>::mesh_.nPoints();
		}

		//- Return number of points
		//  Needed because point and element fields in FEM share
		//  templated patch field type(checking of patch size).
		//  HJ, 16/Oct/2008
		label nPoints() const
		{
			return GeoMesh<polyMesh>::mesh_.nPoints();
		}

		//- Return number of points
		//  Needed because point and elemant fields in FEM share
		//  templated patch field type(checking of patch size).
		//  HJ, 16/Oct/2008
		label nCells() const
		{
			return GeoMesh<polyMesh>::mesh_.nCells();
		}

		//- Return reference to boundary mesh
		const pointBoundaryMesh& boundary() const
		{
			return boundary_;
		}

		//- Return parallel info
		const globalMeshData& globalData() const
		{
			return GeoMesh<polyMesh>::mesh_.globalData();
		}

		//- Return database. For now is its polyMesh.
		const objectRegistry& thisDb() const
		{
			return GeoMesh<polyMesh>::mesh_.thisDb();
		}


		// Mesh motion

			//- Move points, returns volumes swept by faces in motion
		virtual bool movePoints() const;

		//- Update the mesh corresponding to given map
		virtual bool updateMesh(const mapPolyMesh& mpm) const;


		// Member Operators

		bool operator!=(const pointMesh& pm) const
		{
			return &pm != this;
		}

		bool operator==(const pointMesh& pm) const
		{
			return &pm == this;
		}
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_pointMesh_Header
