//Name: Síne Whooley
//Student Number: C00271403
//Date: 13/04/22
//-----------------------
//Christmas Interactive
//-----------------------


#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>

class Game
{
public:
	Game();
	~Game();
	void run();

private:

	void processEvents();
	void processKeys(sf::Event t_event);
	void update(sf::Time t_deltaTime);
	void render();
	
	void setupFontAndText();
	void setupSprite();

	void setupStockingA();
	sf::Sprite m_stockingASprite;
	sf::Texture m_stockingATexture;

	void setupBackgroundA();
	sf::Sprite m_backgroundASprite;
	sf::Texture m_backgroundATexture;

	void setupStockingB();
	sf::Sprite m_stockingBSprite;
	sf::Texture m_stockingBTexture;

	void setupBackgroundB();
	sf::Sprite m_backgroundBSprite;
	sf::Texture m_backgroundBTexture;

	void setupStockingC();
	sf::Sprite m_stockingCSprite;
	sf::Texture m_stockingCTexture;

	void setupBackgroundC();
	sf::Sprite m_backgroundCSprite;
	sf::Texture m_backgroundCTexture;

	sf::RenderWindow m_window; // main SFML window
	sf::Font m_ArialBlackfont; // font used by message
	sf::Text m_welcomeMessage; // text used for message on screen
	sf::Texture m_logoTexture; // texture used for sfml logo
	sf::Sprite m_logoSprite; // sprite used for sfml logo
	bool m_exitGame; // control exiting game

};

#endif // !GAME_HPP

