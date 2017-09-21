CC = g++
CFLAGS = -g
OBJECTS = test.o functions.o
MAIN = test

all : main zipIt clean

main : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(MAIN)

%.o : %.cpp
	$(CC) $(CFLAGS) -c $<

clean :
	rm $(OBJECTS)

zipIt :
	zip -r $(MAIN) *.cpp *.h README makefile

