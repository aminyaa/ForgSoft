#pragma once
#ifndef _cyclicGGIAMGInterface_Header
#define _cyclicGGIAMGInterface_Header

#include <AMGInterface.hxx>
#include <ggiAMGInterface.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
						 Class cyclicGGIAMGInterface Declaration
	\*---------------------------------------------------------------------------*/

	class cyclicGGIAMGInterface
		: public ggiAMGInterface
	{
	public:

		//- Runtime type information
		TypeName("cyclicGgi");


		// Constructors

			//- Construct from fine level interface,
			//  local and neighbour restrict addressing
		cyclicGGIAMGInterface
		(
			const lduPrimitiveMesh& lduMesh,
			const lduInterface& fineInterface,
			const labelField& localRestrictAddressing,
			const labelField& neighbourRestrictAddressing
		);


		//- Destructor
		virtual ~cyclicGGIAMGInterface();
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_cyclicGGIAMGInterface_Header
