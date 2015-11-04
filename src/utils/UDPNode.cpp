/* 
 * File:   UDPNode.cpp
 * Author: daniele
 * 
 * Created on 4 novembre 2015, 12.08
 */

#include "UDPNode.h"
namespace lar_tools {

    std::vector<UDPNode *> UDPNode::instances;

    UDPNode::UDPNode(unsigned short port) {
        this->ready = true;
        if ((this->sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0) {
            this->ready = false;
        }
        memset(&this->local_address, 0, sizeof (this->local_address)); /* Zero out structure */
        this->local_address.sin_family = AF_INET; /* Internet address family */
        this->local_address.sin_addr.s_addr = htonl(INADDR_ANY); /* Any incoming interface */
        this->local_address.sin_port = htons(port);

        if (bind(sock, (struct sockaddr *) & this->local_address, sizeof (this->local_address)) < 0) {
            this->ready = false;
        }
        if (this->ready)
            this->init();
    }

    UDPNode::UDPNode(std::string remote_address, unsigned short port) {
        this->ready = true;
        if ((sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0) {
            this->ready = false;
        }
        memset(&this->remote_address, 0, sizeof (this->remote_address)); /* Zero out structure */
        this->remote_address.sin_family = AF_INET; /* Internet addr family */
        this->remote_address.sin_addr.s_addr = inet_addr(remote_address.c_str()); /* Server IP address */
        this->remote_address.sin_port = htons(port);
        if (this->ready)
            this->init();
    }

    UDPNode::UDPNode(const UDPNode& orig) {
        this->ready = orig.ready;
        this->local_address = orig.local_address;
        this->remote_address = orig.remote_address;
        this->sock = orig.sock;
        this->init();
    }

    UDPNode::~UDPNode() {

    }

    void UDPNode::init() {
        instances.push_back(this);
        struct sigaction sigIntHandler;

        sigIntHandler.sa_handler = UDPNode::handleSignals;
        sigemptyset(&sigIntHandler.sa_mask);
        sigIntHandler.sa_flags = 0;

        sigaction(SIGINT, &sigIntHandler, NULL);
    }

    void UDPNode::handleSignals(int signum) {
        for (size_t i = 0; i < instances.size(); i++) {
            instances[i]->disconnect();
        }
    }

    void UDPNode::disconnect() {
        close(this->sock);
        this->ready = false;
    }

    bool UDPNode::receive(void* data, int data_length) {
        if (recv(this->sock, data, data_length, 0)) {
            return false;
        }
        return true;
    }

    bool UDPNode::send(void* data, int data_length) {
        return sendto(this->sock, data, data_length, 0, (struct sockaddr *)
                &this->remote_address, sizeof (this->remote_address));
    }

    bool UDPNode::isReady() {
        return this->ready;
    }

}