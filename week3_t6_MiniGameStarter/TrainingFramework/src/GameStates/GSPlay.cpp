#include "GSPlay.h"

#include "Shader.h"
#include "Texture.h"
#include "Model.h"
#include "Camera.h"
#include "Font.h"
#include "Sprite2D.h"
#include "Sprite3D.h"
#include "Text.h"
#include "GameButton.h"
#include <string>

#include "AnimationSprite.h"

GSPlay::GSPlay()
{
}


GSPlay::~GSPlay()
{
}
std::string convert_int_to_string(int a) {
	std::stringstream ss;
	ss << a;
	std::string str = ss.str();
	return "Score: " + str;
}
void GSPlay::Init()
{

	//
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto texture = ResourceManagers::GetInstance()->GetTexture("./images/bg_play.tga");

	// background
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_background = std::make_shared<Sprite2D>(model, shader, texture);
	m_background->Set2DPosition((float)Globals::screenWidth / 2, (float)Globals::screenHeight / 2);
	m_background->SetSize(Globals::screenWidth, Globals::screenHeight);
	// tube dow
	texture = ResourceManagers::GetInstance()->GetTexture("tube_dow.tga");
	m_tube1_dow = std::make_shared<Sprite2D>(model, shader, texture);
	m_tube1_dow->Set2DPosition(tube1_x, tube_y + tube1_height/2);
	m_tube1_dow->SetSize(tube_width, tube1_height);

	m_tube2_dow = std::make_shared<Sprite2D>(model, shader, texture);
	m_tube2_dow->Set2DPosition(tube2_x, tube_y + tube2_height/2);
	m_tube2_dow->SetSize(tube_width, tube2_height);

	m_tube3_dow = std::make_shared<Sprite2D>(model, shader, texture);
	m_tube3_dow->Set2DPosition(tube3_x, tube_y + tube3_height/2);
	m_tube3_dow->SetSize(tube_width, tube3_height);
	// tube up
	texture = ResourceManagers::GetInstance()->GetTexture("tube_up.tga");
	m_tube1_up = std::make_shared<Sprite2D>(model, shader, texture);
	m_tube1_up->Set2DPosition(tube1_x, tube1_height + d_2tube + (700-tube1_height-d_2tube)/2);
	m_tube1_up->SetSize(tube_width, 700 - tube1_height - d_2tube);

	m_tube2_up = std::make_shared<Sprite2D>(model, shader, texture);
	m_tube2_up->Set2DPosition(tube2_x, tube2_height + d_2tube + (700 - tube2_height - d_2tube) / 2);
	m_tube2_up->SetSize(tube_width, 700 - tube2_height - d_2tube);

	m_tube3_up = std::make_shared<Sprite2D>(model, shader, texture);
	m_tube3_up->Set2DPosition(tube3_x, tube3_height + d_2tube + (700 - tube3_height - d_2tube) / 2);
	m_tube3_up->SetSize(tube_width,700 - tube3_height - d_2tube);
	
	// sand
	texture = ResourceManagers::GetInstance()->GetTexture("sand1.tga");
	m_sand = std::make_shared<Sprite2D>(model, shader, texture);
	m_sand->Set2DPosition(0, 670);
	m_sand->SetSize(800, 60);
	// button clode
	texture = ResourceManagers::GetInstance()->GetTexture("btn_prev.tga");
	std::shared_ptr<GameButton>  button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(50, 50);
	button->SetSize(50, 50);
	button->SetOnClick([]() {
		GameStateMachine::GetInstance()->PopState();
		});
	m_listButton.push_back(button);

	// score
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("Brightly Crush Shine.otf");
	std::string temp_score = convert_int_to_string(score);
	m_score = std::make_shared< Text>(shader, font, temp_score , TextColor::RED, 1.0);
	m_score->Set2DPosition(Vector2(5, 25));

	// bird
	texture = ResourceManagers::GetInstance()->GetTexture("bird.tga");
	shader = ResourceManagers::GetInstance()->GetShader("AnimationShader");
	m_bird = std::make_shared<AnimationSprite>(model, shader, texture, 3, 0.1f);
	m_bird->Set2DPosition(x_bird, y_bird);
	m_bird->SetSize(bird_width, bird_height);
	
}

void GSPlay::Exit()
{
}


void GSPlay::Pause()
{
}

void GSPlay::Resume()
{
}


void GSPlay::HandleEvents()
{
}

void GSPlay::HandleKeyEvents(int key, bool bIsPressed)
{
	if (bIsPressed == true) {
		switch (key)
		{
		case ' ':
			keyPressed |= KEY_UP;
			break;
		default:
			break;
		}
	}
	else {
		switch (key)
		{
		case ' ':
			keyPressed ^= KEY_UP;
			break;
		default:
			break;
		}
	}
	
}

void GSPlay::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	for (auto button : m_listButton)
	{
		if(button->HandleTouchEvents(x, y, bIsPressed))
		{
			break;
		}
	}
}

void GSPlay::HandleMouseMoveEvents(int x, int y)
{
}
////collision handling
bool GSPlay::Check_collision() {
	if ((m_bird->Get_position_y() - bird_height/2) <= 0) {
		return true;
	}
	if ((m_bird->Get_position_y() + bird_height / 2) >= 640) {
		return true;
	}
	if (m_bird->Get_position_x() + bird_width / 2 >= m_tube1_dow->Get_position_x() - tube_width / 2 &&
		m_bird->Get_position_x() - bird_width / 2 <= m_tube1_dow->Get_position_x() + tube_width / 2) {
		if (m_bird->Get_position_y() - bird_height / 2 <= m_tube1_dow->Get_position_y() * 2) {
			return true;
		}
		else if (m_bird->Get_position_y() + bird_height / 2 >= m_tube1_dow->Get_position_y() * 2 + d_2tube) {
			return true;
		}
	}
	if (m_bird->Get_position_x() + bird_width / 2 >= m_tube2_dow->Get_position_x() - tube_width / 2 &&
		m_bird->Get_position_x() - bird_width / 2 <= m_tube2_dow->Get_position_x() + tube_width / 2) {
		if (m_bird->Get_position_y() - bird_height / 2 <= m_tube2_dow->Get_position_y() * 2) {
			return true;
		}
		else if (m_bird->Get_position_y() + bird_height / 2 >= m_tube2_dow->Get_position_y() * 2 + d_2tube) {
			return true;
		}
	}
	if (m_bird->Get_position_x() + bird_width / 2 >= m_tube3_dow->Get_position_x() - tube_width / 2 &&
		m_bird->Get_position_x() - bird_width / 2 <= m_tube3_dow->Get_position_x() + tube_width / 2) {
		if (m_bird->Get_position_y() - bird_height / 2 <= m_tube3_dow->Get_position_y() * 2) {
			return true;
		}
		else if (m_bird->Get_position_y() + bird_height / 2 >= m_tube3_dow->Get_position_y() * 2 + d_2tube) {
			return true;
		}
	}
	return false;
}
void GSPlay::Update(float deltaTime)
{
	//collision handling
	
	if (Check_collision() == false) {
		//move screen
		m_tube1_dow->Move(deltaTime, Vector2(-1, 0), velocity);
		m_tube2_dow->Move(deltaTime, Vector2(-1, 0), velocity);
		m_tube3_dow->Move(deltaTime, Vector2(-1, 0), velocity);
		m_tube1_up->Move(deltaTime, Vector2(-1, 0), velocity);
		m_tube2_up->Move(deltaTime, Vector2(-1, 0), velocity);
		m_tube3_up->Move(deltaTime, Vector2(-1, 0), velocity);

		// refresh tube
		if (m_tube1_dow->Is_Out_Of_Screen(tube_width)) {
			int temp_tube1_height = 100 + rand() % 400;
			tube1_x = 550;
			m_tube1_dow->Reset_position_dow(temp_tube1_height, tube1_x);
			m_tube1_up->Reset_position_up(temp_tube1_height);

			m_tube1_dow->Reset_size_dow(temp_tube1_height);
			m_tube1_up->Reset_size_up(temp_tube1_height);

			tube1_pass = false;

		}
		if (m_tube2_dow->Is_Out_Of_Screen(tube_width)) {
			int temp_tube2_height = 100 + rand() % 400;
			tube2_x = 550;
			m_tube2_dow->Reset_position_dow(temp_tube2_height, tube2_x);
			m_tube2_up->Reset_position_up(temp_tube2_height);

			m_tube2_dow->Reset_size_dow(temp_tube2_height);
			m_tube2_up->Reset_size_up(temp_tube2_height);

			tube2_pass = false;

		}
		if (m_tube3_dow->Is_Out_Of_Screen(tube_width)) {
			int temp_tube3_height = 100 + rand() % 400;
			tube3_x = 550;
			m_tube3_dow->Reset_position_dow(temp_tube3_height, tube3_x);
			m_tube3_up->Reset_position_up(temp_tube3_height);

			m_tube3_dow->Reset_size_dow(temp_tube3_height);
			m_tube3_up->Reset_size_up(temp_tube3_height);

			tube3_pass = false;

		}
		//update score. bird pass tube -> score++
		if (m_bird->Get_position_x() >= m_tube1_dow->Get_position_x() + tube_width && tube1_pass == false) {
			score += 1;
			tube1_pass = true;
			auto shader = ResourceManagers::GetInstance()->GetShader("TextShader");
			std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("Brightly Crush Shine.otf");
			std::string temp_score = convert_int_to_string(score);
			m_score = std::make_shared< Text>(shader, font, temp_score, TextColor::RED, 1.0);
			m_score->Set2DPosition(Vector2(5, 25));
		}
		if (m_bird->Get_position_x() >= m_tube2_dow->Get_position_x() + tube_width && tube2_pass == false) {
			score += 1;
			tube2_pass = true;
			auto shader = ResourceManagers::GetInstance()->GetShader("TextShader");
			std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("Brightly Crush Shine.otf");
			std::string temp_score = convert_int_to_string(score);
			m_score = std::make_shared< Text>(shader, font, temp_score, TextColor::RED, 1.0);
			m_score->Set2DPosition(Vector2(5, 25));
		}
		if (m_bird->Get_position_x() >= m_tube3_dow->Get_position_x() + tube_width && tube3_pass == false) {
			score += 1;
			tube3_pass = true;
			auto shader = ResourceManagers::GetInstance()->GetShader("TextShader");
			std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("Brightly Crush Shine.otf");
			std::string temp_score = convert_int_to_string(score);
			m_score = std::make_shared< Text>(shader, font, temp_score, TextColor::RED, 1.0);
			m_score->Set2DPosition(Vector2(5, 25));
		}
		//update level
		if (score == 5) {
			velocity = 120;
		}
		if (score == 10) {
			velocity = 150;
		}
		if (score == 15) {
			velocity == 200;
		}
		if (score > 20) {
			velocity == 300;
		}

		//move bird
		if (keyPressed & KEY_UP) {
			//move up bird.
			y_bird -= 0.4;
			m_bird->Set2DPosition(x_bird, y_bird);
		}
		
		if (!keyPressed) {
			y_bird += 1.0;
			x_bird = x_bird;
			m_bird->Set2DPosition(x_bird, y_bird);
		}
		for (auto it : m_listButton)
		{
			it->Update(deltaTime);
		}
		m_bird->Update(deltaTime);
	}
	else {
		auto shader = ResourceManagers::GetInstance()->GetShader("TextShader");
		std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("Brightly Crush Shine.otf");
		std::string temp_score = convert_int_to_string(score);
		m_score = std::make_shared< Text>(shader, font, "Game over, " + temp_score, TextColor::RED, 1.0);
		m_score->Set2DPosition(Vector2(60, 350));
	}
	
}

void GSPlay::Draw()
{
	m_background->Draw();

	m_tube1_dow->Draw();
	m_tube2_dow->Draw();
	m_tube3_dow->Draw();

	m_tube1_up->Draw();
	m_tube2_up->Draw();
	m_tube3_up->Draw();

	m_bird->Draw();

	m_score->Draw();

	m_sand->Draw();
	for (auto it : m_listButton)
	{
		it->Draw();
	}
	
}