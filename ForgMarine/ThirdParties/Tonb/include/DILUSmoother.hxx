#pragma once
#ifndef _DILUSmoother_Header
#define _DILUSmoother_Header

#include <lduMatrix.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
							Class DILUSmoother Declaration
	\*---------------------------------------------------------------------------*/

	class DILUSmoother
		: public lduSmoother
	{
		// Private data

			//- The reciprocal preconditioned diagonal
		scalarField rD_;


	public:

		//- Runtime type information
		TypeName("DILU");


		// Constructors

			//- Construct from matrix components
		DILUSmoother
		(
			const lduMatrix& matrix,
			const FieldField<Field, scalar>& coupleBouCoeffs,
			const FieldField<Field, scalar>& coupleIntCoeffs,
			const lduInterfaceFieldPtrsList& interfaces
		);


		// Member Functions

			//- Smooth the solution for a given number of sweeps
		void smooth
		(
			scalarField& psi,
			const scalarField& source,
			const direction cmpt,
			const label nSweeps
		) const;
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_DILUSmoother_Header
