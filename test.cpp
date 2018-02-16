#include <iostream>
#include <string>
#include "min_lexer.h"
#include "min_parser.h"
#include "min.h"

void run_lexer_test(std::string input)
{
	std::cout << "Test begin for :'" << input << "'" << std::endl;
	min::lexer l(input);
	min::token t;
	do
	{
		t = l.next_token();
		std::cout << t;
	} while (t.type != min::END);
	std::cout << "Test ends" << std::endl;
}

void run_parser_test(std::string input)
{
	std::cout << "Test parser begin for :'" << input << "'" << std::endl;
	min::parser p(input);
	p.func();
	std::cout << "Test parser ends" << std::endl;
}

int main() {

	run_lexer_test("(list a b c d)");
	run_lexer_test("(list (list a b) (list c d))");
	run_lexer_test("(add (add 1 2) (add 4 100))");

	// test parser:
	run_parser_test("(add 1 2)");
	run_parser_test("(add (add 1 2) 1 2)");
	return 0;
}

