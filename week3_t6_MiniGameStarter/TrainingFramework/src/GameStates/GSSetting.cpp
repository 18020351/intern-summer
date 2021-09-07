#include "GSSetting.h"
#include "Shader.h"
#include "Texture.h"
#include "Model.h"
#include "Camera.h"
#include "Font.h"
#include "Sprite2D.h"
#include "Sprite3D.h"
#include "Text.h"
#include "GameButton.h"

GSSetting::GSSetting(){}
GSSetting::~GSSetting(){}

void GSSetting::Init()
{
	

	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto texture = ResourceManagers::GetInstance()->GetTexture("./images/background_menu.tga");

	// background
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_background = std::make_shared<Sprite2D>(model, shader, texture);
	m_background->Set2DPosition((float)Globals::screenWidth / 2, (float)Globals::screenHeight / 2);
	m_background->SetSize(Globals::screenWidth, Globals::screenHeight);

	// button on sound
	texture = ResourceManagers::GetInstance()->GetTexture("btn_music.tga");
	std::shared_ptr<GameButton> button_onSound = std::make_shared<GameButton>(model, shader, texture);
	button_onSound->Set2DPosition(200, 400);
	button_onSound->SetSize(55, 55);
	button_onSound->SetOnClick([]() {
		Globals::isSound = true;
		classSound* onSound = new classSound("../Data/Textures/sound/point.wav");
		onSound->classSound::PlaySound();
		});
	m_listButton.push_back(button_onSound);

	//button off sound
	texture = ResourceManagers::GetInstance()->GetTexture("btn_music_off.tga");
	std::shared_ptr<GameButton>  button_offSound = std::make_shared<GameButton>(model, shader, texture);
	button_offSound->Set2DPosition(200, 500);
	button_offSound->SetSize(55, 55);
	button_offSound->SetOnClick([]() {
		Globals::isSound = false;
		classSound* onSound = new classSound("../Data/Textures/sound/point.wav");
		onSound->classSound::PlaySound();
		});
	m_listButton.push_back(button_offSound);
	// button prev
	// button prev
	texture = ResourceManagers::GetInstance()->GetTexture("btn_prev.tga");
	std::shared_ptr<GameButton>  button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(50, 50);
	button->SetSize(50, 50);
	button->SetOnClick([]() {
		GameStateMachine::GetInstance()->PopState();
		});
	m_listButton.push_back(button);
	//title resume
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("Brightly Crush Shine.otf");
	m_text_onSound = std::make_shared< Text>(shader, font, "On Sound", Vector4(0.5f, 0.5f, 0.0f, 1.0f), 1.0f);
	m_text_onSound->Set2DPosition(Vector2(160, 450));
	// tile replay

	m_text_offSound = std::make_shared< Text>(shader, font, "Off Sound", Vector4(0.5f, 0.5f, 0.0f, 1.0f), 1.0f);
	m_text_offSound->Set2DPosition(Vector2(160, 550));

}

void GSSetting::Exit()
{
}


void GSSetting::Pause()
{
}

void GSSetting::Resume()
{
}


void GSSetting::HandleEvents()
{
}

void GSSetting::HandleKeyEvents(int key, bool bIsPressed)
{
}

void GSSetting::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	for (auto button : m_listButton)
	{
		if (button->HandleTouchEvents(x, y, bIsPressed))
		{
			break;
		}
	}
}

void GSSetting::HandleMouseMoveEvents(int x, int y)
{
}

void GSSetting::Update(float deltaTime)
{
	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
	}
}

void GSSetting::Draw()
{
	m_background->Draw();
	for (auto it : m_listButton)
	{
		it->Draw();
	}
	m_text_onSound->Draw();
	m_text_offSound->Draw();
}