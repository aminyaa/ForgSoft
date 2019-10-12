#pragma once
#ifndef _PstreamTools_Header
#define _PstreamTools_Header

#include <IPstream.hxx>
#include <OPstream.hxx>
#include <IOstreams.hxx>

namespace AutLib
{

	class PstreamTools
	{

	public:

		// Gather and scatter

		//- Gather data. Apply bop to combine Value
		//  from different processors
		template <class T, class BinaryOp>
		static void gather
		(
			const List<Pstream::commsStruct>& comms,
			T& Value,
			const BinaryOp& bop
		);

		//- Like above but switches between linear/tree communication
		template <class T, class BinaryOp>
		static void gather(T& Value, const BinaryOp& bop);

		//- Scatter data. Distribute without modification.
		//  Reverse of gather
		template <class T>
		static void scatter(const List<Pstream::commsStruct>& comms, T& Value);

		//- Like above but switches between linear/tree communication
		template <class T>
		static void scatter(T& Value);


		// Combine variants. Inplace combine values from processors.
		// (Uses construct from Istream instead of <<)

		template <class T, class CombineOp>
		static void combineGather
		(
			const List<Pstream::commsStruct>& comms,
			T& Value,
			const CombineOp& cop
		);

		//- Like above but switches between linear/tree communication
		template <class T, class CombineOp>
		static void combineGather(T& Value, const CombineOp& cop);

		//- Scatter data. Reverse of combineGather
		template <class T>
		static void combineScatter
		(
			const List<Pstream::commsStruct>& comms,
			T& Value
		);

		//- Like above but switches between linear/tree communication
		template <class T>
		static void combineScatter(T& Value);

		// Combine variants working on whole List at a time.

		template <class T, class CombineOp>
		static void listCombineGather
		(
			const List<Pstream::commsStruct>& comms,
			List<T>& Value,
			const CombineOp& cop
		);

		//- Like above but switches between linear/tree communication
		template <class T, class CombineOp>
		static void listCombineGather
		(
			List<T>& Value,
			const CombineOp& cop
		);

		//- Scatter data. Reverse of combineGather
		template <class T>
		static void listCombineScatter
		(
			const List<Pstream::commsStruct>& comms,
			List<T>& Value
		);

		//- Like above but switches between linear/tree communication
		template <class T>
		static void listCombineScatter(List<T>& Value);

		// Combine variants working on whole map at a time. Container needs to
		// have iterators and find() defined.

		template <class Container, class CombineOp>
		static void mapCombineGather
		(
			const List<Pstream::commsStruct>& comms,
			Container& Values,
			const CombineOp& cop
		);

		//- Like above but switches between linear/tree communication
		template <class Container, class CombineOp>
		static void mapCombineGather
		(
			Container& Values,
			const CombineOp& cop
		);

		//- Scatter data. Reverse of combineGather
		template <class Container>
		static void mapCombineScatter
		(
			const List<Pstream::commsStruct>& comms,
			Container& Values
		);

		//- Like above but switches between linear/tree communication
		template <class Container>
		static void mapCombineScatter(Container& Values);



		// Gather/scatter keeping the individual processor data separate.
		// Values is a List of size Pstream::nProcs() where
		// Values[Pstream::myProcNo()] is the data for the current processor.

		//- Gather data but keep individual values separate
		template <class T>
		static void gatherList
		(
			const List<Pstream::commsStruct>& comms,
			List<T>& Values
		);

		//- Like above but switches between linear/tree communication
		template <class T>
		static void gatherList(List<T>& Values);

		//- Scatter data. Reverse of gatherList
		template <class T>
		static void scatterList
		(
			const List<Pstream::commsStruct>& comms,
			List<T>& Values
		);

		//- Like above but switches between linear/tree communication
		template <class T>
		static void scatterList(List<T>& Values);
	};
}

#include <PstreamToolsI.hxx>

#endif // !_PstreamTools_Header
