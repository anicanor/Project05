//pqueue.cpp
//Aaron Nicanor
//anicanor
#include"pqueue.h"
#include"cust.h"
#include<assert.h>

Pqueue::Pqueue(){

	pqueue_head = NULL;
}

Pqueue::~Pqueue(){

	Node *ptr = pqueue_head;
	while (ptr != NULL){
  
    	Node *temp;
    	temp = ptr;
    	ptr = ptr->pqueue_next;
    	delete temp->pqueue_cust;
    	delete temp;

	}
}

int Pqueue::first_priority(){

	if (empty()) return -1;
  
	int first_priority = pqueue_head->pqueue_priority;
	return first_priority;
}

int Pqueue::length(){

	int pqueue_length = 0;
	Node *ptr = pqueue_head;
	while (ptr != NULL){
  
    	ptr = ptr->pqueue_next;
    	pqueue_length++;
	}
	return pqueue_length;
}

void Pqueue::enqueue(Cust *cust, int priority){

	if (pqueue_head == NULL || priority < pqueue_head->pqueue_priority)
    	pqueue_head = new Node(cust,pqueue_head,priority);
	else{
  
    	Node *ptr = pqueue_head;
    	while (priority >= ptr->pqueue_next->pqueue_priority && ptr->pqueue_next != NULL)
        	ptr = ptr->pqueue_next;
    	
    	assert (ptr != NULL);

    	if (ptr->pqueue_next == NULL){
      
        	ptr->pqueue_next = new Node(cust,NULL,priority);
    	}
    	else{
      
        	Node *temp = ptr->pqueue_next;
        	ptr->pqueue_next = new Node(cust,temp,priority);
    	}
	}
}

Cust *Pqueue::dequeue(){

	if (empty())
    	return NULL;

	Node *tmp;
	Cust *tmp_cust;
	tmp_cust = pqueue_head->pqueue_cust;
	tmp = pqueue_head;
	pqueue_head = tmp->pqueue_next;
	delete tmp;
	return tmp_cust;

}


bool Pqueue::empty(){

	if (pqueue_head == NULL)
	return true;
	else if	return false;
}
