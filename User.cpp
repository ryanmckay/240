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
		for(vector<User*>::iterator it = kin.begin(); it != kin.end(); it++){
			cout << kin.at(it-kin.begin())->name << endl;
			count ++;
		}
		if(!count)
			cout << "None." << endl;
		cout << endl;
	}

	void User::viewFriends(){
		int count = 0;
		cout << "Friend connection(s)" << endl;
		for(vector<User*>::iterator it = friends.begin(); it != friends.end(); it++){
			cout << friends.at(it-friends.begin())->name << endl;
			count++;
		}
		if(!count)
			cout << "None." << endl;
		cout << endl;
	}

	void User::viewCoworkers(){
		int count = 0;
		cout << "Co-Worker connection(s)" << endl;
		for(vector<User*>::iterator it = coworkers.begin(); it != coworkers.end(); it++){
			cout << coworkers.at(it-coworkers.begin())->name << endl;
			count++;
	    }
		if(!count)
			cout << "None." << endl;
		cout << endl;
	}


	void User::addKin(User* connection){
		kin.push_back(connection);
	}

	void User::addFriend(User* connection){
		friends.push_back(connection);
	}

	void User::addCoworker(User* connection){
		coworkers.push_back(connection);
	}
