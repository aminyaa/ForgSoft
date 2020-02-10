#pragma once
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

inline tnbLib::scalar tnbLib::geometricOneField::operator[](const label) const
{
	return scalar(1);
}

inline tnbLib::oneField tnbLib::geometricOneField::field() const
{
	return oneField();
}

inline tnbLib::oneField tnbLib::geometricOneField::oldTime() const
{
	return oneField();
}

inline tnbLib::oneFieldField tnbLib::geometricOneField::boundaryField() const
{
	return oneFieldField();
}


// ************************************************************************* //