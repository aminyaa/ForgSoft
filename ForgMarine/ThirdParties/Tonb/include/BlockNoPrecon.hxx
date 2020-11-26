#pragma once
#ifndef _BlockNoPrecon_Header
#define _BlockNoPrecon_Header

#include <typeInfo.hxx>
#include <BlockLduPrecon.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	template<class Type>
	class Field;

	/*---------------------------------------------------------------------------*\
						   Class BlockNoPrecon Declaration
	\*---------------------------------------------------------------------------*/

	template<class Type>
	class BlockNoPrecon
		:
		public BlockLduPrecon<Type>
	{
		// Private Member Functions

			//- Disallow default bitwise copy construct
		BlockNoPrecon(const BlockNoPrecon&);

		//- Disallow default bitwise assignment
		void operator=(const BlockNoPrecon&);


	public:

		//- Runtime type information
		TypeName("none");


		// Constructors

			//- Construct from components
		BlockNoPrecon
		(
			const BlockLduMatrix<Type>& matrix,
			const dictionary& dict
		)
			:
			BlockLduPrecon<Type>(matrix)
		{}


		// Destructor

		virtual ~BlockNoPrecon()
		{}


		// Member Functions

			//- Execute preconditioning
		virtual void precondition
		(
			Field<Type>& x,
			const Field<Type>& b
		) const
		{
			x = b;
		}

		//- Execute preconditioning
		virtual void preconditionT
		(
			Field<Type>& xT,
			const Field<Type>& bT
		) const
		{
			precondition(xT, bT);
		}
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_BlockNoPrecon_Header
