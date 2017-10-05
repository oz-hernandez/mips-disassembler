//
//  Copyright © 2017 OsmaniHernandez. All rights reserved.
//


#include "../include/SimpleFormatFactory.h"
#include "../include/IType.h"
#include "../include/RType.h"

Format* FormatFactory::returnFormat(const unsigned int &instruction)
{
    this->opcode = (instruction & FormatFactory::OP_MASK);
    opcode >>= 26;

    if(!opcode)
        return new Rtype(instruction, opcode, FormatFactory::RS_MASK, FormatFactory::RT_MASK,
                         FormatFactory::RD_MASK, FormatFactory::FUNC_MASK );
    else
        return new Itype(instruction, opcode, FormatFactory::RS_MASK,
                         FormatFactory::RT_MASK, FormatFactory::OFFSET_MASK );
}
