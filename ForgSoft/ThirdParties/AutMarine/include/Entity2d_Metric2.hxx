#pragma once
#ifndef _Entity2d_Metric2_Header
#define _Entity2d_Metric2_Header

#include <Dir2d.hxx>
#include <error.hxx>
#include <OSstream.hxx>

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

namespace AutLib
{

	// Forward Declarations
	class Entity2d_Metric1;

	class Entity2d_Metric2
	{

		friend class boost::serialization::access;

		/*Private Data*/

		gp_Dir2d theE1_;
		gp_Dir2d theE2_;

		Standard_Real theH1_;
		Standard_Real theH2_;


		template<class Archive>
		void serialize(Archive& ar, const unsigned int version);

	public:

		Entity2d_Metric2()
			: theH1_(1.0)
			, theH2_(1.0)
			, theE1_(gp::DX2d())
			, theE2_(gp::DY2d())
		{}

		Entity2d_Metric2
		(
			const Standard_Real theH1,
			const Standard_Real theH2,
			const gp_Dir2d& theE1,
			const gp_Dir2d& theE2
		)
			: theH1_(theH1)
			, theH2_(theH2)
			, theE1_(theE1)
			, theE2_(theE2)
		{}

		Standard_Real H1() const
		{
			return theH1_;
		}

		Standard_Real& H1()
		{
			return theH1_;
		}

		Standard_Real H2() const
		{
			return theH2_;
		}

		Standard_Real& H2()
		{
			return theH2_;
		}

		const gp_Dir2d& E1() const
		{
			return theE1_;
		}

		gp_Dir2d& E1()
		{
			return theE1_;
		}

		const gp_Dir2d& E2() const
		{
			return theE2_;
		}

		gp_Dir2d& E2()
		{
			return theE2_;
		}

		Standard_Boolean IsDegenerated
		(
			const Standard_Real theTol
		) const
		{
			return E1().Crossed(E2()) <= theTol;
		}

		void SetH1
		(
			const Standard_Real theH1
		)
		{
			if (theH1 <= gp::Resolution())
			{
				FatalErrorIn("void SetH1(const Standard_Real theH1)")
					<< "too small value for h1" << endl
					<< abort(FatalError);
			}
			theH1_ = theH1;
		}

		void SetH2
		(
			const Standard_Real theH2
		)
		{
			if (theH2 <= gp::Resolution())
			{
				FatalErrorIn("void SetH1(const Standard_Real theH1)")
					<< "too small value for h1" << endl
					<< abort(FatalError);
			}
			theH2_ = theH2;
		}

		void SetE1
		(
			const gp_Dir2d& theE1
		)
		{
			theE1_ = theE1;
		}

		void SetE2
		(
			const gp_Dir2d& theE2
		)
		{
			theE2_ = theE2;
		}

		// static functions and operators

		static Entity2d_Metric1 ConvertTo1
		(
			const Entity2d_Metric2& theMetric
		);
	};
}

#include <Entity2d_Metric2I.hxx>

#endif // !_Entity2d_Metric2_Header
