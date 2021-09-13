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
#include<fstream>
#include "AnimationSprite.h"
#include "ParallelBG.h"
#include"classSound.h"
#include"GameStateMachine.h"
#include"Singleton.h"
#include<iostream>
using namespace std;

ClassSound * GSPlay::music_bg  = new ClassSound("../Data/Textures/sound/music_bg.wav");

GSPlay::GSPlay()
{
}


GSPlay::~GSPlay()
{
}

int GSPlay::inFile(std::string fileName) {
	ifstream f(fileName);
	string maxScore;
	f>>maxScore;
	reverse(maxScore.begin(), maxScore.end());
	long long binarynum = stoi(maxScore);
	int decimalnum = 0, temp = 0, remainder;
	while (binarynum != 0)
	{
		remainder = binarynum % 10;
		binarynum = binarynum / 10;
		decimalnum = decimalnum + remainder * pow(2, temp);
		temp++;
	}
	return (decimalnum - 2)/5;
}
void GSPlay::outFile(std::string fileName, int Max_score) {
	int temp1 = Max_score * 5 + 2; // tự quy ước
	string s = "";
	while (temp1 != 0) {
		int temp = temp1 % 2;
		temp1 /= 2;
		s += std::to_string(temp);
	}
	ofstream outfile(fileName);
	outfile << s;
}
void GSPlay::Init()
{
	if (Globals::isMusic) {
		music_bg->PlayLoopSound();
	}

	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto texture = ResourceManagers::GetInstance()->GetTexture("./images/img_bg1.tga");

	// background
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_background = std::make_shared<ParallelBG>(model, shader, texture, 100.0f);
	

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
	
	// button prev
	texture = ResourceManagers::GetInstance()->GetTexture("btn_prev.tga");
	std::shared_ptr<GameButton>  button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(50, 50);
	button->SetSize(50, 50);
	button->SetOnClick([]() {
		GameStateMachine::GetInstance()->PopState();
		});
	m_listButton.push_back(button);
	// button pause
	texture = ResourceManagers::GetInstance()->GetTexture("btn_pause.tga");
	std::shared_ptr<GameButton>  button_pause = std::make_shared<GameButton>(model, shader, texture);
	button_pause->Set2DPosition(350, 50);
	button_pause->SetSize(50, 50);
	button_pause->SetOnClick([]() {
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_PAUSE);
		});
	m_listButton.push_back(button_pause);
	//button replay
	texture = ResourceManagers::GetInstance()->GetTexture("btn_restart.tga");
	std::shared_ptr<GameButton>  button_replay = std::make_shared<GameButton>(model, shader, texture);
	button_replay->Set2DPosition(200, 50);
	button_replay->SetSize(50, 50);
	button_replay->SetOnClick([]() {
		music_bg->Stop();
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_PLAY);
		});
	m_listButton.push_back(button_replay);
	// score
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("Brightly Crush Shine.otf");

	

	//string text_MaxScore = convert_int_to_string(inFile("src/score.txt"));
	
	m_score = std::make_shared< Text>(shader, font, "Score: " + std::to_string(score), TextColor::RED, 0.8);
	m_score->Set2DPosition(Vector2(5, 20));

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
			if (Globals::isSound) {
				sound_wing->PlaySound();
			}
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
	if ((m_bird->Get_position_y() + bird_height / 2) >= 700) {
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
		
			m_score = std::make_shared< Text>(shader, font, "Score: " + std::to_string(score), TextColor::RED, 0.8);
			m_score->Set2DPosition(Vector2(5, 20));
			if (Globals::isSound) {
				sound_point->PlaySound();
			}
		}
		if (m_bird->Get_position_x() >= m_tube2_dow->Get_position_x() + tube_width && tube2_pass == false) {
			score += 1;
			tube2_pass = true;
			auto shader = ResourceManagers::GetInstance()->GetShader("TextShader");
			std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("Brightly Crush Shine.otf");
			
			m_score = std::make_shared< Text>(shader, font, "Score: " + std::to_string(score), TextColor::RED, 0.8);
			m_score->Set2DPosition(Vector2(5, 20));
			if (Globals::isSound) {
				sound_point->PlaySound();
			}
		}
		if (m_bird->Get_position_x() >= m_tube3_dow->Get_position_x() + tube_width && tube3_pass == false) {
			score += 1;
			tube3_pass = true;
			auto shader = ResourceManagers::GetInstance()->GetShader("TextShader");
			std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("Brightly Crush Shine.otf");
			
			
			m_score = std::make_shared< Text>(shader, font, "Score: " + std::to_string(score), TextColor::RED, 0.8);
			m_score->Set2DPosition(Vector2(5, 20));
			if (Globals::isSound) {
				sound_point->PlaySound();
			}
		}
		//update level
		if (score == 5) {
			velocity = 120;
		}
		if (score == 10) {
			velocity = 150;
		}
		if (score == 15) {
			velocity = 200;
		}
		if (score == 17) {
			velocity = 230;
		}
		if (score == 20) {
			velocity = 250;
		}
		if (score == 22) {
			velocity = 270;
		}
		if (score == 25) {
			velocity = 300;
		}
		//move bird
		if (keyPressed & KEY_UP) {
			//move up bird.
			y_bird -= 0.4;
			m_bird->Set2DPosition(x_bird, y_bird);	
			
		}
		
		if (!keyPressed) {
			y_bird += 0.8;
			x_bird = x_bird;
			m_bird->Set2DPosition(x_bird, y_bird);
		}
		for (auto it : m_listButton)
		{
			it->Update(deltaTime);
		}
		m_bird->Update(deltaTime);
		m_background->Update(deltaTime);

	}
	else{	
		auto shader = ResourceManagers::GetInstance()->GetShader("TextShader");
		std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("Brightly Crush Shine.otf");
		
		m_score = std::make_shared< Text>(shader, font, "Game over, Your score: " + std::to_string(score), TextColor::RED, 1.0);
		m_score->Set2DPosition(Vector2(60, 350));
		
		if (score > inFile("src/score.txt")) {
			outFile("src/score.txt", score);
		}
		music_bg->Stop();
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
	
	for (auto it : m_listButton)
	{
		it->Draw();
	}
	
}