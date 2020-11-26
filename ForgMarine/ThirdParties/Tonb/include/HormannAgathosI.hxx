#pragma once
// * * * * * * * * * * * * * Private Member Functions  * * * * * * * * * * * //

// Implements a == b within a tolerance define by epsilon_.
// Need to work if epsilon_ == 0.0
inline bool tnbLib::HormannAgathos::equalWithTol
(
	const scalar& a,
	const scalar& b
) const
{
	return (a <= b + epsilon_) && (a >= b - epsilon_);
}


// Implements a > b within a tolerance define by epsilon_.
// Need to work if epsilon_ == 0.0
inline bool tnbLib::HormannAgathos::greaterWithTol
(
	const scalar& a,
	const scalar& b
) const
{
	return a > (b + epsilon_);
}


// Implements a < b within a tolerance define by epsilon_.
// Need to work if epsilon_ == 0.0
inline bool tnbLib::HormannAgathos::smallerWithTol
(
	const scalar& a,
	const scalar& b
) const
{
	return a < (b - epsilon_);
}


// Implements a >= b within a tolerance define by epsilon_.
// Need to work if epsilon_ == 0.0
inline bool tnbLib::HormannAgathos::greaterOrEqualWithTol
(
	const scalar& a,
	const scalar& b
) const
{
	return a >= (b - epsilon_);
}


// Implements a =< b within a tolerance define by epsilon_.
// Need to work if epsilon_ == 0.0
inline bool tnbLib::HormannAgathos::smallerOrEqualWithTol
(
	const scalar& a,
	const scalar& b
) const
{
	return a <= (b + epsilon_);
}


// ************************************************************************* //