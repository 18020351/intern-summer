#include"struct_Position.h"
using namespace std;
Position::Position() {
	this->pos_x = 0;
	this->pos_y = 0;
}
Position::Position(float a, float b) {
	this->pos_x = a;
	this->pos_y = b;
}
Position::~Position(){}