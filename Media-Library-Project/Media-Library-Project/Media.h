#pragma once
#include <string>
#include <vector>
using namespace std;
class Media {
private:
	char type;
	string title;
	string keyName;
	int rating;
	string genre;
	int length;
	int yearReleased;

public:
	Media() {}

	Media(char type, string title, int rating, string genre, int yearReleased) {}

	char getType() { return type; }
	string getTitle() { return title; }
	string getKeyName() { return keyName; }
	int getRating() { return rating; }
	string getGenre() { return genre; }
	int getLength() { return length; }
	int getYearReleased() { return yearReleased; }

	void setType(char c) { type = c; }
	void setTitle(string s) { title = s; }
	void setKeyName(string s) { keyName = s; }
	void setRating(int i) { rating = i; }
	void setGenre(string s) { genre = s; }
	void setLength(int i) { length = i; }
	void setYearReleased(int i) { yearReleased = i; }

	int readDataFile(ifstream fin, ofstream fout, vector<Media> m);
	char printMenu();
	void printBookList(vector<Media> m);
	void printSong(vector<Media> m);
	void printMovieList(vector<Media> m);
	void printList(vector<Media> m);
	void printTotals();
	void addContent(vector<Media>& m);

};