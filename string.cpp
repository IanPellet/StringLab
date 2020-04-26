#include "string.h"

int string::num_strings = 0;

int string::HowManyStrings()
{
	return num_strings;
}

string::string(const char* s, int size)
{
	this ->length_ = size;
	string_ = new char[this->length_ + 1];
	for (int i = 0; i < this->length_ + 1; i++)
	{
		string_[i] = s[i];
	}
	num_strings++;
}


//Member A
char* string::c_str(){ // returns the content of the string
	return string_;
}

string(const string a) //copy constructor, which copies all data from another string 
{							   // and then make new string with all of it
	capacity_ = a.capacity_;
	
	string_ = new char[a.length_];
	for (int i = 0; i < a.length_; i++)
	{
		string_[i] = a.string_[i];
	}
	this->length_ = a.length_;
	num_strings++;
}

int string::size()		// this function has to just return the length which is already in memory
{
	return length_;
}

void string::clear()			//clearing the string is just deleting all chars from the string and pointing string_ to nullptr
{
	length_ = 0;
	delete[] string_;
	string_ = nullptr;
	capacity_ = 0;
}

string& string::operator=(char* a)
{
	delete[] string_;
	
	length_ = char_length(a);   // taking the length of chars in a-string
	string_ = new char[length_];
	for (int i = 0; i < length_; i++)
	{
		string_[i] = a[i];			//adding new chars to string_ from a-string
	}	
	//TODO: implement how to change the capacity
	return *this;
}

string string::operator+(char* a)
{
	int temp = length_;
	length_ += char_length(a);
	int counter = 0;
	for (int i = temp; i < length_; i++)
	{
		string_[i] = a[counter];
		counter++;
	}

	//TODO: implement how to change the capacity

	return *this;
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
	string_[i]='\0'
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



string& string::operator=(const string& str)
{
	size_t new_s = str.length();
	string_ = new char[new_s+1];
	strcpy(string_, str.c_str());
	return *this;
};


size_t string::max_size() const
{
	return 100;
};

string string::operator+(char c)
{
	if (length()+1 <= max_size())
	{
		char* n_c = new char[length()+2];
		strcpy(n_c, string_);
		n_c[length()] = c;
		n_c[length()+1] = '\0';
		string new_s(n_c);
		return n_c;
	};
	string new_s(string_);
	return new_s;
};









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
