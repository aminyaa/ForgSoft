#pragma once
#ifndef _cyclicPointPatch_Header
#define _cyclicPointPatch_Header

#include <coupledFacePointPatch.hxx>
#include <cyclicPolyPatch.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
						  Class cyclicPointPatch Declaration
	\*---------------------------------------------------------------------------*/

	class cyclicPointPatch
		:
		public coupledFacePointPatch
	{
		// Private data

			//- Local reference cast into the cyclic patch
		const cyclicPolyPatch& cyclicPolyPatch_;


		// Demand driven private data

			//- The set of pairs of points that require transformation
			//  and/or mapping
		edgeList transformPairs_;


		// Private Member Functions

			//- Disallow default construct as copy
		cyclicPointPatch(const cyclicPointPatch&);

		//- Disallow default assignment
		void operator=(const cyclicPointPatch&);


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
		virtual void initUpdateMesh();

		//- Update of the patch topology
		virtual void updateMesh();


	public:

		typedef coupledPointPatch CoupledPointPatch;
		typedef pointBoundaryMesh BoundaryMesh;


		//- Runtime type information
		TypeName(cyclicPolyPatch::typeName_());


		// Constructors

			//- Construct from components
		cyclicPointPatch
		(
			const polyPatch& patch,
			const pointBoundaryMesh& bm
		);


		// Destructor

		virtual ~cyclicPointPatch();


		// Member Functions

			// Access

				//- Return the underlying cyclicPolyPatch
		const cyclicPolyPatch& cyclicPatch() const
		{
			return cyclicPolyPatch_;
		}

		//- Are the cyclic planes parallel
		bool parallel() const
		{
			return cyclicPolyPatch_.parallel();
		}

		//- Return face transformation tensor
		const tensorField& forwardT() const
		{
			return cyclicPolyPatch_.forwardT();
		}

		//- Return neighbour-cell transformation tensor
		const tensorField& reverseT() const
		{
			return cyclicPolyPatch_.reverseT();
		}
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //


#endif // !_cyclicPointPatch_Header
