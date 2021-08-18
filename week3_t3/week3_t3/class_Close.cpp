#include"class_Close.h"
#include"class_Open.h"
#include"class_Lock.h"
#include"class_Base.h"
#include"class_Context.h"

using namespace std;
void Close::open_door(Context* door_state) {
	door_state->setState(new Open());
	cout << "Change door state form CLOSE to OPEN" << endl;
}
void Close::close_door(Context* door_state){
	cout << "The door is close" << endl;
}
void Close::lock_door(Context* door_state){
	door_state->setState(new Lock());
	cout << "Change door state form CLOSE to LOCK" << endl;
}
void Close::unlook_door(Context* door_state){
	cout << "Can't unlock when the door is not locked" << endl;
}