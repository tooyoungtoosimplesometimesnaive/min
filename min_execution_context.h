#ifndef MIN_EXECUTION_CONTEXT_H
#define MIN_EXECUTION_CONTEXT_H

#include <vector>
#include <string>
namespace min
{

template<typename T>
struct execution_context
{
	std::string lambda_expr_literal;
	std::vector<T> lambda_args;
	std::vector<T> args;
	T result;

	execution_context() {}
	execution_context(T arg): result(arg) {
		args.push_back(arg);
	}
};

}// namespace min
#endif
