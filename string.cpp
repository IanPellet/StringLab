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

//member B
string::string(char* c_string)
{
    int j = 0;
    while(c_string[j]!='\0')
    {
        j++;
    }
    capacity_ = j;
    string_ = new char[capacity_];
    int i = 0;
    do
    {
        string_[i] = c_string[i];
        i++;
    }
    while(c_string[i]!='\0');
}

int string::length()
{
    int i = 0;
    while(string_[i]!='\0')
    {
        i++;
    }
    return i;
}

// Member C
string::~string(){ // destructor
	delete []string_;
	string_ = nullptr;
}

size_t string::capacity(){ // returns the memory allocated to the array of char
	return capacity_;
}

bool string::empty(){
	return length()==0;
}
