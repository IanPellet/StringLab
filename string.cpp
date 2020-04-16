#include "string.h"

string::string() { // dummy constructor
	capacity_ = 12;
    string_ = new char[capacity_];
    string_[0] = 'H';
    string_[1] = 'e';
    string_[2] = 'l';
    string_[3] = 'l';
    string_[4] = 'o';
    string_[5] = '\0';
}

char* string::c_str(){ // returns the content of the string
	return string_;
}

// Member C
string::~string(){ // destructor
	delete []string_;
	string_ = nullptr;
}

int string::capacity(){ // returns the memory allocated to the array of char
	return capacity_;
} 