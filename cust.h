//cust.h
//Aaron Nicanor
//anicanor
#ifndef CUST_H_
#define CUST_H_

#include<iostream>

using namespace std;

class Cust{

	public:
    	Cust(string,bool,int,int);
    	void print(ostream &);
    	bool m_isRobber;
      
	private:
    	string m_name;
      int m_num_items;
    	int m_arrival_time;
    	
    	
};

#endif
