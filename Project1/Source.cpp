#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <time.h>

namespace CustomerPriority {
	/*
	Suppose that in Problem 6, you have prioritize your customers i.e. each 
	customer Ci also has a priority pi that represents his/her importance. 
	So now you want to find a schedule that minimizes the weighted sum of waiting 
	time based on customer priority.
	*/
	int CUSTOMER_COUNT = 0;
	class Customer {
	private:
		double priority;
		double waitingtime;
		double ratio;
		int queueposition;
	public:
		Customer() {
			priority = rand() % 10 + 1;
			waitingtime = rand() % 10 + 1;
			ratio = waitingtime / priority;
			CUSTOMER_COUNT++;
			queueposition = CUSTOMER_COUNT;
		}
		void print() {
			std::cout << this->queueposition << " ";
		}
		double getRatio() {
			return ratio;
		}
	};
	bool compareRatios(Customer c1, Customer c2) {
		return (c1.getRatio() > c2.getRatio());
	}
	void makeSchedule() {
		Customer customers[10];
		int n = sizeof(customers) / sizeof(customers[0]);
		std::sort(customers, customers + n, compareRatios);
		std::cout << "###QUESTION 7###\n";
		std::cout << "The schedule printing schedule is as follows: ";
		for (int i = 0; i < 10; i++) {
			customers[i].print();
		}
		std::cout << "\nEach number signifies the relative position of a person in the queue.\n";
	}

}

namespace ArtGallery {
	/*
	Suppose there is an art gallery in form of a straight long hall. You are given 
	an ordered set P= {p1, p2, …, pn} of real numbers that represent the positions of 
	precious paintings or sculptures in this hallway. A guard can protect all the objects 
	that comes within d distance on his left and right.Design an algorithm for finding a placements 
	of guards that uses the minimum number of guards to guard all the objects with positions in P.
	*/
	int GUARDDISTANCE = 2;		// d
	void findPlacement() {
		for (int i = 0; i < 10; i++) {
		int paintinglocations[10];
			paintinglocations[i] = rand() % 10 + 1;
		}
	}
}

namespace PrintingFlexes {
	/*You are planning to start a new business of printing flexes. In the first 
	step you have bought a printing machine. Every day you receive printing orders 
	from n different customers. Customer Ci’s job requires time ti. The wait time of 
	a customer Ci is wi which is the amount of time the customer waited till its job 
	completion. You have only one printing machine so you have to devise a schedule of 
	printing. You want your customers to be happy. The happiness of the customer is 
	dependent on the wait time. The smaller the wait time the happier your customer is. 
	Devise a schedule that minimizes the total wait time of all the n customers. Suppose 
	there are three customer with job time t1=4, t2=5, t3=2. If you schedule (1, 2, 3) 
	then w1=4, w2=9, w3=11 total wait time is 4+9+11=24*/
	int CUSTOMERCOUNT = 0;
	class Customer {
	private:
		int position;
		int jobtime;
	public:
		Customer() {
			CUSTOMERCOUNT++;
			jobtime = rand() % 100 + 1;
			position = CUSTOMERCOUNT;
		}
		int getJobTime() {
			return this->jobtime;
		}
		void print() {
			std::cout << position << " ";
		}
	};
	bool compareWaitingTimes(Customer c1, Customer c2) {
		return c1.getJobTime() < c2.getJobTime();
	}
	void makeSchedule() {
		Customer customers[10];
		int n = sizeof(customers) / sizeof(customers[0]);
		std::sort(customers, customers + n, compareWaitingTimes);
		std::cout << "###QUESTION 6###\n";
		std::cout << "The schedule for printing flexes is as follows: ";
		for (int i = 0; i < 10; i++) {
			customers[i].print();
		}
		int totaltime = customers[0].getJobTime();
		for (int i = 1; i < 10; i++) {
			totaltime += (totaltime + customers[i].getJobTime());
		}
		std::cout << "\nThe total waiting for all customers is: " << totaltime << std::endl;
	}
}

int main() {
	srand(time(NULL));
	PrintingFlexes::makeSchedule();			//Q6
	CustomerPriority::makeSchedule();		//Q7
	ArtGallery::findPlacement();			//Q3
}