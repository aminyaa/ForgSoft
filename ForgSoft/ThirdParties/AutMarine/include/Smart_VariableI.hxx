#pragma once
#include <token.hxx>
#include <dictionary.hxx>
template<class Type, class UnitTypeExp>
AutLib::Smart_Variable<Type, UnitTypeExp> AutLib::Smart_Variable<Type, UnitTypeExp>::lookupOrDefault
(
	const word & name,
	const dictionary & dict,
	const unit theUnit,
	const Type & defaultValue
)
{
	Type value = dict.lookupOrDefault<Type>(name, defaultValue);
	return Smart_Variable<Type, UnitTypeExp>(name, value, theUnit);
}

template<class Type, class UnitTypeExp>
AutLib::Smart_Variable<Type, UnitTypeExp> AutLib::Smart_Variable<Type, UnitTypeExp>::lookupOrAddToDict
(
	const word & name,
	dictionary & dict,
	const unit theUnit,
	const Type & defaultValue
)
{
	Type value = dict.lookupOrAddDefault<Type>(name, defaultValue);
	return Smart_Variable<Type, UnitTypeExp>(name, value, theUnit);
}

template<class Type>
AutLib::Smart_Variable<Type, AutLib::NullUnitExps> AutLib::Smart_Variable<Type, AutLib::NullUnitExps>::lookupOrDefault
(
	const word & name,
	const dictionary & dict,
	const Type & defaultValue
)
{
	Type value = dict.lookupOrDefault<Type>(name, defaultValue);
	return Smart_Variable<Type, NullUnitExps>(name, value);
}

template<class Type>
AutLib::Smart_Variable<Type, AutLib::NullUnitExps> AutLib::Smart_Variable<Type, AutLib::NullUnitExps>::lookupOrAddToDict
(
	const word & name,
	dictionary & dict,
	const Type & defaultValue
)
{
	Type value = dict.lookupOrAddDefault<Type>(name, defaultValue);
	return Smart_Variable<Type, NullUnitExps>(name, value);
}

namespace AutLib
{

	template<class Type, class UnitTypeExp>
	Istream & operator>>(Istream & is, Smart_Variable<Type, UnitTypeExp>& sv)
	{
		// do a stream read op for a Type
		is >> sv.Name() >> sv.Value();

		// Check state of Istream
		is.check("Istream & operator>>(Istream & is, Smart_Variable<Type, UnitTypeExp>& sv)");

		return is;
	}

	template<class Type, class UnitTypeExp>
	Ostream & operator<<(Ostream & os, const Smart_Variable<Type, UnitTypeExp>& sv)
	{
		// do a stream write op
		os << sv.Name() << token::SPACE
			<< sv.Value() << token::SPACE
			<< toString(sv.Unit());

		// Check state of Ostream
		os.check("Ostream & operator<<(Ostream & os, const Smart_Variable<Type, UnitTypeExp>& sv)");

		return os;
	}

	template<class Type>
	Istream & operator>>(Istream & is, Smart_Variable<Type, NullUnitExps>& sv)
	{
		// do a stream read op for a Type
		is >> sv.Name() >> sv.Value();

		// Check state of Istream
		is.check("Istream & operator>>(Istream & is, Smart_Variable<Type, NullUnitExps>& sv)");

		return is;
	}

	template<class Type>
	Ostream & operator<<(Ostream & os, const Smart_Variable<Type, NullUnitExps>& sv)
	{
		// do a stream write op
		os << sv.Name() << token::SPACE
			<< sv.Value();

		// Check state of Ostream
		os.check("Ostream & operator<<(Ostream & os, const Smart_Variable<Type, NullUnitExps>& sv)");

		return os;
	}
}