#pragma once
#ifndef _RBFFunction_Header
#define _RBFFunction_Header

#include <typeInfo.hxx>
#include <runTimeSelectionTables.hxx>
#include <tmp.hxx>
#include <autoPtr.hxx>
#include <primitiveFields.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
							 Class RBFFunction Declaration
	\*---------------------------------------------------------------------------*/

	class RBFFunction
	{
		// Private Member Functions

			//- Disallow copy construct
		RBFFunction(const RBFFunction&);

		//- Disallow default bitwise assignment
		void operator=(const RBFFunction&);


	public:

		//- Runtime type information
		TypeName("RBFFunction");


		// Declare run-time constructor selection table

		declareRunTimeSelectionTable
		(
			autoPtr,
			RBFFunction,
			dictionary,
			(
				const dictionary& dict
				),
				(dict)
		);


		// Selectors

			//- Return a pointer to the selected RBF function
		static autoPtr<RBFFunction> New
		(
			const word& type,
			const dictionary& dict
		);


		// Constructors

			//- Construct null
		RBFFunction()
		{}

		//- Create and return a clone
		virtual autoPtr<RBFFunction> clone() const = 0;


		// Destructor

		virtual ~RBFFunction()
		{}


		// Member Functions

			//- Return RBF weights
		virtual tmp<scalarField> weights
		(
			const vectorField& controlPoints,
			const vector& dataPoint
		) const = 0;
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_RBFFunction_Header
