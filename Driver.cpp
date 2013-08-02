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
	cout << "Error: No file give to be read." << endl;
	exit (-1);
}
else
	inFile = argv[1];

cout << endl << endl;

/*create friend object here*/

/*remember to time everything*/

cout << endl << endl;
cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
cout << "         Welcome to FriendFace(patent pending)                      " << endl;
cout << "         You have been selected for pre-alpha testing.              " << endl;
cout << endl << endl;
cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

cout << "What would you like to do?" << endl;



};
