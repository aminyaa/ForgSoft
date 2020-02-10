#pragma once
#ifndef _BlockCoeffNorm_Header
#define _BlockCoeffNorm_Header

#include <dictionary.hxx>
#include <blockCoeffs.hxx>
#include <coeffFields.hxx>
#include <runTimeSelectionTables.hxx>
#include <typeInfo.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * Forward declaration of template friend fuctions * * * * * * * //


	/*---------------------------------------------------------------------------*\
							Class BlockCoeffNorm Declaration
	\*---------------------------------------------------------------------------*/

	template<class Type>
	class BlockCoeffNorm
	{
		// Private data

			//- Control data dictionary
		dictionary dict_;


	protected:

		// Protected Member Functions

			//- Return dictionary
		const dictionary& dict() const
		{
			return dict_;
		}


	public:

		//- Runtime type information
		TypeName("BlockCoeffNorm");

		// Declare run-time constructor selection tables

		declareRunTimeSelectionTable
		(
			autoPtr,
			BlockCoeffNorm,
			dictionary,
			(
				const dictionary& dict
				),
				(
					dict
					)
		);


		// Constructors

			//- Construct from dictionary
		BlockCoeffNorm
		(
			const dictionary& dict
		);


		// Selectors

			//- Return a new norm calculator
		static autoPtr<BlockCoeffNorm<Type> > New
		(
			const dictionary& dict
		);


		// Destructor

		virtual ~BlockCoeffNorm()
		{}


		// Member functions

			//- Solve
		virtual scalar normalize
		(
			const BlockCoeff<Type>& a
		) = 0;

		virtual void coeffMag
		(
			const CoeffField<Type>& a,
			Field<scalar>& b
		) = 0;
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#   include <BlockCoeffNorm.cxx>
#endif

#define makeBlockCoeffNorm(BlockCoeffNormType, typeBlockCoeffNormType)        \
                                                                              \
defineNamedTemplateTypeNameAndDebug(typeBlockCoeffNormType, 0);               \
                                                                              \
addToRunTimeSelectionTable(BlockCoeffNormType, typeBlockCoeffNormType, dictionary);

#define makeBlockCoeffNorms(blockCoeffNormType)                               \
                                                                              \
makeBlockCoeffNorm(blockScalarCoeffNorm, blockCoeffNormType##Scalar);         \
makeBlockCoeffNorm(blockVectorCoeffNorm, blockCoeffNormType##Vector);         \
makeBlockCoeffNorm(blockTensorCoeffNorm, blockCoeffNormType##Tensor);


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_BlockCoeffNorm_Header
