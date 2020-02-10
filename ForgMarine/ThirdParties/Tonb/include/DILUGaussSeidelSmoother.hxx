#pragma once
#ifndef _DILUGaussSeidelSmoother_Header
#define _DILUGaussSeidelSmoother_Header

#include <DILUSmoother.hxx>
#include <GaussSeidelSmoother.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
					   Class DILUGaussSeidelSmoother Declaration
	\*---------------------------------------------------------------------------*/

	class DILUGaussSeidelSmoother
		: public lduSmoother
	{
		// Private data

		DILUSmoother diluSmoother_;
		GaussSeidelSmoother gsSmoother_;


	public:

		//- Runtime type information
		TypeName("DILUGaussSeidel");


		// Constructors

			//- Construct from matrix components
		DILUGaussSeidelSmoother
		(
			const lduMatrix& matrix,
			const FieldField<Field, scalar>& coupleBouCoeffs,
			const FieldField<Field, scalar>& coupleIntCoeffs,
			const lduInterfaceFieldPtrsList& interfaces
		);


		// Member Functions

			//- Smooth the solution for a given number of sweeps
		virtual void smooth
		(
			scalarField& psi,
			const scalarField& Source,
			const direction cmpt,
			const label nSweeps
		) const;
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_DILUGaussSeidelSmoother_Header
