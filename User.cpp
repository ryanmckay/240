#include <string>
#include <vector>
#include "User.h"
#include <stdio.h>
#include <iostream>
#include <sstream>

using namespace std;

User::User(string _name){
	name = _name;
	connections = 0;
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

void User::nonMutual() {
	cout << "called" << endl;
	int isFriend = 0, isKin = 0, isCoworker = 0;
	for(vector<User*>::iterator it = friends.begin() ; it != friends.end() ; it++) {
		cout << "hit" << endl;
		vector<User*>::iterator it2 = (*it)->friends.begin();
		while(!isFriend && it2 != (*it)->friends.begin()) {
			/* implies this user's name */
			if( name == (*it2)->name ) {
				isFriend = 1;
			}
			else
			   it++;
		}
		if(!isFriend) {
			cout << (*it)->name << " has not added " << name << " as a friend." << endl;
		}
	}
	for(vector<User*>::iterator it = kin.begin() ; it != kin.end() ; it++) {
		cout << "hit" << endl;
		vector<User*>::iterator it2 = (*it)->kin.begin();
		while(!isKin && it2 != (*it)->kin.begin()) {
			/* implies this user's name */
			if( name == (*it2)->name ) {
				isKin = 1;
			}
			else
				it++;
		}
		if(!isKin) {
			cout << (*it)->name << " has not added " << name << " as a friend." << endl;
		}
	}
	for(vector<User*>::iterator it = coworkers.begin() ; it != coworkers.end() ; it++) {
		cout << "hit" << endl;
		vector<User*>::iterator it2 = (*it)->coworkers.begin();
		while(!isCoworker && it2 != (*it)->coworkers.begin()) {
			/* implies this user's name */
			if( name == (*it2)->name ) {
				isCoworker = 1;
			}
			else
				it++;
		}
		if(!isCoworker) {
			cout << (*it)->name << " has not added " << name << " as a friend." << endl;
		}
	}


}

