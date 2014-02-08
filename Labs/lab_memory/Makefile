COMPILER = g++
WARNINGS = -Wchar-subscripts -Wparentheses -Wreturn-type -Wmissing-braces -Wundef -Wshadow
COMPILER_OPTS = -c -g -O0 -Wfatal-errors -Werror $(WARNINGS)
LINKER = g++

OBJECTS = main.o letter.o room.o allocator.o fileio.o

allocate : $(OBJECTS)
	$(LINKER) $(OBJECTS) -o allocate

main.o : main.cpp allocator.h letter.h room.h fileio.h
	$(COMPILER) $(COMPILER_OPTS) main.cpp

letter.o: letter.h letter.cpp
	$(COMPILER) $(COMPILER_OPTS) letter.cpp

room.o: room.h room.cpp letter.h
	$(COMPILER) $(COMPILER_OPTS) room.cpp

allocator.o: allocator.h allocator.cpp room.h letter.h fileio.h
	$(COMPILER) $(COMPILER_OPTS) allocator.cpp

fileio.o : fileio.h fileio.cpp room.h
	$(COMPILER) $(COMPILER_OPTS) fileio.cpp

clean : 
	-rm -f *.o allocate

tidy: clean
	-rm -rf ./doc
