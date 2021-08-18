#pragma once
#include"class_Base.h"
#include"class_Lock.h"
using namespace std;
class Close :public Base {
public:
	void open_door(Context*);
	void close_door(Context*);
	void lock_door(Context*);
	void unlook_door(Context*);
};