
clang++ -Wall -std=c++14 -shared min_token.cpp -o ./outputs/min_token.so
clang++ -Wall -std=c++14 -shared min_lexer.cpp -o ./outputs/min_lexer.so
clang++ -Wall -std=c++14 ./outputs/min_lexer.so ./outputs/min_token.so test.cpp -o ./outputs/min_test.o
