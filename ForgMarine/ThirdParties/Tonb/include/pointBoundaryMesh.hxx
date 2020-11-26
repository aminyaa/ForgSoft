#pragma once
#ifndef _pointBoundaryMesh_Header
#define _pointBoundaryMesh_Header

#include <pointPatchList.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// Forward declaration of classes
	class pointMesh;
	class polyBoundaryMesh;
	class globalPointPatch;

	/*---------------------------------------------------------------------------*\
						   Class pointBoundaryMesh Declaration
	\*---------------------------------------------------------------------------*/

	class pointBoundaryMesh
		: public pointPatchList
	{
		// Private data

			//- Reference to mesh
		const pointMesh& mesh_;


		// Private Member Functions

			//- Calculate the geometry for the patches
			//  (transformation tensors etc.)
		void calcGeometry();

		//- Disallow default bitwise copy construct
		pointBoundaryMesh(const pointBoundaryMesh&);

		//- Disallow default bitwise assignment
		void operator=(const pointBoundaryMesh&);


	public:

		//- Declare friendship with pointMesh
		friend class pointMesh;


		// Constructors

			//- Construct from polyBoundaryMesh
		pointBoundaryMesh
		(
			const pointMesh&,
			const polyBoundaryMesh&
		);


		// Member functions

			//- Return the mesh reference
		const pointMesh& mesh() const
		{
			return mesh_;
		}

		//- Return reference to globalPointPatch
		const globalPointPatch& globalPatch() const;

		//- Correct polyBoundaryMesh after moving points
		void movePoints();

		//- Correct polyBoundaryMesh after topology update
		void updateMesh();
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_pointBoundaryMesh_Header
