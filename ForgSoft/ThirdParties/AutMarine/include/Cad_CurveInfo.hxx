#pragma once
#ifndef _Cad_CurveInfo_Header
#define _Cad_CurveInfo_Header

#include <Standard_TypeDef.hxx>

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

#include <iostream>

namespace AutLib
{

	class Cad_CurveInfo
	{

		friend class boost::serialization::access;

		/*Private Data*/

		Standard_Integer theNbDivisions_;

		template<class Archive>
		void serialize(Archive& ar, const unsigned int version) { ar& theNbDivisions_; }

	public:

		static const Standard_Integer DEFAULT_NB_DIVISIONS;

		Cad_CurveInfo()
			: theNbDivisions_(DEFAULT_NB_DIVISIONS)
		{}

		Standard_Integer NbDivisions() const
		{
			return theNbDivisions_;
		}

		void SetNbDivisions(const Standard_Integer theValue)
		{
			theNbDivisions_ = theValue;
		}
	};
}

#endif // !_Cad_CurveInfo_Header