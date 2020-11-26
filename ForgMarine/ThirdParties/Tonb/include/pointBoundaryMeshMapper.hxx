#pragma once
#ifndef _pointBoundaryMeshMapper_Header
#define _pointBoundaryMeshMapper_Header

#include <PtrList.hxx>
#include <pointMesh.hxx>
#include <pointPatchMapper.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
						Class pointBoundaryMeshMapper Declaration
	\*---------------------------------------------------------------------------*/

	class pointBoundaryMeshMapper
		:
		public PtrList<pointPatchMapper>
	{
		// Private Member Functions

			//- Disallow default bitwise copy construct
		pointBoundaryMeshMapper(const pointBoundaryMeshMapper&);

		//- Disallow default bitwise assignment
		void operator=(const pointBoundaryMeshMapper&);


	public:

		// Constructors

			//- Construct from components
		pointBoundaryMeshMapper
		(
			const pointMesh& mesh,
			const pointMapper& pointMap,
			const mapPolyMesh& mpm
		)
			:
			PtrList<pointPatchMapper>(mesh.boundary().size())
		{
			const pointBoundaryMesh& patches = mesh.boundary();

			forAll(patches, patchI)
			{
				set
				(
					patchI,
					new pointPatchMapper
					(
						patches[patchI],
						pointMap,
						mpm
					)
				);
			}
		}
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_pointBoundaryMeshMapper_Header
