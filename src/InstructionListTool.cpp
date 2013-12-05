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
