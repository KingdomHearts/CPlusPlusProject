#ifndef MOUSEBEHAVIOUR_H
#define MOUSEBEHAVIOUR_H

#include "mge/behaviours/AbstractBehaviour.hpp"

class MouseBehaviour : public AbstractBehaviour
{
    public:
        MouseBehaviour(float mouseSpeed = 1);
        virtual ~MouseBehaviour();
		virtual void update( float step );
    protected:
    private:
        float _mouseX;
        float _mouseY;
        float _mouseSpeed;
};

#endif // MOUSEBEHAVIOUR_H
