#ifndef COURSE_COUNTOFPALINDROMES_H
#define COURSE_COUNTOFPALINDROMES_H

#include "../string_.h"

int getWord_(char *beginSearch, WordDescriptor *word) {
    while (*beginSearch == ',' || isspace(*beginSearch)) {
        beginSearch++;
    }
    if (*beginSearch == '\0')
        return 0;

    word->begin = beginSearch;
    while (*beginSearch != ',' && *beginSearch != '\0') {
        beginSearch++;
    }
    word->end = beginSearch;
    return 1;
}

bool isPalindrome(WordDescriptor word) {
    while ((word.end - word.begin) > 0) {
        if (*word.begin != *(word.end - 1))
            return 0;
        word.end--, word.begin++;
    }
    return 1;
}

int countOfPalindromes(char *s) {
    char *readStr = s;
    WordDescriptor word;
    int countPalindromes = 0;
    while (getWord_(readStr, &word)) {
        countPalindromes += isPalindrome(word);
        readStr = word.end;
    }
    return countPalindromes;
}

void test_countOfPalindromes_emptyString() {
    char s[] = "";
    assert(countOfPalindromes(s) == 0);
    fprintf(stderr, "countOfPalindromes_emptyString - OK\n") ;
}

void test_countOfPalindromes_noPalindromes() {
    char s[] = "hello, omom\n";
    assert(countOfPalindromes(s) == 0);
    fprintf(stderr, "countOfPalindromes_noPalindromes - OK\n") ;
}

void test_countOfPalindromes1() {
    char s[] = "heh";
    assert(countOfPalindromes(s) == 1);
    fprintf(stderr, "countOfPalindromes1 - OK\n") ;
}

void test_countOfPalindromes2() {
    char s[] = "heh,hohoohoh";
    assert(countOfPalindromes(s) == 2);
    fprintf(stderr, "countOfPalindromes2 - OK\n") ;
}

void test_countOfPalindromes3() {
    char s[] = "heh,  hohoohoh, \tpod121dop";
    assert(countOfPalindromes(s) == 3);
    fprintf(stderr, "countOfPalindromes3 - OK\n") ;
}

void test_countOfPalindromes() {
    test_countOfPalindromes1();
    test_countOfPalindromes2();
    test_countOfPalindromes3();
    test_countOfPalindromes_emptyString();
    test_countOfPalindromes_noPalindromes();
}

#endif
