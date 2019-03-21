#include <string.h>
#include <iostream>
#include <cstdlib>
#include <exception>
#include <filesystem>
#include <fstream>

using namespace std;
std::string removeAll(std::string str, char c);
std::string removeAll(std::string str, char c[]);
std::string toLowercase(std::string str);

int main(int argc, char** argv) {
	ifstream file; // file stream object. I will close and open this a few times.
	string words[10]; // array containing the words to search for.
	int counts[] = { 0,0,0,0,0,0,0,0,0,0 }; // array of the counts of each word I guess. might remove this is a future revision (if I decide to make changes ever (probably won't))
	file.open("words.txt");
	vector<string> paragraph; // vector for contains all of the words from the paragraph to search
	char c[] = { '.', ',', '(',')' }; // list of characters to remove from the strings for comparisons
	if (file.is_open()) { // making sure words.txt was opened.

		for (int i = 0; file >> words[i]; i++) { // loop to read words.txt word by word.
			words[i] = removeAll(toLowercase(words[i]), c); // add the word to the list after stripping characters and making lowercase.
		}
		file.close(); // close words.txt so we can open a different file.
		file.open("paragraph.txt"); // open the paragraph so we can read the words into memory.
		if (file.is_open()) { // making sure paragraph.txt was opened.
			string t;
			while (file >> t) { // ? get all the words from paragraph.txt.

				paragraph.push_back(removeAll(toLowercase(t), c)); // push the new from the paragraph text file to the vector of strings after stripping non letter characters from the word.
			}
			file.close(); // close paragraph.txt because we are done reading from the file.
			for (int i = 0; i < 10; i++) {
				for (int n = 0; n < paragraph.size(); n++) {
					if (paragraph.at(n) == words[i]) { // compare the words
						counts[i]++; // if we have found one of the words increment it's counter.
					}
				}
				printf("\"%s\" found %i time(s)\n", words[i].c_str(), counts[i]); // printf the results.
			}
		}
	}

	system("pause");
	return 0;
}

std::string toLowercase(std::string str) { // makes strings lowercase.
	for (auto& ch : str)
	{
		ch = tolower(ch);
	}
	return str;
}

std::string removeAll(std::string str, char c[]) { // over load I wrote to make the removeAll function remove multiple characters from a string.
	for (int i = 0; c[i]; i++) {
		str = removeAll(str, c[i]);
	}
	return str;
}

std::string removeAll(std::string str, char c) { // found this function on stack overflow at https://stackoverflow.com/questions/20326356/how-to-remove-all-the-occurrences-of-a-char-in-c-string by Ricardo Pieper
	size_t offset = 0;
	size_t size = str.size();

	size_t i = 0;
	while (i < size - offset) {
		if (str[i + offset] == c) {
			offset++;
		}

		if (offset != 0) {
			str[i] = str[i + offset];
		}

		i++;
	}

	str.resize(size - offset);
	return str;
}