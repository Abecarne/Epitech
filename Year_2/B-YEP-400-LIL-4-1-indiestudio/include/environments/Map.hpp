/*
** EPITECH PROJECT, 2020
** Pikmins
** File description:
** Map.hpp
*/
#pragma once

#include "AnimatedModels.hpp"
#include "StaticModels.hpp"

#include <raylib.h>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <fstream>
#include "boost/property_tree/ptree.hpp"
#include "boost/property_tree/json_parser.hpp"

/*
        MAP FILE INFORMATIONS

SM = Static Model
    ModelType:ModelFile:Position:Scale:rotationAngle

AM = Animated Model
    ModelType:ModelFile:AnimationFile:TextureFile:Position:Scale:rotationAngle

*/

#define PICNIC_MAP "./assets/models/maps/picnic/"
#define CHINEASE_MAP "./assets/models/maps/chinease/"

#define SM_INFOS_NBR 6
#define AM_INFOS_NBR 8

#define SM_MAP_INFOS_FILENAME 1
#define SM_MAP_INFOS_POSITION 2
#define SM_MAP_INFOS_SCALE 3
#define SM_MAP_INFOS_ROTATIONAXIS 4
#define SM_MAP_INFOS_ROTATION 5

#define AM_MAP_INFOS_FILENAME 1
#define AM_MAP_INFOS_ANIMATION 2
#define AM_MAP_INFOS_TEXTURE 3
#define AM_MAP_INFOS_POSITION 4
#define AM_MAP_INFOS_SCALE 5
#define AM_MAP_INFOS_ROTATIONAXIS 6
#define AM_MAP_INFOS_ROTATION 7

namespace bomberman {

    namespace environment {

        class Map {
            private:
                std::string _mapFolder;
                class MapParser {
                    private:
                        enum loadingState {
                            SM,
                            AM
                        };

                        boost::property_tree::ptree _root;
                        std::vector<std::shared_ptr<bomberman::models::StaticModels>> _staticModels;
                        std::vector<std::shared_ptr<bomberman::models::AnimatedModels>> _animatedModels;
                        bomberman::environment::Map::MapParser::loadingState _loadingState;
                        size_t _loadingCount;
                        bool _isFinish;

                        void openFile(std::string file);
                        void createStaticModel(boost::property_tree::ptree::value_type smNode, std::string mapFolder);
                        void checkStaticModel(boost::property_tree::ptree::value_type smNode);
                        void createAnimatedModel(boost::property_tree::ptree::value_type smNode, std::string mapFolder);
                        void checkAnimatedModel(boost::property_tree::ptree::value_type amNode);
                        void getNextAMModels(std::string mapFolder);
                        void getNextSMModels(std::string mapFolder);

                    public:
                        MapParser(void) {}
                        ~MapParser(void) {}
                        void init(std::string mapFolder);
                        bool getMapState(void);
                        void getNextMapModels(std::string mapFolder);

                        std::vector<std::shared_ptr<bomberman::models::StaticModels>> getStaticModels(void);
                        std::vector<std::shared_ptr<bomberman::models::AnimatedModels>> getAnimatedModels(void);
                };
                std::vector<std::shared_ptr<bomberman::models::StaticModels>> _staticModels;
                std::vector<std::shared_ptr<bomberman::models::AnimatedModels>> _animatedModels;
                bomberman::environment::Map::Map::MapParser _mapParser;

            public:
                Map(void) {}
                ~Map(void);
                void init(std::string mapFolder);
                void loadNextModels(void);
                bool getAssetsState(void);

                void updateMap(void);
                void renderMap(void);
                bomberman::environment::Map::MapParser getMapDatas(void);

                std::string getMapFolder(void);
        };

    };

};
