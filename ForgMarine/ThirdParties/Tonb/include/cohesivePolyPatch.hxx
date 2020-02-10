#pragma once
#ifndef _cohesivePolyPatch_Header
#define _cohesivePolyPatch_Header

#include <polyPatch.hxx>
#include <SubField.hxx>
#include <FixedList.hxx>
#include <edgeList.hxx>
#include <transform.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	class patchZones;

	/*---------------------------------------------------------------------------*\
						  Class cohesivePolyPatch Declaration
	\*---------------------------------------------------------------------------*/

	class cohesivePolyPatch
		:
		public polyPatch
	{
	public:

		//- Runtime type information
		TypeName("cohesive");


		// Constructors

			//- Construct from components
		cohesivePolyPatch
		(
			const word& name,
			const label size,
			const label start,
			const label index,
			const polyBoundaryMesh& bm
		);

		//- Construct from dictionary
		cohesivePolyPatch
		(
			const word& name,
			const dictionary& dict,
			const label index,
			const polyBoundaryMesh& bm
		);

		//- Construct as copy, resetting the boundary mesh
		cohesivePolyPatch
		(
			const cohesivePolyPatch&,
			const polyBoundaryMesh&
		);

		//- Construct given the original patch and resetting the
		//  face list and boundary mesh information
		cohesivePolyPatch
		(
			const cohesivePolyPatch& pp,
			const polyBoundaryMesh& bm,
			const label index,
			const label newSize,
			const label newStart
		);

		//- Construct and return a clone, resetting the boundary mesh
		virtual autoPtr<polyPatch> clone(const polyBoundaryMesh& bm) const
		{
			return autoPtr<polyPatch>(new cohesivePolyPatch(*this, bm));
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
					new cohesivePolyPatch(*this, bm, index, newSize, newStart)
					);
		}


		// Destructor

		virtual ~cohesivePolyPatch();


		// Member Functions

			//- Initialize ordering for primitivePatch
		virtual void initOrder(const primitivePatch&) const;

		//- Return new ordering for primitivePatch.
		//  Ordering is -faceMap: for every face
		//  index of the new face -rotation:for every new face the clockwise
		//  shift of the original face. Return false if nothing changes
		//  (faceMap is identity, rotation is 0), true otherwise.
		virtual bool order
		(
			const primitivePatch&,
			labelList& faceMap,
			labelList& rotation
		) const;

		//- Synchronise communications of ordering for primitivePatch
		//  Used in cases when no topological change happens locally,
		//  but is happening on other processors
		virtual void syncOrder() const;
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_cohesivePolyPatch_Header
