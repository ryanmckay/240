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


void User::getSuggestions(User *currentUser) {
	vector<Suggestion> suggestionVec;
	
	/* get suggestions from currentUser's friends */
	for( vector<User*>::iterator it = friends.begin() ; it != friends.end() ; it++ )
	{
		/* fof weight 1 */
		if( !(*it)->friends.empty() ) {
			getSuggestionsAux(1 , suggestionVec , (*it)->friends , currentUser);
		}
		/* kof weight 3 */
		if( !(*it)->kin.empty() ) {
			getSuggestionsAux(3 , suggestionVec , (*it)->kin , currentUser);
		}
		/* cof weight 7 */
		if( !(*it)->coworkers.empty() ) {
			getSuggestionsAux(7 , suggestionVec , (*it)->coworkers , currentUser);			
		}
	}
	
	/* ... currentUser's family */
	for( vector<User*>::iterator it = kin.begin() ; it != kin.end() ; it++ )
	{
		/* fok weight 2 */
		if( !(*it)->friends.empty() ) {
			getSuggestionsAux(2 , suggestionVec , (*it)->friends , currentUser);
		}
		/* kok weight 4 */
		if( !(*it)->kin.empty() ) {
			getSuggestionsAux(4 , suggestionVec , (*it)->kin , currentUser);
		}
		/* cok weight 8 */
		if( !(*it)->coworkers.empty() ) {
			getSuggestionsAux(8 , suggestionVec , (*it)->coworkers , currentUser);
		}
	}

	/* ... currentUser's coworkers */	
	for( vector<User*>::iterator it = coworkers.begin() ; it != coworkers.end() ; it++ )
	{
		/* foc weight 6 */
		if( !(*it)->friends.empty() ) {
			getSuggestionsAux(6 , suggestionVec , (*it)->friends , currentUser);
		}
		/* koc weight 9 */
		if( !(*it)->kin.empty() ) {
			getSuggestionsAux(9 , suggestionVec , (*it)->kin , currentUser);
		}
		/* coc weight 5 */
		if( !(*it)->coworkers.empty() ) {
			getSuggestionsAux(5 , suggestionVec , (*it)->coworkers , currentUser);
		}
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

void User::getSuggestionsAux(int weight, vector<Suggestion> &vec,  vector<User*> &currentVector, User *currentUser) {
	cout << weight << endl;	
}
