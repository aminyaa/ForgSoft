#pragma once
#ifndef _Pln_EdgeAdaptor_Header
#define _Pln_EdgeAdaptor_Header

#include <Global_AccessMethod.hxx>

#include <memory>

namespace tnbLib
{

	// Forward Declarations
	class Pln_Wire;

	class Pln_EdgeAdaptor
	{

		/*Private Data*/

		std::weak_ptr<Pln_Wire> theWire_;

	protected:

		Pln_EdgeAdaptor()
		{}

	public:

		//- Macros
		GLOBAL_ACCESS_SINGLE(std::weak_ptr<Pln_Wire>, Wire)
	};
}

#endif // !_Pln_EdgeAdaptor_Header
