#include <iostream>
#include <vector>

using namespace std;

vector<int> sortArray(vector<int> &array)
{
    vector<int> oddArr;
    vector<int> oddIndex;
    int min = array[array.size()-1];
    if(!array.empty())
    {
        for(int j = 0; j < array.size(); j++)
        {
          if(array[j] % 2 != 0) //place odd number and index in vectors
          {
            if(array[j] == 0)
              continue;
            else
            { 
              oddArr.push_back(array[j]);
              oddIndex.push_back(j);
            }
          }
        }
      for(int i = oddArr.size(); i > 0; i--)
      {
        for(int j = 0; j < oddArr.size()-1; j++)
        {
          if(oddArr[j] > oddArr[j+1])
          {
            int tmp = oddArr[j];
            oddArr[j] = oddArr[j+1];
            oddArr[j+1] = tmp;
          }
        }
      }
      for(int i =0; i < oddArr.size(); i++)
      {
        array[oddIndex[i]] = oddArr[i];
      }
    }
    else
      return {};
    
    return array;
}

int main()
{
  vector<int> arr = {82, 46, 13, 20, 24, 17, 27, 90, 16, 80, 37, 10, 79, 8, 62, 79, 87, 89, 38, 20, 94, 89, 34, 91};
 
  sortArray(arr);
  for(int i = 0; i < arr.size(); i++)
  {
    cout << arr[i] << ", ";
  }

  return 0;
}