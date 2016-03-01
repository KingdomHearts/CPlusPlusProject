#ifndef MAINHALL_H
#define MAINHALL_H
#include <string>
#include "mge/core/GameObject.hpp"

class MainHall : public GameObject
{
    public:
        MainHall(std::string pName = "MainHall");
        virtual void update(float pStep);
        virtual ~MainHall();
    protected:
    private:
};

#endif // MAINHALL_H
