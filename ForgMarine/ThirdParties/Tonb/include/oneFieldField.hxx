#pragma once
#ifndef _oneFieldField_Header
#define _oneFieldField_Header

#include <oneField.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
							   Class oneField Declaration
	\*---------------------------------------------------------------------------*/

	class oneFieldField
		: public one
	{

	public:

		// Constructors

			//- Construct null
		oneFieldField()
		{}


		// Member Operators

		inline oneField operator[](const label) const;
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include <oneFieldFieldI.hxx>

#endif // !_oneFieldField_Header
