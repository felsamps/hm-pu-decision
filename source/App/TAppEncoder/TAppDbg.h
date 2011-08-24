/* 
 * File:   TAppDbg.h
 * Author: felsamps
 *
 * Created on August 24, 2011, 8:18 AM
 */

#ifndef _TAPPDBG_H
#define	_TAPPDBG_H

#include <cstdio>
#include <cstdarg>
#include <string>

class TAppDbg {
private:


public:
    TAppDbg();

    /* Static Attributes */
    static FILE* dbgFile;
    static bool enableDbg;

    /* Static Methods */
    static void openDbgFile(std::string fileName);
    static void closeDbgFile();
    static void printDbg(std::string className, const char* str, ...);


private:

};

#endif	/* _TAPPDBG_H */

