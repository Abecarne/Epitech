/*
** EPITECH PROJECT, 2022
** Documents
** File description:
** Display
*/

#include "../include/header.hpp"

Display::~Display()
{
    delete _window;
}

void Display::_initNetwork(void)
{
    _tabNetworks = _network.getNames();
    _tabReceived = _network.getRC();
    _tabSent = _network.getTr();
    for (size_t i = 0; i < _tabNetworks.size(); i++) {
        _networks.push_back(new NetworkG(_tabNetworks[i], -100 - 20 * i));
    }
}

void Display::_initClock(void)
{
    clockCpu.restart();
}

void Display::_initVariables(void)
{
    _window = nullptr;
    _textureBackground.loadFromFile("./res/background.jpg");
    _fontG.loadFromFile("res/Roboto-Light.ttf");
    _spriteBackground.setTexture(_textureBackground);
    _cpuModel.setString(cpu.getName());
    _cpuModel.setPosition(500, 740);
    _cpuModel.setFont(_fontG);
    _cpuModel.setCharacterSize(13);
    _cpuModel.setFillColor(sf::Color::White);
    _displayCpu = true;
    _displayRam = true;
    _displayNet = true;
    _displayInfo = true;
    
}

void Display::_initRam(void)
{
    ram.initAll();
}

void Display::_initCores(void)
{
    _tabUsage = cpu.getUsage();
    for (int i = 0; i < cpu.getNumberCore(); i++) {
        _cores.push_back(new CpuG("Cpu" + std::to_string(i), -100 - 100 * i));
    }
}

void Display::_initModules(void)
{
    _modules = std::vector<Module*> {new Infos};
    for (auto module : _modules)
        module->initAll();
}

void Display::_initWindow(void)
{
    _videoMode.height = 800;
    _videoMode.width = 1850;
    _window = new sf::RenderWindow(_videoMode, "OurGKrellm", sf::Style::Default);
    _window->setFramerateLimit(30);
}

const bool Display::is_running(void) const
{
    return (_window->isOpen());
}

void Display::_initButtons(void)
{
    sf::RectangleShape rectangle(sf::Vector2f(30, 30));
    rectangle.setFillColor(sf::Color(12, 171, 38));
    _buttonCpu = rectangle;
    _buttonCpu.setPosition(1800, 100);
    _buttonRam = rectangle;
    _buttonRam.setPosition(1800, 150);
    _buttonNet = rectangle;
    _buttonNet.setPosition(1800, 200);
    _buttonInfo = rectangle;
    _buttonInfo.setPosition(1800, 250);
}

void Display::_initTextButtons(void)
{
    sf::Text Text;
    Text.setString("CPU");
    Text.setFont(_fontG);
    Text.setCharacterSize(16);
    Text.setFillColor(sf::Color::White);
    Text.setPosition(1750, 105);
    _cpu = Text;
    Text.setString("RAM");
    Text.setPosition(1750, 155);
    _ram = Text;
    Text.setString("NETWORK");
    Text.setPosition(1720, 205);
    _net = Text;
    Text.setString("INFOS");
    Text.setPosition(1750, 255);
    _info = Text;
}

Display::Display()
{
    _initVariables();
    _initWindow();
    _initModules();
    _initRam();
    _initCores();
    _initClock();
    _initNetwork();
    _initButtons();
    _initTextButtons();
}

void Display::management_mouse(void)
{
    auto mouse_pos = sf::Mouse::getPosition(*_window);
    auto translated_pos = _window->mapPixelToCoords(mouse_pos);
    if(_buttonCpu.getGlobalBounds().contains(translated_pos)) {
        if (_displayCpu) {
            _buttonCpu.setFillColor(sf::Color(255, 0, 0));
            _displayCpu = false;
        } else {
            _buttonCpu.setFillColor(sf::Color(12, 171, 38));
            _displayCpu = true;
        }
    }
    if(_buttonRam.getGlobalBounds().contains(translated_pos)) {
        if (_displayRam) {
            _buttonRam.setFillColor(sf::Color(255, 0, 0));
            _displayRam = false;
        } else {
            _buttonRam.setFillColor(sf::Color(12, 171, 38));
            _displayRam = true;
        }
    }
    if(_buttonNet.getGlobalBounds().contains(translated_pos)) {
        if (_displayNet) {
            _buttonNet.setFillColor(sf::Color(255, 0, 0));
            _displayNet = false;
        } else {
            _buttonNet.setFillColor(sf::Color(12, 171, 38));
            _displayNet = true;
        }
    }
    if(_buttonInfo.getGlobalBounds().contains(translated_pos)) {
        if (_displayInfo) {
            _buttonInfo.setFillColor(sf::Color(255, 0, 0));
            _displayInfo = false;
        } else {
            _buttonInfo.setFillColor(sf::Color(12, 171, 38));
            _displayInfo = true;
        }
    }
}

void Display::poll_event(void)
{
    while (_window->pollEvent(_event)) {
        switch (_event.type) {
            case sf::Event::Closed:
                _window->close();
                break;
            case sf::Event::KeyPressed:
                if(_event.key.code == sf::Keyboard::Escape)
                    _window->close();
                break;
            case sf::Event::MouseButtonPressed:
                management_mouse();
                break;
            default:
                break;
        }
    }
}

void Display::refreshNetwork(void)
{
    _tabNetworks = _network.getNames();
    _tabReceived = _network.getRC();
    _tabSent = _network.getTr();
    for (int i = 0; i < _tabNetworks.size(); i++) {
        _networks[i]->setNetworkName(_tabNetworks[i]);
        _networks[i]->setPaquetReceived(std::to_string(_tabReceived[i].first));
        _networks[i]->setBytesReceived(std::to_string(_tabReceived[i].second));
        _networks[i]->setPaquetSent(std::to_string(_tabSent[i].first));
        _networks[i]->setBytesSent(std::to_string(_tabSent[i].second));
        _networks[i]->refresh();
    }
}

void Display::refreshRam(void)
{
    ramCore.refresh();
    ram.setRam_Max(ramCore.getTotMem());
    ram.setRam_Use(ramCore.getUsedMem());
    ram.refresh();
}

void Display::refreshCores(void)
{
    std::vector<std::string> cpuTmp = cpu.getUsage();
    std::vector<float> freqTmp = cpu.getFrequency();

    for (int i = 0; i < cpu.getNumberCore(); i++) {
        _cores[i]->setCpuGUse(std::stof(cpuTmp[i]));
        _cores[i]->setFrequencyG(freqTmp[i]);
        _cores[i]->refresh();
    }
}

void Display::renderButton(sf::RenderTarget &target)
{
    target.draw(_buttonCpu);
    target.draw(_buttonRam);
    target.draw(_buttonNet);
    target.draw(_buttonInfo);
    target.draw(_cpu);
    target.draw(_ram);
    target.draw(_net);
    target.draw(_info);
}

void Display::renderNetwork(sf::RenderTarget &target)
{
    if (!_displayNet)
        return;
    for (auto net : _networks)
        net->render(*_window);

}

void Display::renderCores(sf::RenderTarget &target)
{
    if (!_displayCpu)
        return;
    for (auto tmp : _cores) {
        tmp->render(target);
    }
    _window->draw(_cpuModel);
}

void Display::refreshModules(void)
{
    for (auto tmp : _modules) {
        tmp->refresh();
    }
}

void Display::renderModules(sf::RenderTarget &target)
{
    if (!_displayInfo)
        return;
    for (auto tmp : _modules) {
        tmp->render(target);
    }
}

void Display::renderRam(sf::RenderTarget &target)
{
    if (!_displayRam)
        return;
    ram.render(target);
}

void Display::update(void)
{
    poll_event();
    refreshModules();
    refreshRam();
    refreshNetwork();
    if (clockCpu.getElapsedTime().asSeconds() > 1) {
        cpu.refresh();
        cpu.setFrequency();
        clockCpu.restart();
        _tabUsage = cpu.getUsage();
        refreshCores();
    }
}

void Display::render(void)
{
    _window->clear();
    _window->draw(_spriteBackground);
    renderModules(*_window);
    renderCores(*_window);
    renderRam(*_window);
    renderNetwork(*_window);
    renderButton(*_window);
    _window->display();
}