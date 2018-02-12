#include <iostream>
#include "min_token.h"

std::ostream& operator<<(std::ostream &os, token & t)
{
	os << "<" << t.text << "," << t.type << ">" << std::endl;
	return os;
}
