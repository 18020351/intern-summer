#include"class_Lock.h"
#include"class_Close.h"
#include"class_Context.h"

using namespace std;
void Lock::open_door(Context* door_state) {
	cout << "Can't open the door, because current the door is lock" << endl;
}
void Lock::close_door(Context* door_state) {
	cout << "The door is lock => The door is close" << endl;
}
void Lock::lock_door(Context* door_state) {
	cout << "The door is lock" << endl;
}
void Lock::unlook_door(Context* door_state) {
	door_state->setState(new Close());
	cout << "Change door state form LOCK to CLOSE" << endl;
}
