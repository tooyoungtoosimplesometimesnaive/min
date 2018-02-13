#ifndef MIN_LEXER_H
#define MIN_LEXER_H

#include <string>
#include "min_token.h"

namespace min {

class lexer {
public:
	min::token next_token();
	min::token name();
	min::token number();
	void consume();

	lexer(std::string input_str): input(input_str), pos(0) {
		c = input[pos];
	}

private:
	std::string input;
	int pos;
	char c;
};

}// namespace min
#endif
