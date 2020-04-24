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

	
		/*
// Member A, all methods tests
	int char_size; char a;
	std::cout << "Type the size of a string: " << std::endl;
	std::cin >> char_size;
	char * mychar=nullptr;
	mychar = new char[char_size];
	for (int i = 0; i < char_size; i++)
	{
		std::cin >> a;
		mychar[i] = a;
	}
	std::cout <<"Those chars from mychar are: "<< mychar << std::endl;;
	string mystring(mychar,char_size);
	string mystring2(mystring); 
	char * mychar2 = nullptr;
	mychar2 = mystring.c_str();
	std::cout <<"Second char* from copy constructor is: "<< mychar2 << std::endl;

	std::cout << "Size of this string is equal to: " << mystring.size() << std::endl;

	mystring2.clear();

	std::cout << "After cleaning, size of string2 is equal to: " << mystring2.size() << std::endl;
	
	char extra_char[] = "this is extra text";
	char* check = nullptr;
	mystring = extra_char;
	check = mystring.c_str();
	std::cout << check << std::endl;

	//string mystring3((mystring + extra_char));
	//check = mystring3.c_str();
	//std::cout << check << std::endl;

	delete[] mychar; 
	//delete[] mychar2;
	//delete[] check;


	*/
	return 0;
}
