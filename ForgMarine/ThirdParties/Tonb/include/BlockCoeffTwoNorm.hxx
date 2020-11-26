#pragma once
#ifndef _BlockCoeffTwoNorm_Header
#define _BlockCoeffTwoNorm_Header

#include <blockCoeffs.hxx>
#include <blockCoeffNorms.hxx>
#include <BlockCoeffNorm.hxx>
#include <coeffFields.hxx>
#include <runTimeSelectionTables.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * Forward declaration of template friend fuctions * * * * * * * //


	/*---------------------------------------------------------------------------*\
							Class BlockCoeffTwoNorm Declaration
	\*---------------------------------------------------------------------------*/

	template<class Type>
	class BlockCoeffTwoNorm
		: public BlockCoeffNorm<Type>
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
		TypeName("twoNorm");


		// Constructors

			//- Construct from dictionary
		BlockCoeffTwoNorm
		(
			const dictionary& dict
		);

		// Destructor

		virtual ~BlockCoeffTwoNorm()
		{}


		// Member functions

			//- Solve
		virtual scalar normalize
		(
			const BlockCoeff<Type>& a
		);

		virtual void coeffMag
		(
			const CoeffField<Type>& a,
			Field<scalar>& b
		);
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#   include <BlockCoeffTwoNorm.cxx>
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_BlockCoeffTwoNorm_Header
