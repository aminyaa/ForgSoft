#pragma once
#ifndef _PstreamCombineReduceOps_Header
#define _PstreamCombineReduceOps_header

#include <Pstream.hxx>
#include <ops.hxx>

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	template <class T, class CombineOp>
	void combineReduce
	(
		const List<Pstream::commsStruct>& comms,
		T& Value,
		const CombineOp& cop
	)
	{
		Pstream::combineGather(comms, Value, cop);
		Pstream::combineScatter(comms, Value);
	}


	template <class T, class CombineOp>
	void combineReduce(T& Value, const CombineOp& cop)
	{
		if (Pstream::nProcs() < Pstream::nProcsSimpleSum())
		{
			Pstream::combineGather(Pstream::linearCommunication(), Value, cop);
			Pstream::combineScatter(Pstream::linearCommunication(), Value);
		}
		else
		{
			Pstream::combineGather(Pstream::treeCommunication(), Value, cop);
			Pstream::combineScatter(Pstream::treeCommunication(), Value);
		}
	}


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
}

#endif // !_PstreamCombineReduceOps_Header
