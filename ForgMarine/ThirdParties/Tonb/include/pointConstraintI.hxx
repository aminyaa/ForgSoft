#pragma once
// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

inline tnbLib::pointConstraint::pointConstraint()
	:
	Tuple2<label, vector>(0, vector::zero)
{}


inline tnbLib::pointConstraint::pointConstraint(Istream& is)
	:
	Tuple2<label, vector>(is)
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

void tnbLib::pointConstraint::applyConstraint(const vector& cd)
{
	if (first() == 0)
	{
		first() = 1;
		second() = cd;
	}
	else if (first() == 1)
	{
		vector planeNormal = cd ^ second();
		scalar magPlaneNormal = mag(planeNormal);

		if (magPlaneNormal > 1e-3)
		{
			first() = 2;
			second() = planeNormal / magPlaneNormal;
		}
	}
	else if (first() == 2)
	{
		if (mag(cd & second()) > 1e-3)
		{
			first() = 3;
			second() = vector::zero;
		}
	}
}


tnbLib::tensor tnbLib::pointConstraint::constraintTransformation() const
{
	if (first() == 0)
	{
		return I;
	}
	else if (first() == 1)
	{
		return I - sqr(second());
	}
	else if (first() == 2)
	{
		return sqr(second());
	}
	else
	{
		return tensor::zero;
	}
}


// ************************************************************************* //