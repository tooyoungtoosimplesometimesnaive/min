#include <iostream>
#include "min_token.h"
#include "min.h"

std::ostream& min::operator<<(std::ostream &os, min::token & t)
{
	os << "<" << t.text << "," << min::type_list[t.type] << ">" << std::endl;
	return os;
}
