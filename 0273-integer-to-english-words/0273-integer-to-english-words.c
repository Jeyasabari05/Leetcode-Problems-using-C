#include <stdlib.h>
#include <string.h>
char* one[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
char* teen[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
char* ten[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
char* thousand[] = {"", "Thousand", "Million", "Billion"};
void help(int num, char* result) {
    if (num == 0) return;
    else if (num < 10) strcat(result, one[num]);
    else if (num < 20) strcat(result, teen[num - 10]);
    else if (num < 100) {
        strcat(result, ten[num / 10]);
        if (num % 10) {
            strcat(result, " ");
            strcat(result, one[num % 10]);
        }
    } else if (num < 1000) {
        strcat(result, one[num / 100]);
        strcat(result, " Hundred");
        if (num % 100) {
            strcat(result, " ");
            help(num % 100, result);
        }
    }
}
char* numberToWords(int num) {
    if (num == 0) return "Zero";
    
    char* result = (char*)malloc(1024);
    memset(result, 0, 1024);
    int thousand_counter = 0;
    while (num > 0) {
        if (num % 1000 != 0) {
            char temp[256] = {0};
            help(num % 1000, temp);
            if (thousand_counter > 0 && strlen(temp) > 0) {
                strcat(temp, " ");
                strcat(temp, thousand[thousand_counter]);
            }
            if (strlen(result) > 0) {
                strcat(temp, " ");
                strcat(temp, result);
            }
            strcpy(result, temp);
        }
        num /= 1000;
        thousand_counter++;
    }

    return result;
}