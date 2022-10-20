#include <string>
#include "Media.h"
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