eight_queens: main.cpp
	clang++ -std=c++14 -Wall -Werror main.cpp -o eight_queens

eight_queens_dbg: main.cpp
	clang++ -std=c++14 -Wall -Werror main.cpp -g -o eight_queens_dbg

run: eight_queens
	./eight_queens
