#include <iostream> 
using namespace std;

class CUltimateMachine
{
    public:
        CUltimateMachine() : m_bState(false)
        {
            cout << "CUltimateMachine constructor called" << endl;
        }

        ~CUltimateMachine()
        {
            cout << "CUltimateMachine destructor called " << endl;
        }

        void displayState()
        {
            switch(m_bState)
            {
                case true:
                cout << "Ultimate machine is ON" << endl;
                break;
                case false:
                cout << "Ultimate machine is OFF" << endl;
                break;
            }
        }
        void turnOn()
        {
            m_bState = true; 
            displayState();
            if(true == m_bState)
            {
                m_bState = false; 
            }
            displayState();
        }
    private:
        bool m_bState; // true for on, false for off;
};

int main()
{
    cout << "The Ultimate Machine Simulation" << endl;

    CUltimateMachine ultMach;
    ultMach.displayState();
    ultMach.turnOn();
}