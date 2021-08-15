#include"class_House.h"
using namespace std;
House::House() : StaticObject()
{
}
House::House(int id, string name, Position pos) : StaticObject(id, name, pos)
{
}
House::~House()
{
}