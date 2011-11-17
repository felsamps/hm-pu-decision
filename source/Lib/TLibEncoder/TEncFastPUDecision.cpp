/* 
 * File:   TEncFastPUDecision.cpp
 * Author: felsamps
 * 
 * Created on September 6, 2011, 3:24 PM
 */

#include "TEncFastPUDecision.h"

TComMv TEncFastPUDecision::bestMv[4];
TComMv TEncFastPUDecision::prefMv[4]; //Se vamos usar vector, temos que resolver BAD_ACCESS da indexacao direta
UInt TEncFastPUDecision::bestDist[4];
UInt TEncFastPUDecision::prefDist[4];
Bool TEncFastPUDecision::borderA;
Bool TEncFastPUDecision::borderB;
Bool TEncFastPUDecision::borderC;
Bool TEncFastPUDecision::borderD;
PartSize TEncFastPUDecision::partSize;
UInt TEncFastPUDecision::currPartIdx;
const PredMode TEncFastPUDecision::predMode;
TComDataCU* TEncFastPUDecision::cu;
std::vector<UInt**> TEncFastPUDecision::distMap;
Int TEncFastPUDecision::refFrameIdx;

void TEncFastPUDecision::init() {
    borderA = false;
    borderB = false;
    borderC = false;
    borderD = false;
    currPartIdx = 0;
    cu = NULL;
}

std::string TEncFastPUDecision::report() {
	std::string returnable("##FastDecision Report##\n");
	char str[50];
	
	
	for(int i=0; i<4; i++) {
		sprintf(str, "MV %d - (%d %d) - %d - %d ", i, bestMv[i].getHor(), bestMv[i].getVer(), bestDist[i], prefDist[i]);
                if(prefDist[i] < bestDist[i])
                    strcat(str,"**");
                strcat(str, "\n");
		std::string cppStr(str);
		returnable += cppStr;
	}

	returnable += "Dec. #1: ";
	returnable += (borderA) ? "1" : "0";
	returnable += (borderB) ? "1" : "0";
	returnable += (borderC) ? "1" : "0";
	returnable += (borderD) ? "1" : "0";
	returnable += "\n";
	

	return returnable;
}

void TEncFastPUDecision::decideMVSimilarity() {
	if(bestMv[0] == bestMv[1]) setBorderA(true);
	if(bestMv[0] == bestMv[2]) setBorderB(true);
	if(bestMv[1] == bestMv[3]) setBorderC(true);
	if(bestMv[2] == bestMv[3]) setBorderD(true);

}