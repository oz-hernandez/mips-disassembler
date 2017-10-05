//
//  Copyright © 2017 OsmaniHernandez. All rights reserved.
//

#include "../include/Decoder.h"
#include "../include/Format.h"
#include "../include/SimpleFormatFactory.h"

Decoder::Decoder(const unsigned int *instruct, const int instructSize) : instruction(instruct), INSTRUCT(instructSize)

{ this->factory = new FormatFactory; }

void Decoder::decode()
{
    for(int i = 0; i < INSTRUCT; ++i, ++this->instruction)
    {
        this->instrucFormat = this->factory->returnFormat(*this->instruction);
        instrucFormat->decodeAndPrint();
        delete instrucFormat;
    }
}

Decoder::~Decoder() { delete this->factory; }
