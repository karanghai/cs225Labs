CXX = g++
CXXFLAGS = -g -O0 -Wall -Werror -fopenmp
LFLAGS = -lpng -fopenmp -g -O0 -Wall -Werror

MIN = min
GENFILE = genfile
COUNTER = counter
HISTOGRAM = histogram

EXES = $(MIN) $(GENFILE) $(COUNTER) $(HISTOGRAM)

all: $(EXES)

$(MIN) : min.o
	$(CXX) $(LFLAGS) -o $(MIN) min.o

$(GENFILE) : genfile.o
	$(CXX) $(LFLAGS) -o $(GENFILE) genfile.o

$(COUNTER) : counter.o pnganalysis.o png.o rgbapixel.o tolerance_selector.o exact_selector.o
	$(CXX) $(LFLAGS) -o $(COUNTER) counter.o pnganalysis.o png.o rgbapixel.o tolerance_selector.o exact_selector.o

$(HISTOGRAM) : histogram.o pnganalysis.o png.o rgbapixel.o tolerance_selector.o exact_selector.o
	$(CXX) $(LFLAGS) -o $(HISTOGRAM) histogram.o pnganalysis.o png.o rgbapixel.o tolerance_selector.o exact_selector.o

png.o : rgbapixel.h png.h png.cpp
	$(CXX) $(CXXFLAGS) -c png.cpp -o png.o

rgbapixel.o : rgbapixel.h rgbapixel.cpp
	$(CXX) $(CXXFLAGS) -c rgbapixel.cpp -o rgbapixel.o

min.o : min.cpp findmin.h findmin.cpp
	$(CXX) $(CXXFLAGS) -c min.cpp -o min.o

genfile.o : genfile.cpp
	$(CXX) $(CXXFLAGS) -c genfile.cpp -o genfile.o

exact_selector.o : exact_selector.h selector.h exact_selector.cpp
	$(CXX) $(CXXFLAGS) -c exact_selector.cpp -o exact_selector.o

tolerance_selector.o : tolerance_selector.h selector.h tolerance_selector.cpp
	$(CXX) $(CXXFLAGS) -c tolerance_selector.cpp -o tolerance_selector.o

counter.o : pnganalysis.o counter.cpp
	$(CXX) $(CXXFLAGS) -c counter.cpp -o counter.o

pnganalysis.o : pnganalysis.h pnganalysis.cpp png.h rgbapixel.h selector.h compare.h
	$(CXX) $(CXXFLAGS) -c pnganalysis.cpp -o pnganalysis.o

histogram.o : pnganalysis.o histogram.cpp
	$(CXX) $(CXXFLAGS) -c histogram.cpp -o histogram.o

tidy:
	-rm -rf parallel serial *.png

clean: tidy
	-rm -rf *.o $(EXES)
