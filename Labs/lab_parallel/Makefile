# run "source /software/intel-composer-2011u5-x86_64/bin/compilervars.sh intel64" to set up compiler variables

LABNAME = lab_parallel
OBJS = rgbapixel.o png.o image_tools.o

COMPILER = icc -openmp 
#COMPILER = g++ -fopenmp 
COMPILER_OPTS = -c -g -O0 -Wall
LINKER = icc -openmp -lpng
#LINKER = g++ -fopenmp -lpng

all: $(LABNAME)

$(LABNAME): $(OBJS) main.cpp
	$(LINKER) $(OBJS) main.cpp -o $(LABNAME)

image_tools.o: image_tools.h image_tools.cpp
	$(COMPILER) $(COMPILER_OPTS) image_tools.cpp

png.o: png.h png.cpp
	$(COMPILER) $(COMPILER_OPTS) png.cpp

rgbapixel.o: rgbapixel.h rgbapixel.cpp
	$(COMPILER) $(COMPILER_OPTS) rgbapixel.cpp

clean:
	-rm -f *.o $(LABNAME)

tidy: clean
	-rm -rf doc
