#pragma once
#ifndef _ListListOps_Header
#define _ListListOps_Header

#include <labelList.hxx>

namespace tnbLib
{

	//
//template <class T> class accessOp;
//template <class T> class offsetOp;
// Dummy access operator for combine()
	template <class T>
	class accessOp
	{
	public:

		const T& operator()(const T& x) const
		{
			return x;
		}
	};


	// Offset operator for combineOffset()
	template <class T>
	class offsetOp
	{
	public:

		T operator()(const T& x, const label offset) const
		{
			return x + offset;
		}
	};

	/*---------------------------------------------------------------------------*\
							   Class ListListOps Declaration
	\*---------------------------------------------------------------------------*/

	namespace ListListOps
	{

		//- Combines sublists into one big list
		template <class AccessType, class T, class AccessOp>
		AccessType combine(const List<T>&, AccessOp aop = accessOp<T>());

		//- Gets sizes of sublists
		template <class T, class AccessOp>
		labelList subSizes(const List<T>&, AccessOp aop = accessOp<T>());

		//- Like combine but also offsets sublists based on passed sizes
		template <class AccessType, class T, class AccessOp, class OffsetOp>
		AccessType combineOffset
		(
			const List<T>&,
			const labelList& sizes,
			AccessOp aop,
			OffsetOp oop = offsetOp<T>()
		);
	};

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
}

#include <ListListOpsI.hxx>

#ifdef NoRepository
#   include <ListListOps.cxx>
#endif

#endif // !_ListListOps_Header
