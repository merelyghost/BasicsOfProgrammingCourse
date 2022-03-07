#ifndef COURSE_STRING__H
#define COURSE_STRING__H

#include <stdio.h>
#include <ctype.h>
#include <memory.h>

#define MAX_STRING_SIZE 100
#define ASSERT_STRING(expected, got) assertString(expected, got, \
__FILE__ , __FUNCTION__ , __LINE__ )

char _stringBuffer[MAX_STRING_SIZE + 1];


void assertString(const char *expected, char *got,
                  char const *fileName, char const *funcName,
                  int line);

typedef struct WordDescriptor {
    char *begin; // позиция начала слова
    char *end;   // позиция первого символа, после последнего символа слова
} WordDescriptor;


// возвращает количество символов в строке, не считая ноль-символ
size_t strlen_(char *begin);

// возвращает указатель на первый элемент с кодом ch,
// расположенным на ленте памяти между адресами begin и end не включая end,
// если символ не найден, возвращается значение end
char *find(char *begin, const char *end, int ch);

// возвращает указатель на первый символ, отличный от пробельных,
// расположенный на ленте памяти, начиная с begin и заканчивая ноль-символом,
// если символ не найден, возвращается адрес первого ноль-символа
char *findNonSpace(char *begin);

// возвращает указатель на первый пробельный символ,
// расположенный на ленте памяти начиная с адреса begin,
// если символ не найден, возвращается адрес первого ноль-символа
char *findSpace(char *begin);

// возвращает указатель на первый справа символ, отличный от пробельных,
// расположенный на ленте памяти, начиная с rbegin (последний символ строки, за которым следует ноль-символ)
// и заканчивая rend (адрес символа перед началом строки),
// если символ не найден, возвращается адрес rend
char *findNonSpaceReverse(char *rbegin, const char *rend);

// возвращает указатель на первый пробельный символ справа,
// расположенный на ленте памяти, начиная с rbegin и заканчивая rend,
// если символ не найден, возвращается адрес rend
char *findSpaceReverse(char *rbegin, const char *rend);


// возвращает значение 0, если lhs и rhs равны,
// отрицательное значение, если lhs располагается до rhs в лексикографическом порядке,
// иначе положительное значение
int strcmp(const char *lhs, const char *rhs);

// записывает по адресу beginDestination фрагмент памяти, начиная с адреса beginSource до endSource,
// возвращает указатель на следующий свободный фрагмент памяти в destination
char *copy(const char *beginSource, const char *endSource, char *beginDestination);

// записывает по адресу beginDestination элементы из фрагмента памяти начиная с beginSource
// заканчивая endSource, удовлетворяющие функции-предикату f,
// возвращает указатель на следующий свободный для записи фрагмент в памяти
char *copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int));

// записывает по адресу beginDestination элементы из фрагмента памяти начиная с rbeginSource
// заканчивая rendSource, удовлетворяющие функции-предикату f,
// возвращает значение beginDestination по окончанию работы функции
char *copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int));

// возвращает конец строки
char *getEndOfString(char *begin);

char *copyIfC(char *beginSource, const char *endSource, char *beginDestination, int (*f)(char *));

// возвращает значение истина если значение по адресу с не равно следующему на ленте памяти, иначе - ложь
int nextIsNotEqual(char *c);

// возвращает значение 0, если слово не было считано, в противном
// случае будет возвращает значение 1 и в переменную word типа WordDescriptor
// записывает позиции начала слова, и первого символа после конца слова
int getWord(char *beginSearch, WordDescriptor *word);

// переносит цифры в слове word в начало
void digitsToStart(WordDescriptor word);



#endif
