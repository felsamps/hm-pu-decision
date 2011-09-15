/* 
 * File:   TComTimeCounter.cpp
 * Author: felsamps
 * 
 * Created on September 14, 2011, 4:33 PM
 */



#include "TComTimeCounter.h"

TComTimeCounter::TComTimeCounter() {
	tag = "";
}

TComTimeCounter::TComTimeCounter(std::string desc) {
	this->tag = desc + " : ";
}

void TComTimeCounter::startCounter() {
	this->start = clock();
}

void TComTimeCounter::endCounter() {
	this->end = clock();
}

std::string TComTimeCounter::report() {
	char str0[50];
	sprintf(str0, "%lf", (double) (this->end - this->start)/CLOCKS_PER_SEC );
	std::string str(str0);
	return this->tag + str + "\n";
}

