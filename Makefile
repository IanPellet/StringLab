CXXFLAGS = -Wall

check: test
	./test

test: string_tests.o string.o
	g++ string_tests.o string.o -o test

string_tests.o: string_tests.cpp
	g++ -c string_tests.cpp -o string_tests.o

string.o: string.cpp
	g++ -c string.cpp -o string.o

clean:
	rm test string_tests.o string.o
