//cust.h
//Aaron Nicanor
//anicanor
#ifndef CUST_H_
#define CUST_H_
#include<iostream>

using namespace std;

class Cust{
	
	public:
    	Cust(string, bool, int, int);
    	void print(ostream &);
    	bool is_robber();
    	int numItems();
    	int arrivalTime();
    	void printEntered(ostream &, int);
    	void printFinishedShopping(ostream &, int);
    	void printFinishedCheckout(ostream &, int, int, int);
    	void printBeginCheckout(ostream &, int, int);
	
	private:
    	string m_name;
    	bool m_isRobber;
    	int m_arrivalTime;
    	int m_numItems;
};
#endif

