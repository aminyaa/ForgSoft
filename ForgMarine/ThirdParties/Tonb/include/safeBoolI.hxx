#pragma once
// * * * * * * * * * * * * * * * Member Operators  * * * * * * * * * * * * * //

template <typename T>
bool operator==(const tnbLib::safeBool<T>& lhs, bool b)
{
	if (b)
	{
		if (lhs)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		if (lhs)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
}

template <typename T>
bool operator==(bool b, const tnbLib::safeBool<T>& rhs)
{
	if (b)
	{
		if (rhs)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		if (rhs)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
}


template <typename T, typename U>
bool operator==
(
	const tnbLib::safeBool<T>& lhs,
	const tnbLib::safeBool<U>& rhs
	)
{
	lhs.this_type_does_not_support_comparisons();
	return false;
}

template <typename T, typename U>
bool operator!=
(
	const tnbLib::safeBool<T>& lhs,
	const tnbLib::safeBool<U>& rhs
	)
{
	lhs.this_type_does_not_support_comparisons();
	return false;
}


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //