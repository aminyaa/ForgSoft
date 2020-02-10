#pragma once
#ifndef _coupledPolyPatch_Header
#define _coupledPolyPatch_Header

#include <polyPatch.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
						   Class coupledPolyPatch Declaration
	\*---------------------------------------------------------------------------*/

	class coupledPolyPatch
		: public polyPatch
	{
	protected:

		// Protected data

			// Alowing derived classes to create their own transformation
			// HJ, 24/Oct/2008

			//- Offset (distance) vector from one side of the couple to the other
		mutable vectorField separation_;

		//- Face transformation tensor
		mutable tensorField forwardT_;

		//- Neighbour-cell transformation tensor
		mutable tensorField reverseT_;


		// Protected Member Functions

			//- Calculate the transformation tensors
			//  smallDist : matching distance per face
			//  absTol    : absolute error in normal
		void calcTransformTensors
		(
			const vectorField& Cf,
			const vectorField& Cr,
			const vectorField& nf,
			const vectorField& nr,
			const scalarField& smallDist,
			const scalar absTol = matchTol_()
		) const;

		//- Initialise the calculation of the patch addressing
		virtual void initAddressing() = 0;

		//- Calculate the patch addressing
		virtual void calcAddressing() = 0;

		//- Initialise the calculation of the patch geometry
		virtual void initGeometry() = 0;

		//- Calculate the patch geometry
		virtual void calcGeometry() = 0;

		//- Initialise the patches for moving points
		virtual void initMovePoints(const pointField&) = 0;

		//- Correct patches after moving points
		virtual void movePoints(const pointField&) = 0;


	public:

		//- Runtime type information
		TypeName("coupled");


		// Constructors

			//- Construct from components
		coupledPolyPatch
		(
			const word& name,
			const label size,
			const label start,
			const label index,
			const polyBoundaryMesh& bm
		);

		//- Construct from dictionary
		coupledPolyPatch
		(
			const word& name,
			const dictionary& dict,
			const label index,
			const polyBoundaryMesh& bm
		);

		//- Construct as copy, resetting the boundary mesh
		coupledPolyPatch(const coupledPolyPatch&, const polyBoundaryMesh&);

		//- Construct given the original patch and resetting the
		//  face list and boundary mesh information
		coupledPolyPatch
		(
			const coupledPolyPatch& pp,
			const polyBoundaryMesh& bm,
			const label index,
			const label newSize,
			const label newStart
		);


		// Destructor

		virtual ~coupledPolyPatch();


		// Member Functions

			// Access

				//- Return true if patch is coupled
		virtual bool coupled() const
		{
			return true;
		}


		//- Are the coupled planes separated
		bool separated() const
		{
			return separation_.size();
		}

		//- Return the offset (distance) vector from one side of the couple
		//  to the other
		const vectorField& separation() const
		{
			return separation_;
		}


		//- Are the cyclic planes parallel
		bool parallel() const
		{
			return forwardT_.empty();
		}

		//- Return face transformation tensor
		const tensorField& forwardT() const
		{
			return forwardT_;
		}

		//- Return neighbour-cell transformation tensor
		const tensorField& reverseT() const
		{
			return reverseT_;
		}


		//- Initialize ordering for primitivePatch. Does not
		//  refer to *this (except for name() and type() etc.)
		virtual void initOrder(const primitivePatch&) const = 0;

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
		) const = 0;

		//- Synchronise communications of ordering for primitivePatch
		//  Used in cases when no topological change happens locally,
		//  but is happening on other processors
		virtual void syncOrder() const = 0;
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_coupledPolyPatch_Header
