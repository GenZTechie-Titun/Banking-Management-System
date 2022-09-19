#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<ctime>
using namespace std;
class Banking
{
	private:
		char name[20],fname[20],nom[20],adhr[20],pan[20],atype[10],dob[20];
		char gen[10],cn[15],eid[30],ads[30],city[20],dist[20],pin[10],o[20];
		long int app_no,act_no,in_amt,net_amt;
		float t_net;
		int fd_no,month;
		double fd_amt,rate,m_amt,interest;
		int emid;
    	char ename[20],egen[10],ecno[15],edob[15],ebg[5],ed[10],email[25];
	public:
		void add();
		void search();
		void display();
		void modify();
		void trans();
		void withdrawal();
		void deposit();
		void bal_enq();
		void del();
		void fd();
		void fd_create();
		void fd_display();
		void fd_delete();
		void add1();
		void search1();
		void display1();
		void modify1();
		void del1();
		void salary();
}b,e,f;

void Banking::add()
{ 
    system("cls");
    cout<<"\t\t\t===================NEW BANK ACCOUNT DETAILS====================\n\n";
    cout<<"\t\t\t\t\t\t";
	cout<<" Date- "<<__DATE__<<"\t"<<" Time- "<<__TIME__<<"\n\n";
    ofstream ofs("bank.txt",ios::app);
    cout<<"\n1- Enter Applicant Number: ";
    cin>>app_no;
    cout<<"\n2- Enter Account Number: ";
    cin>>act_no;
    cout<<"\n3- Enter Account Holder Name: ";
    fflush(stdin);
	gets(name);
    cout<<"\n4- Enter Father's Name: ";
    gets(fname);
    cout<<"\n5- Enter Nominee Name: ";
    gets(nom);
    cout<<"\n6- Enter AADHAR Number: ";
    gets(adhr);
    cout<<"\n7- Enter PAN Number: ";
    gets(pan);
	cout<<"\n8- Account Type(Savings/Current): ";
	gets(atype);
    cout<<"\n9- Date of Birth: ";
    gets(dob);
    cout<<"\n10- Gender: ";
    gets(gen);
    cout<<"\n11- Contact Number: ";
    gets(cn);
    cout<<"\n12- Email ID: ";
    gets(eid);
    cout<<"\n13- Enter Address: ";
    gets(ads);
    cout<<"\n14- Enter City: ";
    gets(city); 
    cout<<"\n15- Enter District: ";
    gets(dist);
    cout<<"\n16- Enter Pincode: ";
	gets(pin);
    cout<<"\n17- Enter Occupation: ";
    gets(o);
	cout<<"\n    Enter Initial Amount: Rs. ";	
	cin>>in_amt;
	net_amt=in_amt;
    ofs.write((char *)&b,sizeof(Banking));
    cout<<"\n\nCongratulations!! \nAccount opened Successfully....";
    ofs.close();
} 

void Banking::search()
{
	int ch_1,act_no1,flag=0; 
	system("cls");
	cout<<"\t\t\t====================SEARCH RECORD SECTION=====================\n\n";
    cout<<"\t\t\t\t\t\t";
	cout<<"Date- "<<__DATE__<<"\t"<<"Time- "<<__TIME__<<"\n\n";
	ifstream ifs("bank.txt");
	if(!ifs)
	{
		cout<<"\nFile not found";
		getch();
		exit(0);
	}
		cout<<"\nSearch using Account Number\n\n";
		cout<<"\nEnter Account Number: ";
		cin>>act_no1;
		while(ifs.read((char*)&b,sizeof(Banking)))
		{
			if(act_no==act_no1)
			{
				cout<<"\nAccount Number:\t\t\t\t"<<act_no;
				cout<<"\nAccount Holder Name:\t\t\t"<<name;
				cout<<"\nFather's Name:\t\t\t\t"<<fname;
				cout<<"\nNominee Name:\t\t\t\t"<<nom;			
				cout<<"\nAADHAR Number:\t\t\t\t"<<adhr;						
				cout<<"\nPAN Number:\t\t\t\t"<<pan;						
				cout<<"\nAccount Type(Savings/Current):\t\t"<<atype;
				cout<<"\nDate of Birth:\t\t\t\t"<<dob;
				cout<<"\nGender:\t\t\t\t\t"<<gen;
				cout<<"\nContact Number:\t\t\t\t"<<cn;
				cout<<"\nEmail Id:\t\t\t\t"<<eid;
				cout<<"\nAddress:\t\t\t\t"<<ads<<"\nCity:\t\t\t\t\t"<<city;
				cout<<"\nDistrict:\t\t\t\t"<<dist<<"\nPincode:\t\t\t\t"<<pin;
				cout<<"\nOccupation:\t\t\t\t"<<o;
				cout<<"\nOpening Account Balance:\t\tRs."<<in_amt;
				cout<<"\nRemaining Account Balance:\t\tRs."<<net_amt;
				flag=1;
			}
		}
	if(flag==0)
	{
		cout<<"\nRecord Details not found..!!\nPlease Try Again......";
	}
	ifs.close();
}

void Banking::display()
{
	system("cls");
	cout<<"\t\t\t=====================DISPLAY ALL CUSTOMER DETAILS=====================\n\n";
    cout<<"\t\t\t\t\t\t\t";
	cout<<"Date- "<<__DATE__<<"\t"<<"Time- "<<__TIME__<<"\n\n";
	ifstream ifs("bank.txt");
	if(!ifs)
	{
		cout<<"\nRecord File not found......!!";
		cout<<"\n\nPress any Button to Exit....";
		exit(0);
	}
	while(ifs.read((char*)&b,sizeof(Banking)))
	{
	    cout<<"\n------------------------------------";
	    cout<<"\nApplicant Number:\t\t\t"<<app_no;
	    cout<<"\nAccount Number:\t\t\t\t"<<act_no;
		cout<<"\nAccount Holder Name:\t\t\t"<<name;
		cout<<"\nFather's Name:\t\t\t\t"<<fname;
		cout<<"\nNominee Name:\t\t\t\t"<<nom;			
		cout<<"\nAADHAR Number:\t\t\t\t"<<adhr;						
		cout<<"\nPAN Number:\t\t\t\t"<<pan;						
		cout<<"\nAccount Type(Savings/Current):\t\t"<<atype;
		cout<<"\nDate of Birth:\t\t\t\t"<<dob;
		cout<<"\nGender:\t\t\t\t\t"<<gen;
		cout<<"\nContact Number:\t\t\t\t"<<cn;
		cout<<"\nEmail Id:\t\t\t\t"<<eid;
		cout<<"\nAddress:\t\t\t\t"<<ads<<"\nCity:\t\t\t\t\t"<<city;
		cout<<"\nDistrict:\t\t\t\t"<<dist<<"\nPincode:\t\t\t\t"<<pin;
		cout<<"\nOccupation:\t\t\t\t"<<o;
		cout<<"\nOpening Account Balance:\t\tRs."<<in_amt;
		cout<<"\nRemaining Account Balance:\t\tRs."<<net_amt;
		cout<<"\n------------------------------------";
		getch();
	}
	ifs.close();
}

void Banking::modify()
{
	system("cls");
	int act_no2,ch_2,flag=0;
	cout<<"\t\t\t=====================ACCOUNT MODIFICATION SECTION=====================\n\n";
    cout<<"\t\t\t\t\t\t\t";
	cout<<"Date- "<<__DATE__<<"\t"<<"Time- "<<__TIME__<<"\n\n";
	ofstream ofs("temp.txt");
	ifstream ifs("bank.txt");
	if(!ifs)
	{
		cout<<"\nFile not found";
		getch();
		exit(0);
	}
			cout<<"\nSearch using Account Number\n\n";
			cout<<"\nEnter Account Number: ";
			cin>>act_no2;
		while(ifs.read((char*)&b,sizeof(Banking)))
		{
			if(act_no==act_no2)
			{
				flag=1;
				cout<<"\nAccount Holder Name:\t"<<name;
				cout<<"\n\nChoose Option to Modify:";
				cout<<"\n1- Account Number:";
				cout<<"\n2- Account Holder Name:";
				cout<<"\n3- Father's Name:";
				cout<<"\n4- Nominee Name:";			
				cout<<"\n5- AADHAR Number:";						
				cout<<"\n6- PAN Number:";						
				cout<<"\n7- Account Type(Savings/Current):";
				cout<<"\n8- Date of Birth:";
				cout<<"\n9- Gender:";
				cout<<"\n10- Contact Number:";
				cout<<"\n11- Email Id:";
				cout<<"\n12- Address:"<<"\n13- City:";
				cout<<"\n14- District:"<<"\n15- Pincode:";
				cout<<"\n16- Occupation:";
				cout<<"\nEnter your choice(1-16): ";
				cin>>ch_2;
				fflush(stdin);
				switch(ch_2)
				{
					case 1: cout<<"\nEnter new Account Number: ";
             	    	   	cin>>act_no;
             	          	break;
             		case 2: cout<<"\nModify Account Holder Name: ";
							gets(name);
	            	        break;
            		case 3: cout<<"\nModify Father's Name: ";
                        	gets(fname);
                        	break;
              		case 4: cout<<"\nModify Nominee Name: ";
                        	gets(nom);
                        	break;
             		case 5: cout<<"\nModify AADHAR Number: ";
                        	gets(adhr);
                        	break;
             		case 6: cout<<"\nModify PAN Number: ";
                       		gets(pan);
							break; 
        			case 7: cout<<"\nChange Account Type(Savings/Current): ";
	                    	gets(atype);
	                    	break;
            		case 8: cout<<"\nModify Date of Birth: ";
                        	gets(dob);
                        	break;
                	case 9: cout<<"\nChange Gender: ";
                        	gets(gen);
                        	break;
                	case 10:cout<<"\nModify Contact Number: ";
                        	gets(cn);
                        	break;
              		case 11:cout<<"\nModify Email ID: ";
                        	gets(eid);
                        	break;
              		case 12:cout<<"\nEnter new Address: ";
                        	gets(ads);
                        	break;
            		case 13:cout<<"\nEnter new City: ";
                    	    gets(city); 
                        	break;
                	case 14:cout<<"\nEnter new District: ";
                        	gets(dist);
                        	break;
            	    case 15:cout<<"\nEnter new Pincode: ";
	                    	gets(pin);
	                    	break;
              		case 16:cout<<"\nModify Occupation: ";
                        	gets(o);
                        	break;
              		default:cout<<"\nInvalid Choice";
                			exit(0);
				}
				ofs.write((char *)&b,sizeof(Banking));
			}
			else
			{
				ofs.write((char *)&b,sizeof(Banking));
			}
		}
	if(flag==0)
	{
	cout<<"\nRecord Details not found..!!\nPlease Try Again......";	
	}
	ofs.close();
	ifs.close();
	remove("bank.txt");
	rename("temp.txt","bank.txt");
}

void Banking::trans()
{
	int ch_3;
	system("cls");
	cout<<"\t\t\t=====================TRANSACTIONS SECTION=====================\n\n";
	cout<<"\t\t\t\t\t\t";
	cout<<"Date- "<<__DATE__<<"\t"<<"Time- "<<__TIME__<<"\n\n";
	cout<<"1- Withdrawal";
	cout<<"\n2- Deposit";
	cout<<"\n3- Balance Enquiry";
	cout<<"\n\nEnter Your Choice: ";
	cin>>ch_3;	
	switch(ch_3)
	{
		case 1:	 withdrawal();
				 break;
		case 2:  deposit();
				 break;
		case 3:  bal_enq();
				 break;
		default: cout<<"\nInvalid Choice..!!\n\nPress any key to exit....";
				 exit(0);
	}
}

void Banking::withdrawal()
{
		int act_no3,wd=0,flag=0;
		system("cls");
		cout<<"\t\t\t===================CASH WITHDRAWAL SECTION====================\n\n";
		cout<<"\t\t\t\t\t\t";
		cout<<"Date- "<<__DATE__<<"\t"<<"Time- "<<__TIME__<<"\n\n";
		ofstream ofs("temp.txt");
		ifstream ifs("bank.txt");
	if(!ifs)
	{
		cout<<"\nFile not found";
		getch();
		exit(0);
	}
			cout<<"\nEnter Customer Account Number: ";
			cin>>act_no3;
		while(ifs.read((char*)&b,sizeof(Banking)))
		{
			if(act_no3==act_no)
			{
				flag=1;
				cout<<"Account Holder Name: "<<name;
				cout<<"\nEnter Amount to be withdrawn: Rs. ";
				cin>>wd;
			if(net_amt<0 || net_amt<wd)
			{
				cout<<"Insufficient Balance...!"<<endl;
				exit(0);
			}
				net_amt=net_amt-wd;
				cout<<"\nAmount Withdrawn Successfully.......!!";
				cout<<"\n\nRemaining Balance= Rs. "<<net_amt;
				ofs.write((char *)&b,sizeof(Banking));
			}
			else
			{
				ofs.write((char*)&b,sizeof(Banking));
			}
		}
	if(flag==0)
	{
		cout<<"\nRecord Details not found..!!\nPlease Try Again......";
		exit(0);
	}
		ifs.close();
		ofs.close();
		remove("bank.txt");
		rename("temp.txt","bank.txt");
}

void Banking::deposit()
{
		int act_no4,depo=0,flag=0;
		system("cls");
		cout<<"\t\t\t=====================CASH DEPOSIT SECTION=====================\n\n";
	    cout<<"\t\t\t\t\t\t";
		cout<<"Date- "<<__DATE__<<"\t"<<"Time- "<<__TIME__<<"\n\n";
		ofstream ofs("temp.txt");
		ifstream ifs("bank.txt");
	if(!ifs)
	{
		cout<<"\nFile not found";
		getch();
		exit(0);
	}
		cout<<"\nEnter Customer Account Number: ";
		cin>>act_no4;
		while(ifs.read((char*)&b,sizeof(Banking)))
		{
			if(act_no4==act_no)
			{
				flag=1;
				cout<<"Account Holder Name:\t"<<name;
				cout<<"\nEnter Amount to be Deposited: Rs. ";
				cin>>depo;
				net_amt=net_amt+depo;
				cout<<"\nAmount Deposited Successfully.......!!";
				cout<<"\nUpdated Balance= Rs. "<<net_amt;
				ofs.write((char *)&b,sizeof(Banking));
			}
			else
			{
				ofs.write((char*)&b,sizeof(Banking));
			}
		}
	if(flag==0)
	{
		cout<<"\nRecord Details not found..!!\nPlease Try Again......";
		exit(0);
	}
		ifs.close();
		ofs.close();
		remove("bank.txt");
		rename("temp.txt","bank.txt");
}

void Banking::bal_enq()
{
	int act_no5,flag=0;
	system("cls");
	cout<<"\t\t\t===================BALANCE ENQUIRY SECTION====================\n\n";
    cout<<"\t\t\t\t\t\t";
	cout<<"Date- "<<__DATE__<<"\t"<<"Time- "<<__TIME__<<"\n\n";
	ofstream ofs("temp.txt");
	ifstream ifs("bank.txt");
	if(!ifs)
	{
		cout<<"\nFile not found";
		getch();
		exit(0);
	}
		cout<<"\nEnter Customer Account Number: ";
		cin>>act_no5;
	
		while(ifs.read((char*)&b,sizeof(Banking)))
		{
			if(act_no5==act_no)
			{
				flag=1;
				cout<<"Account Holder Name:\t"<<name;
				cout<<"\nAvailable Balance:\tRs."<<net_amt;	
			}
		}
	if(flag==0)
	{
		cout<<"\nRecord Details not found..!!\nPlease Try Again......";
		exit(0);
	}
	ifs.close();
	ofs.close();
}

void Banking::del()
{
	system("cls");
	int ch_4,act_no6,flag=0;
	cout<<"\t\t\t====================ACCOUNT DELETION SECTION====================\n\n";
    cout<<"\t\t\t\t\t\t";
	cout<<" Date- "<<__DATE__<<" \t "<<" Time- "<<__TIME__<<"\n\n";
	ofstream ofs("temp.txt");
	ifstream ifs("bank.txt");
	if(!ifs)
	{
		cout<<"\nFile not found";
		getch();
		exit(0);
	}
			cout<<"\nDelete Account using Account Number:\n\n";
			cout<<"\nEnter Account Number: ";
			cin>>act_no6;
		while(ifs.read((char*)&b,sizeof(Banking)))
		{
			if(act_no==act_no6)
			{
				flag=1;
				cout<<"\nAccount Closed Successfully...!!";
			}
			else
			{
				ofs.write((char *)&b,sizeof(Banking));
			}
		}
	if(flag==0)
	{
		cout<<"\nRecord Details not found..!!\nPlease Try Again......";
	}
	ofs.close();
	ifs.close();
	remove("bank.txt");
	rename("temp.txt","bank.txt");
}

void Banking::fd()
{
	int ch_5;
	system("cls");
	cout<<"\t\t\t====================FIXED DEPOSIT ACCOUNTS SECTION====================\n\n";
	cout<<"\t\t\t\t\t\t\t";
	cout<<"Date- "<<__DATE__<<"\t"<<"Time- "<<__TIME__<<"\n\n";
	cout<<"1- Create new FD";
	cout<<"\n2- Display all FD account holders";
	cout<<"\n3- Delete FD account holders";
	cout<<"\n\nEnter Your Choice (1-3): ";
	cin>>ch_5;	
	switch(ch_5)
	{
		case 1:	 fd_create();
				 break;
		case 2:  fd_display();
				 break;
		case 3:  fd_delete();
				 break;
		default: cout<<"\nInvalid Choice..!!\n\nPress any key to exit....";
				 exit(0);
	}
}

void Banking::fd_create()
{
		char ch_6;
		system("cls");
	    cout<<"\t\t\t==================NEW FIXED DEPOSIT ACCOUNT DETAILS====================\n\n";
	    cout<<"\t\t\t\t\t\t\t";
		cout<<" Date- "<<__DATE__<<"\t"<<" Time- "<<__TIME__<<"\n\n";
	    ofstream ofs("fd.txt",ios::app);
	    cout<<"\n1- Enter FD Account Number: ";
	    cin>>fd_no;
	    cout<<"\n2- Enter Account Holder Name: ";
	    fflush(stdin);
		gets(name);
	    cout<<"\n3- Enter Nominee Name: ";
	    gets(nom);
	    cout<<"\n4- Enter AADHAR Number: ";
	    gets(adhr);
	    cout<<"\n5- Enter PAN Number: ";
	    gets(pan);
	    cout<<"\n6- Account Type: ";
	    cout<<"Fixed Deposit\n\n";
	    cout<<"\t\t\t=========================FIXED DEPOSIT SCHEMES===========================\n\n";
		cout<<"\n\t\t\tInterest  Rates\t\t\t\tTime Duration\n";
		cout<<"\n\t\t\t\t4%\t\t\t\tLess than 12 months";
		cout<<"\n\t\t\t\t5%\t\t\t\tMore than 12 months but less than 24 months";
		cout<<"\n\t\t\t\t6%\t\t\t\tMore than 24 months but less than 60 months";
		cout<<"\n\t\t\t\t7.5%\t\t\t\tMore than than 60 months";
		cout<<"\n\nEnter Deposit Amount: Rs. ";	
		cin>>fd_amt;
		cout<<"\n\nEnter Time (in months): ";
		cin>>month;
		if(month<=12)
		{
		rate=0.04;
		}
		else if(month>12 && month<=24)
		{
		rate=0.05;
		}
		else if(month>24 && month<=60)
		{
		rate=0.06;
		}
		else rate=0.075;
    interest=fd_amt*rate;
	m_amt=interest+fd_amt;
	cout<<"\n\nInterest Rate: "<<rate*100<<"%";
	cout<<"\n\n\nMaturity Amount= Rs. "<<m_amt;		
    ofs.write((char *)&f,sizeof(Banking));
    cout<<"\n\nCongratulations!! \nFixed Deposit Account created Successfully....";
    ofs.close();
}

void Banking::fd_display()
{
	system("cls");
	cout<<"\t\t\t=====================DISPLAY ALL FD ACCOUNT HOLDERS=====================\n\n";
    cout<<"\t\t\t\t\t\t\t";
	cout<<"Date- "<<__DATE__<<"\t"<<"Time- "<<__TIME__<<"\n\n";
	ifstream ifs("fd.txt");
	if(!ifs)
	{
		cout<<"\nRecord File not found......!!";
		cout<<"\n\nPress any Button to Exit....";
		exit(0);
	}
	while(ifs.read((char*)&f,sizeof(Banking)))
	{
	    cout<<"\n------------------------------------";
	    cout<<"\nFD Account Number:\t\t\t"<<fd_no;
		cout<<"\nAccount Holder Name:\t\t\t"<<name;
		cout<<"\nNominee Name:\t\t\t\t"<<nom;			
		cout<<"\nAADHAR Number:\t\t\t\t"<<adhr;						
		cout<<"\nPAN Number:\t\t\t\t"<<pan;
		cout<<"\nDeposit Amount:\t\t\t\tRs."<<fd_amt;
		cout<<"\nRate of Interest:\t\t\t"<<rate*100;
		cout<<"\nTime Duration:\t\t\t\t"<<month<<" months";
		cout<<"\nMaturity Amount:\t\t\tRs."<<m_amt;
		cout<<"\n------------------------------------";
		getch();
	}
	ifs.close();
}

void Banking::fd_delete()
{
	system("cls");
	int ch_7,fd_no1,flag=0;
	cout<<"\t\t\t====================FD ACCOUNT DELETION SECTION====================\n\n";
    cout<<"\t\t\t\t\t\t";
	cout<<" Date- "<<__DATE__<<" \t "<<" Time- "<<__TIME__<<"\n\n";
	ofstream ofs("temp.txt");
	ifstream ifs("fd.txt");
	if(!ifs)
	{
		cout<<"\nFile not found";
		getch();
		exit(0);
	}
		cout<<"\nDelete FD Account using FD Account Number:\n\n";
		cout<<"\nEnter Fixed Deposit Account Number: ";
		cin>>fd_no1;
		while(ifs.read((char*)&f,sizeof(Banking)))
		{
			if(fd_no==fd_no1)
			{
				flag=1;
				cout<<"\nRecord Deleted Successfully...!!";
			}
			else
			{
				ofs.write((char *)&f,sizeof(Banking));
			}
		}
	if(flag==0)
	{
		cout<<"\nRecord Details not found..!!\nPlease Try Again......";
	}
	ofs.close();
	ifs.close();
	remove("fd.txt");
	rename("temp.txt","fd.txt");
}

void Banking::add1()
{
	system("cls");
    cout<<"\t\t\t======================ADD EMPLOYEE RECORD SECTION=====================\n\n";
    cout<<"\t\t\t\t\t\t\t";
	cout<<"Date- "<<__DATE__<<"\t"<<"Time- "<<__TIME__<<"\n\n";
	ofstream ofs("emp.txt",ios::app);
    cout<<"1- Enter Employee ID: ";
    cin>>emid;
    fflush(stdin);
    cout<<"\n2- Enter Employee Name: ";
    gets(ename);
    cout<<"\n3- Enter Gender: ";
    gets(egen);
    cout<<"\n4- Enter Date of Birth: ";
    gets(edob);
    cout<<"\n5- Enter Contact Number: ";
    gets(ecno);
    cout<<"\n6- Enter Email Id: ";
    gets(email);
    cout<<"\n7- Enter Blood Group: ";
    gets(ebg);
    cout<<"\n8- Enter Designation: ";
    gets(ed);
    ofs.write((char*)&e,sizeof(Banking));
    cout<<"\n\nRecord Added Successfully!!";
    ofs.close();
}

void Banking::search1()
{
	int emid1,flag=0;
    system("cls");
    cout<<"\t\t\t===================EMPLOYEES SEARCH RECORD SECTION====================\n\n";
    cout<<"\t\t\t\t\t\t\t";
	cout<<"Date- "<<__DATE__<<"\t"<<"Time- "<<__TIME__<<"\n\n";
	ifstream ifs("emp.txt");
    if(!ifs)
    {
        cout<<"\nFile not found";
        getch();
        exit(0);
    }
    cout<<"\nEnter Employee Id to Search: ";
    cin>>emid1;
    while(ifs.read((char*)&e,sizeof(Banking)))
    {
        if(emid==emid1)
        {
            cout<<"\nEmployee Id: "<<emid;
            cout<<"\nEmployee Name: "<<ename;
            cout<<"\nGender: "<<egen;
            cout<<"\nDate of Birth: "<<edob;
            cout<<"\nContact Number: "<<ecno;
            cout<<"\nEmail Id: "<<email;
            cout<<"\nBlood Group: "<<ebg;
            cout<<"\nDesignation: "<<ed;
            cout<<"\nNet Salary withdrawn= Rs. "<<t_net;
            flag=1;
        }
    }
    if(flag==0)
    {
        cout<<"\nEmployee Id not found,Try Again..";
    }
    ifs.close();
} 	

void Banking::display1()
{
    system("cls");
    cout<<"\t\t\t======================DISPLAY EMPLOYEES RECORD SECTION======================\n\n";
    cout<<"\t\t\t\t\t\t\t";
	cout<<"Date- "<<__DATE__<<"\t"<<"Time- "<<__TIME__<<"\n\n";
	ifstream ifs("emp.txt");
    if(!ifs)
    {
        cout<<"\nFile not found";
        getch();
        exit(0);
    }
    while(ifs.read((char*)&e,sizeof(Banking)))
    {
       	cout<<"\n------------------------------------";
        cout<<"\nEmployee Id: "<<emid;
        cout<<"\nEmployee Name: "<<ename;
        cout<<"\nGender: "<<egen;
        cout<<"\nDate of Birth: "<<edob;
        cout<<"\nContact Number: "<<ecno;
        cout<<"\nEmail Id: "<<email;
        cout<<"\nBlood Group: "<<ebg;
        cout<<"\nDesignation: "<<ed;
		cout<<"\n\nNet Salary withdrawn= Rs. "<<t_net;  
 		cout<<"\n------------------------------------";
        getch();
    }
    ifs.close();
}

void Banking::modify1()
{
    system("cls");
    int emid2,ch_8,flag=0;
    cout<<"\t\t\t======================MODIFY EMPLOYEES RECORD SECTION======================\n\n";
    cout<<"\t\t\t\t\t\t\t";
	cout<<"Date- "<<__DATE__<<"\t"<<"Time- "<<__TIME__<<"\n\n";
	ofstream ofs("temp1.txt");
    ifstream ifs("emp.txt");
    if(!ifs)
    {
        cout<<"\nfile not found";
        getch();
        exit(0);
    }
    cout<<"\nEnter Employee Id to modify: ";
    cin>>emid2;
    while(ifs.read((char*)&e,sizeof (Banking)))
    {
        if(emid2==emid)
        {
            flag=1;
            cout<<"\nChoose the option to modify Employee Record:";
            cout<<"\n1- Employee Name:";
            cout<<"\n2- Gender:";
            cout<<"\n3- Date of Birth:";
            cout<<"\n4- Contact Number:";
            cout<<"\n5- Email Id:";
            cout<<"\n6- Blood Group:";
            cout<<"\n7- Designation:";
            cout<<"\nEnter your choice(1-7): ";
            cin>>ch_8;
            fflush(stdin);
            switch(ch_8)
            {
                case 1:
                		cout<<"\nModify Employee Name: ";
                		gets(ename);
                		break;
                case 2:
                		cout<<"\nChange Gender: ";
                		gets(egen);
                		break;
                case 3:
                		cout<<"\nChange Date of Birth: ";
                		gets(edob);
                		break;
                case 4:
                		cout<<"\nChange Contact Number: ";
            			gets(ecno);
                		break;
                case 5:
                		cout<<"\nChange Email Id: ";
                		gets(email);
                		break;
                case 6:
                		cout<<"\nModify Blood group: ";
                		gets(ebg);
                		break;
                case 7:
                		cout<<"\nEnter new Designation: ";
                		gets(ed);
                		break;
                default:
                		cout<<"\nInvalid Choice";
                		exit(0);
            }
            ofs.write((char*)&e,sizeof(Banking));
        }
        else
        {
           ofs.write((char*)&e,sizeof(Banking)); 
        }
    }
    if(flag==0)
    {
        cout<<"\nEmployee ID Details not found..!!\nPlease Try Again......";
    }
    ofs.close();
    ifs.close();
    remove("emp.txt");
    rename("temp1.txt","emp.txt");
}

void Banking::del1()
{
    system("cls");
    int emid3,flag=0;
    cout<<"\t\t\t====================DELETE EX-EMPLOYEES RECORD SECTION====================\n\n";
    cout<<"\t\t\t\t\t\t";
	cout<<" Date- "<<__DATE__<<" \t "<<" Time- "<<__TIME__<<"\n\n";
	ofstream ofs("temp1.txt");
    ifstream ifs("emp.txt");
    if(!ifs)
    {
        cout<<"File not found";
        getch();
        exit(0);
    }
    cout<<"\nEnter Employee ID to delete: ";
    cin>>emid3;
    while(ifs.read((char*)&e,sizeof(Banking)))
    {
        if(emid3==emid)
        {
            flag=1;
            cout<<"\nRecord Deleted Successfully......!!";
        }
        else
        {
            ofs.write((char*)&e,sizeof(Banking));
        }
    }
    if(flag==0)
    {
        cout<<"\nEmployee Record Details not found..!!\nPlease Try Again......";
    }
    ofs.close();
    ifs.close();
    remove("emp.txt");
    rename("temp1.txt","emp.txt");
}

void Banking::salary()
{
    int emid4,flag=0;
    float bs,da,hra,ta,pf,it,t,t_ded,t_all,working_days,month,no_of_days,day_amt,final_amt;
    system("cls");
    cout<<"\t\t\t====================SALARY RECORD SECTION====================\n\n";
    cout<<"\t\t\t\t\t\t";
	cout<<" Date- "<<__DATE__<<" \t "<<" Time- "<<__TIME__<<"\n\n";
	ofstream ofs("temp1.txt");
    ifstream ifs("emp.txt");
    if(!ifs)
    {
        cout<<"File not found";
        getch();
        exit(0);
    }
    cout<<"\nEnter Employee Id for Salary report: ";
    cin>>emid4;
    while(ifs.read((char*)&e,sizeof(Banking)))
    {
        if(emid4==emid)
        {
            flag=1;
            cout<<"\nEmployee Name: "<<ename;
            cout<<"\nEnter Basic Salary: Rs. ";
            cin>>bs;
            cout<<"\nEnter Month from (1-12) to generate salary report: ";
            cin>>month;
            if(month==2){
        	  	no_of_days=28;
    	       	cout<<"\nEnter number of working days (0-28): ";
	           	cin>>working_days;
			}else if(month==4||month==6||month==9||month==11){
				no_of_days=30;
				cout<<"\nEnter number of working days (0-30): ";
            	cin>>working_days;
			}else{
			no_of_days=31;
			cout<<"\nEnter number of working days (0-31): ";
            cin>>working_days;
        	}
			//cout<<"\nEnter number of working days: ";
            //cin>>working_days;
            da=bs*0.05;
            cout<<"\nDearness Allowance(5%):\t\t Rs. "<<da;
            hra=bs*0.10;
            cout<<"\nHouse Rent Allowance(3%):\t Rs. "<<hra;
            ta=bs*0.06;
            cout<<"\nTravelling Allowance(3%):\t Rs. "<<ta;
            t_all=da+hra+ta;
            pf=bs*0.06;
            cout<<"\nProvident Fund(6%):\t\t Rs. "<<pf;
            it=bs*0.10;
            cout<<"\nIncome Tax(10%):\t\t Rs. "<<it;
            t_ded=pf+it;
            t_net=(bs+t_all)-t_ded;
            day_amt=t_net/no_of_days;
            final_amt=day_amt*working_days;
            cout<<"\n\nTotal Net Salary=\t\t Rs. "<<final_amt;
            ofs.write((char*)&e,sizeof(Banking));
        }
        else
        {
            ofs.write((char*)&e,sizeof(Banking));
        }
    }
        if(flag==0)
        {
            cout<<"\nRecord Details not found..!!\nPlease Try Again......";
        }
        ifs.close();
        ofs.close();
        remove("emp.txt");
        rename("temp1.txt","emp.txt"); 
}

int main()
{
	int login,b_ch,e_ch;
	char ch1,ch2;
	char c_id[10],c_pass[10],c_userid[10]="cuser",c_password[10]="cpass";
	char e_id[10],e_pass[10],e_userid[10]="euser",e_password[10]="epass";
	cout<<"\t\t\t=====================WELCOME TO BANKING MANAGEMENT SYSTEM=====================\n\n";
	cout<<"\t\tUSER LOGIN\t\t\t\t\t";
	cout<<"Date- "<<__DATE__<<"\t"<<"Time- "<<__TIME__<<"\n\n";
	cout<<"\t\t1. Customer Banking Login";
	cout<<"\n\t\t2. Employee Records Section";
	cout<<"\n\n\t\tEnter your Choice (1-2): ";
	cin>>login;
	if(login==1)
	{
			fflush(stdin);
			cout<<"\n\n\t\tUser ID: ";
			gets(c_id);
			cout<<endl;
			cout<<"\t\tEnter Password: ";
			gets(c_pass);
		if(strcmp(c_id,c_userid)==0 && strcmp(c_pass,c_password)==0)
		{
			cout<<"\n\nPassword Matched!\nLOADING";
			for(int i=0;i<=6;i++)
			{
			cout<<". ";
			}
			system("cls");
			do
			{
    			system("cls");
        		cout<<"\t\t\t=====================WELCOME TO BANKING MANAGEMENT SYSTEM=====================\n\n";
        		cout<<"\t\t\t\t\t\t\t\t";
				cout<<"Date- "<<__DATE__<<"\t"<<"Time- "<<__TIME__<<"\n";
				cout<<"\n\t\t\t1- Add new bank account:";
        		cout<<"\n\t\t\t2- Search existing accounts:";	
        		cout<<"\n\t\t\t3- Display all (savings/current) accounts:";	
        		cout<<"\n\t\t\t4- Modify existing accounts:";
        		cout<<"\n\t\t\t5- Transaction details:";
        		cout<<"\n\t\t\t6- Delete non-existing account Holders:";
        		cout<<"\n\t\t\t7- Fixed Deposit accounts Section:";      
				cout<<"\n\t\t\t8- Exit:";
        		cout<<"\n\t\t\tEnter your choice (1-8): ";
        		cin>>b_ch;
    			switch(b_ch)
    			{
	    			case 1: b.add();
	   						break;
	    			case 2: b.search();
	   						break;
	    			case 3: b.display();
				    		break;
	    			case 4: b.modify();
	    		    		break;
	    			case 5: b.trans();
	        				break;
        			case 6: b.del();
	        				break;
	    			case 7: f.fd();
	    					break;
					case 8:cout<<"\n\nTHANK YOU..!!\nFor using our BANKING MANAGEMENT SYSTEM";
					exit(0);  
				}
					cout<<"\n\nDo you want to continue again....(Press Y or N): ";
    				cin>>ch1;
    		}while(ch1=='y'||ch1=='Y');
		}else cout<<"\n\nWrong Password Entered........!!";
		exit(0);
    }
    else if(login==2)
    {
    	fflush(stdin);
		cout<<"\n\n\t\tUser ID: ";
		gets(e_id);
		cout<<endl;
		cout<<"\t\tEnter Password: ";
		gets(e_pass);
		if(strcmp(e_id,e_userid)==0 && strcmp(e_pass,e_password)==0)
		{
			cout<<"\n\nPassword Matched!\nLOADING";
			for(int j=0;j<=6;j++)
			{
			cout<<". ";
			}
			system("cls");
			do
			{
				system("cls");
        		cout<<"\t\t\t=====================BANK EMPLOYEE RECORD SECTION=====================\n\n";
				cout<<"\t\t\t\t\t\t\t";
				cout<<"Date- "<<__DATE__<<"\t"<<"Time- "<<__TIME__<<"\n\n";
				cout<<"\t\t\t1- Add New Bank Employee:";
				cout<<"\n\t\t\t2- Search Existing Bank Employees:";
				cout<<"\n\t\t\t3- Display all Bank Employees:";
				cout<<"\n\t\t\t4- Modify Existing Bank Employee Records:";
				cout<<"\n\t\t\t5- Delete non-Existing Bank Employees:";
				cout<<"\n\t\t\t6- Generate Salary Report of Bank Employees:";
				cout<<"\n\t\t\t7- Exit";
				cout<<"\n\n\t\t\tEnter Your Choice (1-7): ";
				cin>>e_ch;
				switch(e_ch)
				{
					case 1:	e.add1();
					break;
					case 2: e.search1();
					break;
					case 3: e.display1();
					break;
					case 4: e.modify1();
					break;
					case 5: e.del1();
					break;
					case 6: e.salary();
					break;
					case 7: cout<<"\n\nTHANK YOU..!!\nFor using our BANKING MANAGEMENT SYSTEM";
					exit(0); 
				}	cout<<"\n\nDo you want to continue again....(Press Y or N): ";
    				cin>>ch2;
    		}while(ch2=='y'||ch2=='Y');
		}else cout<<"\n\nWrong Password Entered........!!";
		exit(0);
	}else cout<<"\n Invalid Choice........!! \nPlease Try Again.....";
}	
