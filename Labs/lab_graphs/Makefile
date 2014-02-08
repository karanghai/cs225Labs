CC = g++ -std=c++0x
CC_OPTS = -O0 -g -c
LINKER = g++ -std=c++0x

DEMO = graphdemo
DEMO_OBJS = graph.o demo.o

LAB = lab_graphs
LAB_OBJS = graph.o graph_tools.o dsets.o

DSETS = dsets.h dsets.cpp

all: $(DEMO) $(LAB)

$(DEMO): $(DEMO_OBJS)
	$(LINKER) -o $(DEMO) $(DEMO_OBJS)
	
$(LAB): $(LAB_OBJS) tests.cpp
	$(LINKER) -o $(LAB) tests.cpp $(LAB_OBJS)
    
demo.o: demo.cpp
	$(CC) $(CC_OPTS) demo.cpp
	
graph.o: lab_graphs_random.h lab_graphs_random.cpp graph.h graph.cpp premade_graphs.h premade_graphs.cpp
	$(CC) $(CC_OPTS) graph.cpp
	
graph_tools.o: graph_tools.h graph_tools.cpp $(DSETS)
	$(CC) $(CC_OPTS) graph_tools.cpp
	
dsets.o: dsets.cpp dsets.h
	$(CC) $(CC_OPTS) dsets.cpp
	
clean:
	-rm -f *.o $(DEMO) $(LAB) *.gch

tidy: clean
	-rm -f images/*.png
	-rm -rf doc
