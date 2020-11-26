#pragma once
#ifndef _pointPatchMapper_Header
#define _pointPatchMapper_Header

#include <pointMapper.hxx>
#include <PointPatchFieldMapper.hxx>
#include <pointPatch.hxx>
#include <primitiveFields.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// Forward declaration of classes
	class pointPatch;
	class mapPolyMesh;

	/*---------------------------------------------------------------------------*\
						   Class pointPatchMapper Declaration
	\*---------------------------------------------------------------------------*/

	class pointPatchMapper
		:
		public PointPatchFieldMapper
	{
		// Private data

			//- Reference to patch
		const pointPatch& patch_;

		//- Reference to point mapper for internal field
		const morphFieldMapper& pointMapper_;

		//- Reference to mapping data
		const mapPolyMesh& mpm_;

		//- Size before mapping
		const label sizeBeforeMapping_;


		// Demand-driven private data

			//- Direct addressing (only one form of addressing is used)
		mutable labelList* directAddrPtr_;

		//- Interpolated addressing (only one form of addressing is used)
		mutable labelListList* interpolationAddrPtr_;

		//- Interpolation weights
		mutable scalarListList* weightsPtr_;


		// Private Member Functions

			//- Disallow default bitwise copy construct
		pointPatchMapper
		(
			const pointPatchMapper&
		);

		//- Disallow default bitwise assignment
		void operator=(const pointPatchMapper&);


		//- Calculate addressing for mapping with inserted cells
		void calcAddressing() const;

		//- Clear out local storage
		void clearOut();


	public:

		// Static data members

		// Constructors

			//- Construct from mappers
		pointPatchMapper
		(
			const pointPatch& patch,
			const pointMapper& pointMap,
			const mapPolyMesh& mpm
		);


		// Destructor

		virtual ~pointPatchMapper();


		// Member Functions

			//- Return size
		virtual label size() const
		{
			return patch_.size();
		}

		//- Return size of field before mapping
		virtual label sizeBeforeMapping() const
		{
			return sizeBeforeMapping_;
		}

		//- Is the mapping direct
		virtual bool direct() const
		{
			return pointMapper_.direct();
		}

		//- Return direct addressing
		virtual const unallocLabelList& directAddressing() const;

		//- Return interpolated addressing
		virtual const labelListList& addressing() const;

		//- Return interpolaion weights
		virtual const scalarListList& weights() const;

	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_pointPatchMapper_Header
