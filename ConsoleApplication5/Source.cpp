//For using Input/output stream class to operate on files.
#include <fstream>
//For reading or writing to the standard input/output streams
#include <iostream>
//For typedefs std::string 
#include <string>
//For exit()
#include <cstdlib>
//For searching and sorting
#include <algorithm>
//Introduces direct visibility of cin and cout of the std namespace
using namespace std;

//Assume we have 10 groups of questions and answers
const int row = 10;
//ONe column for question and the other for answer
const int col = 2;

//Setting up two globe variables
//Store the questions and answers in a atring array
string qanda[row][col];
//Identify the input file name
string filename = "QandA.txt";

//Build a user-defined structure for the sorting function
struct questionaries {
	string question;
	string answer;

	//Buildin function to deal with the elements of the structure
	void printstruct(const questionaries& questionary) {
		cout << questionary.question << endl;
		cout << questionary.answer << endl;
		}
  //Initialize a instance named questionariesarray
} questionariesarray[row];

//For printing the array
void print_arr(string arr[row][col]);

//For searching a user-input keyword
void searching();

//For reading from a text file
void readfromfile(const string& filename);


int main()
{   //Read for a file named "QandA.txt"
	readfromfile("QandA.txt");
		
	//Store the data into structure: questionariesarray
	for (int n = 0; n < row; ++n) {
		questionariesarray[n].question = qanda[n][0];
		questionariesarray[n].answer = qanda[n][1];
	}
		
	cout << endl << "Now the original array are showed below:"  << endl << endl;

	//print the original array:
	for (auto element : questionariesarray)
	           element.printstruct(element) ;
	cout << endl;

	// sort the arrar[] using user-defined structure
	
	std::sort(questionariesarray, questionariesarray + row, [](questionaries a, questionaries b) { return a.question < b.question; });

	// Store the sorted data into the array:
	for (int x = 0; x < row; x++) {
		qanda[x][0] = questionariesarray[x].question;
		qanda[x][1] = questionariesarray[x].answer;
	}
		
	cout << "Now the sorted array are showed below:" << endl << endl;
	
	//print the sorted array:
	print_arr(qanda);

	//searching for keyword
	searching();

	return 0;
}

//Loop for print data in the array
void print_arr(string arr[row][col]) {

	for (int x = 0; x < row; ++x) {
		for (int y = 0; y < col; ++y) {
			cout << arr[x][y] << endl;
		}
	}
	cout << endl << endl;
}


void searching() {

	cout << "Please enter the key word you want to search for:" << endl;
	cout << endl;

	string keyword;
	//Store user input data into variable: "keyword"
	getline(cin, keyword);

	//Set up a counter for the results
	int resultcount = 0;

	//Loop for searching every question string in the structure
	for (int n = 0; n < row; n++) {
		//use const to make sure it would not be changed unintended
		const string& qstring = questionariesarray[n].question;
		const string& astring = questionariesarray[n].answer;
		//use a temp string to set to lower case
		string qtemp = questionariesarray[n].question;
		
		//Change the keyword and the target string both to lower case for mathcing
		transform(keyword.begin(), keyword.end(), keyword.begin(), tolower);
		transform(qtemp.begin(), qtemp.end(), qtemp.begin(), tolower);
		//If found then print the sequence number, question and related answer
		if (qtemp.find(keyword) < qtemp.length()) {
			cout << "The No." << resultcount + 1 << " result of \"" + keyword + "\" are as followed:" << endl;
			cout << endl;
			cout << qstring << endl;
			cout << astring << endl;
			cout << endl;
			// counter +1
			resultcount++;
		}


	}
	//out put the total searching results
	if (resultcount == 0)
		cout << "There are nothing related found." << endl;
	else 
		cout << "There are totally " << resultcount << " results found." << endl;
}

//Function to read from a text file
void readfromfile(const string& filename) {
	//Relate the QandA.txt to the ifstream object inf
	ifstream inf(filename);
	//Generate a temp string to store the read data
	string strRead;

	if (!inf)
	{   //throw an exception if something wrong with the reading process 
		cerr << "The file cannot be opened." << endl;
		exit(1);
	}
	while (inf) {
		//Loop for storing the data into a array
		for (int x = 0; x < row; ++x) {
			for (int y = 0; y < col; ++y) {
				//Make sure the strRead is successfully read and not empty 
				if (getline(inf, strRead) && strRead.length() != 0) {
					qanda[x][y] = strRead;
				}
			}
		}
	}
	inf.close();
}


