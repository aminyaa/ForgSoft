#pragma once
#ifndef _oneField_Header
#define _oneField_Header

#include <one.hxx>
#include <scalar.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
							   Class oneField Declaration
	\*---------------------------------------------------------------------------*/

	class oneField
		: public one
	{
	public:

		// Constructors

			//- Construct null
		oneField()
		{}


		// Member Operators

		inline scalar operator[](const label) const;
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include <oneFieldI.hxx>

#endif // !1
