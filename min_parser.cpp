#include "min_parser.h"
#include "min_execution_context.h"
#include <iostream>
#include <string>
#include <regex>

std::string min::parser::match(int t)
{
	// std::cout << "In match - " << t << " - " << lookahead.type
	// 	<< " - " << lookahead.text << std::endl;
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

min::execution_context<std::string> min::parser::func()
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
		ec.result = std::to_string(result);
		return ec;
	} if (f == min::_SUB) {
		int result = 0;
		for (auto r : ec.args)
			result -= std::stoi(r);
		ec.result = std::to_string(result);
		return ec;
	} else if (f == min::_MUL) {
		int result = 1;
		for (auto r : ec.args)
			result *= std::stoi(r);
		ec.result = std::to_string(result);
		return ec;
	} else if (f == min::_CON) {
		std::string result = "";
		for (auto r : ec.args)
			result += r;
		ec.result = result;
		return ec;
	} else if (f == min::_LIST) {
		// std::string result = "[";
		// for (auto r : ec.args) {
		// 	result += r;
		// 	result += ",";
		// }
		// result += "]";
		// return result;
		return ec;
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
			ec.args.push_back(func().result);
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

std::string min::parser::immediately_invoke_lambda_expr()
{
	// immediately invoke lambda expr ((lambda (x y z) (add x y z)) 1 2 3)
	match(min::LP);
	consume();
	execution_context<std::string> ec;
	lambda_expr(ec);
	for (int i = 0; i < ec.lambda_args.size(); i++) {

		std::string real_arg = match(min::NUMBER);
		consume();
		// std::cout << ec.lambda_args[i] << " " << real_arg << std::endl;
		ec.lambda_expr_literal = std::regex_replace(ec.lambda_expr_literal, std::regex("\\s" + ec.lambda_args[i] + "\\s"),
			(" " + real_arg + " "));

	}
	match(min::RP);
	consume();
	min::parser p(ec.lambda_expr_literal);
	return p.func().result;
}

void min::parser::lambda_expr(execution_context<std::string> & ec)
{
	// lambda expr: (lambda (x y z) (add x y z))
	match(min::LP);
	consume();
	match(min::LAMBDA);
	consume();
	lambda_args(ec);
	std::string lambda_expr_literal = lambda_func_expr(ec);
	ec.lambda_expr_literal = lambda_expr_literal;
	match(min::RP);
	consume();
	std::cout << ec.lambda_expr_literal << std::endl;
}

void min::parser::lambda_args(execution_context<std::string> & ec)
{
	match(min::LP);
	consume();

	while(lookahead.type == min::NAME)
	{
		std::string n = match(min::NAME);
		consume();
		ec.lambda_args.push_back(n);
	}
	match(min::RP);
	consume();
}

std::string min::parser::lambda_func_expr(execution_context<std::string> & ec)
{
	std::string lambda_expr_literal = "";
	match(min::LP);
	consume();
	lambda_expr_literal += "(";
	std::string func_name = match(min::FUNC_NAME);
	consume();
	lambda_expr_literal += func_name;
	while(lookahead.type == min::LP || lookahead.type == min::NAME || lookahead.type == min::NUMBER)
	{
		if (lookahead.type == min::LP)
			lambda_expr_literal += lambda_func_expr(ec);
		else if (lookahead.type == min::NAME) {
			std::string n = match(min::NAME);
			consume();
			auto it = find(ec.lambda_args.cbegin(), ec.lambda_args.cend(), n);
			if (it == ec.lambda_args.cend())
				throw "Error : no such argument!";
			else {
				lambda_expr_literal += (" " + n + " ");
			}
		} else {
			std::string n = match(min::NUMBER);
			consume();
			lambda_expr_literal += (" " + n + " ");
		}

	}
	match(min::RP);
	consume();
	lambda_expr_literal += ")";
	return lambda_expr_literal;
}

void min::parser::map()
{
	match(min::LP);
	consume();
	match(min::MAP);
	consume();

	// get lambda:
	execution_context<std::string> lambda_ec;
	lambda_expr(lambda_ec);

	// list execution context:
	execution_context<std::string> list_ec = func();
	// use this to store the result, could change:
	execution_context<std::string> re;
	re.result = "";
	for (int i = 0; i < list_ec.args.size(); i++)
	{
		std::string map_single_execution_literal = std::regex_replace(
			lambda_ec.lambda_expr_literal,
			std::regex("\\s" + lambda_ec.lambda_args[0] + "\\s"),
			(" " + list_ec.args[i] + " ")
			);
		min::parser p(map_single_execution_literal);
		re.result += p.func().result;
		re.result += " ";
	}
	std::cout << re.result << std::endl;
}
