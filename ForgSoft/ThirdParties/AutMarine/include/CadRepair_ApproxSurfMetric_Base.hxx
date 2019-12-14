#pragma once
#ifndef _CadRepair_ApproxSurfMetric_Base_Header
#define _CadRepair_ApproxSurfMetric_Base_Header

#include <Standard_TypeDef.hxx>

namespace AutLib
{

	class CadRepair_ApproxSurfMetric_Base
	{

		/*Private Data*/

		Standard_Real theMaxDet_;
		Standard_Real theMinDet_;

		Standard_Boolean HasDegeneracy_;

	protected:

		CadRepair_ApproxSurfMetric_Base();


		Standard_Real& ChangeMaxDet()
		{
			return theMaxDet_;
		}

		Standard_Real& ChangeMinDet()
		{
			return theMinDet_;
		}

		Standard_Boolean& Change_HasDegeneracy()
		{
			return HasDegeneracy_;
		}

	public:

		Standard_Real MaxDet() const
		{
			return theMaxDet_;
		}

		Standard_Real MinDet() const
		{
			return theMinDet_;
		}

		Standard_Boolean HasDegeneracy() const
		{
			return HasDegeneracy_;
		}
	};
}

#endif // !_CadRepair_ApproxSurfMetric_Base_Header
