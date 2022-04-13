//Name: Síne Whooley
//Student Number: C00271403
//Date: 13/04/22
//-----------------------
//Christmas Interactive
//-----------------------

#include "Game.h"
#include <iostream>
using namespace std;

/// default constructor
/// setup the window properties
/// load and setup the text 
Game::Game() :
	m_window{ sf::VideoMode{ 700U, 900U, 32U }, "Christmas Interactive" },
	m_exitGame{false}												//when true game will exit
{
	setupFontAndText();												// load font 
	setupSprite();													// load texture
	setupStockingA();
	setupStockingB();
	setupStockingC();

}

/// default destructor we didn't dynamically allocate anything
/// so we don't need to free it, but mthod needs to be here
Game::~Game()
{
}


/// main game loop
/// update 60 times per second,
/// process update as often as possible and at least 60 times per second
/// draw as often as possible but only updates are on time
/// if updates run slow then don't render frames
void Game::run()
{	
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	const float fps{ 60.0f };
	sf::Time timePerFrame = sf::seconds(1.0f / fps);			// 60 fps
	while (m_window.isOpen())
	{
		processEvents();										// as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents();									// at least 60 fps
			update(timePerFrame);								//60 fps
		}
		render();												// as many as possible
	}
}

/// handle user and system events/ input
/// get key presses/ mouse moves etc. from OS
/// and user :: Don't do game update here
void Game::processEvents()
{
	sf::Event newEvent;
	while (m_window.pollEvent(newEvent))
	{
		if ( sf::Event::Closed == newEvent.type)				// window message
		{
			m_exitGame = true;
		}
		if (sf::Event::KeyPressed == newEvent.type)				//user pressed a key
		{
			processKeys(newEvent);
		}
	}
}


/// deal with key presses from the user
void Game::processKeys(sf::Event t_event)
{
	if (sf::Keyboard::Escape == t_event.key.code)
	{
		m_exitGame = true;
	}
}

/// Update the game world
void Game::update(sf::Time t_deltaTime)
{
	if (m_exitGame)
	{
		m_window.close();
	}
}


/// draw the frame and then switch buffers
void Game::render()
{
	m_window.clear(sf::Color::White);
	m_window.draw(m_welcomeMessage);
	m_window.draw(m_logoSprite);
	m_window.draw(m_stockingASprite);
	m_window.draw(m_stockingBSprite);
	m_window.draw(m_stockingCSprite);
	m_window.display();
}

/// load the font and setup the text message for screen
void Game::setupFontAndText()
{
	if (!m_ArialBlackfont.loadFromFile("ASSETS\\FONTS\\Antonio-Regular.ttf"))
	{
		std::cout << "problem loading arial black font" << std::endl;
	}
	m_welcomeMessage.setFont(m_ArialBlackfont);
	m_welcomeMessage.setString("Happy Christmas");
	m_welcomeMessage.setStyle(sf::Text::Italic | sf::Text::Bold);
	m_welcomeMessage.setPosition(125.0f, 100.0f);
	m_welcomeMessage.setCharacterSize(70U);
	m_welcomeMessage.setOutlineColor(sf::Color::Black);
	m_welcomeMessage.setFillColor(sf::Color{ 219,31,7 });
	m_welcomeMessage.setOutlineThickness(2.0f);

}

/// load the texture and setup the sprite for the logo
void Game::setupSprite()
{
	if (!m_logoTexture.loadFromFile("ASSETS\\IMAGES\\Decor-1.png"))
	{
		
		std::cout << "Problem loading logo" << std::endl;			// simple error message if previous call fails
	}
	m_logoSprite.setTexture(m_logoTexture);
	m_logoSprite.setPosition(0.0f, 650.0f);
	m_logoSprite.setScale(1.7, 1.7);
}

void Game::setupStockingA()
{
	if (!m_stockingATexture.loadFromFile("ASSETS\\IMAGES\\stocking-2.png"))
	{
		cout << "Error loading Red Stocking" << endl;
	}

	m_stockingASprite.setPosition(25.0f, 270.0f);
	m_stockingASprite.setScale(0.3, 0.3);
	m_stockingASprite.setTexture(m_stockingATexture);
}

void Game::setupBackgroundA()
{
	if (!m_backgroundATexture.loadFromFile("ASSETS\\IMAGES\\fire-place-red.png"))
	{
		cout << "Error loading Red fire place" << endl;
	}

	m_backgroundASprite.setPosition(0.0f, 0.0f);
	m_backgroundASprite.setScale(4, 4);
	m_backgroundASprite.setTexture(m_backgroundATexture);
}

void Game::setupStockingB()
{
	if (!m_stockingBTexture.loadFromFile("ASSETS\\IMAGES\\stocking-2B.png"))
	{
		cout << "Error loading Red Stocking" << endl;
	}

	m_stockingBSprite.setPosition(225.0f, 270.0f);
	m_stockingBSprite.setScale(0.3, 0.3);
	m_stockingBSprite.setTexture(m_stockingBTexture);
}

void Game::setupBackgroundB()
{
	if (!m_backgroundBTexture.loadFromFile("ASSETS\\IMAGES\\fire-place-blue.png"))
	{
		cout << "Error loading Red fire place" << endl;
	}

	m_backgroundBSprite.setPosition(0.0f, 0.0f);
	m_backgroundASprite.setScale(4, 4);
	m_backgroundBSprite.setTexture(m_backgroundBTexture);
}

void Game::setupStockingC()
{
	if (!m_stockingCTexture.loadFromFile("ASSETS\\IMAGES\\stocking-2C.png"))
	{
		cout << "Error loading Red Stocking" << endl;
	}

	m_stockingCSprite.setPosition(425.0f, 270.0f);
	m_stockingCSprite.setScale(0.3, 0.3);
	m_stockingCSprite.setTexture(m_stockingCTexture);
}

void Game::setupBackgroundC()
{
	if (!m_backgroundCTexture.loadFromFile("ASSETS\\IMAGES\\fire-place-purple.png"))
	{
		cout << "Error loading Red fire place" << endl;
	}

	m_backgroundCSprite.setPosition(0.0f, 0.0f);
	m_backgroundASprite.setScale(4, 4);
	m_backgroundCSprite.setTexture(m_backgroundCTexture);
}

