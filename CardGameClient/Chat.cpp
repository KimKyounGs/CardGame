#include "Chat.h"
#include <iostream>

Chat::Chat() : m_isChatting(false)
{
    m_inputBox.setSize(sf::Vector2f(400, 30));
    m_inputBox.setPosition(50, 550);
    m_inputBox.setFillColor(sf::Color::Cyan);

    if (!m_font.loadFromFile("Font\\RightFont.ttf")) {
        std::cerr << "��Ʈ �ε� ����" << std::endl;
    }

    m_inputText.setFont(m_font);
    m_inputText.setCharacterSize(20);
    m_inputText.setFillColor(sf::Color::Black);
    m_inputText.setPosition(55, 555);
}

Chat::~Chat()
{
    if (m_receivingThread.joinable()) {
        m_receivingThread.join();  // ���� �����尡 ����� ������ ���
    }
}

void Chat::HandleEvent(const sf::Event& event, sf::TcpSocket& socket) 
{
    // O Ű�� ������ ä�� ��� ��ȯ
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::O && !m_isChatting) 
    {
        m_isChatting = !m_isChatting;
        std::cout << "Chat mode " << (m_isChatting ? "Ȱ��ȭ" : "��Ȱ��ȭ") << std::endl;
    }

    // ä�� ��尡 Ȱ��ȭ�� ���¿����� �ؽ�Ʈ �Է� ó��
    // sf::Event::TextEntered : Ű����� �Է��� �ؽ�Ʈ�� ����
    if (m_isChatting && event.type == sf::Event::TextEntered)
    {
        if (event.text.unicode == '\r') // ����Ű�� �޽��� ����
        {
            SendMessage(socket);
            m_isChatting = false;
        }
        else if (event.text.unicode == '\b') // �齺���̽�
        {
            if (!m_currentInput.empty())
            {
                m_currentInput.pop_back();
            }
        }
        else
        {
            m_currentInput += static_cast<char>(event.text.unicode);
        }
        m_inputText.setString(m_currentInput);
    }
}

void Chat::Update(sf::TcpSocket& socket) 
{
    // ���ؽ��� ��װ� ���� ������ �޽����� m_messages�� �ű�
    std::lock_guard<std::mutex> lock(m_mutex);
    for (const auto& msg : m_receivedMessages) {
        m_messages.push_back(msg);
    }
    m_receivedMessages.clear();
}

void Chat::Draw(sf::RenderWindow& window) 
{
    window.draw(m_inputBox);
    window.draw(m_inputText);
    float yOffset = 500;

    // m_messages ���� �� ���
    std::lock_guard<std::mutex> lock(m_mutex);
    for (auto it = m_messages.rbegin(); it != m_messages.rend(); ++it) {
        sf::Text text(*it, m_font, 20);
        text.setFillColor(sf::Color::Black);
        text.setPosition(50, yOffset);
        window.draw(text);
        yOffset -= 25;
        if (yOffset < 50) break;
    }
}
/// <summary>
/// ������ ����Ǿ��� �� �ѹ� ȣ���Ͽ� �����带 �����ϰ� �� �����带 ���ؼ� ����ؼ� �������� ���� �ޱ�
/// </summary>
/// <param name="socket"></param>
void Chat::StartReceiving(sf::TcpSocket& socket)
{
    m_receivingThread = std::thread(&Chat::ReceiveMessage, this, std::ref(socket));
}

void Chat::ReceiveMessage(sf::TcpSocket& socket)
{
    while (true)
    {
        sf::Packet packet;
        if (socket.receive(packet) == sf::Socket::Done)
        {
            std::string message;
            packet >> message;

            // ���� �޽����� ���ؽ��� ��ȣ�ϰ� m_receivedMessages�� �߰�
            std::lock_guard<std::mutex> lock(m_mutex);
            m_receivedMessages.push_back("����: " + message);
        }
        else
        {
            std::cerr << "Error : �޽����� ���Ź��� �� �����ϴ�!" << std::endl;
            break;
        }
    }
}

void Chat::SendMessage(sf::TcpSocket& socket) 
{
    // �޽����� ���� ��
    if (!m_currentInput.empty()) {
        sf::Packet packet;
        packet << m_currentInput;

        if (socket.send(packet) == sf::Socket::Done) {
            std::lock_guard<std::mutex> lock(m_mutex);
            m_messages.push_back("��: " + m_currentInput);
            m_currentInput.clear();
            m_inputText.setString("");
        }
        else {
            std::cerr << "Error: ������ �޽����� �۽��� �� �����ϴ�!" << std::endl;
        }
    }
}
