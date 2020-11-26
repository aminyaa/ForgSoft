#pragma once
#ifndef _patchZones_Header
#define _patchZones_Header

#include <labelList.hxx>
#include <pointField.hxx>
#include <polyPatch.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
							   Class patchZones Declaration
	\*---------------------------------------------------------------------------*/

	class patchZones
		: public labelList
	{
		// Private data

			//- Reference to patch
		const primitivePatch& pp_;

		//- Reference to protected edges
		const boolList& borderEdge_;

		//- Max number of zones
		label nZones_;


		// Private Member Functions

			//- Gets labels of changed faces and propagates them to the edges.
			//  Returns labels of edges changed. Does not cross edges marked in
			//  regionEdge
		labelList faceToEdge
		(
			const labelList& changedFaces,
			labelList& edgeRegion
		);

		//- Reverse of faceToEdge: gets edges and returns faces
		labelList edgeToFace(const labelList& changedEdges);

		//- Fill *this with current zone for every face reachable
		//  from faceI without crossing edge marked in borderEdge.
		void markZone(label faceI);

	public:

		ClassName("patchZones");


		// Constructors

			//- Fills *this with zone of face. Zone is area
			//  reachable by edge crossing without crossing borderEdge
			//  (bool for every edge in patch).
		patchZones(const primitivePatch& pp, const boolList& borderEdge);


		// Member Functions

			//- Number of zones
		label nZones() const
		{
			return nZones_;
		}

	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_patchZones_Header
