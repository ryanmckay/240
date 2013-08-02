#ifndef FACE_H
#define FACE_H

#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <cstring>

typedef std::string Friends;
typedef std::string Co_Workers;
typedef std::string Kin;

class FriendFace{

	private:


	public:

		FriendFace();

		void fill_vector(std::string file_name);

		void showContacts();

		void getSuggestions();

		bool connected(Person person, Person person);

		void nonMutual();

		void menu();

		void quit();


};
#endif

