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
double b1;
double b2;
if(argc !=2) {
	cout << "Usage: ./exe textFile.txt" << endl;
	exit (-1);
}
else
	inFile = argv[1];

cout << endl << endl;


/* Create Object */
timeval begin;
gettimeofday(&begin, NULL);
b1 = begin.tv_usec;

FriendFace f1 = FriendFace(inFile);

gettimeofday(&begin, NULL);
b2 = begin.tv_usec;
cout << "Building FriendFace object took: " << ((b2-b1)*100)/CLOCKS_PER_SEC << " seconds.\n" << endl;

/* Call Menu */
f1.menuCall();

//----------------------------------
/* Time View Kin */
/**
gettimeofday(&begin, NULL);
b1 = begin.tv_usec;

cout << "Viewing Kin " << endl;
f1.userVec.at(0).viewKin();
cout << endl;

gettimeofday(&begin, NULL);
b2 = begin.tv_usec;
cout << "viewKin took: " << ((b2-b1)*100)/CLOCKS_PER_SEC << " seconds.\n" << endl;
*/

//-----------------------------------
/* Test */

/**
gettimeofday(&begin, NULL);
b1 = begin.tv_usec;

cout << "Listing users..." << endl;
f1.listUsers();
cout << endl;

gettimeofday(&begin, NULL);
b2 = begin.tv_usec;
cout << "List users took: " << ((b2-b1)*100)/CLOCKS_PER_SEC << " seconds.\n" << endl;
*/
//-----------------------------------

return 0;
};
