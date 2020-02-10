#pragma once
#ifndef _BlockLduPrecon_Header
#define _BlockLduPrecon_Header

#include <BlockLduMatrix.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
						  Class BlockLduPrecon Declaration
	\*---------------------------------------------------------------------------*/

	template<class Type>
	class BlockLduPrecon
	{
		// Private Member Functions

			//- Disallow default bitwise copy construct
		BlockLduPrecon(const BlockLduPrecon&);

		//- Disallow default bitwise assignment
		void operator=(const BlockLduPrecon&);


	protected:

		// Protected data

			//- Matrix reference
		const BlockLduMatrix<Type>& matrix_;


	public:

		//- Runtime type information
		TypeName("BlockLduPrecon");


		// Declare run-time constructor selection tables

		declareRunTimeSelectionTable
		(
			autoPtr,
			BlockLduPrecon,
			dictionary,
			(
				const BlockLduMatrix<Type>& matrix,
				const dictionary& dict
				),
				(
					matrix,
					dict
					)
		);


		// Constructors

			//- Construct from matrix
		BlockLduPrecon(const BlockLduMatrix<Type>& matrix)
			:
			matrix_(matrix)
		{}


		// Selectors

			//- Select given matrix and dictionary
		static autoPtr<BlockLduPrecon<Type> > New
		(
			const BlockLduMatrix<Type>& matrix,
			const dictionary& dict,
			const word keyword = word("preconditioner")
		);


		// Destructor

		virtual ~BlockLduPrecon()
		{}


		// Member Functions

			//- Execute preconditioning
		virtual void precondition
		(
			Field<Type>& x,
			const Field<Type>& b
		) const = 0;

		//- Execute preconditioning on a transposed matrix
		virtual void preconditionT
		(
			Field<Type>& xT,
			const Field<Type>& bT
		) const
		{
			notImplemented
			(
				type() + "::preconditionT"
				"(Field<Type>& xT, const Field<Type>& bT) const"
			);
		}
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#   include <BlockLduPrecon.cxx>
#endif

#define makeBlockPrecon(PreconType, typePreconType)                          \
                                                                             \
defineNamedTemplateTypeNameAndDebug(typePreconType, 0);                      \
                                                                             \
addToRunTimeSelectionTable(PreconType, typePreconType, dictionary);

#define makeBlockPrecons(preconType)                                         \
                                                                             \
makeBlockPrecon(blockScalarPrecon, preconType##Scalar);                      \
makeBlockPrecon(blockVectorPrecon, preconType##Vector);                      \
makeBlockPrecon(blockTensorPrecon, preconType##Tensor);


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_BlockLduPrecon_Header
