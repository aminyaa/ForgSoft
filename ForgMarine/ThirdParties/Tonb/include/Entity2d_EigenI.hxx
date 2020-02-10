#pragma once
//#include <Numeric_Eigen22.hxx>
#include <Entity2d_Metric1.hxx>
namespace tnbLib
{

	inline
	void Entity2d_Eigen::CalcEigen(const Entity2d_Metric1 & M)
	{
		/*Standard_Real A[2][2];
		A[0][0] = M.A();
		A[0][1] = A[1][0] = M.B();
		A[1][1] = M.C();

		Standard_Real eVals[2];
		Standard_Real eVecs[2][2];

		Numeric_Eigen22::CalcEigen(A, eVals, eVecs, Zero);

		theE1_.X() = eVecs[0][0];
		theE1_.Y() = eVecs[1][0];

		theE2_.X() = eVecs[0][1];
		theE2_.Y() = eVecs[1][1];

		theLamda1_ = eVals[0];
		theLamda2_ = eVals[1];

		theH1_ = 1.0 / sqrt(theLamda1_);
		theH2_ = 1.0 / sqrt(theLamda2_);*/

		arma::mat22 A;
		A(0, 0) = M.A();
		A(0, 1) = A(1, 0) = M.B();
		A(1, 1) = M.C();

		arma::vec2 eigval;
		arma::mat22 eigvec;

		arma::eig_sym(eigval, eigvec, A);

		theE1_.X() = eigvec(0, 0);
		theE1_.Y() = eigvec(1, 0);

		theE2_.X() = eigvec(0, 1);
		theE2_.Y() = eigvec(1, 1);

		theLamda1_ = eigval[0];
		theLamda2_ = eigval[1];

		theH1_ = 1.0 / sqrt(theLamda1_);
		theH2_ = 1.0 / sqrt(theLamda2_);

		Change_IsDone() = Standard_True;
	}

	inline 
		void tnbLib::Entity2d_Eigen::CalcEigen
		(
			const arma::mat22 & A
		)
	{
		arma::vec2 eigval;
		arma::mat22 eigvec;

		arma::eig_sym(eigval, eigvec, A);

		theE1_.X() = eigvec(0, 0);
		theE1_.Y() = eigvec(1, 0);

		theE2_.X() = eigvec(0, 1);
		theE2_.Y() = eigvec(1, 1);

		theLamda1_ = eigval[0];
		theLamda2_ = eigval[1];

		theH1_ = 1.0 / sqrt(theLamda1_);
		theH2_ = 1.0 / sqrt(theLamda2_);

		Change_IsDone() = Standard_True;
	}
}