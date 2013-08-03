#include "FriendFace.h"
#include <iostream> // for file parsing
#include <sstream> // converting from str to numbers
#include <unistd.h>
using namespace std;

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
				if(found){
					cout << "Logged in as: " << currentUserName << endl;
					loginMenu((*currentUser));
				}
				else
					cout << "User not found." << endl;			
			}

			/* Show all users */
			else if (choice == "2"){
				cout << "*Currently Registered Users*" << endl;
				listUsers();
			}

			/* Check if two users are connected */
			else if (choice == "3"){
				cout << "Not implemented yet." << endl;
			}

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
		cout << endl;
		cout << "\tLog in Menu" << endl;
		cout << "\t\t|1. Show all connections" << endl;
		cout << "\t\t|2. Show all friends" << endl;
		cout << "\t\t|3. Show all family" << endl;
		cout << "\t\t|4. Show all coworkers" << endl; 
		cout << "\t\t|5. Get suggested friends" << endl;
		cout << "\t\t|6. Show all non-mutual connections" << endl;
		cout << "\t\t|7. Log out and return to main menu" << endl;
		cout << "\t\t|8. Log out and quit" << endl;
		
		cout << "Input: ";
		getline(cin,choice);

		int loggedIn = 1;

		while(loggedIn){
			if(choice.size()>1)
				cout << "Invalid choice. (Enter a single character)" << endl;
			else if( choice=="1" )
				currentUser.viewAll();

			else if( choice=="2" )
				currentUser.viewFriends();

			else if( choice=="3" )
				currentUser.viewKin();
		
			else if( choice=="4" )
				cout << "Not implemented yet." << endl;	

			else if( choice=="5" )
				cout << "Not implemented yet." << endl;	

			else if( choice=="6" )
				cout << "Not implemented yet." << endl;
				
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


