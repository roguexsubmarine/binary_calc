#include<stdio.h>
#include<stdlib.h>

//typedef -ing node_stack
typedef struct node_stack{
	int data;
	struct node_stack *next;
}node_stack;

//typedef -ing node_stack
typedef node_stack* stack;

//defining functions
void init_stack(stack *head);
void ins_end_stack(stack *head, int d);
void ins_beg_stack(stack *head, int d);
void traverse_stack(stack *head);
void del_beg_stack(stack *head);
void del_end_stack(stack *head);
void is_palindrome_stack(stack *head); 
void remove_duplicates_stack(stack *head);


//init stack
void init_stack(stack *head){
	*head = NULL;
	return;	
}

//insert at end
void ins_end_stack(stack *head, int d){
	node_stack *p, *q;
	p = (node_stack *)malloc(sizeof(node_stack));
	if (p){
		p->data = d;
		p->next = NULL;
	}
	else{
		return;
	}
	if(*head == NULL){
		*head = p;
		return;
	}
	q = *head;
	while(q->next != NULL){
		q = q->next;
	}
	q->next = p;
	return;
}

//insert at begining 
void ins_beg_stack(stack *head, int d){
	node_stack *p;
	p = (node_stack *)malloc(sizeof(node_stack));
	if (p){
		p->data = d;
		p->next = *head;
		*head = p;
	}
	else{
		return;
	}
}

//printing stack
void traverse_stack(stack *head){
	if (*head == NULL){
		return;
	}
	node_stack *p;
	p = *head;
	printf("[");
	while(p){
		printf("'%d'", p->data);
		p = p->next;
	}
	printf("]");
	return;
}

//deleting first element
void del_beg_stack(stack *head){
	if (!(*head)){
		return;
	}
	node_stack *p;
	p = *head;
	*head = (*head)->next;
	free(p);
	return;
}

//deleting top element in the stack
void del_end_stack(stack *head){
	if(!(*head)){
		return;
	}
	node_stack *p, *q;
	q = *head;
	while(q->next){
		q = q->next;
	}
	p = *head;
	while(p->next != q){
		p = p->next;
	}
	p->next = NULL;
	free(q);
	return;
}

//to check if its palindrome
void is_palindrome_stack(stack *head){
	node_stack *p;
	p = *head;
	int count = 0;
	while(p->next){
		count++;
		p = p->next;
	}
	int arr[count ];
	p = *head;
	int i = 0;
	while(p){
		arr[i] = p->data;
		i++;
		p = p->next;
	}
	int m = 0;
	int n = count;
	while(m++ <= n--){
		if (arr[m] != arr[n]){
			printf("Not a Palindrome");
			return;
		}
	}
	printf("Is a Palindrome");
	return;
}

// deleting similar elements
void remove_duplicates_stack(stack *head){
	//find greatest
	int big = 0;
	node_stack *p;
	p = *head;
	while(p){
		if(p->data > big){
			big = p->data;
		}
		p = p->next;
	}
	printf("%d\n",big);

	//declaring array of greatest size
	int arr[big];
	for(int j = 0; j <= big; j++){
		arr[j] = 0;
	}
	p = *head;

	//incrementing the elements corresponding to their indices
	while(p){
		arr[p->data] += 1;
		p = p->next;
	}

	/*//loop to print our array 
		for(int j = 0; j <= big; j++){
			printf("%d ",arr[j]);
		}
	*/

	p = *head;
	node_stack *q;
	q = *head;
	p = p->next;

	while(p){
		if(arr[p->data] > 1){
			q = p->next;
		}
	}


}