#ifndef _TENCFASTPUDECISION_H
#define	_TENCFASTPUDECISION_H

#include <vector>
#include "../TLibCommon/TComMv.h"
#include "../TLibCommon/TComDataCU.h"

class TEncFastPUDecision {
    std::vector<TComMv*> bestMv, prefMv;
    std::vector<UInt> bestDist, prefDist;
    Bool borderA, borderB, borderC, borderD;
    PartSize partSize;
    UInt currPartIdx;
    static const PredMode predMode = MODE_INTER;
    TComDataCU *cu;
    std::vector<UInt**> distMap; 

public:
    TEncFastPUDecision();
    
    /* Fast PU Decision Methods */
    void decide();
    void xSetCUParameters();
        

    void        setCU               (TComDataCU *pCu)           { this->cu = pCu; }
    TComDataCU* getCU               ()                          { return this->cu; }

    void        setCurrPartIdx      (UInt idx)                  { this->currPartIdx = idx; }
    UInt        getCurrPartIdx      ()                          { return this->currPartIdx; }


    /* Best Matches' Information Setters and Getters */
    void        setBestMv           (UInt block, TComMv* mv)    { this->bestMv[block] = mv; }
    void        setBestMv           (TComMv* mv)                { this->bestMv[this->currPartIdx] = mv; }
    TComMv*     getBestMv           (UInt block)                { return this->bestMv[block]; }

    void        setBestDist         (UInt block, UInt dist)     { this->bestDist[block] = dist; }
    UInt        getBestDist         (UInt block)                { return this->bestDist[block]; }

    /* Prefferred Matches' Information Setters and Getters */
    void        setPrefMv           (UInt block, TComMv *mv)    { this->prefMv[block] = mv; }
    TComMv*     getPrefMv           (UInt block)                { return this->prefMv[block]; }

    void        setPrefDist         (UInt block, UInt dist)     { this->prefDist[block] = dist; }
    UInt        getPrefDist         (UInt block)                { return this->prefDist[block]; }

    /* Border flags setters and getters */
    void        setBorderA          (Bool b)                    { this->borderA = b; }
    void        setBorderB          (Bool b)                    { this->borderB = b; }
    void        setBorderC          (Bool b)                    { this->borderC = b; }
    void        setBorderD          (Bool b)                    { this->borderD = b; }

    Bool        isBorderA           ()                          { return borderA; }
    Bool        isBorderB           ()                          { return borderB; }
    Bool        isBorderC           ()                          { return borderC; }
    Bool        isBorderD           ()                          { return borderD; }

private:

};

#endif	/* _TENCFASTPUDECISION_H */

