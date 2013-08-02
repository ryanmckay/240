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


//-----------------------------------
timeval begin;
gettimeofday(&begin, NULL);
b1 = begin.tv_usec;

/* create FriendFace object */
FriendFace f1 = FriendFace(inFile);

gettimeofday(&begin, NULL);
b2 = begin.tv_usec;
cout << "Building FriendFace object took: " << ((b2-b1)*100)/CLOCKS_PER_SEC << " seconds.\n" << endl;

//-----------------------------------
gettimeofday(&begin, NULL);
b1 = begin.tv_usec;

cout << "Viewing Kin " << endl;
f1.userVec.at(0).viewKin();
cout << endl;

gettimeofday(&begin, NULL);
b2 = begin.tv_usec;
cout << "viewKin took: " << ((b2-b1)*100)/CLOCKS_PER_SEC << " seconds.\n" << endl;

//-----------------------------------

//-----------------------------------


//-----------------------------------
/* Test */
gettimeofday(&begin, NULL);
b1 = begin.tv_usec;

cout << "Listing users..." << endl;
f1.listUsers();
cout << endl;

gettimeofday(&begin, NULL);
b2 = begin.tv_usec;
cout << "List users took: " << ((b2-b1)*100)/CLOCKS_PER_SEC << " seconds.\n" << endl;
//-----------------------------------


/*menu*/
cout << endl << endl;
cout << "     \033[1;31m    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\033[0m\n" << endl;
cout << "             Welcome to FriendFace(patent pending)                  " << endl;
cout << "         You have been selected for pre-alpha testing.              " << endl;
cout << "     \033[1;31m~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\033[0m\n" << endl;

cout << "\t What would you like to do?" << endl;
cout << "\t\t|1. Log in\n";
cout << "\t\t|2. Show all users\n";
cout << "\t\t|3. Quit\n";
cout << "\t\t|4. Dance\n";


return 0;
};
