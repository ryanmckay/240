#include "FriendFace.h"
#include <iostream> // for file parsing
#include <sstream> // converting from str to numbers
#include <unistd.h>
#include <queue>
using namespace std;
int cCount = 0;//global var needed for isConnected. leave for now.
/* NOTES


 */

/* CONSTRUCTOR ========================================================= */

FriendFace::FriendFace(string file_name) {
	setup(userVec, file_name);	
}


/* PUBLIC METHODS ========================================================== */

/* Display menu after FriendFace object is set up */
void FriendFace::menuCall() {
	int running=1, found=0;
	string choice;
	string currentUserName;
	User* currentUser;

	cout << endl << endl;
	cout << "     \033[1;31m    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\033[0m\n";
	cout << "             Welcome to FriendFace(patent pending)                  " << endl;
	cout << "         You have been selected for pre-alpha testing.              " << endl;
	cout << "     \033[1;31m~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\033[0m\n" << endl;
	cout << "\t What would you like to do?" << endl;
	cout << "\t\t|1. Log in\n";
	cout << "\t\t|2. Show all users\n";
	cout << "\t\t|3. Check if two users are connected\n";
	cout << "\t\t|4. Quit\n";
	cout << "\t\t|5. Dance\n";

	while(running) {

		cout << endl << "Input: ";
		getline(cin, choice);
		cout << endl;

		if (choice.size() > 1)
			cout << "Invalid input." << endl;

		else if (choice.size() == 0)
			cout << "No input given." << endl;

		/* Login */
		else if (choice == "1"){
			while (!found){
				cout << "Enter q to quit." << endl;
				cout << "Name: ";
				getline(cin, currentUserName);
				if(currentUserName == "q")
					menuCall();
				else {
					for(vector<User>::iterator it = userVec.begin() ; it != userVec.end() ; it++) {
						if(currentUserName==userVec.at(it-userVec.begin()).name){
							currentUser = &userVec.at(it-userVec.begin());
							found = 1;
							break;	
						}
					}
				}
				if(!found)
					cout << "User not found." << endl << endl;
			}
			if(found){
				cout << "Logged in as: " << currentUserName << endl;
				loginMenu((*currentUser));
			}

		}

		/* Show all users */
		else if (choice == "2"){
			cout << "*Currently Registered Users*" << endl;
			listUsers();
		}

		/* Check if two users are connected */
		else if (choice == "3"){
			string user1str;
			string user2str;
			User* user1;
			User* user2;
			int found1 = 0;
			int found2 = 0;
			int same = 0;
			cout << "Enter users to check.\n";								  				 
			while(!found1){
				cout << "First user: ";
				getline(cin, user1str);

				if(user1str == "q")
					menuCall();
				else{
					for(vector<User>::iterator it = userVec.begin() ; it != userVec.end() ; it++){
						if(user1str==userVec.at(it-userVec.begin()).name){
							user1 = &userVec.at(it-userVec.begin());
							found1 = 1;
							break;
						}
					}
				}
				if(!found1)
					cout << "User not found." << endl << endl;
			}//end of found1 loop

			while(!found2 && !same){
				cout << "Second user: ";
				getline(cin, user2str);

				if(user2str == "q")
					menuCall();

				else{
					for(vector<User>::iterator it= userVec.begin(); it != userVec.end(); it++){
						if(user2str==userVec.at(it-userVec.begin()).name){
							user2 = &userVec.at(it-userVec.begin());
							if(user1 == user2){
								same = 1;
							}
							else{
								found2 = 1;
								same = 0;
								break;
							}
						}
					}
				}
				if(!found2 && same)
					cout << "Error: Can't compare user to itself." << endl;
				else if(!found2)
					cout << "User not found." << endl << endl;

				same = 0;
			}//end of found2 loop  

			cout << "User1: " << user1str << endl;
			cout << "User2: " << user2str << endl;
			cout << "And now to actually check..." << endl;

			/*			cout << "connections: ";
						/(&user1->getConnections());
						cout << "connections of user 1....: ";
						cout << user1->getConnections();//doesn't work
						cout << endl;
			 */
			if(isConnected(*user1, user2str)){
				cout << "These two users are connected." << endl;
			}
			else
				cout << "These two users are not connected." << endl;

		}//end of choice 3

		/* Quit */
		else if (choice == "4") {
			cout << "Thank you for using FriendFace." << endl;
			running = 0;
			exit(-1);
		}


		else if (choice == "5"){
			cout << "<('o'<) " << endl << endl;
			sleep(1);
			cout << "^( '-' )^ " << endl << endl;
			sleep(1);
			cout << "(>‘o’)> " << endl << endl;
			sleep(1);
			cout << "v( ‘.’ )v " << endl << endl;
			sleep(1);
			cout << "<(' .' )> " << endl << endl;
			sleep(1);
			cout << "<('.'<) " << endl << endl;
			sleep(1);
			cout << "^( '.' )^ " << endl  << endl;
			sleep(1);
			cout << "(>‘.’)> " << endl << endl;
			sleep(1);
			cout << "v( ‘.’ )v " << endl << endl;
			sleep(1);
			cout << "<('.' )> " << endl << endl;
			cout << endl;
			cout << "Rock on." << endl;
		}	
	}
}

void FriendFace::loginMenu(User& currentUser){
	string choice;
	cout << "Connections: " << currentUser.getConnections() << endl;

	cout << endl;
	cout << "\tLog in Menu" << endl;
	cout << "\t\t|1. Show all connections" << endl;
	cout << "\t\t|2. Show all friends" << endl;
	cout << "\t\t|3. Show all family" << endl;
	cout << "\t\t|4. Show all coworkers" << endl; 
	cout << "\t\t|5. Get suggested friends" << endl;
	cout << "\t\t|6. Show all non-mutual connections" << endl;
	cout << "\t\t|7. Log out and return to main menu" << endl;
	cout << "\t\t|8. Log out and quit" << endl << endl;
	int loggedIn = 1;
	while(loggedIn){
		cout << "Input: ";
		getline(cin,choice);
		cout << endl;

		if(choice.size()>1)
			cout << "Invalid choice. (Enter a single character)" << endl;
		else if( choice=="1" )
			currentUser.viewAll();

		else if( choice=="2" )
			currentUser.viewFriends();

		else if( choice=="3" )
			currentUser.viewKin();

		else if( choice=="4" )
			currentUser.viewCoworkers();	

		else if( choice=="5" )
			/* nonMutual makes use of pointer equality */
			currentUser.getSuggestions(&currentUser);

		else if( choice=="6" )
			/* nonMutual makes use of pointer equality */
			currentUser.nonMutual(&currentUser);

		else if( choice=="7" ){
			loggedIn = 0;
			menuCall();	
		}

		else if( choice=="8" ){
			loggedIn = 0;
			cout << "Thank you for using FriendFinder." << endl;
			cout << "Goodbye." << endl;
			exit(-1);
		}

		else
			cout << "Invalid choice. " << endl;
	}
}	

/* PRIVATE METHODS ========================================================= */

/* File parsing and set up user vector */


void FriendFace::setup(vector<User>& userVec, string file_name) {
	int userCount, connectionCount, found=0;
	User* currentUser, *connection;
	string temp, temp2;
	char type;

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
		if(!isdigit(temp2[0])) {
			cout << "Error detected in input file. Terminating" << endl;
			exit(-1);
		}
		ss >> connectionCount;
		
		//	cout << "currentUser: " << temp << " | connectionCount: " << connectionCount << endl;
		/* grab correct user object */
		found = 0;
		vector<User>::iterator it = userVec.begin();
		while(!found && it!=userVec.end()) {
			if( temp == userVec.at(it-userVec.begin()).name ) {
				currentUser = &userVec.at(it-userVec.begin());
				currentUser->connections = connectionCount;
//				cout << "grabbed " << currentUser->name << endl;
				found = 1;
			}
			else
				it++;
		}

		/* fill the grabbed user's connection vectors */
		while( connectionCount > 0 ) {
			/* temp holds connectionName, temp2 a char for connection Type */
			getline(inFile,temp,',');
			getline(inFile,temp2);
			trim(temp2);
			type = temp2.at(0);

			found = 0;
			vector<User>::iterator it = userVec.begin();
			while(!found && it!=userVec.end()) {
				if( temp == userVec.at(it-userVec.begin()).name ) {
					connection = &userVec.at(it-userVec.begin());
					found = 1;
				}
				else
					it++;
			}

			switch(type) {
				case 'C' :
					(*currentUser).addCoworker(connection);
					break;
				case 'K' :
					(*currentUser).addKin(connection);
					break;
				default :
					//				cout << "Friend added to " << temp << endl;
					(*currentUser).addFriend(connection);
					break;
			}	

			connectionCount--;	
		}
		userCount--;
//		cout << "usercount: " << userCount << endl;
	}
}

bool FriendFace::isConnected(User& user1, string user2){
	int found = 0;
	vector<User*>::iterator it;
	cout << "count: " << cCount << endl;

	if(!found && cCount !=user1.getConnections()){
		for(it = user1.coworkers.begin(); it !=user1.coworkers.end() ; it++){
			cout << "current user: " << (*it)->name << endl;
			cout << "current count in loop: " << cCount << endl;
			if((*it)->name == user2){
				cout << "found it." << endl;
				found = 1;
				break;
			}
			cCount++;
		}
	}

	if(!found && cCount!=user1.getConnections()){
		for(it = user1.kin.begin(); it !=user1.kin.end(); it++){
			cout << "current user 2: " << (*it)->name << endl;

			if((*it)->name == user2){
				found = 1;
				break;
			}
			cCount++;
		}
	}

	if(!found && cCount!=user1.getConnections()){
		for(it = user1.friends.begin(); it !=user1.friends.end(); it++){
			cout << "current user 3: " << (*it)->name << endl;
			if((*it)->name == user2){
				found = 1;
				break;
			}
			cCount++;
		}
	}
	
	if(!found && cCount !=user1.getConnections()){
		isConnected(**it, user2);
	}

return found;
}	

/* HELPER METHODS ========================================================= */

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

