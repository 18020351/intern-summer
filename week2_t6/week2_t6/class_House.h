#pragma once
#include"class_StaticObject.h"
using namespace std;
class House : public StaticObject
{
public:
	House();
	House(int id, string name, Position pos);
	~House();
};