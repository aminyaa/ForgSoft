#pragma once
#ifndef _BlockLduSolver_Header
#define _BlockLduSolver_Header

#include <dictionary.hxx>
#include <blockLduMatrices.hxx>
#include <runTimeSelectionTables.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * Forward declaration of template friend fuctions * * * * * * * //

	template<class Type>
	class BlockSolverPerformance;

	/*---------------------------------------------------------------------------*\
							Class BlockLduSolver Declaration
	\*---------------------------------------------------------------------------*/

	template<class Type>
	class BlockLduSolver
	{
		// Private data

			//- Name of field being solved for
		word fieldName_;

		//- Control data dictionary
		dictionary dict_;


	protected:

		// Protected data types

		typedef Field<Type> TypeField;


		// Protected data

			//- Matrix
		const BlockLduMatrix<Type>& matrix_;


		// Protected Member Functions

			//- Return dictionary
		const dictionary& dict() const
		{
			return dict_;
		}

		//- Read a control parameter from the dictionary
		template<class T>
		void readControl
		(
			const dictionary& dict,
			T& control,
			const word& controlName
		);


	public:

		//- Runtime type information
		TypeName("BlockLduSolver");


		// Static data

			//- Large value for the use in solvers
		static const scalar great_;

		//- Small value for the use in solvers
		static const scalar small_;


		// Declare run-time constructor selection tables

		declareRunTimeSelectionTable
		(
			autoPtr,
			BlockLduSolver,
			symMatrix,
			(
				const word& fieldName,
				BlockLduMatrix<Type>& matrix,
				const dictionary& dict
				),
				(
					fieldName,
					matrix,
					dict
					)
		);

		declareRunTimeSelectionTable
		(
			autoPtr,
			BlockLduSolver,
			asymMatrix,
			(
				const word& fieldName,
				BlockLduMatrix<Type>& matrix,
				const dictionary& dict
				),
				(
					fieldName,
					matrix,
					dict
					)
		);



		// Constructors

			//- Construct from field name and matrix
		BlockLduSolver
		(
			const word& fieldName,
			const BlockLduMatrix<Type>& matrix
		);

		//- Construct from dictionary
		BlockLduSolver
		(
			const word& fieldName,
			const BlockLduMatrix<Type>& matrix,
			const dictionary& dict
		);


		// Selectors

			//- Return a new solver from a dictionary
		static autoPtr<BlockLduSolver<Type> > New
		(
			const word& fieldName,
			BlockLduMatrix<Type>& matrix,
			const dictionary& dict
		);

		//- Return a new solver given type
		static autoPtr<BlockLduSolver<Type> > New
		(
			const word& solverName,
			const word& fieldName,
			BlockLduMatrix<Type>& matrix,
			const dictionary& dict
		);


		// Destructor

		virtual ~BlockLduSolver()
		{}


		// Member functions

			//- Return field name
		const word& fieldName() const
		{
			return fieldName_;
		}

		//- Solve
		virtual BlockSolverPerformance<Type> solve
		(
			TypeField& x,
			const TypeField& b
		) = 0;
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#   include <BlockLduSolver.cxx>
#endif


#define makeBlockSolverTypeName(typeSolverType)                              \
                                                                             \
defineNamedTemplateTypeNameAndDebug(typeSolverType, 0);

#define makeBlockSolvers(solverType)                                         \
                                                                             \
makeBlockSolverTypeName(solverType##Scalar);                                 \
makeBlockSolverTypeName(solverType##Vector);                                 \
makeBlockSolverTypeName(solverType##Tensor);


#define addSolverToBlockMatrix(Type, typeSolverType, typeMatrix)             \
                                                                             \
addToRunTimeSelectionTable(block##Type##Solver, typeSolverType, typeMatrix);

#define addSolversToBlockMatrix(solverType, typeMatrix)                      \
                                                                             \
addSolverToBlockMatrix(Scalar, solverType##Scalar, typeMatrix);              \
addSolverToBlockMatrix(Vector, solverType##Vector, typeMatrix);              \
addSolverToBlockMatrix(Tensor, solverType##Tensor, typeMatrix);

#define addSymSolverToBlockMatrix(solverType)                                \
                                                                             \
addSolversToBlockMatrix(solverType, symMatrix);

#define addAsymSolverToBlockMatrix(solverType)                               \
                                                                             \
addSolversToBlockMatrix(solverType, asymMatrix);


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_BlockLduSolver_Header
