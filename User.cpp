#include <string>
#include <vector>
#include "User.h"
#include <stdio.h>
#include <iostream>
#include <sstream>

using namespace std;

	User::User(string _name){
		name = _name;
	}

	/*fill in other values after file read?*/

	int User::getConnections(){
		return connections;
	}

	void User::viewAll(){
		cout << "Family connection(s)" << endl;
		viewKin();
		cout << endl;
		
		cout << "Family connection(s)" << endl;
		viewFriends();
		cout << endl;

		cout << "Co-Worker connection(s)" << endl;
		viewCoworkers();
		cout << endl;

	}

	void User::viewKin(){
		for(vector<string>::iterator it = kin.begin(); it != kin.end(); it++){
			cout << kin.at(it-kin.begin()) << endl;
		}

	}

	void User::viewFriends(){
		for(vector<string>::iterator it = friends.begin(); it != friends.end(); it++){
			cout << friends.at(it-kin.begin()) << endl;
		}

	}

	void User::viewCoworkers(){
		for(vector<string>::iterator it = coworkers.begin(); it != coworkers.end(); it++){
			cout << coworkers.at(it-kin.begin()) << endl;
	    }

	}
