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

std::string type_list[7] = {"", "END", "LP", "RP", "NAME", "FUNC_NAME", "NUMBER"};

// Reserved key words:
std::string _ADD = "add";
std::string _MUL = "mul";

} // namespace min
#endif
