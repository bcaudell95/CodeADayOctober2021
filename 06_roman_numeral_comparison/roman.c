#include <stdio.h>
#include <string.h>
int romanCharToInt(char roman) {
    switch (roman) {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
    }
    printf("error: %c\n", roman);
    return -1;
}

int romanToInt(char *roman) {
    int output = 0;
    int val;
    for(int i = 0; i < strlen(roman); i++) {
        if ((val = romanCharToInt(roman[i])) == -1) {
            return -1;
        }
        output += val;
    }
    return output;
}

int romanLessThan(char *left, char *right) {
    int leftVal;
    int rightVal;
    for (int i=0;; i++) {
        if (i < strlen(left) && i >= strlen(right)) {
            return 0;
        } else if (i >= strlen(left) && i < strlen(right)) {
            return 1;
        } else if (i == strlen(left) && i == strlen(right)) {
            return 0;
        } else {
            if ((leftVal = romanCharToInt(left[i])) == -1) {
                return -1;
            }
            if ((rightVal = romanCharToInt(right[i])) == -1) {
                return -1;
            }
            if (leftVal < rightVal) {
                return 1;
            } else if (leftVal > rightVal) {
                return 0;
            }
        }
    }
    return 0;
}

int main(int argc, char *argv[]) {
    if(argc != 3) {
        printf("Usage: ./outDebug.exe <roman numeral> <roman numeral>");
        return 1;
    }

    int result = romanLessThan(argv[1], argv[2]);
    switch(result) {
        case 1:
            printf("true");
            break;
        case 0:
            printf("false");
            break;
        default:
            printf("error!");
    }
    return 0;
}