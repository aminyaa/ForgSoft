#pragma once
#ifndef _PointPatchFieldMapper_Header
#define _PointPatchFieldMapper_Header

#include <primitiveFields.hxx>
#include <FieldMapper.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
						Class PointPatchFieldMapper Declaration
	\*---------------------------------------------------------------------------*/

	class PointPatchFieldMapper
		: public FieldMapper
	{

	public:

		// Constructors

			//- Null constructor
		PointPatchFieldMapper()
		{}
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_PointPatchFieldMapper_Header
