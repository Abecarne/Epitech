/*
** EPITECH PROJECT, 2022
** Documents
** File description:
** Infos
*/

#ifndef INFOS_HPP_
#define INFOS_HPP_

#include "header.hpp"

class Infos : public Module {
    public:
        // CTOR & DTOR
        Infos();
        ~Infos();

        // GETTER
        std::string getHostName(void) const;
        std::string getUserName(void) const;
        std::string getSystemName(void) const;
        std::string getVersion(void) const;
        std::string getDate(void) const;

        // SETTER
        void setHostName(std::string);
        void setUserName(std::string);
        void setSystemName(std::string);
        void setVersion(std::string);
        void setDate(std::string);

        void setAllInfos(void);
        void initAll(void);
        bool initTextHostName();
        bool initTextUserName();
        bool initTextsystemeName();
        bool initTextVersion();
        bool initTextDate();

        void refresh(void);
        void render(sf::RenderTarget &target);

    protected:
        // NAME
        std::string _hostname;
        std::string _username;
        std::string _systemName;
        std::string _version;
        std::string _date;

        // TEXT
        sf::Text _TextMonitorName;
        sf::Text _TextHostname;
        sf::Text _TextUsername;
        sf::Text _TextSystemName;
        sf::Text _TextVersion;
        sf::Text _TextDate;
        sf::Text _TextTime;

        Info _infos;
};

#endif /* !INFOS_HPP_ */
