#pragma once
#ifndef _DummyMatrix_Header
#define _DummyMatrix_Header

#include <constraint.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
							   Class DummyMatrix Declaration
	\*---------------------------------------------------------------------------*/

	template<class Type>
	class DummyMatrix
	{
		// Private Member Functions

			//- Disallow default bitwise copy construct
		DummyMatrix(const DummyMatrix&);

		//- Disallow default bitwise assignment
		void operator=(const DummyMatrix&);


	public:

		// Public typedefs

		typedef constraint<Type> ConstraintType;

		// Constructors

			//- Construct null
		DummyMatrix();

	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_DummyMatrix_Header
