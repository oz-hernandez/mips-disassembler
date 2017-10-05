//
//  Copyright © 2017 OsmaniHernandez. All rights reserved.
//

#ifndef DECODER_H
#define DECODER_H

class Format;
class FormatFactory;

class Decoder
{
public:
    Decoder(const unsigned int*, const int);
    void decode();
    ~Decoder();
    
private:
    FormatFactory       *factory;
    Format              *instrucFormat;
    const unsigned int  *instruction;
    const int           INSTRUCT;
//    unsigned int        opcode;
};

#endif
