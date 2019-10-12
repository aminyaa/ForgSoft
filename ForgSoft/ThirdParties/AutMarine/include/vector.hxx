#pragma once
#ifndef _vector_Header
#define _vector_Header

#include <scalar.hxx>
#include <VectorTemplate.hxx>
#include <contiguous.hxx>

namespace AutLib
{

	typedef Vector<scalar> vector;

	//- Data associated with vector type are contiguous
	template<>
	inline bool contiguous<vector>()
	{
		return true;
	}

	template<class Type>
	class flux
		: public innerProduct<vector, Type>
	{};

	template<>
	class flux<scalar>
	{
	public:

		typedef scalar type;
	};
}

#endif // !_vector_Header
