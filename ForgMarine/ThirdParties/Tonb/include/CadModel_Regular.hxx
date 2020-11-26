#pragma once
#ifndef _CadModel_Regular_Header
#define _CadModel_Regular_Header

#include <CadModel_Entity.hxx>

namespace tnbLib
{

	class CadModel_Regular
		: public CadModel_Entity
	{

		/*Private Data*/

	protected:

		CadModel_Regular()
		{}

		CadModel_Regular(const Standard_Integer theIndex);

		CadModel_Regular(const Standard_Integer theIndex, const word& theName);

	public:

		virtual ~CadModel_Regular()
		{}

		void PerformToPreview() override;
	};
}

#endif // !_CadModel_Regular_Header
