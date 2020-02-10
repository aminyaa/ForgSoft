#pragma once
#ifndef _regionCoupleAMGInterface_Header
#define _regionCoupleAMGInterface_Header

#include <ggiAMGInterface.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
						 Class regionCoupleAMGInterface Declaration
	\*---------------------------------------------------------------------------*/

	class regionCoupleAMGInterface
		:
		public ggiAMGInterface
	{

		// Private data

			//- Is the interface coupled?
		const bool coupled_;


	public:

		//- Runtime type information
		TypeName("regionCouple");


		// Constructors

			//- Construct from fine level interface,
			//  local and neighbour restrict addressing
		regionCoupleAMGInterface
		(
			const lduPrimitiveMesh& lduMesh,
			const lduInterface& fineInterface,
			const labelField& localRestrictAddressing,
			const labelField& neighbourRestrictAddressing
		);


		// Destructor

		virtual ~regionCoupleAMGInterface();


		// Member Functions

			// Access

				//- Return true if interface is coupled
		virtual bool coupled() const
		{
			return coupled_;
		}
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_regionCoupleAMGInterface_Header
