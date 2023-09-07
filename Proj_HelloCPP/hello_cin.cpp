/// @file hello_cin.cpp
/// @brief takes a single-word message as input, then outputs it to the console
/// @author Eli Karmon


#include <iostream>
#include <string>
using namespace std;
int main()
{
string strMessage;
cout << "Please type a single word message" << endl;
cin >> strMessage;
cout << "Message: " << strMessage << endl;
return 0;
}