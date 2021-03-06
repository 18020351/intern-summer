#pragma once
#include "GameStateBase.h"
#include <iostream>
#include"classSound.h"
#include<vector>
#include<fstream>

class Sprite2D;
class Sprite3D;
class Text;
class GameButton;
class AnimationSprite;
class ParallelBG;

class GSPlay :
	public GameStateBase
{
public:
	GSPlay();
	~GSPlay();

	void	Init() override;
	void	Exit() override;

	void	Pause() override;
	void	Resume() override;

	void	HandleEvents() override;
	void	HandleKeyEvents(int key, bool bIsPressed) override;
	void	HandleTouchEvents(int x, int y, bool bIsPressed) override;
	void	HandleMouseMoveEvents(int x, int y) override;
	void	Update(float deltaTime) override;
	void	Draw() override;

	bool Check_collision();

	int inFile(std::string fileName);

	void outFile(std::string fileName, int Max_score);

	static ClassSound* music_bg;

private:
	std::shared_ptr<ParallelBG>	m_background;
	

	std::shared_ptr<Sprite2D>	m_tube1_dow;
	std::shared_ptr<Sprite2D>	m_tube2_dow;
	std::shared_ptr<Sprite2D>	m_tube3_dow;

	std::shared_ptr<Sprite2D>	m_tube1_up;
	std::shared_ptr<Sprite2D>	m_tube2_up;
	std::shared_ptr<Sprite2D>	m_tube3_up;

	std::shared_ptr<AnimationSprite>	m_bird;
	std::shared_ptr<Sprite2D>	m_sand;
	std::shared_ptr<Text>		m_score;
	std::list<std::shared_ptr<GameButton>>	m_listButton;

	ClassSound* sound_wing = new ClassSound("../Data/Textures/sound/wing.wav");;
	ClassSound* sound_point = new ClassSound("../Data/Textures/sound/point.wav");
	ClassSound* sound_die = new ClassSound("../Data/Textures/sound/hit.wav");
	

	float velocity = 100.0f;

	int x_bird = 50;
	float y_bird = 350.0;

	int bird_width = 40;
	int bird_height = 40;

	int	tube1_x = 400;
	int	tube2_x = 600;
	int	tube3_x = 800;
	int	tube_y = 0;

	int d_2tube = 200;

	int score = 0;

	int tube_width = 50;
	int tube1_height = (100 + rand() % 400);
	int tube2_height = (100 + rand() % 400);
	int tube3_height = (100 + rand() % 400);

	bool tube1_pass = false;
	bool tube2_pass = false;
	bool tube3_pass = false;

};

