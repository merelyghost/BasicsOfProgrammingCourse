#ifndef COURSE_LASTWORDINFIRSTSTRINGINSECONDSTRING_H
#define COURSE_LASTWORDINFIRSTSTRINGINSECONDSTRING_H

#include "../string_.h"




// Даны две строки. Определить последнее из слов первой строки, которое есть во второй строке.

WordDescriptor lastWordInFirstStringInSecondString(char *s1, char *s2) {
    getBagOfWords(&_bag, s1);
    getBagOfWords(&_bag2, s2);
    WordDescriptor word = {NULL, NULL};

    for (int i = (int)_bag.size - 1; i >= 0; i--) {
        for (int j = 0; j < _bag2.size; j++) {
            if (areWordsEqual(_bag.words[i], _bag2.words[j]) == 0)
                return _bag.words[i];
        }
    }
    return word;
}

void test_lastWordInFirstStringInSecondString1() {
    char s1[] = "abc def gg h1 h2";
    char s2[] = "abc fhfh gg def";
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
