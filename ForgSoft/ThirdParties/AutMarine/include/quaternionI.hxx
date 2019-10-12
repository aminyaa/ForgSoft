#pragma once
inline 
AutLib::quaternion::quaternion()
{}

inline 
AutLib::quaternion::quaternion(const scalar w, const vector& v)
	: w_(w)
	, v_(v)
{}

inline 
AutLib::quaternion::quaternion(const vector& d, const scalar theta)
	: w_(cos(0.5*theta))
	, v_((sin(0.5*theta) / magSqr(d))*d)
{
	normalize();
}

inline 
AutLib::quaternion::quaternion(const scalar w)
	: w_(w)
	, v_(vector::zero)
{}

inline 
AutLib::quaternion::quaternion(const vector& v)
	: w_(0)
	, v_(v)
{}

inline 
AutLib::quaternion::quaternion
(
	const scalar angleX,
	const scalar angleY,
	const scalar angleZ
)
{
	operator=(quaternion(vector(1, 0, 0), angleX));
	operator*=(quaternion(vector(0, 1, 0), angleY));
	operator*=(quaternion(vector(0, 0, 1), angleZ));
}

inline 
AutLib::scalar AutLib::quaternion::w() const
{
	return w_;
}


inline 
const AutLib::vector& AutLib::quaternion::v() const
{
	return v_;
}


inline 
AutLib::scalar& AutLib::quaternion::w()
{
	return w_;
}


inline 
AutLib::vector& AutLib::quaternion::v()
{
	return v_;
}


inline 
void AutLib::quaternion::normalize()
{
	operator/=(mag(*this));
}


inline 
AutLib::quaternion AutLib::quaternion::mulq0v(const vector& u) const
{
	return quaternion(-(v() & u), w()*u + (v() ^ u));
}


inline 
AutLib::vector AutLib::quaternion::transform(const vector& u) const
{
	return (mulq0v(u)*conjugate(*this)).v();
}


inline 
AutLib::vector AutLib::quaternion::invTransform(const vector& u) const
{
	return (conjugate(*this).mulq0v(u)*(*this)).v();
}


inline 
AutLib::quaternion AutLib::quaternion::transform(const quaternion& q) const
{
	return AutLib::normalize((*this)*q);
}


inline 
AutLib::quaternion AutLib::quaternion::invTransform
(
	const quaternion& q
) const
{
	return AutLib::normalize(conjugate(*this)*q);
}

inline 
void AutLib::quaternion::operator=(const quaternion& q)
{
	w_ = q.w_;
	v_ = q.v_;
}

inline 
void AutLib::quaternion::operator+=(const quaternion& q)
{
	w_ += q.w_;
	v_ += q.v_;
}

inline 
void AutLib::quaternion::operator-=(const quaternion& q)
{
	w_ -= q.w_;
	v_ -= q.v_;
}

inline 
void AutLib::quaternion::operator*=(const quaternion& q)
{
	scalar w0 = w();
	w() = w()*q.w() - (v() & q.v());
	v() = w0 * q.v() + q.w()*v() + (v() ^ q.v());
}

inline
void AutLib::quaternion::operator/=(const quaternion& q)
{
	return operator*=(inv(q));
}


inline 
void AutLib::quaternion::operator=(const scalar s)
{
	w_ = s;
}


inline
void AutLib::quaternion::operator=(const vector& v)
{
	v_ = v;
}


inline 
void AutLib::quaternion::operator*=(const scalar s)
{
	w_ *= s;
	v_ *= s;
}

inline 
void AutLib::quaternion::operator/=(const scalar s)
{
	w_ /= s;
	v_ /= s;
}

inline
AutLib::scalar AutLib::magSqr(const quaternion& q)
{
	return magSqr(q.w()) + magSqr(q.v());
}


inline
AutLib::scalar AutLib::mag(const quaternion& q)
{
	return sqrt(magSqr(q));
}


inline 
AutLib::quaternion AutLib::conjugate(const quaternion& q)
{
	return quaternion(q.w(), -q.v());
}


inline 
AutLib::quaternion AutLib::inv(const quaternion& q)
{
	scalar magSqrq = magSqr(q);
	return quaternion(q.w() / magSqrq, -q.v() / magSqrq);
}


inline
AutLib::quaternion AutLib::normalize(const quaternion& q)
{
	return q / mag(q);
}


inline 
AutLib::tensor AutLib::quaternion::R() const
{
	scalar w2 = sqr(w());
	scalar x2 = sqr(v().x());
	scalar y2 = sqr(v().y());
	scalar z2 = sqr(v().z());

	scalar txy = 2 * v().x()*v().y();
	scalar twz = 2 * w()*v().z();
	scalar txz = 2 * v().x()*v().z();
	scalar twy = 2 * w()*v().y();
	scalar tyz = 2 * v().y()*v().z();
	scalar twx = 2 * w()*v().x();

	return tensor
	(
		w2 + x2 - y2 - z2, txy - twz, txz + twy,
		txy + twz, w2 - x2 + y2 - z2, tyz - twx,
		txz - twy, tyz + twx, w2 - x2 - y2 + z2
	);
}

inline bool AutLib::operator==(const quaternion& q1, const quaternion& q2)
{
	return (equal(q1.w(), q2.w()) && equal(q1.v(), q2.v()));
}


inline bool AutLib::operator!=(const quaternion& q1, const quaternion& q2)
{
	return !operator==(q1, q2);
}


inline AutLib::quaternion AutLib::operator+
(
	const quaternion& q1,
	const quaternion& q2
	)
{
	return quaternion(q1.w() + q2.w(), q1.v() + q2.v());
}


inline AutLib::quaternion AutLib::operator-(const quaternion& q)
{
	return quaternion(-q.w(), -q.v());
}


inline AutLib::quaternion AutLib::operator-
(
	const quaternion& q1,
	const quaternion& q2
	)
{
	return quaternion(q1.w() - q2.w(), q1.v() - q2.v());
}


inline AutLib::scalar AutLib::operator&(const quaternion& q1, const quaternion& q2)
{
	return q1.w()*q2.w() + (q1.v() & q2.v());
}


inline AutLib::quaternion AutLib::operator*
(
	const quaternion& q1,
	const quaternion& q2
	)
{
	return quaternion
	(
		q1.w()*q2.w() - (q1.v() & q2.v()),
		q1.w()*q2.v() + q2.w()*q1.v() + (q1.v() ^ q2.v())
	);
}


inline AutLib::quaternion AutLib::operator/
(
	const quaternion& q1,
	const quaternion& q2
	)
{
	return q1 * inv(q2);
}


inline AutLib::quaternion AutLib::operator*(const scalar s, const quaternion& q)
{
	return quaternion(s*q.w(), s*q.v());
}


inline AutLib::quaternion AutLib::operator*(const quaternion& q, const scalar s)
{
	return quaternion(s*q.w(), s*q.v());
}


inline AutLib::quaternion AutLib::operator/(const quaternion& q, const scalar s)
{
	return quaternion(q.w() / s, q.v() / s);
}