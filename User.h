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
		std::vector<User*> kin;
		std::vector<User*> friends;
		std::vector<User*> coworkers;

		/* OTHER */
		
		struct Suggestion {
		   int weight;
		   User* u;
		   Suggestion( int _weight, User* _u ) :
		   weight( _weight), u( _u) { } ;
		};


		/* METHODS */

		/* Returns user name */	
		std::string getName();

		int getConnections();

		/* view funcitons get called directly on the User */
		void viewAll(); 

		void viewKin();	

		void viewFriends();

		void viewCoworkers();

		void addKin(User* connection);

		void addFriend(User* connection);

		void addCoworker(User* connection);

		void nonMutual(User *currentUser);

		void getSuggestions(User *currentUser);

		/* HELPER METHODS */

		bool nonMutualAux(User *currentUser, User *connection);

		void getSuggestionsAux(int weight, std::vector<Suggestion> &sugVec, std::vector<User*> &currentVector, User *currentUser);	
};

#endif
