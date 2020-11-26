#pragma once
#include <tnbVersion.hxx>

// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

template<class Stream>
inline Stream& tnbLib::IOobject::writeBanner(Stream& os, bool noHint, bool noCopyright)
{
	static bool spacesSet = false;
	static char spaces[37];

	if (!spacesSet)
	{
		memset(spaces, ' ', 37);

		size_t len = strlen(tnbLib::TONBversion);
		if (len < 35)
		{
			spaces[35 - len] = '\0';
		}
		else
		{
			spaces[0] = '\0';
		}
		spacesSet = true;
	}

	/*if (noHint)
	{
		os <<
			"/*---------------------------------------------------------------------------*\\\n";
	}
	else
	{
		os <<
			"/*--------------------------------*- C++ -*----------------------------------*\\\n";
	}

	os <<
		"| =========                 |                                                 |\n"
		"| \\\\      /  F ield         | foam-extend: Open Source CFD                    |\n"
		"|  \\\\    /   O peration     | Version:     " << TONBversion << spaces << "|\n"
		"|   \\\\  /    A nd           | Web:         http://www.foam-extend.org         |\n";

	if (noCopyright)
	{
		os <<
			"|    \\\\/     M anipulation  |                                                 |\n";
	}
	else
	{
		os <<
			"|    \\\\/     M anipulation  | For copyright notice see file Copyright         |\n";
	}

	os <<*/
		//"\\*---------------------------------------------------------------------------*/\n";

	return os;
}


template<class Stream>
inline Stream& tnbLib::IOobject::writeDivider(Stream& os)
{
	os <<
		"// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //\n";

	return os;
}

template<class Stream>
inline Stream& tnbLib::IOobject::writeEndDivider(Stream& os)
{
	os << "\n\n"
		"// ************************************************************************* //\n";

	return os;
}


// ************************************************************************* //
