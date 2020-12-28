#include <vector>
#include <iostream>
#include <algorithm>

template <typename T>
void swap(T* a, T* b)
{
  if(a != b)
  {
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
  }
}
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
          swap(&v[i],&v[j]);
        }
      }
      else if(i != 0)
      {
        if(v[i] < v[j] || v[i] < v[h])
        {
          swap(&v[i], &v[j]);
        }
      }
    }
  }
}

// void wave_sort(std::vector<int> &v) {
//   if(v.size() <= 1)
//       return;
//   int i = 0;
//   while(i<v.size())
//   {
//     if(i > 0 && v[i-1] > v[i])
//       std::swap(v[i], v[i-1]);
//     if(i < v.size() - 1 && v[i] < v[i + 1])
//       std::swap(v[i + 1], v[i]);
//     i+=2;
//   }
// }
bool is_wave_sorted(std::vector<int> &v)
{
  std::vector<int> r = v;
  wave_sort(r);
  return v == r; 
}

int main()
{
  int count(0);
  std::vector<int> v = {9, 47, 22, 23, 33, 14, 46, 9, 29, 39, 13, 29, 44, 91};
  std::cout << "v.size() " << v.size() << std::endl;
  // for(auto i = v.begin(); i != v.end(); i++)
  // {
  //   std::cout << count << " " << *i << std::endl;
  //   count++;
  // }
  wave_sort(v);
  int count1(0);
  for(auto i = v.begin(); i != v.end(); i++)
  {
    std::cout << count1 << " " << *i << std::endl;
    count1++;
  }
  return 0;
}
