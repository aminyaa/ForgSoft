#pragma once
#ifndef _degenerateMatcher_Header
#define _degenerateMatcher_Header

#include <hexMatcher.hxx>
#include <wedgeMatcher.hxx>
#include <prismMatcher.hxx>
#include <tetWedgeMatcher.hxx>
#include <pyrMatcher.hxx>
#include <tetMatcher.hxx>


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
							   Class degenerateMatcher Declaration
	\*---------------------------------------------------------------------------*/

	class degenerateMatcher
	{

		// Static data members

			//- Matchers for all degenerate hex shapes
		static hexMatcher hex;
		static wedgeMatcher wedge;
		static prismMatcher prism;
		static tetWedgeMatcher tetWedge;
		static pyrMatcher pyr;
		static tetMatcher tet;

		// Static functions

			//- Recognize basic shape
		static cellShape match
		(
			const faceList& faces,
			const labelList& faceOwner,
			const label cellI,
			const labelList& cellFaces
		);

	public:

		// Static data members

			//- Recognize shape given faces of a cell
		static cellShape match(const faceList& faces);

		//- Recognize given uncollapsed shape (usually hex) with duplicate
		//  vertices. cellShape just used to extract faces.
		static cellShape match(const cellShape& shape);

		//- Recognize shape given mesh and cellI
		static cellShape match(const primitiveMesh& mesh, const label cellI);
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_degenerateMatcher_Header
