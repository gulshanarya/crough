//Check for balanced parenthesis using stack
//*Note: Must have my lib list.h

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdarg.h>
#include "list.h"

void checkForBalancedParanthesis(char exp[]) {

    List stackList = list(0);
    for(int i =0; i < strlen(exp); i++) {
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            stackList.append(exp[i]);
        } else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if(stackList.get()  == exp[i] - 1 || stackList.get()  == exp[i] - 2) {
                //balanced
                stackList.rem();
            } else {
                printf("Last opened, closed first or put open bracket first!");
                return;
            }
        }
    }

    if(stackList.get() == '\0') { //since get() is returning null if empty
        printf("Expression is balanced");
    } else {
        printf("Expression is not balanced");
    }
}

int main(){


    checkForBalancedParanthesis("}{");

    //printNode();
//    int ab[] = {4,5,6,7};
//    arr((int[3]){4,5,6});
    return 0;
}

