#pragma once
#ifndef _PstreamGlobals_Header
#define _PstreamGlobals_Header

#include <mpi.h>
#include <DynamicList.hxx>

namespace AutLib
{

	namespace PstreamGlobals
	{

		extern DynamicList<MPI_Request> IPstream_outstandingRequests_;
		extern DynamicList<MPI_Request> OPstream_outstandingRequests_;

	};
}

#endif // !_PstreamGlobals_Header
