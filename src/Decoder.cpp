//
//  Copyright © 2017 OsmaniHernandez. All rights reserved.
//

#include "../include/Decoder.h"
#include "../include/Format.h"
#include "../include/RType.h"
#include "../include/IType.h"
#include <iostream>
using std::cout;

Decoder::Decoder(const unsigned int *instruct, const int instructSize) : instruction(instruct), INSTRUCT(instructSize) {}

void Decoder::decode()
{
    // masks
    
    int OP_MASK     = 0xFC000000;
    int RS_MASK     = 0x03E00000;
    int RT_MASK     = 0x001F0000;
    int RD_MASK     = 0x0000F800;
    int FUNC_MASK   = 0x0000003F;
    int OFFSET_MASK = 0x0000FFFF;

    for(int i = 0; i < INSTRUCT; ++i, ++this->instruction)
    {
        this->opcode = (*this->instruction & OP_MASK);
        opcode >>= 26;
        
        if(!opcode)
            this->instrucFormat = new Rtype( *this->instruction, opcode, RS_MASK, RT_MASK, RD_MASK, FUNC_MASK );
        else
        {
            this->instrucFormat = new Itype( *this->instruction, opcode, RS_MASK, RT_MASK, OFFSET_MASK );
        }
        
        instrucFormat->decodeAndPrint();
        delete instrucFormat;
    }
}
