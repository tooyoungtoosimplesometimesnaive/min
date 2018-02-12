#include "min_lexer.h"
#include "min_token.h"
#include "min.h"

token lexer::next_token()
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
		else
			throw "Invalid";
	}
	return token(END, "EOF");
}

void lexer::consume()
{
	pos++;
	if (pos > input.size())
		c = '\0';
	else
		c = input[pos];
}

token lexer::name()
{
	std::string name = "";
	do {
		name.append(1, c);
		consume();
	} while (isalpha(c));
	return token(NAME, name);
}

