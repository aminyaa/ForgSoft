#pragma once
#ifndef _BlockDiagonalPrecon_Header
#define _BlockDiagonalPrecon_Header

#include <BlockLduPrecon.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
						  Class BlockDiagonalPrecon Declaration
	\*---------------------------------------------------------------------------*/

	template<class Type>
	class BlockDiagonalPrecon
		:
		public BlockLduPrecon<Type>
	{
		// Private Member Functions

			//- Disallow default bitwise copy construct
		BlockDiagonalPrecon(const BlockDiagonalPrecon&);

		//- Disallow default bitwise assignment
		void operator=(const BlockDiagonalPrecon&);


	public:

		//- Runtime type information
		TypeName("diagonal");


		// Constructors

			//- Construct from components
		BlockDiagonalPrecon
		(
			const BlockLduMatrix<Type>& matrix,
			const dictionary& dict
		)
			:
			BlockLduPrecon<Type>(matrix)
		{}


		// Destructor

		virtual ~BlockDiagonalPrecon()
		{}


		// Member Functions

			//- Execute preconditioning
		virtual void precondition
		(
			Field<Type>& x,
			const Field<Type>& b
		) const;

		//- Execute preconditioning on a transposed matrix
		virtual void preconditionT
		(
			Field<Type>& xT,
			const Field<Type>& bT
		) const
		{
			return precondition(xT, bT);
		}
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#   include <BlockDiagonalPrecon.cxx>
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_BlockDiagonalPrecon_Header
