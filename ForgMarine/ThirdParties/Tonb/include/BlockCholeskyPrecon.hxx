#pragma once
#ifndef _BlockCholeskyPrecon_Header
#define _BlockCholeskyPrecon_Header

#include <BlockLduPrecon.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
						  Class BlockCholeskyPrecon Declaration
	\*---------------------------------------------------------------------------*/

	template<class Type>
	class BlockCholeskyPrecon
		: public BlockLduPrecon<Type>
	{
		// Private Data

			//- Preconditioned diagonal
		mutable CoeffField<Type> preconDiag_;


		// Private Member Functions

			//- Disallow default bitwise copy construct
		BlockCholeskyPrecon(const BlockCholeskyPrecon&);

		//- Disallow default bitwise assignment
		void operator=(const BlockCholeskyPrecon&);

		//- Precondition the diagonal
		void calcPreconDiag();

		// Diagonal multiplication, symmetric matrix
		template<class DiagType, class ULType>
		void diagMultiply
		(
			Field<DiagType>& dDiag,
			const Field<ULType>& upper
		);

		//- Diagonal multiplication with transpose upper square coeff
		//  for the symmetric matrix
		template<class DiagType, class ULType>
		void diagMultiplyCoeffT
		(
			Field<DiagType>& dDiag,
			const Field<ULType>& upper
		);

		//- Diagonal multiplication, asymmetric matrix
		template<class DiagType, class ULType>
		void diagMultiply
		(
			Field<DiagType>& dDiag,
			const Field<ULType>& lower,
			const Field<ULType>& upper
		);

		//- ILU multiplication, symmetric matrix
		template<class DiagType, class ULType>
		void ILUmultiply
		(
			Field<Type>& x,
			const Field<DiagType>& dDiag,
			const Field<ULType>& upper,
			const Field<Type>& b
		) const;

		//- ILU multiplication, with transpose upper square coeff
		//  for a symmetric matrix
		template<class DiagType, class ULType>
		void ILUmultiplyCoeffT
		(
			Field<Type>& x,
			const Field<DiagType>& dDiag,
			const Field<ULType>& upper,
			const Field<Type>& b
		) const;

		//- ILU multiplication, asymmetric matrix
		template<class DiagType, class ULType>
		void ILUmultiply
		(
			Field<Type>& x,
			const Field<DiagType>& dDiag,
			const Field<ULType>& lower,
			const Field<ULType>& upper,
			const Field<Type>& b
		) const;

		//- ILU multiplication transposed asymmetric matrix
		template<class DiagType, class ULType>
		void ILUmultiplyTranspose
		(
			Field<Type>& x,
			const Field<DiagType>& dDiag,
			const Field<ULType>& lower,
			const Field<ULType>& upper,
			const Field<Type>& b
		) const;


		// Decoupled operations, used in template specialisation

			//- Precondition the diagonal, decoupled version
		void calcDecoupledPreconDiag();

		//- Execute preconditioning, decoupled version
		void decoupledPrecondition
		(
			Field<Type>& x,
			const Field<Type>& b
		) const;

		//- Execute preconditioning with matrix transpose,
		//  decoupled version
		void decoupledPreconditionT
		(
			Field<Type>& xT,
			const Field<Type>& bT
		) const;


	public:

		//- Runtime type information
		TypeName("Cholesky");


		// Constructors

			//- Construct from matrix for smoother use
		BlockCholeskyPrecon
		(
			const BlockLduMatrix<Type>& matrix
		);

		//- Construct from components
		BlockCholeskyPrecon
		(
			const BlockLduMatrix<Type>& matrix,
			const dictionary& dict
		);


		// Destructor

		virtual ~BlockCholeskyPrecon();


		// Member Functions

			//- Execute preconditioning
		virtual void precondition
		(
			Field<Type>& x,
			const Field<Type>& b
		) const;

		//- Execute preconditioning with matrix transpose
		virtual void preconditionT
		(
			Field<Type>& xT,
			const Field<Type>& bT
		) const;
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#   include <BlockCholeskyPrecon.cxx>
#   include <BlockCholeskyPreconDecoupled.cxx>
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_BlockCholeskyPrecon_Header
