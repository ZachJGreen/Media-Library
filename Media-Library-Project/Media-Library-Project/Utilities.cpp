#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>
#include "Utilities.h"
#include "Media.h"

int readDataFile(string infile, string outfile, vector<Media>& m) {
	ifstream fin;
	ofstream fout;

	fin.open(infile);
	fout.open(outfile);

	string line, tempStr;
	vector<string> row;
	
	if (!fin.is_open()) {
		cout << "File did not open" << endl;
		return -1;
	}


	do {
		getline(fin, line);
		char t;
		string tit, k, g;
		int r, y, l;
		stringstream ss(line);
		row.clear();

		while (getline(ss, tempStr, ',')) {
			row.push_back(tempStr);
		}
		t = row[0][0];

		switch (t) {
		case 'M': case 'S': case 'B':
			break;
		default:
			getline(fin, line);
			continue;
		}

		try {
			r = stoi(row[3]);
			l = stoi(row[5]);
			y = stoi(row[6]);
		}
		catch (invalid_argument& e) {
			fout << line << endl;
			fout << "stoi invalid" << endl << endl;
			continue;
		}

		
		tit = row[1];
		k = row[2];
		g = row[4];

		Media tempMedia(t, tit, k, r, g, l, y);
		m.push_back(tempMedia);

		switch (t) {
		case 'M':
			Media::numMovies++;
			break;
		case 'S':
			Media::numSongs++;
			break;
		case 'B':
			Media::numBooks++;
			break;
		default:
			break;
		}
	} while (fin.good());
	fin.close();
	fout.close();
	return 1;
}
char printMenu() {
	cout << endl << "Welcome to the Media Library" << endl << endl;
	cout << "MENU CHOICES" << endl;
	cout << "M - Print Movie List\n" 
		 << "B - Print Book List\n" 
		 << "S - Print Song List\n" 
		 << "A - Print All Media\n" 
		 << "N - Add New Media\n" 
		 << "T - Print Media Counts\n" 
		 << "Q - Quit\n" << endl;

	char c;
	
	cout << "Enter your choice: ";
	cin >> c;
	c = toupper(c);
	cout << endl;

	switch (c) {
	case 'M': case 'B': case 'S': case 'A': case 'N': case 'T': case 'Q':
		return c;
	default:
		cout << "Invalid Option." << endl;
		return '-1';
	}

	
}
void printBookList(vector<Media> m) {
	for (int i = 0; i < m.size(); i++) {
		if (m[i].getType() == 'B') {
			cout << left << setw(40)
				<< m[i].getTitle()
				<< "|" 
				<< setw(40)
				<< m[i].getKeyName() 
				<< "|" 
				<< right << setw(2)
				<< m[i].getRating() 
				<< "|" 
				<< left << setw(25)
				<< m[i].getGenre() 
				<< "|" 
				<< right << setw(4)
				<< m[i].getLength() 
				<< "|" 
				<< setw(4)
				<< m[i].getYearReleased()
				<< endl;
		}
	}
	cout << endl << endl;
}
void printSongList(vector<Media> m) {
	for (int i = 0; i < m.size(); i++) {
		if (m[i].getType() == 'S') {
			cout << left << setw(40)
				<< m[i].getTitle()
				<< "|"
				<< setw(40)
				<< m[i].getKeyName()
				<< "|"
				<< right << setw(2)
				<< m[i].getRating()
				<< "|"
				<< left << setw(25)
				<< m[i].getGenre()
				<< "|"
				<< right << setw(4)
				<< m[i].getLength()
				<< "|"
				<< setw(4)
				<< m[i].getYearReleased()
				<< endl;
		}
	}
	cout << endl << endl;
}
void printMovieList(vector<Media> m) {
	for (int i = 0; i < m.size(); i++) {
		if (m[i].getType() == 'M') {
			cout << left << setw(40)
				<< m[i].getTitle()
				<< "|"
				<< setw(40)
				<< m[i].getKeyName()
				<< "|"
				<< right << setw(2)
				<< m[i].getRating()
				<< "|"
				<< left << setw(25)
				<< m[i].getGenre()
				<< "|"
				<< right << setw(4)
				<< m[i].getLength()
				<< "|"
				<< setw(4)
				<< m[i].getYearReleased()
				<< endl;
		}
	}
	cout << endl << endl;
}
void printList(vector<Media> m) {
	for (int i = 0; i < m.size(); i++) {
		cout << left << setw(40)
			<< m[i].getTitle()
			<< "|"
			<< setw(40)
			<< m[i].getKeyName()
			<< "|"
			<< right << setw(2)
			<< m[i].getRating()
			<< "|"
			<< left << setw(25)
			<< m[i].getGenre()
			<< "|"
			<< right << setw(4)
			<< m[i].getLength()
			<< "|"
			<< setw(4)
			<< m[i].getYearReleased()
			<< endl;
		
	}
	cout << endl << endl;
}
void printTotals() {
	cout << right << setw(2) << "#" << " " << left << setw(5) << "Type" << endl;
	cout << right << setw(2) << Media::numMovies << " " << left << setw(6) << "Movies" << endl;
	cout << right << setw(2) << Media::numBooks << " " << left << setw(6) << "Books" << endl;
	cout << right << setw(2) << Media::numSongs << " " << left << setw(6) << "Songs" << endl;
	cout << right << setw(2) << Media::numSongs + Media::numMovies + Media::numBooks << " " << left << setw(6) << "Items" << endl;
}
void addContent(vector<Media>& m) {
	char type;
	string title, keyName, genre, tempRating, tempLength, tempYear;
	int rating, length, year;
	
	cout << "Enter Media Type ((M)ovie, (B)ook, (S)ong): ";
	cin >> type;
	type = toupper(type);
	

	cout << "Enter Title: ";
	cin.ignore();
	getline(cin, title);

	cout << "Enter Name (Artist, Author, Director, etc.): ";
	cin.ignore();
	getline(cin, keyName);

	cout << "Enter Genre: ";
	cin.ignore();
	getline(cin, genre);

	cout << "Enter Rating: ";
	cin >> tempRating;

	cout << "Enter Length: ";
	cin >> tempLength;

	cout << "Enter Year Released: ";
	cin >> tempYear;

	try {
		rating = stoi(tempRating);
		length = stoi(tempLength);
		year = stoi(tempYear);
	}
	catch (invalid_argument& e) {
		cout << "Invalid input. Cancelling content addition." << endl;
		return;
	}
	if (type == 'M' || type == 'B' || type == 'S') {
		Media addM(type, title, keyName, rating, genre, length, year);
		m.push_back(addM);
		switch (type) {
		case 'M':
			Media::numMovies++;
			break;
		case 'B':
			Media::numBooks++;
			break;
		case 'S':
			Media::numSongs++;
			break;
		}
	}
	else
		cout << "Invalid input. Cancelling content addition." << endl;

}