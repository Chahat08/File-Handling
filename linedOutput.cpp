#include <iostream>
#include <fstream>

using namespace std;

int main() {
	fstream outFile;

	string outputFileName = "sea_cities.txt";
	outFile.open(outputFileName, ios::out);

	if (!outFile.is_open()) {
		cout << "Unable to create file " << outputFileName << endl;
		return -1;
	}

	const char* poem[5] = {
		"Other sea-cities have faltered,",
		"and striven with the tide.",
		"Other sea-cities have struggled,",
		"and died.",
		"\t-H.D."
	};

	for (int i = 0; i < 5; ++i) {
		outFile << i + 1;
		outFile << ". ";
		outFile << poem[i] << endl;
	}

	outFile.close();

	return 0;
}