#pragma once
#ifndef _oppositeFace_Header
#define _oppositeFace_Header

#include <face.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
							   Class oppositeFace Declaration
	\*---------------------------------------------------------------------------*/

	class oppositeFace
		: public face
	{
		// Private data

			//- Master face index
		const label masterIndex_;

		//- Opposite face index
		const label oppositeIndex_;


	public:

		// Constructors

			//- Construct from components
		oppositeFace
		(
			const face& f,
			const label masterIndex,
			const label oppositeIndex
		)
			:
			face(f),
			masterIndex_(masterIndex),
			oppositeIndex_(oppositeIndex)
		{}


		// Member Functions

			//- Master face index
		label masterIndex() const
		{
			return masterIndex_;
		}

		//- Slave face index
		label oppositeIndex() const
		{
			return oppositeIndex_;
		}

		//- Does the opposite face exist?
		bool found() const
		{
			return size() > 0;
		}
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_oppositeFace_Header
