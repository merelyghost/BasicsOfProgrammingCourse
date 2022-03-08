#ifndef COURSE_DELETEPALINDROMES_H
#define COURSE_DELETEPALINDROMES_H

#include "../string_.h"

void deletePalindromes(char *s) {
    char *endBuffer = copy(s, getEndOfString(s), _stringBuffer);
    *endBuffer= '\0';

    if (*s == '\0')
        return ;

    WordDescriptor word;
    char *readStr = _stringBuffer;
    char *wrightStr = s;
    while (getWord(readStr, &word)) {
        if (!isPalindrome(word)) {
            wrightStr = copy(word.begin, word.end, wrightStr);
            *wrightStr = ' ';
            wrightStr++;
        }
        readStr = word.end;
    }

    if (wrightStr != s)
        wrightStr--;
    *wrightStr = '\0';
}

void test_deletePalindromes1() {
    char s[] = "heh jk noon th rm ant ";
    deletePalindromes(s);

    ASSERT_STRING("jk th rm ant", s);
}

void test_deletePalindromes2() {
    char s[] = "jk noonn th rm ant";
    deletePalindromes(s);

    ASSERT_STRING("jk noonn th rm ant", s);
}

void test_deletePalindromes_empty() {
    char s[] = "";
    deletePalindromes(s);

    ASSERT_STRING("", s);
}

void test_deletePalindromes3() {
    char s[] = "jkj noon  tht rmr a";
    deletePalindromes(s);

    ASSERT_STRING("", s);
}

void test_deletePalindromes() {
    test_deletePalindromes1();
    test_deletePalindromes2();
    test_deletePalindromes3();
    test_deletePalindromes_empty();
}

#endif
