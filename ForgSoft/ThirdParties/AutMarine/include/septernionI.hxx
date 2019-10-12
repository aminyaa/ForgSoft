#pragma once
inline AutLib::septernion::septernion()
{}

inline AutLib::septernion::septernion(const vector& t, const quaternion& r)
	: t_(t)
	, r_(r)
{}

inline AutLib::septernion::septernion(const vector& t)
	: t_(t)
	, r_(quaternion::I)
{}

inline AutLib::septernion::septernion(const quaternion& r)
	: t_(vector::zero)
	, r_(r)
{}

inline const AutLib::vector& AutLib::septernion::t() const
{
	return t_;
}


inline const AutLib::quaternion& AutLib::septernion::r() const
{
	return r_;
}


inline AutLib::vector& AutLib::septernion::t()
{
	return t_;
}


inline AutLib::quaternion& AutLib::septernion::r()
{
	return r_;
}


inline AutLib::vector AutLib::septernion::transform(const vector& v) const
{
	return t() + r().transform(v);
}


inline AutLib::vector AutLib::septernion::invTransform(const vector& v) const
{
	return r().invTransform(v - t());
}

inline void AutLib::septernion::operator=(const septernion& tr)
{
	t_ = tr.t_;
	r_ = tr.r_;
}

inline void AutLib::septernion::operator*=(const septernion& tr)
{
	t_ += r().transform(tr.t());
	r_ *= tr.r();
}


inline void AutLib::septernion::operator=(const vector& t)
{
	t_ = t;
}

inline void AutLib::septernion::operator+=(const vector& t)
{
	t_ += t;
}

inline void AutLib::septernion::operator-=(const vector& t)
{
	t_ -= t;
}


inline void AutLib::septernion::operator=(const quaternion& r)
{
	r_ = r;
}

inline void AutLib::septernion::operator*=(const quaternion& r)
{
	r_ *= r;
}

inline void AutLib::septernion::operator/=(const quaternion& r)
{
	r_ /= r;
}


inline void AutLib::septernion::operator*=(const scalar s)
{
	t_ *= s;
	r_ *= s;
}

inline void AutLib::septernion::operator/=(const scalar s)
{
	t_ /= s;
	r_ /= s;
}

inline AutLib::septernion AutLib::inv(const septernion& tr)
{
	return septernion(-tr.r().invTransform(tr.t()), conjugate(tr.r()));
}

inline bool AutLib::operator==(const septernion& tr1, const septernion& tr2)
{
	return (tr1.t() == tr2.t() && tr1.r() == tr2.r());
}


inline bool AutLib::operator!=(const septernion& tr1, const septernion& tr2)
{
	return !operator==(tr1, tr2);
}


inline AutLib::septernion AutLib::operator+
(
	const septernion& tr,
	const vector& t
	)
{
	return septernion(tr.t() + t, tr.r());
}


inline AutLib::septernion AutLib::operator+
(
	const vector& t,
	const septernion& tr
	)
{
	return septernion(t + tr.t(), tr.r());
}


inline AutLib::septernion AutLib::operator+
(
	const septernion& tr1,
	const septernion& tr2
	)
{
	return septernion(tr1.t() + tr2.t(), tr1.r() + tr2.r());
}


inline AutLib::septernion AutLib::operator-
(
	const septernion& tr,
	const vector& t
	)
{
	return septernion(tr.t() - t, tr.r());
}


inline AutLib::septernion AutLib::operator-
(
	const septernion& tr1,
	const septernion& tr2
	)
{
	return septernion(tr1.t() - tr2.t(), tr1.r() - tr2.r());
}


inline AutLib::septernion AutLib::operator*
(
	const quaternion& r,
	const septernion& tr
	)
{
	return septernion(tr.t(), r*tr.r());
}


inline AutLib::septernion AutLib::operator*
(
	const septernion& tr,
	const quaternion& r
	)
{
	return septernion(tr.t(), tr.r()*r);
}


inline AutLib::septernion AutLib::operator/
(
	const septernion& tr,
	const quaternion& r
	)
{
	return septernion(tr.t(), tr.r() / r);
}


inline AutLib::septernion AutLib::operator*
(
	const septernion& tr1,
	const septernion& tr2
	)
{
	return septernion
	(
		tr1.t() + tr1.r().transform(tr2.t()),
		tr1.r().transform(tr2.r())
	);
}


inline AutLib::septernion AutLib::operator/
(
	const septernion& tr1,
	const septernion& tr2
	)
{
	return tr1 * inv(tr2);
}


inline AutLib::septernion AutLib::operator*(const scalar s, const septernion& tr)
{
	return septernion(s*tr.t(), s*tr.r());
}


inline AutLib::septernion AutLib::operator*(const septernion& tr, const scalar s)
{
	return septernion(s*tr.t(), s*tr.r());
}


inline AutLib::septernion AutLib::operator/(const septernion& tr, const scalar s)
{
	return septernion(tr.t() / s, tr.r() / s);
}