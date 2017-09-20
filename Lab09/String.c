// COMP1511 17s2 -- Complex ADT
// Created by: Tim Ryan (z5080316)
//             Oscar Golding (z5160173)
// Created on: 2017-09-19
// Tutorial:   Tue10am


#include "String.h"
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE !TRUE
#include <err.h>

typedef struct _string {
    int length;
    char* characters;
} string;

static int getLength(char * str) {
    int length = 0;

    while(str[length] != '\0'){
        length ++;
    }
    return length;
}

String newString (char *str){
    String newString = calloc(1, sizeof(string));
    //newString->characters = stringClone(str);

    newString->length = getLength(str);
    newString->characters = calloc(newString->length+1, sizeof(char));

    int i = 0;
    while (i < newString->length + 1) {
        newString->characters[i] = str[i];
        i++;
    }


    return newString;
}


void destroyString (String s){
    free(s->characters);
    free(s);
}

int stringLength (String s){
    return s->length;
}

String stringClone (String s){
    int i = 0;
    //printf("length of string to copy is %d\n",(s->length));
    char clonedString[s->length+1];

    while (s->characters[i] != '\0') {
        clonedString[i] = s->characters[i];
        i++;
    }
    clonedString[i] = '\0';

    String clone = newString(clonedString);
    return clone;
}

char stringAt (String s, int index){
    if (index < 0 || index > stringLength(s)){
        errx(EXIT_FAILURE, "Invalid index");
    } else {
        char character = s->characters[index-1];
        return character;
    }
}

int stringFindChar (String s, char find){
    int i = 0;
    int foundMatch = 0;
    while(s->characters[i] != '\0' && foundMatch == 0){
        if (s->characters[i] == find){
            foundMatch = 1;
        } else {
            i ++;
        }
    }

    if (foundMatch == 1){
        return i+1;//since it indexes from 0.
    } else {
        return -1;
    }
}


int stringsEqual (String s1, String s2) {

    if (s1->length != s2->length) {
        return FALSE;
    } else {
        int i = 0;
        int match = TRUE;
        while (s1->characters[i] != '\0' && s2->characters[i] != '\0' &&
            match == TRUE) {
            if (s1->characters[i] == s2->characters[i]){
                i++;
            } else {
                match = FALSE;
            }
        }
        return match;
    }
}

String stringConcat (String s1, String s2){
    int newLength = s1->length + s2->length;
    char joinedString[newLength+1];
    int i = 0;
    while (i < s1->length) {
        joinedString[i] = s1->characters[i];
        i++;
    }
    int j = 0;

    while (j < s2->length) {
        joinedString[i] = s2->characters[j];
        i++;
        j++;
    }
    joinedString[i] = '\0';
    String concatString = newString(joinedString);
    return concatString;
}
