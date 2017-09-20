#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "String.h"


int main(void) {
    printf("Starting Tests...\n");

    String myString = newString("hello");
    assert(stringLength(myString) == 5);

    myString = newString("comp1511");
    assert(stringLength(myString) == 8);

    myString = newString("this is a long string");
    assert(stringLength(myString) == 21);

    myString = newString(".");
    assert(stringLength(myString) == 1);

    myString = newString("");
    assert(stringLength(myString) == 0);

    printf("Passed String length Tests!\n");


    String anotherString = newString("hamburger");
    String clonedString;
    clonedString = stringClone(anotherString);
    assert(stringsEqual(clonedString, anotherString) == 1);

    anotherString = newString("ch33s3");
    clonedString = stringClone(anotherString);
    assert(stringsEqual(clonedString, anotherString) == 1);

    anotherString = newString("");
    clonedString = stringClone(anotherString);
    assert(stringsEqual(clonedString, anotherString) == 1);

    anotherString = newString("this should fail ...");
    clonedString = stringClone(anotherString);
    anotherString = newString("this should fail ....");
    assert(stringsEqual(clonedString, anotherString) == 0);

    printf("Passed Clone and Equal Tests!\n");


    anotherString = newString("SOMeth1ng ");
    assert(stringAt(anotherString,2) == 'O');
    assert(stringAt(anotherString,5) == 't');
    assert(stringAt(anotherString,7) == '1');
    assert(stringAt(anotherString,10) == ' ');

    printf("Passed stringAt Tests!\n");



    String stringy;
    stringy = newString("qwerTYiiiiop");
    assert(stringFindChar(stringy, 'Q') == -1);
    assert(stringFindChar(stringy, 'i') == 7);
    assert(stringFindChar(stringy, 'p') == 12);

    printf("Passed stringFindChar Tests!\n");


    String stringa;
    stringa = newString("It's a me, ");
    String stringb;
    stringb = newString("Mario!");
    String joined;
    joined = stringClone(stringConcat (stringa, stringb));
    String answer;
    answer = newString("It's a me, Mario!");
    assert(stringsEqual(joined, answer) == 1);

    printf("Passed stringConcat Tests!\n");


}
