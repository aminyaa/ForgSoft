#pragma once
#ifndef _lduAddressing_Header
#define _lduAddressing_Header

#include <labelList.hxx>
#include <lduSchedule.hxx>
#include <labelList.hxx>
#include <PtrList.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// Forward declaration of classes
	class extendedLduAddressing;

	/*---------------------------------------------------------------------------*\
						   Class lduAddressing Declaration
	\*---------------------------------------------------------------------------*/

	class lduAddressing
	{
		// Private data

			//- Number of equations
		label size_;


		//- Demand-driven data

			//- Losort addressing
		mutable labelList* losortPtr_;

		//- Owner start addressing
		mutable labelList* ownerStartPtr_;

		//- Losort start addressing
		mutable labelList* losortStartPtr_;

		//- Extended addressing with p-order fill-in
		mutable PtrList<extendedLduAddressing> extendedAddr_;


		// Private Member Functions

			//- Disallow default bitwise copy construct
		lduAddressing(const lduAddressing&);

		//- Disallow default bitwise assignment
		void operator=(const lduAddressing&);

		//- Calculate losort
		void calcLosort() const;

		//- Calculate owner start
		void calcOwnerStart() const;

		//- Calculate losort start
		void calcLosortStart() const;


	public:

		// Constructor
		lduAddressing(const label nEqns);


		//- Destructor
		virtual ~lduAddressing();


		// Member Functions

			//- Return number of equations
		label size() const
		{
			return size_;
		}

		//- Return number of interfaces
		virtual label nPatches() const = 0;

		//- Return lower addressing
		virtual const unallocLabelList& lowerAddr() const = 0;

		//- Return upper addressing
		virtual const unallocLabelList& upperAddr() const = 0;

		//- Return patch to internal addressing given patch number
		virtual const unallocLabelList& patchAddr
		(
			const label patchNo
		) const = 0;

		// Return patch field evaluation schedule
		virtual const lduSchedule& patchSchedule() const = 0;

		//- Return losort addressing
		const unallocLabelList& losortAddr() const;

		//- Return owner start addressing
		const unallocLabelList& ownerStartAddr() const;

		//- Return losort start addressing
		const unallocLabelList& losortStartAddr() const;

		//- Return off-diagonal index given owner and neighbour label
		label triIndex(const label a, const label b) const;

		//- Return extended addressing given p index
		const extendedLduAddressing& extendedAddr(const label p) const;
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_lduAddressing_Header
