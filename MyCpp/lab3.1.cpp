#include <iostream>
using namespace std;

//temputer change

float Convert(float);
int main(void)
{
    float TempFer;
    float TempCel;

    cout << "�����뻪���¶ȣ�";
    cin >> TempFer;
    TempCel = Convert(TempFer);
    cout << "\nת��Ϊ�����¶��ǣ�";
    cout << TempCel << endl;
    return 0;
}

float Convert(float TempFer)
{
    float TempCel;
    TempCel = ((TempFer - 32) * 5) / 9;
    return TempCel;
}
