#
# USING THIS MAKEFILE:
#
#  'make quackfun' - creates test executable
#

OBJS = main.o exercises.o
EXENAME = quackfun 

CC = g++
CCOPTS = -g -O0 -Wall
LINK = g++
LINKOPTS = -o 

all : $(EXENAME)

$(EXENAME) : $(OBJS)
	$(LINK) $(LINKOPTS) $(EXENAME) $(OBJS)

main.o : main.cpp quackfun.h quackfun.cpp
	$(CC) -c $(CCOPTS) main.cpp

exercises.o : exercises.cpp exercises.h
	$(CC) -c $(CCOPTS) exercises.cpp

clean : 
	rm -f *.o $(EXENAME)

tidy: clean
	rm -rf ./doc
