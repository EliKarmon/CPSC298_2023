#include <iostream>
#include <string>
using namespace std;
class ElectronicControlUnit
{
    private:
        bool* m_hydraulics = new bool; //button A
        bool* m_beltTires = new bool; // button B
        bool* m_illumination = new bool; //button C
        void activateHydraulics();
        void activateBelts();
        void activateIllumination();
    public:
        ElectronicControlUnit();
        ~ElectronicControlUnit();
        void handleCommand(char c);
};
ElectronicControlUnit::ElectronicControlUnit()
{
    *m_beltTires = false;
    *m_hydraulics = false;
    *m_illumination = false;
}
ElectronicControlUnit::~ElectronicControlUnit()
{
    delete m_beltTires;
    delete m_hydraulics;
    delete m_illumination;
}
void ElectronicControlUnit::activateHydraulics()
{
    if(*m_hydraulics)
    {
        *m_hydraulics = false;
        cout << "Hydraulic Jacks Deactivated" << endl;
    }
    else
    {
        if(*m_beltTires)
        {  
            *m_beltTires = false;
            cout <<"Belt Tires Deactivated" << endl;
        }
        *m_hydraulics = true;
        cout << "Hydraulic Jacks Activated" << endl;
    }
    

    
}
void ElectronicControlUnit::activateBelts()
{
    if(*m_beltTires)
    {
        *m_beltTires = false;
        cout << "Belt Tires Deactivated" << endl;
    }
    else
    {
        *m_beltTires = true;
        cout << "Belt Tires Activated" << endl;
    }
}
void ElectronicControlUnit::activateIllumination()
{
    if(*m_illumination)
    {
        *m_illumination = false;
        cout << "Infared Illumination Deactivated" << endl;
    }
    else
    {
        *m_illumination = true;
        cout << "Infared Illumination Activated" << endl;
    }
}
void ElectronicControlUnit::handleCommand(char c)
{
    switch(c)
    {
        case 'A':
        case 'a':
            activateHydraulics();
            break;
        case 'B':
        case 'b':
            activateBelts();
            break;
        case 'E':
        case 'e':
            activateIllumination();
            break;
    }
}
int main()
{
    char input = 'y';
    cout << "Press X to turn off the car, or enter a command with A, B, or E" << endl;
    cout <<"   (A)   " << endl << "(F)(G)(B)" << endl << "(E)   (C)" << endl <<"   (D)   " << endl;
    ElectronicControlUnit* e = new ElectronicControlUnit();
    while(input != 'X')
    {
        cin >> input;
        e->handleCommand(input);
        if(input == 'X'){break;}
        cout << "Press X to turn off the car, or enter a command with A, B, or E" << endl;
        cout <<"   (A)   " << endl << "(F)(G)(B)" << endl << "(E)   (C)" << endl <<"   (D)   " << endl;
    }
    delete e;
}