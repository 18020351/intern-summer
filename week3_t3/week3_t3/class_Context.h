#pragma once
#include<iostream>
#include"class_Base.h"

using namespace std;
class Context {
private:
	Base *m_door_state;
public:
	Context(Base*);
	void setState(Base*);
	Base *getState();
};
