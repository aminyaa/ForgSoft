#pragma once
#ifndef _safeBool_Header
#define _safeBool_Header

namespace AutLib
{

	class safeBoolBase
	{

	public:

		typedef void (safeBoolBase::*boolType)() const;

		void thisTypeDoesNotSupportComparisons() const
		{}

	protected:

		safeBoolBase()
		{}

		safeBoolBase(const safeBoolBase&)
		{}

		safeBoolBase& operator=(const safeBoolBase&)
		{
			return *this;
		}

		~safeBoolBase()
		{}
	};

	template <typename T = void>
	class safeBool
		: private safeBoolBase
	{

		// private or protected inheritance is very important here as it triggers the
		// access control violation in main.

	public:

		operator boolType() const
		{
			return (static_cast<const T*>(this))->test() ? &safeBoolBase::thisTypeDoesNotSupportComparisons : 0;
		}

	protected:

		~safeBool()
		{}
	};
}

template <typename T>
inline bool operator==(const AutLib::safeBool<T>& lhs, bool b)
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
inline bool operator==(bool b, const AutLib::safeBool<T>& rhs)
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
inline bool operator==
(
	const AutLib::safeBool<T>& lhs,
	const AutLib::safeBool<U>& rhs
	)
{
	lhs.this_type_does_not_support_comparisons();
	return false;
}

template <typename T, typename U>
inline  bool operator!=
(
	const AutLib::safeBool<T>& lhs,
	const AutLib::safeBool<U>& rhs
	)
{
	lhs.this_type_does_not_support_comparisons();
	return false;
}

#endif // !_safeBool_Header
