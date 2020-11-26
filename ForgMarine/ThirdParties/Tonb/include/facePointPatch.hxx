#pragma once
#ifndef _facePointPatch_Header
#define _facePointPatch_Header

#include <pointPatch.hxx>
#include <polyPatch.hxx>
#include <autoPtr.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
						  Class facePointPatch Declaration
	\*---------------------------------------------------------------------------*/

	class facePointPatch
		:
		public pointPatch
	{
		// Private data

			//- Reference to the underlying polyPatch
		const polyPatch& polyPatch_;


	protected:

		// Protected Member Functions

			//- Initialise the calculation of the patch geometry
		virtual void initGeometry();

		//- Calculate the patch geometry
		virtual void calcGeometry();

		//- Initialise the patches for moving points
		virtual void initMovePoints(const pointField&);

		//- Correct patches after moving points
		virtual void movePoints(const pointField&);

		//- Initialise the update of the patch topology
		virtual void initUpdateMesh();

		//- Update of the patch topology
		virtual void updateMesh();


		// Private Member Functions

			//- Disallow default bitwise copy construct
		facePointPatch(const facePointPatch&);

		//- Disallow default bitwise assignment
		void operator=(const facePointPatch&);


	public:



		//- Runtime type information
		TypeName(polyPatch::typeName_());


		// Declare run-time constructor selection tables

		declareRunTimeSelectionTable
		(
			autoPtr,
			facePointPatch,
			polyPatch,
			(const polyPatch& patch, const pointBoundaryMesh& bm),
			(patch, bm)
		);


		// Constructors

			//- Construct from polyPatch
		facePointPatch
		(
			const polyPatch&,
			const pointBoundaryMesh&
		);


		// Selectors

			//- Return a pointer to a new patch created on freestore from polyPatch
		static autoPtr<facePointPatch> New
		(
			const polyPatch&,
			const pointBoundaryMesh&
		);


		// Destructor

		virtual ~facePointPatch()
		{}


		// Member Functions

			//- Return the polyPatch
		const polyPatch& patch() const
		{
			return polyPatch_;
		}

		//- Return name
		virtual const word& name() const
		{
			return polyPatch_.name();
		}

		//- Return size
		virtual label size() const
		{
			return polyPatch_.nPoints();
		}

		//- Return number of faces
		virtual label nFaces() const
		{
			return polyPatch_.size();
		}

		//- Return the index of this patch in the pointBoundaryMesh
		virtual label index() const
		{
			return polyPatch_.index();
		}


		// Access functions for demand driven data

			//- Return mesh points
		virtual const labelList& meshPoints() const
		{
			return polyPatch_.meshPoints();
		}

		//- Return pointField of points in patch
		virtual const pointField& localPoints() const
		{
			return polyPatch_.localPoints();
		}

		//- Return point unit normals
		virtual const vectorField& pointNormals() const
		{
			return polyPatch_.pointNormals();
		}
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_facePointPatch_Header
