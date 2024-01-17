#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>

#include "linkedlist.c"
#include "stack.c"



//input function
list input_dll(list* input){
    // writing first input function
    char digit = 0;
    printf("Enter the string\n>>>");
    while(1){
        char c;
        scanf("%c",&c);

        if(isdigit(c)){
           insertright_dll(input, (int)(c-'0')); 
        }
        else
            break;
    }
    return *input;
}

//return 1 if first is bigger and 0 is second is bigger
int isbigger(list* list1, list* list2){

    node* p1 = list1->front;
    node* p2 = list2->front;

    if(length_dll(list1) < length_dll(list2)){
        return 0;
    }

    while(p1 && p2){
        if(p1->data < p2->data){
            return 0;
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    return 1;
}

//add function
list bin_sum(list* sum, list* list1, list* list2){

    //reversing both lists
    reverse_dll(list1);
    reverse_dll(list2);

    //adding elements of both lists
    node* p1 = list1->front;
    node* p2 = list2->front;

    while(p1 && p2){
        insertright_dll(sum, (p1->data + p2->data));
        p1 = p1->next;
        p2 = p2->next;
    }

    //reversing lists back
    reverse_dll(list1);
    reverse_dll(list2);

    p1 = sum->front;
    int carry;
    while(p1->next){
        

        if (p1->data > 9){
            carry = (int)(p1->data / 10);
            p1->next->data = p1->next->data + carry;
            p1->data =  p1->data % 10;
        }
        p1 = p1->next;
    } 

    if (p1->data > 9){
        carry = (int)(p1->data / 10);
        insertright_dll(sum, carry);
        p1->data = p1->data % 10;
    }

    reverse_dll(sum);
    return *sum;

}


//diff function
list bin_diff(list* diff, list* list1, list* list2){

    if(isbigger(list1, list2)){
        //reversing both lists
        reverse_dll(list1);
        reverse_dll(list2);

        //subtracting elements of both lists
        node* p1 = list1->front;
        node* p2 = list2->front;

        while(p1->next && p2->next){
        
        //sub
        int sub = p1->data - p2->data;
        if(p1->data < p2->data){
            p1->next->data = p1->next->data - 1;
            sub = sub + 10;
        }
        insertright_dll(diff, sub);
        p1 = p1->next;
        p2 = p2->next;
        }

        int sub = p1->data - p2->data;
        insertright_dll(diff, sub);

    }
    else{

        //reversing both lists
        reverse_dll(list1);
        reverse_dll(list2);

        //subtracting elements of both lists
        //switching the numbers !!!
        node* p2 = list1->front;
        node* p1 = list2->front;

        while(p1->next && p2->next){
        
        //sub
        int sub = p1->data - p2->data;
        if(p1->data < p2->data){
            p1->next->data = p1->next->data - 1;
            sub = sub + 10;
        }
        insertright_dll(diff, sub);
        p1 = p1->next;
        p2 = p2->next;
        }

        int sub = p1->data - p2->data;
        insertright_dll(diff, 0 - sub);

    }

    reverse_dll(diff);
    return *diff;


}




int main() {

    //creating a linked list 1
    list input1;
    init_dll(&input1);

    //input list 1
    input1 = input_dll(&input1);


    //printing list 1
    //printlistLR_dll(&input1);


    //creating a second linked list
    list input2;
    init_dll(&input2);

    //inputting list 2
    input2 = input_dll(&input2);

    //printing list 2
    //printlistLR_dll(&input2);

    //creating sum linked list
    list sum_dll;
    init_dll(&sum_dll);
    sum_dll = bin_sum(&sum_dll, &input1, &input2);

    //printing sum
    printlistLR_dll(&sum_dll);

    //creating diff linked list
    list diff_dll;
    init_dll(&diff_dll);
    diff_dll = bin_diff(&diff_dll, &input1, &input2);

    //printing diff
    printlistLR_dll(&diff_dll);




    return 0;
}