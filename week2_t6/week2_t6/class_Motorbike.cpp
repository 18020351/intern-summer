#include"class_Motorbike.h"
using namespace std;
Motorbike::Motorbike() : DynamicObject()
{
}
Motorbike::Motorbike(int id, string name, Position pos) : DynamicObject(id, name, pos)
{
}
Motorbike::~Motorbike()
{
}