#ifndef COURSE_GETSTRINGWITHWORDSOTHERTHANLAST_H
#define COURSE_GETSTRINGWITHWORDSOTHERTHANLAST_H

#include "../string_.h"

// Получить строку из слов данной строки, которые отличны от последнего слова

void getStringWithWordsOtherThanLast(char *s) {
    char *endBuffer = copy(s, getEndOfString(s), _stringBuffer);
    *endBuffer= '\0';

    WordDescriptor lastWord;
    if (!getLastWord(endBuffer - 1, _stringBuffer - 1, &lastWord))
        return;

    WordDescriptor word;
    char *readStr = _stringBuffer;
    char *wrightStr = s;
    while (getWord(readStr, &word)) {
        if (areWordsEqual(word, lastWord)) {
            wrightStr = copy(word.begin, word.end, wrightStr);
            *wrightStr = ' ';
            wrightStr++;
        }
        readStr = word.end;
    }

    if (wrightStr != s)
        wrightStr--;
    *wrightStr = '\0';

}

void test_getStringWithWordsOtherThanLast1() {
    char s[] = "heh jk ant th rm ant";
    getStringWithWordsOtherThanLast(s);

    ASSERT_STRING("heh jk th rm", s);
}

void test_getStringWithWordsOtherThanLast2() {
    char s[] = "ant ant  ant ";
    getStringWithWordsOtherThanLast(s);

    ASSERT_STRING("", s);
}

void test_getStringWithWordsOtherThanLast_empty() {
    char s[] = "";
    getStringWithWordsOtherThanLast(s);

    ASSERT_STRING("", s);
}


void test_getStringWithWordsOtherThanLast() {
    test_getStringWithWordsOtherThanLast1();
    test_getStringWithWordsOtherThanLast2();
    test_getStringWithWordsOtherThanLast_empty();
}

#endif
