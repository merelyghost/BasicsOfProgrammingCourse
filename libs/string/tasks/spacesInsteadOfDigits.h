#ifndef COURSE_SPACESINSTEADOFDIGITS_H
#define COURSE_SPACESINSTEADOFDIGITS_H

#include "../string_.h"

#define CODE_DIFFERENCE 48

// Преобразовать строку, заменяя каждую цифру соответствующим ей числом пробелов

void spacesInsteadOfDigits(char * s) {
    char *endString = getEndOfString(s);
    char *endStringBuffer = copy(s, endString, _stringBuffer);
    *endStringBuffer = '\0';

    char *readStr = _stringBuffer;
    while (*readStr != '\0') {
        if (isdigit(*readStr)) {
            int k = *readStr - CODE_DIFFERENCE;
            while (k--)
                *s++ = ' ';
        } else
            *s++ = *readStr;
        readStr++;
    }
    *s = '\0';
}

void test_spacesInsteadOfDigits1() {
    char s[] = "5a 2bc";
    spacesInsteadOfDigits(s);
    ASSERT_STRING("     a   bc", s);
}

void test_spacesInsteadOfDigits2() {
    char s[] = " 1f2\t g3g ";
    spacesInsteadOfDigits(s);
    ASSERT_STRING("  f  \t g   g ", s);
}

void test_spacesInsteadOfDigits_emptyString() {
    char s[] = "";
    spacesInsteadOfDigits(s);
    ASSERT_STRING("", s);
}

void test_spacesInsteadOfDigits_onlyDigits() {
    char s[] = "2 4";
    spacesInsteadOfDigits(s);
    ASSERT_STRING("       ", s);
}

void test_spacesInsteadOfDigits() {
    test_spacesInsteadOfDigits1();
    test_spacesInsteadOfDigits2();
    test_spacesInsteadOfDigits_emptyString();
    test_spacesInsteadOfDigits_onlyDigits();

}

#endif
