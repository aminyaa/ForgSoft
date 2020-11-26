#pragma once
#ifndef _lduMesh_Header
#define _lduMesh_Header

#include <lduAddressing.hxx>
#include <lduInterfacePtrsList.hxx>
#include <typeInfo.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	class objectRegistry;

	/*---------------------------------------------------------------------------*\
							   Class lduMesh Declaration
	\*---------------------------------------------------------------------------*/

	class lduMesh
	{

	public:

		//- Runtime type information
		TypeName("lduMesh");


		// Constructors

		// Destructor

		virtual ~lduMesh()
		{}


		// Member Functions

			// Access

				//- Return the object registry
		virtual const objectRegistry& thisDb() const;

		//- Return ldu addressing
		virtual const lduAddressing& lduAddr() const = 0;

		//- Return a list of pointers for each patch
		//  with only those pointing to interfaces being set
		virtual lduInterfacePtrsList interfaces() const = 0;
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_lduMesh_Header
