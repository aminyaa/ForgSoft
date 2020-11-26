#pragma once
#ifndef _InfoProxy_Header
#define _InfoProxy_Header

namespace tnbLib
{

	class Ostream;

	/*---------------------------------------------------------------------------*\
							   Class InfoProxy Declaration
	\*---------------------------------------------------------------------------*/

	template<class T> class InfoProxy;
	template<class T> Ostream& operator<<(Ostream&, const InfoProxy<T>&);

	template<class T>
	class InfoProxy
	{
	public:

		const T& t_;

		InfoProxy(const T& t)
			:
			t_(t)
		{}

		friend Ostream& operator<< <T>
			(Ostream&, const InfoProxy<T>&);
	};
}

#endif // !_InfoProxy_Header
