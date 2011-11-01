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

TEncFastPUDecision::TEncFastPUDecision() {
    borderA = false;
    borderB = false;
    borderC = false;
    borderD = false;
    currPartIdx = 0;
    cu = NULL;
}

