
#include <iostream>
#include <string>
using namespace std;

int main()
{
    char authorizerChar1 = 'E';
    char authorizerChar2 = 'C';
    char authorizerChar3 = 'A';

    char userChar1;
    char userChar2;
    char userChar3;

    string correctInput;
    string userInput;
    correctInput += authorizerChar1;
    correctInput += authorizerChar2;
    correctInput += authorizerChar3;

    cout << "write the first character of the code" << endl; 
    cin >> userChar1;
    userInput += userChar1;
    cout << "write the second character of the code" << endl; 
    cin >> userChar2;
    userInput += userChar2;
    cout << "write the third character of the code" << endl; 
    cin >> userChar3;
    userInput += userChar3;

    cout << "authenticator code: " << correctInput << endl;
    cout << "entered code: " << userInput << endl;

    if(authorizerChar1 == userChar1 && authorizerChar2 == userChar2 && authorizerChar3 == userChar3)
    {
        cout << "correct input!" << endl;
    }
    else
    {
        cout << "authentication failed" << endl;
    }
    if(correctInput == userInput)
    {
        cout << " inputs authenticated through string comparison" << endl;
    }
    else
    {
        cout << " inputs failed to authenticate through string comparison " << endl;
    }

    int checksum = 0;
    checksum = int(userChar1) + int(userChar2) + int(userChar3);
    checksum = checksum % 7;
    if(checksum == 5)
    {
        cout << "  input authenticated with characterization." << endl;
    }
    else
    {
        cout <<"  input failed to authenticate with characterization" << endl;
    }


   
}
