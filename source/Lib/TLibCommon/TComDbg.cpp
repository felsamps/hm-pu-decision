/* 
 * File:   TComDbg.cpp
 * Author: grellert
 * 
 * Created on September 13, 2011, 8:18 AM
 */

#include "TComDbg.h"

FILE* TComDbg::dbgFile;
bool TComDbg::enableDbg;

TComDbg::TComDbg() {
}

void TComDbg::openDbgFile(std::string fileName) {
	if( enableDbg ) {
		if((dbgFile = fopen(fileName.c_str(), "w")) == NULL)
                    printf("Error -> Dbg File could not be created\n");
	}
}

void TComDbg::setDbgFile(FILE *filePointer) {
	if( enableDbg ) {
		dbgFile = filePointer; 
	}
}

void TComDbg::closeDbgFile() {
	if( enableDbg ) {
		fclose(dbgFile);
	}
}

void TComDbg::printDbg(std::string className, const char* str, ...) {
	if( enableDbg ) {
		va_list args;
		char buffer[BUFSIZ];

		va_start(args, str);
		vsprintf(buffer, str, args);
		fprintf(dbgFile, "%s: %s\n", className.c_str(), buffer);
		va_end(args);
	}
}

void TComDbg::print(const char* str, ...) {
	if( enableDbg ) {
		va_list args;
		char buffer[BUFSIZ];

		va_start(args, str);
		vsprintf(buffer, str, args);
		fprintf(dbgFile, "%s", buffer);
		va_end(args);
	}
}




