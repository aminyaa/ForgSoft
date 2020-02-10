#pragma once
#ifndef _zeroField_Header
#define _zeroField_Header

#include <zero.hxx>
#include <scalar.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
							   Class zeroField Declaration
	\*---------------------------------------------------------------------------*/

	class zeroField
		: public zero
	{
	public:

		// Constructors

			//- Construct null
		zeroField()
		{}


		// Member Operators

		inline scalar operator[](const label) const;

		inline zeroField field() const;

		inline zeroField oldTime() const;
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include <zeroFieldI.hxx>

#endif // !1
