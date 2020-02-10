#pragma once
#ifndef _BlockLduSmoother_Header
#define _BlockLduSmoother_Header

#include <blockLduMatrices.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
							Class BlockLduSmoother Declaration
	\*---------------------------------------------------------------------------*/

	template<class Type>
	class BlockLduSmoother
	{
		// Private Member Functions

			//- Disallow default bitwise copy construct
		BlockLduSmoother(const BlockLduSmoother&);

		//- Disallow default bitwise assignment
		void operator=(const BlockLduSmoother&);


	protected:

		// Protected data

			//- Matrix reference
		const BlockLduMatrix<Type>& matrix_;


	public:

		//- Runtime type information
		TypeName("BlockLduSmoother");


		// Declare run-time constructor selection tables

		declareRunTimeSelectionTable
		(
			autoPtr,
			BlockLduSmoother,
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
		BlockLduSmoother(const BlockLduMatrix<Type>& matrix)
			:
			matrix_(matrix)
		{}


		// Selectors

			//- Select given matrix and dictionary
		static autoPtr<BlockLduSmoother<Type> > New
		(
			const BlockLduMatrix<Type>& matrix,
			const dictionary& dict,
			const word keyword = word("smoother")
		);


		// Destructor

		virtual ~BlockLduSmoother()
		{}


		// Member Functions

			//- Execute smoothing
		virtual void smooth
		(
			Field<Type>& x,
			const Field<Type>& b,
			const label nSweeps
		) const = 0;
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#   include <BlockLduSmoother.cxx>
#endif

#define makeBlockSmoother(SmootherType, typeSmootherType)                    \
                                                                             \
defineNamedTemplateTypeNameAndDebug(typeSmootherType, 0);                    \
                                                                             \
addToRunTimeSelectionTable(SmootherType, typeSmootherType, dictionary);

#define makeBlockSmoothers(smootherType)                                       \
                                                                             \
makeBlockSmoother(blockScalarSmoother, smootherType##Scalar);                  \
makeBlockSmoother(blockVectorSmoother, smootherType##Vector);                  \
makeBlockSmoother(blockTensorSmoother, smootherType##Tensor);


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_BlockLduSmoother_Header
