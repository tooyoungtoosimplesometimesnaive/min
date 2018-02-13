#ifndef MIN_TOKEN_H
#define MIN_TOKEN_H

#include <string>
#include <iostream>

namespace min {

struct token{
	friend std::ostream& operator<<(std::ostream &os, token & t);
	int type;
	std::string text;
	token():type(1), text("") {}
	token(int t, std::string txt):type(t), text(txt) {}
};

} // namespace min
#endif

