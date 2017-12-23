#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <conio.h>
#include <string>
#include <fstream>
#include <ctime>
#include <time.h>

using namespace std;


/******************************************************************************************************/
/************************************** PROTOTYPES OF FUNCTIONS ***************************************/
/******************************************************************************************************/

void menu();
void studentInfo();
void attendanceRecord();
void disC();
void hod();
void arrangeMeeting();
void filewrite();
void search();
void sickwrite();
void dropwrite();
void shrtatndwrite();
void sickread();
void dropread();
void shrtatndread();


/***************************************** END OF PROTOTYPES ******************************************/


/******************************************************************************************************/
/*********************************** DEFINITION OF VARIABLES ******************************************/
/******************************************************************************************************/
	int rollNumber;

	char *studentName= new char[];

	char *fathersName= new char[];

	char *dob= new char[];

	char *enrollmentDate= new char[];

	char *batch= new char[];

	char *department= new char[];

	float semester[9][6];

	int offences=1;

    int *natOffences= new int [];

	int fine = 0 ;
	
	int sem;

	int meetingReason ;

	int warning;

	int appProcess[5][5]={0,0,0,0,0};

	int appcount=0;

	int *sick=new int [];

	int *shrtatnd=new int[];

	int *drop=new int[];

	int sickcounter=0;

	int dropcounter=0;

	int shrtatndcounter=0;
	
	int criticality[4]={0,0,0,0};

	int attendancecheck=0;

	int meetingSchedule[4]={0,1,2,3};

/***************************************** END OF DEFINITIONS *****************************************/




/******************************************************************************************************/
/****************************************** MAIN FUNCTION *********************************************/
/******************************************************************************************************/

	

int main()
{

	

	system("color 34");
	system("cls");
	cout<<"                         __  __   __   __   __  __      ___  __ "<<endl;
	cout<<"                     .  /   /  \\ /  \\ |__) |_  |__)  /\\  |  |_  "<<endl;
	cout<<"                     |  \\__ \\__/ \\__/ |    |__ |  \\ /--\\ |  |__ "<<endl;

	cout<<"\n\n"<<setw(50)<<"Welcome to iCooperte\n"<<setw(65)<< "FAST National University Student Management System\n\n\n";					
		
	cout<<"Enter Roll No. of Student: (For Example \"110023\")\n";
	cin>>rollNumber;
	search();
	sickread();
	shrtatndread();
	dropread();

	char x='n';
	do
	{
	

		system("color 34");
		system("cls");
		cout<<"                         __  __   __   __   __  __      ___  __ "<<endl;
		cout<<"                     .  /   /  \\ /  \\ |__) |_  |__)  /\\  |  |_  "<<endl;
		cout<<"                     |  \\__ \\__/ \\__/ |    |__ |  \\ /--\\ |  |__ "<<endl;
	
		cout<<"\n\n"<<setw(50)<<"Welcome to iCooperte\n"<<setw(65)<< "FAST National University Student Management System\n\n\n";

		menu();

		cout<<"\n\n\tPress any key to return to the main menu, or press 'e' to exit.";
		x=getche();
		
		} while (x!='e');

	filewrite();

	return 0;

	
	
	
}
		
	
/***************************************** END OF FUNCTION *******************************************/


/******************************************************************************************************/
/***************************************** MENU FUNCTION **********************************************/
/******************************************************************************************************/
void menu()
{
	
	system("cls");

	int opt ;
	int x=0 ;

	cout<<setw(78)<<" ** iCOOPERATE **" <<endl;

		system("cls");
		
		cout<<setw(78)<<" ** iCOOPERATE **" <<endl;

		cout<<endl ;
		cout<<"ENTER CORRESPONDING NUMBER FOR DESIRED OPTION \n"<<endl;
		cout<<"1- Student Info \n2- Attendance Record \n3- Disciplinary Committee Records \n4- H.O.D. Meetings \n" << endl ;
		cin>> opt ;


		switch (opt)
		{

		case 1:
			{
				studentInfo(); //FUNCTION CALL TO VIEW OR EDIT STUDENT INFO
				break;
			}
		case 2:
			{
				attendanceRecord(); //FUNCTION CALL TO VIEW OR EIDT ATTENDANCE RECORD OF STUDENT
				break;
			}
		case 3:
			{
				disC(); //FUNCTION CALL TO VIEW OR EDIT THE DISCIPLINARY RECORD OF STUDENT
				break;
			}
		case 4:
			{
				hod(); //FUNCTION CALL TO ASSIGN MEETING WITH THE HOD
				break;
			}
		default:
			{
				cout<<"Invalid option entered.\nPlease enter a valid option.\n\n";
			}
		}

		
	

	
}

/***************************************** END OF FUNCTION *******************************************/





/******************************************************************************************************/
/************************************* STUDENT INFO FUNCTION ******************************************/
/******************************************************************************************************/



void studentInfo()
{
	int opt ;
	
	system("cls");
	cout<<setw(78)<<" ** iCOOPERATE **" <<endl;

	
	/* PROMPTING USER TO CHOOSE DESIRED ACTION */


	cout<<"Do you want to view or edit the information?\nPlease enter 1 to view and 2 to edit : "<<endl;
	cin>>opt;

	switch (opt)
	{
		case 1:
		{

			/* PRINTING ALL DATA TAKEN FROM THE USER FOR THE CURRENT STUDENT */


			cout<<"\nStudent's Full Name: "<<studentName;
			cout<<"\nFather's Full Name: "<<fathersName;
			cout<<"\nStudent's Date Of Birth (DD/MM/YY): "<<dob;
			cout<<"\nStudent's Date of Enrollment: "<<enrollmentDate;
			cout<<"\nBatch of Student: "<<batch;
			cout<<"\nDepartment of Student: "<<department;
			

			/*PRINTING SEMESTER WISE GPA OF STUDENT */
			if (sem>1)

			{
				cout<<"\nStudent's Semester-wise GPA: ";


				for (int i=1; i<sem; i++)
				{
					cout<<"\nGPA of Semester "<<i<<" is: ";
				}
				
			}
			
			cout<<"\nPlease enter any key to go back to the main menu."<<endl;

			getche();

			break;
		}

		case 2:
		{
			
			cin.ignore();

			/* TAKING ALL DATA FROM USER */

			cout<<"Enter Student's Full Name: ";
			cin.getline(studentName , 30 , '\n');

			cout<<"\nEnter Father's's Full Name: ";
			cin.getline( fathersName , 30 , '\n');			
	
			cout<<"\nEnter Student's Date Of Birth (DD/MM/YY): ";
			cin.getline( dob , 80 , '\n');	
		
			cout<<"\nEnter Student's Date of Enrollment: ";
			cin.getline( enrollmentDate , 80 , '\n');
		
			cout<<"\nEnter Batch of Student: " ;
			cin.getline( batch , 80 , '\n');
	
			cout<<"\nEnter Department of Student: " ;
			cin.getline( department, 80 , '\n');	
	
			cout<<"\nEnter current semester of the student: ";
			cin>>sem;

			/* TAKING SEMESTER WISE GPA FROM THE USER */
	
			if (sem>1)
			{

				cout<<"\nEnter Student's Semester-wise GPA: ";
		
				for (int i=1; i<sem; i++)

					{
						cout<<"\nEnter GPA of Semester "<<i<<": ";

						cin>>semester[i][0];
					}
			}

			/* RETURNING TO MAIN MENU AFTER THE COMPLETION OF TASK */

			cout<<"\n\nPress any key to go back to main menu"<<endl;

			getche();

			cout<<semester[0][0];

			break;
		

		}

		default:
			{
				cout<<"\nPlease enter a valid option.\n";
				getche();
			}
	
	
	}

/***************************************** END OF FUNCTION *******************************************/




/******************************************************************************************************/
/*********************************** ATTENDANCE RECORD FUNCTION ***************************************/
/******************************************************************************************************/



}
void attendanceRecord()
{
	system("cls");
	cout<<setw(78)<<" ** iCOOPERATE **" <<endl;

	int opt; 

	/* PROMPTING USER TO CHOOSE DESIRED ACTION */
	cout<<"Do you want to view or edit the information?\nPlease enter 1 to view and 2 to edit : "<<endl;
	cin>>opt;

	switch (opt)
	{
		case 1:
			{
				
				for ( int i=sem ; i<=sem ; i++ )
				{
						for (int j=1 ; j<=5 ; j++ )
						{
								cout <<"\nPercentage Attendance In Course "<<j<<" Of Current Semester "<<i<<":"<<semester[i][j];
						}
				
				}

				cout<<"\nPlease enter any key to go back to the main menu."<<endl;
				system("pause");
				getche() ;
				getche() ;
				break;
			}
				
		case 2:
			{
				cout<<"Enter Percentage Attendence of Each Course" <<endl ;

				cout<<"\nEnter Current Semester"<<endl ;
				cin>> sem ;

				for ( int i=sem ; i<=sem ; i++ )
					{
						for (int j=1 ; j<=5 ; j++ )
						{
								cout <<"\nEnter Percentage Attendance In Course "<<j<<" Of Current Semester "<<i<<":";
								cin>> semester[i][j] ;
						}
					}

				
				break ;

			}	
			
			/* RETURNING TO MAIN MENU AFTER THE COMPLETION OF TASK */

			cout<<"\nPlease enter any key to go back to the main menu."<<endl;
				getche();
	}
}


/***************************************** END OF FUNCTION *******************************************/



/******************************************************************************************************/
/************************************ DISCIPLINARY RECORD FUNCTION ************************************/
/******************************************************************************************************/

void disC()
{
	system("cls");
	cout<<setw(78)<<" ** iCOOPERATE **" <<endl;

	int opt; 

	/* PROMPTING USER TO CHOOSE DESIRED ACTION */

	cout<<"Do you want to view or edit the information?\nPlease enter 1 to view and 2 to edit : "<<endl;
	cin>>opt;

	switch (opt)
	{
		case 1:
			{
				cout<<"\nNumber of Offences: "<<offences;
				for (int i=0; i<offences; i++)
				{
					cout<<"\nNature of offence "<<i+1<<"is: ";
					
					switch (natOffences[i])
					{
						case 1 :
						{
							cout<<"\nSmoking\\Drugs\n";
							cout<<" FINE : Rs 2000"<<endl ;
							break ;
						}
						case 2 :
						{
							cout<<"\nCheating\n";
							cout<<" FINE : Rs 2000"<<endl ;
							break ;
						}
						case 3 :
						{
							cout<<"\nLoss of University Card\n";
							cout<<" FINE : Rs 500"<<endl ;
							break;
						}
						case 4 :
						{
							cout<<"\nFighting\n";
							cout<<" FINE : Rs 2000"<<endl ;
							break ;
						}
						case 5 :
						{
							cout<<"\nDamaging University Property\n";
							cout<<" FINE : Rs 2000"<<endl ;
							break ;
						}
						case 6 :
						{
							cout<<"\nStealing\n";
							cout<<" FINE : Rs 2000"<<endl ;
							break ;
						}
						case 7 :
						{
							cout<<"\nMisbehaviour with Faculty\n";
							cout<<" FINE : Rs 2000"<<endl ;
							break ;
						}
					}
				}

				cout<<"\nPress any key to go back to the main menu."<<endl;

				getche();
				
				break;

			}



		case 2:
			{
	
				cout<<"Enter Number of Offences: ";
				cin>>offences;	
				if (offences>3)
				{
					warning++;
					if(warning>1)
					{
						cout<<"\n\nThe student was previously on warning.\n\nOn further offence, the student is rusticated from the university.\n";
						break;
					} 
				
				}

				cout<<"\nPlease enter the corresponding number to the nature of offence\n1- Smoking\\Drugs\n2- Cheating\n3- Loss of university card\n4- Fighting\n5- Damaging university property\n6- Stealing\n7- Misbehaviour with faculty"<<endl ;
	
				
	
					for (int i=0; i<offences; i++)
				{
					cout<<"\n Enter nature of offence "<<i+1<<": ";
					cin>>natOffences[i];
		

				switch (natOffences[i])
				{
					case 1 :
					{
					cout<<" FINE : Rs 2000"<<endl ;
					fine += 2000 ;
					break ;
				}
				case 2 :
				{
					cout<<" FINE : Rs 2000"<<endl ;
					fine += 2000 ;
					break ;
				}
				case 3 :
				{
					cout<<" FINE : Rs 500"<<endl ;
					fine += 500 ;
					break ;
				}
				case 4 :
				{
					cout<<" FINE : Rs 2000"<<endl ;
					fine += 2000 ;
					break ;
				}
				case 5 :
				{
					cout<<" FINE : Rs 2000"<<endl ;
					fine += 2000 ;
					break ;
				}
				case 6 :
				{
					cout<<" FINE : Rs 2000"<<endl ;
					fine += 2000 ;
					break ;
				}
				case 7 :
				{
					cout<<" FINE : Rs 2000"<<endl ;
					fine += 2000 ;
					break ;
				}

				}

					}

	cout<<"\nTOTAL FINE PAID: "<<fine<<endl;


			}
	}
	
	/* RETURNING TO MAIN MENU AFTER THE COMPLETION OF TASK */
	
	cout<<"\nPress any key to go back to the main menu"<<endl;
	getche();
}

/***************************************** END OF FUNCTION *******************************************/



/******************************************************************************************************/
/************************************** HOD MEETING FUNCTION ******************************************/
/******************************************************************************************************/


void hod()
{

	system("cls");
	cout<<setw(78)<<" ** iCOOPERATE **" <<endl;
	
	/* PROMPTING USER TO CHOOSE DESIRED ACTION */

	
	int i;

	for (i=1; i<6; i++)
	{
		if (semester[sem][i]<80)
		{
			attendancecheck=1;
			break;
		}
	}

	

	cout<<"\nIs the meeting which is to be arranged for LEAVE, COURSE DROP or SHORT ATTENDANCE ?\nPress 1 for LEAVE.\nPress 2 for COURSE DROP.\nPress 3 for SHORT ATTENDANCE."<<endl;
	cin>>meetingReason;

	switch (meetingReason)
	{
		case 1:
			{
				

				if (attendancecheck==1)
				{
					cout<<"The attendance of the student in course "<<i<<" is short.\n\nLeave Application Rejected\n";
				}
				else
				{
					appProcess[appcount][1]=1;
					arrangeMeeting();
				}

				

				break;
			}
		case 2:
			{
				appProcess[appcount][2]=1;
				arrangeMeeting();

				break;
			}

		case 3:
			{
				
				

				if (attendancecheck==0)
				{
					cout<<"\nThe attendance of the student in all courses is sufficient.\nHence the student is not debarred in any course, application not needed.\n";
					getche();
				}

				else
				{
					cout<<"\nThe attendence of the student is short in one or more courses. \n";
					appProcess[appcount][3]=1;
					arrangeMeeting();

				}
				
				break;


			}
			

	
	}
	appcount++;

	getche();

}

/***************************************** END OF FUNCTION *******************************************/





/******************************************************************************************************/
/*************************** MEETING ARRANGEMENT AND HANDLING FUNCTION ********************************/
/******************************************************************************************************/

void arrangeMeeting()
{

	appProcess[appcount][0]=rollNumber;

	if (appProcess[appcount][1]==1)
	{
		sick[sickcounter]=appProcess[appcount][0];
		sickcounter++;

		if (offences>0 && attendancecheck!=0)
		{
			criticality[1]+=4;
			cout<<"Criticallity of Meetings for Sick Leave is: "<<criticality[1]<<endl;
		}

		if (offences>0 && attendancecheck==0)
		{
			criticality[1]+=3;
			cout<<"Criticallity of Meetings for Sick Leave is: "<<criticality[1]<<endl;
		}

		if (offences==0 && attendancecheck!=0)
		{
			criticality[1]+=2;
			cout<<"Criticallity of Meetings for Sick Leave is: "<<criticality[1]<<endl;
		}

		if (offences==0 && attendancecheck==0)
		{
			criticality[1]+=1;
			cout<<"Criticallity of Meetings for Sick Leave is: "<<criticality[1]<<endl;
		}

		getche();


		
		
	}
		

	if (appProcess[appcount][2]==1)
	{
		drop[dropcounter]=appProcess[appcount][0];
		dropcounter++;

		if (offences>0 && attendancecheck!=0)
		{
			criticality[2]+=4;
			cout<<"Criticallity of Meetings for Dropping Course is: "<<criticality[2]<<endl;
		}

		if (offences>0 && attendancecheck==0)
		{
			criticality[2]+=3;
			cout<<"Criticallity of Meetings for Dropping Course is: "<<criticality[2]<<endl;
		}

		if (offences==0 && attendancecheck!=0)
		{
			criticality[2]+=2;
			cout<<"Criticallity of Meetings for Dropping Course is: "<<criticality[2]<<endl;
		}

		if (offences==0 && attendancecheck==0)
		{
			criticality[2]+=1;
			cout<<"Criticallity of Meetings for Dropping Course is: "<<criticality[2]<<endl;
		}

		getche();

		

	}

	if (appProcess[appcount][3]==1)
	{
		shrtatnd[shrtatndcounter]=appProcess[appcount][0];
		shrtatndcounter++;

		if (offences>0 && attendancecheck!=0)
		{
			criticality[3]+=4;
			cout<<"Criticallity of Meetings for Course Debarrment is: "<<criticality[3]<<endl;
		}


		else if (offences>0 && attendancecheck==0)
		{
			criticality[3]+=3;
			cout<<"Criticallity of Meetings for Course Debarrment is: "<<criticality[3]<<endl;
		}


		else if (offences==0 && attendancecheck!=0)
		{
			criticality[3]+=2;
			cout<<"Criticallity of Meetings for Course Debarrment is: "<<criticality[3]<<endl;
		}


		else if (offences==0 && attendancecheck==0)
		{
			criticality[3]+=1;
			cout<<"Criticallity of Meetings for Course Debarrment is: "<<criticality[3]<<endl;
		}

		getche();

		
	}

	int hold;

    for ( int pass = 0; pass <  3; pass++ )
	{
    	for ( int j = 0; j < 3 - pass; j++ )           
		{
			if ( criticality[ j ] <= criticality[ j + 1 ] ) 
			{                     
			
				hold = meetingSchedule[ j ];                                
                meetingSchedule[ j ] = meetingSchedule[ j + 1 ];                          
                meetingSchedule[ j + 1 ] = hold;                            
                                                              
             } 
		}
	}
	
	cout<<"Press any key to print the meeting schedule\n\n";
	getche();

	time_t schedtime=time(0)+3600;


	cout<<"********************************************************************************"<<endl;
	cout<<"\t\t\tMeeting Schedule\n";
	cout<<"********************************************************************************"<<endl;

	for (int i=0; i<4; i++)
	{
		
		if (meetingSchedule[i]==0)
			continue;
		

		cout<<"\nThe meeting at place "<<i+1<<" is:";
		

		switch(meetingSchedule[i])
		{
			case 1:
				{
					if(sickcounter!=0)
					{
						cout<<"\n*********************** Students with sick leave ***********************\n";
						cout<<"\t\tThe students in this meeting are:\n";
						for (int i=0; i<sickcounter; i++)
						{
							cout<<endl<<sick[i]<<endl;

						}
						cout<<"\n**********************************************************************\n";
						cout<<"Scheduled at\t\t"<<ctime(&schedtime)<<"\n";
						schedtime+=3600;

					}

					else
					{
						cout<<"\nNo students are scheduled here\n\n";
					}

					break;

				}

			case 2:
				{
					if(dropcounter!=0)
					{
						cout<<"\n*********************** Students for dropping a course ***********************\n";
						cout<<"\t\tThe students in this meeting are:\n";
						for (int i=0; i<dropcounter; i++)
						{
							cout<<endl<<drop[i]<<endl;

						}
						cout<<"\n**********************************************************************\n";
						cout<<"Scheduled at\t\t"<<ctime(&schedtime)<<"\n";
						schedtime+=3600;

		

					}

					else
					{
						cout<<"\nNo students are scheduled here\n\n";
					}

					break;

				}

			case 3:
				{
						if(shrtatndcounter!=0)
					{
						cout<<"\n*********************** Students with short attendance ***********************\n";
						cout<<"\t\tThe students in this meeting are:\n";
						for (int i=0; i<shrtatndcounter; i++)
						{
							cout<<endl<<shrtatnd[i]<<endl;

						}
						cout<<"\n**********************************************************************\n";
						cout<<"Scheduled at\t\t"<<ctime(&schedtime)<<"\n";
						schedtime+=3600;

					}

					else
					{
						cout<<"\nNo students are scheduled here\n\n";
					}

					break;
				}

			case 0:
				{
					continue;
				}


		}

		



	}

	sickwrite();
	dropwrite();
	shrtatndwrite();




}



/******************************************************************************************************/
/************************************** FILE WRITING FUNCTION *****************************************/
/******************************************************************************************************/


void filewrite()
{
	ofstream input;
	input.open("record.txt", ios::app);


	input<<rollNumber<<","<<studentName<<","<<fathersName<<","<<dob<<","<<enrollmentDate<<","<<batch<<","<<department<<","<<offences<<","<<fine<<","<<sem<<","<<warning<<",";

	for ( int i=1 ; i<2 ; i++)
	{
		for ( int j=0 ; j<6 ; j++)
		{
			input<<semester[i][j]<<"," ;
		}
	}

	input<<endl;
	input.close();

}

/***************************************** END OF FUNCTION ********************************************/


void search()
{

	system("cls");
	cout<<setw(78)<<" ** iCOOPERATE **" <<endl;

	int x=0;
	char *a=new char [];
	char *b= new char [];
	char *c= new char[];
	int d=0;

	int k;

	ifstream fileread;

	fileread.open ("record.txt", ios::in);

	

	while (!fileread.eof())		
	{
		fileread.getline(a, 10000, '\n');
		if (strlen(a)==0)
			break;

		
		b=strtok(a, ",");

	
		k= atoi (b);


		if (k==rollNumber)
		{
			cout<<"Record Found\n";

			studentName=strtok(NULL,",");
			fathersName=strtok(NULL,",");
			dob=strtok(NULL,",");
			enrollmentDate=strtok(NULL,",");
			batch=strtok(NULL,",");
			department=strtok(NULL,",");
			offences=atoi (strtok(NULL,","));
			fine=atoi (strtok(NULL,","));
			sem=atoi (strtok(NULL,","));
			warning=atoi (strtok(NULL,","));
			semester[1][0]=atoi (strtok(NULL,","));
			semester[1][1]=atoi (strtok(NULL,","));
			semester[1][2]=atoi (strtok(NULL,","));
			semester[1][3]=atoi (strtok(NULL,","));
			semester[1][4]=atoi (strtok(NULL,","));
			semester[1][5]=atoi (strtok(NULL,","));

			

		}
		
	

	}


	cout<<"\nLatest Record Loaded\n";
	cout<<"Press any key to return to the main menu.."<<endl;

	fileread.close();

	getche();
	
	

}


void sickwrite()
{
	ofstream input;
	input.open("meetings.txt", ios::out);

	input<<sickcounter<<","<<criticality[1]<<","; ; 

	for ( int i=0 ; i<sickcounter ; i++ )
	{
		if ( sick [i] != 0 )
		{
			input<<sick[i]<<",";
		}
	
	}
	

	input.close();

}

/***************************************** END OF FUNCTION ********************************************/

void dropwrite()
{
	ofstream input;
	input.open("meetings1.txt" , ios::out);

	input<<dropcounter<<","<<criticality[2]<<",";
	for ( int i=0 ; i<dropcounter ; i++ )
	{

		if ( drop [i] != 0 )
		{
			input<<drop[i]<<",";
		}
	}
}

/***************************************** END OF FUNCTION ********************************************/

void shrtatndwrite()
{
	ofstream input;
	input.open("meetings2.txt" , ios::out);

	input<<shrtatndcounter<<","<<criticality[3]<<","; ;
	for (int i=0 ; i<shrtatndcounter ; i++ )
	{
		
		if ( shrtatnd [i] !=0 )
		{
			
			input<<shrtatnd[i]<<",";
		}
	}
}

/***************************************** END OF FUNCTION ********************************************/

void sickread()
{
	ifstream input;

	input.open("meetings.txt", ios::in);

	char *a=new char [];

	input.getline(a, 100, '\n');

	sickcounter= atoi (strtok (a, ","));
	criticality[1]= atoi (strtok (NULL, ","));

	for (int i=0; i<sickcounter; i++)
	{
		sick[i]=atoi (strtok (NULL, ","));
	}

	input.close();

}

/***************************************** END OF FUNCTION ********************************************/

void shrtatndread()
{
	ifstream input;

	input.open("meetings2.txt", ios::in);

	char *a=new char [];

	input.getline(a, 100, '\n');

	shrtatndcounter= atoi (strtok (a, ","));
	criticality[3]= atoi (strtok (NULL, ","));

	for (int i=0; i<shrtatndcounter; i++)
	{
		shrtatnd[i]=atoi (strtok (NULL, ","));
	}

	input.close();

}

/***************************************** END OF FUNCTION ********************************************/

void dropread()
{
	ifstream input;

	input.open("meetings1.txt", ios::in);

	char *a=new char [];

	input.getline(a, 100, '\n');

	dropcounter= atoi (strtok (a, ","));
	criticality[2]= atoi (strtok (NULL, ","));

	for (int i=0; i<dropcounter; i++)
	{
		drop[i]=atoi (strtok (NULL, ","));
	}

	input.close();

}

/***************************************** END OF FUNCTION ********************************************/