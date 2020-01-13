#include <iostream>
#include <string>
using namespace std;

int main(){
	int dur, deprecRec, month, prevMonth = 0;
	double downpay,  amLoan, perDeprec, monthlyRate = 0, remain = 0, last_perDeprec;
	while(cin >> dur >> downpay >> amLoan >> deprecRec && dur > 0){
		monthlyRate = amLoan / dur;
		remain = amLoan;
		amLoan += downpay;
		prevMonth = 1;//month 0 always present
		cin >> month;
		cin >> perDeprec;
		last_perDeprec = perDeprec;
		amLoan = amLoan * (1 - perDeprec);
		while(--deprecRec > 0){
			cin >> month;
			cin >> perDeprec;
			while(remain >= amLoan &&  prevMonth++ < month){
				amLoan = amLoan * (1 - last_perDeprec);
				remain -= monthlyRate;
			}
			if(remain >= amLoan){
				prevMonth = month;
			}
			last_perDeprec = perDeprec;
		}
		while(remain >= amLoan && prevMonth++ <= dur){
			amLoan = amLoan * (1 - perDeprec);
			remain -= monthlyRate;
		}
		//cout << remain << ' ' << amLoan << ' ';
		cout << --prevMonth << " month";
		if(prevMonth > 1) cout << "s" << endl;
		else cout << endl;
	}
}
/*
int loanDur, nRec;
	double downPayment, loan, decP[101];

	while (true) {
		cin >> loanDur >> downPayment >> loan >> nRec;
		if (loanDur < 0)
			break;

		int m;
		double p;
		while (nRec--) {
			cin >> m >> p;
			for (int i = m; i < 101; i++)
				decP[i] = p;
		}
*/
