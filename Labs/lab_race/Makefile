# When compiled with g++, the Intel tools show incorrect data races, so we are compiling with icc

EXENAME = lab_race

#COMPILER = g++ -fopenmp 
COMPILER = icpc -openmp 
COMPILER_OPTS = -c -g -O0 # -Werror-all
#LINKER = g++ -fopenmp -lpng
LINKER = icpc -openmp -lpng

MAIN_OBJS = point.o rgbapixel.o png.o collage.o table.o flipper.o shifter.o animation.o main.o

all: $(EXENAME)

$(EXENAME) : $(MAIN_OBJS)
	$(LINKER) $(MAIN_OBJS) -o $(EXENAME)

main.o : png.o collage.o table.o main.cpp
	$(COMPILER) $(COMPILER_OPTS) main.cpp

table.o : table.h table.cpp
	$(COMPILER) $(COMPILER_OPTS) table.cpp

shifter.o : png.o animation.o shifter.h shifter.cpp
	$(COMPILER) $(COMPILER_OPTS) shifter.cpp

animation.o : animation.h animation.cpp
	$(COMPILER) $(COMPILER_OPTS) animation.cpp

flipper.o : flipper.h flipper.cpp
	$(COMPILER) $(COMPILER_OPTS) flipper.cpp

collage.o : point.o png.o collage.h collage.cpp
	$(COMPILER) $(COMPILER_OPTS) collage.cpp

png.o : png.h png.cpp rgbapixel.o
	$(COMPILER) $(COMPILER_OPTS) png.cpp

rgbapixel.o : rgbapixel.h rgbapixel.cpp
	$(COMPILER) $(COMPILER_OPTS) rgbapixel.cpp

point.o : point.h point.cpp
	$(COMPILER) $(COMPILER_OPTS) point.cpp

clean:
	-rm -f *.o $(EXENAME)

tidy: clean
	-rm -rf frames/ doc/ collage.png shifted.gif flipped.png 
