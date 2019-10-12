#pragma once

namespace AutLib
{

	template<class Archive>
	void Entity2d_Metric1::serialize
	(
		Archive & ar,
		const unsigned int version
	)
	{
		ar& A();
		ar& B();
		ar& C();
	}

	inline Entity2d_Metric1 & Entity2d_Metric1::operator*=(const Standard_Real Scalar)
	{
		theA_ *= Scalar;
		theB_ *= Scalar;
		theC_ *= Scalar;

		return *this;
	}

	inline arma::mat22 Entity2d_Metric1::Arma() const
	{
		arma::mat22 m;
		m(0, 0) = theA_;
		m(0, 1) = m(1, 0) = theB_;
		m(1, 1) = theC_;

		return std::move(m);
	}

	inline void AutLib::Entity2d_Metric1::Inverse()
	{
		Standard_Real D = 1.0 / Determinant();
		std::swap(theA_, theC_);

		theB_ *= -D;
		theA_ *= D;
		theC_ *= D;
	}

	inline Entity2d_Metric1::Entity2d_Metric1
	(
		const Standard_Real Lamda1,
		const Standard_Real Lamda2,
		const Pnt2d & E1,
		const Pnt2d & E2
	)
	{
		arma::mat22 H;
		H(0, 0) = Lamda1;
		H(1, 0) = H(0, 1) = 0;
		H(1, 1) = Lamda2;

		arma::mat22 S;
		S(0, 0) = E1.X();
		S(1, 0) = E1.Y();
		S(0, 1) = E2.X();
		S(1, 1) = E2.Y();

		arma::mat22 M = trans(S)*H*S;

		theA_ = M(0, 0);
		theB_ = M(0, 1);
		theC_ = M(1, 1);
	}

	inline Entity2d_Metric1 Entity2d_Metric1::Avg(const metric & M1, const metric & M2)
	{
		return metric(0.5*(M1.A() + M2.A()), 0.5*(M1.B() + M2.B()), 0.5*(M1.C() + M2.C()));
	}

	inline Entity2d_Metric1 Entity2d_Metric1::Interpolation
	(
		const Standard_Real c1,
		const Standard_Real c2,
		const Standard_Real c3,
		const metric & M1,
		const metric & M2,
		const metric & M3
	)
	{
		return metric
		(
			c1*M1.A() + c2 * M2.A() + c3 * M3.A(),
			c1*M1.B() + c2 * M2.B() + c3 * M3.B(),
			c1*M1.C() + c2 * M2.C() + c3 * M3.C()
		);
	}


	inline Entity2d_Metric1 operator*(const Entity2d_Metric1 & Metric, const Standard_Real Scalar)
	{
		Entity2d_Metric1 M = Metric;
		M *= Scalar;
		return std::move(M);
	}

	inline Entity2d_Metric1 operator*(const Standard_Real Scalar, const Entity2d_Metric1 & Metric)
	{
		Entity2d_Metric1 M = Metric;
		M *= Scalar;
		return std::move(M);
	}

	inline Entity2d_Metric1 operator+(const Entity2d_Metric1 & theMetric1, const Entity2d_Metric1 & theMetric2)
	{
		return Entity2d_Metric1(theMetric1.A() + theMetric2.A(), theMetric1.B() + theMetric2.B(), theMetric1.C() + theMetric2.C());
	}
}