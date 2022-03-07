#ifndef COURSE_REVERSEWORDS_H
#define COURSE_REVERSEWORDS_H

#include "../string_.h"


void reverseWords(char *s) {
    char *end = copy(s, getEndOfString(s), _stringBuffer);
    *end = '\0';

    BagOfWords bag;
    getBagOfWords(&bag, _stringBuffer);

    char *wEnd = s;
    bool isChanged = false;
    for (int i = (int)bag.size - 1; i >= 0; i--) {
        isChanged = true;
        wEnd = copy(bag.words[i].begin, bag.words[i].end, wEnd);
        *wEnd++ = ' ';
    }
    if (isChanged)
        wEnd--;

    *wEnd = '\0';

}

void test_reverseWords1() {
    char s[] = "a b c";
    reverseWords(s);
    ASSERT_STRING("c b a", s);
}

void test_reverseWords2() {
    char s[] = "!! jam  with bread";
    reverseWords(s);
    ASSERT_STRING("bread with jam !!", s);
}

void test_reverseWords_emptyString() {
    char s[] = "";
    reverseWords(s);
    ASSERT_STRING("", s);
}

void test_reverseWords3() {
    char s[] = " ff to";
    reverseWords(s);
    ASSERT_STRING("to ff", s);
}

void test_reverseWords() {
    test_reverseWords1();
    test_reverseWords2();
    test_reverseWords3();
    test_reverseWords_emptyString();
}

#endif
