#ifndef COURSE_REPLACE_H
#define COURSE_REPLACE_H

#include "../string_.h"

// Заменить все вхождения слова w1 на слово w2

char *wordInString(char *source, char *word) {
    while (*source != '\0') {
        if (*source == *word) {
            char *compS = source;
            char *compW = word;

            int isEqual = 1;
            while (*compW != '\0' && isEqual)
                isEqual = *compW++ == *compS++;

            if (isEqual)
                return source; // начало слова
        }
        source++;
    }
    return source;
}

void replace(char *source, char *w1, char *w2) {
    size_t w1Size = strlen_(w1);
    size_t w2Size = strlen_(w2);

    char *readPtr, *recPtr;
    if (w1Size >= w2Size) {
        readPtr = source;
        recPtr = source;
    } else {
        char *end = copy(source, getEndOfString(source), _stringBuffer);
        *end = '\0';
        readPtr = _stringBuffer;
        recPtr = source;
    }

    while (*readPtr != '\0') {
        char *beginWord = wordInString(readPtr, w1);
        recPtr = copy(readPtr, beginWord, recPtr); //записали все, до начала слова w1

        if (*beginWord == '\0') {
            *recPtr = '\0';
            return;
        }

        memcpy(recPtr, w2, w2Size); //записали слово w2
        recPtr += w2Size;

        readPtr = beginWord + w1Size;
    }
    *recPtr = '\0';
}


void test_replace1() {
    char s[20] = "abbc bab ab";
    char w1[] = "ab";
    char w2[] = "xxx";
    replace(s, w1, w2);
    ASSERT_STRING("xxxbc bxxx xxx", s);
}

void test_replace2() {
    char s[20] = "abbc bab ab";
    char w1[] = "ab";
    char w2[] = "x";
    replace(s, w1, w2);
    ASSERT_STRING("xbc bx x", s);
}

void test_replace_emptyString() {
    char s[20] = "";
    char w1[] = "ab";
    char w2[] = "xxx";
    replace(s, w1, w2);
    ASSERT_STRING("", s);
}

void test_replace_onlyW1() {
    char s[20] = "ababab";
    char w1[] = "ab";
    char w2[] = "xxx";
    replace(s, w1, w2);
    ASSERT_STRING("xxxxxxxxx", s);
}

void test_replace_noW1() {
    char s[20] = "lolo lo ";
    char w1[] = "ab";
    char w2[] = "xxx";
    replace(s, w1, w2);
    ASSERT_STRING("lolo lo ", s);
}


void test_replace() {
    test_replace1();
    test_replace2();
    test_replace_emptyString();
    test_replace_noW1();
    test_replace_onlyW1();
}

#endif
