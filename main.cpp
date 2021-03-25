/* 
* This is like
* the shittiest fucking calculator you've ever seen
* it can do four (4) things given two (2) numbers and thats it
* hey it can detect spaces between inputs and process floats at least
* man i hate c++
*/

#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main()
{
    while(1) 
    {
        cout << "> ";
        string in_expr;

        getline(cin, in_expr);
        regex e ("(\\d+(?:\\.\\d+)?)\\s*([+\\-*/])\\s*(\\d+(?:\\.\\d+)?)");
        smatch matches;

        if (regex_match(in_expr, matches, e))
        {
            string::size_type sz;
            
            float num1 = stof(matches.str(1), &sz);
            string op = matches.str(2);
            float num2 = stof(matches.str(3), &sz);

            if (op == "+") 
                cout << num1+num2 << endl;
            else if (op == "-")
                cout << num1-num2 << endl;
            else if (op == "*")
                cout << num1*num2 << endl;
            else if (op == "/")
                cout << num1/num2 << endl;
        }
        else
            cout << "Malformed input; try again!" << endl;
    }
}