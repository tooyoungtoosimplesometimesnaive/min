#include "min_lexer.h"
#include "min_token.h"
#include "min.h"

min::token min::lexer::next_token()
{
	while (c != '\0') {
		if (isspace(c)) {
			consume();
			continue;
		}
		else if (c == '(')
		{
			consume();
			return token(LP, "(");
		}
		else if (c == ')')
		{
			consume();
			return token(RP, ")");
		}
		else if (isalpha(c))
			return name();
		else if (c >= '0' && c <= '9')
			return number();
		else
			throw "Invalid";
	}
	return token(END, "EOF");
}

void min::lexer::consume()
{
	pos++;
	if (pos > input.size())
		c = '\0';
	else
		c = input[pos];
}

min::token min::lexer::name()
{
	std::string name = "";
	do {
		name.append(1, c);
		consume();
	} while (isalpha(c));

	if (name == min::_ADD)
		return token(min::FUNC_NAME, name);
	else if (name == min::_MUL)
		return token(min::FUNC_NAME, name);
	else
		return token(NAME, name);
}

min::token min::lexer::number()
{
	std::string number = "";
	do {
		number.append(1, c);
		consume();
	} while (c >= '0' && c <= '9');
	return token(NUMBER, number);
}

