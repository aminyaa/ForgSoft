#pragma once
#include <stringList.hxx>

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

template<class Enum, int nEnum>
tnbLib::NamedEnum<Enum, nEnum>::NamedEnum()
	: HashTable<int>(2 * nEnum)
{
	for (int i = 0; i < nEnum; i++)
	{
		if (!names[i] || names[i][0] == '\0')
		{
			stringList goodNames(i);

			for (label j = 0; j < i; j++)
			{
				goodNames[j] = names[j];
			}

			FatalErrorIn("NamedEnum<Enum, nEnum>::NamedEnum()")
				<< "Illegal enumeration name at position " << i << endl
				<< "after entries " << goodNames << ".\n"
				<< "Possibly your NamedEnum<Enum, nEnum>::names array"
				<< " is not of size " << nEnum << endl
				<< abort(FatalError);
		}
		insert(names[i], i);
	}
}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

template<class Enum, int nEnum>
Enum tnbLib::NamedEnum<Enum, nEnum>::read(Istream& is) const
{
	word name(is);

	HashTable<int>::const_iterator iter = find(name);

	if (iter == HashTable<int>::end())
	{
		FatalIOErrorIn
		(
			"NamedEnum<Enum, nEnum>::read(Istream& is) const",
			is
		) << name << " is not in enumeration " << toc()
			<< exit(FatalIOError);
	}

	return Enum(iter());
}


template<class Enum, int nEnum>
void tnbLib::NamedEnum<Enum, nEnum>::write(const Enum e, Ostream& os) const
{
	os << operator[](e);
}


// * * * * * * * * * * * * * * * Ostream Operator  * * * * * * * * * * * * * //

template<class Enum, int nEnum>
tnbLib::Ostream& tnbLib::operator<<
(
	Ostream& os,
	const NamedEnum<Enum, nEnum>& n
	)
{
	for (int e = 0; e < nEnum; e++)
	{
		os << e << " " << n.names[e] << nl;
	}

	return os;
}


// ************************************************************************* //