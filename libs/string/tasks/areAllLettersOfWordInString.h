#ifndef COURSE_AREALLLETTERSOFWORDINSTRING_H
#define COURSE_AREALLLETTERSOFWORDINSTRING_H

#include "../string_.h"

//Определить, входит ли в данную строку каждая буква данного слова.
//Указание: алгоритм должен иметь линейную сложность

bool areAllLettersOfWordInString(char *s, char *word) {
    if (*word == '\0' || *s == '\0')
        return false;

    bool areLettersOfWordInS[255];
    for (int i = 0; i < 255; i++)
        areLettersOfWordInS[i] = false;

    while (*s != '\0') {
        if (isalpha(*s) && !areLettersOfWordInS[*s])
            areLettersOfWordInS[*s] = true;
        s++;
    }

    while (*word != '\0') {
        if (!areLettersOfWordInS[*word])
            return false;
        word++;
    }

    return true;
}

void test_areAllLettersOfWordInString1() {
    char s[MAX_STRING_SIZE] = "hoho heh lol ooo";
    char *word = "hello";

    assert(areAllLettersOfWordInString(s, word));
}

void test_areAllLettersOfWordInString2() {
    char s[MAX_STRING_SIZE] = "  hoho haeh lol oo jk o";
    char *word = "hello";

    assert(areAllLettersOfWordInString(s, word));
}

void test_areAllLettersOfWordInString3() {
    char s[MAX_STRING_SIZE] = "hoho hh lol ooo ";
    char *word = "hello";

    assert(!areAllLettersOfWordInString(s, word));
}

void test_areAllLettersOfWordInString_empty() {
    char s[MAX_STRING_SIZE] = "";
    char *word = "hello";

    assert(!areAllLettersOfWordInString(s, word));
}

void test_areAllLettersOfWordInString4() {
    char s[MAX_STRING_SIZE] = "hoho heh lol ooo";
    char *word = "";

    assert(!areAllLettersOfWordInString(s, word));
}

void test_areAllLettersOfWordInString() {
    test_areAllLettersOfWordInString1();
    test_areAllLettersOfWordInString2();
    test_areAllLettersOfWordInString3();
    test_areAllLettersOfWordInString4();
    test_areAllLettersOfWordInString_empty();
    fprintf(stderr, "test_areAllLettersOfWordInString - OK\n");
}


#endif
