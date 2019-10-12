#pragma once
#ifndef _Leg_Model_Parameter_Header
#define _Leg_Model_Parameter_Header

#include <Standard_TypeDef.hxx>
#include <Global_Indexed.hxx>
#include <Global_Named.hxx>

namespace AutLib
{

	class Leg_Model_Parameter
		: public Global_Indexed
		, public Global_Named
	{

		/*private Data*/

		Standard_Real theValue_;

	protected:

		Leg_Model_Parameter()
			: theValue_(0)
		{}

		Leg_Model_Parameter(const Standard_Real theValue)
			: theValue_(theValue)
		{}

		Leg_Model_Parameter
		(
			const Standard_Integer theIndex, 
			const word& theName, 
			const Standard_Real theValue
		)
			: theValue_(theValue)
			, Global_Indexed(theIndex)
			, Global_Named(theName)
		{}

	public:

		Standard_Real Value() const
		{
			return theValue_;
		}

		virtual void SetValue(const Standard_Real theValue)
		{
			theValue_ = theValue;
		}

		virtual Standard_Boolean IsConstant() const
		{
			return Standard_False;
		}

		virtual Standard_Boolean IsBounded() const
		{
			return Standard_False;
		}
	};
}

#endif // !_Leg_Model_Parameter_Header
