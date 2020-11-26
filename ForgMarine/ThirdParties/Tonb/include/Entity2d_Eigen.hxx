#pragma once
#ifndef _Entity2d_Eigen_Header
#define _Entity2d_Eigen_Header

#include <Global_Done.hxx>
#include <Pnt2d.hxx>
#include <armadillo.h>


namespace tnbLib
{

	// Forward Declarations
	class Entity2d_Metric1;

	struct Entity2d_EigenInfo
	{
		Standard_Real Zero;

		Entity2d_EigenInfo() : Zero(1.0E-6) {}
	};

	class Entity2d_Eigen
		: public Entity2d_EigenInfo
		, public Global_Done
	{

		/*Private Data*/

		Pnt2d theE1_;
		Pnt2d theE2_;

		Standard_Real theH1_;
		Standard_Real theH2_;

		Standard_Real theLamda1_;
		Standard_Real theLamda2_;

	public:

		Entity2d_Eigen()
		{}

		const Pnt2d& E1() const
		{
			return theE1_;
		}

		const Pnt2d& E2() const
		{
			return theE2_;
		}

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

		Standard_Real Lamda1() const
		{
			return theLamda1_;
		}

		Standard_Real& Lamda1()
		{
			return theLamda1_;
		}

		Standard_Real Lamda2() const
		{
			return theLamda2_;
		}

		Standard_Real& Lamda2()
		{
			return theLamda2_;
		}

		void CalcEigen(const Entity2d_Metric1& M);

		void CalcEigen(const arma::mat22& M);

		void CalcGenEigen(const Entity2d_Metric1& A, const Entity2d_Metric1& B);

		void ExportToPlt(fstream& File) const;

		void ExportToPlt(const Pnt2d& Centre, OFstream& File) const;

		void Print(Standard_OStream& ostream = cout) const;

		//- Static functions and operators


	};
}

#include <Entity2d_EigenI.hxx>

#endif // !_Entity2d_Eigen_Header
