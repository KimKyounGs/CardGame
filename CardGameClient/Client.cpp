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
    if (socket.receive(packet) == sf::Socket::Done) {
        packet >> message;
        std::cout << "Message from server: " << message << std::endl;
    }

    return 0;
}
