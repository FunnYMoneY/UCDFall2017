CC = g++
CFLAGS = -g
OBJECTS = main.o Animal.o Dog.o Fish.o Horse.o Monkey.o Lizard.o
MAIN = ClayHW4-1

all : main zipIt clean

main : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(MAIN)

%.o : %.cpp
	$(CC) $(CFLAGS) -c $<

clean :
	rm $(OBJECTS)

zipIt :
	zip -r $(MAIN) *.cpp *.h README makefile
