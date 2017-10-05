//
//  Copyright © 2017 OsmaniHernandez. All rights reserved.
//

#ifndef SIMPLEFORMATFACTORY_H
#define SIMPLEFORMATFACTORY_H

class Format;

class FormatFactory
{
public:
    Format *returnFormat(const unsigned int&);
    
    enum
    {
        OP_MASK     = 0xFC000000,
        RS_MASK     = 0x03E00000,
        RT_MASK     = 0x001F0000,
        RD_MASK     = 0x0000F800,
        FUNC_MASK   = 0x0000003F,
        OFFSET_MASK = 0x0000FFFF
    };
private:
    unsigned int opcode;
};

#endif
