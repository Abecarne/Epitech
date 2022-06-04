/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** DLLoader
*/

#ifndef DLLOADER_HPP_
#define DLLOADER_HPP_

#include <iostream>
#include <dlfcn.h>

/*
Utillisation de template pour la classe DLLoader :
    - Générique pour les types IGameModule et IDisplayModule
    - Pas besoin d'include Core.hpp
    - Pas de "boucle-inf" dans les includes avec Core.hpp / Errors.hpp / DLLoader.hpp
*/

template <class T>
class DLLoader {
    public:
        DLLoader() {}
        ~DLLoader() {}

        void *open(const std::string filename, int flag) { return (dlopen(filename.c_str(), flag)); }

        void *sym(void *handle, std::string symbol) { return (dlsym(handle, symbol.c_str())); }

        std::string error(void) { return (dlerror()); }

        int close(void *handle) { return (dlclose(handle)); }

        void loadShared(std::string filepath)
        {
            handle = this->open(filepath, RTLD_NOW);
            if (!handle)
                throw std::invalid_argument("Cannot open library: " + this->error());

            T *(*loaded)(void) = (T *(*)(void))this->sym(handle, "EntryPoint");
            instance = loaded();
            if (!instance)
                throw std::runtime_error("Unable to load library : " + filepath);
        }

        void unloadShared(void)
        {
            if (instance != nullptr)
                delete instance;
            this->close(handle);
        }

        T *getInstance(void) { return (instance); }
    
    private:
        void *handle;
        T *instance;
};

#endif /* !DLLOADER_HPP_ */
