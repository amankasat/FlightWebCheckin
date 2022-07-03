/*Ok so having a ticket before you check in is important. So try making something which makes a booking/ticket
It should take:
Number of passengers
And then a loop to get their details:- f name, last name, age, gender
Pnr should be linked to that ticket. So i should be able to access all details using that number
*/

#include<iostream>
#include <algorithm>
using namespace std;
class Pnr
{
	private:
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
				cin>>fname[0];
				cout<<"Enter Last Name : ";
				cin>>lname[0];
				cout<<"Enter Age : ";
				cin>>age[0];
				cout<<"Enter Gender (M/F/N): ";
				cin>>gender[0];
			}
		}

	public:
		Pnr(int n)
		{
			passengerCount=n;	
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

int main()
{
	int passengerCount=5;
	cout<<"Enter the number of Passengers (upto 4)";
	cin>>passengerCount;
	while(passengerCount>4)
	{
		cout<<"Enter the number of Passengers (upto 4)";
		cin>>passengerCount;
	}
	Pnr p(passengerCount);
	p.start();
	cout<<"Your PNR is : "<<p.getPnr();

	return 0;
}