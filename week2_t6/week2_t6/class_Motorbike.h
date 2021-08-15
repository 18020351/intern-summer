#pragma once
#include"class_DynamicObject.h"
using namespace std;
class Motorbike : public DynamicObject
{
public:
	Motorbike();
	Motorbike(int id, string name, Position pos);
	~Motorbike();
};