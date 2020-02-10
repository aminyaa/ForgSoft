#pragma once
#ifndef _BlockAMGPrecon_Header
#define _BlockAMGPrecon_Header

#include <BlockLduPrecon.hxx>
#include <Switch.hxx>
#include <BlockAMGCycle.hxx>
#include <BlockAMGLevel.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * Forward declaration of template friend fuctions * * * * * * * //

	template<class Type>
	class BlockAMGCycle;

	/*---------------------------------------------------------------------------*\
						   Class BlockAMGPrecon Declaration
	\*---------------------------------------------------------------------------*/

	template<class Type>
	class BlockAMGPrecon
		:
		public BlockLduPrecon<Type>
	{
		// Private Data

			//- Cycle type
		const typename BlockAMGCycle<Type>::cycleType cycle_;

		//- Number of pre-sweeps
		const label nPreSweeps_;

		//- Number of post-sweeps
		const label nPostSweeps_;

		//- Maximum number of levels
		const label nMaxLevels_;

		//- Scaling
		const Switch scale_;

		//- AMG cycle pointer
		autoPtr<BlockAMGCycle<Type> > amgPtr_;

		//- x buffer
		mutable Field<Type> xBuffer_;


		// Private Member Functions

			//- Disallow default bitwise copy construct
		BlockAMGPrecon(const BlockAMGPrecon<Type>&);

		//- Disallow default bitwise assignment
		void operator=(const BlockAMGPrecon<Type>&);


	public:

		//- Runtime type information
		TypeName("BlockAMG");


		// Constructors

			//- Construct from matrix and dictionary
		BlockAMGPrecon
		(
			const BlockLduMatrix<Type>& matrix,
			const dictionary& dict
		);


		//- Destructor
		virtual ~BlockAMGPrecon();


		// Member Functions

			//- Return number of AMG levels
		label nLevels() const;

		//- Calculate residual
		const Field<Type>& residual
		(
			const Field<Type>& x,
			const Field<Type>& b
		) const;

		//- Perform a single cycle
		void cycle
		(
			Field<Type>& x,
			const Field<Type>& b
		) const;

		//- Execute preconditioning
		virtual void precondition
		(
			Field<Type>& x,
			const Field<Type>& b
		) const;
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#   include <BlockAMGPrecon.cxx>
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_BlockAMGPrecon_Header
