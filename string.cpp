#include "string.h"

int string::num_strings = 0;

int string::HowManyStrings()
{
	return num_strings;
}

/*string::string(const char* s, int size)
{
	length = size;
	string_ = new char[length + 1];
	for (int i - 0; i < length + 1; i++)
	{
		string_[i] = s[i];
	}
	num_strings++;

}*/


//Member A
char* string::c_str() const { // returns the content of the string
	return string_;
}

/*string(const string a) //copy constructor, which copies all data from another string 
{							   // and then make new string with all of it
	capacity_ = a.capacity_;
	length = a.length;
	string_ = new char[a.length];
	for (int i = 0; i < a.length; i++)
	{
		string_[i] = a.string_[i];
	}
	num_strings++;
}*/

/*size_t string::size()		// this function has to just return the length which is already in memory
{
	return length;
}*/

void string::clear()			//clearing the string is just deleting all chars from the string and pointing string_ to nullptr
{
	delete[] string_;
	string_ = nullptr;
}

/*string& string::operator=(char* a)
{
	delete[] string_;
	
	length = char_length(a);   // taking the length of chars in a-string
	string_ = new char[length];
	for (int i = 0; i < length; i++)
	{
		string_[i] = a[i];			//adding new chars to string_ from a-string
	}	
	//TODO: implement how to change the capacity
}*/

/*string string::operator+(const char* a)
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
}*/


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

void string::resize(size_t n, char c)
{
    if (length()<n)
    {
        for(int i=length(); i<n;i++)
        {
            string_[i]=c;
        }
    }
    for(int j=n; j<capacity_;j++)
    {
        string_[j]='\0';
    }
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

bool string::empty(){
	return length()==0;
}

void string::reserve(size_t n){ // allocate or desallocate memory in order to have a capacity of n

    if (length()<n)
    {
        char temp[length()+1] = {*c_str()};
        this->~string();
        capacity_ = n;
        string_ = new char[capacity_];

        int i = 0;
	    do
	    {
	        string_[i] = temp[i];
	        i++;
	    }
	    while(temp[i]!='\0');

    }

}

string& string::operator=(const char* s){ // assigns the value s to the string
	int lens = 0;
    do
    {
        lens++;
    }
    while(s[lens]!='\0');

    char* temp = new char[lens];

    int i = 0;
    do
    {	
    	temp[i] = s[i];
        i++;
    }
    while(s[i]!='\0');

    string returnedstr(temp);

    delete []temp;
	temp = nullptr;

    return returnedstr;
}

string operator+(const string& lhs, const string& rhs){ // returns the concatenation of lhs adn rhs
	int lenlhs = 0;
    while(lhs.c_str()[lenlhs]!='\0'){
        lenlhs++;
    }
    int lenrhs = 0;
    do
    {
        lenrhs++;
    }
    while(rhs.c_str()[lenrhs]!='\0');

    char* temp = new char[lenlhs + lenrhs +1];

    int i = 0;
    while(lhs.c_str()[i]!='\0'){
    	temp[i] = lhs.c_str()[i];
    	i++;
    }
    do
    {	
    	temp[i] = rhs.c_str()[i-lenlhs];
        i++;
    }
    while(rhs.c_str()[i-lenlhs]!='\0');
    temp[lenlhs + lenrhs] = '\0';

    string returnedstr(temp);

    delete []temp;
	temp = nullptr;

    return returnedstr;
}