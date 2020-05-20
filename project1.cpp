#include<iostream>
#include<string.h>
using namespace std;
class bus_reservation
{
	string bus_no, driver,arrival_time,departure_time,from,destination,seats[8][4];
	public:
		void add_bus();
		void reserve();
		void display();
		void initial();
		void availability();
		void cancellation();
}bus[15];
static int c=0;
void line()
{
	for(int i=0;i<100;i++)
	{
		cout<<"_";
	}
}
void bus_reservation::add_bus()
{
	cout<<"\nEnter bus no:\t";
	cin>>bus_no;
	cout<<"\nEnter Driver's name:\t";
	cin>>driver;
	cout<<"\nEnter Arrival Time:\t";
	cin>>arrival_time;
	cout<<"\nEnter Departure Time:\t";
	cin>>departure_time;
	cout<<"\nEnter From:\t";
	cin>>from;
	cout<<"\nEnter Destination:\t";
	cin>>destination;
	initial();
	c++;
}
void bus_reservation::reserve()
{
	
	string x;
	int num;
	top:
	cout<<"\nEnter Bus No.:\t";
	cin>>x;
	
	for(num=0;num<=c;num++)
	{
		if(bus[num].bus_no==x)
		{
			break;
		}
	}
	if(num>c)
	{
		cout<<"\nEnter correct Bus no.";
		goto top;
	}
	else
	{
		while(true)
		{
			cout<<"\nEnter Seat No.:\t";
			int seat;
			cin>>seat;
			if (seat>32)
			{
				cout<<"The total number of seats in the bus is only 32.";
			}
			else 
			{
				if(bus[num].seats[seat/4][(seat%4)-1]=="Empty")
				{
					string name;
					cout<<"\nEnter name of the passenger:\t";
					cin>>name;
					bus[num].seats[seat/4][(seat%4)-1]=name;
					break;
				}
				else
				{
					cout<<"\nThat seat is unavailable.";
				}
			}
		}
		
	}
}

void bus_reservation::initial()
{
	for(int i=0;i<8;i++)
	{
		for (int j=0;j<4;j++)
		{
			seats[i][j]="Empty";
		}
	}
}
void bus_reservation::display()
{
	string x;
	int num;
	top:
	cout<<"\nEnter Bus No:\t";
	cin>>x;
	for(num=0;num<=c;num++)
	{
		if(x==bus[num].bus_no)
		{
			break;
		}
	}
	if(num>c)
	{
		cout<<"\nEnter correct Bus no.";
		goto top;
	}
	else
	{
		line();
		cout<<"\n\nEnter Bus No:\t"<<bus[num].bus_no
		<<"\tDriver's Name:\t"<<bus[num].driver
		<<"\tArrival Time:\t"<<arrival_time
		<<"\nDeparture Time:\t"<<departure_time
		<<"\tFrom:\t"<<from
		<<"\tDestination:\t"<<destination<<"\n";
		line();
		cout<<"\n";
		for(int i=0;i<8;i++)
		{
			for(int j=0;j<4;j++)
			{
				cout<<((i*4)+j+1)<<". "<<bus[num].seats[i][j]<<"\t";
			}
			cout<<"\n";
		}
	}
}
void bus_reservation::availability()
{
	for (int i=0;i<c;i++)
	{
		int av=0;
		for(int j=0;j<8;j++)
		{
			for(int k=0;k<4;k++)
			{
				if(bus[i].seats[j][k]=="Empty")
				{
					av++;
				}
			}
		}
		cout<<"\nBus No. "<<bus[i].bus_no<<" has"<<av<<" empty seats.\n";
	}
}
void bus_reservation::cancellation()
{
	string x;
	int num;
	top:
	cout<<"\nEnter Bus No.:\t";
	cin>>x;
	
	for(num=0;num<=c;num++)
	{
		if(bus[num].bus_no==x)
		{
			break;
		}
	}
	if(num>c)
	{
		cout<<"\nEnter correct Bus no.";
		goto top;
	}
	else
	{
		cout<<"\nEnter Name of the passenger and Seat No.: \t";
		string name;
		int seat;
		cin>>name>>seat;
		if(bus[num].seats[seat/4][(seat%4)-1]!="Empty")
		{
			if(bus[num].seats[seat/4][(seat%4)-1]==name)
			{
				bus[num].seats[seat/4][(seat%4)-1]="Empty";
			}
			else
			{
				cout<<"\nThis seat is not reserved in "<<name<<"'s name.";
			}
		}
		else
		{
			cout<<"\nTHIS SEAT IS NOT RESERVED. IT IS EMPTY!";
		}
		
	}
}
int main()
{

	while(true)
	{
		int ch;
		cout<<"\n\t\t\t\tEnter:\n\t\t\t\t\t1-Add Bus.\n\t\t\t\t\t2-Reservation\n\t\t\t\t\t3-Display.\n\t\t\t\t\t4-Buses Available.\n\t\t\t\t\t5-Cancellation.\n\t\t\t\t\t6-Exit.\n\t\t\t\t\tYour Choice:-";
		cin>>ch;
		switch(ch)
		{
			case 1:
				bus[c].add_bus();
				break;
			case 2:
				bus[c].reserve();
				break;
			case 3:
				bus[0].display();
				break;
			case 4:
				bus[0].availability();
				break;
			case 5:
				bus[0].cancellation();
				break;
			case 6:
				exit(0);
		}
	}
	return 1;
}
