/* Andy Yee and Ryan McKay
Lab 07
User.h */

#ifndef USER_H
#define USER_H

#include <string>
#include <vector>

class User {

public:
	
/* CONSTRUCTOR */
	
	User(std::string name);


public:

/* FIELDS */
	
	std::string name;
	int connections;
	std::vector<std::string> kin;
	std::vector<std::string> friends;
	std::vector<std::string> coworkers;

/* METHODS */
	
	/* Returns user name */	
	std::string getName();

	int getConnections();

	/* view funcitons get called directly on the User */
	void viewAll(); 

	void viewKin();	

	void viewFriends();
	
	void viewCoworkers();
};

#endif
