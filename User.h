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
	
	User();


private:

/* FIELDS */
	
	std::string name;
	int allCount;
	std::vector<std::string> kin;
	std::vector<std::string> friends;
	std::vector<std::string> coworkers;

/* METHODS */
	
	/* Returns user name */	
	std::string getName();

	int getCount();

	void viewAll(); 

	void viewKin();	

	void viewFriends();
	
	void viewCoworkers();
};

#endif
