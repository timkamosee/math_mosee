#pragma once

/* 
   Header-only библиотека.
   Все функции inline, чтобы избежать multiple definition.
*/

#ifndef CALC_STRUCT_DEFINED
#define CALC_STRUCT_DEFINED

struct calc {
    long long a;
    long long b;
    char operation;
    int err = 0;      //1 - incorrect input      4 - переполнение после вычсления 
    long long result; //2 - Переполнение типа
};                    //3 - деление на 0

#endif

namespace math_mosee {

inline void add(calc* str){
    if (__builtin_add_overflow(str->a, str->b, &str->result) ){
        str->err = 4;
    }
}

inline void sub(calc* str){
    if(__builtin_sub_overflow(str->a, str->b, &str->result)){
        str->err = 4;
    }
}

inline bool mul(long long a,  long long b, long long* result ){
    if(__builtin_mul_overflow(a, b, result)){
        return true;
    }
    return false;
}

inline int dic(calc* str){
    str->result = str->a / str->b; 
    return 0;
}

inline int exp(calc* str){
    str->result = str->a;
    bool errcod = false;
    for(int i = 1; i < str-> b && !errcod; i++){
        errcod = mul(str->result, str->a, &str->result);
    }
    if(errcod)str->err = 4;
    return 0;
}

inline long long fac(long long n, int* errcod){
    if (n <= 1) return (long long)1;
    long long result;
    if(mul(n, fac(n - 1, errcod), &result)) {
        *errcod = 4
        return 0}; 
    return result;
}
}