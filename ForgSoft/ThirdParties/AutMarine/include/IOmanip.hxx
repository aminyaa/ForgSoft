#pragma once
#ifndef _IOmanip_Header
#define _IOmanip_Header

#include <Istream.hxx>
#include <Ostream.hxx>

namespace AutLib
{

	// Forward declaration of friend functions and operators

	template<class T> class Smanip;
	template<class T> class Imanip;
	template<class T> class Omanip;

	template<class T>
	inline Istream& operator>>(Istream& is, const Smanip<T>& m);

	template<class T>
	inline Ostream& operator<<(Ostream& os, const Smanip<T>& m);

	template<class T>
	inline Istream& operator>>(Istream& is, const Imanip<T>& m);

	template<class T>
	inline Ostream& operator<<(Ostream& os, const Omanip<T>& m);

	template<class T>
	class Smanip
	{
		T(IOstream::*_fPtr)(const T);
		T _i;

	public:

		Smanip(T(IOstream::*fPtr)(const T), const T i)
			: _fPtr(fPtr)
			, _i(i)
		{
		}

		template<class T>
		friend Istream& operator>>(Istream& is, const Smanip<T>& m);

		template<class T>
		friend Ostream& operator<<(Ostream& os, const Smanip<T>& m);
	};


	template<class T>
	inline Istream& operator>>(Istream& is, const Smanip<T>& m)
	{
		(is.*m._fPtr)(m._i);
		return is;
	}


	template<class T>
	inline Ostream& operator<<(Ostream& os, const Smanip<T>& m)
	{
		(os.*m._fPtr)(m._i);
		return os;
	}

	template<class T>
	class Imanip
	{
		T(Istream::*_fPtr)(const T);
		T _i;

	public:

		Imanip(T(Istream::*fPtr)(const T), const T i)
			: _fPtr(fPtr)
			, _i(i)
		{
		}

		template<class T>
		friend Istream& operator>>(Istream& is, const Imanip<T>& m);
	};


	template<class T>
	inline Istream& operator>>(Istream& is, const Imanip<T>& m)
	{
		(is.*m._fPtr)(m._i);
		return is;
	}

	template<class T>
	class Omanip
	{
		T(Ostream::*_fPtr)(const T);
		T _i;

	public:

		Omanip(T(Ostream::*fPtr)(const T), const T i)
			: _fPtr(fPtr)
			, _i(i)
		{
		}

		template<class T>
		friend Ostream& operator<<(Ostream& os, const Omanip<T>& m);
	};


	template<class T>
	inline Ostream& operator<<(Ostream& os, const Omanip<T>& m)
	{
		(os.*m._fPtr)(m._i);
		return os;
	}

	inline Smanip<ios_base::fmtflags> setf
	(
		const ios_base::fmtflags flags
	)
	{
		return Smanip<ios_base::fmtflags>(&IOstream::setf, flags);
	}


	inline Omanip<IOstream::streamFormat> setformat
	(
		const IOstream::streamFormat fmt
	)
	{
		return Omanip<IOstream::streamFormat>(&IOstream::format, fmt);
	}


	inline Omanip<IOstream::versionNumber> setversion
	(
		const IOstream::versionNumber ver
	)
	{
		return Omanip<IOstream::versionNumber>(&IOstream::version, ver);
	}


	inline Omanip<IOstream::compressionType> setcompression
	(
		const IOstream::compressionType cmp
	)
	{
		return Omanip<IOstream::compressionType>(&IOstream::compression, cmp);
	}


	inline Omanip<int> setw(const int i)
	{
		return Omanip<int>(&Ostream::width, i);
	}


	inline Omanip<int> setprecision(const int i)
	{
		return Omanip<int>(&Ostream::precision, i);
	}
}

#endif // !_IOmanip_Header
