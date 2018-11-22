#ifndef NetManager_h
#define NetManager_h

#include "Main.h"

class NetManager
{
public:
    NetManager();
    ~NetManager();
    void update();
    void acceptClient();
    void processTcp();
    void processUdp();
    void createRoom(Uint8 hostId, int maxClients);
    void deleteRoom(Uint8 id);

    Room* getRoom(Uint8 id);
    Uint8 getAvailableRoomId();

    Uint8 getAvailableId();
    Client* getClient(Uint8 id);
    void disconnectClient(Uint8 id);
    
private:
    std::vector<std::unique_ptr<Client>> clients;

    std::vector<std::unique_ptr<Room>> rooms;

    IPaddress address;
    TCPsocket TCP_socket; //for connectivity
    SDLNet_SocketSet TCP_SocketSet;
    UDPsocket UDP_socket; //for gameplay
    UDPpacket UDP_packet;
    UniversalPacket universalPacket;
};

#endif
