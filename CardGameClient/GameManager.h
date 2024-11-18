#pragma once
#ifndef _GAMEMANAGER_H
#define _GAMEMANAGER_H

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <functional>
#include "Card.h"
#include "Player.h"

class GameManager 
{
private:
	Player& m_player; // �÷��̾�
	Card* m_playerCards[10]; // �÷��̾� ī��
	Card* m_enemyCards[10]; // �� ī��
	bool m_isMyTurn; // �� ����

private:
	GameManager(const GameManager&); // ��� ���ϴ� �Լ� ���ϱ�
	GameManager& operator=(const GameManager&); // ��� ���ϴ� �Լ� ���ϱ�

public:
	GameManager();
	
	void GameStart(); // ���� ������ �� �Լ�
	void ChangeTurn(); // �� ���� �Լ��� �ݹ� �غ�
};


#endif // !_GAMEMANAGER_H