/*
** EPITECH PROJECT, 2022
** Documents
** File description:
** NetworkG
*/

#ifndef NETWORKG_HPP_
#define NETWORKG_HPP_

#include "header.hpp"

class NetworkG : public Module {
    public:
        NetworkG(std::string name = "Network", int x = 0);
        ~NetworkG();

        // SETTERS
        void setNetworkName(std::string name);
        void setPaquetReceived(std::string name);
        void setPaquetSent(std::string name);
        void setBytesReceived(std::string name);
        void setBytesSent(std::string name);

        // GETTERS
        std::string getNetworkName(void);
        std::string getPaquetReceived(void);
        std::string getPaquetSent(void);
        std::string getBytesReceived(void);
        std::string getBytesSent(void);

        // FUNCTIONS
        void initAll(void);
        
        void refresh(void);
        void render(sf::RenderTarget &target);

        void initNetworkName(void);
        void initNetworkPaquetReceived(void);
        void initNetworkPaquetSent(void);
        void initNetworkBytesReceived(void);
        void initNetworkBytesSent(void);

    private:
        sf::Vector2f _size;
        // NAMES
        std::string _byteSent;
        std::string _paquetSent;
        std::string _networkName;
        std::string _byteReceived;
        std::string _paquetReceived;

        // TEXTS
        sf::Text _TextByteSent;
        sf::Text _TextPaquetSent;
        sf::Text _TextNetworkName;
        sf::Text _TextByteReceived;
        sf::Text _TextPaquetReceived;
        sf::Text _TitleNetworkName;
        sf::Text _TitlePaquetReceived;
        sf::Text _TitleBytesReceived;
        sf::Text _TitlePaquetSent;
        sf::Text _TitleBytesSent;

};

#endif /* !NETWORKG_HPP_ */
