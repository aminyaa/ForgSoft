#pragma once
#ifndef _morphFieldMapper_Header
#define _morphFieldMapper_Header

#include <Field.hxx>
#include <Map.hxx>
#include <FieldMapper.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
							   Class morphFieldMapper Declaration
	\*---------------------------------------------------------------------------*/

	class morphFieldMapper
		: public FieldMapper
	{

	public:

		// Constructors

			//- Null constructor
		morphFieldMapper()
		{}


		// Destructor

		virtual ~morphFieldMapper()
		{}


		// Member Functions

			//- Return size of field before mapping
		virtual label sizeBeforeMapping() const = 0;

		//- Are there any inserted objects
		virtual bool insertedObjects() const = 0;

		//- Return list of inserted objects
		virtual const labelList& insertedObjectLabels() const = 0;
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_morphFieldMapper_Header
