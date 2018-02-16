#include "min_parser.h"
#include <iostream>

void min::parser::match(int t)
{
	std::cout << "In match - " << t << " - " << lookahead.type
		<< " - " << lookahead.text << std::endl;
	if (lookahead.type == t)
		consume();
	else throw "Error, type does not match";
}

void min::parser::consume()
{
	std::cout << "Consuming: " << lookahead.text << " - " << lookahead.type << std::endl;
	lookahead = lex.next_token();
}

void min::parser::func()
{
	match(min::LP);
	func_expr();
	exprs();
	match(min::RP);
}

void min::parser::func_expr()
{
	match(min::FUNC_NAME);
}

void min::parser::exprs()
{
	while(lookahead.type == min::LP || lookahead.type == min::NUMBER)
	{
		if (lookahead.type == min::LP)
			func();
		else
			expr();
	}

}

void min::parser::expr()
{
	match(min::NUMBER);
}
