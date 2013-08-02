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
		/* count is used first as totalUsers, then connectionCount for
		each user */
		int userCount, connectionCount;
		string temp, temp2;
		
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
		ss >> userCount;
		cout << "total users: " << userCount << endl;

		/* Create a user object for each user.
		We will fill in their connections after. */
		for( int i=0 ; i < userCount ; i++ ) {
			getline(inFile,temp);
			User u = User(temp);
			userVec.push_back(u);	
		}
		
		/* Start filling each user's connections */
		while( userCount > 0 ) {
			getline(inFile,temp,',');
			getline(inFile,temp2);
			trim(temp2);
			
			/* clearing ss */
			ss.str("");
			ss.clear();
			
			ss.str(temp2);
			ss >> connectionCount;
			
			//cout << "currentUser: " << temp << " | connectionCount: " << connectionCount << endl;
			/* grab correct user object */
			User* target;
			int found = 0;
			vector<User>::iterator it = userVec.begin();
			while(!found && it!=userVec.end()) {
				if( temp == userVec.at(it-userVec.begin()).name ) {
					target = &userVec.at(it-userVec.begin());
					found = 1;
				}
				else
					it++;
			}
			
			/* fill the user's connection vectors */
			char type;
			while( connectionCount > 0 ) {
				/* temp holds connectionName, temp2 a char for connection Type */
				getline(inFile,temp,',');
				getline(inFile,temp2);
				trim(temp2);
				type = temp2.at(0);
				
				switch(type) {
					case 'C' :
						(*target).addCoworker(temp);
						break;
					case 'K' :
						(*target).addKin(temp);
						break;
					default :
						(*target).addFriend(temp);
						break;
				}	
					
				connectionCount--;	
			}
			userCount--;
		}
	}

/* HELPER METHODS */

	/* Trim right and left white-space for string */
	void FriendFace::trim(string& s) {
		size_t i = s.find_first_not_of(" \t");
		s.erase(0, i);
		i = s.find_last_not_of(" \t");
		if (string::npos != i)
		s.erase(i+1);
	}
	
	void FriendFace::listUsers() {
		for(vector<User>::iterator it = userVec.begin(); it != userVec.end(); it++){
			cout << userVec.at(it-userVec.begin()).name << endl;
		}
	}

