/* 
 * File:   InstructionListTool.h
 * Author: cjoffro2
 *
 * Created on 26 novembre 2013, 13:30
 */

#ifndef INSTRUCTIONLISTTOOL_H
#define	INSTRUCTIONLISTTOOL_H

#include <vector>
#include "Instruction.h"
#include "Coordinates.h"

class InstructionListTool {
public:
    static std::vector<Instruction>* compacte(std::vector<Instruction>* instructions);

    static std::vector<Instruction>* concateneInstruction(std::vector<Instruction>* vec, Instruction elem);
    static std::vector<Coordinates*>* concateneCoordinates(std::vector<Coordinates*>* vec, Coordinates* elem);
private:
};

#endif	/* INSTRUCTIONLISTTOOL_H */

