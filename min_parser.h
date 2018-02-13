#ifndef MIN_PARSER_H
#define MIN_PARSER_H

#include "min.h"

namespace min {

class parser {
public:
	void list();
	void list_name();
	void list_element();
	void consume();
	void match(int t);
}

} // namespace min
#endif
