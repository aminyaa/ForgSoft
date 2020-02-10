#pragma once
#ifndef _hexMatcher_Header
#define _hexMatcher_Header

#include <cellMatcher.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
							   Class hexMatcher Declaration
	\*---------------------------------------------------------------------------*/

	class hexMatcher
		:
		public cellMatcher
	{
		// Static data members

			//- constants for this shape
		static const label vertPerCell;
		static const label facePerCell;
		static const label maxVertPerFace;


		// Private Member Functions

			//- Disallow default bitwise copy construct
		hexMatcher(const hexMatcher&);

		//- Disallow default bitwise assignment
		void operator=(const hexMatcher&);


	public:

		// Constructors

			//- Construct null
		hexMatcher();

		// Destructor

		~hexMatcher();


		// Member Functions

		virtual label nVertPerCell() const
		{
			return vertPerCell;
		}

		virtual label nFacePerCell() const
		{
			return facePerCell;
		}

		virtual label nMaxVertPerFace() const
		{
			return maxVertPerFace;
		}

		virtual label faceHashValue() const;

		virtual bool faceSizeMatch(const faceList&, const labelList&) const;

		virtual bool matchShape
		(
			const bool checkOnly,
			const faceList& faces,
			const labelList& faceOwner,
			const label cellI,
			const labelList& myFaces
		);

		virtual bool isA(const primitiveMesh& mesh, const label cellI);

		virtual bool isA(const faceList&);

		virtual bool matches
		(
			const primitiveMesh& mesh,
			const label cellI,
			cellShape& shape
		);
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_hexMatcher_Header
