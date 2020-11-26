#pragma once
#ifndef _transformList_Header
#define _transformList_Header

#include <transform.hxx>
#include <List.hxx>
#include <Map.hxx>
#include <EdgeMap.hxx>
#include <tensorField.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	//- Extend transform to work on list.
	template<class T>
	List<T> transform
	(
		const tensor& rotTensor,
		const UList<T>& field
	);

	//- Apply transformation to list. Either single transformation tensor
	//  or one tensor per element.
	template<class T>
	void transformList(const tensorField&, UList<T>&);

	template<class T>
	void transformList(const tensorField&, Map<T>&);

	template<class T>
	void transformList(const tensorField&, EdgeMap<T>&);


	template<>
	inline void transformList(const tensorField&, UList<label>&)
	{}
	template<>
	inline void transformList(const tensorField&, Map<label>&)
	{}
	template<>
	inline void transformList(const tensorField&, EdgeMap<label>&)
	{}


	template<>
	inline void transformList(const tensorField&, UList<scalar>&)
	{}
	template<>
	inline void transformList(const tensorField&, Map<scalar>&)
	{}
	template<>
	inline void transformList(const tensorField&, EdgeMap<scalar>&)
	{}


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#   include <transformList.cxx>
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_transformList_Header
