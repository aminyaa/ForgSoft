#pragma once
#ifndef _DICGaussSeidelSmoother_Header
#define _DICGaussSeidelSmoother_Header

#include <DICSmoother.hxx>
#include <GaussSeidelSmoother.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
					   Class DICGaussSeidelSmoother Declaration
	\*---------------------------------------------------------------------------*/

	class DICGaussSeidelSmoother
		: public lduSmoother
	{
		// Private data

		DICSmoother dicSmoother_;

		GaussSeidelSmoother gsSmoother_;


	public:

		//- Runtime type information
		TypeName("DICGaussSeidel");


		// Constructors

			//- Construct from matrix components
		DICGaussSeidelSmoother
		(
			const lduMatrix& matrix,
			const FieldField<Field, scalar>& coupleBouCoeffs,
			const FieldField<Field, scalar>& coupleIntCoeffs,
			const lduInterfaceFieldPtrsList& interfaces
		);


		// Member Functions

			//- Execute smoothing
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


#endif // !_DICGaussSeidelSmoother_Header
