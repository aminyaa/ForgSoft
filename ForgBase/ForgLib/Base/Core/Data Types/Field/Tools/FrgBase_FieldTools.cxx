#include <FrgBase_FieldTools.hxx>
#include <FrgBase_Field_Entity.hxx>
#include <FrgBase_SymbolTable.hxx>
#include <FrgBase_SymbolTableRegistry.hxx>

#include <exprtk.hpp>

#define DECORATOR_DOLLAR_STR "$"
#define DECORATOR_HASHTAG_STR "#"
#define DECORATOR_PERCENT_STR "%"
#define DECORATOR_ATSIGN_STR "@"
#define DECORATOR_AMPERSAND_STR "&"

#define BRACKET_ROUND_BEGIN_STR "("
#define BRACKET_ROUND_END_STR "("
#define BRACKET_SQUARE_BEGIN_STR "["
#define BRACKET_SQUARE_END_STR "["
#define BRACKET_CURLY_BEGIN_STR "{"
#define BRACKET_CURLY_END_STR "}"
#define BRACKET_ANGLE_BEGIN_STR "<"
#define BRACKET_ANGLE_END_STR ">"

static std::string ReplaceInString
(
	const std::string& str,
	const size_t start_pos,
	const size_t length,
	const std::string& to
)
{
	std::string result = str;

	if (start_pos < 0)
		throw std::exception("end_pos is smaller than 0 in " __FUNCSIG__);

	if (length > result.size())
		throw std::exception("length is larger than size of string.");

	result.replace(start_pos, length, to);

	return result;
}

static std::string ReplaceAllInString
(
	const std::string& str,
	const std::string& from,
	const std::string& to
)
{
	if (from.empty())
		return str;

	std::string result = str;
	size_t start_pos = 0;

	while ((start_pos = result.find(from, start_pos)) != std::string::npos)
	{
		result = ReplaceInString(result, start_pos, from.length(), to);
		start_pos += to.length();
	}

	return result;
}

ForgBaseLib::FrgBase_FieldTools::Decorator
ForgBaseLib::FrgBase_FieldTools::theDecorator_ =
ForgBaseLib::FrgBase_FieldTools::Decorator::Dollar;

ForgBaseLib::FrgBase_FieldTools::Bracket
ForgBaseLib::FrgBase_FieldTools::theBracket_ =
ForgBaseLib::FrgBase_FieldTools::Bracket::Curly;

std::string ForgBaseLib::FrgBase_FieldTools::GetDecoratorAsString()
{
	return GetDecoratorAsString(theDecorator_);
}

std::string ForgBaseLib::FrgBase_FieldTools::GetDecoratorAsString
(
	Decorator dec
)
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

	return DECORATOR_DOLLAR_STR;
}

void ForgBaseLib::FrgBase_FieldTools::SetDecorator
(
	Decorator dec
)
{
	theDecorator_ = dec;
}

std::pair<std::string, std::string> ForgBaseLib::FrgBase_FieldTools::GetBracketAsString()
{
	return GetBracketAsString(theBracket_);
}

std::pair<std::string, std::string>
ForgBaseLib::FrgBase_FieldTools::GetBracketAsString
(
	Bracket bracket
)
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
	else
	{
		begin = BRACKET_CURLY_BEGIN_STR;
		end = BRACKET_CURLY_END_STR;
	}

	return std::make_pair(begin, end);
}

void ForgBaseLib::FrgBase_FieldTools::SetBracket
(
	Bracket bracket
)
{
	theBracket_ = bracket;
}

std::string ForgBaseLib::FrgBase_FieldTools::AddDecoratorAndBracket
(
	const std::shared_ptr<FrgBase_Field_Entity>& field
)
{
	if (!field)
		return "";

	
	return AddDecoratorAndBracketToString
	(
		field->GetFullPresentationName()
	);
}

std::string ForgBaseLib::FrgBase_FieldTools::AddDecoratorAndBracketToString
(
	const std::string& text
)
{
	auto decorator = GetDecoratorAsString();
	auto bracket = GetBracketAsString();

	return (decorator + bracket.first + text + bracket.second);
}

size_t ForgBaseLib::FrgBase_FieldTools::GetNumberOfAdditionalString()
{
	auto decorator = GetDecoratorAsString();
	auto bracket = GetBracketAsString();

	return decorator.size() + bracket.first.size() + bracket.second.size();
}

std::string ForgBaseLib::FrgBase_FieldTools::DecorizeExpressionUsingString
(
	const std::string& expression,
	const std::vector<std::shared_ptr<FrgBase_SymbolTable>>& tables
)
{
	auto result = expression;
	for (const auto& table : tables)
	{
		auto fields =
			table->GetFields();
		for (const auto& field : fields)
		{
			result = ReplaceAllInString
			(
				result,
				field->GetFullName(),
				AddDecoratorAndBracketToString(field->GetFullPresentationName())
			);
		}
	}

	return result;
}

std::string ForgBaseLib::FrgBase_FieldTools::DecorizeExpression
(
	const std::shared_ptr<FrgBase_Field_Entity>& field
)
{
	if (!field)
		throw std::exception("Field is null in " __FUNCSIG__);

	auto tables =
		field->RetrieveSymbolTablesIncludingExternals();

	auto expression =
		FrgBase_FieldParser::CompileExpression
		(
			FrgBase_FieldParser::CreateFieldExpressionReadyToCompile(field),
			tables
		);

	auto variables =
		FrgBase_FieldParser::CollectVariablesFullName(field);

	auto result = field->GetExpression();

	for (auto var : variables)
	{
		auto field =
			FrgBase_FieldParser::RetrieveFieldUsingFullName
			(
				var,
				tables
			);

		result = ReplaceAllInString
		(
			result,
			var,
			AddDecoratorAndBracket(field)
		);
	}

	return result;
}

std::string ForgBaseLib::FrgBase_FieldTools::UnDecorizeExpression
(
	const std::string& decorizedExpression,
	const std::vector<std::shared_ptr<FrgBase_SymbolTable>>& tables
)
{
	if (decorizedExpression.empty())
		throw std::exception("Empty Expression.");

	if (tables.empty())
		return decorizedExpression;

	auto str = decorizedExpression;

	auto decorator = GetDecoratorAsString();
	auto [lb, rb] = GetBracketAsString();

	bool flag = true;
	size_t found = 0;

	while (flag)
	{
		found = str.find(decorator, found);
		if (found != std::string::npos)
		{
			auto f_lb = str.find(lb, found + 1);
			auto f_rb = str.find(rb, found + 1);

			if (f_lb == std::string::npos || f_rb == std::string::npos)
			{
				std::string message =
					"Error in finding a field. You may miss a \"" + lb + "\" or \"" + rb + "\"";

				throw std::exception(message.c_str());
			}

			std::string word;
			for (size_t i = f_lb + 1; i < f_rb; i++)
				word += str[i];

			auto field =
				FrgBase_FieldParser::RetrieveFieldUsingFullPresentationName
				(
					word,
					tables
				);

			if (!field)
			{
				std::string message =
					"Cannot parse \"" + word + "\"";

				throw std::exception(message.c_str());
			}

			std::string spaces;
			if (found - f_lb > 1)
			{
				for (size_t i = found + 1; i < f_lb; i++)
				{
					if (str[i] != ' ')
					{
						std::string message = "Bad character(s) between \"" +
							decorator + "\" and \"" + lb + "\"";

						throw std::exception(message.c_str());
					}
					spaces += ' ';
				}
			}

			/*str = ReplaceInString
			(
				str,
				found,
				(decorator + spaces + lb + word + rb).length(),
				field->GetFullName()
			);*/

			str = ReplaceAllInString
			(
				str,
				decorator + spaces + lb + word + rb,
				field->GetFullName()
			);

			found++;
		}
		else
		{
			flag = false;
		}
	}

	return str;
}