#pragma once
#ifndef _FrgBase_FieldTools_Header
#define _FrgBase_FieldTools_Header

#include <FrgBase_Object.hxx>

BeginForgBaseLib

class FrgBase_Field_Entity;
class FrgBase_SymbolTableRegistry;

class FORGBASE_EXPORT FrgBase_FieldTools
	: public FrgBase_Object
{

public:

	enum class Decorator
	{
		Dollar,		// $
		HashTag,	// #
		Percent,	// %
		AtSign,		// @
		Ampersand	// &
	};

	enum class Bracket
	{
		Round,		// ()
		Square,		// []
		Curly,		// {}
		Angle		// <>
	};

	static Decorator theDecorator_;
	static Bracket theBracket_;

	static std::string GetDecoratorAsString();
	static std::string GetDecoratorAsString(Decorator dec);
	static void SetDecorator(Decorator dec);

	static std::pair<std::string, std::string> GetBracketAsString();
	static std::pair<std::string, std::string> GetBracketAsString(Bracket bracket);
	static void SetBracket(Bracket bracket);

	// Methods

	static std::string AddDecoratorAndBracket(FrgBase_Field_Entity* field);
	//static std::string RemoveDecoratorAndBracket(FrgBase_Field_Entity* field);

	static size_t GetNumberOfAdditionalString();

	static std::string DecorizeExpression
	(
		FrgBase_Field_Entity* field
	);

	static std::string UnDecorizeExpression
	(
		const std::string& decorizedExpression,
		FrgBase_SymbolTableRegistry* registry
	);
};

EndForgBaseLib

#endif // !_FrgBase_FieldTools_Header