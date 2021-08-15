#pragma once
#include"class_StaticObject.h"
using namespace std;
class Tree : public StaticObject
{
public:
	Tree();
	Tree(int id, string name, Position pos);
	~Tree();
};

