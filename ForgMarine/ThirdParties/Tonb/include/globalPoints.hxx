#pragma once
#ifndef _globalPoints_Header
#define _globalPoints_Header

#include <DynamicList.hxx>
#include <dynamicLabelList.hxx>
#include <Map.hxx>
#include <labelList.hxx>
#include <FixedList.hxx>
#include <primitivePatch.hxx>
#include <className.hxx>
#include <edgeList.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// Forward declaration of classes
	class polyMesh;
	class polyBoundaryMesh;
	class cyclicPolyPatch;

	/*---------------------------------------------------------------------------*\
							   Class globalPoints Declaration
	\*---------------------------------------------------------------------------*/

	class globalPoints
	{
		// Private classes

			//- Define procPointList as holding a list of meshPoint/processor labels
		typedef FixedList<label, 2> procPoint;
		typedef List<procPoint> procPointList;

		// Private data

			//- Mesh reference
		const polyMesh& mesh_;

		//- Sum of points on processor patches (unfiltered, point on 2 patches
		//  counts as 2)
		const label nPatchPoints_;

		//- All points on boundaries and their corresponding connected points
		//  on other processors.
		DynamicList<procPointList> procPoints_;

		//- Map from mesh point to index in procPoints
		Map<label> meshToProcPoint_;

		//- Shared points used by this processor (= global point number)
		labelList sharedPointAddr_;

		//- My meshpoints corresponding to the shared points
		labelList sharedPointLabels_;

		//- Total number of shared points.
		label nGlobalPoints_;


		// Private Member Functions

			//- Count all points on processorPatches. Is all points for which
			//  information is collected.
		static label countPatchPoints(const polyBoundaryMesh&);

		//- Add information about patchPointI in relative indices to send
		//  buffers (patchFaces, indexInFace etc.)
		static void addToSend
		(
			const primitivePatch&,
			const label patchPointI,
			const procPointList&,
			dynamicLabelList& patchFaces,
			dynamicLabelList& indexInFace,
			DynamicList<procPointList>& allInfo
		);

		//- Merge info from neighbour into my data
		static bool mergeInfo
		(
			const procPointList& nbrInfo,
			procPointList& myInfo
		);

		//- Store (and merge) info for meshPointI
		bool storeInfo(const procPointList& nbrInfo, const label meshPointI);

		//- Initialize procPoints_ to my patch points. allPoints = true:
		//  seed with all patch points, = false: only boundaryPoints().
		void initOwnPoints(const bool allPoints, labelHashSet& changedPoints);

		//- Send subset of procPoints to neighbours
		void sendPatchPoints(const labelHashSet& changedPoints) const;

		//- Receive neighbour points and merge into my procPoints.
		void receivePatchPoints(labelHashSet& changedPoints);

		//- Remove entries of size 2 where meshPoint is in provided Map.
		//  Used to remove normal face-face connected points.
		void remove(const Map<label>&);

		//- Get indices of point for which I am master (lowest numbered proc)
		labelList getMasterPoints() const;

		//- Send subset of shared points to neighbours
		void sendSharedPoints(const labelList& changedIndices) const;

		//- Receive shared points and update subset.
		void receiveSharedPoints(labelList& changedIndices);


		//- Should move into cyclicPolyPatch but some ordering problem
		//  keeps on giving problems.
		static edgeList coupledPoints(const cyclicPolyPatch&);

		//- Disallow default bitwise copy construct
		globalPoints(const globalPoints&);

		//- Disallow default bitwise assignment
		void operator=(const globalPoints&);


	public:

		//- Declare name of the class and its debug switch
		ClassName("globalPoints");


		// Constructors

			//- Construct from mesh
		globalPoints(const polyMesh& mesh);


		// Member Functions

			// Access

		label nPatchPoints() const
		{
			return nPatchPoints_;
		}

		const Map<label>& meshToProcPoint() const
		{
			return meshToProcPoint_;
		}

		//- shared points used by this processor (= global point number)
		const labelList& sharedPointAddr() const
		{
			return sharedPointAddr_;
		}

		//- my meshpoints corresponding to the shared points
		const labelList& sharedPointLabels() const
		{
			return sharedPointLabels_;
		}

		label nGlobalPoints() const
		{
			return nGlobalPoints_;
		}

	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_globalPoints_Header
