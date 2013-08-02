#include "FriendFace.h"
#include <iostream> // for file parsing
#include <sstream> // converting from str to numbers

using namespace std;

/* NOTES


*/

/* CONSTRUCTOR */

	FriendFace::FriendFace() {
	
	}


/* PRIVATE METHODS */

	/* file parsing and set up user vector */
	void FriendFace::setup(string file_name) {
		int totalUsers;
		string temp;
		
		cout << "Parsing file: " << file_name << "...";
		ifstream inFile(file_name.c_str());	
		
		/* error if input not good */
		if(!inFile) {
			cout << "Error with file. Terminating." << endl;
			return;
		}
		cout << "OK." << endl;	
	
		/* getfirst line */
		getline(inFile,temp);
		stringstream ss(temp);
		ss >> totalUsers;
		cout << "total: " << totalUsers << endl;
	}

