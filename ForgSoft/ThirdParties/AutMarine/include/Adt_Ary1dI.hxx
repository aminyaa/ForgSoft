#pragma once

namespace AutLib
{
	template<class T>
	Adt_Ary1d<T> operator+(const Adt_Ary1d<T>& V1, const Adt_Ary1d<T>& V2)
	{
		if (V1.Size() NOT_EQUAL V2.Size())
		{
			FatalErrorIn("AutLib::ADT_Ary1d<T>& AutLib::ADT_Ary1d<T>::operator/=(const ADT_Ary1d<T>& Other)")
				<< "No match between two array sizes"
				<< abort(FatalError);
		}

		auto Temp = V1;
		Temp += V2;

		MOVE(Temp);
	}

	template<class T>
	Adt_Ary1d<T> operator-(const Adt_Ary1d<T>& V1, const Adt_Ary1d<T>& V2)
	{
		if (V1.Size() NOT_EQUAL V2.Size())
		{
			FatalErrorIn("AutLib::ADT_Ary1d<T>& AutLib::ADT_Ary1d<T>::operator/=(const ADT_Ary1d<T>& Other)")
				<< "No match between two array sizes"
				<< abort(FatalError);
		}

		auto Temp = V1;
		Temp -= V2;

		MOVE(Temp);
	}

	template<class T>
	Adt_Ary1d<T> operator*(const Adt_Ary1d<T>& V1, const Adt_Ary1d<T>& V2)
	{
		if (V1.Size() NOT_EQUAL V2.Size())
		{
			FatalErrorIn("AutLib::ADT_Ary1d<T>& AutLib::ADT_Ary1d<T>::operator/=(const ADT_Ary1d<T>& Other)")
				<< "No match between two array sizes"
				<< abort(FatalError);
		}

		auto Temp = V1;
		Temp *= V2;

		MOVE(Temp);
	}

	template<class T>
	Adt_Ary1d<T> operator/(const Adt_Ary1d<T>& V1, const Adt_Ary1d<T>& V2)
	{
		if (V1.Size() NOT_EQUAL V2.Size())
		{
			FatalErrorIn("AutLib::ADT_Ary1d<T>& AutLib::ADT_Ary1d<T>::operator/=(const ADT_Ary1d<T>& Other)")
				<< "No match between two array sizes"
				<< abort(FatalError);
		}

		auto Temp = V1;
		Temp /= V2;

		MOVE(Temp);
	}

	template<class T>
	Adt_Ary1d<T> operator+(const Adt_Ary1d<T>& V1, const T& Entity)
	{
		auto Temp = V1;
		Temp += Entity;

		MOVE(Temp);
	}

	template<class T>
	Adt_Ary1d<T> operator+(const T& Entity, const Adt_Ary1d<T>& V1)
	{
		auto Temp = V1;
		Temp += Entity;

		MOVE(Temp);
	}

	template<class T>
	Adt_Ary1d<T> operator-(const Adt_Ary1d<T>& V1, const T& Entity)
	{
		auto Temp = V1;
		Temp -= Entity;

		MOVE(Temp);
	}

	template<class T>
	Adt_Ary1d<T> operator-(const T& Entity, const Adt_Ary1d<T>& V1)
	{
		auto Temp = V1;
		Temp -= Entity;

		MOVE(Temp);
	}

	template<class T>
	Adt_Ary1d<T> operator*(const Adt_Ary1d<T>& V1, const T& Entity)
	{
		auto Temp = V1;
		Temp *= Entity;

		MOVE(Temp);
	}

	template<class T>
	Adt_Ary1d<T> operator*(const T& Entity, const Adt_Ary1d<T>& V1)
	{
		auto Temp = V1;
		Temp *= Entity;

		MOVE(Temp);
	}

	template<class T>
	Adt_Ary1d<T> operator/(const Adt_Ary1d<T>& V1, const T& Entity)
	{
		auto Temp = V1;
		Temp /= Entity;

		MOVE(Temp);
	}
}