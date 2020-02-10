#pragma once
#ifndef _Entity3d_Metric1_Header
#define _Entity3d_Metric1_Header

#include <Standard_TypeDef.hxx>
#include <Global_AccessMethod.hxx>
#include <Pnt2d.hxx>
#include <Pnt3d.hxx>
#include <armadillo.h>

#include <iostream>
#include <fstream>

namespace tnbLib
{

	class Entity3d_Metric1
	{

		typedef Entity3d_Metric1 metric;

		/*Private Data*/

		Standard_Real theA_;
		Standard_Real theB_;
		Standard_Real theC_;
		Standard_Real theD_;
		Standard_Real theE_;
		Standard_Real theF_;

	public:

		Entity3d_Metric1()
		{}

		Entity3d_Metric1
		(
			const Standard_Real A,
			const Standard_Real B,
			const Standard_Real C,
			const Standard_Real D,
			const Standard_Real E,
			const Standard_Real F
		);

		metric& operator*=(const Standard_Real Scalar);

		arma::mat33 Arma() const;

		Standard_Real Determinant() const;

		Standard_Boolean IsSingular(const Standard_Real theEps) const;

		Pnt3d Multiplied(const Pnt3d& theU) const;

		gp_Vec Multiplied(const gp_Vec& theU) const;

		metric Inversed() const;

		void Inverse();

		void Print(Standard_OStream& Ostream = cout) const;

		void ExportToPlt(const Pnt2d& Centre, fstream& File) const;

		void ExportToPlt(fstream& File) const;

		friend metric operator*(const metric& Metric, const Standard_Real Scalar);
		friend metric operator*(const Standard_Real Scalar, const metric& Metric);
		friend metric operator+(const metric& theMetric1, const metric& theMetric2);

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
			const Standard_Real c4,
			const metric& M1,
			const metric& M2,
			const metric& M3,
			const metric& M4
		);

		static metric Interpolation
		(
			const Standard_Real c1,
			const Standard_Real c2,
			const Standard_Real c3,
			const Standard_Real c4,
			const metric& M1,
			const metric& M2,
			const metric& M3,
			const metric& M4
		);

		static Standard_Real DistanceSQ
		(
			const Pnt3d& P1,
			const Pnt3d& P2,
			const metric& M
		);

		static Standard_Real Distance
		(
			const Pnt3d& P1,
			const Pnt3d& P2,
			const metric& M
		);

		//- Macros

		GLOBAL_ACCESS_PRIM_SINGLE(Standard_Real, A)
			GLOBAL_ACCESS_PRIM_SINGLE(Standard_Real, B)
			GLOBAL_ACCESS_PRIM_SINGLE(Standard_Real, C)
			GLOBAL_ACCESS_PRIM_SINGLE(Standard_Real, D)
			GLOBAL_ACCESS_PRIM_SINGLE(Standard_Real, E)
			GLOBAL_ACCESS_PRIM_SINGLE(Standard_Real, F)
	};
}

#endif // !_Entity3d_Metric1_Header
