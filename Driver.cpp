#include "User.h"
#include "FriendFace.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <sys/time.h> /* for calc. build time */

using namespace std;

int main(int argc, char** argv){

string inFile;

if(argc !=2) {
	cout << "Usage: ./exe textFile.txt" << endl;
	exit (-1);
}
else
	inFile = argv[1];

cout << endl << endl;


timeval begin;
gettimeofday(&begin, NULL);
double b1 = begin.tv_usec;

/* create FriendFace object */
FriendFace f1 = FriendFace(inFile);

int timeTest = (2^30) - (2^29);
timeTest = 0;
cout << "Time testing..." << timeTest << endl;

gettimeofday(&begin, NULL);
double b2 = begin.tv_usec;
cout << "Building FriendFace object took: " << ((b2-b1)*1000)/CLOCKS_PER_SEC << " seconds." << endl;

/*remember to time everything*/

/* Test */
f1.listUsers();


cout << endl << endl;
cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
cout << "         Welcome to FriendFace(patent pending)                      " << endl;
cout << "         You have been selected for pre-alpha testing.              " << endl;
cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

cout << "What would you like to do?" << endl;


return 0;
};
