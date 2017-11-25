#SE MODIFY THE FOLLOWING 2 LINES
name    = Battleship Player Human Computer WaterVehicle Gameboard 
#####################################

#g++ -o Battleship Battleship.cpp Player.cpp Player.h Human.h Human.cpp
#	Computer.cpp Computer.h Gameboard.h Gameboard.cpp WaterVehicle.cpp
#	WaterVehicle.h Positions.txt

CC      = g++
CFLAGS  = -Wall
LFLAGS = -Wall

all: Battleship clean

compileIt: $(name).o
	$(CC) -o $@ $^ $(LFLAGS)

$(name).o: $(name).cpp
	$(CC) -c $(CFLAGS) $<

clean:
	rm $(name).o

#zipIt: 
#	zip -r $(name).zip $(name).cpp *.h makefile

