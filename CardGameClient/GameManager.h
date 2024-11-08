#pragma once
#ifndef _GAMEMANAGER_H
#define _GAMEMANAGER_H

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include "Card.h"

class GameManager 
{
private:
	Card m_playerCards[10];
	Card m_enemyCards[10];
	bool m_isMyTurn;

private:
	GameManager(const GameManager&);
	~GameManager();

public:
	GameManager();
	
	void GameStart(); // ���� ������ �� �Լ�
	void TurnChange(); // �� ����

};


#endif // !_GAMEMANAGER_H