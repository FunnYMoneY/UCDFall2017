#SE MODIFY THE FOLLOWING 2 LINES
name    = ClayHW1
#####################################

CC      = g++
CFLAGS  = -Wall
LFLAGS = -Wall

all: ClayHW1 zipIt clean

compileIt: $(name).o
	$(CC) -o $@ $^ $(LDFLAGS)

$(name).o: $(name).cpp
	$(CC) -c $(CFLAGS) $<

clean:
	rm $(name).o

zipIt: 
	zip -r $(name).zip $(name).cpp *.h README makefile
