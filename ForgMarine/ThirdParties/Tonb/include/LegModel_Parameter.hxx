#pragma once
#ifndef _LegModel_Parameter_Header
#define _LegModel_Parameter_Header

#include <Global_Indexed.hxx>
#include <Global_Named.hxx>

namespace tnbLib
{

	class LegModel_Parameter
		: public Global_Indexed
		, public Global_Named
	{

		/*Private Data*/

		Standard_Real theValue_;

	protected:

		LegModel_Parameter()
			: theValue_(0)
		{}

		LegModel_Parameter
		(
			const Standard_Real theValue
		)
			: theValue_(theValue)
		{}

		LegModel_Parameter
		(
			const Standard_Integer theIndex,
			const word& theName,
			const Standard_Real theValue
		)
			: theValue_(theValue)
		{}

	public:

		auto Value() const
		{
			return theValue_;
		}

		auto& Value()
		{
			return theValue_;
		}


		virtual Standard_Boolean IsBounded() const
		{
			return Standard_False;
		}

		virtual Standard_Boolean IsConstant() const
		{
			return Standard_False;
		}
	};
}

#endif // !_LegModel_Parameter_Header
