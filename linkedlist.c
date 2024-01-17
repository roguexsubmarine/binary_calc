//typedef -ing node

typedef struct node{
	int data;
	struct node *next;
}node;


// typedef -ing list 
typedef node* list;


//function definitions
void init_sll(list *head);
void ins_end_sll(list *head, int d);
void ins_beg_sll(list *head, int d);
void traverse_sll(list *head);
void del_beg_sll(list *head);
void del_end_sll(list *head);
void is_palindrome_sll(list *head); 
void remove_duplicates_sll(list *head);


//function definitions

void init_sll(list *head){
	*head = NULL;
	return;	
}

void ins_end_sll(list *head, int d){
	node *p, *q;
	p = (node *)malloc(sizeof(node));
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

void ins_beg_sll(list *head, int d){
	node *p;
	p = (node *)malloc(sizeof(node));
	if (p){
		p->data = d;
		p->next = *head;
		*head = p;
	}
	else{
		return;
	}
}

void traverse_sll(list *head){
	if (*head == NULL){
		return;
	}
	node *p;
	p = *head;
	printf("[");
	while(p){
		printf("'%d'", p->data);
		p = p->next;
	}
	printf("]");
	return;
}

void del_beg_sll(list *head){
	if (!(*head)){
		return;
	}
	node *p;
	p = *head;
	*head = (*head)->next;
	free(p);
	return;
}

void del_end_sll(list *head){
	if(!(*head)){
		return;
	}
	node *p, *q;
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

void is_palindrome_sll(list *head){
	node *p;
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

void remove_duplicates_sll(list *head){
	//find greatest
	int big = 0;
	node *p;
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
	node *q;
	q = *head;
	p = p->next;

	while(p){
		if(arr[p->data] > 1){
			q = p->next;
		}
	}





}