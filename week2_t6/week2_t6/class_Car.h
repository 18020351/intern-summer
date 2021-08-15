#pragma once
#include"class_DynamicObject.h"
using namespace std;
class Car : public DynamicObject
{
public:
	Car();
	Car(int id, string name, Position pos);
	~Car();
};