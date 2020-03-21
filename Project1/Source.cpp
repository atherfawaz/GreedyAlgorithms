#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <time.h>

namespace CustomerPriority_Q7 {
	int CUSTOMER_COUNT = 0;
	/*
	Suppose that in Problem 6, you have prioritize your customers i.e. each customer Ci also has a priority pi
	that represents his/her importance. So now you want to find a schedule that minimizes the weighted sum of
	waiting time based on customer priority. Specifically you want to minimize ∑ wipi
	*/
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
		std::cout << "The schedule is as follows: ";
		for (int i = 0; i < 10; i++) {
			customers[i].print();
		}
		std::cout << "\nEach number signifies the relative position of a person in the queue.\n";
	}

}

int main() {
	srand(time(NULL));
	CustomerPriority_Q7::makeSchedule();
}