#include <iostream>
#include <fstream>

using namespace std;

int main() {
	//ofstream outFile;
	fstream outFile;

	std::string outputFileName = "text.txt";
	//outFile.open(outputFileName);
	outFile.open(outputFileName, ios::out);

	if (outFile.is_open()) {
		outFile << "HI and Hello there and bye" << endl;
		outFile << 1234 << endl;
		outFile.close();
	}
	else std::cout << "File not create file: " << outputFileName << std::endl;

	return 0;
}