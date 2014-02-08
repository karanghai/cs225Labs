NAME_OF_EXECUTABLE_FILE = testavl

COMPILER = g++ 
WARNINGS = -Wchar-subscripts -Wparentheses -Wreturn-type -Wmissing-braces -Wundef -Wshadow
COMPILER_OPTS = -c -g -O0 $(WARNINGS)
 
LINKER = g++ 
LINKER_OPTS = -o $(NAME_OF_EXECUTABLE_FILE)
 
OBJS = coloredout.o main.o

$(NAME_OF_EXECUTABLE_FILE): $(OBJS) avltree.h avltree_given.cpp avltree.cpp printtree.h
	$(LINKER) $(OBJS) $(LINKER_OPTS)

main.o: main.cpp avltree.h avltree_given.cpp avltree.cpp printtree.h
	$(COMPILER) $(COMPILER_OPTS) main.cpp

coloredout.o: coloredout.cpp coloredout.h 
	$(COMPILER) $(COMPILER_OPTS) coloredout.cpp

clean:
	-rm -f *.o $(NAME_OF_EXECUTABLE_FILE)

tidy:
	-rm -rf ./doc
