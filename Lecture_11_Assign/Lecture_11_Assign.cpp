#include <iostream>

using namespace std;

int main()
{
    /*
    구구단을 2단부터 9단까지 출력한다.
    */
    for (int i = 2; i <= 9; ++i)
    {
        for (int j = 1; j <= 9; ++j)
        {
            cout << i << " * " << j << " = " << i * j << endl;
        }
        cout << endl;
    }

    /*
    2단  3단  4단
    5단  6단  7단
    8단  9단  10단
    */

    /*
    *
    **
    ***
    ****
    *****
    */

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < i + 1; ++j)
        {
            cout << "*";
        }
        cout << endl;
    }

    /*
    *****
    ****
    ***
    **
    *
    */

    cout << endl;

    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5 - i; ++j)
        {
            cout << "*";
        }
        cout << endl;
    }

    /*
       *
      ***
     *****
    *******
    */
    // 공백 : 3, 2, 1, 0  별 : 1, 3, 5, 7
    for (int i = 0; i < 4; ++i)
    {
        // 공백을 출력하기 위한 for문
        for (int j = 0; j < 3 - i; ++j)
        {
            cout << " ";
        }

        // *을 출력하기 위한 for문
        for (int j = 0; j < i * 2 + 1; ++j)
        {
            cout << "*";
        }

        cout << endl;
    }

    return 0;
}
