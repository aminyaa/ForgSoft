#pragma once
#ifndef _PstreamReduceOps_Header
#define _PstreamReduceOps_Header

#include <PstreamTools.hxx>
#include <ops.hxx>

namespace AutLib
{

	// Reduce operation with user specified communication schedule
	template <class T, class BinaryOp>
	void reduce
	(
		const List<Pstream::commsStruct>& comms,
		T& Value,
		const BinaryOp& bop
	)
	{
		PstreamTools::gather(comms, Value, bop);
		PstreamTools::scatter(comms, Value);
	}


	// Reduce using either linear or tree communication schedule
	template <class T, class BinaryOp>
	void reduce
	(
		T& Value,
		const BinaryOp& bop
	)
	{
		if (Pstream::nProcs() < Pstream::nProcsSimpleSum())
		{
			reduce(Pstream::linearCommunication(), Value, bop);
		}
		else
		{
			reduce(Pstream::treeCommunication(), Value, bop);
		}
	}


	// Reduce using either linear or tree communication schedule
	template <class T, class BinaryOp>
	T returnReduce
	(
		const T& Value,
		const BinaryOp& bop
	)
	{
		T WorkValue(Value);

		if (Pstream::nProcs() < Pstream::nProcsSimpleSum())
		{
			reduce(Pstream::linearCommunication(), WorkValue, bop);
		}
		else
		{
			reduce(Pstream::treeCommunication(), WorkValue, bop);
		}

		return WorkValue;
	}


	// Insist there is a specialisation for the reduction of a scalar
	void reduce(scalar& Value, const sumOp<scalar>& bop);

	template <class T, class CombineOp>
	void combineReduce
	(
		const List<Pstream::commsStruct>& comms,
		T& Value,
		const CombineOp& cop
	)
	{
		PstreamTools::combineGather(comms, Value, cop);
		PstreamTools::combineScatter(comms, Value);
	}


	template <class T, class CombineOp>
	void combineReduce(T& Value, const CombineOp& cop)
	{
		if (Pstream::nProcs() < Pstream::nProcsSimpleSum())
		{
			PstreamTools::combineGather(Pstream::linearCommunication(), Value, cop);
			PstreamTools::combineScatter(Pstream::linearCommunication(), Value);
		}
		else
		{
			PstreamTools::combineGather(Pstream::treeCommunication(), Value, cop);
			PstreamTools::combineScatter(Pstream::treeCommunication(), Value);
		}
	}
}

#endif // !_PstreamReduceOps_Header
