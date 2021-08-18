#include"class_Open.h"
#include"class_Close.h"
#include"class_Context.h"

void Open::open_door(Context* door_state) {
	cout << "The door is open" << endl;
}
void Open::close_door(Context* door_state) {
	door_state->setState(new Close());
	cout << "Change door state form OPEN to CLOSE" << endl;
}
void Open::lock_door(Context* door_state) {
	cout << "Can't lock the door while it's open" << endl;
}
void Open::unlook_door(Context* door_state) {
	cout << "The door is open => The door is unlock" << endl;
}