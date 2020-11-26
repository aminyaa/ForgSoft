#pragma once
#ifndef _cell_Header
#define _cell_Header

#include <faceList.hxx>
#include <oppositeFace.hxx>
#include <debugSwitch.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// Forward declaration of friend functions and operators

	class cell;
	bool operator==(const cell&, const cell&);
	inline bool operator!=(const cell&, const cell&);


	/*---------------------------------------------------------------------------*\
							   Class cell Declaration
	\*---------------------------------------------------------------------------*/

	class cell
		: public labelList
	{

	public:

		// Static data members

		static const char* const typeName;

		//- Debug switch
		static debug::debugSwitch debug;


		// Constructors

			//- Construct null
		cell();

		//- Construct given size
		explicit cell(label);

		//- Construct from list of labels
		explicit cell(const UList<label>&);

		//- Construct by transferring the parameter contents
		explicit cell(const Xfer<labelList>&);

		//- Construct from Istream
		cell(Istream&);


		// Member Functions

			//- Return number of faces
		label nFaces() const;

		//- Return labels of cell vertices
		labelList labels(const unallocFaceList&) const;

		//- Return the cell vertices
		pointField points(const unallocFaceList&, const pointField&) const;

		//- Return cell edges
		edgeList edges(const unallocFaceList&) const;

		//- Return index of opposite face
		label opposingFaceLabel
		(
			const label masterFaceLabel,
			const unallocFaceList& meshFaces
		) const;

		//- Return opposite face oriented the same way as the master face
		oppositeFace opposingFace
		(
			const label masterFaceLabel,
			const unallocFaceList& meshFaces
		) const;


		// Instructions for centre and mag:
		// When one wants to access the cell centre and magnitude, the
		// functionality on the mesh level should be used in preference to the
		// functions provided here. They do not rely to the functionality
		// implemented here, provide additional checking and are more efficient.
		// The cell::centre and cell::mag functions may be removed in the
		// future.

		//- Returns cell centre
		point centre(const pointField&, const unallocFaceList&) const;

		//- Returns cell volume
		scalar mag(const pointField&, const unallocFaceList&) const;


		// Friend Operators

		friend bool operator==(const cell&, const cell&);
		friend bool operator!=(const cell&, const cell&);
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include <cellI.hxx>

#endif // !_cell_Header
