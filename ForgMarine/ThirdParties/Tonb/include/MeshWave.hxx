#pragma once
#ifndef _MeshWave_Header
#define _MeshWave_Header

#include <FaceCellWave.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
							Class MeshWaveName Declaration
	\*---------------------------------------------------------------------------*/

	TemplateName(MeshWave);


	/*---------------------------------------------------------------------------*\
							   Class MeshWave Declaration
	\*---------------------------------------------------------------------------*/

	template <class Type>
	class MeshWave
		: public MeshWaveName
	{
		// Private data

			//- Wall information for all faces
		List<Type> allFaceInfo_;

		//- Wall information for all cells
		List<Type> allCellInfo_;

		//- Wave calculation engine.
		FaceCellWave<Type> calc_;

		// Private Member Functions

			//- Disallow default bitwise copy construct
		MeshWave(const MeshWave&);

		//- Disallow default bitwise assignment
		void operator=(const MeshWave&);

	public:

		// Constructors

			//- Construct from mesh and list of changed faces with the Type
			//  for these faces. Iterates until nothing changes or maxIter reached.
			//  (maxIter can be 0)
		MeshWave
		(
			const polyMesh& mesh,
			const labelList& initialChangedFaces,
			const List<Type>& changedFacesInfo,
			const label maxIter
		);

		//- Construct from mesh, list of changed faces with the Type
		//  for these faces and initial field.
		//  Iterates until nothing changes or maxIter reached.
		//  (maxIter can be 0)
		MeshWave
		(
			const polyMesh& mesh,
			const labelList& initialChangedFaces,
			const List<Type>& changedFacesInfo,
			const List<Type>& allCellInfo,
			const label maxIter
		);


		// Member Functions

			//- Get allFaceInfo
		const List<Type>& allFaceInfo() const
		{
			return allFaceInfo_;
		}

		//- Get allCellInfo
		const List<Type>& allCellInfo() const
		{
			return allCellInfo_;
		}


		//- Iterate until no changes or maxIter reached. Returns number of
		//  unset cells (see getUnsetCells)
		label iterate(const label maxIter)
		{
			return calc_.iterate(maxIter);
		}

		//- Get number of unvisited cells, i.e. cells that were not (yet)
		//  reached from walking across mesh. This can happen from
		//  - not enough iterations done
		//  - a disconnected mesh
		//  - a mesh without walls in it
		label getUnsetCells() const
		{
			return calc_.getUnsetCells();
		}

		//- Get number of unvisited faces
		label getUnsetFaces() const
		{
			return calc_.getUnsetFaces();
		}
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#   include <MeshWave.cxx>
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_MeshWave_Header
