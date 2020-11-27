//Evaluation of Prefix and Postfix expressions using stack
//*Note: Must have my lib list.h and list.c

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdarg.h>
#include "list.h"


float operationRes(char op, float oprL,float oprR) {

    float res;

    switch(op)
    {
        case '+': res = oprL+oprR;
        break;
        case '-': res = oprL-oprR;
        break;
        case '*': res = oprL*oprR;
        break;
        case '/': res = oprL/oprR;
        break;
    }

    return res;
}

float EvaluatePreFix(char exp[]) {

    List stackList = list(0);
    for(int i = strlen(exp)-1; i>=0; i--) {
        if(!(exp[i] == '*' || exp[i] == '+' || exp[i] == '-' || exp[i] == '/')) {
            stackList.append(exp[i] - '0'); //actual number of that char integer
        } else {
            float oprL = stackList.get(); //Left operand at the top of stack
            stackList.rem();

            float oprR = stackList.get(); //right operand at the bottom of stack
            stackList.rem();

            stackList.append(operationRes(exp[i], oprL, oprR));
        }
    }

    return stackList.get();
}

float EvaluatePostFix(char exp[]) {

    List stackList = list(0);
    for(int i = 0; i<strlen(exp); i++) {
        if(!(exp[i] == '*' || exp[i] == '+' || exp[i] == '-' || exp[i] == '/')) {
            stackList.append(exp[i]-'0'); //actual number of that char integer
        } else {
            float oprR = stackList.get(); //right operand at the top of stack
            stackList.rem(); //opr1

            float oprL = stackList.get(); //left operand at the bottom of stack
            stackList.rem(); //opr2

            stackList.append(operationRes(exp[i], oprL, oprR));
        }

    }

    return stackList.get();

}

int main(){


    float postres = EvaluatePostFix("23*54*+9-");
    float preres = EvaluatePreFix("-+*23*549");
    printf("answer postfix: %f\nanswer prefix: %f", postres, preres);


    return 0;
}

