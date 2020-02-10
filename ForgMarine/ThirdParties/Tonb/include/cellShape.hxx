#pragma once
#ifndef _cellShape_Header
#define _cellShape_Header

#include <pointField.hxx>
#include <labelList.hxx>
#include <cellModel.hxx>
#include <autoPtr.hxx>
#include <InfoProxy.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// Forward declaration of classes
	class cell;

	// Forward declaration of friend functions and operators

	class cellShape;
	bool operator==(const cellShape&, const cellShape&);
	Istream& operator>>(Istream&, cellShape&);
	Ostream& operator<<(Ostream&, const cellShape&);


	/*---------------------------------------------------------------------------*\
							   Class cellShape Declaration
	\*---------------------------------------------------------------------------*/

	class cellShape
		: public labelList
	{
		// Private data

			//- Access to the cellShape's model
		const cellModel *m;


	public:

		// Constructors

			//- Construct null
		cellShape();

		//- Construct from components
		cellShape
		(
			const cellModel&,
			const labelList&,
			const bool doCollapse = false
		);

		//- Construct from Istream
		cellShape(Istream& is);

		//- Clone
		autoPtr<cellShape> clone() const;


		// Member Functions

			//- Return the points corresponding to this cellShape
		pointField points(const pointField& meshPoints) const;

		//- Model reference
		const cellModel& model() const;

		//- Mesh face labels of this cell (in order of model)
		labelList meshFaces
		(
			const faceList& allFaces, const cell&
		) const;

		//- Mesh edge labels of this cell (in order of model)
		labelList meshEdges
		(
			const edgeList& allEdges,
			const labelList&
		) const;

		//- Faces of this cell
		faceList faces() const;

		//- Collapsed faces of this cell
		faceList collapsedFaces() const;

		//- Number of faces
		label nFaces() const;

		//- Edges of this cellShape
		edgeList edges() const;

		//- Number of edges
		label nEdges() const;

		//- Number of points
		label nPoints() const;

		//- Centroid of the cell
		point centre(const pointField&) const;

		//- Return info proxy.
		//  Used to print token information to a stream
		tnbLib::InfoProxy<cellShape> info() const
		{
			return *this;
		}

		//- Scalar magnitude
		scalar mag(const pointField&) const;

		//- Collapse shape to correct one after removing duplicate vertices
		void collapse();


		// Friend Operators

		friend bool operator==(const cellShape&, const cellShape&);


		// IOstream operators

		friend Istream& operator>>(Istream&, cellShape&);
		friend Ostream& operator<<(Ostream&, const cellShape&);
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include <cellShapeI.hxx>

#endif // !_cellShape_Header
