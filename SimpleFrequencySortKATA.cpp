#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//std::vector<int> solve(const std::vector<int>& vec) {
//
//}

int main()
{
	int count(0);
	std::vector<int> vec = { 2,3,5,3,7,9,5,3,7 };
	vector<int> vec2(vec.size());
	std::sort(vec.begin(), vec.end());
	/*for (auto i = vec.begin(); i != vec.end(); i++)
	{
		for (auto j = vec.begin(); j != vec.end(); j++)
		{
			if (*i == *(j+1))
				count++;
			if (count == 0)
				vec2.push_back(*i);
			else if (count == 1)
			{
				while (count > 0)
				{
					vec2.push_back(*i);
					count--;
				}
			}
			else if (count > 1)
			{
				while (count > 0)
				{
					vec2.push_back(*i);
					count--;
				}
			}

		}
	}*/

	for (auto i = vec.begin(); i != vec.end(); i++) cout << *i << " ";
	
	return 0;
}