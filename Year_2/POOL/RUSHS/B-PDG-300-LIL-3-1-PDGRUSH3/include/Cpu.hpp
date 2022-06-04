/*
** EPITECH PROJECT, 2022
** B-PDG-300-LIL-3-1-PDGRUSH3-pierre-jean.descarpentries
** File description:
** Cpu
*/

#ifndef CPU_HPP_
#define CPU_HPP_

#include <unistd.h>
#include <vector>
#include <fstream>
#include <cstring>
#include <filesystem>

class Cpu {
    public:
        Cpu();

        void Do_calcul(void); // effectue les calculs et met les résultats dans _Usage.

        int getNumberCore(void); // nombre de coeurs
        std::vector<std::string> getUsage(void); // renvoie un tableau de string avec l'utilisation en % de chaque coeur /!\ LE 0 c'est le proc en général donc le tab va de 0 à 8 inclu
        std::string getName(void); // renvoie un string avec le nom du proc genre Intel blablabla
        std::vector<float> getFrequency(void); // renvoie un tableau de float avec les frequences de chaque coeurs.

        void setUsage(void); // init des tableau de données | utilisation unique dans le constructor
        void setOldValue(void); // change les tableaux old avec les valeurs de current
        void setCurrentValue(void); // Prend les nouvelles valeurs de l'ordi et les met dans les tableaux current
        void setFrequency(void); // met à jour le tableau des frequences des coeurs

        void searchNameCpu(void); // set le nom du proc utilisé
        void refresh(void); // set old et current (en utilisant les setters) puis appelle la fonction de calculs.

    private:
        int _nbr_core;
        std::vector<float> _frequency;
        std::string _name;
        std::vector<float> _oldValueC;
        std::vector<float> _oldValueA;
        std::vector<float> _CurrentValueC;
        std::vector<float> _CurrentValueA;
        std::vector<std::string> _Usage;
};

#endif /* !CPU_HPP_ */
