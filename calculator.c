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
int isbigger(list* list1, list* list2) {
    node* p1 = list1->front;
    node* p2 = list2->front;

    // Skip leading zeros
    while (p1 && p1->data == 0) {
        p1 = p1->next;
    }

    while (p2 && p2->data == 0) {
        p2 = p2->next;
    }

    // Compare lengths after skipping leading zeros
    int len1 = 0;
    int len2 = 0;

    while (p1) {
        len1++;
        p1 = p1->next;
    }

    while (p2) {
        len2++;
        p2 = p2->next;
    }

    if (len1 < len2) {
        return 0;  // list1 is shorter
    } else if (len1 > len2) {
        return 1;  // list1 is longer
    }

    // Compare digits
    p1 = list1->front;
    p2 = list2->front;

    while (p1 && p2) {
        if (p1->data < p2->data) {
            return 0;  // list1 is lexicographically smaller
        } else if (p1->data > p2->data) {
            return 1;  // list1 is lexicographically greater
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    return 0;  // Both lists are equal
}

//add function
void bin_sum(list* sum, list* list1, list* list2){

    //adding elements of both lists
    node* p1 = list1->rear;
    node* p2 = list2->rear;

    while(p1 && p2){
        insertleft_dll(sum, (p1->data + p2->data));
        p1 = p1->prev;
        p2 = p2->prev;
    }
    while(!p2 && p1){
        insertleft_dll(sum, (p1->data));
        p1 = p1->prev;
    }
    while(!p1 && p2){
        insertleft_dll(sum, (p2->data));
        p2 = p2->prev;
    }

    p1 = sum->rear;
    int carry;
    while(p1->prev){
        if (p1->data > 9){
            carry = (int)(p1->data / 10);
            p1->prev->data = p1->prev->data + carry;
            p1->data =  p1->data % 10;
        }
        p1 = p1->prev;
    } 

    if (p1->data > 9){
        carry = (int)(p1->data / 10);
        insertleft_dll(sum, carry);
        p1->data = p1->data % 10;
    }
    return;
}

//difference function
void bin_diff(list* diff, list* list1, list* list2){

    if(isbigger(list1, list2)){
        //subtracting elements of both lists
        node* p1 = list1->rear;
        node* p2 = list2->rear;

        while(p1 && p2){
            insertleft_dll(diff, (p1->data - p2->data));
            p1 = p1->prev;
            p2 = p2->prev;
        }
        while(!p2 && p1){
            insertleft_dll(diff, (p1->data));
            p1 = p1->prev;
        }
        while(!p1 && p2){
            insertleft_dll(diff, (p2->data));
            p2 = p2->prev;
        }

        p1 = diff->rear;
        int borrow;
        while(p1->prev){
            if (p1->data < 0){
                p1->data = (p1->data + 10);
                p1->prev->data = p1->prev->data - 1;
            }
            p1 = p1->prev;
        }
    }
    else {

        //subtracting elements of both lists
        node* p1 = list2->rear;
        node* p2 = list1->rear;

        while(p1 && p2){
            insertleft_dll(diff, (p1->data - p2->data));
            p1 = p1->prev;
            p2 = p2->prev;
        }
        while(!p2 && p1){
            insertleft_dll(diff, (p1->data));
            p1 = p1->prev;
        }
        while(!p1 && p2){
            insertleft_dll(diff, (p2->data));
            p2 = p2->prev;
        }

        p1 = diff->rear;
        int borrow;
        while(p1->prev){
            if (p1->data < 0){
                p1->data = (p1->data + 10);
                p1->prev->data = p1->prev->data - 1;
            }
            p1 = p1->prev;
        }

        diff->front->data = 0 - (diff->front->data);

    }
    return;

}

//multiplying with single digit
void bin_prod_single (list *prod, list* list1, int d){

    node* r1 = list1->rear;

    while(r1){
        insertleft_dll(prod, r1->data * d);
        r1 = r1->prev;
    }

    r1 = prod->rear;
    while(r1){
        if(!r1->prev){
            insertleft_dll(prod, (r1->data) / 10);
            r1->data = r1->data % 10;
            return;
        }
        else{
            if(r1->data > 9){
                r1->prev->data = r1->prev->data + ((r1->data) / 10);
                r1->data = r1->data % 10;
            }
        }
        r1 = r1->prev;
    }

    return;
}

//multiplication function
void bin_prod(list* prod, list* list1, list* list2){
    
    list temp_prod;
    init_dll(&temp_prod);

    list temp_sum;

    node* s1 = list2->front;
    while(s1){
        bin_prod_single(&temp_prod, list1, s1->data);
        s1 = s1->next;

        //creating copy of temp product
        init_dll(&temp_sum);
        node* q1 = prod->front;
        while(q1){
            insertright_dll(&temp_sum, q1->data);
            q1 = q1->next;
        }
        insertright_dll(&temp_sum, 0);
        printlistLR_dll(&temp_sum);
        init_dll(prod);
        bin_sum(prod, &temp_prod, &temp_sum);
    }

    


    return;
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

    printf("%d\n", isbigger(&input1, &input2));

    //creating sum linked list

    list sum_dll;
    init_dll(&sum_dll);
    bin_sum(&sum_dll, &input1, &input2);

    //printing sum

    printlistLR_dll(&sum_dll);

    //creating diff linked list

    list diff_dll;
    init_dll(&diff_dll);
    bin_diff(&diff_dll, &input1, &input2);

    //printing diff

    printlistLR_dll(&diff_dll);

    //printf("\n%d\n", length_dll(&input1));

    //creating product linked list

    list prod_dll;
    init_dll(&prod_dll);
    bin_prod(&prod_dll, &input1, &input2);

    //printing prod

    printlistLR_dll(&prod_dll);



    printf("\n");
    return 0;
}