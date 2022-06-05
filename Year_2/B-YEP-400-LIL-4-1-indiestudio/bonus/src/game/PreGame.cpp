/*
** EPITECH PROJECT, 2020
** Pikmins
** File description:
** PreGame.cpp
*/

#include "PreGame.hpp"
#include <iostream>

bomberman::game::PreGame *bomberman::game::PreGame::_preGameInstance {nullptr};
std::mutex bomberman::game::PreGame::_mutex;

void bomberman::game::PreGame::init(bomberman::core::GameEngine *engine)
{
    _map = std::make_shared<bomberman::environment::Map>(*engine->getGameAssets()->getMap());
    if (!_map)
        bomberman::core::Errors("[PreGame]", "Not enough memories!");

    _skybox = std::make_shared<bomberman::environment::Skybox>(*engine->getGameAssets()->getSkyBox());
    if (!_skybox)
        bomberman::core::Errors("[PreGame]", "Not enough memories!");
    _travelingParser.init(_map->getMapFolder());
    _startedTime = GetTime();
    _nbrTraveling = 0;

    _travelingDurations = _travelingParser.getTravelingDurations();
    _beginPositions = _travelingParser.getBeginPosition();
    _endingPositions = _travelingParser.getEndingPosition();
    _camera.setPosition(10.0f, 10.0f, 10.0f);
    _camera.setTarget(0.0f, 0.0f, 0.0f);
    _camera.setUp(0.0f, 1.0f, 0.0f);
    _startedTime = GetTime();
}

void bomberman::game::PreGame::cleanup(void)
{
    // Nothing
}

void bomberman::game::PreGame::pause(void)
{
    // Nothing
}

void bomberman::game::PreGame::resume(void)
{
    // Nothing
}

void bomberman::game::PreGame::processInput(bomberman::core::GameEngine *engine)
{
    (void)engine;
}

float getTimePercent(float maxSecond, float currentSecond)
{
    return (100 * currentSecond) / maxSecond;
}

void deplaceCamera(bomberman::entities::CameraCustom &camera, Vector3 startedPoint,
Vector3 endedPoint, float time)
{
    Vector3 newPos = (Vector3){std::lerp(startedPoint.x, endedPoint.x, time),
                               std::lerp(startedPoint.y, endedPoint.y, time),
                               std::lerp(startedPoint.z, endedPoint.z, time)};

    camera.setPosition(newPos.x, newPos.y, newPos.z);
}

void moveCameraAngle(bomberman::entities::CameraCustom &camera, Vector3 firstAngle,
Vector3 secondAngle, float time)
{
    Vector3 newAngle = (Vector3){std::lerp(firstAngle.x, secondAngle.x, time),
                                 std::lerp(firstAngle.y, secondAngle.y, time),
                                 std::lerp(firstAngle.z, secondAngle.z, time)};

    camera.setTarget(newAngle.x, newAngle.y, newAngle.z);
}

void bomberman::game::PreGame::update(bomberman::core::GameEngine *engine,
bomberman::core::Time deltaTime)
{
    float elapsedTime = GetTime() - _startedTime;
    float timePercent = 0;

    (void)engine;
    (void)deltaTime;
    _map->updateMap();
    if (_beginPositions.size() <= _nbrTraveling)
        return;
    timePercent = getTimePercent(_travelingDurations[_nbrTraveling], elapsedTime) / 100;
    if (timePercent <= 1) {
        deplaceCamera(_camera, _beginPositions[_nbrTraveling].first, _endingPositions[_nbrTraveling].first, timePercent);
        moveCameraAngle(_camera, _beginPositions[_nbrTraveling].second, _endingPositions[_nbrTraveling].second, timePercent);
    }
    else {
        _startedTime = GetTime();
        _nbrTraveling++;
    }
}

void bomberman::game::PreGame::render(bomberman::core::GameEngine *engine)
{
    (void)engine;

    BeginDrawing();
        ClearBackground(SKYBLUE);
        BeginMode3D(*_camera.getCamera());
            _skybox->drawSkybox();
            _map->renderMap();
        EndMode3D();
    EndDrawing();
}

// Initialize Traveling Parser

void bomberman::game::PreGame::TravelingParser::init(std::string mapFolder)
{
    openFile(mapFolder + "mapInfos.json");
    getTravelingInformations(mapFolder);
}

void bomberman::game::PreGame::TravelingParser::openFile(std::string filepath)
{
    if (!FileExists(filepath.c_str()))
        throw bomberman::core::Errors("[Traveling Parser]", "Can't open file: " + filepath);
    try {
        boost::property_tree::read_json(filepath, _root);
    } catch (boost::property_tree::json_parser_error const &error) {
        bomberman::core::Errors("[Traveling Parser]", "Json file is not correct!");
    }
}
void bomberman::game::PreGame::TravelingParser::checkLineInfos(boost::property_tree::ptree::value_type travelingNode)
{
    std::string state[2] = {"begin", "ending"};
    std::string vector[2] = {"position", "target"};

    for (size_t nbrState = 0; nbrState < 2; nbrState++) {
        for (size_t nbrVector = 0; nbrVector < 2; nbrVector++) {
            try {
                travelingNode.second.get_child(state[nbrState] + "." + vector[nbrVector] + ".x");
                travelingNode.second.get_child(state[nbrState] + "." + vector[nbrVector] + ".y");
                travelingNode.second.get_child(state[nbrState] + "." + vector[nbrVector] + ".z");
            } catch(boost::property_tree::ptree_bad_path const &error) {
                bomberman::core::Errors("[Traveling Parser]", "\"" + state[nbrState] + "." + vector[nbrVector] + "\" is not found!");
            }
        }
    }

    try {
        travelingNode.second.get_child("durationTime");
    } catch (boost::property_tree::ptree_bad_path const &error) {
        bomberman::core::Errors("[Traveling Parser]", "\"durationTime\" is not found!");
    }

}

void bomberman::game::PreGame::TravelingParser::pushTravelingInformations(boost::property_tree::ptree::value_type travelingNode)
{
    std::vector<std::string> infosCamera;
    std::pair<Vector3, Vector3> cameraPairBegin;
    std::pair<Vector3, Vector3> cameraPairEnding;
    float duration = 0;

    checkLineInfos(travelingNode);

    try {
        cameraPairBegin.first = {travelingNode.second.get<float>("begin.position.x"), travelingNode.second.get<float>("begin.position.y"), travelingNode.second.get<float>("begin.position.z")};
        cameraPairBegin.second = {travelingNode.second.get<float>("begin.target.x"), travelingNode.second.get<float>("begin.target.y"), travelingNode.second.get<float>("begin.target.z")};
        cameraPairEnding.first = {travelingNode.second.get<float>("ending.position.x"), travelingNode.second.get<float>("ending.position.y"), travelingNode.second.get<float>("ending.position.z")};
        cameraPairEnding.second = {travelingNode.second.get<float>("ending.target.x"), travelingNode.second.get<float>("ending.target.y"), travelingNode.second.get<float>("ending.target.z")};
        duration = travelingNode.second.get<float>("durationTime");
    } catch (const std::exception &error) {
        throw bomberman::core::Errors("[Traveling Parser]", "Informations aren't correct in the file!");
    }

    _beginPositions.push_back(cameraPairBegin);
    _endingPositions.push_back(cameraPairEnding);
    _travelingDurations.push_back(duration);
}

void bomberman::game::PreGame::TravelingParser::getTravelingInformations(std::string mapFolder)
{
    try {
        _root.get_child("traveling");
    } catch(boost::property_tree::ptree_bad_path const &error) {
        throw bomberman::core::Errors("[Traveling Parser]", "Error doesn't find : \"traveling\"!");
    }

    for (boost::property_tree::ptree::value_type &travelingNode : _root.get_child("traveling"))
        pushTravelingInformations(travelingNode);
}

std::vector<std::pair<Vector3, Vector3>> bomberman::game::PreGame::TravelingParser::getBeginPosition(void)
{
    return _beginPositions;
}

std::vector<std::pair<Vector3, Vector3>> bomberman::game::PreGame::TravelingParser::getEndingPosition(void)
{
    return _endingPositions;
}

std::vector<float> bomberman::game::PreGame::TravelingParser::getTravelingDurations(void)
{
    return _travelingDurations;
}