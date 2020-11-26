#pragma once
#ifndef _extendedBlockLduMatrix_Header
#define _extendedBlockLduMatrix_Header

#include <extendedLduAddressing.hxx>
#include <BlockLduMatrix.hxx>
#include <className.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{


	/*---------------------------------------------------------------------------*\
					   Class extendedBlockLduMatrix Declaration
	\*---------------------------------------------------------------------------*/

	template<class Type>
	class extendedBlockLduMatrix
	{
		// Public data type

		typedef CoeffField<Type> TypeCoeffField;


	private:

		// Private data

			//- Reference to underlying BlockLduMatrix
		const BlockLduMatrix<Type>& basicBlockLduMatrix_;

		//- Reference to extended ldu addressing
		const extendedLduAddressing& extLduAddr_;

		//- Extended lower coeffs
		CoeffField<Type>* extendedLowerPtr_;

		//- Extended upper coeffs
		CoeffField<Type>* extendedUpperPtr_;


		// Private member functions

			//- Disallow default bitwise copy construct
		extendedBlockLduMatrix(const extendedBlockLduMatrix<Type>&);

		//- Disallow default bitwise assignement
		void operator=(const extendedBlockLduMatrix<Type>&);


		// Helper functions

			//- Clear all demand driven data - helper function
		void clearOut();

		//- Map upper and lower coeffs from ordinary block matrix to
		//  extended block matrix
		void mapOffDiagCoeffs(const BlockLduMatrix<Type>&);


	public:


		ClassName("extendedBlockLduMatrix");


		// Constructors

			//- Construct given BlockduMatrix, extension level and polyMesh
		extendedBlockLduMatrix
		(
			const BlockLduMatrix<Type>&,
			const extendedLduAddressing&
		);


		//- Destructor
		~extendedBlockLduMatrix();


		// Member functions

			// Access

				//- Const access to underlying basic BlockLduMatrix
		const lduMatrix& basicBlockLduMatrix() const
		{
			return basicBlockLduMatrix_;
		};

		//- Const access to extendedLduAddressing
		const extendedLduAddressing& extendedLduAddr() const
		{
			return extLduAddr_;
		};

		//- Non-const access to extended lower coeffs
		TypeCoeffField& extendedLower();

		//- Non-const access to extended upper coeffs
		TypeCoeffField& extendedUpper();

		//- Const access to extended lower coeffs
		const TypeCoeffField& extendedLower() const;

		//- Const access to extended upper coeffs
		const TypeCoeffField& extendedUpper() const;
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#   include <extendedBlockLduMatrix.cxx>
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_extendedBlockLduMatrix_Header
