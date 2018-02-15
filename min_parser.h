#ifndef MIN_PARSER_H
#define MIN_PARSER_H

#include "min.h"
#include "min_lexer.h"

namespace min {

class parser {
public:
	parser(min::lexer l) : lex(l), lookahead(l.next_token()) {}
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
