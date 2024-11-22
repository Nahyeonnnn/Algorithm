#include<iostream>
#include<string>
using namespace std;

int main() {
    //문자열 S를 받고 수를 센다...
    string str;
    cin>>str;
    int zero=0, one=0;
    int len=str.length();
    for(int i=0;i<len;i++) {
        if(str[i]=='0')
            zero++;
        else if(str[i]=='1')
            one++;
    }

    //타노스
    zero = zero/2;
    one = one/2;

    string result;
    //사전순으로 빨라야 하니까 1은 앞에서부터 지우자
    while (one) {
        for (int i=0; i<str.length(); i++) {
            if (str[i] == '1') {
                str = str.substr(0, i) + str.substr(i + 1);  // 현재 i 위치에서 1 삭제
                one--;
                break;
            }
        }
    }

    //그 다음 뒤에서부터 0 지움
    while (zero) {
        for(int i=str.length(); 0 <= i; i--) {
            if(str[i] == '0') {
                str = str.substr(0, i) + str.substr(i+1);
                zero--;
                break;
            }
        }
    }

    cout << str;

    return 0;
}