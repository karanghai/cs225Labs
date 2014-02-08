/**
 * @file binary_file_reader.h
 * Definition of a binary file class for input operations.
 *
 * @author Chase Geigle
 * @date Summer 2012
 */

#ifndef _BINARY_FILE_READER_H_
#define _BINARY_FILE_READER_H_

#include <fstream>
#include <string>

/**
 * BinaryFileReader: interface for reading binary files, bit by bit or byte
 * by byte. Wraps an ifstream in binary mode.
 *
 * @author Chase Geigle
 * @date Summer 2012
 */
class BinaryFileReader {
	public:
		/**
		 * Constructs a new BinaryFileReader by opening the given file.
		 *
		 * @param fileName File to be opened.
		 */
		BinaryFileReader( const std::string & fileName );

		/**
		 * Destroys a BinaryFileReader, ensuring the file is correctly
		 * closed. If the file is already closed, does nothing.
		 */
		~BinaryFileReader();

		/**
		 * Reads the next bit of the file. Should only be called when
		 * hasBits() is true.
		 *
		 * @return The next bit of the file.
		 */
		bool getNextBit();

		/**
		 * Reads the next byte of the file. Should only be called when
		 * hasBytes() is true.
		 *
		 * @return The next byte of the file, as a char.
		 */
		char getNextByte();

		/**
		 * Resets the file pointer to the beginning of the file.
		 */
		void reset();

		/**
		 * Closes the given file.
		 */
		void close();

		/**
		 * Determines if there are more **bits** to be read in the file.
		 *
		 * @return Whether or not there exists at least one more unread bit
		 *	in the file.
		 */
		bool hasBits() const;

		/**
		 * Determines if there are more **bytes** to be read in the file.
		 *
		 * @return Whether or not there exists at least one more unread
		 *	byte in the file.
		 */
		bool hasBytes() const;


	private:
		std::ifstream file; /**< std::ifstream used to read in the file. */
		char currentByte;	/**< The current byte to read bits from. */
		int currentBit;		/**< The current bit within the currentByte that is being read. */
		int maxBytes;		/**< The total number of bytes in the file. */
		int numRead;		/**< The number of bytes read from the file. */
		int paddingBits;    /**< The number of padding bits there are in the final byte. */

		/**
		 * Determines whether or not another byte needs read from the file.
		 *
		 * @return Whether or not another byte must be read.
		 */
		bool needsNextByte() const;

		/**
		 * Reads in a single byte from the file.
		 */
		void readNextByte();
};

#endif
