/*
Author: Dexter Jones

- Obtain User input and append to CSC450_CTS_mod5.txt
- Create reversal method of all characters in ^ txt file and write results to CSC450-mod5-reverse.txt
- Use safe methods to mitigate vulnerabilities
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void reverseFile(fstream &myFile) {
	streampos begin, end;
	int* length = new int; // pointer
	
	if (myFile.is_open()) {
		myFile.seekg(0, ios::end); 
		end = myFile.tellg();
		
		*length = end; //pointer length assigned value of end
		
		char* buffer = new char[*length]; // create buffer for characters and allocate memory

		myFile.seekg(0, ios::beg);
		myFile.read(buffer, *length);

		for (int i = 0; i < *length / 2; ++i) { // reverse contents of buffer
			swap(buffer[i], buffer[*length - i - 1]);
		}

		myFile.seekp(0, ios::beg);

		ofstream myRevFile;
		myRevFile.open("CSC450-mod5-reverse.txt", ios::out | ios::binary);

		if (myRevFile.is_open()) {
			myRevFile.write(buffer, *length);
			myRevFile.close();
			cout << "Reverse order of characters successfully written to file" << endl;
		}
		else {
			cout << "Unable to open file for reverse writing" << endl;
		}

		delete[] buffer;
		delete length;
	}
	else {
		cout << "Unable to open file" << endl;
	}
	
}
int main() {
	string s;
	ofstream outFile;
	outFile.open("CSC450_CT5_mod5.txt", ios_base::app);

	cout << "Please enter your city and state: ";
	getline(cin, s); // get user input

	if (outFile.is_open()) {
		outFile << endl <<s; // Add user input to file
		outFile.close(); 
	}
	else {
		cout << "Unable to open file";
	}
	
	fstream myFile("CSC450_CT5_mod5.txt", ios::in | ios::out | ios::binary);

	reverseFile(myFile); // calls function to reverse characters in file
	myFile.close();
	
	return 0;
}