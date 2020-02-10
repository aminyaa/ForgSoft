#pragma once
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	//- Return the average of a vector of as a scalar
	template <class Cmpt, int length>
	void contractScalar(Cmpt& result, const VectorN<Cmpt, length>& t)
	{
		result = pTraits<Cmpt>::zero;

		for (register int i = 0; i < TensorN<Cmpt, length>::rowLength; i++)
		{
			result += t[i];
		}

		// Modified 2009/11/3 by I. Clifford
		result *= 1.0 / VectorN<Cmpt, length>::nComponents;
	}


	//- Return the Average of a vector of as a scalar
	template <class Cmpt, int length>
	Cmpt contractScalar(const VectorN<Cmpt, length>& t)
	{
		Cmpt result;
		contractScalar(result, t);
		return result;
	}


	//- Return the diagonal of a TensorN as a scalar
	template <class Cmpt, int length>
	void contractScalar(Cmpt& result, const TensorN<Cmpt, length>& t)
	{
		result = pTraits<Cmpt>::zero;

		register int j = 0;
		for (register int i = 0; i < TensorN<Cmpt, length>::rowLength; i++)
		{
			result += t[j];
			j += TensorN<Cmpt, length>::rowLength + 1;
		}

		// Modified 2009/11/3 by I. Clifford
		result *= 1.0 / TensorN<Cmpt, length>::rowLength;
	}


	//- Return the diagonal of a TensorN as a scalar
	template <class Cmpt, int length>
	Cmpt contractScalar(const TensorN<Cmpt, length>& t)
	{
		Cmpt result;
		contractScalar(result, t);
		return result;
	}


	//- Return the diagonal of a DiagTensorN as a scalar
	template <class Cmpt, int length>
	void contractScalar(Cmpt& result, const DiagTensorN<Cmpt, length>& t)
	{
		result = pTraits<Cmpt>::zero;

		for (register int i = 0; i < DiagTensorN<Cmpt, length>::rowLength; i++)
		{
			result += t[i];
		}

		result *= 1.0 / TensorN<Cmpt, length>::rowLength;
	}


	//- Return the diagonal of a DiagTensorN as a scalar
	template <class Cmpt, int length>
	Cmpt contractScalar(const DiagTensorN<Cmpt, length>& t)
	{
		Cmpt result;
		contractScalar(result, t);
		return result;
	}


	//- Return the diagonal of a SphericalTensorN as a scalar
	template <class Cmpt, int length>
	void contractScalar
	(
		Cmpt& result,
		const SphericalTensorN<Cmpt, length>& t
	)
	{
		result = t[0];
	}


	//- Return the diagonal of a SphericalTensorN as a scalar
	template <class Cmpt, int length>
	Cmpt contractScalar(const SphericalTensorN<Cmpt, length>& t)
	{
		Cmpt result;
		contractScalar(result, t);
		return result;
	}


	//- Return the diagonal of a TensorN as a vectorN
	template <class Cmpt, int length>
	void contractLinear
	(
		VectorN<Cmpt, length>& result,
		const TensorN<Cmpt, length>& t
	)
	{
		register int j = 0;
		for (register int i = 0; i < TensorN<Cmpt, length>::rowLength; i++)
		{
			result[i] = t[j];
			j += TensorN<Cmpt, length>::rowLength + 1;
		}
	}


	//- Return the diagonal of a TensorN as a vectorN
	template <class Cmpt, int length>
	VectorN<Cmpt, length> contractLinear(const TensorN<Cmpt, length>& t)
	{
		VectorN<Cmpt, length> result;
		contractLinear(result, t);
		return result;
	}


	//- Return the diagonal of a DiagTensorN as a vectorN
	template <class Cmpt, int length>
	void contractLinear
	(
		VectorN<Cmpt, length>& result,
		const DiagTensorN<Cmpt, length>& t
	)
	{
		for (register int i = 0; i < DiagTensorN<Cmpt, length>::rowLength; i++)
		{
			result[i] = t[i];
		}
	}


	//- Return the diagonal of a DiagTensorN as a vectorN
	template <class Cmpt, int length>
	VectorN<Cmpt, length> contractLinear(const DiagTensorN<Cmpt, length>& t)
	{
		VectorN<Cmpt, length> result;
		contractLinear(result, t);
		return result;
	}


	//- Return the diagonal of a SphericalTensorN as a vectorN
	template <class Cmpt, int length>
	void contractLinear
	(
		VectorN<Cmpt, length>& result,
		const SphericalTensorN<Cmpt, length>& t
	)
	{
		for
			(
				register int i = 0;
				i < SphericalTensorN<Cmpt, length>::rowLength;
				i++
				)
		{
			result[i] = t[0];
		}
	}


	//- Return the diagonal of a SphericalTensorN as a vectorN
	template <class Cmpt, int length>
	VectorN<Cmpt, length> contractLinear
	(
		const SphericalTensorN<Cmpt, length>& t
	)
	{
		VectorN<Cmpt, length> result;
		contractLinear(result, t);
		return result;
	}


	//- Return the VectorN given a scalar
	template <class Cmpt, int length>
	void expandScalar(VectorN<Cmpt, length>& result, const Cmpt& v)
	{
		for (register int i = 0; i < VectorN<Cmpt, length>::nComponents; i++)
		{
			result[i] = v;
		}
	}


	//- Return the TensorN given a scalar
	template <class Cmpt, int length>
	void expandScalar(TensorN<Cmpt, length>& result, const Cmpt& v)
	{
		result = TensorN<Cmpt, length>::zero;

		register int j = 0;
		for (register int i = 0; i < TensorN<Cmpt, length>::rowLength; i++)
		{
			result[j] = v;
			j += TensorN<Cmpt, length>::rowLength + 1;
		}
	}


	//- Return the DiagTensorN given a scalar
	template <class Cmpt, int length>
	void expandScalar(DiagTensorN<Cmpt, length>& result, const Cmpt& v)
	{
		for (register int i = 0; i < DiagTensorN<Cmpt, length>::rowLength; i++)
		{
			result[i] = v;
		}
	}


	//- Return the SphericalTensorN given a scalar
	template <class Cmpt, int length>
	void expandScalar(SphericalTensorN<Cmpt, length>& result, const Cmpt& v)
	{
		result[0] = v;
	}


	//- Return the TensorN given a diagonal vectorN
	template <class Cmpt, int length>
	void expandLinear
	(
		TensorN<Cmpt, length>& result,
		const VectorN<Cmpt, length>& v
	)
	{
		result = TensorN<Cmpt, length>::zero;

		register int j = 0;
		for (register int i = 0; i < TensorN<Cmpt, length>::rowLength; i++)
		{
			result[j] = v[i];
			j += TensorN<Cmpt, length>::rowLength + 1;
		}
	}

	//- Return the DiagTensorN given a diagonal vectorN
	template <class Cmpt, int length>
	void expandLinear
	(
		DiagTensorN<Cmpt, length>& result,
		const VectorN<Cmpt, length>& v
	)
	{
		for (register int i = 0; i < DiagTensorN<Cmpt, length>::rowLength; i++)
		{
			result[i] = v[i];
		}
	}


	//- Return the SphericalTensorN given a diagonal vectorN
	template <class Cmpt, int length>
	void expandLinear
	(
		SphericalTensorN<Cmpt, length>& result,
		const VectorN<Cmpt, length>& v
	)
	{
		result[0] = pTraits<Cmpt>::zero;

		for (register int i = 0; i < DiagTensorN<Cmpt, length>::rowLength; i++)
		{
			result[0] += v[i];
		}

		result[0] *= 1.0 / DiagTensorN<Cmpt, length>::rowLength;
	}


	//- Sum row elements of a TensorN as a vectorN
	template <class Cmpt, int length>
	void sumToDiag
	(
		VectorN<Cmpt, length>& result,
		const TensorN<Cmpt, length>& t
	)
	{
		result = VectorN<Cmpt, length>::zero;

		for (register int i = 0; i < TensorN<Cmpt, length>::rowLength; i++)
		{
			for (register int j = 0; j < TensorN<Cmpt, length>::rowLength; j++)
			{
				result[i] += t(i, j);
			}
		}
	}


	//- Sum row elements of a TensorN as a vectorN
	template <class Cmpt, int length>
	VectorN<Cmpt, length> sumToDiag(const TensorN<Cmpt, length>& t)
	{
		VectorN<Cmpt, length> result;
		sumToDiag(result, t);
		return result;
	}


	//- Sum magnitudes of row elements of a TensorN as a vectorN
	template <class Cmpt, int length>
	void sumMagToDiag
	(
		VectorN<Cmpt, length>& result,
		const TensorN<Cmpt, length>& t
	)
	{
		result = VectorN<Cmpt, length>::zero;

		for (register int i = 0; i < TensorN<Cmpt, length>::rowLength; i++)
		{
			for (register int j = 0; j < TensorN<Cmpt, length>::rowLength; j++)
			{
				result[i] += tnbLib::mag(t(i, j));
			}
		}
	}


	//- Sum magnitudes of row elements of a TensorN as a vectorN
	template <class Cmpt, int length>
	VectorN<Cmpt, length> sumMagToDiag(const TensorN<Cmpt, length>& t)
	{
		VectorN<Cmpt, length> result;
		sumMagToDiag(result, t);
		return result;
	}


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //