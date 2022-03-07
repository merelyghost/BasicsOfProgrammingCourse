#ifndef COURSE_ISORDEREDWORDS_H
#define COURSE_ISORDEREDWORDS_H

#include "../string_.h"

// Определить, упорядочены ли лексикографически слова данного предложения

bool isOrderedWords(char *s) {
    WordDescriptor previousWord;
    if (!getWord(s, &previousWord))
        return true;

    WordDescriptor currentWord;
    char *beginSearch = previousWord.end;

    while (getWord(beginSearch, &currentWord)){
        if (areWordsEqual(currentWord, previousWord) < 0)
            return false;

        previousWord = currentWord;
        beginSearch = previousWord.end;
    }
    return true;

}

void test_isOrderedWords1() {
    char s[] = "a b c c d e";
    assert(isOrderedWords(s));
}

void test_isOrderedWords2() {
    char s[] = "a b c a b e";
    assert(!isOrderedWords(s));
}

void test_isOrderedWords3() {
    char s[] = "a15 b b23 helpa helpb v85 v850";
    assert(isOrderedWords(s));
}

void test_isOrderedWords4() {
    char s[] = "kkk abc a12 aa t";
    assert(!isOrderedWords(s));
}

void test_isOrderedWords5() {
    char s[] = "";
    assert(isOrderedWords(s));
}

void test_isOrderedWords() {
    test_isOrderedWords1();
    test_isOrderedWords2();
    test_isOrderedWords3();
    test_isOrderedWords4();
    test_isOrderedWords5();
}

#endif
