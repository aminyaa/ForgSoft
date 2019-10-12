#pragma once
#ifndef _labelVector_Header
#define _labelVector_Header

#include <label.hxx>
#include <VectorTemplate.hxx>
#include <contiguous.hxx>

namespace AutLib
{
	typedef Vector<label> labelVector;

	//- Data associated with labelVector type are contiguous
	template<>
	inline bool contiguous<labelVector>()
	{
		return true;
	}
}

#endif // !_labelVector_Header
