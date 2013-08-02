#include <string>
#include <vector>
#include "User.h"
#include <stdio.h>
#include <iostream>
#include <sstream>

using namespace std;

	User::User(string name){
		this.name = name;
	}

	/*fill in other values after file read?*/

	int User::getCount(){
		return count;
	}

	void User::viewAll(){
		cout << "Family connection(s)" << endl;
		viewKin();
		cout << endl;
		
		cout << "Family connection(s)" << endl;
		viewFriends();
		cout << endl;

		cout << "Co-Worker connection(s)" << endl;
		viewCoWorkers();
		cout << endl;

	}

	void User::viewKin(){
		for(vector<string>::iterator it = kin.begin(); it != kin.end(); it++){
			cout << kin.at(it) << endl;
		}

	}

	void User::viewFriends(){
		for(vector<string>::iterator it = friends.begin(); it != friends.end(); it++){
			cout << friends.at(it) << endl;
		}

	}

	void User::viewCoWorkers(){
		for(vector<string>::iterator it = coworkers.begin(); it != coworkers.end(); it++){
			cout << coworkers.at(it) << endl;
	    }

	}
