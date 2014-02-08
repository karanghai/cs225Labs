CXX = g++
LINKER = g++

WARNINGS = -Wchar-subscripts -Wparentheses -Wreturn-type -Wmissing-braces -Wundef -Wshadow
CXXOPTS = -O0 -g -c $(WARNINGS) -std=c++0x

DECODER = decoder
ENCODER = encoder
PRINTER = print_as_ascii

EXES = $(DECODER) $(ENCODER) $(PRINTER)

ENC_OBJS = huffman_tree.o frequency.o encoder.o encoder_prog.o binary_file_writer.o binary_file_reader.o
DEC_OBJS = huffman_tree.o frequency.o decoder.o decoder_prog.o binary_file_writer.o binary_file_reader.o
PRINT_OBJS = binary_file_reader.o print_as_ascii.o

all: $(EXES)

$(ENCODER): $(ENC_OBJS)
	$(LINKER) $(ENC_OBJS) -o $(ENCODER)

$(DECODER): $(DEC_OBJS)
	$(LINKER) $(DEC_OBJS) -o $(DECODER)
				 
$(PRINTER): $(PRINT_OBJS)
	$(LINKER) $(PRINT_OBJS) -o $(PRINTER)

frequency.o: frequency.h frequency.cpp
	$(CXX) $(CXXOPTS) frequency.cpp

huffman_tree.o: binary_file_reader.h binary_file_writer.h frequency.h huffman_tree.h huffman_tree.cpp
	$(CXX) $(CXXOPTS) huffman_tree.cpp

binary_file_reader.o: binary_file_reader.h binary_file_reader.cpp
	$(CXX) $(CXXOPTS) binary_file_reader.cpp

binary_file_writer.o: binary_file_writer.h binary_file_writer.cpp
	$(CXX) $(CXXOPTS) binary_file_writer.cpp

encoder.o: encoder.h encoder.cpp frequency.h binary_file_writer.h
	$(CXX) $(CXXOPTS) encoder.cpp

encoder_prog.o: encoder.h encoder_prog.cpp
	$(CXX) $(CXXOPTS) encoder_prog.cpp

decoder.o: decoder.h decoder.cpp frequency.h binary_file_reader.h
	$(CXX) $(CXXOPTS) decoder.cpp

decoder_prog.o: decoder.h decoder_prog.cpp
	$(CXX) $(CXXOPTS) decoder_prog.cpp

print_as_ascii.o: binary_file_reader.h print_as_ascii.cpp
	$(CXX) $(CXXOPTS) print_as_ascii.cpp

doc: lab_huffman.doxygen
	doxygen lab_huffman.doxygen

tidy:
	-rm -rf *.bin *.txt *.huff

clean:
	-rm -rf *.o $(EXES) doc
