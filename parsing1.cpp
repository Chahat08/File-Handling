#include <iostream>
#include <fstream>
#include <unordered_map>

using namespace std;

int main() {

	ifstream inFile;

	string inputFileName = "stats1.txt";
	inFile.open(inputFileName);

	if (!inFile.is_open())
		return -1;

	unordered_map<string, int> m;

	string line;
	while (true) {
		getline(inFile, line, ':'); 
		if (!inFile)
			break;

		int population;
		inFile >> population;

		m[line] = population;

		//inFile.get();
		inFile >> ws;
	}

	for (auto& x : m)
		cout << x.first << "-> " << x.second << endl;

	return 0;
}