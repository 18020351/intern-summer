#include"class_Context.h"
#include"class_Base.h"

Context::Context(Base* door_state) {
	m_door_state = door_state;
}
void Context::setState(Base* door_state) {
	m_door_state = door_state;
}
Base* Context::getState() {
	return m_door_state;
}