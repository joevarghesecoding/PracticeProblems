#include <iostream>
#include "timer.h"

using namespace std;

//NOT MADE BY ME
//NOTICE THE ODD TEST
int sum_odd_digits(int n)
{
    if (n == 0)
        return 0;
    int digit = n % 10;
    return n % 2 * digit + sum_odd_digits(n / 10); //<--- WHERE THE MAGIC LIES, THE ODD TEST
}

int main()
{
    Timer begin;
    Timer begin2;
    int ans, ans2;
    begin.start();
    ans = sum_odd_digits(258);
    begin.stop();
    cout << ans << endl;
    begin.show();

    begin2.start();
    ans2 = sum_odd_digits(234);
    begin2.stop();
    cout << ans2 << endl;
    begin2.show();

    return 0;
}