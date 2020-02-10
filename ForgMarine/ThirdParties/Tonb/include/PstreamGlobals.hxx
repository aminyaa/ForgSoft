#pragma once
#ifndef _PstreamGlobals_Header
#define _PstreamGlobals_Header

#include <DynamicList.hxx>

#include <mpi.h>

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
						   Class PstreamGlobals Declaration
\*---------------------------------------------------------------------------*/

	namespace PstreamGlobals
	{

		extern DynamicList<MPI_Request> IPstream_outstandingRequests_;
		extern DynamicList<MPI_Request> OPstream_outstandingRequests_;

	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
}


#endif // !_PstreamGlobals_Header
