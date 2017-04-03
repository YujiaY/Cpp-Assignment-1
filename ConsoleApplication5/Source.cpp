#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib> // for exit()
#include <algorithm>

using namespace std;
const int row = 10;
const int col = 2;
string qanda[row][col];

string filename = "QandA.txt";

struct questionaries {
	string question;
	string answer;

	void printstruct(const questionaries& questionary) {
		cout << questionary.question << endl;
		cout << questionary.answer << endl;
		}

} questionariesarray[row];

void print_arr(string arr[row][col]);

void searching();

void readfromfile(const string& filename);


int main()
{
	readfromfile("QandA.txt");

	for (int n = 0; n < row; ++n) {
		questionariesarray[n].question = qanda[n][0];
		questionariesarray[n].answer = qanda[n][1];
	}

	//print the original array:
	cout << endl << "Now the original array are showed below:"  << endl << endl;
    
	for (auto element : questionariesarray)
	           element.printstruct(element) ;
	cout << endl;

	// sort the arrar[] using user-defined structure


	std::sort(questionariesarray, questionariesarray + row, [](questionaries a, questionaries b) { return a.question < b.question; });

	// change the array to be sorted:
	for (int x = 0; x < row; x++) {
		qanda[x][0] = questionariesarray[x].question;
		qanda[x][1] = questionariesarray[x].answer;
	}

	//print the sorted array:
	cout << "Now the sorted array are showed below:" << endl << endl;

	print_arr(qanda);

	//searching for keyword

	searching();

	return 0;
}

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

	getline(cin, keyword);

	int resultcount = 0;
	for (int n = 0; n < row; n++) {
		string &qstring = questionariesarray[n].question;
		string &astring = questionariesarray[n].answer;
		string qtemp = questionariesarray[n].question;

		transform(keyword.begin(), keyword.end(), keyword.begin(), tolower);
		transform(qtemp.begin(), qtemp.end(), qtemp.begin(), tolower);

		if (qtemp.find(keyword) < qtemp.length()) {
			cout << "The No." << resultcount + 1 << " result of \"" + keyword + "\" are as followed:" << endl;
			cout << endl;
			cout << qstring << endl;
			cout << astring << endl;
			cout << endl;
			resultcount++;
		}


	}
	cout << "There are totally " << resultcount << " results found." << endl;
}

void readfromfile(const string& filename) {

	ifstream inf(filename);
	string strInput;

	if (!inf)
	{
		cerr << "The file cannot be opened." << endl;
		exit(1);
	}
	while (inf) {

		for (int x = 0; x < row; ++x) {
			for (int y = 0; y < col; ++y) {
				if (getline(inf, strInput) && strInput.length() != 0) {
					qanda[x][y] = strInput;
					//cout << strInput << endl;
				}
			}
		}

	}

	inf.close();

}
