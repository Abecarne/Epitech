/*
** EPITECH PROJECT, 2022
** delivery
** File description:
** KoalaDoctor
*/

#ifndef KOALADOCTOR_HPP_
#define KOALADOCTOR_HPP_

class KoalaDoctor {
    public:
        KoalaDoctor(std::string doctor_name);
        ~KoalaDoctor();
        void diagnose(SickKoala *patient);
        void timeCheck(void);
        std::string getName(void);

    private:
        std::string _doctorName;
        bool _docWorks = false;
};

#endif /* !KOALADOCTOR_HPP_ */
