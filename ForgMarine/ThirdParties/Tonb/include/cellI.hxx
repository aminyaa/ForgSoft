#pragma once
// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

// Construct null
inline tnbLib::cell::cell()
{}


// Construct given size
inline tnbLib::cell::cell(label s)
	:
	labelList(s, -1)
{}


// Construct from components
inline tnbLib::cell::cell(const UList<label>& lst)
	:
	labelList(lst)
{}


inline tnbLib::cell::cell(const Xfer<labelList>& lst)
	:
	labelList(lst)
{}


// Construct from Istream
inline tnbLib::cell::cell(Istream& is)
	:
	labelList(is)
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

// Number of faces
inline tnbLib::label tnbLib::cell::nFaces() const
{
	return size();
}


inline bool tnbLib::operator!=(const cell& a, const cell& b)
{
	return (!(a == b));
}

// ************************************************************************* //