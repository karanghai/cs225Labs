#
# USING THIS MAKEFILE:
#
#  'make treefun' - creates test executable
#

OBJS = main.o coloredout.o
EXENAME = treefun

COMPILER = g++
WARNINGS = -Wchar-subscripts -Wparentheses -Wreturn-type -Wmissing-braces -Wundef -Wshadow
COMPILER_OPTS = -c -g -O0 -Wfatal-errors -Werror $(WARNINGS)
LINKER = g++

all : $(EXENAME)

$(EXENAME) : $(OBJS)
	$(LINKER) $(OBJS) -o $(EXENAME)

main.o : main.cpp binarytree.h binarytree.cpp binarytree_given.cpp coloredout.h random.h
	$(COMPILER) $(COMPILER_OPTS) main.cpp

coloredout.o: coloredout.cpp coloredout.h
	$(COMPILER) $(COMPILER_OPTS) $(@:.o=.cpp)

clean :
	rm -f *.o $(EXENAME)

