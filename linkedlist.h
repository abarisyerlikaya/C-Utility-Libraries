struct n{
	int data;
	struct n * next;
};
typedef struct n node;

void printList(node * head);

node * getNode(node * head, int index);

node * searchList(node * head, int keyData);

int nodeCount(node * head);

node * createNode(int data);

void addFront(node ** head, int newData);

void addAfter(node * prev, int newData);

void append(node * head, int newData);

void deleteNode(node ** head, node * element);

node * unlinkNode(node ** head, node * element);

void insertFront(node ** head, node * element);

void insertAfter(node * prev, node * element);

void moveFront(node ** head, node * element);

void moveAfter(node ** head, node * prev, node * element);

void sortList(node **head);

void sortListDsc(node **head);

void printList(node * head){	
	node * tmp;
	tmp = head;
	printf("[%d]",tmp->data);
	if(tmp->next != NULL){
		tmp = tmp->next;
		while(tmp != NULL){
			printf(" -> [%d]",tmp->data);
			tmp = tmp->next;
		}
	}
	printf("\n");
}

node * getNode(node * head, int index){
	int i = 0;
	node * tmp = head;
	while(i!=index && tmp!= NULL){
		tmp = tmp->next;
		i++;
	}
	return tmp;
}

node * searchList(node * head, int keyData){ 	
	node * tmp;
	tmp = head;
	while(tmp!=NULL){
		if(tmp->data == keyData)
			return tmp;
		tmp=tmp->next;
	}
	return NULL;
}

int nodeCount(node * head){
	node * tmp = head;
	int count = 0;
	while(tmp != NULL){
		count++;
		tmp = tmp->next;
	}
	return count;
}

node * createNode(int data){
	node * head = (node *)malloc(sizeof(node));
	head->data = data;
	head->next = NULL;
}

void addFront(node ** head, int newData){
	node * newNode = (node *)malloc(sizeof(node));
	newNode->data = newData;
	newNode->next = *head;
	*head = newNode;
}

void addAfter(node * prev, int newData){
	node * newNode = (node *)malloc(sizeof(node));
	newNode->data = newData;
	newNode->next = prev->next;
	prev->next = newNode;
}

void append(node * head, int newData){
	node * tail = head;
	while(tail->next != NULL){
		tail = tail->next;
	}
	tail->next = (node *)malloc(sizeof(node));
	tail->next->data = newData;
	tail->next->next = NULL;	
}

void deleteNode(node ** head, node * element){
	node * tmp = *head;
	if((*head) == element){
		*head = (*head)->next;
		free(tmp);
	}
	else{
		while(tmp->next != element && tmp != NULL){
			tmp = tmp->next;
		}
		if(tmp != NULL){
			node * prev = tmp;
			tmp = tmp->next;
			prev->next = tmp->next;
			free(tmp);
		}
	}
}

node * unlinkNode(node ** head, node * element){
	node * tmp = *head;
	if((*head) == element){
		*head = (*head)->next;
		tmp->next = NULL;
		return tmp;
	}
	else{
		while(tmp->next != element && tmp != NULL){
			tmp = tmp->next;
		}
		if(tmp != NULL){
			node * prev = tmp;
			tmp = tmp->next;
			prev->next = tmp->next;
			tmp->next = NULL;
			return tmp;
		}
	}
}

void insertFront(node ** head, node * element){
	element->next = *head;
	*head = element;
}

void insertAfter(node * prev, node * element){
	element->next = prev->next;
	prev->next = element;
}

void moveFront(node ** head, node * element){
	insertFront(head, unlinkNode(head, element));
}

void moveAfter(node ** head, node * prev, node * element){
	insertAfter(prev, unlinkNode(head, element));
}

void sortList(node **head){
    node *tmp, *tmp2;
    for(tmp=*head; tmp!=NULL; tmp=tmp->next){
    	for(tmp2 = tmp->next; tmp2 != NULL; tmp2=tmp2->next){ 
        	if(tmp2->data < tmp->data)
            	swap(&tmp->data, &tmp2->data);
        }
    }
}

void sortListDsc(node **head){
    node *tmp, *tmp2;
    for(tmp=*head; tmp!=NULL; tmp=tmp->next){
    	for(tmp2 = tmp->next; tmp2 != NULL; tmp2=tmp2->next){ 
        	if(tmp2->data > tmp->data)
            	swap(&tmp->data, &tmp2->data);
        }
    }
}
