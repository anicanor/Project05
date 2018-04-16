//cust.cpp
//Aaron Nicanor
//anicanor
#include"cust.h"

//Constructor
Cust::Cust(string name,bool isRobber,int arrival_time,int num_items){

	m_name = name;
	m_isRobber = isRobber;
	m_arrival_time = arrival_time;
	m_num_items = num_items;
}

//Print values out onto the screen
void Cust::print(ostream &os){

	os << m_name << " ";
  //Determines if customer is a robber or a shopper
	if (m_isRobber)
	os << "robber ";
	else
	os << "shopper ";
  
	os << m_arrival_time << " ";
	os << m_num_items << endl;
}
