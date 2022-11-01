#pragma once
#include <string>
#include <vector>
using namespace std;
class Media {
private:
	//Initialize private data members
	char type;
	string title;
	string keyName;
	int rating;
	string genre;
	int length;
	int yearReleased;

public:
	//Constructors
	Media();
	Media(char type, string title, string keyName, int rating, string genre, int length, int yearReleased);

	//Get value of private data members
	char getType() { return type; }
	string getTitle() { return title; }
	string getKeyName() { return keyName; }
	int getRating() { return rating; }
	string getGenre() { return genre; }
	int getLength() { return length; }
	int getYearReleased() { return yearReleased; }

	//Set value of private data members
	void setType(char c) { type = c; }
	void setTitle(string s) { title = s; }
	void setKeyName(string s) { keyName = s; }
	void setRating(int i) { rating = i; }
	void setGenre(string s) { genre = s; }
	void setLength(int i) { length = i; }
	void setYearReleased(int i) { yearReleased = i; }

	//Static variables for counting
	static int numMovies;
	static int numSongs;
	static int numBooks;

};

