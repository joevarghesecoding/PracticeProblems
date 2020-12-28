#include <iostream>
#include <deque>
#include <cmath>
#include <stack>

using namespace std;


int main()
{
	int n = 89;
	int p = 1;
	deque<int> num;
	int total(0);

	//testing to see if my modolus works because output printed nothing
	//the mistake i made was not getting rid of the 9 by dividing out by 10
	/*cout << n % 10 << endl;
	n /= 10;
	cout << n << endl;
	cout << n % 10 << endl;
	n /= 10;
	cout << n << endl;
	n /= 10;
	cout << n << endl;*/

	//Tried this alogirthm, first idea that popped into my head for separating digits, missed dividing the 10

	//changed the for loop to a while
	while (n > 0)
	{
		num.push_front(n % 10);
		n /= 10;
	}
	
	deque<int>::iterator itrNum;
	for (itrNum = num.begin(); itrNum != num.end(); itrNum++)
	{
		total += pow(*itrNum, p);
		
		cout << "Total: " << total << " *itrNum: " << *itrNum << " p: " << p << endl;
		p++;
	}

	if (total % n == 0)
	{
		int result = total / n;
		cout << "Result: " << result << endl;
	}
	else
		cout << "-1" << endl;
	cout << "DONE " << endl;

	return 0;
}

/*
Best solution I found: converting to a string and then back to a int and checking
#include <cmath>
using namespace std;
class DigPow
{
public:
  static int digPow(int n, int p){
   long long sum=0;
   for(char digit : to_string(n)){ //took advantage of the c++ for method
	 sum+=pow(digit-'0',p++);
   }
   return (sum/n)*n==sum ? sum/n : -1;
  }
};
*/

/*My CODE
#include <deque>
#include <cmath>
class DigPow
{
public:
  static int digPow(int n, int p);
};

int DigPow::digPow(int n, int p)
{
  int number = n;
  std::deque<int> num;
  int total(0);
  while(n>0)
	{
	num.push_front(n%10);
	n /= 10;
  }
  for(auto itrNum = num.begin(); itrNum != num.end(); itrNum++)
	{
	total += pow(*itrNum, p);
	p++;
  }
  if(total % number == 0)
	return total / number;
  else
	return -1;
}
*/