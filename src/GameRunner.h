/*
*	SW3 (SSE2034-41) Term Project
*	
*	Briefly explain : Declare game object
*
*	Copyright 2021 by 3-codiots
*/

#ifndef GAMERUNNER_H
#define GAMERUNNER_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <cstdlib> // rand()
#include <ctime> // time()
#include <cmath> // abs()
#include <string> // to_string()
#include "Brick.h"
#include "Ball.h"
#include "Paddle.h"
#define PLAYER1 1
#define PLAYER2 2

class Game{
private:
	// initial value
	const int BRICKS_PER_ROW = 10;
	const int BRICKS_PER_COL = 3;
	const float BALL_RADIUS = 6;
	const float PADDLE_SPEED = 5.0;
	const float BALL_SPEED = 4.0;
	
	// variable
	int screen_width;
	int screen_height;
	bool is_start_page;
	bool is_game_start;
	int is_game_end;

	// Bricks
	float gap;
	std::vector<Brick> p1_b;
	std::vector<Brick> p2_b;
	sf::SoundBuffer bufferBricks;
	sf::Sound soundBricks;

	// Paddle
	Paddle p1;
	Paddle p2;
	bool p1_item2_timer;
	bool p1_item3_timer;
	bool p2_item2_timer;
	bool p2_item3_timer;
	sf::SoundBuffer bufferPaddle;
	sf::Sound soundPaddle;

	// item slot
	sf::Texture p1_item;
	sf::Texture p2_item;
	sf::Sprite p1_item_slot;
	sf::Sprite p2_item_slot;

	// item1
	sf::SoundBuffer bufferBomb;
	sf::Sound soundBomb;
	
	sf::Texture item1_1;
	sf::Texture item1_2;
	sf::Texture item1_3;
	sf::Sprite p1_s_item1_1;
	sf::Sprite p1_s_item1_2;
	sf::Sprite p1_s_item1_3;
	sf::Sprite p2_s_item1_1;
	sf::Sprite p2_s_item1_2;
	sf::Sprite p2_s_item1_3;

	// item2
	sf::Texture item2_1;
	sf::Texture item2_2;
	sf::Texture item2_3;
	sf::Sprite p1_s_item2_1;
	sf::Sprite p1_s_item2_2;
	sf::Sprite p1_s_item2_3;
	sf::Sprite p2_s_item2_1;
	sf::Sprite p2_s_item2_2;
	sf::Sprite p2_s_item2_3;

	// item3
	sf::Texture item3_1;
	sf::Texture item3_2;
	sf::Texture item3_3;
	sf::Sprite p1_s_item3_1;
	sf::Sprite p1_s_item3_2;
	sf::Sprite p1_s_item3_3;
	sf::Sprite p2_s_item3_1;
	sf::Sprite p2_s_item3_2;
	sf::Sprite p2_s_item3_3;

	// Ball
	std::vector<Ball> balls;

	// Event
	sf::Event event;

	// Window
	sf::RenderWindow window;
	
	//bgm
	sf::Music bgm;
public:
	Game(int w, int h);

	void gameStart();
	void gameRunning();
	void receiveKeyinputs();
	void object_draw();

	void ball_wall_collision();
	void ball_paddle_collision();
	void ball_brick_collision(Ball &ball);
	void p1_get_item(Brick &brick);
	void p2_get_item(Brick &brick);
};

#endif
