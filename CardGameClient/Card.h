#pragma once
#ifndef _CARD_H_ // ������� �� ���ؼ� Card.h�� �� ���� ���ԵǱ� ������ �ߺ� ���� �߻��� ���� 
#define _CARD_H_

/// <summary>
/// include
/// </summary>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <iostream>

/// <summary>
/// Class Name = CardClass
/// </summary>
class Card {

private:
	struct CardPoisition
	{
		int x;
		int y;
	};

public:
	Card();
	Card(const Card&);
	~Card();

	// ������Ƽ �Լ�
	
private:
	int m_CardId;
	sf::Texture m_Cardtexture;
	CardPoisition m_CardPosition;

private:

};




#endif // !_CARD_H_