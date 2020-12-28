#include <string>
#include <vector>
#include <iostream>
#include <cmath>

std::string encode(std::string text)
{
   std::string finalResult;
   for(int i = 0; i <= text.length()-1; i++) 
   {
     std::string binary = "00000000";
      int temp = (int)text[i];
      std::cout << "etemp " << temp << std::endl;
      for(int i = binary.length()-1; i >= 0; --i)
      {
        temp%2 == 0 ? binary[i] = '0' : binary[i] = '1';
        temp /= 2;
        std::cout << "ebinary " << binary << std::endl;
        if(temp == 0)
          break;
      }
      int j = 0;
      while(j < binary.length())
      {
        finalResult = finalResult + binary[j] + binary[j] + binary[j];
        j++;
      }
    
   }
   return finalResult;  
}

std::string decode(std::string bits)
{
    std::string triplets; 
    std::vector<int>bytes;
    std::vector<int>decimal;
    std::string result;
    for(int i = 0; i < bits.length(); i += 3)
    {
      std::string temp = bits.substr(i, 3);
      std::cout << "dtemp " << i << " " << i+3 << " "<< temp << std::endl;
      if(temp == "001" || temp == "000" || temp == "100" || temp == "010")
        temp = "0";
      else if(temp == "111" || temp == "101" || temp == "110" || temp == "011")
        temp = "1";
        
      triplets += temp;
    }
    std::cout << "triplets " << triplets << std::endl;
    for(int i = 0; i < triplets.length()-1; i += 8)
    {
      bytes.push_back(stoi(triplets.substr(i,8)));
    }
    for(auto i = bytes.begin(); i != bytes.end(); i++)
    {
      int decimalNumber = 0, k = 0, remainder;
      while(*i != 0)
      {
        remainder = *i%10;
        *i /= 10;
        decimalNumber += remainder * pow(2, k);
        k++;

      }
      decimal.push_back(decimalNumber);
    }
    // for(auto i = bytes.begin(); i != bytes.end(); i++)
    // {
    //   std::cout << *i << std::endl;
    // }
     for(auto i = decimal.begin(); i != decimal.end(); i++)
    {
      std::cout << *i << std::endl;
    }
    for(auto i = decimal.begin(); i != decimal.end(); i++)
    {
      result += (char)*i; 
    }
    return result;
}


int main()
{

  std::string prob = "T?st!%";
  std::string ans = encode(prob);
  std::cout << "encode " << ans << std::endl;
  std::string prob2 = decode(ans);
  std::cout << "decode " << prob2 << std::endl;

  return 0;
}

//000 111 000 111 000 111 000 000 000 111 111 000 111 000 000 000 000 111 111 000 000 111 000 111 000 000 111 000 000 000 000 000 000 111 000 111 000 000 111 111 000 111 111 000 000 111 000 111 000 111 111 000 111 111 111 000 000 111 111 111 000 000 111 111 000 111 111 000 000 111 000 111 000 111 111 000 111 000 000 111 000 000 111 000 000 000 000 000 000 111 111 111 000 111 000 000 000 111 111 000 111 111 111 111 000 111 111 000 111 111 000 000 000 111 111 000 000 111 000 000 000 000 111 000 000 000 000 000 000 111 111 000 111 111 000 111 000 111 111 000 000 111 000 111 000 000 111 000 000 000 000 000 000 111 111 111 000 111 000 000 000 111 111 000 111 000 000 000 000 111 111 000 000 000 000 111 000 111 111 111 000 111 000 000 000 000 111 000 000 000 000 000 000 111 111 000 111 000 000 111 000 000 111 000 000 000 000 000 000 111 111 000 000 000 111 111 000 111 111 000 000 000 000 111 000 111111000111111111000000000111000000000000000000111111000000111000000000111111000111111111111000000111000000000000000000111111111000111000000000111111000111000000000000111111000111000000111000111111111000000111111000000111000000000000000000111111000111000111111000111111000000000000111000111111111000111000000000111111000000000000111