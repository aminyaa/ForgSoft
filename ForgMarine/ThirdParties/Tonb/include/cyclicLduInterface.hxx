#pragma once
#ifndef _cyclicLduInterface_Header
#define _cyclicLduInterface_Header

#include <lduInterface.hxx>
#include <primitiveFieldsFwd.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
						   Class cyclicLduInterface Declaration
	\*---------------------------------------------------------------------------*/

	class cyclicLduInterface
	{

	public:

		//- Runtime type information
		TypeName("cyclicLduInterface");

		// Constructors

		// Destructor

		virtual ~cyclicLduInterface();


		// Member Functions

			// Access

				//- Return face transformation tensor
		virtual const tensorField& forwardT() const = 0;

		//- Return face reverse transformation tensor
		virtual const tensorField& reverseT() const = 0;
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_cyclicLduInterface_Header
