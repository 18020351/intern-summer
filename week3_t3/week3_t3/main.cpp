#include"class_Base.h"
#include"class_Close.h"
#include"class_Context.h"
#include"class_Lock.h"
#include"class_Open.h"
using namespace std;
int main() {
	
	Context* context = new Context(new Close());

	context->getState()->close_door(context);
	context->getState()->open_door(context);
	context->getState()->lock_door(context);
	context->getState()->close_door(context);
	context->getState()->open_door(context);
	context->getState()->unlook_door(context);
	context->getState()->open_door(context);

	delete context;
	return 0;
}