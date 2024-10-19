#include <SFML/Network.hpp>
#include <iostream>

int main() {
    sf::TcpSocket socket;

    // ������ ����
    if (socket.connect("127.0.0.1", 53000) != sf::Socket::Done) {
        std::cerr << "Error: Could not connect to server" << std::endl;
        return -1;
    }

    std::cout << "Connected to server!" << std::endl;

    // �����κ��� �޽��� ����
    sf::Packet packet;
    std::string message;
    // sf::Socket::Done�� �����Ͱ� ���������� ���ŵǾ����� �ǹ��մϴ�.
    if (socket.receive(packet) == sf::Socket::Done) {
        packet >> message; // ��Ŷ���� �޽��� ����
        std::cout << "Message from server: " << message << std::endl;
    }
    else {
        std::cerr << "Error receiving message from server" << std::endl;
    }

    while (true)
    {
        // ������ �޽��� ����
        sf::Packet sendPacket;
        std::string messageToSend = "�ȳ� ������~";
        std::cin >> messageToSend;
        sendPacket << messageToSend;  // �޽����� ��Ŷ�� �߰�

        if (socket.send(sendPacket) != sf::Socket::Done) {
            std::cerr << "Error: Could not send message to server" << std::endl;
        }
        else {
            std::cout << "�������� �޼��� ���� : " << messageToSend << std::endl;
        }

        if (messageToSend == "bye")
        {
            std::cout<< "Ŭ���̾�Ʈ ����" << std::endl;
            break;
        }
    }


    return 0;
}