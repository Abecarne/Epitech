/*
** EPITECH PROJECT, 2022
** Pikmins
** File description:
** Map.cpp
*/

#include "Map.hpp"
#include <iostream>

// All methods for Map class

void bomberman::environment::Map::init(std::string mapFolder)
{
    _mapFolder = mapFolder;

    std::cout << "HELLLLLOOOOOOOO" << std::endl;

    _mapParser.init(_mapFolder);
}

bomberman::environment::Map::~Map(void)
{
    std::cout << "dsqdsqdsdsqdsdq" << std::endl;

    _staticModels.clear();
    _animatedModels.clear();
}

void bomberman::environment::Map::renderMap(void)
{
    for (auto staticModel : _staticModels)
        staticModel->renderModel();
    for (auto animatedModel : _animatedModels)
        animatedModel->renderModel();
}

void bomberman::environment::Map::updateMap(void)
{
    for (auto animatedModel : _animatedModels)
        animatedModel->updateModel();
}

bomberman::environment::Map::MapParser bomberman::environment::Map::getMapDatas(void)
{
    return _mapParser;
}

void bomberman::environment::Map::loadNextModels(void)
{
    _mapParser.getNextMapModels(_mapFolder);

    if (_mapParser.getMapState()) {
        _staticModels = _mapParser.getStaticModels();
        _animatedModels = _mapParser.getAnimatedModels();
    }
}

bool bomberman::environment::Map::getAssetsState(void)
{
    return _mapParser.getMapState();
}

// All methods for MapParser class

void bomberman::environment::Map::MapParser::init(std::string mapFolder)
{
    openFile(mapFolder + "mapInfos.json");
    _loadingState = SM;
    _loadingCount = 0;
    _isFinish = false;

    try {
        _root.get_child("mapStructures.SM");
    } catch(boost::property_tree::ptree_bad_path const &error) {
        throw bomberman::core::Errors("[Map Parser]", "Error doesn't find : \"mapStructures.SM\"!");
    }

    try {
        _root.get_child("mapStructures.AM");
    } catch(boost::property_tree::ptree_bad_path const &error) {
        throw bomberman::core::Errors("[Map Parser]", "Error doesn't find : \"mapStructures.AM\"!");
    }
}


void bomberman::environment::Map::MapParser::openFile(std::string filepath)
{
    if (!FileExists(filepath.c_str()))
        throw bomberman::core::Errors("[Map Parser]", "Can't open file: " + filepath);
    try {
        boost::property_tree::read_json(filepath, _root);
    } catch (boost::property_tree::json_parser_error const &error) {
        bomberman::core::Errors("[Map Parser]", "Json file is not correct!");
    }
}

void bomberman::environment::Map::MapParser::getNextAMModels(std::string mapFolder)
{
    size_t modelCount = 0;

    for (boost::property_tree::ptree::value_type &animatedModel : _root.get_child("mapStructures").get_child("AM")) {
        if (modelCount == _loadingCount) {
            _loadingCount++;
            createAnimatedModel(animatedModel, mapFolder);
            return;
        }
        modelCount++;
    }
}

void bomberman::environment::Map::MapParser::getNextSMModels(std::string mapFolder)
{
    size_t modelCount = 0;

    if (_root.get_child("mapStructures").get_child("SM").size() <= _loadingCount) {
        _loadingState = bomberman::environment::Map::MapParser::loadingState::AM;
        _loadingCount = 0;
        return;
    }

    for (boost::property_tree::ptree::value_type &staticModel : _root.get_child("mapStructures").get_child("SM")) {
        if (modelCount == _loadingCount) {
            createStaticModel(staticModel, mapFolder);
            _loadingCount++;
            return;
        }
        modelCount++;
    }
}

void bomberman::environment::Map::MapParser::getNextMapModels(std::string mapFolder)
{
    if (_loadingState == SM) {
        getNextSMModels(mapFolder);
    } else if (_loadingState == AM && _root.get_child("mapStructures").get_child("AM").size() > _loadingCount) {
        getNextAMModels(mapFolder);
    } else
        _isFinish = true;
}

void bomberman::environment::Map::MapParser::createAnimatedModel(boost::property_tree::ptree::value_type amNode, std::string mapFolder)
{
    std::shared_ptr<bomberman::models::AnimatedModels> animModelPtr;

    // getting map informations
    try {
        std::string modelFile = amNode.second.get<std::string>("modelFile");
        std::string animatioFile = amNode.second.get<std::string>("animationFile");
        std::string textureFile = amNode.second.get<std::string>("textureFile");
        Vector3 position = {amNode.second.get<float>("position.x"), amNode.second.get<float>("position.y"), amNode.second.get<float>("position.z")};
        Vector3 scale = {amNode.second.get<float>("scale.x"), amNode.second.get<float>("scale.y"), amNode.second.get<float>("scale.z")};
        Vector3 rotationAxis = {amNode.second.get<float>("rotationAxis.x"), amNode.second.get<float>("rotationAxis.y"), amNode.second.get<float>("rotationAxis.z")};
        float rotationAngle = amNode.second.get<float>("rotationAngle");

        animModelPtr = std::make_shared<bomberman::models::AnimatedModels>(mapFolder + modelFile, mapFolder + animatioFile, mapFolder + textureFile, position, scale, rotationAxis, rotationAngle);
        _animatedModels.push_back(animModelPtr);
    } catch (std::exception const &error) {
        throw bomberman::core::Errors("[Map Parser]", "Error in file!");
    }

}

void bomberman::environment::Map::MapParser::checkAnimatedModel(boost::property_tree::ptree::value_type amNode)
{
    std::string nodeChild[4] = {"modelFile", "animationFile", "textureFile", "rotationAngle"};
    std::string nodeChildVector[3] = {"position", "scale", "rotationAxis"};

    for (size_t i = 0; i < 4; i++) {
        try {
            amNode.second.get_child(nodeChild[i]);
        } catch(boost::property_tree::ptree_bad_path const &error) {
            throw bomberman::core::Errors("[Map Parser]", "Error in animated models : \"" + nodeChild[i] + "\"" + " not found!");
        }
    }

    for (size_t i = 0; i < 3; i++) {
        try {
            amNode.second.get_child(nodeChildVector[i]);
            amNode.second.get_child(nodeChildVector[i] + ".x");
            amNode.second.get_child(nodeChildVector[i] + ".y");
            amNode.second.get_child(nodeChildVector[i] + ".z");
        } catch(boost::property_tree::ptree_bad_path const &error) {
            throw bomberman::core::Errors("[Map Parser]", "Error in animated models : \"" + nodeChildVector[i] + "\""  + " or is coordinate aren't found!");
        }
    }
}

void bomberman::environment::Map::MapParser::checkStaticModel(boost::property_tree::ptree::value_type smNode)
{
    std::string nodeChildVector[3] = {"position", "scale", "rotationAxis"};

    try {
        smNode.second.get_child("modelFile");
    } catch(boost::property_tree::ptree_bad_path const &error) {
        throw bomberman::core::Errors("[Map Parser]", "Error in static models : \"modelFile\" not found!");
    }

    for (size_t i = 0; i < 3; i++) {
        try {
            smNode.second.get_child(nodeChildVector[i]);
            smNode.second.get_child(nodeChildVector[i] + ".x");
            smNode.second.get_child(nodeChildVector[i] + ".y");
            smNode.second.get_child(nodeChildVector[i] + ".z");
        } catch(boost::property_tree::ptree_bad_path const &error) {
            throw bomberman::core::Errors("[Map Parser]", "Error in static models : \"" + nodeChildVector[i] + "\" or is coordinate aren't found!");
        }
    }

    try {
        smNode.second.get_child("rotationAngle");
    } catch(boost::property_tree::ptree_bad_path const &error) {
        throw bomberman::core::Errors("[Map Parser]", "Error in static models : \"rotationAngle\" isn't found!");
    }
}

void bomberman::environment::Map::MapParser::createStaticModel(boost::property_tree::ptree::value_type smNode, std::string mapFolder)
{
    std::shared_ptr<bomberman::models::StaticModels> staticModel;

    checkStaticModel(smNode);
    // getting map informations
    try {
        std::string modelFile = smNode.second.get<std::string>("modelFile");
        Vector3 position = {smNode.second.get<float>("position.x"), smNode.second.get<float>("position.y"), smNode.second.get<float>("position.z")};
        Vector3 scale = {smNode.second.get<float>("scale.x"), smNode.second.get<float>("scale.y"), smNode.second.get<float>("scale.z")};
        Vector3 rotationAxis = {smNode.second.get<float>("rotationAxis.x"), smNode.second.get<float>("rotationAxis.y"), smNode.second.get<float>("rotationAxis.z")};
        float rotationAngle = smNode.second.get<float>("rotationAngle");

        staticModel = std::make_shared<bomberman::models::StaticModels>(mapFolder + modelFile, position, scale, rotationAxis, rotationAngle);
        _staticModels.push_back(staticModel);
    } catch (std::exception const &error) {
        throw bomberman::core::Errors("[Map Parser]", "Error in file!");
    }

}

std::vector<std::shared_ptr<bomberman::models::AnimatedModels>> bomberman::environment::Map::MapParser::getAnimatedModels(void)
{
    return _animatedModels;
}

std::vector<std::shared_ptr<bomberman::models::StaticModels>> bomberman::environment::Map::MapParser::getStaticModels(void)
{
    return _staticModels;
}

std::string bomberman::environment::Map::getMapFolder(void)
{
    return _mapFolder;
}

bool bomberman::environment::Map::MapParser::getMapState(void)
{
    return _isFinish;
}