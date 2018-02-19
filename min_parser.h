#ifndef MIN_PARSER_H
#define MIN_PARSER_H

#include <string>
#include "min.h"
#include "min_lexer.h"
#include "min_execution_context.h"

namespace min {

class parser {
public:
	parser(std::string input) : lex(input), lookahead(lex.next_token()){}
	void consume();
	std::string match(int t);

	std::string func();


	std::string func_expr();
	void exprs(min::execution_context<std::string> & ec);

	void lambda_expr(execution_context<std::string> & ec);
	void lambda_args(execution_context<std::string> & ec);
	std::string lambda_func_expr(execution_context<std::string> & ec);

private:
	min::lexer lex;
	min::token lookahead;
};

} // namespace min
#endif
