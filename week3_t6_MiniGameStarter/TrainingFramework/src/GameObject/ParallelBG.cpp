#include "ParallelBG.h"
#include "Sprite2D.h"
#include "Shader.h"
#include "Model.h"
#include "Camera.h"
#include "Texture.h"
#include "Application.h"

ParallelBG::ParallelBG() : m_time(0.0f), m_speed(0.0f)
{}
ParallelBG::ParallelBG(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture, GLfloat speed)
	: BaseObject(0, model, shader, texture), m_speed(speed), m_time(0.0f)
{
	m_background = std::make_shared<Sprite2D>(model, shader, texture);
	m_background->Set2DPosition(Globals::screenWidth / 2, Globals::screenHeight / 2);
	m_background->SetSize(Globals::screenWidth, Globals::screenHeight);

	m_background1 = std::make_shared<Sprite2D>(model, shader, texture);
	m_background1->Set2DPosition(Globals::screenWidth / 2 + Globals::screenWidth, Globals::screenHeight / 2);
	m_background1->SetSize(Globals::screenWidth, Globals::screenHeight);
	Init();
}
void ParallelBG::Init()
{
	SetCamera(Application::GetInstance()->GetCamera());
	CalculateWorldMatrix();
}

void ParallelBG::Draw()
{
	m_background->Draw();
	m_background1->Draw();
	/*if (m_pCamera == nullptr) return;
	glUseProgram(m_pShader->m_program);
	glBindBuffer(GL_ARRAY_BUFFER, m_pModel->GetVertexObject());
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_pModel->GetIndiceObject());

	GLuint iTempShaderVaribleGLID = -1;
	Matrix wvpMatrix;

	wvpMatrix = m_worldMatrix * m_pCamera->GetLookAtCameraMatrix();

	if (m_pTexture != nullptr)
	{
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, m_pTexture->Get2DTextureAdd());
		if (m_pShader->m_iTextureLoc[0] != -1)
			glUniform1i(m_pShader->m_iTextureLoc[0], 0);
	}
	else
	{
		iTempShaderVaribleGLID = -1;
		iTempShaderVaribleGLID = m_pShader->GetUniformLocation((char*)"u_color");
		if (iTempShaderVaribleGLID != -1)
			glUniform4f(iTempShaderVaribleGLID, m_color.x, m_color.y, m_color.z, m_color.w);
	}


	iTempShaderVaribleGLID = -1;
	iTempShaderVaribleGLID = m_pShader->GetAttribLocation((char*)"a_posL");
	if (iTempShaderVaribleGLID != -1)
	{
		glEnableVertexAttribArray(iTempShaderVaribleGLID);
		glVertexAttribPointer(iTempShaderVaribleGLID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), VETEX_POSITION);
	}

	iTempShaderVaribleGLID = -1;
	iTempShaderVaribleGLID = m_pShader->GetAttribLocation((char*)"a_uv");
	if (iTempShaderVaribleGLID != -1)
	{
		glEnableVertexAttribArray(iTempShaderVaribleGLID);
		glVertexAttribPointer(iTempShaderVaribleGLID, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), VETEX_UV);
	}

	iTempShaderVaribleGLID = -1;
	iTempShaderVaribleGLID = m_pShader->GetUniformLocation((char*)"u_alpha");
	if (iTempShaderVaribleGLID != -1)
		glUniform1f(iTempShaderVaribleGLID, 1.0);

	iTempShaderVaribleGLID = -1;
	iTempShaderVaribleGLID = m_pShader->GetUniformLocation((char*)"u_wvpMatrix");
	if (iTempShaderVaribleGLID != -1)
		glUniformMatrix4fv(iTempShaderVaribleGLID, 1, GL_FALSE, wvpMatrix.m[0]);

	

	glDrawElements(GL_TRIANGLES, m_pModel->GetNumIndiceObject(), GL_UNSIGNED_INT, 0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindTexture(GL_TEXTURE_2D, 0);*/

}

void ParallelBG::Update(GLfloat deltatime)
{
	m_time += deltatime;
	Vector2 deltaMove = Vector2(-1, 0) * m_speed * deltatime;
	m_background->Set2DPosition(m_background->GetPosition().x + deltaMove.x, m_background->GetPosition().y + deltaMove.y);
	if (m_background->GetPosition().x < - Globals::screenWidth / 2) {
		m_background->Set2DPosition(Globals::screenWidth + Globals::screenWidth / 2, m_background->GetPosition().y);
	}

	m_background1->Set2DPosition(m_background1->GetPosition().x + deltaMove.x, m_background1->GetPosition().y + deltaMove.y);
	if (m_background1->GetPosition().x < -Globals::screenWidth / 2) {
		m_background1->Set2DPosition(Globals::screenWidth + Globals::screenWidth / 2, m_background1->GetPosition().y);
	}
}