#pragma once
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

inline tnbLib::scalar tnbLib::zeroField::operator[](const label) const
{
	return scalar(0);
}

inline tnbLib::zeroField tnbLib::zeroField::field() const
{
	return zeroField();
}

inline tnbLib::zeroField tnbLib::zeroField::oldTime() const
{
	return zeroField();
}

// ************************************************************************* //