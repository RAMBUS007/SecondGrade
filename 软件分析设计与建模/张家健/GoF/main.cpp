#include<iostream>
#include<windows.h>
using namespace std;

class Controller;

class State
{
public:
    virtual void Handle(Controller* pController) = 0;
};

class Controller
{
public:
    Controller(State * pState)
    {
        m_pState = pState;
    }

    void Request()
    {
        if (m_pState)
        {
            m_pState->Handle(this);
        }
    }

    void ChangeState(State * pState)
    {
        m_pState = pState;
    }

    int getDoor()
    {
        return door;
    }
    void setDoor(int value)
    {
        door = value;
    }
    int getCandle()
    {
        return candle;
    }
    void setCandle(int value)
    {
        candle = value;
    }
private:
    State * m_pState;
    int door = 0;   //0表示门已开 1表示门已关
    int candle = 1; //1表示蜡烛在原位 0表示蜡烛被移动
};



class Wait : public State
{
public:
    virtual void Handle(Controller* pController)
    {
        cout << "GameState: Wait." << endl;
        if (!pController->getDoor())
        {
            cout << "You are searching for the lock......" << endl;
            cout << "Please decide whether to close the door !!!" << endl;
            cout << "Enter 1 to close the door, and 0 to let the door open." << endl;
            int temp;
            cin >> temp;
            pController->setDoor(temp);
            cout << "You are removing the candle......" << endl;
            pController->setCandle(0);
            if (pController->getDoor())
            {
                cout << "The lock is revealed !" << endl;
            }
            else
            {
                pController->Request();
            }
        }
    }
};

class Lock : public State
{
public:
    virtual void Handle(Controller* pController)
    {
        cout << "GameState: Lock." << endl;
        cout << "Please decide whether to put back the candle !!!" << endl;
        cout << "Enter 1 to put back the candle, and 0 to let the candle out." << endl;
        int temp;
        cin >> temp;
        pController->setCandle(temp);
        cout << "You are turning the key ......" << endl;
        Sleep(2000);
    }
};

class Open : public State
{
public:
    virtual void Handle(Controller* pController)
    {
        cout << "GameState: Open." << endl;
        Sleep(1000);
        cout << "3" << endl;
        Sleep(1000);
        cout << "2" << endl;
        Sleep(1000);
        cout << "1" << endl;
        cout << "safe closed !!!" << endl;
    }
};



int main()
{
    State* pWait = new Wait();
    State* pLock = new Lock();
    State* pOpen = new Open();
    Controller* pController = new Controller(pWait);
    pController->Request();
    int loop = 1;
    while (loop)
    {
        pController->ChangeState(pLock);
        pController->Request();
        if (pController->getCandle())
        {
            cout << "The lock is open safely !" << endl;
            pController->ChangeState(pOpen);
            pController->Request();
            pController->ChangeState(pWait);
            pController->Request();
        }
        else
        {
            cout << "You have released the Killer Rabbit, run now!!!" << endl;
            Sleep(1000);
            cout << "3" << endl;
            Sleep(1000);
            cout << "2" << endl;
            Sleep(1000);
            cout << "1" << endl;
            cout << "Game Over" << endl;
            loop = 0;
        }
    }

   

    delete pController;
    delete pLock;
    delete pWait;
    delete pOpen;

    return 0;
}
