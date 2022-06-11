#include <FrgBase_FieldTools.hxx>
#include <FrgBase_Field_Entity.hxx>

#define DECORATOR_DOLLAR_STR "$"
#define DECORATOR_HASHTAG_STR "#"
#define DECORATOR_PERCENT_STR "%"
#define DECORATOR_ATSIGN_STR "@"
#define DECORATOR_AMPERSAND_STR "&"
#define DECORATOR_NONE_STR ""

#define BRACKET_ROUND_BEGIN_STR "("
#define BRACKET_ROUND_END_STR "("
#define BRACKET_SQUARE_BEGIN_STR "["
#define BRACKET_SQUARE_END_STR "["
#define BRACKET_CURLY_BEGIN_STR "{"
#define BRACKET_CURLY_END_STR "}"
#define BRACKET_ANGLE_BEGIN_STR "<"
#define BRACKET_ANGLE_END_STR ">"
#define BRACKET_NONE_BEGIN_STR ""
#define BRACKET_NONE_END_STR ""

static std::string ReplaceAllInString(const std::string& str, const std::string& from, const std::string& to)
{
	if (from.empty())
		return "";

	std::string result = str;
	size_t start_pos = 0;

	while ((start_pos = str.find(from, start_pos)) != std::string::npos)
	{
		result.replace(start_pos, from.length(), to);
		start_pos += to.length();
	}
}

ForgBaseLib::FrgBase_FieldTools::Decorator ForgBaseLib::FrgBase_FieldTools::theDecorator_ = ForgBaseLib::FrgBase_FieldTools::Decorator::Dollar;

ForgBaseLib::FrgBase_FieldTools::Bracket ForgBaseLib::FrgBase_FieldTools::theBracket_ = ForgBaseLib::FrgBase_FieldTools::Bracket::Curly;

std::string ForgBaseLib::FrgBase_FieldTools::GetDecoratorAsString()
{
	return GetDecoratorAsString(theDecorator_);
}

std::string ForgBaseLib::FrgBase_FieldTools::GetDecoratorAsString(Decorator dec)
{
	if (dec == Decorator::Dollar)
		return DECORATOR_DOLLAR_STR;
	if (dec == Decorator::HashTag)
		return DECORATOR_HASHTAG_STR;
	if (dec == Decorator::Percent)
		return DECORATOR_PERCENT_STR;
	if (dec == Decorator::AtSign)
		return DECORATOR_ATSIGN_STR;
	if (dec == Decorator::Ampersand)
		return DECORATOR_AMPERSAND_STR;
	if (dec == Decorator::None)
		return DECORATOR_NONE_STR;

	return DECORATOR_DOLLAR_STR;
}

void ForgBaseLib::FrgBase_FieldTools::SetDecorator(Decorator dec)
{
	theDecorator_ = dec;
}

std::pair<std::string, std::string> ForgBaseLib::FrgBase_FieldTools::GetBracketAsString()
{
	return GetBracketAsString(theBracket_);
}

std::pair<std::string, std::string> ForgBaseLib::FrgBase_FieldTools::GetBracketAsString(Bracket bracket)
{
	std::string begin;
	std::string end;

	if (bracket == Bracket::Round)
	{
		begin = BRACKET_ROUND_BEGIN_STR;
		end = BRACKET_ROUND_END_STR;
	}
	else if (bracket == Bracket::Square)
	{
		begin = BRACKET_SQUARE_BEGIN_STR;
		end = BRACKET_SQUARE_END_STR;
	}
	else if (bracket == Bracket::Curly)
	{
		begin = BRACKET_CURLY_BEGIN_STR;
		end = BRACKET_CURLY_END_STR;
	}
	else if (bracket == Bracket::Angle)
	{
		begin = BRACKET_ANGLE_BEGIN_STR;
		end = BRACKET_ANGLE_END_STR;
	}
	else if (bracket == Bracket::None)
	{
		begin = BRACKET_NONE_BEGIN_STR;
		end = BRACKET_NONE_END_STR;
	}
	else
	{
		begin = BRACKET_CURLY_BEGIN_STR;
		end = BRACKET_CURLY_END_STR;
	}

	return std::make_pair(begin, end);
}

void ForgBaseLib::FrgBase_FieldTools::SetBracket(Bracket bracket)
{
	theBracket_ = bracket;
}

std::string ForgBaseLib::FrgBase_FieldTools::AddDecoratorAndBracket(FrgBase_Field_Entity* field)
{
	if (!field)
		return "";

	auto decorator = GetDecoratorAsString();
	auto bracket = GetBracketAsString();

	return (decorator + bracket.first + field->GetPresentationName() + bracket.second);
}

std::string ForgBaseLib::FrgBase_FieldTools::RemoveDecoratorAndBracket(FrgBase_Field_Entity* field)
{
	if (!field)
		return "";

	auto decorator = GetDecoratorAsString();
	auto bracket = GetBracketAsString();

	auto expr = ReplaceAllInString(field->GetPresentationName(), " ", "");

	if (expr.size() <= GetNumberOfAdditionalString())
		return "";

	std::string result;
	for (int i = 2; i < expr.size() - 1; i++)
		result.push_back(expr[i]);

	return result;
}

size_t ForgBaseLib::FrgBase_FieldTools::GetNumberOfAdditionalString()
{
	auto decorator = GetDecoratorAsString();
	auto bracket = GetBracketAsString();

	return decorator.size() + bracket.first.size() + bracket.second.size();
}