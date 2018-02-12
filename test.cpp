#include <iostream>
#include <string>
#include "min_lexer.h"
#include "min.h"

void run_test(std::string input)
{
	std::cout << "Test begin for :'" << input << "'" << std::endl;
	lexer l(input);
	token t;
	do
	{
		t = l.next_token();
		std::cout << t;
	} while (t.type != END);
	std::cout << "Test ends" << std::endl;
}
int main() {

	run_test("(list a b c d)");
	run_test("(list (list a b) (list c d))");
	return 0;
}

