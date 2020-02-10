#pragma once
#ifndef _lduPrimitiveMesh_Header
#define _lduPrimitiveMesh_Header

#include <lduMesh.hxx>
#include <labelList.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
						   Class lduPrimitiveMesh Declaration
	\*---------------------------------------------------------------------------*/

	class lduPrimitiveMesh
		: public lduMesh
		, public lduAddressing
	{
		// Private data

			//- Lower addressing
		labelList lowerAddr_;

		//- Upper addressing
		labelList upperAddr_;

		//- Patch to internal addressing
		labelListList patchAddr_;

		//- List of pointers for each patch
		//  with only those pointing to interfaces being set
		lduInterfacePtrsList interfaces_;

		//- Patch field evaluation schedule.
		//  Note this does must be held as a copy.  HJ, 20/Feb/2009
		lduSchedule patchSchedule_;


		// Private Member Functions

			//- Disallow default bitwise copy construct
		lduPrimitiveMesh(const lduPrimitiveMesh&);

		//- Disallow default bitwise assignment
		void operator=(const lduPrimitiveMesh&);


	public:

		// Constructors

			//- Construct from components as copies
			//  Interfaces are added upon construction.  HJ, 20/Feb/2009
		lduPrimitiveMesh
		(
			const label nCells,
			const unallocLabelList& l,
			const unallocLabelList& u
		)
			:
			lduAddressing(nCells),
			lowerAddr_(l),
			upperAddr_(u)
		{}


		//- Construct from components and re-use storage as specified.
		lduPrimitiveMesh
		(
			const label nCells,
			labelList& l,
			labelList& u,
			bool reUse
		)
			:
			lduAddressing(nCells),
			lowerAddr_(l, reUse),
			upperAddr_(u, reUse)
		{}


		// Destructor

		virtual ~lduPrimitiveMesh()
		{}


		// Member Functions

			//- Add interfaces.  Constructor helper
		void addInterfaces
		(
			const lduInterfacePtrsList& interfaces,
			const labelListList& pa,
			const lduSchedule& ps
		)
		{
			interfaces_ = interfaces;
			patchAddr_ = pa;
			patchSchedule_ = ps;
		}

		//- Clear interfaces
		void clearInterfaces()
		{
			// Clear interface pointers: they are not deleted
			// by the lduInterfacePtrsList (derived from UPtrList)
			// HJ, 5/Feb/2016
			forAll(interfaces_, i)
			{
				if (interfaces_.set(i))
				{
					delete interfaces_(i);
				}
			}
		}

		//- Return number of interfaces
		virtual label nPatches() const
		{
			return patchAddr_.size();
		}


		// Access

			//- Return ldu addressing
		virtual const lduAddressing& lduAddr() const
		{
			return *this;
		}

		//- Return a list of pointers for each patch
		//  with only those pointing to interfaces being set
		virtual lduInterfacePtrsList interfaces() const
		{
			return interfaces_;
		}

		//- Return Lower addressing
		virtual const unallocLabelList& lowerAddr() const
		{
			return lowerAddr_;
		}

		//- Return Upper addressing
		virtual const unallocLabelList& upperAddr() const
		{
			return upperAddr_;
		}

		//- Return patch addressing
		virtual const unallocLabelList& patchAddr(const label i) const
		{
			return patchAddr_[i];
		}

		//- Return patch evaluation schedule
		virtual const lduSchedule& patchSchedule() const
		{
			return patchSchedule_;
		}
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_lduPrimitiveMesh_Header
