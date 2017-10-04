//
//  Copyright © 2017 OsmaniHernandez. All rights reserved.
//
//  responsible for decoding and printing arithmetic instructions
//

#ifndef RTYPE_H
#define RTYPE_H

#include "Format.h"

class Rtype : public Format
{
public:
    Rtype(const unsigned int&, const int&, const int&, const int&, const int&, const int &);
    void printRS();
    void printRT();
    void printRD();
    virtual void decodeAndPrint();
    virtual ~Rtype() {};
};

#endif
