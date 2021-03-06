typedef long unsigned int size_t;


class string{
	public :
		static int HowManyStrings();
		string() = default; // constructor
		

		// Member A
		string(const char* s, int size);
		string(const string& a);  //copy constructor
		char* c_str() const; 
		int size(); //method which will count number of chars in string
		void clear(); //method which will delete all chars 
		string& operator=(char* a);
		string operator+(char* a);

		
		
		//Member B
		string(char* c_string);	//constructor from a c-sting
		int length() const;
		size_t max_size() const;
		void resize(size_t n, char c);
		string& operator=(const string& str);
    		string operator+(char c);

		

		


		// Member C
		~string(); // destructor
		size_t capacity(); // returns the memory allocated to the array of char
		bool empty(); // true if length = 0
		void reserve(size_t n); // allocate or desallocate memory in order to have a capacity of n
		string& operator=(const char* s); // assigns the value s to the string
		
		int char_length(char * a)		//function which will count the length of char*
		{
			// checking the length of parameter "a"
			int counter = 0;
			char n = a[counter];
			while (n != '\0')
			{
				counter++;
				n = a[counter];
			}
			return counter;
			// counter is the length of parameter "a"
		}
  
	protected :
		char* string_; // dynamic array containing the string's chars
		size_t capacity_ = 0; // needs to be updated each time we allocate or desallocate memory space
		int length_;
	private:
		static int num_strings;
};

string operator+(const string& lhs, const string& rhs); // returns the concatenation of lhs adn rhs

