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
		viewKin();
		cout << endl;
		
		viewFriends();
		cout << endl;

		viewCoworkers();
		cout << endl;

	}

	void User::viewKin(){
		int count = 0;
		cout << "Family connection(s)" << endl;
		for(vector<string>::iterator it = kin.begin(); it != kin.end(); it++){
			cout << kin.at(it-kin.begin()) << endl;
			count ++;
		}
		if(!count)
			cout << "None." << endl;
		cout << endl;
	}

	void User::viewFriends(){
		int count = 0;
		cout << "Friend connection(s)" << endl;
		for(vector<string>::iterator it = friends.begin(); it != friends.end(); it++){
			cout << friends.at(it-friends.begin()) << endl;
			count++;
		}
		if(!count)
			cout << "None." << endl;
		cout << endl;
	}

	void User::viewCoworkers(){
		int count = 0;
		cout << "Co-Worker connection(s)" << endl;
		for(vector<string>::iterator it = coworkers.begin(); it != coworkers.end(); it++){
			cout << coworkers.at(it-coworkers.begin()) << endl;
			count++;
	    }
		if(!count)
			cout << "None." << endl;
		cout << endl;
	}


	void User::addKin(string name){
		kin.push_back(name);
	}

	void User::addFriend(string name){
		friends.push_back(name);
	}

	void User::addCoworker(string name){
		coworkers.push_back(name);
	}
