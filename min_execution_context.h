#ifndef MIN_EXECUTION_CONTEXT_H
#define MIN_EXECUTION_CONTEXT_H

#include <vector>
namespace min
{

template<typename T>
struct execution_context
{
	std::vector<T> args;
	T result;

	execution_context() {}
	execution_context(T arg): result(arg) {
		args.push_back(arg);
	}
};

}// namespace min
#endif
