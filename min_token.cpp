#include <iostream>
#include "min_token.h"
#include "min.h"

std::ostream& operator<<(std::ostream &os, token & t)
{
	os << "<" << t.text << "," << type_list[t.type] << ">" << std::endl;
	return os;
}
