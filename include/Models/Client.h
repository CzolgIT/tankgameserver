#ifndef CLIENT_H
#define CLIENT_H

#include "Main.h"

class Client
{
public:
    Client(Uint8 ID, TCPsocket tcpsock, UDPsocket udpsock);
    ~Client();
    
    void udpSend(const BasePacket &packet);
    void tcpSend(const BasePacket &packet);
    void setUdpAddress(IPaddress address);
    void attachSocketSet(SDLNet_SocketSet *socketSet);
    void setPosition(SDL_Point newPosition);
    void setIDirection(int iDirection);
    void setITowerDirection(int iTowerDirection);
    void setKeys(int x, bool keys);

    TCPsocket getTcpSocket();
    Uint8 getId();
    SDL_Point getPosition();
    int getIDirection();
    int getITowerDirection();
    bool getKeys(int i);

    bool needsUdpAddress();

    void print();
    
private:
    TCPsocket tcpSocket;
    UDPsocket udpSocket;
    UDPpacket udpPacket;
    Uint8 id;
    bool hasUDPAddress;

    SDLNet_SocketSet* SockSet;

    SDL_Point position;
    int iDirection, iTowerDirection;
    bool keys[7]; // up down left right z x space
};


#endif // CLIENT_H
