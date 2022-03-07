#ifndef COURSE_DIGITSTOSTARTINEVERYWORDOFSTRING_H
#define COURSE_DIGITSTOSTARTINEVERYWORDOFSTRING_H

#include "../string_.h"

//Преобразовать строку таким образом, чтобы цифры каждого слова были
//перенесены в начало слова без изменения порядка следования их в слове,
//буквы перенести в конец слова


void digitsToStartInEveryWordOfString(char * s) {
    char *beginSearch = s;

    WordDescriptor word;
    while (getWord(beginSearch, &word)) {
        digitsToStart(word);

        beginSearch = word.end;
    }
}

void test_digitsToStartInEveryWordOfString1() {
    char s[] = "5abc";
    digitsToStartInEveryWordOfString(s);
    ASSERT_STRING("5abc", s);
}

void test_digitsToStartInEveryWordOfString2() {
    char s[] = "  fg1dc2t3  \t  \n 52ebf8fv22a  12 ";
    digitsToStartInEveryWordOfString(s);
    ASSERT_STRING("  123fgdct  \t  \n 52822ebffva  12 ", s);
}

void test_digitsToStartInEveryWordOfString_onlySpaces() {
    char s[] = "  \n\t  ";
    digitsToStartInEveryWordOfString(s);
    ASSERT_STRING("  \n\t  ", s);
}

void test_digitsToStartInEveryWordOfString_emptyString() {
    char s[] = "";
    digitsToStartInEveryWordOfString(s);
    ASSERT_STRING("", s);
}

void test_digitsToStartInEveryWordOfString_onlyLetters() {
    char s[] = "Sdf  hObg  dSvff";
    digitsToStartInEveryWordOfString(s);
    ASSERT_STRING("Sdf  hObg  dSvff", s);
}

void test_digitsToStartInEveryWordOfString_onlyDigits() {
    char s[] = "455 125 \t  01";
    digitsToStartInEveryWordOfString(s);
    ASSERT_STRING("455 125 \t  01", s);
}

void test_digitsToStartInEveryWordOfString() {
    test_digitsToStartInEveryWordOfString1();
    test_digitsToStartInEveryWordOfString2();
    test_digitsToStartInEveryWordOfString_onlySpaces();
    test_digitsToStartInEveryWordOfString_emptyString();
    test_digitsToStartInEveryWordOfString_onlyLetters();
    test_digitsToStartInEveryWordOfString_onlyDigits();

}

#endif
