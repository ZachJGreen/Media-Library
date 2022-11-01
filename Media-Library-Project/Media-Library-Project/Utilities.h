#pragma once
#include <fstream>
#include <vector>
#include "Media.h"

int readDataFile(string infile, string outfile, vector<Media>& m);
//pre:  Accepts string names of input/output files and empty Media vector
//post: Reads the data from csv file and loads the objects into a vector<Media>. Produces an error report of any records that have errors
char printMenu();
//pre:  None
//post: Prints the menu so user can choose from the options. Verifies that a correct option is chosen and returns the char
void printBookList(vector<Media> m);
//pre:  None
//post: Print the partial list of books
void printSongList(vector<Media> m);
//pre:  None
//post: Print the partial list of songs
void printMovieList(vector<Media> m);
//pre:  None
//post: Print the partial list of movies
void printList(vector<Media> m);
//pre:  None
//post: Print the full list
void printTotals();
//pre:  None
//post: Print the total count of movies, books, songs, and items in library
void addContent(vector<Media>& m);
//pre:  None
//post: Prompt user input with respect to corresponding instruction and push into the vector<Media>. Cancel if input is invalid.