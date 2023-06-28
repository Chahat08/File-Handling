#include <iostream>
#include <fstream>

using namespace std;

#pragma pack(push, 1)

struct Person {
	/* We can't use a string for name because
	* since the string class doesn't know how big the string is going to be,
	* it just stores a pointer to it
	* In the heap section of the memory.
	* When we read from the binary later, we will just read a pointer that no longer points anywhere
	*/
	char name[50]; // size: 50*1 = 50
	int age; // size: 4
	double weight; // size: 8
};

#pragma pack(pop)

int main() {
	// 50, 4, 8
	cout << sizeof(Person::name) << " " << sizeof(Person::age) << " " << sizeof(Person::weight) << endl;
	
	// 64 (Because some padding is done in structs)
	cout << sizeof(Person) << endl;


	return 0;
}