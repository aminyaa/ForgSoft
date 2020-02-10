#pragma once
#ifndef _cellMatcher_Header
#define _cellMatcher_Header

#include <labelList.hxx>
#include <faceList.hxx>
#include <boolList.hxx>
#include <Map.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// Forward declaration of classes
	class primitiveMesh;
	class cell;
	class cellShape;
	class cellModel;

	/*---------------------------------------------------------------------------*\
							   Class cellMatcher Declaration
	\*---------------------------------------------------------------------------*/

	class cellMatcher
	{
	protected:

		// Static functions

			//- Given start and end of edge generate unique key
		static label edgeKey
		(
			const label numVert,
			const label v0,
			const label v1
		);

		//- Step along face either in righthand or lefthand direction
		static label nextVert(const label, const label, const bool);

		// Protected data

			// Map from mesh to local vertex numbering
		Map<label> localPoint_;

		//- Faces using local vertex numbering
		faceList localFaces_;

		//- Number of vertices per face in localFaces_
		labelList faceSize_;

		//- Map from local to mesh vertex numbering
		labelList pointMap_;

		//- Map from local to mesh face numbering
		labelList faceMap_;

		//- Map from 'edge' to neighbouring faces
		labelList edgeFaces_;

		//- pointFaceIndex[localVertI][localFaceI] is index in localFace
		//  where localVertI is.
		labelListList pointFaceIndex_;

		//- After matching: holds mesh vertices in cellmodel order
		labelList vertLabels_;

		//- After matching: holds mesh faces in cellmodel order
		labelList faceLabels_;

		//- CellModel name
		const word cellModelName_;

		mutable const cellModel* cellModelPtr_;


		// Protected Member Functions

			//- Calculates localFaces. Returns number of local vertices (or -1
			//  if more than vertPerCell).
		label calcLocalFaces(const faceList& faces, const labelList& myFaces);

		//- Fill edge (start, end) to face number
		void calcEdgeAddressing(const label numVert);

		//- Fill vertex/face to index in face data structure
		void calcPointFaceIndex();

		//- Given start,end of edge lookup both faces sharing it and return
		//  face != localFaceI
		label otherFace
		(
			const label numVert,
			const label v0,
			const label v1,
			const label localFaceI
		) const;


	private:

		// Private Member Functions

			//- Disallow default bitwise copy construct and assignment
		cellMatcher(const cellMatcher&);
		void operator=(const cellMatcher&);


	public:

		// Static functions

			//- Create list with incrementing labels
		static labelList makeIdentity(const label nElems);


		// Constructors

			//- Construct given mesh and shape factors
		cellMatcher
		(
			const label vertPerCell,
			const label facePerCell,
			const label maxVertPerFace,
			const word& cellModelName
		);


		// Destructor

		virtual ~cellMatcher()
		{}


		// Member Functions

			// Access

		const Map<label>& localPoint() const;
		const faceList& localFaces() const;
		const labelList& faceSize() const;
		const labelList& pointMap() const;
		const labelList& faceMap() const;
		const labelList& edgeFaces() const;
		const labelListList& pointFaceIndex() const;
		const labelList& vertLabels() const;
		const labelList& faceLabels() const;
		const cellModel& model() const;


		// Write

		void write(Ostream& os) const;

		// Cell shape dependent

		virtual label nVertPerCell() const = 0;

		virtual label nFacePerCell() const = 0;

		virtual label nMaxVertPerFace() const = 0;

		//- Hash value of all face sizes of this shape. Can be used for
		//  quick initial recognition.
		virtual label faceHashValue() const = 0;

		//- Check whether number of face sizes match the shape.
		virtual bool faceSizeMatch(const faceList&, const labelList&)
			const = 0;

		//- Low level shape recognition. Return true if matches.
		//  Works in detection mode only (checkOnly=true) or in exact
		//  matching. Returns true and sets vertLabels_.
		//  Needs faces, faceOwner of all faces in 'mesh' and cell number
		//  and labels of faces for this cell.
		//  cellI only used in combination with faceOwner to detect owner
		//  status.
		virtual bool matchShape
		(
			const bool checkOnly,
			const faceList& faces,
			const labelList& faceOwner,
			const label cellI,
			const labelList& myFaces
		) = 0;

		//- Exact match. Uses faceSizeMatch.
		//  Returns true if cell matches shape exactly.
		virtual bool isA(const primitiveMesh& mesh, const label cellI) = 0;

		//- Exact match given all the faces forming a cell. No checks
		//  on whether faces match up and form a closed shape.
		virtual bool isA(const faceList&) = 0;

		//- Like isA but also constructs a cellShape (if shape matches)
		virtual bool matches
		(
			const primitiveMesh& mesh,
			const label cellI,
			cellShape& shape
		) = 0;

	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include <cellMatcherI.hxx>

#endif // !_cellMatcher_Header
