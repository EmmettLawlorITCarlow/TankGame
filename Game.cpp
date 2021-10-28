#include "Game.h"
#include <iostream>

// Updates per milliseconds
static double const MS_PER_UPDATE = 10.0;

////////////////////////////////////////////////////////////
Game::Game()
	: m_window(sf::VideoMode(ScreenSize::s_width, ScreenSize::s_height, 32), "SFML Playground", sf::Style::Default)
{
	m_window.setVerticalSyncEnabled(true);
	initialiseTank();
}

////////////////////////////////////////////////////////////
void Game::run()
{
	sf::Clock clock;
	sf::Int32 lag = 0;

	while (m_window.isOpen())
	{
		sf::Time dt = clock.restart();

		lag += dt.asMilliseconds();

		processEvents();

		while (lag > MS_PER_UPDATE)
		{
			update(lag);
			lag -= MS_PER_UPDATE;
		}
		update(lag);

		render();
	}
}

////////////////////////////////////////////////////////////
void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_window.close();
		}
		processGameEvents(event);
	}
}

////////////////////////////////////////////////////////////
void Game::processGameEvents(sf::Event& event)
{
	// check if the event is a a mouse button release
	if (sf::Event::KeyPressed == event.type)
	{
		switch (event.key.code)
		{
		case sf::Keyboard::Escape:
			m_window.close();
			break;
		case sf::Keyboard::W:
			m_sprite.setRotation(180.f);
			break;

		case sf::Keyboard::S:
			m_sprite.setRotation(0.f);
			break;

		case sf::Keyboard::A:
			m_sprite.setRotation(90.f);
			break;
		
		case sf::Keyboard::D:
			m_sprite.setRotation(270.f);
		default:
			break;
		}
	}
}

void Game::initialiseTank()
{

	if (!m_spriteTexture.loadFromFile("E-100.png"))
	{
		std::string s("Error loading texture");
		throw std::exception(s.c_str());
	}

	m_sprite.setTexture(m_spriteTexture);
	m_sprite.setOrigin(48.f, 103.5f); //halfed 96 and 207 dimensions
	m_sprite.setPosition(300, 400); //sets position of sprite in window
}

void Game::rotateTank()
{


	//this could all be avoided by rotating the tank before beginning to code by using the rotate option when
	//viewing the image. Commented out as used earlier function for the rotations. 
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		//m_sprite.setRotation(90.f); 
		//result is sprites cannon faces left because the sprites texture was facing down. 
	}


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) //faces the right. 
	{
		//m_sprite.setRotation(270.f); 
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		//m_sprite.setRotation(0.f); //usually 0 corresponds to right on sfml, but this is down

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		//m_sprite.setRotation(180.f); //faces up
	}
}

////////////////////////////////////////////////////////////
void Game::update(double dt)
{
	//rotateTank();
}

////////////////////////////////////////////////////////////
void Game::render()
{
	m_window.clear(sf::Color(0, 0, 0, 0));
	m_window.draw(m_sprite); //to draw the sprite
	m_window.display();
}





