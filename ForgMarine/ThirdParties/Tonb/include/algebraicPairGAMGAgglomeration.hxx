#pragma once
#ifndef _algebraicPairGAMGAgglomeration_Header
#define _algebraicPairGAMGAgglomeration_Header

#include <pairGAMGAgglomeration.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
					 Class algebraicPairGAMGAgglomeration Declaration
	\*---------------------------------------------------------------------------*/

	class algebraicPairGAMGAgglomeration
		: public pairGAMGAgglomeration
	{

	public:

		//- Runtime type information
		TypeName("algebraicPair");


		// Constructors

			//- Construct given mesh and controls
		algebraicPairGAMGAgglomeration
		(
			const lduMatrix& matrix,
			const dictionary& dict
		);
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_algebraicPairGAMGAgglomeration_Header
