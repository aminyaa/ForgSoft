#pragma once
#ifndef _Entity2d_Metric1_Header
#define _Entity2d_Metric1_Header

#include <Standard_TypeDef.hxx>
#include <Pnt2d.hxx>
#include <armadillo.h>

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

#include <iostream>
#include <fstream>

namespace AutLib
{

	class Entity2d_Metric1
	{

		typedef Entity2d_Metric1 metric;

		friend class boost::serialization::access;

		/*Private Data*/

		Standard_Real theA_;
		Standard_Real theB_;
		Standard_Real theC_;


		template<class Archive>
		void serialize(Archive& ar, const unsigned int version);

	public:

		Entity2d_Metric1()
		{}

		Entity2d_Metric1
		(
			const Standard_Real A, 
			const Standard_Real B, 
			const Standard_Real C
		)
			: theA_(A)
			, theB_(B)
			, theC_(C)
		{}

		Entity2d_Metric1
		(
			const Standard_Real Lamda1,
			const Standard_Real Lamda2,
			const Pnt2d& E1, 
			const Pnt2d& E2
		);

		metric& operator*=(const Standard_Real Scalar);

		arma::mat22 Arma() const;

		Standard_Real Determinant() const
		{
			return theA_ * theC_ - theB_ * theB_;
		}

		Standard_Real A() const
		{
			return theA_;
		}

		Standard_Real B() const
		{
			return theB_;
		}

		Standard_Real C() const
		{
			return theC_;
		}

		Standard_Real& A()
		{
			return theA_;
		}

		Standard_Real& B()
		{
			return theB_;
		}

		Standard_Real& C()
		{
			return theC_;
		}

		Standard_Boolean IsSingular(const Standard_Real theEps) const
		{
			return Determinant() <= theEps;
		}

		Pnt2d Multiplied(const Pnt2d& theU) const
		{
			Pnt2d P(theA_*theU.X() + theB_ * theU.Y(), theB_*theU.X() + theC_ * theU.Y());
			return std::move(P);
		}

		gp_Vec2d Multiplied(const gp_Vec2d& theU) const
		{
			gp_Vec2d P(theA_*theU.X() + theB_ * theU.Y(), theB_*theU.X() + theC_ * theU.Y());
			return std::move(P);
		}

		metric Inversed() const
		{
			auto copy = *this;
			copy.Inverse();
			return std::move(copy);
		}

		metric SQRT() const;

		void Inverse();

		void Print(Standard_OStream& Ostream = cout) const;

		void ExportToPlt(const Pnt2d& Centre, fstream& File) const;

		void ExportToPlt(fstream& File) const;

		friend Entity2d_Metric1 operator*(const Entity2d_Metric1& Metric, const Standard_Real Scalar);
		friend Entity2d_Metric1 operator*(const Standard_Real Scalar, const Entity2d_Metric1& Metric);
		friend Entity2d_Metric1 operator+(const Entity2d_Metric1& theMetric1, const Entity2d_Metric1& theMetric2);

		//- Static functions 

		static metric Avg(const metric& M1, const metric& M2);

		static metric IntersectionSR(const metric& M1, const metric& M2);

		static metric IntersectionPD(const metric& M1, const metric& M2);

		static metric UnionSR(const metric& M1, const metric& M2);

		static metric IntersectionPD_Inverse(const metric& M1, const metric& M2);

		static metric InterpolationIM(const Standard_Real t, const metric& M1, const metric& M2);

		static metric InterpolationIM
		(
			const Standard_Real c1,
			const Standard_Real c2, 
			const Standard_Real c3,
			const metric& M1, 
			const metric& M2, 
			const metric& M3
		);

		static metric Interpolation
		(
			const Standard_Real c1,
			const Standard_Real c2,
			const Standard_Real c3,
			const metric& M1,
			const metric& M2,
			const metric& M3
		);

		static Standard_Real DistanceSQ
		(
			const Pnt2d& P1, 
			const Pnt2d& P2,
			const metric& M
		)
		{
			Standard_Real Dx = P2.X() - P1.X();
			Standard_Real Dy = P2.Y() - P1.Y();
			return M.A()*Dx*Dx + 2.0*M.B()*Dx*Dy + M.C()*Dy*Dy;
		}

		static Standard_Real Distance
		(
			const Pnt2d& P1,
			const Pnt2d& P2,
			const metric& M
		)
		{
			return sqrt(DistanceSQ(P1, P2, M));
		}
	};
}

#include <Entity2d_Metric1I.hxx>

#endif // !_Entity2d_Metric1_Header
