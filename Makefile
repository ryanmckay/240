COMPILER = g++
FLAGS = -g -std=c++0x
OUTPUT_NAME = sub

all: FriendFace.o Driver.o
	$(COMPILER) $(FLAGS) -o $(OUTPUT_NAME) FriendFace.o Driver.o

FriendFace.o : FriendFace.cpp
	$(COMPILER) $(FLAGS) -c -Wall FriendFace.cpp

FriendFace.o : Driver.cpp
	$(COMPILER) $(FLAGS) -c -Wall Driver.cpp

clean:
	rm -rf *.o $(OUTPUT_NAME)
