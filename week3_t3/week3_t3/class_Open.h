#pragma once
#include"class_Base.h"

using namespace std;
class Open : public Base {
public:
	void open_door(Context*);
	void close_door(Context*);
	void lock_door(Context*);
	void unlook_door(Context*);
};