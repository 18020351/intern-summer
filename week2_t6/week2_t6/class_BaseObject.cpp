#include"class_BaseObject.h"

using namespace std;
BaseObject::BaseObject()
{
	this->id = 0;
	this->name = "";
	this->pos = Position(0, 0);
}
BaseObject::BaseObject(int id, string name, Position pos)
{
	this->id = id;
	this->name = name;
	this->pos = pos;
}
BaseObject::~BaseObject()
{
}
int BaseObject::getID() {
	return this->id;
}
string BaseObject::getName() {
	return this->name;
}
void BaseObject::move(Position pos) {
	this->pos.pos_x += pos.pos_x;
	this->pos.pos_y += pos.pos_y;
}
Position BaseObject::getPos() {
	return this->pos;
}
void BaseObject::printPosition() {
	cout << "Position: (" << this->pos.pos_x << ", " << this->pos.pos_y << ")" << endl;
}