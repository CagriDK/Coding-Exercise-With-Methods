#include <iostream>
#include <string>
#include <map>
using namespace std;

enum StringValues {
    P,
    A,
    M,
    S,
    L,
    Q
};

map<string, StringValues> m_StringValues;

void register_levels()
{
    //Argument input values are m_String_Values["input"] , if "Q" is written to argument
    //enum value Q is selected and case Q is activated

    m_StringValues["P"] = P;
    m_StringValues["A"] = A;
    m_StringValues["M"] = M;
    m_StringValues["S"] = S;
    m_StringValues["L"] = L;
    m_StringValues["Q"] = Q;

    //If  m_StringValues["Q"] change to m_StringValues["Q_Value"] , the argument should written to cmd as "Q_Value" to activate Q case
    //m_StringValues["Q_Value"] = Q;
}

int main()
{
    register_levels();
    string input;
    cin >> input;
    switch (m_StringValues[input])
    {
    case P:
        cout << "Case P selected from command prompt!"; break;
    case A:
        cout << "Case A selected from command prompt!"; break;
    case M:
        cout << "Case M selected from command prompt!"; break;
    case S:
        cout << "Case S selected from command prompt!"; break;
    case L:
        cout << "Case L selected from command prompt!"; break;
    case Q:
        cout << "Case Q selected from command prompt!"; break;
    }
    return 0;
}