#pragma once
#include<iostream>
#include<string>
#include"struct_Position.h"
using namespace std;
class BaseObject
{
private:
	int id;
	string name;
	Position pos;
public:
	BaseObject();
	BaseObject(int ad, string name, Position pos);
	~BaseObject();

	int getID();
	string getName();
	virtual void move(Position pos);
	Position getPos();
	void printPosition();
};
