﻿// lab9.cpp : Defines the entry point for the console application.
// Lucas Manker

#include <iostream>
#include <map>
#include <string>
#include <fstream>

using namespace std;

void write(map<string, int>words, ofstream &stream);
map<string, int> insert(ifstream &stream);

int main()
{
	ifstream stream;
	ofstream outstream;
	stream.open("example.txt");
	outstream.open("output.txt");
	map <string, int> words = insert(stream);
	write(words, outstream);
    return 0;
}

void write(map<string, int>words, ofstream &stream) {
	map<string, int>::iterator it = words.begin();
	for (it = words.begin(); it != words.end(); it++) {
		while (it->second >= 0) {
			stream << it->first<<endl;
			it->second--;
		}
	}
	stream.close();
}

map<string, int> insert(ifstream &stream) {
	map<string, int> words;
	int count(0), unique(0);
	if (!stream.is_open()) {
		cout << "file not found!" << endl;
		return words;
	}
	string word;
	while (stream>>word) {
		if (words.count(word) > 0) {
			words.find(word)->second++;
			count++;
		}
		else {
			words.insert(pair<string, int>(word, 0));
			unique++;
			count++;
		}
	}
	cout << "==============File Information==============" << endl;
	cout << "Unique Words: " << unique << endl;
	cout << "Total Words: " << count << endl;
	cout << "============================================" << endl;
	stream.close();
	return words;
}
