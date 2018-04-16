//pqueue.h
//Aaron Nicanor
//anicanor
#ifndef PQUEUE_H_
#define PQUEUE_H_

#include<iostream>
#include<string>

#include"cust.h"

using namespace std;
class Pqueue{
	
	public:
    	Pqueue();
    	~Pqueue();
    	Cust *dequeue();
    	void enqueue(Cust *, int);
    	bool dequeue(int &);
    	bool empty();
    	void print();
    	int priorityOne();
    	int length();
	
	private:
	//Node class
    	class Node{
		
        	public:
            	Node(Cust *cust, Node *next, int priority){
			pqueue_cust = cust;
			pqueue_next = next;
			pqueue_priority = priority;
		}
		
            	Cust *pqueue_cust;
            	Node *pqueue_next;
            	int pqueue_priority;
    	};
    	Node *pqueue_head = NULL;
 };
 #endif
