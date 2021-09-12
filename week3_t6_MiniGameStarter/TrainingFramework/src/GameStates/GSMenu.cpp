#include "GSMenu.h"
#include "Camera.h"

GSMenu::GSMenu() : GameStateBase(StateType::STATE_MENU), 
	m_background(nullptr), m_listButton(std::list<std::shared_ptr<GameButton>>{}), m_textGameName(nullptr)
{
}


GSMenu::~GSMenu()
{
}



void GSMenu::Init()
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto texture = ResourceManagers::GetInstance()->GetTexture("./images/background_menu.tga");

	// background
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_background = std::make_shared<Sprite2D>(model, shader, texture);
	m_background->Set2DPosition(Globals::screenWidth / 2, Globals::screenHeight / 2);
	m_background->SetSize(Globals::screenWidth, Globals::screenHeight);
	
	// play button
	texture = ResourceManagers::GetInstance()->GetTexture("btn_play.tga");
	std::shared_ptr<GameButton> button_play = std::make_shared<GameButton>(model, shader, texture);
	button_play->Set2DPosition(200, 345);
	button_play->SetSize(55, 55);
	button_play->SetOnClick([]() {
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_PLAY);
		});
	m_listButton.push_back(button_play);
	// setting button
	texture = ResourceManagers::GetInstance()->GetTexture("btn_settings.tga");
	std::shared_ptr<GameButton> button_setting = std::make_shared<GameButton>(model, shader, texture);
	button_setting->Set2DPosition(200, 445);
	button_setting->SetSize(55, 55);
	button_setting->SetOnClick([]() {
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_SETTING);
		});
	m_listButton.push_back(button_setting);
	//high score button
	texture = ResourceManagers::GetInstance()->GetTexture("btn_menu.tga");
	std::shared_ptr<GameButton> button_HighScore = std::make_shared<GameButton>(model, shader, texture);
	button_HighScore->Set2DPosition(200, 545);
	button_HighScore->SetSize(55, 55);
	button_HighScore->SetOnClick([]() {
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_HIGHSCORE);
		});
	m_listButton.push_back(button_HighScore);
	// credit button
	texture = ResourceManagers::GetInstance()->GetTexture("btn_help.tga");
	std::shared_ptr<GameButton> button_credit = std::make_shared<GameButton>(model, shader, texture);
	button_credit->Set2DPosition(200, 645);
	button_credit->SetSize(55, 55);
	button_credit->SetOnClick([]() {
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_CREDIT);
		});
	m_listButton.push_back(button_credit);
	// exit button
	texture = ResourceManagers::GetInstance()->GetTexture("btn_close.tga");
	std::shared_ptr<GameButton> button_close = std::make_shared<GameButton>(model, shader, texture);
	button_close->Set2DPosition(Globals::screenWidth - 50, 50);
	button_close->SetSize(50, 50);
	button_close->SetOnClick([]() {
		exit(0);
		});
	m_listButton.push_back(button_close);

	// game title
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("Brightly Crush Shine.otf");
	m_textGameName = std::make_shared< Text>(shader, font, "Duc.NV-Flappy Bird", Vector4(0.5f, 0.5f, 0.0f, 1.0f), 1.7f);
	m_textGamePlay = std::make_shared< Text>(shader, font, "Play", Vector4(0.5f, 0.5f, 0.0f, 1.0f), 1.0f);
	m_textGameSetting = std::make_shared< Text>(shader, font, "Setting", Vector4(0.5f, 0.5f, 0.0f, 1.0f), 1.0f);
	m_textGameCredit = std::make_shared< Text>(shader, font, "Credit", Vector4(0.5f, 0.5f, 0.0f, 1.0f), 1.0f);
	m_textHighScore = std::make_shared< Text>(shader, font, "High Score", Vector4(0.5f, 0.5f, 0.0f, 1.0f), 1.0f);

	m_textGameName->Set2DPosition(Vector2(20, 295));
	m_textGamePlay->Set2DPosition(Vector2(175, 395));
	m_textGameSetting->Set2DPosition(Vector2(165, 495));
	m_textHighScore->Set2DPosition(Vector2(150, 595));
	m_textGameCredit->Set2DPosition(Vector2(165, 695));
	

}

void GSMenu::Exit()
{
}


void GSMenu::Pause()
{
}

void GSMenu::Resume()
{
}


void GSMenu::HandleEvents()
{
}

void GSMenu::HandleKeyEvents(int key, bool bIsPressed)
{
}

void GSMenu::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	for (auto button : m_listButton)
	{
		if (button->HandleTouchEvents(x, y, bIsPressed))
		{
			break;
		}
	}
}

void GSMenu::HandleMouseMoveEvents(int x, int y)
{
}

void GSMenu::Update(float deltaTime)
{
	m_background->Update(deltaTime);
	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
	}
}

void GSMenu::Draw()
{
	m_background->Draw();
	for (auto it : m_listButton)
	{
		it->Draw();
	}
	m_textGameName->Draw();
	m_textGamePlay->Draw();
	m_textGameSetting->Draw();
	m_textGameCredit->Draw();
	m_textHighScore->Draw();
}
