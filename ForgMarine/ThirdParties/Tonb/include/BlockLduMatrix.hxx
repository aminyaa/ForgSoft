#pragma once
#ifndef _BlockLduMatrix_Header
#define _BlockLduMatrix_Header

#include <coeffFields.hxx>
#include <FieldField.hxx>
#include <lduMesh.hxx>
#include <HashSet.hxx>
#include <BlockLduInterfaceFieldPtrsList.hxx>
#include <Map.hxx>
#include <optimisationSwitch.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
						 Class blockLduMatrix Declaration
	\*---------------------------------------------------------------------------*/

	class blockLduMatrix
	{
	public:

		// Static data

		//ClassName("blockLduMatrix");


		// Constructors

			//- Construct null
		blockLduMatrix()
		{}
	};



	// * * * * * * Forward declaration of template friend fuctions * * * * * * * //

	template<class Type>
	class BlockLduMatrix;

	template<class Type>
	Ostream& operator<<(Ostream&, const BlockLduMatrix<Type>&);

	template<class Type>
	class BlockConstraint;


	/*---------------------------------------------------------------------------*\
							Class BlockLduMatrix Declaration
	\*---------------------------------------------------------------------------*/

	template<class Type>
	class BlockLduMatrix
		:
		public blockLduMatrix,
		public refCount
	{
	public:

		// Public data types

		typedef CoeffField<Type> TypeCoeffField;
		typedef Field<Type> TypeField;
		typedef BlockConstraint<Type> ConstraintType;

		ClassName("blockLduMatrix");


	private:

		// Private data

			// LDU mesh reference
		const lduMesh& lduMesh_;

		//- Eliminated equations
		//  Consider adding solo cells on construction.  HJ, 26/Oct/2012
		labelHashSet eliminatedEqns_;


		// Block matrix elements

			//- Diagonal coefficients
		CoeffField<Type>* diagPtr_;

		//- Upper triangle coefficients.  Also used for symmetric matrix
		CoeffField<Type>* upperPtr_;

		//- Lower triangle coefficients
		CoeffField<Type> *lowerPtr_;


		// Coupling

			//- List of coupled interfaces
		typename BlockLduInterfaceFieldPtrsList<Type>::Type interfaces_;

		//- Coupled interface coefficients, upper
		FieldField<CoeffField, Type> coupleUpper_;

		//- Coupled interface coefficients, lower
		FieldField<CoeffField, Type> coupleLower_;


		// Constraints

			//- Equation triangle map
		mutable Map<ConstraintType> fixedEqns_;


		// Private static data

			//- Matrix constraint fill-in
			//  Equals to the estimated fraction of fixed nodes in the matrix
		static const debug::optimisationSwitch fixFillIn;


		// Private member functions

			// Decoupled versions of nmatrix operations

				//- Sum off-diagonal coefficients and add to diagonal,
				//  decoupled version
		void decoupledSumDiag();

		//- Sum negative off-diagonal coefficients and add to diagonal,
		//  decoupled version
		void decoupledNegSumDiag();

		//- Check matrix for diagonal dominance, decoupled version
		void decoupledCheck() const;

		//- Relax matrix, decoupled version
		void decoupledRelax
		(
			const TypeField& x,
			TypeField& b,
			const scalar alpha
		);

		//- Matrix scaling with scalar field, decoupled version
		void decoupledMultEqOp(const scalarField& sf);

		//- Matrix multiplication without coupled interface update,
		//  Decoupled version
		void decoupledAmulCore
		(
			TypeField& Ax,
			const TypeField& x
		) const;

		//- Matrix transpose multiplication without coupled
		//  interface update
		//  Decoupled version
		void decoupledTmulCore
		(
			TypeField& Tx,
			const TypeField& x
		) const;

		//- Return L-U vector-matrix multiplication in row-form,
		//  Decoupled version
		tmp<TypeField> decoupledH(const TypeField& x) const;

		//- Return L-U  vector-matrix multiplication in off-diagonal form,
		//  Decoupled version
		tmp<TypeField> decoupledFaceH(const TypeField& x) const;


	protected:

		// Access to constraints

			//- Return constraint map
		const Map<ConstraintType>& fixedEqns() const
		{
			return fixedEqns_;
		}


		//- Return access constraint map
		Map<ConstraintType>& fixedEqns()
		{
			return fixedEqns_;
		}


	public:

		// Constructors

			//- Construct given addressing
		explicit BlockLduMatrix(const lduMesh&);

		//- Construct as copy
		BlockLduMatrix(const BlockLduMatrix<Type>&);

		//- Construct as copy or re-use as specified.
		BlockLduMatrix(BlockLduMatrix<Type>&, bool reUse);


		//- Destructor
		virtual ~BlockLduMatrix();


		// Member functions

			// Access to addressing

				//- Return the LDU mesh from which the addressing is obtained
		const lduMesh& mesh() const
		{
			return lduMesh_;
		}

		//- Return eliminated equations
		const labelHashSet& eliminatedEqns() const
		{
			return eliminatedEqns_;
		}

		//- Return access to eliminated equations
		labelHashSet& eliminatedEqns()
		{
			return eliminatedEqns_;
		}

		//- Return the LDU addressing
		const lduAddressing& lduAddr() const
		{
			return lduMesh_.lduAddr();
		}

		//- Return the patch evaluation schedule
		const lduSchedule& patchSchedule() const
		{
			return lduAddr().patchSchedule();
		}


		// Access to coefficients

			//- Return access to diagonal coefficients
		TypeCoeffField& diag();

		//- Return diagonal coefficients
		const TypeCoeffField& diag() const;

		//- Return access to upper coefficients
		//  Also used for symmetric matrices
		TypeCoeffField& upper();

		//- Return upper coefficients
		//  Also used for symmetric matrices
		const TypeCoeffField& upper() const;

		//- Return access to lower coefficients
		TypeCoeffField& lower();

		//- Return lower coefficients
		const TypeCoeffField& lower() const;

		//- Return access to coupled interface coefficients, upper
		FieldField<CoeffField, Type>& coupleUpper()
		{
			return coupleUpper_;
		}

		//- Return coupled interface coefficients, upper
		const FieldField<CoeffField, Type>& coupleUpper() const
		{
			return coupleUpper_;
		}

		//- Return access to coupled interface coefficients, lower
		FieldField<CoeffField, Type>& coupleLower()
		{
			return coupleLower_;
		}

		//- Return coupled interface coefficients, lower
		const FieldField<CoeffField, Type>& coupleLower() const
		{
			return coupleLower_;
		}

		//- Return coupled interfaces
		const typename BlockLduInterfaceFieldPtrsList<Type>::Type&
			interfaces() const
		{
			return interfaces_;
		}

		//- Access to coupled interfaces
		typename BlockLduInterfaceFieldPtrsList<Type>::Type& interfaces()
		{
			return interfaces_;
		}

		//- Clear interfaces.  Destructor helper
		void clearInterfaces();


		// Matrix structure

			//- Return true if there is a diagonal
		bool thereIsDiag() const
		{
			return (diagPtr_);
		}

		//- Return true if upper triangle is allocated
		bool thereIsUpper() const
		{
			return (upperPtr_);
		}

		//- Return true if lower triangle is allocated
		bool thereIsLower() const
		{
			return (lowerPtr_);
		}

		//- Return true if matrix is empty
		bool empty() const;

		//- Return true if matrix is diagonal-only
		bool diagonal() const;

		//- Return true if matrix is symmetric
		bool symmetric() const;

		//- Return true if matrix is asymmetric
		bool asymmetric() const;

		//- Return true if matrix is component-coupled
		bool componentCoupled() const;


		// Operations

			//- Sum off-diagonal coefficients and add to diagonal
		void sumDiag();

		//- Sum negative off-diagonal coefficients and add to diagonal
		void negSumDiag();

		//- Check matrix for diagonal dominance
		void check() const;

		//- Relax matrix
		void relax
		(
			const TypeField& x,
			TypeField& b,
			const scalar alpha
		);

		//- Matrix multiplication
		void Amul
		(
			TypeField& Ax,
			const TypeField& x
		) const;

		//- Matrix multiplication without coupled interface update
		void AmulCore
		(
			TypeField& Ax,
			const TypeField& x
		) const;

		//- Matrix transpose multiplication
		void Tmul
		(
			TypeField& Ax,
			const TypeField& x
		) const;

		//- Matrix transpose multiplication without coupled
	   //  interface update
		void TmulCore
		(
			TypeField& Ax,
			const TypeField& x
		) const;


		//- Return decoupled b
		void segregateB
		(
			TypeField& sMul,
			const TypeField& x
		) const;


		// Coupled interface functionality

			//- Initialise the update of coupled interfaces
			//  for Amul operations
		void initInterfaces
		(
			const FieldField<CoeffField, Type>& interfaceCoeffs,
			TypeField& result,
			const TypeField& psi,
			const bool switchToLhs = false
		) const;

		//- Update coupled interfaces
		void updateInterfaces
		(
			const FieldField<CoeffField, Type>& interfaceCoeffs,
			TypeField& result,
			const TypeField& psi,
			const bool switchToLhs = false
		) const;


		// Constraint manipulation

			//- Set constrained value in a prescribed point
		void setValue
		(
			const label eqnIndex,
			const Type& value
		);


		// Residual calculation

			//- Calculate residual
		tmp<TypeField> residual
		(
			const TypeField& x
		) const;

		tmp<TypeField> residual
		(
			const TypeField& x,
			const TypeField& b
		) const;


		// H-operations

			//- Return L-U vector-matrix multiplication in row-form
		tmp<TypeField> H(const TypeField&) const;

		//- Return L-U  vector-matrix multiplication in off-diagonal form
		tmp<TypeField> faceH(const TypeField&) const;


		// Member operators

		void operator=(const BlockLduMatrix<Type>&);

		void negate();

		void operator+=(const BlockLduMatrix<Type>&);
		void operator-=(const BlockLduMatrix<Type>&);

		void operator*=(const scalarField&);
		void operator*=(const scalar);


		// Ostream operator

		friend Ostream& operator<< <Type>
			(
				Ostream&,
				const BlockLduMatrix<Type>&
				);
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#   include <BlockLduMatrix.cxx>
#   include <BlockLduMatrixOperations.cxx>
#   include <BlockLduMatrixUpdateInterfaces.cxx>
#   include <BlockLduMatrixATmul.cxx>
#   include <BlockLduMatrixHOps.cxx>
#   include <BlockLduMatrixDecouple.cxx>
#   include <BlockLduMatrixDecoupledHOps.cxx>
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_BlockLduMatrix_Header

