#include "Player.h"
#include <iostream>

Player::Player()
{

}

void Player::setTurnChangeCallback(const std::function<void()>& callback) {
    m_turnChangeCallback = callback;  // GameManager���� �ݹ� ����
}

void Player::PlayCard()
{
    std::cout << "Player: Card played!" << std::endl;
    // �� ���� ��û
    if (m_turnChangeCallback) {  // �ݹ��� �����Ǿ� ������ ȣ��
        m_turnChangeCallback();
    }
}
