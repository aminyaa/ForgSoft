#pragma once
#ifndef _ProcessorTopologyTemplate_Header
#define _ProcessorTopologyTemplate_Header

#include <labelList.hxx>
#include <lduSchedule.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
						   Class ProcessorTopology Declaration
	\*---------------------------------------------------------------------------*/

	template<class Patch, class ProcPatch>
	class ProcessorTopology
		: public labelListList
	{

	private:

		// Private data

			//- Local map from neighbour proc to patchI. Different per processor!
			//  -1 or patchI for connection to procID
		labelList procPatchMap_;

		//- Order in which the patches should be initialised/evaluated
		//  corresponding to the schedule
		lduSchedule patchSchedule_;


		// Private Member Functions

			//- Return all neighbouring processors of this processor. Set
			//  procPatchMap_.
		labelList procNeighbours(const PtrList<Patch>&);

	public:

		// Constructors

			//- Construct from boundaryMesh
		ProcessorTopology(const PtrList<Patch>& patches);


		// Member Functions

			//- from neighbour processor to index in boundaryMesh. Local information
			//  (so not same over all processors)
		const labelList& procPatchMap() const
		{
			return procPatchMap_;
		}

		//- Order in which the patches should be initialised/evaluated
		//  corresponding to the schedule
		const lduSchedule& patchSchedule() const
		{
			return patchSchedule_;
		}
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#   include <ProcessorTopologyTemplate.cxx>
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_ProcessorTopologyTemplate_Header
