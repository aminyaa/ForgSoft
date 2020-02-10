#pragma once
#ifndef _FieldMapper_Header
#define _FieldMapper_Header

#include <labelList.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
							   Class FieldMapper Declaration
	\*---------------------------------------------------------------------------*/

	class FieldMapper
	{

	public:

		// Constructors

			//- Null constructor
		FieldMapper()
		{}


		// Destructor

		virtual ~FieldMapper()
		{}


		// Member Functions

		virtual label size() const = 0;

		virtual label sizeBeforeMapping() const = 0;

		virtual bool direct() const = 0;

		virtual const unallocLabelList& directAddressing() const
		{
			FatalErrorIn("FieldMapper::directAddressing() const")
				<< "attempt to access null direct addressing"
				<< abort(FatalError);

			return unallocLabelList::null();
		}

		virtual const labelListList& addressing() const
		{
			FatalErrorIn("FieldMapper::addressing() const")
				<< "attempt to access null interpolation addressing"
				<< abort(FatalError);

			return labelListList::null();
		}

		virtual const scalarListList& weights() const
		{
			FatalErrorIn("FieldMapper::weights() const")
				<< "attempt to access null interpolation weights"
				<< abort(FatalError);

			return scalarListList::null();
		}


		// Member Operators

		template<class Type>
		tmp<Field<Type>> operator()(const Field<Type>& f) const
		{
			return tmp<Field<Type>>(new Field<Type>(f, *this));
		}
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_FieldMapper_Header
