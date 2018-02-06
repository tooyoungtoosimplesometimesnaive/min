#include "min_lexer.h"
#include "min_token.h"

token lexer::next_token()
{
	char c;
	while (!f.eof()) {
		if (isspace(c))
			continue;
		else if (c == '(')
			consume();
		else if (c == ')')
			consume();
		else if (isalpha(c))
			return name();
		else
			throw "Invalid";
	}
	return token(1, "<EOF>");
}

