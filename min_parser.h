#ifndef MIN_PARSER_H
#define MIN_PARSER_H

#include <string>
#include "min.h"
#include "min_lexer.h"

namespace min {

class parser {
public:
	parser(std::string input) : lex(input), lookahead(lex.next_token()){}
	void consume();
	void match(int t);
	void func();
	void func_expr();
	void expr();
	void exprs();

private:
	min::lexer lex;
	min::token lookahead;
};

} // namespace min
#endif
