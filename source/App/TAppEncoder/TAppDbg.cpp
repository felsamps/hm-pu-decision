/* 
 * File:   TAppDbg.cpp
 * Author: felsamps
 * 
 * Created on August 24, 2011, 8:18 AM
 */

#include "TAppDbg.h"

FILE* TAppDbg::dbgFile;
bool TAppDbg::enableDbg;

TAppDbg::TAppDbg() {
}

void TAppDbg::openDbgFile(std::string fileName) {
	if( enableDbg ) {
            if((dbgFile = fopen(fileName.c_str(), "w")) == NULL)
               printf("Error -> Dbg File could not be created\n");
	}
}

FILE* TAppDbg::getDbgFile() {
        return dbgFile;
}

void TAppDbg::closeDbgFile() {
	if( enableDbg ) {
		fclose(dbgFile);
	}
}

void TAppDbg::printDbg(std::string className, const char* str, ...) {
	if( enableDbg ) {
		va_list args;
		char buffer[BUFSIZ];

		va_start(args, str);
		vsprintf(buffer, str, args);
		fprintf(dbgFile, "%s: %s\n", className.c_str(), buffer);
		va_end(args);
	}	
}



