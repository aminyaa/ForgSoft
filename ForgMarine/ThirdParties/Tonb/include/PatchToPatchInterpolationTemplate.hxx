#pragma once
#ifndef _PatchToPatchInterpolationTemplate_Header
#define _PatchToPatchInterpolationTemplate_Header

#include <className.hxx>
#include <labelList.hxx>
#include <scalarField.hxx>
#include <pointField.hxx>
#include <faceList.hxx>
#include <intersection.hxx>
#include <tolerancesSwitch.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
					Class PatchToPatchInterpolationName Declaration
	\*---------------------------------------------------------------------------*/
	template<template<class> class Field, class Type>
	class FieldField;

	TemplateName(PatchToPatchInterpolation);


	/*---------------------------------------------------------------------------*\
					  Class PatchToPatchInterpolation Declaration
	\*---------------------------------------------------------------------------*/

	template<class FromPatch, class ToPatch>
	class PatchToPatchInterpolation
		:
		public PatchToPatchInterpolationName
	{
		// Private data

			//- Reference to the source patch
		const FromPatch& fromPatch_;

		//- Reference to the target patch
		const ToPatch& toPatch_;

		//- Type of intersection algorithm to use in projection
		intersection::algorithm alg_;

		//- Direction projection to use in projection
		intersection::direction dir_;


		// Static data

			//- Relative merge tolerance for projected points missing the target
			//  Expressed as the fraction of min involved edge size
		static const debug::tolerancesSwitch projectionTol_;

		//- Direct hit tolerance
		static const debug::tolerancesSwitch directHitTol_;


		// Point addressing

			//- Face into which each point of target patch is projected
		mutable labelList* pointAddressingPtr_;

		//- Weighting factors
		mutable FieldField<Field, scalar>* pointWeightsPtr_;

		//- Distance to intersection for patch points
		mutable scalarField* pointDistancePtr_;


		// Face addressing

			//- Face into which each face centre of target patch is projected
		mutable labelList* faceAddressingPtr_;

		//- Weighting factors
		mutable FieldField<Field, scalar>* faceWeightsPtr_;

		//- Distance to intersection for patch face centres
		mutable scalarField* faceDistancePtr_;


		// Private Member Functions

			//- Disallow default bitwise assignment
		void operator=(const PatchToPatchInterpolation&);

		//- Calculate point weights
		void calcPointAddressing() const;

		//- Calculate face weights
		void calcFaceAddressing() const;

		//- Clear all geometry and addressing
		void clearOut();


	protected:

		// Protected member functions

			//- Set weights when read from file
		void setWeights
		(
			labelList* paPtr,
			FieldField<Field, scalar>* pwPtr,
			scalarField* pdPtr,
			labelList* faPtr,
			FieldField<Field, scalar>* fwPtr,
			scalarField* fdPtr
		);


	public:

		// Constructors

			//- Construct from components
		PatchToPatchInterpolation
		(
			const FromPatch& fromPatch,
			const ToPatch& toPatch,
			const intersection::algorithm alg = intersection::FULL_RAY,
			const intersection::direction dir = intersection::VECTOR
		);

		//- Construct as copy
		PatchToPatchInterpolation
		(
			const PatchToPatchInterpolation<FromPatch, ToPatch>&
		);


		// Destructor

		~PatchToPatchInterpolation();


		// Member Functions

			// Access

				//- Return ype of intersection algorithm to use in projection
		intersection::algorithm projectionAlgo() const
		{
			return alg_;
		}

		//- Return direction projection to use in projection
		intersection::direction projectionDir() const
		{
			return dir_;
		}

		//- Return reference to point addressing
		const labelList& pointAddr() const;

		//- Return reference to point weights
		const FieldField<Field, scalar>& pointWeights() const;

		//- Return reference to face addressing
		const labelList& faceAddr() const;

		//- Return reference to face weights
		const FieldField<Field, scalar>& faceWeights() const;

		//- Return distance to intersection for patch points
		const scalarField& pointDistanceToIntersection() const;

		//- Return distance to intersection for patch face centres
		const scalarField& faceDistanceToIntersection() const;


		// Interpolation functions

			//- Interpolate point field
		template<class Type>
		tmp<Field<Type> > pointInterpolate(const Field<Type>& pf) const;

		template<class Type>
		tmp<Field<Type> > pointInterpolate
		(
			const tmp<Field<Type> >& tpf
		) const;

		//- Interpolate face field
		template<class Type>
		tmp<Field<Type> > faceInterpolate(const Field<Type>& pf) const;

		template<class Type>
		tmp<Field<Type> > faceInterpolate
		(
			const tmp<Field<Type> >& tpf
		) const;


		// Edit

			//- Correct weighting factors for moving mesh.
		bool movePoints();
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

#ifdef NoRepository
#   include <PatchToPatchInterpolationTemplate.cxx>
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_PatchToPatchInterpolationTemplate_Header
