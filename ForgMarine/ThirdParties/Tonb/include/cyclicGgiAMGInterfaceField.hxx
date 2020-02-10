#pragma once
#ifndef _cyclicGgiAMGInterfaceField_Header
#define _cyclicGgiAMGInterfaceField_Header

#include <AMGInterfaceField.hxx>
#include <ggiAMGInterfaceField.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
					  Class cyclicGgiAMGInterfaceField Declaration
	\*---------------------------------------------------------------------------*/

	class cyclicGgiAMGInterfaceField
		: public ggiAMGInterfaceField
	{
	public:

		//- Runtime type information
		TypeName("cyclicGgi");


		// Constructors

			//- Construct from AMG interface and fine level interface field
		cyclicGgiAMGInterfaceField
		(
			const AMGInterface& AMGCp,
			const lduInterfaceField& fineInterfaceField
		);


		// Destructor

		virtual ~cyclicGgiAMGInterfaceField();
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_cyclicGgiAMGInterfaceField_Header
