#pragma once
#ifndef _Marine_StationInfo_Header
#define _Marine_StationInfo_Header

#include <Standard_TypeDef.hxx>
#include <Marine_StationType.hxx>

namespace AutLib
{

	class Marine_StationInfo
	{

		/*Private Data*/

		Marine_StationType theType_;

		Standard_Real theX_;
		Standard_Real theZbar_;

		Standard_Real theT_;
		Standard_Real theArea_;
		Standard_Real theLength_;

	protected:

		Marine_StationInfo();


		Marine_StationType& ChangeType()
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

		Marine_StationType Type() const
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

#endif // !_Marine_StationInfo_Header
