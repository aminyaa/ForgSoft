#pragma once
#ifndef _UniformDimensionedField_Header
#define _UniformDimensionedField_Header

#include <regIOobject.hxx>
#include <dimensionedType.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
						 Class UniformDimensionedField Declaration
	\*---------------------------------------------------------------------------*/

	template<class Type>
	class UniformDimensionedField
		:
		public regIOobject,
		public dimensioned<Type>
	{

	public:

		//- Runtime type information
		TypeName("UniformDimensionedField");


		// Constructors

			//- Construct null
		UniformDimensionedField();

		//- Construct from components
		UniformDimensionedField(const IOobject&, const dimensioned<Type>&);

		//- Construct as copy
		UniformDimensionedField(const UniformDimensionedField<Type>&);

		//- Construct from Istream
		UniformDimensionedField(const IOobject&);


		//- Destructor
		virtual ~UniformDimensionedField();


		// Member Functions

			//- Name function provided to resolve the ambiguity between the
			//  name functions in regIOobject and dimensioned<Type>
		virtual const word& name() const
		{
			return dimensioned<Type>::name();
		}

		bool writeData(Ostream&) const;


		// Member Operators

		void operator=(const UniformDimensionedField<Type>&);
		void operator=(const dimensioned<Type>&);
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#   include <UniformDimensionedField.cxx>
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_UniformDimensionedField_Header
