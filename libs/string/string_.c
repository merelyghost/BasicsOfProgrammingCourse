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

void digitsToStart(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end, _stringBuffer);
    char *recPosition = copyIf(_stringBuffer,
                                      endStringBuffer,
                                      word.begin, isdigit);
    copyIf(_stringBuffer, endStringBuffer, recPosition, isalpha);
}
