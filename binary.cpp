#include <iostream>
#include <fstream>

using namespace std;

#pragma pack(push, 1)

struct Person {
	char name[50];
	int age;
	double height;
};

#pragma pack(pop)

int main() {

	// extension can be something else as well
	string fileName = "test.bin"; 


	//// WRITING BINARY FILE //////////////

	fstream outFile;
	outFile.open(fileName, ios::out|ios::binary);

	if (!outFile.is_open()) {
		cout << "Could not create file " << fileName << endl;
		return -1;
	}

	Person person = {
		"Chahat",
		22,
		1.6
	};

	//outFile.write((char*)&person, sizeof(Person));
	outFile.write(reinterpret_cast<char*>(&person), sizeof(Person));

	outFile.close();

	//// READING BINARY FILE //////////////

	fstream inFile;
	inFile.open(fileName, ios::in | ios::binary);

	if (!inFile.is_open()) {
		cout << "Could not read file " << fileName << endl;
		return -1;
	}

	Person anotherPerson;

	//inFile.read((char*)&anotherPerson, sizeof(Person));
	inFile.read(reinterpret_cast<char*>(&anotherPerson), sizeof(Person));

	inFile.close();

	cout << anotherPerson.name << endl;
	cout << anotherPerson.age << endl;
	cout << anotherPerson.height << endl;

	

	return 0;
}