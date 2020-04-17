/*struct node    // node which will contain a letter and a pointer to next node with next letter
{
	char value;			//letter
	node*next = nullptr;		//pointer to next node

};*/

typedef unsigned int size_t;

class string{
	public :
		string(); // constructor

		// Member A
		//µstring(const string a); //copy constructor
		char* c_str(); 
		//int size(); //method which will count number of nodes in string
		//void clear(); //method which will delete all nodes and set first pointer to null
		//string& operator=(char a);
		//string operator+(const string&, const char*);

		//Member B
		//string(char &string);	//constructor from a c-sting
        //size_t length();
        //size_t max_size();
        //void resize(size_t n, char c);
        //string operator=(const string&);
        //string operator+(const string&);
        //string operator=(const string string&);
		//string operator+(char c);
		
		
		// Member C
		~string(); // destructor
		size_t capacity(); // returns the memory allocated to the array of char
		//bool empty(); // true if length = 0
		//reserve(size_t n); // allocate or desallocate memory in order to have a capacity of n
		//string& operator=(const char* s); // assigns the value s to the string
		//string operator+(const string& lhr, const string& rhs); // returns the concatenation of lhr adn rhs
	protected :
		char* string_; // dynamic array containing the string's chars
		size_t capacity_ = 0; // needs to be updated each time we allocate or desallocate memory space

	//private:
	//	node * first = nullptr;			//first pointer to the first node (letter) which is empty in the beggining
};