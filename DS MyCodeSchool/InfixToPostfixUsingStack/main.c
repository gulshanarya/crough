//Infix To Postfix using stack
//*Note: Must have my lib list.h and list.c

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdarg.h>
#include "list.h"


int checkPriority(char opr) {

    int priorityLen;
    switch(opr) {

        case '+': priorityLen = 1;
        break;
        case '-': priorityLen = 1;
        break;
        case '*': priorityLen = 2;
        break;
        case '/': priorityLen = 2;
        break;
    }

    return priorityLen;
}

int hasHighPrecedence(char prevOpr, char newOpr) {

    if(checkPriority(prevOpr) >= checkPriority(newOpr)) { //opr in stacklist have high or equal priority
        return 1;
    }
//    if((prevOpr == '*' || prevOpr == '/') && (newOpr != '*' || newOpr != '/')) {
//        return 1;
//    }
    return 0;

}

int IsOpeningParantheses(char ele) {
    if(ele == '(' || ele == '{' || ele == '[') {
        return 1;
    }
    return 0;
}

int IsClosingParantheses(char ele) {
    if(ele == ')' || ele == '}' || ele == ']') {
        return 1;
    }

    return 0;
}

char res[20] = "";
char* InfixToPostfix(char exp[]) {

    List stackList = list(0);
    int count = 0;
    for(int i =0; i< strlen(exp); i++) {
        if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {
            printf("%d ", stackList.isEmpty());
            while(!stackList.isEmpty() && hasHighPrecedence(stackList.get(), exp[i]) && !IsOpeningParantheses(stackList.get())) {
                res[count] = stackList.get();
                printf("%d ", count);
                stackList.rem();
                count += 1;
            }
            stackList.append(exp[i]);
        } else if(IsOpeningParantheses(exp[i])) {
            stackList.append(exp[i]);
        } else if(IsClosingParantheses(exp[i])) {
            while(!stackList.isEmpty() && !IsOpeningParantheses(stackList.get())) {
                res[count] = stackList.get();
                count++;
                stackList.rem();
            }
            stackList.rem(); //for removing the opening brackets from stackList
        } else {
            res[count] = exp[i];
            count += 1;
        }
    }

    while(!(stackList.isEmpty() == 1)) {
//        printf("%d ", count);
        res[count] = stackList.get();
        count++;
        stackList.rem();
    }

    return res;
}

int main(){

    printf("%s", InfixToPostfix("((A+B)*C-D)*E"));

    return 0;
}

