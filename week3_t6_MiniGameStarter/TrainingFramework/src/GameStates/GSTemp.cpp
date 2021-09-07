#include "GSTemp.h"
#include "Shader.h"
#include "Texture.h"
#include "Model.h"
#include "Camera.h"
#include "Font.h"
#include "Sprite2D.h"
#include "Sprite3D.h"
#include "Text.h"
#include "GameButton.h"

GSTemp::GSTemp(){}
GSTemp::~GSTemp() {}

void GSTemp::Init()
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto texture = ResourceManagers::GetInstance()->GetTexture("./images/background_menu.tga");

	// background
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_background = std::make_shared<Sprite2D>(model, shader, texture);
	m_background->Set2DPosition((float)Globals::screenWidth / 2, (float)Globals::screenHeight / 2);
	m_background->SetSize(Globals::screenWidth, Globals::screenHeight);

	// button resume
	texture = ResourceManagers::GetInstance()->GetTexture("btn_play.tga");
	std::shared_ptr<GameButton> button_resume = std::make_shared<GameButton>(model, shader, texture);
	button_resume->Set2DPosition(200, 400);
	button_resume->SetSize(55, 55);
	button_resume->SetOnClick([]() {
		GameStateMachine::GetInstance()->PopState();
		});
	m_listButton.push_back(button_resume);

	//button replay
	texture = ResourceManagers::GetInstance()->GetTexture("btn_restart.tga");
	std::shared_ptr<GameButton>  button_replay = std::make_shared<GameButton>(model, shader, texture);
	button_replay->Set2DPosition(200, 500);
	button_replay->SetSize(55, 55);
	button_replay->SetOnClick([]() {
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_PLAY);
		});
	m_listButton.push_back(button_replay);
	//button setting
	texture = ResourceManagers::GetInstance()->GetTexture("btn_settings.tga");
	std::shared_ptr<GameButton> button_setting = std::make_shared<GameButton>(model, shader, texture);
	button_setting->Set2DPosition(200, 600);
	button_setting->SetSize(55, 55);
	button_setting->SetOnClick([]() {
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_SETTING);
		});
	m_listButton.push_back(button_setting);
	//title resume
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("Brightly Crush Shine.otf");
	m_text_resume = std::make_shared< Text>(shader, font, "Resume", Vector4(0.5f, 0.5f, 0.0f, 1.0f), 1.0f);
	m_text_resume->Set2DPosition(Vector2(165, 450));
	// tile replay
	m_text_replay = std::make_shared< Text>(shader, font, "Replay", Vector4(0.5f, 0.5f, 0.0f, 1.0f), 1.0f);
	m_text_replay->Set2DPosition(Vector2(165, 550));
	// title setting
	m_text_setting = std::make_shared< Text>(shader, font, "Setting", Vector4(0.5f, 0.5f, 0.0f, 1.0f), 1.0f);
	m_text_setting->Set2DPosition(Vector2(160, 650));
}

void GSTemp::Exit()
{
}


void GSTemp::Pause()
{
}

void GSTemp::Resume()
{
}


void GSTemp::HandleEvents()
{
}

void GSTemp::HandleKeyEvents(int key, bool bIsPressed)
{
}

void GSTemp::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	for (auto button : m_listButton)
	{
		if (button->HandleTouchEvents(x, y, bIsPressed))
		{
			break;
		}
	}
}

void GSTemp::HandleMouseMoveEvents(int x, int y)
{
}

void GSTemp::Update(float deltaTime)
{
	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
	}
}

void GSTemp::Draw()
{
	m_background->Draw();
	for (auto it : m_listButton)
	{
		it->Draw();
	}
	m_text_resume->Draw();
	m_text_replay->Draw();
	m_text_setting->Draw();
}