#include <string>
#include <iostream>
#include <sstream>
#include "Media.h"
#include <fstream>
using namespace std;

Media::Media() {
	type = ' ';
	title = "";
	keyName = "";
	rating = 0;
	genre = "";
	length = 0;
	yearReleased = 0;

}

Media::Media(char type, string title, string keyName, int rating, string genre, int length, int yearReleased) {
	this->type = type;
	this->title = title;
	this->keyName = keyName;
	this->rating = rating;
	this->genre = genre;
	this->length = length;
	this->yearReleased = yearReleased;
}

