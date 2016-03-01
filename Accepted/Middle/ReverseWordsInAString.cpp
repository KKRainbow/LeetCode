//
// Created by sunsijie on 16-3-1.
//

#include <string.h>
void reverse(char* l, char* r)
{
    while (r > l) {
        char tmp = *r;
        *r = *l;
        *l = tmp;
        l++;
        r--;
    }
}

void reverseWords(char *s) {
    //先把字符串整个翻转，然后分别翻转每一个词
    size_t len = strlen(s);
    if (!len) {
        return;
    }

    char* l = s, *r = s + len - 1;
    reverse(l, r);

    l = s;
    while (*l == ' ') l++;
    r = l;
    char* rightPlace = s; //用于剔除多余空格，把单词移动到正确的位置

    if (!*l) {
        *s = '\0';
        return;
    }

    while (*l) {
        while (*r != ' ' && *r) {
            r++;
        }

        reverse(l, r - 1);
        memmove(rightPlace, l, r - l);
        rightPlace += r - l;

        while(*r == ' ') {
            r++;
        };
        if (*r) {
            *rightPlace = ' ';
            rightPlace++;
        } else {
            *rightPlace = '\0';
        }

        l = r;
    }
}

int main(int argc, char* argv[], char* env[])
{
    char s[] = "a";
    reverseWords(s);
}