﻿#include <iostream>
#include <time.h>

using namespace std;

/*
열거체 : 연속된 숫자에 이름을 부여할 수 있는 기능이다.
enum 열거체명 {} 의 형태로 구성된다.
열거체명을 이용해서 열거체 타입의 변수를 선언도 가능하다.
즉. 열거체 자체가 사용자정의 변수 타입이 될 수도 있다.
열거체는 숫자에 이름을 붙여주는 기능이다.
*/

enum NUM
{
    NUM_0,  // 아무것도 부여하지 않을 경우 0부터 1씩 차례로 값이 부여된다.
    NUM_1,
    NUM_2,
    NUM_3
};

#define NUM_4  4

enum SRP
{
    SRP_S = 1,
    SRP_R,
    SRP_P,
    SRP_END
};

int main()
{
    /*
    switch 문 : 분기문의 한 종류이다. if문이 조건을 체크하는 분기문이라면
    switch문은 값이 뭔지를 체크하는 분기문이다.
    형태 : switch(변수) {} 의 형태로 구성된다. 코드블럭 안에는 case break 구문이
    들어가게 된다. case 상수: 의 형태로 처리가 되고 변수값이 무엇인지에 따라서
    case 뒤에 오는 상수를 비교하게 된다.
    */
    int iNumber = 1;
#if 0
    cout << "숫자를 입력하세요 : ";
    cin >> iNumber;

    switch (iNumber)
    {
    case NUM_0: // iNumber값이 무엇인지에 따라서 실행되는 case 구분이 결정된다.
        cout << "입력한 숫자는 1입니다." << endl;
        break;  // break 를 만나게 되면 switch 문을 빠져나가게 된다.
    case NUM_1:
        cout << "입력한 숫자는 2입니다." << endl;
        // 여기처럼 break가 없을 경우 바로 아래에 있는 case 구분도 강제로
        // 실행이 되게 된다.
    case NUM_2:
        cout << "입력한 숫자는 2입니다." << endl;
        break;
    case NUM_3:
        cout << "입력한 숫자는 3입니다." << endl;
        break;
    case NUM_4:
        cout << "입력한 숫자는 4입니다." << endl;
        break;
    default:  // case 로 지정되어 있지 않은 숫자가 들어올 경우 실행된다.
        cout << "그 외의 숫자입니다." << endl;
        break;
    }
#endif

    // 열거체 타입의 변수를 선언했다. 열거체 타입 변수는 무조건 4byte를
    // 차지하게 된다. 열거체를 이용해서 선언한 변수는 값의 표현 범위가
    // 열거체에 나열된 값들 안에서 선택해서 사용한다.
    NUM     eNum = (NUM)10;

    // sizeof(타입 or 변수) 를 하게 되면 해당 타입 혹은 변수의 메모리 크기를
    // 구해준다.
    cout << sizeof(NUM) << endl;
    // typeid(타입 or 변수).name() 을 하게 되면 typeid 안에 들어간 타입 혹은
    // 변수의 타입을 문자열로 반환해준다.
    cout << typeid(eNum).name() << endl;
    cout << eNum << endl;

    /*
    반복문 : 특정 작업을 반복해서 수행해주는 기능이다.
    종류 : for, while, do while 3종류가 존재한다.
    while(조건식) {} 의 형태로 구성된다.
    while문은 조건식을 체크해서 true일 경우 코드블럭 안의 코드가 동작되고 다시
    조건식을 체크한다. 조건식이 false가 되면 while문을 빠져나오게 된다.
    반복문 안에서 break를 만나게되면 해당 반복문을 빠져나오게 된다.
    */
    iNumber = 0;
    while (iNumber < 10)
    {
        cout << iNumber << endl;
        ++iNumber;

        if (iNumber == 4)
            break;
    }

    // 화면을 깨끗이 지워준다.
    system("cls");

    // 난수테이블 생성
    srand((unsigned int)time(0));

    int iPlayer, iAI;

    //while (true)
    while (false)  // for문 실습을 위해 변경
    {
        cout << "1. 가위" << endl;
        cout << "2. 바위" << endl;
        cout << "3. 보" << endl;
        cout << "4. 종료" << endl;
        cout << "메뉴를 선택하세요 : ";
        cin >> iPlayer;

        if (iPlayer < SRP_S || iPlayer > SRP_END)
        {
            cout << "잘못된 값을 입력하였습니다." << endl;
            // 일시정지
            system("pause");
            // countinue : 반복문의 시작점으로 이동시켜주는 기능이다.
            continue;
        }
        else if (iPlayer == SRP_END)
            break;

        // 봇이 선택을 한다.
        iAI = rand() % 3 + SRP_S;

        switch (iAI)
        {
        case SRP_S:
            cout << "AI : 가위" << endl;
            break;
        case SRP_R:
            cout << "AI : 바위" << endl;
            break;
        case SRP_P:
            cout << "AI : 보" << endl;
            break;
        }

        int iWin = iPlayer - iAI;

        /*
        if (iWin == 1 || iWin == -2)
            cout << "Player 승리" << endl;
        else if (iWin == 0)
            cout << "비김";
        else
            cout << "AI 승리" << endl; */

        switch (iWin)
        {
        case 1:
        case -2:
            cout << "Player 승리" << endl;
            break;
        case 0:
            cout << "비김";
            break;
        default:
            cout << "AI 승리" << endl;
            break;

        }

        system("pause");
    }

    /*
    for (int i
    */

    /*
    for문 : 반복문의 한 종류이다.
    형태: for(초기값; 조건식; 증감값) {} 의 형태로 구성이 된다.
    조건식이 true이면 코드블럭의 코드가 동작된다.
    무한루프를 돌릴때는 for(;;) {} 을 해주면 무한으로 돌아가게 된다.
    for문에서 초기값은 처음 for문에 진입할때 딱 1번만 동작된다. 그 후에 조건식을
    체크하고 조건식이 true이면 코드블럭의 코드가 동작된 후에 증감값을 처리한다.
    그후 다시 조건을 체크하고 true면 동작되고 증감 -> 조건 -> 증감 -> 조건의
    순서로 처리가 된다. false이거나 break를 만나게 되면 for문을 빠져나가게
    된다.
    */
    // 초기값 : i = 0 조건식 : i < 10  증감값 : ++ㅑ
    // 먼저 for문에 진입하면서 초기값이 실행되므로 i를 0으로 초기화한다.
    // 그 후에 i < 10을 체크해서 0일때는 true가 나오게 되어 i값을 출력한다.
    // 그 후에 증감을 처리하는데 ++을 하면 0에서 1이 되고 조건을 체크하게 된다.
    // 2 출력 3, 4, 5, 6, 7, 8, 9 까지는 조건이 true라서 9를 출력하고
    // ++이 되어 10이 되고 10 < 10을 하면 조건이 false가 되므로 반복문을
    // 빠져나오게 된다.
    for (int i = 0; i < 10; ++i)
    {
        cout << i << endl;
    }

    // 구구단 2단을 출력해보자.
    for (int i = 1; i <= 9; ++i)
    {
        cout << "2 * " << i << " = " << 2 * i << endl;
    }

    // 1 ~ 100 사이의 숫자중 짝수만 출력하는 for문을 작성해보자.
    // i += 2   i = i + 2  2일때 4가 되고 4일때 6 6일때 8
    for (int i = 2; i <= 100; i += 2)
    {
        cout << i << " " << endl;
    }

    for (int i = 1; i <= 100; ++i)
    {
        if (i % 3 == 0 && i % 7 == 0)
        {
            cout << i << endl;
        }
    }

    // for문 안에 또다른 FOR문이 존재하는 형태이다.
    // 구구단 출력
    for (int i = 2; i < 10; i++)
    {
        for (int j = 1; j < 10; j++)
        {
            cout << i << "*" << j << " = " << i * j << endl;
        }
    }

    //별모양 출력 1
    // *
    // **
    // ***
    // ****
    // *****
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    //별모양 출력 2
    // *****
    // ****
    // ***
    // **
    // *
    for (int i = 5; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    //별모양 출력 3
    //    *
    //   ***
    //  *****
    // *******
    for (int i = 1; i <= 7; i += 2)
    {
        for (int j = 0; j < (7 - i) / 2; j++)
            cout << " ";
        for (int k = 0; k < i; k++)
            cout << "*";
        cout << endl;
    }
    
    //별모양 출력 4
    // *******
    //  *****
    //   ***
    //    *
    for (int i = 7; i > 0; i -= 2)
    {
        for (int j = 0; j < (7 - i) / 2; j++)
            cout << " ";
        for (int k = 0; k < i; k++)
            cout << "*";
        cout << endl;
    }

    return 0;
}

