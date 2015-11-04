/* 
 * File:   UDPNode.h
 * Author: daniele
 *
 * Created on 4 novembre 2015, 12.08
 */

#ifndef UDPNODE_H
#define	UDPNODE_H

#include "lar_tools.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <strings.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <signal.h>


namespace lar_tools {
    
    struct UDPNodeMessage{
        int command;
        long time;
        float payload[32];
    };
    
    class UDPNode {
    public:
        UDPNode(unsigned short port);
        UDPNode(std::string remote_address,unsigned short port);
        UDPNode(const UDPNode& orig);
        virtual ~UDPNode();
        bool isReady();
        bool receive(void* data,int data_length);
        bool send(void* data,int data_length);
        bool receiveMessage(UDPNodeMessage& message);
        bool sendMessage(const UDPNodeMessage& message);
        void disconnect(); 
    private:
        void init();
        int sock; /* Socket */
        struct sockaddr_in remote_address;
        struct sockaddr_in local_address;
        bool ready;
        static std::vector<UDPNode *> instances;
        static void handleSignals(int signum);
    };

}
#endif	/* UDPNODE_H */

