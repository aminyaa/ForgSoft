#pragma once
#ifndef _globalPointPatch_Header
#define _globalPointPatch_Header

#include <pointPatch.hxx>
#include <coupledPointPatch.hxx>
#include <globalMeshData.hxx>
#include <pointMesh.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
							 Class globalPointPatch Declaration
	\*---------------------------------------------------------------------------*/

	class globalPointPatch
		:
		public pointPatch,
		public coupledPointPatch
	{
		// Private data

			// //- Reference to the basic globalMeshData
			// const globalMeshData& globalMeshData_;

			//- Index in the boundary mesh
		label index_;


	protected:

		// Protected Member Functions

			//- Initialise the calculation of the patch geometry
		virtual void initGeometry()
		{}

		//- Calculate the patch geometry
		virtual void calcGeometry()
		{}

		//- Correct patches after moving points
		virtual void movePoints()
		{}

		//- Initialise the update of the patch topology
		virtual void initUpdateMesh()
		{}

		//- Update of the patch topology
		virtual void updateMesh()
		{}


		// Private Member Functions

			//- Disallow default construct as copy
		globalPointPatch
		(
			const globalPointPatch&
		);

		//- Disallow default assignment
		void operator=(const globalPointPatch&);


	public:

		typedef coupledPointPatch CoupledPointPatch;
		typedef pointBoundaryMesh BoundaryMesh;


		//- Runtime type information
		TypeName("global");

		// Constructors

			//- Construct from components
		globalPointPatch
		(
			const pointBoundaryMesh&,
			const label index
		);


		// Destructor

		virtual ~globalPointPatch();


		// Member functions

			//- Return name
		virtual const word& name() const
		{
			// There can only be a single patch of this type - therefore
			// its name is hard-coded.
			return type();
		}

		//- Return size
		virtual label size() const
		{
			return meshPoints().size();
		}

		//- Return true if running parallel
		virtual bool coupled() const
		{
			if (Pstream::parRun())
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		//- Return number of faces
		virtual label nFaces() const
		{
			return 0;
		}

		//- Return the index of this patch in the pointBoundaryMesh
		virtual label index() const
		{
			return index_;
		}

		//- Return mesh points
		virtual const labelList& meshPoints() const
		{
			return boundaryMesh().mesh().globalData().sharedPointLabels();
		}

		//- Return local points.  Not implemented
		virtual const pointField& localPoints() const
		{
			notImplemented("globalPointPatch::localPoints() const");
			return pointField::null();
		}

		//- Return point normals.  Not implemented
		virtual const vectorField& pointNormals() const
		{
			notImplemented("globalPointPatch::pointNormals() const");
			return vectorField::null();
		}

		//- Return total number of shared points
		virtual label globalPointSize() const
		{
			return boundaryMesh().mesh().globalData().nGlobalPoints();
		}

		//- Return total number of shared edges. Not implemented
		virtual label globalEdgeSize() const
		{
			return 0;
		}

		//- Return addressing into the global points list
		const labelList& sharedPointAddr() const
		{
			return boundaryMesh().mesh().globalData().sharedPointAddr();
		}

		//- Face decomposition into triangle.  Not implemented
		virtual triFaceList faceTriangles(const label faceID) const;

		//- Return mesh edges.  Not implemented
		virtual const edgeList& meshEdges() const;

		//- Return addressing into the global edge list.  Not implemented
		const labelList& sharedEdgeAddr() const;

		//- Return cut mesh edges.  Not implemented
		const edgeList& meshCutEdges() const;

		//- Return cut mesh edges multiplication mask
		//  Warning: this one is in the original cut edge order.
		//  For patch matrix multiplication se the reordered one.
		//  Not implemented
		const scalarField& meshCutEdgeMask() const;


		// Access functions for demand driven data

			//- Return list of edge indices for edges local to the patch
			//  Not implemented
		virtual const labelList& localEdgeIndices() const;

		//- Return list of edge indices for cut edges
		//  (i.e. connecting points within the patch ot points outside it)
		//  Not implemented
		virtual const labelList& cutEdgeIndices() const;

		// Cut edge addressing

		   //- Return cut edge owner edge indices.  Not implemented
		const labelList& cutEdgeOwnerIndices() const;

		//- Return cut edge owner edge starts.  Not implemented
		const labelList& cutEdgeOwnerStart() const;

		//- Return cut edge neighbour edge indices.  Not implemented
		const labelList& cutEdgeNeighbourIndices() const;

		//- Return cut edge neighbour edge starts.  Not implemented
		const labelList& cutEdgeNeighbourStart() const;

		// Doubly cut edge addressing

			//- Return doubly cut edge indices.  Not implemented
		const labelList& doubleCutEdgeIndices() const;

		//- Return doubly cut edge owner addressing
		//  into current patch.  Not implemented
		const labelList& doubleCutOwner() const;

		//- Return doubly cut edge neighbour addressing
		//  into current patch.  Not implemented
		const labelList& doubleCutNeighbour() const;

		//- Return cut edge multiplication mask.  Not implemented
		const scalarField& ownNeiDoubleMask() const;
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_globalPointPatch_Header
