#ifndef MIN_LEXER_H
#define MIN_LEXER_H

#include "min_token.h"

int LP = 2; // left parenthesis
int RP = 3; // right parenthesis

class lexer {
public:
	token next_token();
	token name();
	void consume();

};

#endif
