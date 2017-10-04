//
//  Copyright © 2017 OsmaniHernandez. All rights reserved.
//

#include "../include/Format.h"
#include <iostream>

Format::Format(const unsigned int &instruc, const int &op, const int &RS_MASK, const int &RT_MASK)
    : instruction(instruc), op(op), RS_MASK(RS_MASK), RT_MASK(RT_MASK) {}

unsigned int Format::address = 0x9A040;

void Format::printAddress() const
{
    std::cout << std::hex << std::uppercase << Format::address << " " << std::dec;
    Format::address += 0x0004;
}

int Format::getOp() const
{
    return this->op;
}

int Format::getRS() const
{
    return this->rs;
}

int Format::getRT() const
{
    return this->rt;
}

int Format::getRD() const
{
    return this->rd;
}

int Format::getFUNCT() const
{
    return this->funct;
}

short Format::getOFFSET() const
{
    return this->offset;
}

void Format::setRD_MASK(const int &RD_MASK)
{
    this->RD_MASK = RD_MASK;
}

void Format::setFUNCT_MASK(const int &FUNCT_MASK)
{
    this->FUNC_MASK = FUNCT_MASK;
}

void Format::setOFFSET_MASK(const int &OFFSET_MASK)
{
    this->OFFSET_MASK = OFFSET_MASK;
}

void Format::decodeOP() const
{
    printAddress();
    switch(this->op)
    {
        case Format::LW:  std::cout << "lw " ; break;
        case Format::SW:  std::cout << "sw " ; break;
        case Format::BEQ: std::cout << "beq "; break;
        case Format::BNE: std::cout << "bne "; break;
    }
}

void Format::decodeRS()
{
    this->rs = (this->instruction & this->RS_MASK) >> 21;
}

void Format::decodeRT()
{
    this->rt = (this->instruction & this->RT_MASK) >> 16;
}

void Format::decodeRD()
{
    this->rd = (this->instruction & this->RD_MASK) >> 11;
}

void Format::decodeFUNCT()
{
    this->funct = this->instruction & this->FUNC_MASK;
    
    switch(this->funct)
    {
        case Format::ADD: std::cout << "add "; break;
        case Format::SUB: std::cout << "sub "; break;
        case Format::AND: std::cout << "and "; break;
        case Format::OR:  std::cout << "or " ; break;
        case Format::SLT: std::cout << "slt "; break;
    }
}

void Format::decodeBranchOFFSET()
{
    this->offset = (this->instruction & this->OFFSET_MASK) << 2;
}

void Format::decodeLoadWordStoreWordOFFSET()
{
    this->offset = (this->instruction & this->OFFSET_MASK);
}

