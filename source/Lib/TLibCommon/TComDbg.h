/* 
 * File:   TComDbg.h
 * Author: grellert
 *
 * Created on August 24, 2011, 8:18 AM
 */

#ifndef _TCOMDBG_H
#define	_TCOMDBG_H

#include <cstdio>
#include <cstdarg>
#include <string>

class TComDbg {
private:


public:
    TComDbg();

    /* Static Attributes */
    static FILE* dbgFile;
    static bool enableDbg;

    /* Static Methods */
    static void openDbgFile(std::string fileName);
    static void setDbgFile(FILE *filePointer);
    static void closeDbgFile();
    static void printDbg(std::string className, const char* str, ...);
    static void print(const char* str, ...);


private:

};

#endif	/* _TCOMDBG_H */


