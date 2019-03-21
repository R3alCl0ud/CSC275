#include <string.h>
#include <iostream>
#include <cstdlib>
#include <exception>

using namespace std;

class MyException : std::exception {

public:

	const char * what() const throw () {
		return "Uh, boss, I don't feel so guud.";
	}
};

int main(int argc, char** argv) {
	
	try {

		if (argc == 1) throw 1;
		if (argc == 2) throw MyException();
		if (argc == 3) throw "more than 2 for some reason";
	}
	catch (MyException& e) {
		cout << e.what() << endl;
	}
	catch (int& i) {
		cout << "Bad news: " << i << endl;
	}
	catch (char* c) {
		cout << c << endl;
	}
	catch (...) {
		printf("something bad happened");
	}

	system("pause");
	return 0;
}