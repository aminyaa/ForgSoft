#pragma once
#ifndef _BlockGaussSeidelPrecon_Header
#define _BlockGaussSeidelPrecon_Header

#include <BlockLduPrecon.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
						  Class BlockGaussSeidelPrecon Declaration
	\*---------------------------------------------------------------------------*/

	template<class Type>
	class BlockGaussSeidelPrecon
		: public BlockLduPrecon<Type>
	{
		// Private Data

			//- Inverse of diagonal diagonal
		CoeffField<Type> invDiag_;

		//- Off-diag part of diagonal
		CoeffField<Type> LUDiag_;

		//- Temporary space for updated decoupled source
		//  Initialised with zero size and resized on first use
		mutable Field<Type> bPlusLU_;

		//- Temporary space for solution intermediate
		mutable Field<Type> bPrime_;

		//- Number of sweeps
		const label nSweeps_;


		// Private Member Functions

			//- Disallow default bitwise copy construct
		BlockGaussSeidelPrecon(const BlockGaussSeidelPrecon&);

		//- Disallow default bitwise assignment
		void operator=(const BlockGaussSeidelPrecon&);


		//- Calculate inverse diagonal
		void calcInvDiag();

		//- Block Gauss-Seidel sweep, symmetric matrix
		template<class DiagType, class ULType>
		void BlockSweep
		(
			Field<Type>& x,
			const Field<DiagType>& dD,
			const Field<ULType>& upper,
			const Field<Type>& b
		) const;

		//- Block Gauss-Seidel sweep, asymmetric matrix
		template<class DiagType, class ULType>
		void BlockSweep
		(
			Field<Type>& x,
			const Field<DiagType>& dD,
			const Field<ULType>& lower,
			const Field<ULType>& upper,
			const Field<Type>& b
		) const;


		// Decoupled operations, used in template specialisation

		   //- Calculate inverse diagonal, decoupled version
		void calcDecoupledInvDiag();

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
		static const char* typeName_() { return "GaussSeidel"; }
		static const word typeName;
		static debug::debugSwitch debug;;
		virtual const word& type() const { return typeName; };


		// Constructors

			//- Construct from matrix for smoother use
		BlockGaussSeidelPrecon
		(
			const BlockLduMatrix<Type>& matrix
		);

		//- Construct from components
		BlockGaussSeidelPrecon
		(
			const BlockLduMatrix<Type>& matrix,
			const dictionary& dict
		);


		// Destructor

		virtual ~BlockGaussSeidelPrecon()
		{}


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
#   include <BlockGaussSeidelPrecon.cxx>
#   include <BlockGaussSeidelPreconDecoupled.cxx>
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_BlockGaussSeidelPrecon_Header
