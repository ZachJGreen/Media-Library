#include <iostream>
#include <vector>
#include "Media.h"
#include "Utilities.h"
using namespace std;

int Media::numBooks = 0;
int Media::numMovies = 0;
int Media::numSongs = 0;

int main()
{
    
    string infile = "mediaList.csv";
    string outfile = "report.txt";
    vector<Media> m;
    char option = printMenu();

    readDataFile(infile, outfile, m);

    while (option != 'Q') {
        
        switch (option) {
        case 'M':
            printMovieList(m);
            break;
        case 'B':
            printBookList(m);
            break;
        case 'S':
            printSongList(m);
            break;
        case 'A':
            printList(m);
            break;
        case 'N':
            addContent(m);
            break;
        case 'T':
            printTotals();
            break;
        case 'Q':
            break;
        }
        option = printMenu();
    }
}

