#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
	fstream inFile;
	
	string inputFileName = "stats.txt";
	inFile.open(inputFileName, ios::in);

	unordered_map<string, long> m;
	if (inFile.is_open()) {
		string line;
		while (getline(inFile, line)) { // getline(inFile, line, '\n') -> getline allows using a delimiter (char upto which it reads)
			int i = 0;
			string country, population;
			for (char c : line) {
				if (c == ' ') i++;
				else if (i == 1 && c!=':') country += c;
				else if (i == 2) if (c != ',' && c != '\n') population += c;
			}
			m[country] = stoi(population);
		}
		inFile.close();
	}

	else {
		cout << "Unable to open file " << inputFileName << endl;
		return -1;
	}

	for (auto& x : m) 
		cout << x.first << ": " << x.second << endl;

	return 0;
}