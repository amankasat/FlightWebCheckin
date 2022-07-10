#include <iostream>
#include <string>
#include <algorithm>
#include <windows.h>
// #include<unistd.h> (linux version)
#include <iomanip>
using namespace std;

// ■
class Pnr
{
	public:
		string fname[4],lname[4], age[4], gender[4], pnr;
		int passengerCount;
		string randomString( size_t length )
		{
		    auto randChar = []() -> char
	    	{
	        	const char charSet[] = "0123456789";
		        const size_t maxIndex = (sizeof(charSet) - 1);
		        return charSet[ rand() % maxIndex ];
		    };
		    string str(length,0);
		    generate_n(str.begin(), length, randChar );
		    return str;
		}
		void setDetails()
		{
			for(int i=0;i<passengerCount;i++)
			{
				cout<<"Details of passenger number "<<(i+1)<<endl;
				cout<<"Enter First Name : ";
				cin>>fname[i];
				cout<<"Enter Last Name : ";
				cin>>lname[i];
				cout<<"Enter Age : ";
				cin>>age[i];
				cout<<"Enter Gender (M/F/N): ";
				cin>>gender[i];
			}
		}


		Pnr(int n)
		{
			passengerCount=n;	
		}
		Pnr()
		{
			passengerCount=0;	
		}
		void start()
		{
			setDetails();
			pnr=randomString(5);
		}
		string getPnr()
		{
			return pnr;
		}
};


class Plane
{
	public:
	const static int ROWS = 6;
	const static int COLS = 10;
	string seats[ROWS][COLS];
	const static int num_seats = 10;
	int x[num_seats][2];
	string s[4];

	void generatePlane() {
		for (int i = 0; i < ROWS; i++) {
			for (int j = 0; j < COLS; j++) {
				seats[i][j] = "□";
			}
		}
	}

	void randomSeats(){
		srand(time(0));
		for(int i = 0; i < num_seats; i++){		
			int t1 = rand() % ROWS ;
			int t2 = rand() % COLS ;
			//int t1=0, t2=0;
			
			seats[t1][t2] = "■";
		}
	}

	void bookSeats(int num_p)
	{
		for (int i = 0; i < num_p; i++)
		{ 	
			
			cout<<"\nEnter seat number for passenger number "<<i+1<<" in the correct format; example-A1"<<endl;
			cin>>s[i];
			int row = s[i][0]-65;
			int col = stoi(s[i].substr(1,2))-1;
			if (!(col>=0 && col<COLS && row>=0 && row<ROWS)){
				cout<<"Seat does not exist, try again"<<endl;
				i--;
				continue;
			}
			if(seats[row][col] == "■"){
				i--;
				cout<<"Seat already booked :<"<<endl;
				continue;
			}
			else{
				seats[row][col] = "■";
			}
		}	
	}	


	void displayPlane() {
		/**
		 * @brief prints the cabin of the plane with appropriate formatting
		 * 		  and booking of seats
		 */

		char tempChar = 'A';
		for (int i = 0; i < ROWS; i++) {
			if(i == 0)	  // for first row numbers
				cout << ". 1 2 3 | 4 5 6 7 8 9 10"<<endl;
			if(i==ROWS/2) // for aisle gap of 2 rows
				cout<<"\n\n";
			for (int j = 0; j < COLS; j++) {	
				if (j == 0) // for alphabets in first column
					cout << (tempChar++) << " ";
				if (j == 3) // for division between business and economy
					cout << "| ";
				cout << seats[i][j] << " "; // IMP printing seats with a space
			}
			cout<<endl; // next line after an entire row
		}
		cout << "Business    Economy"<<endl;
	}
};



int main() {
	int passengerCount=5;
	cout<<"Enter the number of Passengers (upto 4) ";
	cin>>passengerCount;

	Pnr p(passengerCount);
	p.start();
	
	cout<<"Directing you to web check in\n\n";
	
	Sleep(2000);
	// usleep(2000);

	Plane p1;
	p1.generatePlane();

	p1.randomSeats();

	p1.displayPlane();

	p1.bookSeats(passengerCount);

	p1.displayPlane();

	cout<<"\nCongratulations! Your seats are booked.\n\n\n";


	cout<<left<< setw(13)<< "First Name"<< left<< setw(13)<< "Last Name"<< left<< setw(5)<< "Age"<< left<< setw(6)<< "Gender"<<left<< setw(6)<< "Seat No."<< endl;
	for (int i = 0; i < 4; i++)
    {
    	cout<< left<< setw(13)<<p.fname[i]<< left<< setw(13)<< p.lname[i]<< left<< setw(5)<<p.age[i]<< left<< setw(6)<<p.gender[i]<< left<< setw(6)<<p1.s[i]<<endl;
    }
	cout<<"\n\nYour PNR is : "<<p.getPnr()<<endl;
	return 0;
}