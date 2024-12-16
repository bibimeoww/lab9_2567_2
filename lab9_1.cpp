#include<iostream>
#include<iomanip> //For using setw(), setprecision(), ...
using namespace std;

int main(){	
	double initialLoan, interestRate, paymentPeryear;

	cout << "Enter initial loan: ";
	cin >> initialLoan;

	cout << "Enter interest rate per year (%): ";
	cin >> interestRate;

	cout << "Enter amount you can pay per year: ";
	cin >> paymentPeryear;


	
	cout << setw(13) << left << "EndOfYear#"; 
	cout << setw(13) << left << "PrevBalance"; 
	cout << setw(13) << left << "Interest"; 
	cout << setw(13) << left << "Total";
	cout << setw(13) << left << "Payment";
	cout << setw(13) << left << "NewBalance";
	cout << "\n";

	cout << fixed << setprecision(2);

	double PrevBalance = initialLoan;
	int year = 1;

	while (PrevBalance > 0){
		double interest = (PrevBalance * interestRate)/ 100;
		double Total = PrevBalance + interest;
		double actualPayment = (PrevBalance + interest < paymentPeryear) ? PrevBalance + interest : paymentPeryear;
		double NewBalance = Total - actualPayment;

		cout << fixed << setprecision(2); 
		cout << setw(13) << left << year; 
		cout << setw(13) << left << PrevBalance;
		cout << setw(13) << left << interest;
		cout << setw(13) << left << Total;
		cout << setw(13) << left << actualPayment;
		cout << setw(13) << left << NewBalance;
		cout << "\n";	

		PrevBalance = (NewBalance > 0) ? NewBalance : 0;
        year++;
	}
	
	return 0;
}
