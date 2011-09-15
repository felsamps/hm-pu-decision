#ifndef _TCOMTIMECOUNTER_H
#define	_TCOMTIMECOUNTER_H

#include <ctime>
#include <string>
#include <cstdio>
#include <iostream>

class TComTimeCounter {
    clock_t start, end;
    std::string tag;
public:
    TComTimeCounter();
    TComTimeCounter(std::string desc);
    void startCounter();
    void endCounter();
    std::string report();
private:

};

#endif	/* _TCOMTIMECOUNTER_H */

