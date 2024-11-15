#pragma once
#ifndef _CARD_H_ // ������� �� ���ؼ� Card.h�� �� ���� ���ԵǱ� ������ �ߺ� ���� �߻��� ���� 
#define _CARD_H_

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
	enum class Parity
	{
		Odd,
		Even,
		Defalut
	};
	Card(const Card&);
	Card& operator=(const Card&);

private:
	int m_cardNum;
	Parity m_cardParity;
	bool m_isUsed;
	// sf::Texture m_Cardtexture;
	// CardPoisition m_CardPosition;

public:
	Card();


public:
	void SetNum(const int& num);
	const int GetNum();
};




#endif // !_CARD_H_