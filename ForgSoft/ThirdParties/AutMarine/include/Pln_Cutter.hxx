#pragma once
#ifndef _Pln_Cutter_Header
#define _Pln_Cutter_Header

#include <Pln_Edge.hxx>

namespace AutLib
{

	class Pln_Cutter
		: public Pln_Edge
	{

		/*Private Data*/

		std::shared_ptr<Pln_Edge> theParent_;

	public:

		Pln_Cutter(const std::shared_ptr<Pln_Edge>& theParent);


		//- override functions and operators

		Standard_Boolean IsRing() const override
		{
			return theParent_->IsRing();
		}
	};
}

#endif // !_Pln_Cutter_Header
