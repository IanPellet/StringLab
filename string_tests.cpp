#include "string.h"
#include <iostream>
#include <iterator>
#include <cstring>

int main()
{
	// Dummy constructor test (can be deleted once a real constructor is implemented)
	//string hello();
	//std::cout << hello.c_str() << std::endl;

// Member C
	// capacity test
	char helloc[] = "Hello";
	string hello(helloc);
	bool capatest = hello.capacity() == std::end(helloc) - std::begin(helloc) - 1; // unitary test
	std::cout << "Capacity : ";
	if(capatest){
		std::cout << "ok" << std::endl;
	}else{                                           // test output
		std::cout << "not working" << std::endl;
	}

	// empty test
	char heyc[] = "hey";
	char oc[] = "";
	string hey(heyc);
	string o(oc);
	bool emptytest = (o.empty() && !hey.empty()); // unitary test
	std::cout << "Empty : ";
	if(emptytest){
		std::cout << "ok" << std::endl;
	}else{                                           // test output
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
	bool restest = (capahello1 == n1) && (capahey0 == capahey1); // unitary test
	std::cout << "Reserve : ";
	if(restest){
		std::cout << "ok" << std::endl;
	}else{                                           // test output
		std::cout << "not working" << std::endl;
	}

	// operator=(const char*) test
	hello = heyc;
	bool eqchartest = std::strcmp(hello.c_str(), heyc) == 0; // unitary test
	std::cout << "operator=(const char*) : ";
	if(eqchartest){
		std::cout << "ok" << std::endl;
	}else{                                           // test output
		std::cout << "not working" << std::endl;
	}

	// operator+(const string&, const string&) test
	char abc[] = "abc";
	char defgh[] = "defgh";
	string str1(abc);
	string str2(defgh);
	string concat = str1+str2;
	bool plusstrstrtest = std::strcmp(concat.c_str(), "abcdefgh") == 0; // unitary test
	std::cout << "operator+(const string&, const string&) : ";
	if(plusstrstrtest){
		std::cout << "ok" << std::endl;
	}else{                                           // test output
		std::cout << "not working" << std::endl;
	}                 

	// destruction of all used strings
	hello.~string();
	hey.~string();
	o.~string();
	str1.~string();
	str2.~string();

	return 0;
}