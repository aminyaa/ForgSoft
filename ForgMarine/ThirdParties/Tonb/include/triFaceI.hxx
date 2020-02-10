#pragma once
#include <IOstreams.hxx>
#include <face.hxx>
#include <triPointRef.hxx>

// * * * * * * * * * * * * * Static Member Functions * * * * * * * * * * * * //

inline int tnbLib::triFace::compare(const triFace& a, const triFace& b)
{
	if
		(
		(a[0] == b[0] && a[1] == b[1] && a[2] == b[2])
			|| (a[0] == b[1] && a[1] == b[2] && a[2] == b[0])
			|| (a[0] == b[2] && a[1] == b[0] && a[2] == b[1])
			)
	{
		// identical
		return 1;
	}
	else if
		(
		(a[0] == b[2] && a[1] == b[1] && a[2] == b[0])
			|| (a[0] == b[1] && a[1] == b[0] && a[2] == b[2])
			|| (a[0] == b[0] && a[1] == b[2] && a[2] == b[1])
			)
	{
		// same face, but reversed orientation
		return -1;
	}
	else
	{
		return 0;
	}
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

inline tnbLib::triFace::triFace()
{}


inline tnbLib::triFace::triFace
(
	const label a,
	const label b,
	const label c
)
{
	operator[](0) = a;
	operator[](1) = b;
	operator[](2) = c;
}


inline tnbLib::triFace::triFace(const UList<label>& lst)
	:
	FixedList<label, 3>(lst)
{}


inline tnbLib::triFace::triFace(Istream& is)
	:
	FixedList<label, 3>(is)
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

inline tnbLib::label tnbLib::triFace::collapse()
{
	// we cannot resize a FixedList, so mark duplicates with '-1'
	// (the lower vertex is retained)
	// catch any '-1' (eg, if called twice)

	label n = 3;
	if (operator[](0) == operator[](1) || operator[](1) == -1)
	{
		operator[](1) = -1;
		n--;
	}
	else if (operator[](1) == operator[](2) || operator[](2) == -1)
	{
		operator[](2) = -1;
		n--;
	}
	if (operator[](0) == operator[](2))
	{
		operator[](2) = -1;
		n--;
	}

	return n;
}


inline tnbLib::pointField tnbLib::triFace::points(const pointField& points) const
{
	pointField p(3);

	p[0] = points[operator[](0)];
	p[1] = points[operator[](1)];
	p[2] = points[operator[](2)];

	return p;
}


inline tnbLib::face tnbLib::triFace::triFaceFace() const
{
	face f(3);

	f[0] = operator[](0);
	f[1] = operator[](1);
	f[2] = operator[](2);

	return f;
}


inline tnbLib::label tnbLib::triFace::nEdges() const
{
	return 3;
}


inline tnbLib::edgeList tnbLib::triFace::edges() const
{
	edgeList e(3);

	e[0].start() = operator[](0);
	e[0].end() = operator[](1);

	e[1].start() = operator[](1);
	e[1].end() = operator[](2);

	e[2].start() = operator[](2);
	e[2].end() = operator[](0);

	return e;
}


// return
//  - +1: forward (counter-clockwise) on the face
//  - -1: reverse (clockwise) on the face
//  -  0: edge not found on the face
inline int tnbLib::triFace::edgeDirection(const edge& e) const
{
	if
		(
		(operator[](0) == e.start() && operator[](1) == e.end())
			|| (operator[](1) == e.start() && operator[](2) == e.end())
			|| (operator[](2) == e.start() && operator[](0) == e.end())
			)
	{
		return 1;
	}
	else if
		(
		(operator[](0) == e.end() && operator[](1) == e.start())
			|| (operator[](1) == e.end() && operator[](2) == e.start())
			|| (operator[](2) == e.end() && operator[](0) == e.start())
			)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}


inline tnbLib::point tnbLib::triFace::centre(const pointField& points) const
{
	return (1.0 / 3.0)*
		(
			points[operator[](0)]
			+ points[operator[](1)]
			+ points[operator[](2)]
			);
}


inline tnbLib::scalar tnbLib::triFace::mag(const pointField& points) const
{
	return ::tnbLib::mag(normal(points));
}

// could also delegate to triPointRef(...).normal()
inline tnbLib::vector tnbLib::triFace::normal(const pointField& points) const
{
	return 0.5*
		(
		(points[operator[](1)] - points[operator[](0)])
			^ (points[operator[](2)] - points[operator[](0)])
			);
}


inline tnbLib::label tnbLib::triFace::nTriangles() const
{
	return 1;
}


inline tnbLib::triFace tnbLib::triFace::reverseFace() const
{
	// The starting points of the original and reverse face are identical.
	return triFace(operator[](0), operator[](2), operator[](1));
}


inline tnbLib::scalar tnbLib::triFace::sweptVol
(
	const pointField& opts,
	const pointField& npts
) const
{
	return (1.0 / 6.0)*
		(
		(
			(npts[operator[](0)] - opts[operator[](0)])
			& (
			(opts[operator[](1)] - opts[operator[](0)])
				^ (opts[operator[](2)] - opts[operator[](0)])
				)
			)
			+ (
			(npts[operator[](1)] - opts[operator[](1)])
				& (
				(opts[operator[](2)] - opts[operator[](1)])
					^ (npts[operator[](0)] - opts[operator[](1)])
					)
				)
			+ (
			(opts[operator[](2)] - npts[operator[](2)])
				& (
				(npts[operator[](1)] - npts[operator[](2)])
					^ (npts[operator[](0)] - npts[operator[](2)])
					)
				)
			);
}


inline tnbLib::pointHit tnbLib::triFace::ray
(
	const point& p,
	const vector& q,
	const pointField& points,
	const intersection::algorithm alg,
	const intersection::direction dir
) const
{
	return triPointRef
	(
		points[operator[](0)],
		points[operator[](1)],
		points[operator[](2)]
	).ray(p, q, alg, dir);
}


inline tnbLib::scalar tnbLib::triFace::contactSphereDiameter
(
	const point& p,
	const vector& n,
	const pointField& meshPoints
) const
{
	vector n1 = n / (tnbLib::mag(n) + SMALL);
	vector n2 = normal(meshPoints);

	n2 /= tnbLib::mag(n2) + SMALL;

	return 2 * ((centre(meshPoints) - p) & n2) / ((n1 & n2) - 1.0);
}


inline tnbLib::triPointRef tnbLib::triFace::tri(const pointField& points) const
{
	return triPointRef
	(
		points[operator[](0)],
		points[operator[](1)],
		points[operator[](2)]
	);
}


// * * * * * * * * * * * * * * * Friend Operators  * * * * * * * * * * * * * //

inline bool tnbLib::operator==(const triFace& a, const triFace& b)
{
	return triFace::compare(a, b) != 0;
}


inline bool tnbLib::operator!=(const triFace& a, const triFace& b)
{
	return triFace::compare(a, b) == 0;
}


// ************************************************************************* //