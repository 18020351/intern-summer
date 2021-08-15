#include"class_StaticObject.h"
using namespace std;
StaticObject::StaticObject(): BaseObject()
{
}
StaticObject::StaticObject(int id, string name, Position pos) : BaseObject(id, name, pos)
{
}
StaticObject::~StaticObject()
{
}
void StaticObject::move(Position pos) {
	cout<<this->getName() << " is static, so not move" << endl;
}