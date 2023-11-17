#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class CentralPolygonalNumbers
{
    public:
        CentralPolygonalNumbers();
        CentralPolygonalNumbers(int n);
        ~CentralPolygonalNumbers();
        void display();
        bool save(string fileName);
    private:
        int m_max;
        int* m_numArray;
};
CentralPolygonalNumbers::CentralPolygonalNumbers()
{
    m_max = 0;
    m_numArray = new int[m_max];
    for(int i = 0; i < m_max; i++)
    {
        m_numArray[i] = (i * i + i + 2)/2;
    }
}
CentralPolygonalNumbers::CentralPolygonalNumbers(int n)
{
    m_max = n+1;
    m_numArray = new int[m_max+1];
    for(int i = 0; i < m_max; i++)
    {
        m_numArray[i] = (i * i + i + 2)/2;
    }
}
CentralPolygonalNumbers::~CentralPolygonalNumbers()
{
    delete[] m_numArray;
    cout << "CentralPolygonalNumbers destructor called "<< endl;
}
void CentralPolygonalNumbers::display()
{
    for(int i = 0; i < m_max; i++)
    {
       cout << "n: " << i << " maximum number of slices: " << m_numArray[i] << endl;
    }
}
bool CentralPolygonalNumbers::save(string fileName)
{
    ofstream numfile(fileName);
    for(int i = 0; i < m_max; i++)
    {
       numfile << "n: " << i << " maximum number of slices: " << m_numArray[i] << endl;
    }
    return true;
}
int main()
{
    CentralPolygonalNumbers cpn(12);
    cpn.display();
    cpn.save("nums.txt");
}