/* 
 * File:   TEncFastPUDecision.cpp
 * Author: felsamps
 * 
 * Created on September 6, 2011, 3:24 PM
 */

#include "TEncFastPUDecision.h"

TEncFastPUDecision::TEncFastPUDecision() {
    borderA = false;
    borderB = false;
    borderC = false;
    borderD = false;
    currPartIdx = 0;
    cu = NULL;
}

