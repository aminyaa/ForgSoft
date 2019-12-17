#pragma once
#ifndef _CadCascade_Regular_Header
#define _CadCascade_Regular_Header

#include <CadCascade_Model.hxx>

namespace AutLib
{

	class CadCascade_Regular
		: public CadCascade_Model
	{

		/*Private Data*/

	protected:

		CadCascade_Regular()
		{}

		CadCascade_Regular(const Standard_Integer theIndex, const word& theName)
			: CadCascade_Model(theIndex, theName)
		{}

	public:

		
	};
}

#endif // !_CadCascade_Regular_Header
