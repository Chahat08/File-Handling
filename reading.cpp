#include <iostream>
#include <fstream>

using namespace std;

int main() {
	fstream inFile;

	string inputFileName = "sea_cities.txt";
	inFile.open(inputFileName, ios::in);

	if (inFile.is_open()) {
		string line;

		//while (!inFile.eof()) { // ! operator has been overloaded so we can do something like below
		while (inFile) {
			getline(inFile, line);
			cout << line << endl;
		}

		inFile.close();
	}
	else {
		std::cout << "Unable to open file " << inputFileName << endl;
		return -1;
	}

	return 0;
}