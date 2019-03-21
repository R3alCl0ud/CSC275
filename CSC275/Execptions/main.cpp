#include <string.h>
#include <iostream>
#include <cstdlib>
#include <exception>

using namespace std;

class MyException : std::exception { // Custom exception created for example purposes.

public:

	const char * what() const throw () {
		return "Uh, boss, I don't feel so good. I think someone used the number two";
	}
};

int main(int argc, char** argv) {
	int ti;
	cin >> ti;
	try {
		if (ti <= 0) printf("Something sane was entered: %i", ti);
		if (ti == 1) throw "less than 2 for some reason";
		if (ti == 2) throw MyException();
		if (ti >= 3) throw ti;
	}
	catch (MyException& e) {
		cout << e.what() << endl;
	}
	catch (int& i) {
		cout << "Bad news: wrong int: " << i << endl;
	}
	catch (char* c) {
		cout << c << endl;
	}
	catch (...) {
		printf("something bad happened, not sure what() went wrong.");
	}

	system("pause");
	return 0;
}