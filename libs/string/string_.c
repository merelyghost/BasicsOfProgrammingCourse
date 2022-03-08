#include "string_.h"

void assertString(const char *expected, char *got,
                  char const *fileName, char const *funcName,
                  int line) {
    int x = strcmp(expected, got);
    if (x) {
        fprintf(stderr, " File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, " Expected : \"%s\"\n", expected);
        fprintf(stderr, "Got: \"%s\"\n\n", got);
    } else
        fprintf(stderr, "%s - OK\n", funcName);
}


size_t strlen_(char *begin) {
    char *end = begin;
    while (*end != '\0')
        end++;
    return end - begin;
}


char *find(char *begin, const char *end, int ch) {
    while (begin != end && *begin != ch)
        begin++;

    return begin;
}

char *findNonSpace(char *begin) {
    while (*begin != '\0' && isspace(*begin))
        begin++;

    return begin;
}

char *findSpace(char *begin) {
    while (*begin != '\0' && !isspace(*begin))
        begin++;

    return begin;
}

char *findNonSpaceReverse(char *rbegin, const char *rend) {
    while (rbegin != rend && isspace(*rbegin))
        rbegin--;

    return rbegin;
}

char *findSpaceReverse(char *rbegin, const char *rend) {
    while (rbegin != rend && !isspace(*rbegin))
        rbegin--;

    return rbegin;
}


int strcmp(const char *lhs, const char *rhs) {
    while (*lhs != '\0' && (*lhs == *rhs))
        lhs++, rhs++;

    return *lhs - *rhs;
}


char *copy(const char *beginSource, const char *endSource, char *beginDestination) {
    memcpy(beginDestination, beginSource, endSource - beginSource);

    return beginDestination + (endSource - beginSource);
}

void copyReverse(char *rbeginSource, const char *rendSource, char *beginDestination) {
    while (rbeginSource != rendSource) {
        *beginDestination++ = *rbeginSource;

        rbeginSource--;
    }
    *beginDestination = '\0';
}

char *copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int)) {
    while (beginSource != endSource) {
        if (f(*beginSource))
            *beginDestination++ = *beginSource;

        beginSource++;
    }

    return beginDestination;
}

char *copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int)) {
    while (rbeginSource != rendSource) {
        if (f(*rbeginSource))
            *beginDestination++ = *rbeginSource;

        rbeginSource--;
    }

    return beginDestination;
}


char *getEndOfString(char *begin) {
    while (*begin != '\0')
        begin++;

    return begin;
}

char *copyIfC(char *beginSource, const char *endSource, char *beginDestination, int (*f)(char *)) {
    while (beginSource != endSource) {
        if (f(beginSource))
            *beginDestination++ = *beginSource;

        beginSource++;
    }

    return beginDestination;
}

int nextIsNotEqual(char *c) {
    return *c != *(c + 1);
}


int getWord(char *beginSearch, WordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);
    if (*word->begin == '\0')
        return 0;

    word->end = findSpace(word->begin);

    return 1;
}

int getLastWord(char *beginSearchR, char *endSearchR, WordDescriptor *word) {
    word->end = findNonSpaceReverse(beginSearchR, endSearchR);

    if (word->end == endSearchR)
        return 0;

    word->begin = findSpaceReverse(word->end, endSearchR);
    word->begin++, word->end++;

    return 1;
}

void digitsToStart(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end, _stringBuffer);
    char *recPosition = copyIf(_stringBuffer,
                               endStringBuffer,
                               word.begin, isdigit);
    copyIf(_stringBuffer, endStringBuffer, recPosition, isalpha);
}

int areWordsEqual(WordDescriptor w1, WordDescriptor w2) {
    char *beginW1 = w1.begin;
    char *beginW2 = w2.begin;

    while (beginW1 != w1.end - 1 && (*beginW1 == *beginW2))
        beginW1++, beginW2++;

    return *beginW1 - *beginW2;
}

void getBagOfWords(BagOfWords *bag, char *s) {
    char *beginSearch = s;
    WordDescriptor word;
    bag->size = 0;
    while (getWord(beginSearch, &word)) {
        bag->words[bag->size] = word;
        bag->size++;
        beginSearch = word.end;
    }
}

void wordDescriptorToString(WordDescriptor word, char *destination) {
    *copy(word.begin, word.end, destination) = '\0';
}