#ifndef COURSE_LASTWORDINFIRSTSTRINGINSECONDSTRING_H
#define COURSE_LASTWORDINFIRSTSTRINGINSECONDSTRING_H

#include "../string_.h"


// Даны две строки. Определить последнее из слов первой строки, которое есть во второй строке.

WordDescriptor lastWordInFirstStringInSecondString(char *s1, char *s2) {
    getBagOfWords(&_bag, s1);
    getBagOfWords(&_bag2, s2);
    WordDescriptor word = {NULL, NULL};

    WordDescriptor *readBagR = _bag.words + _bag.size - 1;
    WordDescriptor *readBag2 = _bag2.words;
    while (readBagR >= _bag.words) {
        WordDescriptor *w = readBag2;
        while (w < _bag2.words + _bag2.size) {
            if (areWordsEqual(*readBagR, *w) == 0)
                return *readBagR;
            w++;
        }
        readBagR--;
    }
    return word;
}

void test_lastWordInFirstStringInSecondString1() {
    char s1[] = "abc def gg h2 h1 ";
    char s2[] = "abc fhfh j gg def";
    WordDescriptor word = lastWordInFirstStringInSecondString(s1, s2);

    char res[MAX_STRING_SIZE];
    wordDescriptorToString(word, res);
    ASSERT_STRING ("gg", res);
}

void test_lastWordInFirstStringInSecondString2() {
    char s1[] = "abc def gg h1 h2";
    char s2[] = "ui jk th ";
    WordDescriptor word = lastWordInFirstStringInSecondString(s1, s2);

    char res[MAX_STRING_SIZE];
    wordDescriptorToString(word, res);
    ASSERT_STRING ("", res);
}

void test_lastWordInFirstStringInSecondString_empty() {
    char s1[] = "";
    char s2[] = "";
    WordDescriptor word = lastWordInFirstStringInSecondString(s1, s2);

    char res[MAX_STRING_SIZE];
    wordDescriptorToString(word, res);
    ASSERT_STRING ("", res);
}

void test_lastWordInFirstStringInSecondString() {
    test_lastWordInFirstStringInSecondString1();
    test_lastWordInFirstStringInSecondString2();
    test_lastWordInFirstStringInSecondString_empty();
}

#endif
