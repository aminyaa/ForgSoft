#pragma once
#ifndef _BlockGaussSeidelSmoother_Header
#define _BlockGaussSeidelSmoother_Header

#include <debugSwitch.hxx>
#include <BlockLduSmoother.hxx>
#include <blockGaussSeidelPrecons.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
					   Class BlockGaussSeidelSmoother Declaration
	\*---------------------------------------------------------------------------*/

	template<class Type>
	class BlockGaussSeidelSmoother
		:
		public BlockLduSmoother<Type>
	{
		// Private Data

			//- Gauss-Seidel preconditioner
		BlockGaussSeidelPrecon<Type> gs_;


		// Private Member Functions

			//- Disallow default bitwise copy construct
		BlockGaussSeidelSmoother(const BlockGaussSeidelSmoother&);

		//- Disallow default bitwise assignment
		void operator=(const BlockGaussSeidelSmoother&);


	public:

		//- Runtime type information
		static const char* typeName_() { return "GaussSeidel"; }
		static const word typeName;
		static debug::debugSwitch debug;;
		virtual const word& type() const { return typeName; };


		// Constructors

			//- Construct from components
		BlockGaussSeidelSmoother
		(
			const BlockLduMatrix<Type>& matrix,
			const dictionary& dict
		)
			:
			BlockLduSmoother<Type>(matrix),
			gs_(matrix)
		{}


		// Destructor

		virtual ~BlockGaussSeidelSmoother()
		{}


		// Member Functions

			//- Execute smoothing
		virtual void smooth
		(
			Field<Type>& x,
			const Field<Type>& b,
			const label nSweeps
		) const
		{
			for (label sweep = 0; sweep < nSweeps; sweep++)
			{
				gs_.precondition(x, b);
			}
		}
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_BlockGaussSeidelSmoother_Header
