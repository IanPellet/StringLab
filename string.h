#include <memory> // needed to use an allocator

struct node    // node which will contain a letter and a pointer to next node with next letter
{
	char value;			//letter
	node*next = nullptr;		//pointer to next node

};

class string{
	public :
		// Member A
		string(const string a); //copy constructor
		char* c_str(); 
		int size(); //method which will count number of nodes in string
		void clear(); //method which will delete all nodes and set first pointer to null
		string& operator=(char a);
		string operator+(const string&, const char*);


		// Member C
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

	private:
		node * first = nullptr;			//first pointer to the first node (letter) which is empty in the beggining
};