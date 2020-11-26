#pragma once
#ifndef _tetCell_Header
#define _tetCell_Header

#include <FixedList.hxx>
#include <triFace.hxx>
#include <edge.hxx>
#include <pointField.hxx>
#include <tetPointRef.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	class cellShape;

	/*---------------------------------------------------------------------------*\
							   class tetCell Declaration
	\*---------------------------------------------------------------------------*/

	class tetCell
		: public FixedList<label, 4>
	{

	public:

		// Constructors

			//- Construct null
		tetCell();

		//- Construct from four points
		tetCell
		(
			const label a,
			const label b,
			const label c,
			const label d
		);

		//- Construct from FixedList
		explicit tetCell(const FixedList<label, 4>&);

		//- Construct from Istream
		explicit tetCell(Istream&);


		// Member Functions

			// Access

				//- Return i-th face
		triFace face(const label faceI) const;

		//- Return first face adjacent to the given edge
		label edgeFace(const label edgeI) const;

		//- Return face adjacent to the given face sharing the same edge
		label edgeAdjacentFace
		(
			const label edgeI,
			const label faceI
		) const;

		//- Return i-th edge
		edge tetEdge(const label edgeI) const;


		// Operations

			//- Return tet shape cell
		cellShape tetCellShape() const;

		//- Return the tetrahedron
		tetPointRef tet(const pointField&) const;
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include <tetCellI.hxx>

#endif // !_tetCell_Header
