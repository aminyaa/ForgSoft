#pragma once
#ifndef _wedgePolyPatch_Header
#define _wedgePolyPatch_Header

#include <polyPatch.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
						  Class wedgePolyPatch Declaration
	\*---------------------------------------------------------------------------*/

	class wedgePolyPatch
		:
		public polyPatch
	{
		// Private data

			//- Axis of the wedge
		vector axis_;

		//- Centre normal between the wedge boundaries
		vector centreNormal_;

		//- Normal to the patch
		vector patchNormal_;

		//- Face transformation tensor
		tensor faceT_;

		//- Neighbour-cell transformation tensor
		tensor cellT_;

		//- Calculate the above tensors
		void initTransforms();


	public:

		//- Runtime type information
		TypeName("wedge");


		// Constructors

			//- Construct from components
		wedgePolyPatch
		(
			const word& name,
			const label size,
			const label start,
			const label index,
			const polyBoundaryMesh& bm
		);

		//- Construct from dictionary
		wedgePolyPatch
		(
			const word& name,
			const dictionary& dict,
			const label index,
			const polyBoundaryMesh& bm
		);

		//- Construct as copy, resetting the boundary mesh
		wedgePolyPatch(const wedgePolyPatch&, const polyBoundaryMesh&);

		//- Construct given the original patch and resetting the
		//  face list and boundary mesh information
		wedgePolyPatch
		(
			const wedgePolyPatch& pp,
			const polyBoundaryMesh& bm,
			const label index,
			const label newSize,
			const label newStart
		);

		//- Construct and return a clone, resetting the boundary mesh
		virtual autoPtr<polyPatch> clone(const polyBoundaryMesh& bm) const
		{
			return autoPtr<polyPatch>(new wedgePolyPatch(*this, bm));
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
					new wedgePolyPatch(*this, bm, index, newSize, newStart)
					);
		}


		// Member functions

			// Access

				//- Return axis of the wedge
		const vector& axis() const
		{
			return axis_;
		}

		//- Return plane normal between the wedge boundaries
		const vector& centreNormal() const
		{
			return centreNormal_;
		}

		//- Return the normal to the patch
		const vector& patchNormal() const
		{
			return patchNormal_;
		}

		//- Return face transformation tensor
		const tensor& faceT() const
		{
			return faceT_;
		}

		//- Return neighbour-cell transformation tensor
		const tensor& cellT() const
		{
			return cellT_;
		}
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_wedgePolyPatch_Header
