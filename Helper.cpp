using namespace std;
#include "Helper.h"
#include <vector>

vector<int> decimalToBinary(int num) {
    vector<int> binaryNum(8, 0);

    int i = 7;
    while (num > 0 && i >= 0) {
        binaryNum[i] = num % 2;
        num = num / 2;
        i--;
    }

    return binaryNum;
}

int binaryToDecimal(int n)
{
    int num =n;
    int dec_value = 0;

    int base =1;

    int temp=num;
    while (temp) {
        int last_digit = temp % 10;
        temp = temp / 10;

        dec_value += last_digit * base;

        base = base * 2;
    }

    return dec_value;
}