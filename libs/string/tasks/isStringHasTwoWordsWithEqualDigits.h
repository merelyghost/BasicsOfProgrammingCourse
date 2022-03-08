#ifndef COURSE_ISSTRINGHASTWOWORDSWITHEQUALDIGITS_H
#define COURSE_ISSTRINGHASTWOWORDSWITHEQUALDIGITS_H

#include "../string_.h"

//Определить, есть ли в данной строке пара слов, составленных из одинаковых букв

int cmp(const void *a, const void *b) {
    return *(const char *) a - *(const char *) b;
}

bool isStringHasTwoWordsWithEqualDigits(char *s) {
    *copy(s, getEndOfString(s), _stringBuffer) = '\0';

    WordDescriptor word;
    char *readStr = _stringBuffer;
    while (getWord(readStr, &word)) {
        qsort(word.begin, word.end - word.begin, sizeof(char), cmp);
        readStr = word.end;
    }

    return isStringHasEqualWords(_stringBuffer);
}

void test_isStringHasTwoWordsWithEqualDigits1() {
    char s[MAX_STRING_SIZE] = "fg jikm ik gff mkji l";
    assert(isStringHasTwoWordsWithEqualDigits(s));
}

void test_isStringHasTwoWordsWithEqualDigits2() {
    char s[MAX_STRING_SIZE] = "fg jikm ik gff mkkji l";
    assert(!isStringHasTwoWordsWithEqualDigits(s));
}

void test_isStringHasTwoWordsWithEqualDigits_empty() {
    char s[MAX_STRING_SIZE] = "";
    assert(!isStringHasTwoWordsWithEqualDigits(s));
}

void test_isStringHasTwoWordsWithEqualDigits() {
    test_isStringHasTwoWordsWithEqualDigits1();
    test_isStringHasTwoWordsWithEqualDigits2();
    test_isStringHasTwoWordsWithEqualDigits_empty();
    fprintf(stderr, "test_isStringHasTwoWordsWithEqualDigits - OK\n");
}

#endif
