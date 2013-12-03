/* 
 * File:   RoadBook.h
 * Author: cjoffro2
 *
 * Created on 27 novembre 2013, 13:14
 */

#ifndef ROADBOOK_H
#define	ROADBOOK_H

#include <vector>
#include <iterator>
#include "Instruction.h"



class RoadBook {
public:
    RoadBook(std::vector<Instruction>* tmpinstructions);
    ~RoadBook();
    bool hasInstruction();
    Instruction next();
   
private:
    std::vector<Instruction>* instructions;
};

#endif	/* ROADBOOK_H */

