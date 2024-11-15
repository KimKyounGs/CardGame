#pragma once
#ifndef _PlAYER_H_
#define _PlAYER_H_

#include <vector>
#include <string>
#include <functional> // �ݹ��Լ� ���.
#include "Card.h"

class Player
{
private:
	std::string m_playerName;
	std::vector<Card> m_cards;

private:
	Player(const Player&); // �ݱ�
	Player& operator=(const Player&); // �ݱ�

public:
	Player(); // ������
	void PlayCard(); // ī�带 ���� �Լ�
	
};


#endif // !_PlAYER_H_