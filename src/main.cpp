//
//  Copyright © 2017 OsmaniHernandez. All rights reserved.
//

#include <iostream>
#include "../include/Decoder.h"

int main()
{
    const int INSTRUC = 11;
    const unsigned int instructions[INSTRUC] = { 0x032BA020, 0x8CE90014, 0x12A90003,
                                                 0x022DA822, 0xADB30020, 0x02697824,
                                                 0xAE8FFFF4, 0x018C6020, 0x02A4A825,
                                                 0x158FFFF7, 0x8ECDFFF0
                                               };
    
    Decoder *mipsDecoder = new Decoder(instructions, INSTRUC);
    mipsDecoder->decode();
    delete mipsDecoder;
}
