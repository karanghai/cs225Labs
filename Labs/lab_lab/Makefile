# Lines that start with a # are comments
#		   	
# Here we define variables that we can use later.
# When variables are used we must wrap them with $()
OBJS = main.o png.o rgbapixel.o
EXENAME = remove

CXX = g++
CXXFLAGS = -c -g -O0 -Wall
LINK = g++
LDFLAGS = -lpng

all : $(EXENAME)

$(EXENAME) : $(OBJS)
	$(LINK) $(OBJS) $(LDFLAGS) -o $(EXENAME)

main.o : main.cpp png.o rgbapixel.o
	$(CXX) $(CXXFLAGS) main.cpp

rgbapixel.o: rgbapixel.h rgbapixel.cpp
	$(CXX) $(CXXFLAGS) rgbapixel.cpp
	
png.o : png.cpp png.h rgbapixel.h
	$(CXX) $(CXXFLAGS) png.cpp

clean : 
	rm -f *.o $(EXENAME) 2>/dev/null
