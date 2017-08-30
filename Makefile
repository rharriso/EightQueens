build:
	clang++ -std=c++14 -Wall -Werror main.cpp -o eight_queens

run: build
	./eight_queens