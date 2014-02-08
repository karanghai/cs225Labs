# CS 225 Lab 02
# Written by Jack Toole Fall 2010

EXE = sketchify

OBJS = main.o rgbapixel.o png.o

COMPILER = g++
COMPILER_OPTS = -c -g -O0 -w
LINKER = g++
LINKER_OPTS = -lpng

all : $(EXE)

$(EXE) : $(OBJS)
	$(LINKER) $(OBJS) $(LINKER_OPTS) -o $(EXE)

main.o : main.cpp png.h
	$(COMPILER) $(COMPILER_OPTS) main.cpp
	
png.o : png.cpp png.h
	$(COMPILER) $(COMPILER_OPTS) png.cpp

rgbapixel.o : rgbapixel.cpp rgbapixel.h
	$(COMPILER) $(COMPILER_OPTS) rgbapixel.cpp

clean : 
	-rm -f *.o $(EXE) out.png

