#pragma once
#ifndef _BlockAMGCycle_Header
#define _BlockAMGCycle_Header

#include <BlockAMGLevel.hxx>
#include <NamedEnum.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * Forward declaration of template friend fuctions * * * * * * * //

	template<class Type>
	class fineBlockAMGLevel;

	template<class Type>
	class coarseBlockAMGLevel;

	template<class Type>
	class BlockMatrixCoarsening;

	template<class Type>
	class BlockAMGLevel;


	/*---------------------------------------------------------------------------*\
						  Class blockAMGCycleName Declaration
	\*---------------------------------------------------------------------------*/

	class blockAMGCycleName
	{
	public:

		// Public enumerations

			//- Cycle type
		enum cycleType
		{
			V_CYCLE,
			W_CYCLE,
			F_CYCLE
		};

		//- Static data

			//- Cycle type names
		static const NamedEnum<cycleType, 3> cycleNames_;
	};


	/*---------------------------------------------------------------------------*\
							   Class BlockAMGCycle Declaration
	\*---------------------------------------------------------------------------*/

	template<class Type>
	class BlockAMGCycle
		:
		public blockAMGCycleName
	{
		// Private data

			//- Pointer to current AMG level
		autoPtr<BlockAMGLevel<Type> > levelPtr_;

		//- Pointer to coarse AMG cycle
		BlockAMGCycle<Type>* coarseLevelPtr_;

		//- Number of coarse levels
		label nLevels_;


		// Private Member Functions

			//- Disallow default bitwise copy construct
		BlockAMGCycle(const BlockAMGCycle<Type>&);

		//- Disallow default bitwise assignment
		void operator=(const BlockAMGCycle<Type>&);


	public:

		//- Runtime type information
		TypeName("BlockAMGCycle");


		// Constructors

			//- Construct from AMG level
		BlockAMGCycle(autoPtr<BlockAMGLevel<Type> > levelPtr);


		// Destructor

		virtual ~BlockAMGCycle();


		// Member Functions

			//- Make coarse levels
		void makeCoarseLevels(const label nMaxLevels);

		//- Return number of levels
		label nLevels() const
		{
			return nLevels_;
		}

		//- Calculate residual
		void residual
		(
			const Field<Type>& x,
			const Field<Type>& b,
			Field<Type>& res
		) const
		{
			levelPtr_->residual(x, b, res);
		}


		//- Fixed cycle
		void fixedCycle
		(
			Field<Type>& x,
			const Field<Type>& b,
			Field<Type>& xBuffer,
			const BlockAMGCycle::cycleType cycle,
			const label nPreSweeps,
			const label nPostSweeps,
			const bool scale
		) const;
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#   include <BlockAMGCycle.cxx>
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_BlockAMGCycle_Header
