#ifndef HUD_H
#define HUD_H
#include "mge/core/GameObject.hpp"


class HUD : public GameObject
{
    public:
        bool FredPickedUp = false;
        bool FredActive = false;
        static HUD* GetInstance();
        void ActivateFred();
        void DeactivateFred();
        virtual ~HUD();
    protected:
    private:
        HUD();
        GameObject * _borders;

	    static HUD* HUDInstance;
};

#endif // HUD_H
