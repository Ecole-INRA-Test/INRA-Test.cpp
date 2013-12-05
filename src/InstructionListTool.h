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

class InstructionListTool {
public:
    static std::vector<Instruction>* compacte(std::vector<Instruction>* instructions);
private:
};

#endif	/* INSTRUCTIONLISTTOOL_H */

