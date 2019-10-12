#pragma once
namespace AutLib
{

	//- Inner-product between two spherical tensors
	inline sphericalTensor2 operator&(const sphericalTensor2& st1, const sphericalTensor2& st2)
	{
		return sphericalTensor2(st1[0] * st2[0]);
	}


	//- Inner-product between a spherical tensor and a vector
	inline vector2 operator&(const sphericalTensor2& st, const vector2& v)
	{
		vector2 result;

		result[0] = st[0] * v[0];
		result[1] = st[0] * v[1];

		return result;
	}


	//- Inner-product between a vector and a spherical tensor
	inline vector2 operator&(const vector2& v, const sphericalTensor2& st)
	{
		vector2 result;

		result[0] = v[0] * st[0];
		result[1] = v[1] * st[0];

		return result;
	}


	//- Return the inverse of a tensor given the determinant
	inline sphericalTensor2 inv(const sphericalTensor2& st)
	{
		return sphericalTensor2(1 / st[0]);
	}
}