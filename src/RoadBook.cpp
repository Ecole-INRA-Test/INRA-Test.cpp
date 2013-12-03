/* 
 * File:   RoadBook.cpp
 * Author: cjoffro2
 * 
 * Created on 27 novembre 2013, 13:14
 */

#include "RoadBook.h"

RoadBook::RoadBook(std::vector<Instruction>* tmpinstructions) {
	instructions = tmpinstructions;
}

RoadBook::~RoadBook() {
}

bool RoadBook::hasInstruction(){
	return !(instructions->empty());
}

Instruction RoadBook::next(){
	return instructions->front();
}
