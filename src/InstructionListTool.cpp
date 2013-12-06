/* 
 * File:   InstructionListTool.cpp
 * Author: cjoffro2
 * 
 * Created on 26 novembre 2013, 13:30
 */

#include "InstructionListTool.h"
#include <iostream>


std::vector<Instruction>* InstructionListTool::compacte(std::vector<Instruction>* instructions){
	int cpt = 0;
	Instruction inst ;
        std::vector<Instruction>* copieCompacte = new std::vector<Instruction>();
	while(!instructions->empty()){
		inst = instructions->front();
		if(inst != TURNRIGHT){
			if (cpt != 0) {
				if (cpt == 3) {
					std::cout << "ici" << std::endl;
					copieCompacte->push_back(TURNLEFT);
				}
				else {
					while (cpt > 0){
						copieCompacte->push_back(TURNRIGHT);
						cpt--;
					}
				}
				cpt=0;
			}
			copieCompacte->push_back(inst);
		}
		else{
			cpt++;
			std::cout << cpt << std::endl;
		}
		instructions->erase(instructions->begin());
	}
        return copieCompacte;
}

std::vector<Instruction>* InstructionListTool::concateneInstruction(std::vector<Instruction>* vect, Instruction elem){
	std::vector<Instruction>* instructions = new std::vector<Instruction> (vect->begin(), vect->end());
	instructions->push_back(elem);
	return instructions;
}
std::vector<Coordinates*>* InstructionListTool::concateneCoordinates(std::vector<Coordinates*>* vect, Coordinates* elem){
	std::vector<Coordinates*>* coordinates = new std::vector<Coordinates*> (vect->begin(), vect->end());
	coordinates->push_back(elem);
	return coordinates;

}
