#pragma once
#ifndef _PatchTools_Header
#define _PatchTools_Header

#include <PrimitivePatchTemplate.hxx>
#include <HashSet.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
							 Class PatchTools Declaration
	\*---------------------------------------------------------------------------*/

	class PatchTools
	{
	public:

		//- Check for orientation issues.
		//  Returns true if problems were found.
		//  If a normal flips across an edge, places it in the HashSet
		template
			<
			class Face,
			template<class> class FaceList,
			class PointField,
			class PointType
			>
			static bool checkOrientation
			(
				const PrimitivePatch<Face, FaceList, PointField, PointType>&,
				const bool report = false,
				labelHashSet* marked = 0
			);


		//- Fill faceZone with currentZone for every face reachable
		//  from faceI without crossing edge marked in borderEdge.
		//  Note: faceZone has to be sized nFaces before calling.
		template
			<
			class BoolListType,
			class Face,
			template<class> class FaceList,
			class PointField,
			class PointType
			>
			static void markZone
			(
				const PrimitivePatch<Face, FaceList, PointField, PointType>&,
				const BoolListType& borderEdge,
				const label faceI,
				const label currentZone,
				labelList& faceZone
			);

		//- Size and fills faceZone with zone of face.
		//  Zone is area reachable by edge crossing without crossing borderEdge.
		//  Returns number of zones.
		template
			<
			class BoolListType,
			class Face,
			template<class> class FaceList,
			class PointField,
			class PointType
			>
			static label markZones
			(
				const PrimitivePatch<Face, FaceList, PointField, PointType>&,
				const BoolListType& borderEdge,
				labelList& faceZone
			);

		//- Determine the mapping for a sub-patch.
		//  Only include faces for which bool-list entry is true.
		//  @param[in]  includeFaces faces to include
		//  @param[out] pointMap mapping new to old localPoints
		//  @param[out] faceMap  mapping new to old faces
		template
			<
			class BoolListType,
			class Face,
			template<class> class FaceList,
			class PointField,
			class PointType
			>
			static void subsetMap
			(
				const PrimitivePatch<Face, FaceList, PointField, PointType>&,
				const BoolListType& includeFaces,
				labelList& pointMap,
				labelList& faceMap
			);

		//- Return edge-face addressing sorted by angle around the edge.
		//  Orientation is anticlockwise looking from edge.vec(localPoints())
		template
			<
			class Face,
			template<class> class FaceList,
			class PointField,
			class PointType
			>
			static labelListList sortedEdgeFaces
			(
				const PrimitivePatch<Face, FaceList, PointField, PointType>&
			);


		//- If 2 face neighbours: label of face where ordering of edge
		//  is consistent with righthand walk.
		//  If 1 neighbour: label of only face.
		//  If >2 neighbours: undetermined.
		template
			<
			class Face,
			template<class> class FaceList,
			class PointField,
			class PointType
			>
			static labelList edgeOwner
			(
				const PrimitivePatch<Face, FaceList, PointField, PointType>&
			);


	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#   include <PatchTools.cxx>
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_PatchTools_Header
