#pragma once
#ifndef _VectorNLists_Header
#define _VectorNLists_Header

#include <VectorNFieldTypes.hxx>
#include <List.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

#define makeListTypeDef(type, Type, args)  \
    typedef List<type> type##List;

	typedef List<vector2> vector2List;
	typedef List<vector3> vector3List;
	typedef List<vector4> vector4List;
	typedef List<vector6> vector6List;
	typedef List<vector8> vector8List;
		
	typedef List<tensor2> tensor2List;
	typedef List<tensor3> tensor3List;
	typedef List<tensor4> tensor4List;
	typedef List<tensor6> tensor6List;
	typedef List<tensor8> tensor8List;
		
	typedef List<diagTensor2> diagTensor2List;
	typedef List<diagTensor3> diagTensor3List;
	typedef List<diagTensor4> diagTensor4List;
	typedef List<diagTensor6> diagTensor6List;
	typedef List<diagTensor8> diagTensor8List;
		
	typedef List<sphericalTensor2> sphericalTensor2List;
	typedef List<sphericalTensor3> sphericalTensor3List;
	typedef List<sphericalTensor4> sphericalTensor4List;
	typedef List<sphericalTensor6> sphericalTensor6List;
	typedef List<sphericalTensor8> sphericalTensor8List;

#undef makeListTypeDef

}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_VectorNLists_Header
