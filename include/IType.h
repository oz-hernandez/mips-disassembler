//
//  Copyright © 2017 OsmaniHernandez. All rights reserved.
//
//  responsible for decoding and printing appropriate fields for branching, lw and sw opcodes.
//

#ifndef ITYPE_H
#define ITYPE_H

#include "Format.h"

class Itype : public Format
{
public:
    Itype(const unsigned int&, const int&, const int&, const int&, const int&);
    virtual void decodeAndPrint();
    void printRS();
    void printBranchRS();
    void printRT();
    void printOFFSET();
    void printPCRelativeOffset();
    virtual ~Itype() {};
};

#endif
