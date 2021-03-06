#pragma once
#include "GameStateBase.h"
#include"classSound.h"
#include"GSPlay.h"


class Sprite2D;
class Sprite3D;
class Text;
class GameButton;

class GSSetting :
    public GameStateBase
{
public:
	GSSetting();
	~GSSetting();
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
private:
	std::shared_ptr<Sprite2D>	m_background;
	std::shared_ptr<Text>		m_text_onSound;
	std::shared_ptr<Text>		m_text_offSound;
	std::shared_ptr<Text>		m_text_onMusic;
	std::shared_ptr<Text>		m_text_offMusic;
	std::list<std::shared_ptr<GameButton>>	m_listButton;
};

