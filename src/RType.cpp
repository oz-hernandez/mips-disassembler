//
//  Copyright © 2017 OsmaniHernandez. All rights reserved.
//

#include "../include/RType.h"
#include <iostream>

Rtype::Rtype(const unsigned int &instruc, const int &op, const int &RS_MASK,
             const int &RT_MASK, const int &RD_MASK, const int &FUNCT_MASK)
    : Format(instruc, op, RS_MASK, RT_MASK) { setRD_MASK(RD_MASK); setFUNCT_MASK(FUNCT_MASK); }

void Rtype::decodeAndPrint()
{
    printAddress();
    decodeFUNCT();
    decodeRD();
    printRD();
    decodeRS();
    printRS();
    decodeRT();
    printRT();
}

void Rtype::printRS()
{
    std::cout << "$" << getRS() << ", ";
}

void Rtype::printRT()
{
    std::cout << "$" << getRT() << std::endl;
}

void Rtype::printRD()
{
    std::cout << "$" << getRD() << ", ";
}
