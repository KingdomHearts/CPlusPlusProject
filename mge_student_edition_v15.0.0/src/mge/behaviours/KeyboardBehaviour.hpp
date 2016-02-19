#ifndef KEYBOARDBEHAVIOUR_H
#define KEYBOARDBEHAVIOUR_H


class KeyboardBehaviour
{
    public:
        KeyboardBehaviour();

        static KeyboardBehaviour* GetInstance();
        void BindMeshToButton(int pNumberToBind);
    protected:
    private:

        static KeyboardBehaviour* KeyBoardInstance;
};

#endif // KEYBOARDBEHAVIOUR_H
