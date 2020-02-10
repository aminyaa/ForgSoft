#pragma once
#ifndef _PstreamReduceOps_Header
#define _PstreamReduceOps_Header

#include <Pstream.hxx>
#include <ops.hxx>

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

// Reduce operation with user specified communication schedule
	template <class T, class BinaryOp>
	void reduce
	(
		const List<Pstream::commsStruct>& comms,
		T& Value,
		const BinaryOp& bop
	)
	{
		Pstream::gather(comms, Value, bop);
		Pstream::scatter(comms, Value);
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


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
}

#endif // !_PstreamReduceOps_Header
