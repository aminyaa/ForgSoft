#pragma once
#ifndef _expandTensor_Header
#define _expandTensor_Header

#include <TensorTemplate.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	//- Return the diagonal of a tensor as a scalar
	template <class Cmpt>
	void contractScalar(Cmpt& result, const Tensor<Cmpt>& t)
	{
		result = 1.0 / 3.0*(t.xx() + t.yy() + t.zz());
	}


	//- Return the diagonal of a tensor as a scalar
	template <class Cmpt>
	Cmpt contractScalar(const Tensor<Cmpt>& t)
	{
		Cmpt result;
		contractScalar(result, t);
		return result;
	}


	//- Return the diagonal of a tensor as a vector
	template <class Cmpt>
	void contractLinear(Vector<Cmpt>& result, const Tensor<Cmpt>& t)
	{
		result = Vector<Cmpt>(t.xx(), t.yy(), t.zz());
	}


	//- Return the diagonal of a tensor as a vector
	template <class Cmpt>
	Vector<Cmpt> contractLinear(const Tensor<Cmpt>& t)
	{
		Vector<Cmpt> result;
		contractLinear(result, t);
		return result;
	}


	//- Return the vector given a scalar
	template <class Cmpt>
	void expandScalar(Vector<Cmpt>& result, const Cmpt& v)
	{
		result = Vector<Cmpt>(v, v, v);
	}


	//- Return the tensor given a scalar
	template <class Cmpt>
	void expandScalar(Tensor<Cmpt>& result, const Cmpt& v)
	{
		result = Tensor<Cmpt>
			(
				v, pTraits<Cmpt>::zero, pTraits<Cmpt>::zero,
				pTraits<Cmpt>::zero, v, pTraits<Cmpt>::zero,
				pTraits<Cmpt>::zero, pTraits<Cmpt>::zero, v
				);
	}


	//- Return the tensor given a diagonal vector
	template <class Cmpt>
	void expandLinear(Tensor<Cmpt>& result, const Vector<Cmpt>& v)
	{
		result = Tensor<Cmpt>
			(
				v.x(), pTraits<Cmpt>::zero, pTraits<Cmpt>::zero,
				pTraits<Cmpt>::zero, v.y(), pTraits<Cmpt>::zero,
				pTraits<Cmpt>::zero, pTraits<Cmpt>::zero, v.z()
				);
	}


	//- Sum row elements of a tensor as a vector
	template <class Cmpt>
	void sumToDiag(Vector<Cmpt>& result, const Tensor<Cmpt>& t)
	{
		result = Vector<Cmpt>
			(
				t.xx() + t.xy() + t.xz(),
				t.yx() + t.yy() + t.yz(),
				t.zx() + t.zy() + t.zz()
				);
	}


	//- Sum row elements of a TensorN as a vectorN
	template <class Cmpt>
	Vector<Cmpt> sumToDiag(const Tensor<Cmpt>& t)
	{
		Vector<Cmpt> result;
		sumToDiag(result, t);
		return result;
	}


	//- Sum row elements of a tensor as a vector
	template <class Cmpt>
	void sumMagToDiag(Vector<Cmpt>& result, const Tensor<Cmpt>& t)
	{
		result = Vector<Cmpt>
			(
				tnbLib::mag(t.xx()) + tnbLib::mag(t.xy()) + tnbLib::mag(t.xz()),
				tnbLib::mag(t.yx()) + tnbLib::mag(t.yy()) + tnbLib::mag(t.yz()),
				tnbLib::mag(t.zx()) + tnbLib::mag(t.zy()) + tnbLib::mag(t.zz())
				);
	}


	//- Sum magnitudes of row elements of a TensorN as a vectorN
	template <class Cmpt>
	Vector<Cmpt> sumMagToDiag(const Tensor<Cmpt>& t)
	{
		Vector<Cmpt> result;
		sumMagToDiag(result, t);
		return result;
	}


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_expandTensor_Header
