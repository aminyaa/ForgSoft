#pragma once
#include <IStringStream.hxx>
#include <OStringStream.hxx>
#include <dictionary.hxx>
template<class T>
AutLib::primitiveEntry::primitiveEntry(const keyType& keyword, const T& t)
	: entry(keyword)
	, ITstream(keyword, tokenList(10))
{
	OStringStream os;
	os << t << token::END_STATEMENT;
	readEntry(dictionary::null, IStringStream(os.str())());
}
