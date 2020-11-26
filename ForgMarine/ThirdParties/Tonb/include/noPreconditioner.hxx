#pragma once
#ifndef _noPreconditioner_Header
#define _noPreconditioner_Header

#include <lduMatrix.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
						  Class noPreconditioner Declaration
	\*---------------------------------------------------------------------------*/

	class noPreconditioner
		:
		public lduPreconditioner
	{
		// Private Member Functions

			//- Disallow default bitwise copy construct
		noPreconditioner(const noPreconditioner&);

		//- Disallow default bitwise assignment
		void operator=(const noPreconditioner&);


	public:

		//- Runtime type information
		TypeName("none");


		// Constructors

			//- Construct from matrix components and preconditioner solver controls
		noPreconditioner
		(
			const lduMatrix& matrix,
			const FieldField<Field, scalar>& coupleBouCoeffs,
			const FieldField<Field, scalar>& coupleIntCoeffs,
			const lduInterfaceFieldPtrsList& interfaces,
			const dictionary& dict
		);


		// Destructor

		virtual ~noPreconditioner()
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

#endif // !_noPreconditioner_Header
