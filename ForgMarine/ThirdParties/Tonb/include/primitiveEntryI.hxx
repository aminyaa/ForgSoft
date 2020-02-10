#pragma once
#include <dictionary.hxx>
#include <BiIndirectList.hxx>
#include <UIndirectList.hxx>
#include <IndirectList.hxx>
#include <SLList.hxx>
#include <PtrList.hxx>

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

template<class T>
tnbLib::primitiveEntry::primitiveEntry(const keyType& keyword, const T& t)
	:
	entry(keyword),
	ITstream(keyword, tokenList(10))
{
	OStringStream os;
	os << t << token::END_STATEMENT;
	readEntry(dictionary::null, IStringStream(os.str())());
}


// ************************************************************************* //