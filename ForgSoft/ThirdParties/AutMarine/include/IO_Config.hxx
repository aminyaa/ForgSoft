#pragma once
#ifndef _IO_Config_Header
#define _IO_Config_Header

#include <Standard_TypeDef.hxx>

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

#include <memory>

namespace AutLib
{

	struct FastDiscrete_Params;

	class IO_Config
	{

		friend class boost::serialization::access;

		/*Private Data*/

		Standard_Boolean FixShape_;
		Standard_Boolean Discrete_;

		Standard_Real theMinTol_;
		Standard_Real theMaxTol_;
		Standard_Real thePrecision_;

		std::shared_ptr<FastDiscrete_Params> theParams_;

		template<class Archive>
		void serialize(Archive& ar, const unsigned int version)
		{
			ar& FixShape_;
			ar& Discrete_;

			ar& theMinTol_;
			ar& theMaxTol_;
			ar& thePrecision_;
		}

	public:

		IO_Config(const std::shared_ptr<FastDiscrete_Params>& theParams)
			: FixShape_(Standard_False)
			, Discrete_(Standard_False)
			, theParams_(theParams)
		{}

		Standard_Boolean FixShape() const
		{
			return FixShape_;
		}

		Standard_Boolean Discrete() const
		{
			return Discrete_;
		}

		Standard_Real MinTol() const
		{
			return theMinTol_;
		}

		Standard_Real MaxTol() const
		{
			return theMaxTol_;
		}

		Standard_Real Precision() const
		{
			return thePrecision_;
		}

		const std::shared_ptr<FastDiscrete_Params>& FastDiscreteParams() const
		{
			return theParams_;
		}

		void SetToFixShape()
		{
			FixShape_ = Standard_True;
		}

		void SetToDiscrete()
		{
			Discrete_ = Standard_True;
		}

		void SetMinTol(const Standard_Real theMinTol)
		{
			theMinTol_ = theMinTol;
		}

		void SetMaxTol(const Standard_Real theMaxTol)
		{
			theMaxTol_ = theMaxTol;
		}

		void SetPrecision(const Standard_Real thePrec)
		{
			thePrecision_ = thePrec;
		}
	};
}

#endif // !_IO_Config_Header
