#include"class_Car.h"
using namespace std;
Car::Car() : DynamicObject()
{
}
Car::Car(int id, string name, Position pos) : DynamicObject(id, name, pos)
{
}
Car::~Car()
{
}