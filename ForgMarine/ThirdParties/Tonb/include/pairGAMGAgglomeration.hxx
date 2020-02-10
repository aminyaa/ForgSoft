#pragma once
#ifndef _pairGAMGAgglomeration_Header
#define _pairGAMGAgglomeration_Header

#include <primitiveFieldsFwd.hxx>
#include <GAMGAgglomeration.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
					   Class pairGAMGAgglomeration Declaration
	\*---------------------------------------------------------------------------*/

	class pairGAMGAgglomeration
		:
		public GAMGAgglomeration
	{
		// Private data

			//- Number of levels to merge, 1 = don't merge, 2 = merge pairs etc.
		label mergeLevels_;


	protected:

		// Protected Member Functions

			//- Calculate and return agglomeration of given level
		tmp<labelField> agglomerate
		(
			label& nCoarseCells,
			const lduAddressing& fineMatrixAddressing,
			const scalarField& faceWeights
		);

		//- Agglomerate all levels starting from the given face weights
		void agglomerate
		(
			const lduMesh& mesh,
			const scalarField& faceWeights
		);

		void combineLevels(const label curLevel);

		//- Disallow default bitwise copy construct
		pairGAMGAgglomeration(const pairGAMGAgglomeration&);

		//- Disallow default bitwise assignment
		void operator=(const pairGAMGAgglomeration&);


	public:

		//- Runtime type information
		TypeName("pair");


		// Constructors

			//- Construct given mesh and controls
		pairGAMGAgglomeration
		(
			const lduMesh& mesh,
			const dictionary& dict
		);
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_pairGAMGAgglomeration_Header
