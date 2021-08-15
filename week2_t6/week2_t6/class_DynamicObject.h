#pragma once
#include<iostream>
#include"class_BaseObject.h"
using namespace std;
class DynamicObject : public BaseObject
{
public:
	DynamicObject();
	DynamicObject(int id, string name, Position pos);
	~DynamicObject();
};
