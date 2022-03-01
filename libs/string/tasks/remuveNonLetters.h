#ifndef COURSE_REMUVENONLETTERS_H
#define COURSE_REMUVENONLETTERS_H

#include "../string_.h"

void removeNonLetters(char *s) {
    char *endSource = getEndOfString(s);
    char *destination = copyIf(s, endSource, s, isgraph);
    *destination = '\0';
}

void test_removeNonLetters_noSpaces() {
    char s[] = "hello77";
    removeNonLetters(s);
    ASSERT_STRING("hello77", s);
}

void test_removeNonLetters_spaces() {
    char s[] = "he ll o \n77  ";
    removeNonLetters(s);
    ASSERT_STRING("hello77", s);
}

void test_removeNonLetters_emptyString() {
    char s[] = "";
    removeNonLetters(s);
    ASSERT_STRING("", s);
}

void test_removeNonLetters_spacesSymbols() {
    char s[] = "\n  \t\n";
    removeNonLetters(s);
    ASSERT_STRING("", s);
}

void test_removeNonLetters() {
    test_removeNonLetters_emptyString();
    test_removeNonLetters_noSpaces();
    test_removeNonLetters_spaces();
    test_removeNonLetters_spacesSymbols();
}

#endif
