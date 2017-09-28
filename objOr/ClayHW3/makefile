CC = g++
CFLAGS = -g
OBJECTS = clayHW2.o grid.o WaterVehicle.o Submarine.o
MAIN = ClayHW2

all : main zipIt clean

main : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(MAIN)

%.o : %.cpp
	$(CC) $(CFLAGS) -c $<

clean :
	rm $(OBJECTS)

zipIt :
	zip -r $(MAIN) *.cpp *.h README makefile

