#include <vector>
#include <iostream>

void wave_sort(std::vector<int> &v) 
{
  for(int i = 0, h = -1, j = 1; i < v.size(); i++, h++, j++)
  {
    if(i%2 == 0)
    {
      if(i == 0)
      {
        if(v[i] < v[j])
        {
          int temp = v[j];
          v[j] = v[i];
          v[i] = temp;
        }
      }
      else if(i != 0)
      {
        if(v[i] < v[j] || v[i] < v[h])
        {
          int temp = v[j];
          v[j] = v[i];
          v[i] = temp;
        }
      }
    }
    else if(i%2 != 0)
    {
      if(v[i] > v[h] || v[i] > v[j])
      {
        int temp = v[j];
          v[j] = v[i];
          v[i] = temp;
      }
    }
  }
    
}

int main()
{
  std::vector<int> v = {9, 47, 22, 23, 33, 14, 46, 9, 29, 39, 13, 29, 44, 91};
  wave_sort(v);
  int count(0);
  for(auto i = v.begin(); i != v.end(); i++)
  {
    std::cout << count << " " << *i << std::endl;
    count++;
  }
  return 0;
}
