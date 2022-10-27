#include <string>
#include <iostream>
#include <sstream>
#include "Media.h"
#include <fstream>
using namespace std;

Media::Media() {
	type = ' ';
	title = "";
	rating = 0;
	genre = "";
	yearReleased = 0;

}

Media::Media(char type, string title, int rating, string genre, int yearReleased) {
	this->type = type;
	this->title = title;
	this->rating = rating;
	this->genre = genre;
	this->yearReleased = yearReleased;
}

int readDataFile(ifstream fin, ofstream fout, vector<Media> m) {
	fin.open("mediaList.csv");
	string line, tempStr;
	vector<Media> row;
	if (!fin.is_open()) {
		cout << "File did not open" << endl;
		return -1;
	}

	getline(fin, line);
	while (fin.good()) {
		stringstream ss(line);
		row.clear();

		while (getline(ss, tempStr, ',')) {
			row.push_back(tempStr)
		}
	}
}
char printMenu() {}
void printBookList(vector<Media> m) {}
void printSong(vector<Media> m) {}
void printMovieList(vector<Media> m) {}
void printList(vector<Media> m) {}
void printTotals() {}
void addContent(vector<Media>& m) {}