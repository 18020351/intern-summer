#pragma once
#include<iostream>

using namespace std;
class Context;

class Base {
public:
	Base();
	virtual void open_door(Context *);
	virtual void close_door(Context*);
	virtual void lock_door(Context*);
	virtual void unlook_door(Context*);
};