#ifndef COURSE_PRINTWORDBEFOREFIRSTWORDWITHA_H
#define COURSE_PRINTWORDBEFOREFIRSTWORDWITHA_H

#include "../string_.h"

bool isWordWithA(WordDescriptor word) {
    while (word.begin != word.end) {
        if (*word.begin == 'A' || *word.begin == 'a')
            return true;
        word.begin++;
    }

    return false;
}

WordBeforeFirstWordWithAReturnCode getWordBeforeFirstWordWithA(char *s,
                                                               char **beginWordBefore,
                                                               char **endWordBefore) {
    WordDescriptor preWord;

    if (!getWord(s, &preWord))
        return EMPTY_STRING;

    if (isWordWithA(preWord))
        return FIRST_WORD_WITH_A;

    WordDescriptor curWord;
    char *readStr = preWord.end;
    while (getWord(readStr, &curWord)) {
        if (isWordWithA(curWord)) {
            *beginWordBefore = preWord.begin;
            *endWordBefore = preWord.end;
            return WORD_FOUND;
        }
        preWord = curWord;
        readStr = preWord.end;
    }
    return NOT_FOUND_A_WORD_WITH_A;
}

void printWordBeforeFirstWordWithA(char *s) {
    WordDescriptor word;

    if (getWordBeforeFirstWordWithA(s, &word.begin, &word.end) == WORD_FOUND) {
        *word.end = '\0';
        printf("%s\n", word.begin);
    }
}

// test_printWordBeforeFirstWordWithA:
// char s[MAX_STRING_SIZE] = "GG POOR ALICE LAP";
// printWordBeforeFirstWordWithA(s);  =>  "POOR"

void test_getWordBeforeFirstWordWithA() {
    char *beginWord, *endWord;

    char s1[] = "";
    assert(getWordBeforeFirstWordWithA(s1, &beginWord, &endWord) == EMPTY_STRING);
    fprintf(stderr, "getWordBeforeFirstWordWithA_EMPTY_STRING - OK\n");

    char s2[] = " ABC";
    assert(getWordBeforeFirstWordWithA(s2, &beginWord, &endWord) == FIRST_WORD_WITH_A);
    fprintf(stderr, "getWordBeforeFirstWordWithA_FIRST_WORD_WITH_A - OK\n");

    char s3[] = "BC A";
    assert(getWordBeforeFirstWordWithA(s3, &beginWord, &endWord) == WORD_FOUND);
    fprintf(stderr, "getWordBeforeFirstWordWithA_WORD_FOUND - OK\n");
    char got[MAX_WORD_SIZE];
    copy(beginWord, endWord, got);
    got[endWord - beginWord] = '\0';
    ASSERT_STRING("BC", got);

    char s4[] = "B Q WE YR OW IUWR ";
    assert(getWordBeforeFirstWordWithA(s4, &beginWord, &endWord) == NOT_FOUND_A_WORD_WITH_A);
    fprintf(stderr, "getWordBeforeFirstWordWithA_NOT_FOUND_A_WORD_WITH_A - OK\n");
}


#endif
