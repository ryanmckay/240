#ifndef FACE_H
#define FACE_H

#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <cstring>
#include "User.h"

typedef std::string Friends;
typedef std::string Co_Workers;
typedef std::string Kin;

class FriendFace{

	public:

		std::vector<User> userVec;

		void setup(std::vector<User>& userVec, std::string file_name);
		

	public:

		FriendFace(std::string file_name);

		void fill_vector(std::string file_name);

		void showContacts();

		void getSuggestions();

		bool isConnected(User& user1, std::string user2);

		void menu();

		void quit();

		void trim(std::string& s);
		
		void listUsers();

		void menuCall();

		void loginMenu(User& currentUser);

		void suggested();
};
#endif

