#ifndef MIN_H
#define MIN_H

#include <string>

namespace min {
// Some costants goes here:
int END = 1;
int LP = 2; // left parenthesis
int RP = 3; // right parenthesis
int NAME = 4;
int FUNC_NAME = 5;
int NUMBER = 6;
int LB = 7; // left bracket
int RB = 8; // right bracket
int COMMA = 9; // right bracket
int LAMBDA = 10;
int MAP = 11;

std::string type_list[12] = {"", "END", "LP", "RP", "NAME", "FUNC_NAME", "NUMBER",
	"LB", "RB", "COMMA", "LAMBDA", "MAP"};

// Reserved key words:
std::string _ADD = "add"; // the addition operator on integers
std::string _SUB = "sub"; // the subtraction operator on integers
std::string _MUL = "mul"; // the multiplication operator on integers
std::string _CON = "con"; // the concatenation operator on strings
std::string _LIST = "list"; // the list constructor
std::string _LAMBDA = "lambda"; // the lambda
std::string _MAP = "map"; // the map

} // namespace min
#endif
