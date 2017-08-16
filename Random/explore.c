//  Exploring memory
//  Created by Richard Buckland on 2012-11-20.
//
//  Modified by:
//      Your name (your zID)
//      Your partner's name (your partner's zID)
//
//  YYYY-MM-DD

#include <stdio.h>
#include <stdlib.h>

long add (int x, int y);

int main(int argc, const char * argv[]) {

    int x;
    int y;
    long total;

    x = 40;
    y = 2;

    printf("The size of a int, in bytes, is %lu.\n", sizeof(x));
    printf("The variable x is located at memory address %p.\n", &x);

    total = add (x, y);

    printf("the sum of %d and %d is %ld\n", x, y, total);

    char c ='a';
	printf("The size of a char, in bytes, is %lu.\n", sizeof(c));
    printf("The variable c is located at memory address %p.\n", &c);

    unsigned long ul       = 0;
    printf("The size of an unsigned long, in bytes, is %lu.\n", sizeof(ul));
    printf("The variable ul is located at memory address %p.\n", &ul);

    unsigned int ui        = 1;
    printf("The size of an unsigned int, in bytes, is %lu.\n", sizeof(ui));
    printf("The variable ui is located at memory address %p.\n", &ui);

    unsigned long long ull = 2;
    printf("The size of an unsigned long long, in bytes, is %lu.\n", sizeof(ull));
    printf("The variable ull is located at memory address %p.\n", &ull);

    unsigned short us      = 3;
    printf("The size of an unsigned short, in bytes, is %lu.\n", sizeof(us));
    printf("The variable us is located at memory address %p.\n", &us);

    signed long sl       = 4;
    printf("The size of a signed long, in bytes, is %lu.\n", sizeof(sl));
    printf("The variable sl is located at memory address %p.\n", &sl);

    signed int si        = 5;
    printf("The size of a signed int, in bytes, is %lu.\n", sizeof(si));
    printf("The variable si is located at memory address %p.\n", &si);

    signed long long sll = 6;
    printf("The size of a signed long long, in bytes, is %lu.\n", sizeof(sll));
    printf("The variable sll is located at memory address %p.\n", &sll);

    signed short ss      = 7;
    printf("The size of a signed short, in bytes, is %lu.\n", sizeof(ss));
    printf("The variable ss is located at memory address %p.\n", &ss);

    long l       = 8;
    printf("The size of a long, in bytes, is %lu.\n", sizeof(l));
    printf("The variable l is located at memory address %p.\n", &l);

    int i        = 9;
    printf("The size of a int, in bytes, is %lu.\n", sizeof(i));
    printf("The variable i is located at memory address %p.\n", &i);

    long long ll = 10;
    printf("The size of a long long, in bytes, is %lu.\n", sizeof(ll));
    printf("The variable ll is located at memory address %p.\n", &ll);

    short s      = 11;
    printf("The size of a short, in bytes, is %lu.\n", sizeof(s));
    printf("The variable s is located at memory address %p.\n", &s);

    float f = 3.1;
    printf("The size of a float, in bytes, is %lu.\n", sizeof(f));
    printf("The variable f is located at memory address %p.\n", &f);

    double d = 3.14;
	printf("The size of a double, in bytes, is %lu.\n", sizeof(d));
	printf("The variable d is located at memory address %p.\n", &d);

    unsigned int as1 = 4294967295;
    printf("The size of unsigned int is %d.\n", as1);

    unsigned int as2 = -1;
    printf("The size of unsigned int is %d.\n", as2);

    // add them all together just to make use of them so the compiler
    // doesn't grumble that they are unused in the program

    double grandTotal;
    grandTotal =  c +
        ul + ui + ull + us +
        sl + si + sll + ss +
        l +  i +  ll +  s +
        f + d;

    printf ("all these things added together make %f\n",
            grandTotal);

    // Some of the loops that are able to return numbers (no integer problem).

    char qwe = 0;
    while (qwe >= 0) {
        qwe++;
    }
    printf("The min values of char is %d\n", qwe);

    char poi = 0;
    while (poi <= 0) {
        poi--;
    }
    printf("The max value of char is %d\n", poi);

    unsigned char azc, fgh;
    azc = 1;
    while (azc > 0) {
        fgh = azc;
        azc++;
    }
    printf("The max values of usigned char is %d\n", fgh);

    unsigned short cvb, vbn;
    cvb = 1;
    while (cvb > 0) {
        vbn = cvb;
        cvb++;
    }
    printf("The max values of usigned short is %d\n", vbn);

    short hjk, jkl;
    hjk = 1;
    while (hjk > 0) {
        jkl = hjk;
        hjk++;
    }
    printf("The min values of short is %d\n", hjk);
    printf("The max value of short is %d\n", jkl);

    long long a1, a2;
    a1 = 1;
    while (a1 > 0) {
        a2 = a1;
        a1++;
    }
    printf("The min values of float is %lld\n", a1);
    printf("The max value of float int is %lld\n", a2);

    unsigned int tyui, yui;
    tyui = 1;
    while (tyui > 0) {
        yui = tyui;
        tyui++;
    }
    printf("The min values of unsigned int is %d\n", yui);
    printf("The max value of usigned int is %d\n", tyui);

    // Add in your own variables, printf statements and arithmetic to
    // figure out the size of different types, where they live
    // and how big the numebrs they store are


    return EXIT_SUCCESS;
}

long add (int x, int y) {
    long answer;
    answer = x + y;

    return answer;
}
