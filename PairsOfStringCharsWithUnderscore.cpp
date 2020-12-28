//Complete the solution so that it splits the string into pairs of two characters. If the string contains an odd number of characters then it should replace the missing second character of the final pair with an underscore ('_').

// Examples:

// solution("abc") // should return {"ab", "c_"}
// solution("abcdef") // should return {"ab", "cd", "ef"}

#include <string>
#include <vector>

using namespace std;

vector<string> solution(const string &s)
{
    string under = "_";
    string b = s;
    vector<string> myString;
  
    if(b.length() % 2 != 0)
      b.append(under);
    
    for(int i = 0; i < b.length()-1; i+=2)
    {
      string a = b.substr(i, 2);
      myString.push_back(a);
    }

    return myString; 
}


