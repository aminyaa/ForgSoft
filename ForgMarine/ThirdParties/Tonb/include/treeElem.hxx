#pragma once
#ifndef _treeElem_Header
#define _treeElem_Header

#include <treeBoundBox.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
							   Class treeElem Declaration
	\*---------------------------------------------------------------------------*/

	template <class Type>
	class treeElem
	{
		// Private data

			//- Bounding box of this node
		treeBoundBox bb_;

	public:

		// Constructors

			//- Construct from bounding box
		treeElem(const treeBoundBox& bb)
			: bb_(bb)
		{}


		// Member Functions

			// Access

				//- Bounding box of this node
		const treeBoundBox& bb() const
		{
			return bb_;
		}

		//- Bounding box of this node
		treeBoundBox& bb()
		{
			return bb_;
		}
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_treeElem_Header
