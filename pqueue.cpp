//pqueue.cpp
//Aaron Nicanor
//anicanor

#include"pqueue.h"
#include"cust.h"
#include<assert.h>

//Constructor
Pqueue::Pqueue(){
	
	pqueue_head = NULL;
}

//Deconstructor
Pqueue::~Pqueue(){
	
	Node *ptr = pqueue_head;
	while(ptr != NULL){

    		Node *temp;
    		temp = ptr;
    		ptr = ptr->pqueue_next;
    		delete temp->pqueue_cust;
    		delete temp;
	}
}

//Adds element to queue
void Pqueue::enqueue(Cust *cust, int priority){
	
	if(pqueue_head == NULL || priority < pqueue_head->pqueue_priority)
    		pqueue_head = new Node(cust, pqueue_head, priority);
	else{
		
    		Node *ptr = pqueue_head;
    		while(ptr->pqueue_next != NULL && priority >= ptr->pqueue_next->pqueue_priority){
		
       			ptr = ptr->pqueue_next;
    		}
    		assert(ptr != NULL);
    		if(ptr ->pqueue_next == NULL)	
        		ptr->pqueue_next = new Node(cust, NULL, priority);
    		else{
		
        		Node *temp = ptr->pqueue_next;
        		ptr->pqueue_next = new Node(cust,temp,priority);
    		}
	}
}

//Removes element from queue
Cust *Pqueue::dequeue(){
	
	if(empty())
    		return NULL;
	
	Node *temp;
	Cust *temp_cust;
	temp_cust = pqueue_head->pqueue_cust;
	temp = pqueue_head;
	pqueue_head = temp->pqueue_next;
	delete temp;
	return temp_cust;
}

//Checks if empty
bool Pqueue::empty(){
	return (pqueue_head == NULL);
}

//Finds and returns the length of the queue
int Pqueue::length(){
	
	int pqLength = 0;
	Node * ptr = pqueue_head;
	while (ptr != NULL){
		
    		ptr = ptr->pqueue_next;
    		pqLength++;
	}
	
	return pqLength;
}

//Gets the priority of the first element
int Pqueue::priorityOne(){
	
	if(empty())
    		return -1;

	int priorityOne = pqueue_head->pqueue_priority;
    	return priorityOne;
}
