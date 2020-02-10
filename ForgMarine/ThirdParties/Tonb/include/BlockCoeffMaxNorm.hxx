#pragma once
#ifndef _BlockCoeffMaxNorm_Header
#define _BlockCoeffMaxNorm_Header

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
							Class BlockCoeffMaxNorm Declaration
	\*---------------------------------------------------------------------------*/

	template<class Type>
	class BlockCoeffMaxNorm
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
		TypeName("maxNorm");


		// Constructors

			//- Construct from dictionary
		BlockCoeffMaxNorm
		(
			const dictionary& dict
		);

		// Destructor

		virtual ~BlockCoeffMaxNorm()
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
#   include <BlockCoeffMaxNorm.cxx>
#endif

#endif // !_BlockCoeffMaxNorm_Header
