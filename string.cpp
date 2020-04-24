#include "string.h"

int string::num_strings = 0;

int string::HowManyStrings()
{
	return num_strings;
}


string::string() { // dummy constructor
	capacity_ = 12;
	length = 10;
    string_ = new char[length];
    string_[0] = 'H';
    string_[1] = 'e';
    string_[2] = 'l';
    string_[3] = 'l';
    string_[4] = 'o';
    string_[5] = '\0';

	num_strings++;
}

string::string(const char* s, int size)
{
	length = size;
	string_ = new char[length + 1];
	for (int i - 0; i < length + 1; i++)
	{
		string_[i] = s[i];
	}
	num_strings++;

}


//Member A
char* string::c_str(){ // returns the content of the string
	return string_;
}

string(const string& a) //copy constructor, which copies all data from another string 
{							   // and then make new string with all of it
	capacity_ = a.capacity_;
	length = a.length;
	string_ = new char[a.length];
	for (int i = 0; i < a.length; i++)
	{
		string_[i] = a.string_[i];
	}
	num_strings++;
}

size_t string::size()		// this function has to just return the length which is already in memory
{
	return length;
}

void string::clear()			//clearing the string is just deleting all chars from the string and pointing string_ to nullptr
{
	delete[] string_;
	string_ = nullptr;
}

string& string::operator=(char* a)
{
	delete[] string_;
	
	length = char_length(a);   // taking the length of chars in a-string
	string_ = new char[length];
	for (int i = 0; i < length; i++)
	{
		string_[i] = a[i];			//adding new chars to string_ from a-string
	}	
	//TODO: implement how to change the capacity
}

string string::operator+(const char* a)
{
	int temp = length;
	length += char_length(a);
	int counter = 0;
	for (int i = temp; i < length; i++)
	{
		string_[i] = a[counter];
		counter++;
	}

	//TODO: implement how to change the capacity
}


// Member C
string::~string(){ // destructor
	delete []string_;
	string_ = nullptr;
	num_strings--;
}

size_t string::capacity(){ // returns the memory allocated to the array of char
	return capacity_;
} 