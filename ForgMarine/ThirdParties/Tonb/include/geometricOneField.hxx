#pragma once
#ifndef _geometricOneField_Header
#define _geometricOneField_Header

#include <oneFieldField.hxx>
#include <scalar.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
						  Class geometricOneField Declaration
	\*---------------------------------------------------------------------------*/

	class geometricOneField
		: public one
	{

	public:

		// Constructors

			//- Construct null
		geometricOneField()
		{}


		// Member Operators

		inline scalar operator[](const label) const;

		inline oneField field() const;

		inline oneField oldTime() const;

		inline oneFieldField boundaryField() const;
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include <geometricOneFieldI.hxx>

#endif // !_geometricOneField_Header
