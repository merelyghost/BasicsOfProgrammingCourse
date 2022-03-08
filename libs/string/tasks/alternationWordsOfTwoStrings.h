#ifndef COURSE_ALTERNATIONWORDSOFTWOSTRINGS_H
#define COURSE_ALTERNATIONWORDSOFTWOSTRINGS_H

#include "../string_.h"

// Даны две строки. Получить строку, в которой чередуются слова первой и второй строки.
// Если в одной из строк число слов больше, чем в другой, то оставшиеся слова этой строки
// должны быть дописаны в строку-результат.
// В качестве разделителя между словами используйте пробел.

void alternationWordsOfTwoStrings(char *s, char *s1, char *s2) {
    WordDescriptor word1, word2;
    bool isW1Found, isW2Found;
    char *beginSearch1 = s1, *beginSearch2 = s2;
    char *sRes = s;
    while ((isW1Found = getWord(beginSearch1, &word1)), (isW2Found = getWord(beginSearch2, &word2)),
            isW1Found || isW2Found) {
        if (isW1Found) {
            sRes = copy(word1.begin, word1.end, sRes);
            *sRes++ = ' ';
            beginSearch1 = word1.end;
        }

        if (isW2Found) {
            sRes = copy(word2.begin, word2.end, sRes);
            *sRes++ = ' ';
            beginSearch2 = word2.end;
        }
    }

    if (sRes != s)
        sRes--;

    *sRes = '\0';
}

void test_alternationWordsOfTwoStrings1() {
    char s[MAX_STRING_SIZE];
    char s1[] = "a c e g ";
    char s2[] = "b d f";
    alternationWordsOfTwoStrings(s, s1, s2);
    ASSERT_STRING("a b c d e f g", s);
}

void test_alternationWordsOfTwoStrings2() {
    char s[MAX_STRING_SIZE];
    char s1[] = "b b b  ";
    char s2[] = "  o o \t o o o";
    alternationWordsOfTwoStrings(s, s1, s2);
    ASSERT_STRING("b o b o b o o o", s);
}

void test_alternationWordsOfTwoStrings_emptyString() {
    char s[MAX_STRING_SIZE];
    char s1[] = "";
    char s2[] = "  ";
    alternationWordsOfTwoStrings(s, s1, s2);
    ASSERT_STRING("", s);
}

void test_alternationWordsOfTwoStrings() {
    test_alternationWordsOfTwoStrings1();
    test_alternationWordsOfTwoStrings2();
    test_alternationWordsOfTwoStrings_emptyString();
}

#endif
