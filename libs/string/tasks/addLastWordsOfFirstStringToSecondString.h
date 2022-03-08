#ifndef COURSE_ADDLASTWORDSOFFIRSTSTRINGTOSECONDSTRING_H
#define COURSE_ADDLASTWORDSOFFIRSTSTRINGTOSECONDSTRING_H

#include "../string_.h"

// Даны две строки. Пусть n1 – число слов в первой строке, а n2 – во второй.
// Требуется дополнить строку, содержащую меньшее количество слов, последними
// словами строки, в которой содержится большее количество слов.
void addLastWordsOfFirstStringToSecondString_(char *s, char *sLess, int n, int nLess) {
    int dif = n - nLess;

    if (*sLess == '\0') {
        *copy(s, getEndOfString(s), sLess) = '\0';
        return;
    }

    WordDescriptor word;
    char *readStr = getEndOfString(s);
    while (dif) {
        dif -= getLastWord(readStr - 1, s - 1, &word);

        readStr = word.begin;
    }

    char *wrightS = getEndOfString(sLess);

    *wrightS++ = ' ';
    *copy(word.begin, getEndOfString(s), wrightS) = '\0';
}


void addLastWordsOfFirstStringToSecondString(char *s1, char *s2, int n1, int n2) {
    if (n1 == n2)
        return;

    if (n2 - n1 > 0)
        addLastWordsOfFirstStringToSecondString_(s2, s1, n2, n1);
    else
        addLastWordsOfFirstStringToSecondString_(s1, s2, n1, n2);
}

void test_addLastWordsOfFirstStringToSecondString1() {
    char s1[MAX_STRING_SIZE] = "a b";
    char s2[MAX_STRING_SIZE] = "a b c ";
    int n1 = 2;
    int n2 = 3;
    addLastWordsOfFirstStringToSecondString(s1, s2, n1, n2);

    ASSERT_STRING("a b c ", s1);
}

void test_addLastWordsOfFirstStringToSecondString2() {
    char s1[MAX_STRING_SIZE] = "ak buu noon jk";
    char s2[MAX_STRING_SIZE] = "self st";
    int n1 = 4;
    int n2 = 2;
    addLastWordsOfFirstStringToSecondString(s1, s2, n1, n2);

    ASSERT_STRING("self st noon jk", s2);
}

void test_addLastWordsOfFirstStringToSecondString3() {
    char s1[MAX_STRING_SIZE] = "";
    char s2[MAX_STRING_SIZE] = "self st";
    int n1 = 0;
    int n2 = 2;
    addLastWordsOfFirstStringToSecondString(s1, s2, n1, n2);

    ASSERT_STRING("self st", s1);
}

void test_addLastWordsOfFirstStringToSecondString4() {
    char s1[MAX_STRING_SIZE] = "";
    char s2[MAX_STRING_SIZE] = "";
    int n1 = 0;
    int n2 = 0;
    addLastWordsOfFirstStringToSecondString(s1, s2, n1, n2);

    ASSERT_STRING("", s1);
}

void test_addLastWordsOfFirstStringToSecondString() {
    test_addLastWordsOfFirstStringToSecondString1();
    test_addLastWordsOfFirstStringToSecondString2();
    test_addLastWordsOfFirstStringToSecondString3();
    test_addLastWordsOfFirstStringToSecondString4();
}

#endif
