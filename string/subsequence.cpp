#include <iostream>
#include <string>

using namespace std;

void printsub(string input, string output)
{
    if (input.empty())
    {
        cout << output << " ";
        return;
    }
    else
    {
        printsub(input.substr(1), output + input[0]);
        printsub(input.substr(1), output);
    }
}

int main()
{
    string output = "";
    string input = "abc";
    printsub(input, output);
}