#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <time.h>
#include <vector>

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
	int GUARDDISTANCE = 10;		// d
	void findPlacement() {
		int paintinglocations[10];
		for (int i = 0; i < 10; i++) {
			paintinglocations[i] = rand() % 50 + 1;
		}
		int n = sizeof(paintinglocations) / sizeof(paintinglocations[0]);
		std::sort(paintinglocations, paintinglocations + n);
		std::vector<int> positions;
		positions.push_back(paintinglocations[0] + GUARDDISTANCE);
		int previous = 0;
		int nextposition = 1;
		for (int i = 1; i < 9; i++) {
			if (positions[previous] + GUARDDISTANCE < paintinglocations[nextposition]) {
				//we'll need another guard at the next painting
				positions.push_back(paintinglocations[nextposition]);
				previous++;
				nextposition++;
			}
			nextposition++;
			if (nextposition > 9) {
				break;
			}
		}
		std::cout << "###QUESTION 3###\n";
		std::cout << "For the following positions: \n";
		for (int i = 0; i < 10; i++) {
			std::cout << paintinglocations[i] << " ";
		}
		std::cout << "\nGuards should be positioned at the following locations: ";
		for (int i = 0; i < positions.size(); i++) {
			std::cout << positions[i] << " ";
		}
	}
}

namespace PrintingFlexes {
	/*
	You are planning to start a new business of printing flexes. In the first 
	step you have bought a printing machine. Every day you receive printing orders 
	from n different customers. Customer Ci’s job requires time ti. The wait time of 
	a customer Ci is wi which is the amount of time the customer waited till its job 
	completion. You have only one printing machine so you have to devise a schedule of 
	printing. You want your customers to be happy. The happiness of the customer is 
	dependent on the wait time. The smaller the wait time the happier your customer is. 
	Devise a schedule that minimizes the total wait time of all the n customers. Suppose 
	there are three customer with job time t1=4, t2=5, t3=2. If you schedule (1, 2, 3) 
	then w1=4, w2=9, w3=11 total wait time is 4+9+11=24
	*/
	int CUSTOMERCOUNT = 0;
	int TOTALTIME;
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
		std::cout << "\n###QUESTION 6###\n";
		std::cout << "The schedule for printing flexes is as follows: ";
		for (int i = 0; i < 10; i++) {
			customers[i].print();
		}
		int TOTALTIME = customers[0].getJobTime();
		for (int i = 1; i < 10; i++) {
			TOTALTIME += (TOTALTIME + customers[i].getJobTime());
		}
		std::cout << "\nThe total waiting for all customers is: " << TOTALTIME << std::endl;
	}
}

namespace Triathalon {
	/*
	Suppose you want to organize activities for some campers. This includes a triathalon 
	exercise: each contestant must swim 20 laps of a pool, then bike 10 miles, then run 3 
	miles. The contestants must use the pool one at a time. In other words, first one contestant 
	swims the 20 laps, gets out, and starts biking. As soon as this first person is out of the 
	pool, a second contestant begins swimming the 20 laps; as soon as he or she is out and starts 
	biking, a third contestant begins swimming . . . and so on. Each contestant has a projected 
	swimming time (the expected time it will take him or her to complete the 20 laps), a projected 
	biking time (the expected time it will take him or her to complete the 10 miles of bicycling), 
	and a projected running time (the time it will take him or her to complete the 3 miles of running). 
	You want to decide on a schedule for the triathalon: an order in which to sequence the starts of 
	the contestants. The completion time of a schedule is the earliest time at which all contestants 
	will be finished with all three legs of the triathalon, assuming they each spend exactly their 
	projected swimming, biking, and running times on the three parts. (Again, note that participants 
	can bike and run simultaneously, but at most one person can be in the pool at any time.) 
	What’s the best order for sending people out, if one wants the whole competition to be over 
	as early as possible?
	*/
	int RUNNERCOUNTER = 0;
	class Camper {
	private:
		int runningtime;
		int bikingtime;
		int swimmingtime;
		int position;
	public:
		Camper() {
			RUNNERCOUNTER++;
			runningtime = rand() % 20 + 1;
			bikingtime = rand() % 20 + 1;
			swimmingtime = rand() % 20 + 1;
			position = RUNNERCOUNTER;
		}
		void print() {

		}
	};
	void makeSchedule() {
		Camper campers[10];
	}
}

namespace TernaryHuffman {
	void encodeCharacters() {

	}
}

namespace COVID19 {
	void findValidSchedule() {

	}
}

int main() {
	srand(time(NULL));
	TernaryHuffman::encodeCharacters();		//Q2
	ArtGallery::findPlacement();			//Q3
	Triathalon::makeSchedule();				//Q4
	COVID19::findValidSchedule();			//Q5
	PrintingFlexes::makeSchedule();			//Q6
	CustomerPriority::makeSchedule();		//Q7
}