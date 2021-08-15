#pragma once
#include"class_BaseObject.h"
#include<iostream>
using namespace std;
class StaticObject : public BaseObject
{
public:
	StaticObject();
	StaticObject(int id, string name, Position pos);
	~StaticObject();
	void move(Position pos) ;
};
