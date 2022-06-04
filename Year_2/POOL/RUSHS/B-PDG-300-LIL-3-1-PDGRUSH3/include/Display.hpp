#ifndef DISPLAY_HPP_
#define DISPLAY_HPP_

#include "header.hpp"

class Display : public IMonitorDisplay {
    public:
        // CTOR & DTOR
        Display();
        ~Display();

        // FUNCTIONS
        const bool is_running(void) const;
        void poll_event(void);
        void update(void);
        void render(void);
        void refreshModules(void);
        void refreshCores(void);
        void refreshRam(void);
        void refreshNetwork(void);
        void renderModules(sf::RenderTarget &target);
        void renderCores(sf::RenderTarget &target);
        void renderNetwork(sf::RenderTarget &target);
        void renderRam(sf::RenderTarget &target);
        void renderButton(sf::RenderTarget &target);
        void management_mouse(void);

    protected:
        void _initWindow(void);
        void _initVariables(void);
        void _initModules(void);
        void _initNetwork(void);
        void _initRam(void);
        void _initCores(void);
        void _initClock(void);
        void _initButtons(void);
        void _initTextButtons(void);

        Cpu cpu;
        Ram ram;
        sf::Font _fontG;
        RamCore ramCore;
        Network _network;
        sf::Event _event;
        sf::Clock clockCpu;
        sf::Text _cpuModel;
        sf::Text _cpu;
        sf::Text _net;
        sf::Text _ram;
        sf::Text _info;
        sf::VideoMode _videoMode;
        sf::RenderWindow *_window;
        std::vector<CpuG*> _cores;
        std::vector<Module*> _modules;
        std::vector<NetworkG*> _networks;
        std::vector<std::string> _tabUsage;
        std::vector<std::string> _tabNetworks;
        std::vector<std::pair<size_t, size_t>> _tabSent;
        std::vector<std::pair<size_t, size_t>> _tabReceived;
        sf::RectangleShape _buttonCpu;
        sf::RectangleShape _buttonRam;
        sf::RectangleShape _buttonNet;
        sf::RectangleShape _buttonInfo;
        bool _displayCpu;
        bool _displayRam;
        bool _displayNet;
        bool _displayInfo;

    private:
        sf::Sprite _spriteBackground;
        sf::Texture _textureBackground;
};

#endif /* !DISPLAY_HPP_ */
