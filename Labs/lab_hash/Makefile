CC = g++
WARNINGS = -Wchar-subscripts -Wparentheses -Wreturn-type -Wmissing-braces -Wundef -Wshadow
CC_OPTS = -O0 -g $(WARNINGS)
LINKER = g++

LC_TEST = charcount
LC_OBJS = hashes.o textfile.o charcount.o

ANAGRAM_TEST = anagramtest
ANAGRAM_OBJS = hashes.o textfile.o anagramtest.o

WC_TEST = wordcount
WC_OBJS = hashes.o textfile.o wordcount.o

LP_HASH = hashes.h lphashtable.cpp lpiterator.cpp htiterator.cpp lphashtable.h lpiterator.h hashtable.h htiterator.h
SC_HASH = hashes.h schashtable.cpp sciterator.cpp htiterator.cpp schashtable.h sciterator.h hashtable.h htiterator.h

GENLOG = genlog

PARSER = lfparse
PARSE_OBJS = logfile_parser.o lfparse.o hashes.o

all: $(LC_TEST) $(ANAGRAM_TEST) $(WC_TEST) $(GENLOG) $(PARSER)

$(LC_TEST) : $(LC_OBJS)
	$(LINKER) -o $(LC_TEST) $(LC_OBJS)

$(WC_TEST) : $(WC_OBJS)
	$(LINKER) -o $(WC_TEST) $(WC_OBJS)

$(ANAGRAM_TEST) : $(ANAGRAM_OBJS)
	$(LINKER) -o $(ANAGRAM_TEST) $(ANAGRAM_OBJS)

$(GENLOG) : logfile_generator.cpp
	$(CC) $(CC_OPTS) -o $(GENLOG) logfile_generator.cpp

$(PARSER) : $(PARSE_OBJS)
	$(LINKER) -o $(PARSER) $(PARSE_OBJS)

anagramtest.o : anagramtest.cpp anagram_finder.h anagram_finder.cpp $(LP_HASH) $(SC_HASH)
	$(CC) $(CC_OPTS) -c anagramtest.cpp

charcount.o : charcount.cpp char_counter.h textfile.h char_counter.h char_counter.cpp $(LP_HASH) $(SC_HASH)
	$(CC) $(CC_OPTS) -c charcount.cpp

wordcount.o : wordcount.cpp word_counter.h word_counter.cpp textfile.h $(LP_HASH) $(SC_HASH)
	$(CC) $(CC_OPTS) -c wordcount.cpp

textfile.o : textfile.h textfile.cpp
	$(CC) $(CC_OPTS) -c textfile.cpp

lfparse.o : lfparse.cpp logfile_parser.h
	$(CC) $(CC_OPTS) -c lfparse.cpp

logfile_parser.o : $(LP_HASH) $(SC_HASH) logfile_parser.h logfile_parser.cpp
	$(CC) $(CC_OPTS) -c logfile_parser.cpp

hashes.o : hashes.h hashes.cpp
	$(CC) $(CC_OPTS) -c hashes.cpp

doc: $(wildcard *.h) $(wildcard *.cpp)
	-doxygen lab_hash.doxygen

clean:
	-rm -rf doc *.o $(LC_TEST) $(LC_TEST).exe $(ANAGRAM_TEST) $(ANAGRAM_TEST).exe $(WC_TEST) $(WC_TEST).exe $(GENLOG) $(GENLOG).exe $(PARSER) $(PARSER).exe

tidy:
	-rm -f anagrams.txt
