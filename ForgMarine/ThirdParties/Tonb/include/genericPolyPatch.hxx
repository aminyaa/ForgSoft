#pragma once
#ifndef _genericPolyPatch_Header
#define _genericPolyPatch_Header

#include <polyPatch.hxx>
#include <dictionary.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
						  Class genericPolyPatch Declaration
	\*---------------------------------------------------------------------------*/

	class genericPolyPatch
		:
		public polyPatch
	{
		// Private data

		word actualTypeName_;
		dictionary dict_;

	public:

		//- Runtime type information
		TypeName("genericPatch");


		// Constructors

			//- Construct from components
		genericPolyPatch
		(
			const word& name,
			const label size,
			const label start,
			const label index,
			const polyBoundaryMesh& bm
		);

		//- Construct from dictionary
		genericPolyPatch
		(
			const word& name,
			const dictionary& dict,
			const label index,
			const polyBoundaryMesh& bm
		);

		//- Construct as copy, resetting the boundary mesh
		genericPolyPatch
		(
			const genericPolyPatch&,
			const polyBoundaryMesh&
		);

		//- Construct given the original patch and resetting the
		//  face list and boundary mesh information
		genericPolyPatch
		(
			const genericPolyPatch& pp,
			const polyBoundaryMesh& bm,
			const label index,
			const label newSize,
			const label newStart
		);

		//- Construct and return a clone, resetting the boundary mesh
		virtual autoPtr<polyPatch> clone(const polyBoundaryMesh& bm) const
		{
			return autoPtr<polyPatch>(new genericPolyPatch(*this, bm));
		}

		//- Construct and return a clone, resetting the face list
		//  and boundary mesh
		virtual autoPtr<polyPatch> clone
		(
			const polyBoundaryMesh& bm,
			const label index,
			const label newSize,
			const label newStart
		) const
		{
			return autoPtr<polyPatch>
				(
					new genericPolyPatch(*this, bm, index, newSize, newStart)
					);
		}


		// Destructor

		~genericPolyPatch();


		// Member functions

			//- Write the polyPatch data as a dictionary
		virtual void write(Ostream&) const;
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_genericPolyPatch_Header
