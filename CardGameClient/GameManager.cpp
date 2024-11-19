#include "GameManager.h"
#include "iostream"

GameManager::GameManager() : m_isMyTurn(false)
{
	m_player.setTurnChangeCallback(std::bind(&GameManager::ChangeTurn, this));
}

void GameManager::GameStart()
{
	// �۽��ϱ� -> �� �����ֱ�. m_isMyTurn = �Լ�
	std::cout << "���� ����!" << std::endl;
	
}

void GameManager::ChangeTurn()
{
	m_isMyTurn = !m_isMyTurn;
	if (m_isMyTurn)
	{
		std::cout << "����!" << std::endl;
	}
	else
	{
		std::cout << "�����!" << std::endl;
	}

}