#pragma once
#include "BaseObject.h"

class Sprite2D : public BaseObject
{
protected:
	GLint		m_iWidth;
	GLint		m_iHeight;
	GLuint		m_vboId;

public:
	Sprite2D() : BaseObject(), m_iWidth(0), m_iHeight(0), m_vboId(0) {}
	Sprite2D(GLint id, std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture);
	Sprite2D(GLint id, std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, Vector4 color);
	Sprite2D(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture);
	~Sprite2D();

	void		Init() override;
	void		Draw() override;
	void		Update(GLfloat deltatime) override;

	void		Set2DPosition(float x, float y);
	void		Set2DPosition(Vector2 position);
	void		SetSize(GLint width, GLint height);

	void Move(float deltaTime, Vector2 direction, float velocity);

	bool Is_Out_Of_Screen(float tube_width);


	int Get_position_x();

	int Get_position_y();

	void Reset_position_dow(int tube_height1, int tube_x);

	//void Reset_position_dow(int tube_height1);

	void Reset_size_dow(int tube_height1);

	void Reset_position_up(int tube_height);

	void Reset_size_up(int tube_height1);

	//int Reset_size1();

	
};

