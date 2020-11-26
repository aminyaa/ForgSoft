#pragma once
#ifndef _mixingPlanePolyPatch_Header
#define _mixingPlanePolyPatch_Header

#include <coupledPolyPatch.hxx>
#include <mixingPlaneInterpolation.hxx>
#include <transform.hxx>
#include <word.hxx>
#include <faceZone.hxx>
#include <coordinateSystem.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
						 Class mixingPlanePolyPatch Declaration
	\*---------------------------------------------------------------------------*/

	class mixingPlanePolyPatch
		:
		public coupledPolyPatch
	{
		// Private data

			//- Shadow patch name
		const word shadowName_;

		//- Interpolation zone name
		const word zoneName_;

		//- Coordinate system for the mixing plane
		autoPtr<coordinateSystem> csPtr_;

		//- Type of mixing plane discretisation algorithm
		mixingPlaneInterpolation::discretisation discretisationType_;

		//- Orientation of the mixing plane ribbon patch
		//  sweepAxis = axis in which ribbon length is measured
		//  stackAxis = axis in which ribbon width/height is measured
		mixingPlaneInterpolation::sweepAxis sweepAxisType_;
		mixingPlaneInterpolation::stackAxis stackAxisType_;

		//- User-defined interpolation profile file name
		fileName userProfileFile_;


		// Demand-driven data

			//- Shadow patch index.  Delayed evaluation for construction
		mutable label shadowIndex_;

		//- Interpolation zone index.  Delayed evaluation for construction
		mutable label zoneIndex_;

		//- Patch-to-patch interpolation
		mutable mixingPlaneZoneInterpolation* patchToPatchPtr_;

		//- Patch-to-zone addressing
		mutable labelList* zoneAddressingPtr_;

		//- Reconstructed patch neighbour cell centres
		mutable vectorField* reconFaceCellCentresPtr_;


		// Parallel communication optimisation, stored on master processor

			//- Is the patch localised on a single processor
			// (single processor in a parallel run)?
			//  Used for parallel optimisation
		mutable bool* localParallelPtr_;

		//- List of zone faces indices received from each processor
		mutable labelListList* receiveAddrPtr_;


		// Private member functions

			//- Calculate patch-to-zone addressing
		virtual void calcZoneAddressing() const;

		//- Calculate interpolation
		virtual void calcPatchToPatch() const;


		// Geometry

			//- Calculate reconstructed cell centres
		void calcReconFaceCellCentres() const;

		//- Force calculation of transformation tensors
		virtual void calcTransforms() const;


		// Parallel communication optimisation, stored on master processor

			//- Calculate local parallel switch
		void calcLocalParallel() const;

		//- Calculate receive addressing
		void calcReceive() const;


		//- Return receive addressing
		const labelListList& receiveAddr() const;


		// Memory management

			//- Clear geometry
		void clearGeom() const;

		//- Clear out
		void clearOut() const;


	protected:

		// Protected Member functions

			//- Is the mixing plane active? (zone and shadow present)
		bool active() const;

		//- Initialise the calculation of the patch addressing
		virtual void initAddressing();

		//- Calculate the patch addressing
		virtual void calcAddressing();

		//- Initialise the calculation of the patch geometry
		virtual void initGeometry();

		//- Calculate the patch geometry
		virtual void calcGeometry();

		//- Initialise the patches for moving points
		virtual void initMovePoints(const pointField&);

		//- Correct patches after moving points
		virtual void movePoints(const pointField&);

		//- Initialise the update of the patch topology
		virtual void initUpdateMesh();

		//- Update of the patch topology
		virtual void updateMesh();


	public:

		//- Runtime type information
		TypeName("mixingPlane");


		// Constructors

			//- Construct from components
		mixingPlanePolyPatch
		(
			const word& name,
			const label size,
			const label start,
			const label index,
			const polyBoundaryMesh& bm
		);

		//- Construct from components
		mixingPlanePolyPatch
		(
			const word& name,
			const label size,
			const label start,
			const label index,
			const polyBoundaryMesh& bm,
			const word& shadowName,
			const word& zoneName,
			const coordinateSystem& cs,
			const mixingPlaneInterpolation::discretisation discretisationType,
			const mixingPlaneInterpolation::sweepAxis sweepAxisType,
			const mixingPlaneInterpolation::stackAxis stackAxisType,
			const fileName& userProfileFile
		);

		//- Construct from dictionary
		mixingPlanePolyPatch
		(
			const word& name,
			const dictionary& dict,
			const label index,
			const polyBoundaryMesh&
		);

		//- Construct as copy, resetting the boundary mesh
		mixingPlanePolyPatch
		(
			const mixingPlanePolyPatch&,
			const polyBoundaryMesh&
		);

		//- Construct as given the original patch and resetting the
		//  face list and boundary mesh information
		mixingPlanePolyPatch
		(
			const mixingPlanePolyPatch& pp,
			const polyBoundaryMesh& bm,
			const label index,
			const label newSize,
			const label newStart
		);

		//- Construct and return a clone, resetting the boundary mesh
		virtual autoPtr<polyPatch> clone(const polyBoundaryMesh& bm) const
		{
			return autoPtr<polyPatch>(new mixingPlanePolyPatch(*this, bm));
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
					new mixingPlanePolyPatch
					(
						refCast<const mixingPlanePolyPatch>(*this),
						bm,
						index,
						newSize,
						newStart
					)
					);
		}


		// Destructor

		virtual ~mixingPlanePolyPatch();


		// Member functions

			// Basic info

				//- Return shadow patch name
		const word& shadowName() const
		{
			return shadowName_;
		}

		//- Return name of interpolation face zone
		const word& zoneName() const
		{
			return zoneName_;
		}

		//- Return shadow patch index
		label shadowIndex() const;

		//- Return zone patch index
		label zoneIndex() const;

		//- Return shadow patch
		const mixingPlanePolyPatch& shadow() const;

		//- Return interpolation face zone
		const faceZone& zone() const;


		// Interpolation data

			//- Is this the master side?
		bool master() const
		{
			return index() < shadowIndex();
		}

		//- Is this the slave side?
		bool slave() const
		{
			return !master();
		}

		//- Return coordinate system
		const coordinateSystem& cs() const;

		//- Return number of profile bands
		label nProfileBands() const
		{
			return patchToPatch().nProfileBands();
		}

		//- Return patch-to-zone addressing
		const labelList& zoneAddressing() const;

		//- Is the patch localised on a single processor
		bool localParallel() const;

		//- Return reference to patch-to-patch interpolation
		//  Used only for addressing
		const mixingPlaneZoneInterpolation& patchToPatch() const;


		// Interpolation functions

			//- Interpolate face field to profile: given field on a
			//- master/slave side, create a profile field
		template<class Type>
		tmp<Field<Type> > toProfile
		(
			const Field<Type>& pf
		) const;

		template<class Type>
		tmp<Field<Type> > toProfile
		(
			const tmp<Field<Type> >& tpf
		) const;

		//- Interpolate profile to face field: given field on a profile,
		//  create a patch field
		template<class Type>
		tmp<Field<Type> > fromProfile
		(
			const Field<Type>& pf
		) const;

		template<class Type>
		tmp<Field<Type> > fromProfile
		(
			const tmp<Field<Type> >& tpf
		) const;

		//- Interpolate face field: given field on a the shadow side,
		//  create an interpolated field on this side
		template<class Type>
		tmp<Field<Type> > interpolate(const Field<Type>& pf) const;

		template<class Type>
		tmp<Field<Type> > interpolate(const tmp<Field<Type> >& tpf) const;

		//- Interpolate face field from average: given field on a the
		//  master/slave side, create interpolated field on the same side
		//  using averaged values
		template<class Type>
		tmp<Field<Type> > circumferentialAverage
		(
			const Field<Type>& pf
		) const;

		template<class Type>
		tmp<Field<Type> > circumferentialAverage
		(
			const tmp<Field<Type> >& tpf
		) const;


		// Geometric data

			//- Return reconstructed cell centres
		const vectorField& reconFaceCellCentres() const;


		// Patch ordering

			//- Initialize ordering for primitivePatch. Does not
			//  refer to *this (except for name() and type() etc.)
		virtual void initOrder(const primitivePatch&) const;

		//- Return new ordering for primitivePatch.
		//  Ordering is -faceMap: for every face
		//  index of the new face -rotation: for every new face the
		//   clockwise shift of the original face.
		//   Return false if nothing changes
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


		//- Write
		virtual void write(Ostream&) const;
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#   include <mixingPlanePolyPatchTemplates.cxx>
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_mixingPlanePolyPatch_Header
