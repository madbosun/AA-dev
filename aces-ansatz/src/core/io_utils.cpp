/*! io_utils.cpp  Contains routines to read and write primitive types and arrays from
 * binary and text files.
 * 
 *
 *  Created on: Jul 7, 2013
 *      Author: Beverly Sanders
 */

#include "core.h"
#include "io_utils.h"
#include <stdexcept>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "abort.h"

namespace setup{
    
    void ReadFileExists(const std::string& name) {
        struct stat buffer;
        if (stat (name.c_str(), &buffer)) {
            std::cout << "File " << name << " does not exist" << std::endl;
            all_abort();
        }
    }

/* Default constructors and destructors for OutputFile */
OutputStream::OutputStream():stream_(NULL){}

OutputStream::~OutputStream(){
	if(stream_) {
		//stream_->close();
		delete stream_;
	}
}

/* BinaryOutputFile */
BinaryOutputFile::BinaryOutputFile(const std::string& name) : file_name_(name){
	file_stream_ = new std::ofstream(name.c_str(), std::ios::binary | std::ios::trunc);
	stream_ = file_stream_;
	if (!file_stream_->is_open()){
		std::cout << stream_->eof() << "\t" << stream_->fail() << "\t" << stream_->bad();
		std :: cerr << "File "<< name  <<" could not be opened !";
		exit(-1);
	}
}

BinaryOutputFile::~BinaryOutputFile(){
	if (file_stream_->is_open())
		file_stream_->close();
}

void BinaryOutputStream::write_string(const std::string& aString) {
        //trim trailing spaces
        size_t endpos = aString.find_last_not_of(" ");
        std::string trimmed = (endpos == std::string::npos) ? "" : aString.substr(0,endpos+1);
	int length = (int) trimmed.length() + 1; //extra for null
	write_int(length);
//std::cout << "writing string " << trimmed << ", length=" << length << std::endl;
	stream_->write(trimmed.c_str(), length);
}

void BinaryOutputStream::write_int( int value) {
	stream_->write(reinterpret_cast<char *>(&value), sizeof(int));
}

void BinaryOutputStream::write_int_array(int size, int  values[]) {
	write_int(size);
	stream_->write(reinterpret_cast<char *>(values), sizeof(int) * size);
}

void BinaryOutputStream::write_double(double value) {
	stream_->write(reinterpret_cast<char *>(&value), sizeof(double));
}

void BinaryOutputStream::write_double_array(int size, double values[]) {
	write_int(size);
	stream_->write( reinterpret_cast<char *>(values), sizeof(double) * size);
}

void BinaryOutputStream::write_size_t_val(size_t value) {
	stream_->write( reinterpret_cast<char *>(&value), sizeof(size_t));
}

BinaryOutputByteStream::BinaryOutputByteStream(char *char_stream, int size){
	char_stream_ = new CharStreamBuf(char_stream, char_stream + size);
	this->stream_ = new std::ostream(char_stream_);

}

BinaryOutputByteStream::~BinaryOutputByteStream(){
	delete char_stream_;
}

InputStream::InputStream():stream_(NULL){}

InputStream::~InputStream(){
		if ((stream_)) {
		  //if (stream->is_open()){  stream->close();}
		  delete stream_;
	}
}
    

} /*namespace setup*/
