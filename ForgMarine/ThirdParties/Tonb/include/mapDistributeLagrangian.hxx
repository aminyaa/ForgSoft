#pragma once
#ifndef _mapDistributeLagrangian_Header
#define _mapDistributeLagrangian_Header

#include <mapDistribute.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	class mapPolyMesh;

	/*---------------------------------------------------------------------------*\
							   Class mapDistributeLagrangian Declaration
	\*---------------------------------------------------------------------------*/

	class mapDistributeLagrangian
	{
		// Private data

			//- Map to distribute particles
		const mapDistribute particleMap_;

		//- Per element in subsetted mesh the cell label
		const labelListList constructCellLabels_;


	public:

		// Constructors

			//- Construct from components
		mapDistributeLagrangian
		(
			const label nNewParticles,
			const labelListList& subParticleMap,
			const labelListList& constructParticleMap,
			const labelListList& constructCellLabels
		)
			:
			particleMap_(nNewParticles, subParticleMap, constructParticleMap),
			constructCellLabels_(constructCellLabels)
		{}

		//- Construct from components and steal storage
		mapDistributeLagrangian
		(
			const label nNewParticles,
			labelListList& subParticleMap,
			labelListList& constructParticleMap,
			labelListList& constructCellLabels,
			const bool reUse
		)
			:
			particleMap_
			(
				nNewParticles,
				subParticleMap,
				constructParticleMap,
				reUse
			),
			constructCellLabels_(constructCellLabels, reUse)
		{}


		// Member Functions

			// Access

				//- Distribution map
		const mapDistribute& particleMap() const
		{
			return particleMap_;
		}

		//- Per received particle the destination cell label
		const labelListList& constructCellLabels() const
		{
			return constructCellLabels_;
		}


		// Edit

			//- distribute list of lagrangian data
		template<class T>
		void distributeLagrangianData(List<T>& lst) const
		{
			particleMap_.distribute(lst);
		}

		//- Correct for topo change.
		void updateMesh(const mapPolyMesh&)
		{
			notImplemented
			(
				"mapDistributeLagrangian::updateMesh(const mapPolyMesh&)"
			);
		}
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_mapDistributeLagrangian_Header
