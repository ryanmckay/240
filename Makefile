COMPILER = g++
FLAGS = -g -std=c++0x
OUTPUT_NAME = sub

all: FriendFace.o Driver.o User.o
	$(COMPILER) $(FLAGS) -o $(OUTPUT_NAME) FriendFace.o Driver.o User.o

FriendFace.o : FriendFace.cpp
	$(COMPILER) $(FLAGS) -c -Wall FriendFace.cpp

Driver.o : Driver.cpp
	$(COMPILER) $(FLAGS) -c -Wall Driver.cpp

User.o : User.cpp
	$(COMPILER) $(FLAGS) -c -Wall User.cpp


clean:
	rm -rf *.o $(OUTPUT_NAME)
