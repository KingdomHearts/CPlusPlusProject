#ifndef MAINHALL_H
#define MAINHALL_H
#include <string>
#include "mge/core/GameObject.hpp"

class MainHall : public GameObject
{
    public:
        MainHall(std::string pName = "MainHall"
                 );
        virtual ~MainHall();
        GameObject* CreateHall();
    protected:
    private:
};

#endif // MAINHALL_H
