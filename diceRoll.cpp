#include <iostream>
#include <stdlib.h>
#include <string>
#include <cmath>
#include <ctime>
using namespace std;

int main () {
	srand(time(0)); /*holds time so random numbers are continuously different*/

	int r1, r2, r3, sum, player=0, cpu=0, roundnum=1;
	char yesORno;
	int ones_count=0;  //keep track of 1 occurring in rolling of die//

	while(player<150&&cpu<150) {
		//manipulates rolling of dice using rand nums
		yesORno = 'n';
		while(yesORno == 'n'){
			ones_count = 0;
			r1 = rand()%6 + 1;
		    r2 = rand()%6 + 1;
		    r3 = rand()%6 + 1;
			sum = r1+r2+r3;
		    cout << "Rolled " << r1 << ", " << r2 << ", " << r3 << endl;
		    cout << "Sum = " << r1 + r2 + r3 << endl;

			   if (r1==1)
			       ones_count++;
			   if (r2==1)
			       ones_count++;
			   if (r3==1)
			       ones_count++;

			   if(ones_count==0) {

				   do { //if user enters something other than y/n
					   cout << "Bank? (y/n) ";
					   cin >> yesORno;
				   } while (yesORno != 'y' && yesORno != 'n');

				   if(yesORno=='y') {
					  player+=sum;
				   }
		   		}
				// if player rolls any 1's
			   else if(ones_count==1){
				   cout<<"Lose a turn"<<endl<<endl;
				   yesORno = 'y';
			   }
			   else if(ones_count==2){
				   cout<<"Lose a turn and half of sum"<<endl<<endl;
				   player/=2;
				   yesORno = 'y';

			   }
			   else if(ones_count==3){
				   cout<<"Lose a turn and current sum"<<endl<<endl;
				   player=0;
				   yesORno = 'y';
			   }
		   }
		   //cpu turn // -----------------------------------------------------
		   cout<<"Computer's turn"<<endl;
		   yesORno = 'n';
		   while(yesORno == 'n'){
   			ones_count = 0;
   			r1 = rand()%6 + 1; r2 = rand()%6 + 1; r3 = rand()%6 + 1;
   			sum = r1+r2+r3;
   		    cout << "Rolled " << r1 << ", " << r2 << ", " << r3 << endl;

   			   if (r1==1)
   			       ones_count++;
   			   if (r2==1)
   			       ones_count++;
   			   if (r3==1)
   			       ones_count++;

   			   if(ones_count==0) {
				   cout << "Sum = " << r1 + r2 + r3;
				   if(sum>=10){ //intelligence to 'bid' for higher sum
					   yesORno='y';
					   cpu+=sum;
					   cout<<" bank"<<endl;

				   }else{
					   cout<<" no bank"<<endl;
				   }
			   }
   				// if cpu gets a 1
   			   else if(ones_count==1){
   				   cout<<"Lose a turn"<<endl;
				   yesORno = 'y';

   			   }
   			   else if(ones_count==2){
   				   cout<<"Lose a turn and half of sum"<<endl;
   				   cpu/=2;
				   yesORno = 'y';

   			   }
   			   else if(ones_count==3){
   				   cout<<"Lose a turn and current sum"<<endl;
   				   cpu=0;
				   yesORno = 'y';
   			   }
   		   }
	   		cout<<"After round "<<roundnum<<" human has "<<player<<" and computer has "<<cpu<<endl;
			roundnum++;
			cout<<endl;

			if(player>=150){
				cout<<" Player Won";
				cout<<endl;
			}
			else if(cpu>=150){
				cout<<"Computer Won";
				cout<<endl;
			}
	 }
	 return 0;
}


