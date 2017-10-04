//
//  Copyright © 2017 OsmaniHernandez. All rights reserved.
//
//  responsible for decoding all bit fields. Couldn't make all printing virtual
//  so I left it to inheriting classes to deal with as they see fit, this way we wouldn't have
//  some printing defined here and some in concrete implementations.
//

#ifndef FORMAT_H
#define FORMAT_H

class Format
{
public:
    Format( const unsigned int&, const int&, const int&, const int& );
    void decodeOP() const;
    void decodeRS();
    void decodeRT();
    void decodeRD();
    void decodeFUNCT();
    void decodeBranchOFFSET();
    void decodeLoadWordStoreWordOFFSET();
    int getOp() const;
    int getRS() const;
    int getRT() const;
    int getRD() const;
    int getFUNCT() const;
    short getOFFSET() const;
    void printAddress() const;
    static unsigned int address;
    
    void setRD_MASK(const int&);
    void setFUNCT_MASK(const int&);
    void setOFFSET_MASK(const int&);
    virtual void decodeAndPrint() = 0;
    
    enum instruc
    {
        ADD = 0x20,
        SUB = 0x22,
        AND = 0x24,
        OR  = 0X25,
        SLT = 0x2a,
        LW  = 0x23,
        SW  = 0x2b,
        BEQ = 0x4,
        BNE = 0x5
    };
    
    virtual ~Format() {};
    
private:
    int             op;
    int             rs;
    int             rt;
    int             rd;
    int             funct;
    short           offset;
    int             RS_MASK;
    int             RT_MASK;
    int             RD_MASK;
    int             FUNC_MASK;
    int             OFFSET_MASK;
    unsigned int    instruction;
};

#endif
