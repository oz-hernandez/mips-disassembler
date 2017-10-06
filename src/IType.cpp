//
//  Copyright © 2017 OsmaniHernandez. All rights reserved.
//

#include "../include/IType.h"
#include <iostream>


Itype::Itype(const unsigned int &instruction, const int &op, const int &RS_MASK, const int &RT_MASK, const int &OFFSET_MASK)
    : Format(instruction, op, RS_MASK, RT_MASK) { setOFFSET_MASK(OFFSET_MASK); }

void Itype::decodeAndPrint()
{
    if(getOp() == Itype::LW || getOp() == Itype::SW)
    {
        decodeOP();
        decodeRT();
        printRT();
        decodeLoadWordStoreWordOFFSET();
        printOFFSET();
        decodeRS();
        printRS();
    }
    else
    {
        decodeOP();
        decodeRS();
        printBranchRS();
        decodeRT();
        printRT();
        decodeBranchOFFSET();
        printPCRelativeOffset();
    }
}

void Itype::printRT()
{
    std::cout << "$" << getRT() << ", ";
}

void Itype::printRS()
{
    std::cout << "($" << getRS() << ")" << std::endl;
}

void Itype::printOFFSET()
{
    std::cout << getOFFSET();
}

void Itype::printPCRelativeOffset()
{
    unsigned int temp = Format::address + getOFFSET();
    std::cout << "address " << std::hex << temp << std::dec << std::endl;
    
}

void Itype::printBranchRS()
{
    std::cout << "$" << getRS() << ", ";
}
