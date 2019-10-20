#pragma once
#ifndef _Vessel_StationInfo_Header
#define _Vessel_StationInfo_Header

#include <Vessel_StationType.hxx>
#include <Standard_TypeDef.hxx>

namespace AutLib
{

	class Vessel_StationInfo
	{

		/*Private Data*/

		Vessel_StationType theType_;

		Standard_Real theX_;
		Standard_Real theZbar_;

		Standard_Real theT_;
		Standard_Real theArea_;
		Standard_Real theLength_;

	protected:

		Vessel_StationInfo();


		Vessel_StationType& ChangeType()
		{
			return theType_;
		}

		Standard_Real& Change_zBar()
		{
			return theZbar_;
		}

		Standard_Real& ChangeT()
		{
			return theT_;
		}

		Standard_Real& Area()
		{
			return theArea_;
		}

		Standard_Real& Length()
		{
			return theLength_;
		}


	public:

		Vessel_StationType Type() const
		{
			return theType_;
		}

		Standard_Real X() const
		{
			return theX_;
		}

		Standard_Real zBar() const
		{
			return theZbar_;
		}

		Standard_Real Area() const
		{
			return theArea_;
		}

		Standard_Real Length() const
		{
			return theLength_;
		}
	};
}

#endif // !_Vessel_StationInfo_Header
