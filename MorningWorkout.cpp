#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	string s = "abc####d##c#";
	int count(0);
	//vector<char> a(s.length());
	cout << s << endl;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '#')
			count++;
	}
	if (count > s.length() / 2)
		s = "";
	while(s.find("#") != NULL)
	{
		try {
			int i = s.find("#");
			if (i > s.length()) break;
			string del = s.substr(i - 1, 2);
			s.erase(i - 1, del.length());
			cout << s << endl;
		}
		catch (exception& e)
		{
			cerr << "Error from " << e.what() << endl;
		}
			
	}
	
	//cout << s << endl;
	return 0;
}