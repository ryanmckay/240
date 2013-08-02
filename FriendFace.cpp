#include "FriendFace.h"
#include <iostream> // for file parsing
#include <sstream> // converting from str to numbers

using namespace std;

/* NOTES


*/

/* CONSTRUCTOR */

	FriendFace::FriendFace(string file_name) {
		setup(userVec, file_name);	
	}


/* PRIVATE METHODS */

	/* File parsing and set up user vector */
	void FriendFace::setup(vector<User>& userVec, string file_name) {
		int totalUsers;
		string temp;
		
		cout << "Parsing file: " << file_name << "...";
		ifstream inFile(file_name.c_str());	
		
		/* Error if input not good */
		if(!inFile) {
			cout << "Error with file. Terminating." << endl;
			return;
		}
		cout << "OK." << endl;	
	
		/* Get first line, check # of users */
		getline(inFile,temp);
		stringstream ss(temp);
		ss >> totalUsers;
		cout << "total: " << totalUsers << endl;

		/* Create a user object for each user.
		We will fill in their connections after. */
		for( int i=0 ; i < totalUsers ; i++ ) {
			getline(inFile,temp);
			User u = User(temp);
			userVec.push_back(u);	
		}
	}

	void FriendFace::listUsers() {
		for(vector<User>::iterator it = userVec.begin(); it != userVec.end(); it++){
			cout << userVec.at(it-userVec.begin()).name << endl;
		}
	}

