#include "string.h"

string::string() {
    string_ = new char[12];
    string_[0] = 'H';
    string_[1] = 'e';
    string_[2] = 'l';
    string_[3] = 'l';
    string_[4] = 'o';
    string_[5] = '\0';
}

char* string::c_str(){
	return string_;
}