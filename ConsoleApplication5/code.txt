#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <array>
#include <cstdlib> // for exit()
#include <algorithm> 

using namespace std;
const int row = 10;
const int col = 2;


int main() {
	// ifstream is used for reading files
	// We'll read from a file called QandA.txt
	

	ifstream inf("QandA.txt");

	string qanda[row][col];
	string strInput;
	if (!inf)
	{
		cerr << "The file cannot be opened." << endl;
		exit(1);
	}
	while (inf) {

		for (int x = 0; x < row; ++x) {
			for (int y = 0; y < col; ++y) {
				if (getline(inf, strInput) && strInput.length() != 0){
				qanda[x][y] = strInput;
				//cout << strInput << endl;
				}
			}
		}

	}

	inf.close();
	
 

	// print the original array[]
	cout << "Now the original array are showed below:" << endl;
	cout << endl;

	for (int x = 0; x < row; ++x) {
		for (int y = 0; y < col; ++y) {
			cout << qanda[x][y] << endl;
		}
	 
		cout << endl;
	}
 

	// sort the arrar[] using vector
 
	vector<string> vecstring;


	for (int x = 0; x < row; x++) {
	string temp = qanda[x][0] + "\n" + qanda[x][1];
	vecstring.push_back(temp);
	}

	sort(vecstring.begin(), vecstring.end());

	cout << "Now the sorted array are showed below:" << endl;

	for ( string &s : vecstring)
	cout << s << endl;

 
	//searching
cout << "Please enter the key word you want to search for:" << endl;
cout << endl;

string keyword;

getline(cin, keyword);

int resultcount = 0;
for (int x = 0; x < row; x++) {
string qstring = qanda[x][0];
string qs = qanda[x][0];
string as = qanda[x][1];

transform(keyword.begin(), keyword.end(), keyword.begin(), tolower);
transform(qstring.begin(), qstring.end(), qstring.begin(), tolower);

if (qstring.find(keyword) < qstring.length()) {
cout << "The result of \"" + keyword + "\" are as followed:" << endl ;
cout << endl;
cout << qs << endl;
cout << as << endl;
cout << endl;
resultcount++;
}

}

 
cout << "There are " << resultcount << " results found." << endl;
 
	return 0;

}
 
