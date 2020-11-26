#pragma once
#ifndef _diagonalPreconditioner_Header
#define _diagonalPreconditioner_Header

#include <lduMatrix.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
							   Class diagonalPreconditioner Declaration
	\*---------------------------------------------------------------------------*/

	class diagonalPreconditioner
		:
		public lduPreconditioner
	{
		// Private data

			//- The reciprocal diagonal
		scalarField rD;


		// Private Member Functions

			//- Disallow default bitwise copy construct
		diagonalPreconditioner(const diagonalPreconditioner&);

		//- Disallow default bitwise assignment
		void operator=(const diagonalPreconditioner&);


	public:

		//- Runtime type information
		TypeName("diagonal");


		// Constructors

			//- Construct from matrix components and preconditioner solver controls
		diagonalPreconditioner
		(
			const lduMatrix& matrix,
			const FieldField<Field, scalar>& coupleBouCoeffs,
			const FieldField<Field, scalar>& coupleIntCoeffs,
			const lduInterfaceFieldPtrsList& interfaces,
			const dictionary& dict
		);


		// Destructor

		virtual ~diagonalPreconditioner()
		{}


		// Member Functions

			//- Execute preconditioning
		virtual void precondition
		(
			scalarField& wA,
			const scalarField& rA,
			const direction cmpt = 0
		) const;

		//- Execute preconditioning with matrix transpose
		virtual void preconditionT
		(
			scalarField& wT,
			const scalarField& rT,
			const direction cmpt = 0
		) const
		{
			precondition(wT, rT, cmpt);
		}
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_diagonalPreconditioner_Header
