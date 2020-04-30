#include "string.h"
#include <iostream>
#include <iterator>
#include <cstring>

int main()
{


// Member A
	/*
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

	string mystring3((mystring + extra_char));
	check = mystring3.c_str();
	std::cout << check << std::endl;

	delete[] mychar; 
	//delete[] mychar2;
	//delete[] check;


	*/	
//member B :
	
	  //test constructor from c_string : 

	  char str_c[]="hello";
	  string test(str_c);
	  char* s = test.c_str();
	  bool content_test=true;
	  int i = 0;
	  while(str_c[i]!='\0')   //comparaison des composant des chaines 1 à 1
	  {
	    if (str_c[i]!=s[i])
	      content_test=false;
	    i++;
	  }

	  if(content_test)
	    std::cout<<"Même contenu entre le c_string et notre string issu du constructeur, constructeur ok"<<std::endl;
	  else
	    std::cout<<"contenu différent entre le c_string et notre string issu du constructeur, constructeur pas ok"<<std::endl;

	  bool capa_test = (test.capacity()==i);  //la capacité du string est-elle bien initialisée avec la taille du c_string ?

	  if(capa_test)
	    std::cout<<"La capacité est égale à la taille du c_string, constructeur ok"<<std::endl;
	  else
	    std::cout<<"La capacité n'est pas égale à la taille du c_string, constructeur pas ok"<<std::endl;



	//test fonction resize

	  //cas ou on resize en plus petit
	char test1[]="hello";
	char test2[]="hel";
	char test3[]="helloccccc";

	string str1(test1);
	string str2(test2);
	string str3(test3);
	str1.resize(3,'c'); //str1 = str2 si resize fonctionne bien
	bool test_resize1 = strcmp(str1.c_str(),str2.c_str());  //renvoi 0 si chaines égales
	if(test_resize1 == 0)
	  std::cout<<"les chaines de carractère sont égales, resize en plus petit ok"<<std::endl;
	else
	  std::cout<<"les chaines sont différentes, resize en plus petit pas ok"<<std::endl;
	test_resize1=(str1.capacity()==str2.capacity());
	if(test_resize1)
	  std::cout<<"Les capacités sont égales, resize en plus petit ok"<< std::endl;
	else
	  std::cout<<"Les capacités sont différentes, resize en plus petit pas ok"<<std::endl;


	  //cas ou on resize en plus grand

	char test4[]="hello";
	string str4(test4);
	str4.resize(10,'c'); //str4 = str3 si resize fonctionne bien

	bool test_resize2 = strcmp(str4.c_str(),str3.c_str());  //renvoi 0 si chaines égales
	if(test_resize2 == 0)
	  std::cout<<"les chaines de carractère sont égales, resize en plus grand ok"<<std::endl;
	else
	  std::cout<<"les chaines sont différentes, resize en plus grand pas ok"<<std::endl;
	test_resize2=(str3.capacity()==str4.capacity());
	if(test_resize2)
	  std::cout<<"Les capacités sont égales, resize en plus grand ok"<< std::endl;
	else
	  std::cout<<"Les capacités sont différentes, resize en plus grand pas ok"<<std::endl;


	//test fonction length()

	char test_len[]="heyy";
	string test_l(test_len);
	bool len_test = (test_l.length()==4);
	if(len_test)
	  std::cout<<"La longueur est la bonne, length() ok"<< std::endl;
	else
	  std::cout<<"La longueur est fausse, length() pas ok"<<std::endl;


	//test opérateur = entre deux string :

	char test_op1[]="hello";
	char test_op2[]="hi";
	string test_o1(test_op1);
	string test_o2(test_op2);
	test_o1=test_o2;  
	bool content_test2 = strcmp(test_o1.c_str(),test_o2.c_str());
	if(content_test2 == 0)
	  std::cout<<"les chaines de carractère sont égales, l'opérateur = fonctionne"<<std::endl;
	else
	  std::cout<<"les chaines sont différentes, opérateur = défectueux"<<std::endl;

	bool capa_test2 = (test_o1.capacity()==test_o2.capacity());
	if(capa_test2)
	  std::cout<<"La longueur est égale, opérateur = fonctionnel"<< std::endl;
	else
	  std::cout<<"La longueur est différente, opérateur = défectueux"<<std::endl;

	//test opérateur + entre un string et un char : 
	char test_ope1[]="hello";
	char test_ope2[]="helloc";
	string test_oe1(test_ope1);
	string test_oe2(test_ope2);
	test_oe1=test_oe1 + 'c';

	bool content_test3 = strcmp(test_oe1.c_str(),test_oe2.c_str());
	if(content_test3 == 0)
	  std::cout<<"les chaines de carractère sont égales, l'opérateur + fonctionne"<<std::endl;
	else
	  std::cout<<"les chaines sont différentes, opérateur + défectueux"<<std::endl;

	bool capa_test3 = (test_oe1.capacity()==test_oe2.capacity());
	if(capa_test3)
	  std::cout<<"La longueur est égale, opérateur + fonctionnel"<< std::endl;
	else
	  std::cout<<"La longueur est différente, opérateur + défectueux\n"<<std::endl;  


	

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
	string str1C(abc);
	string str2C(defgh);
	string concat = str1C+str2C;
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
	str1C.~string();
	str2C.~string();
	test.~string();
	str1.~string();
	str2.~string();
	str3.~string();
	str4.~string();
	test_o1.~string();
	test_o2.~string();
	test_oe1.~string();
	test_oe2.~string();
	

	return 0;
}
