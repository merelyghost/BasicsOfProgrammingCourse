#ifndef COURSE_REMOVEADJACENTEQUALLETTERS_H
#define COURSE_REMOVEADJACENTEQUALLETTERS_H

#include "../string_.h"


void removeAdjacentEqualLetters(char *s) {
    char *endSource = getEndOfString(s);
    char *destination = copyIfC(s, endSource, s, nextIsNotEqual);
    *destination = '\0';
}

void test_removeAdjacentEqualLetters_recurringSymbols() {
    char s[] = "qqqqweertyyyyyy   55";
    removeAdjacentEqualLetters(s);
    ASSERT_STRING("qwerty 5", s);
}

void test_removeAdjacentEqualLetters_emptyString() {
    char s[] = "";
    removeAdjacentEqualLetters(s);
    ASSERT_STRING("", s);
}

void test_removeAdjacentEqualLetters_recurringSymbols2() {
    char s[] = "hhhhii  \n\n wwwworrlddd";
    removeAdjacentEqualLetters(s);
    ASSERT_STRING("hi \n world", s);
}

void test_removeAdjacentEqualLetters_uniqueSymbols() {
    char s[] = "red car";
    removeAdjacentEqualLetters(s);
    ASSERT_STRING("red car", s);
}

void test_removeAdjacentEqualLetters() {
    test_removeAdjacentEqualLetters_recurringSymbols();
    test_removeAdjacentEqualLetters_emptyString();
    test_removeAdjacentEqualLetters_recurringSymbols2();
    test_removeAdjacentEqualLetters_uniqueSymbols();
}

#endif
