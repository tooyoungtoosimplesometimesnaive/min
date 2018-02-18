#include "min_parser.h"
#include "min_execution_context.h"
// #include <iostream>
#include <string>

std::string min::parser::match(int t)
{
	// std::cout << "In match - " << t << " - " << lookahead.type
		// << " - " << lookahead.text << std::endl;
	if (lookahead.type == t)
	{
		return lookahead.text;
	}
	else throw "Error, type does not match";
}

void min::parser::consume()
{
	// std::cout << "Consuming: " << lookahead.text << " - " << lookahead.type << std::endl;
	lookahead = lex.next_token();
}

std::string min::parser::func()
{
	match(min::LP);
	consume();
	std::string f = func_expr();
	min::execution_context<std::string> ec;
	exprs(ec);
	match(min::RP);
	consume();
	if (f == min::_ADD) {
		int result = 0;
		for (auto r : ec.args)
			result += std::stoi(r);
		return std::to_string(result);
	} if (f == min::_SUB) {
		int result = 0;
		for (auto r : ec.args)
			result -= std::stoi(r);
		return std::to_string(result);
	} else if (f == min::_MUL) {
		int result = 1;
		for (auto r : ec.args)
			result *= std::stoi(r);
		return std::to_string(result);
	} else if (f == min::_CON) {
		std::string result = "";
		for (auto r : ec.args)
			result += r;
		return result;
	} else if (f == min::_LIST) {
		std::string result = "[";
		for (auto r : ec.args) {
			result += r;
			result += ",";
		}
		result += "]";
		return result;
	} else {
		// no support
		throw "No support for this function.";
	}
}

std::string min::parser::func_expr()
{
	std::string func_name = match(min::FUNC_NAME);
	consume();
	return func_name;
}

void min::parser::exprs(min::execution_context<std::string> & ec)
{
	while(lookahead.type == min::LP || lookahead.type == min::NUMBER || lookahead.type == min::NAME)
	{
		if (lookahead.type == min::LP)
			ec.args.push_back(func());
		else if (lookahead.type == min::NUMBER) {
			std::string n = match(min::NUMBER);
			consume();
			ec.args.push_back(n);
		} else {
			std::string n = match(min::NAME);
			consume();
			ec.args.push_back(n);
		}
	}

}
