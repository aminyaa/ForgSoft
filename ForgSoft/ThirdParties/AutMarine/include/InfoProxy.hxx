#pragma once
#ifndef _InfoProxy_Header
#define _InfoProxy_Header

namespace AutLib
{

	template<class T>
	class InfoProxy
	{

	public:

		const T& t_;

		InfoProxy(const T& t)
			: t_(t)
		{}
	};
}

#endif // !_InfoProxy_Header
