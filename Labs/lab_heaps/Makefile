EXENAME = testheap
COMPILER = g++
WARNINGS = -Wchar-subscripts -Wparentheses -Wreturn-type -Wmissing-braces -Wundef -Wshadow
COMPILER_OPTS = -g -O0 -Wfatal-errors -Werror $(WARNINGS)
OBJS = testheap.o coloredout.o

$(EXENAME) : $(OBJS)
	$(COMPILER) $(OBJS) -o $@

testheap.o: testheap.cpp heap.h heap.cpp printheap.cpp printtree.h
	$(COMPILER) -c $(COMPILER_OPTS) testheap.cpp

coloredout.o: coloredout.cpp coloredout.h
	$(COMPILER) -c $(COMPILER_OPTS) coloredout.cpp

doc: lab_heaps.doxygen $(wildcard *.h) $(wildcard *.cpp)
	doxygen lab_heaps.doxygen

clean:
	-rm -rf *.o $(EXENAME) doc
