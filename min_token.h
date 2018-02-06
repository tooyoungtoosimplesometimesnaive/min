#ifndef MIN_TOKEN_H
#define MIN_TOKEN_H

#include <string>
#include <iostream>

struct token{
	friend std::ostream& operator<<(std::ostream &os, token & t);
	int type;
	std::string text;
	token(int t, std::string txt):type(t), text(txt) {}
};

#endif

