#ifndef COURSE_OUTPUTREVERSEWORDS_H
#define COURSE_OUTPUTREVERSEWORDS_H

#include "../string_.h"

//Вывести слова данной строки в обратном порядке по одному в строке экрана

void outputReverseWords(char *s) {
    getBagOfWords(&_bag, s);
    char word[MAX_STRING_SIZE];
    for (int i = 0; i < _bag.size; i++) {
        copyReverse(_bag.words[i].end - 1, _bag.words[i].begin - 1, word);
        printf("%s", word);
        if (i != _bag.size - 1)
            printf(" ");
    }
}

/*
void test_outputReverseWords() {
    char *s = "ab bc cd";
    outputReverseWords(s);
    printf("\n");

    char *s2 = " abcd 123  \t y89 ";
    outputReverseWords(s2);
    printf("\n");

    char *s3 = "123456  789";
    outputReverseWords(s3);
    printf("\n");

    char *s4 = " ";
    outputReverseWords(s4);
    printf("\n");
} */


#endif
