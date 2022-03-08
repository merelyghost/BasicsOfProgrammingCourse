#ifndef COURSE_ISSTRINGHASEQUALWORDS_H
#define COURSE_ISSTRINGHASEQUALWORDS_H

#include "../string_.h"

bool isStringHasEqualWords(char *s) {
    getBagOfWords(&_bag, s);

    WordDescriptor *wordBegin = _bag.words;
    WordDescriptor *wordEnd = _bag.words + _bag.size - 1;

    while (wordBegin < wordEnd) {
        WordDescriptor *w = wordBegin + 1;
        while (w <= wordEnd) {
            if (areWordsEqual(*wordBegin, *w) == 0)
                return true;
            w++;
        }
        wordBegin++;
    }
    return false;
}


void test_isStringHasEqualWords1() {
    char s[MAX_STRING_SIZE] = "ab ji ab j";
    assert(isStringHasEqualWords(s));
}

void test_isStringHasEqualWords2() {
    char s[MAX_STRING_SIZE] = "ab ji kk";
    assert(!isStringHasEqualWords(s));
}

void test_isStringHasEqualWords_empty() {
    char s[MAX_STRING_SIZE] = "";
    assert(!isStringHasEqualWords(s));
}

void test_isStringHasEqualWords() {
    test_isStringHasEqualWords1();
    test_isStringHasEqualWords2();
    test_isStringHasEqualWords_empty();
    fprintf(stderr, "test_isStringHasEqualWords - OK\n");
}

#endif
