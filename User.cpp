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

/* Prints out all non-mutual connections */
void User::nonMutual(User *currentUser) {
	/* Check mutuality of connections in friends vec */
	for( vector<User*>::iterator it = friends.begin() ; it != friends.end() ; it++ ) {
		/* dereferenced "it" once. passing a pointer to the connection (type User*) */
		if( !nonMutualAux(currentUser,(*it)))
			cout << (*it)->name << " has not added " << currentUser->name << " as a friend." << endl;
	}

	/* ... in kin vec */
	for( vector<User*>::iterator it = kin.begin() ; it != kin.end() ; it++ ) {
		/* dereferenced "it" once. passing a pointer to the connection (type User*) */
		if( !nonMutualAux(currentUser,(*it)))
			cout << (*it)->name << " has not added " << currentUser->name << " as family." << endl;
	}

	/* ... in coworkers vec*/
	for( vector<User*>::iterator it = coworkers.begin() ; it != coworkers.end() ; it++ ) {
		/* dereferenced "it" once. passing a pointer to the connection (type User*) */
		if( !nonMutualAux(currentUser,(*it)))
			cout << (*it)->name << " has not added " << currentUser->name << " as a coworker." << endl;
	}
}

/* Tests if a connection is mutual */
bool User::nonMutualAux(User *currentUser, User *connection ) {
	int mutual = 0;
//	cout << "Connection Passed : " << connection->name << endl;

	for( vector<User*>::iterator it = connection->friends.begin() ; it != connection->friends.end(); it++ ) {
		if( (*it) == currentUser )
			mutual = 1;
	}

	/* check other vectors if currentUser not found in connection's friends */

	if(!mutual) {
		for( vector<User*>::iterator it = connection->kin.begin() ; it != connection->kin.end(); it++ ) { 
			if( (*it) == currentUser ) 
				mutual = 1;
		}
	}

	if(!mutual) {
		for( vector<User*>::iterator it = connection->coworkers.begin() ; it != connection->coworkers.end(); it++ ) { 
			if( (*it) == currentUser ) 
				mutual = 1;
		}
	}
	
	if(mutual)
		cout << connection->name << " is mutual." << endl;
	return mutual;
}

