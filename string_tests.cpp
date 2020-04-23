#include "string.h"
#include <iostream>
#include <iterator>

int main()
{
	// Dummy constructor test (can be deleted once a real constructor is implemented)
	//string hello();
	//std::cout << hello.c_str() << std::endl;

// Member C
	// capacity test
	char helloc[] = "Hello";
	string hello(helloc);
	bool capatest = hello.capacity() == std::end(helloc) - std::begin(helloc) - 1;
	std::cout << "Capacity : ";
	if(capatest){
		std::cout << "ok" << std::endl;
	}else{
		std::cout << "not working" << std::endl;
	}

	// empty test
	char heyc[] = "hey";
	char oc[] = "";
	string hey(heyc);
	string o(oc);
	bool emptytest = (o.empty() && !hey.empty());
	std::cout << "Empty : ";
	if(emptytest){
		std::cout << "ok" << std::endl;
	}else{
		std::cout << "not working" << std::endl;
	}

	// reserve test 
	int n1 = 13; 
	int n2 = 1;
	size_t capahey0 = hey.capacity();
	hello.reserve(n1);
	hey.reserve(n2);
	size_t capahello1 = hello.capacity();
	size_t capahey1 = hey.capacity();
	bool restest = (capahello1 == n1) && (capahey0 == capahey1);
	std::cout << "Reserve : ";
	if(restest){
		std::cout << "ok" << std::endl;
	}else{
		std::cout << "not working" << std::endl;
	}

	return 0;
}