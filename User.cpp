#include <string>
#include <vector>
#include "User.h"
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <algorithm>

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
	vector<Suggestion> sugVec;
	
	/* get suggestions from currentUser's friends */
	for( vector<User*>::iterator it = friends.begin() ; it != friends.end() ; it++ )
	{
		/* fof weight 1 */
		if( !(*it)->friends.empty() ) {
			getSuggestionsAux(1 , sugVec , (*it)->friends , currentUser);
		}
		/* kof weight 3 */
		if( !(*it)->kin.empty() ) {
			getSuggestionsAux(3 , sugVec , (*it)->kin , currentUser);
		}
		/* cof weight 7 */
		if( !(*it)->coworkers.empty() ) {
			getSuggestionsAux(7 , sugVec , (*it)->coworkers , currentUser);			
		}
	}
	
	/* ... currentUser's family */
	for( vector<User*>::iterator it = kin.begin() ; it != kin.end() ; it++ )
	{
		/* fok weight 2 */
		if( !(*it)->friends.empty() ) {
			getSuggestionsAux(2 , sugVec , (*it)->friends , currentUser);
		}
		/* kok weight 4 */
		if( !(*it)->kin.empty() ) {
			getSuggestionsAux(4 , sugVec , (*it)->kin , currentUser);
		}
		/* cok weight 8 */
		if( !(*it)->coworkers.empty() ) {
			getSuggestionsAux(8 , sugVec , (*it)->coworkers , currentUser);
		}
	}

	/* ... currentUser's coworkers */	
	for( vector<User*>::iterator it = coworkers.begin() ; it != coworkers.end() ; it++ )
	{
		/* foc weight 6 */
		if( !(*it)->friends.empty() ) {
			getSuggestionsAux(6 , sugVec , (*it)->friends , currentUser);
		}
		/* koc weight 9 */
		if( !(*it)->kin.empty() ) {
			getSuggestionsAux(9 , sugVec , (*it)->kin , currentUser);
		}
		/* coc weight 5 */
		if( !(*it)->coworkers.empty() ) {
			getSuggestionsAux(5 , sugVec , (*it)->coworkers , currentUser);
		}
	}

#if 1 // TEST CODE TEST CODE TEST CODE
	cout << "Suggestions" << endl;
	int count = 1;
	for( vector<Suggestion>::iterator sit = sugVec.begin() ; sit != sugVec.end() ; sit++) {
		cout << count << ". " << (*sit).u->name << " : " << "(weight)" << (*sit).weight << endl;
		count++;
	}
#endif // TEST CODE TEST CODE TEST CODE

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
			if( (*it) == currentUser ){ 
				mutual = 1;
			}
		}
	}
	
	if(mutual)
		cout << connection->name << " is mutual." << endl;

	return mutual;
	
}

void User::getSuggestionsAux(int weight, vector<Suggestion> &sugVec,  vector<User*> &currentVector, User *currentUser) {
	
	for( vector<User*>::iterator it = currentVector.begin() ; it != currentVector.end() ; it++ ) {
		if( (*it) != currentUser ) {
			if(sugVec.empty())//don't need to check for duplicates it empty
				{
					Suggestion s = Suggestion(weight, (*it));
					sugVec.push_back(s);
				}
			else {//check for duplicates
				int exists = 0;
				vector<Suggestion>::iterator sit = sugVec.begin();
				while(!exists && sit != sugVec.end())
				{
					if( (*sit).u == (*it) )
						exists = 1;
					else 
						sit++;
				}
				if(!exists && sit == sugVec.end())
				{
						Suggestion s = Suggestion(weight, (*it));
						sugVec.push_back(s);
				}
			}
		}
	}
	if(!sugVec.empty()){
		sort(sugVec.begin(), sugVec.end());
	}
}
