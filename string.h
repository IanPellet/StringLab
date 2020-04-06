#include <memory> // needed to use an allocator

class string{
	public :
		~string(); // destructor
		int capacity(); // returns the memory allocated to the array of char
		bool empty(); // true if length = 0
		reserve(size_t n); // allocate or desallocate memory in order to have a capacity of n
		string& operator=(const char* s); // assigns the value s to the string
		string operator+(const string& lhr, const string& rhs); // returns the concatenation of lhr adn rhs

	protected :
		char* string_; // pointer to the array containing the char of our string
		allocator<char> alloc_; // will be used to manage the string's memory space
		int capacity_; // needs to be updated each time we allocate or desallocate memory space
};