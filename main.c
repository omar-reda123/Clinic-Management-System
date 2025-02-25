#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "main.h"

//=Team======================================================  Display Main Menu ===========================================================

void Wellcome()
{
    printf("*************************************************\n");
    printf("*          DOCTOR INFORMATION BOARD             *\n");
    printf("*************************************************\n");
    printf("* Doctor    : Name of Doctor                    *\n");
    printf("* Specialty : Internal Medicine                 *\n");
    printf("*************************************************\n");
    printf("*              WORKING HOURS                    *\n");
    printf("*************************************************\n");
    printf("*  1:00 -  1:30  |                              *\n");
    printf("*  1:30 -  2:00  |                              *\n");
    printf("*  2:00 -  2:30  |                              *\n");
    printf("*  2:30 -  3:00  |                              *\n");
    printf("*  3:00 -  3:30  |                              *\n");
    printf("*  4:00 -  4:30  |                              *\n");
    printf("*  4:30 -  5:00  |                              *\n");
    printf("*************************************************\n");
    printf("*              EMERGENCY HOURS                  *\n");
    printf("*************************************************\n");
    printf("*  6:00 -  6:300 |        Emergency             *\n");
    printf("*  6:30 -  7:00  |        Emergency             *\n");
    printf("*************************************************\n");
    printf("* Degree    : Doctorate in Internal Medicine    *\n");
    printf("*************************************************\n");
}

//=Team======================================================  Display Main Menu ===========================================================

void Home_Menu()
{

    int option;
    do
    {
        printf("\tClinic Management System\n");
        printf("1. Admin Mode\n");
        printf("2. User mood\n");
        printf("3. Exit\n");
        printf("Enter your option: ");
        fflush(stdin);
        scanf("%i", &option);

        switch(option)
        {
            case 1:
                Admin_Login();
                return ;
                break;
            case 2:
                User_Mood();
                break;
            case 3:
                printf("you are out of system!!!");
                option=3;
                break;
            default:
                printf("invalid!! please try again!!");
        }

    }while(option!=3);

}
//=Omar======================================================  Admin Login ============================================================
void Admin_Login()
{
    int password;
    int attempts=0;

    while(attempts<6)
    {
    printf("Enter password:\n");
    fflush(stdin);
    scanf("%i",&password);
        if(password==1234)
        {
            printf("Admin mode accessed!!");
            Admin_Menu();
            return;
        }
        else
        {
            printf("incorrect!!try again\n");
            attempts++;
            if(attempts==3)
            {
                printf(" you Entered incorrect password 3 times ! \n");
                printf(" you must wait 15s until lastest 3 times  \n");
                for(int i = 0 ; i<=15 ; i++)
                {
                    fflush(stdout);
                    printf("\a");
                    usleep(300000);
                    printf("%d\n",i);
                }
            }
        }
    }
    return ;

}
//=Team======================================================  Admin Menu ============================================================
void Admin_Menu()
{

    int choice;
    do
    {
        printf("\nAdmin Menu\n");
        printf("1. Reserve Slot\n");
        printf("2. Edit Patient Record\n");
        printf("3. Cancel Reservation\n");
        printf("4. usermood\n");
        printf("5. Logout\n");

        printf("Enter your choice: ");
        fflush(stdin);
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: Reserve_Slot(); break;
            case 2: Edit_Patient_Record(); break;
            case 3: Cancel_Reservation(); break;
            case 4: User_Mood(); Home_Menu(); break;
            case 5: printf("Logging out...\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while(choice != 4);

}
//=Mohamed======================================================  edit Patient Record ============================================================
int Search_Patient(int patientID)
{
    int i;
    for (i =0;i<MAX_PATIENTS;i++)
        {
            if (patients[i].patientID==patientID&&patients[i].patientID!=0)
                return (i) ;
        }
return -1 ;
}
void Edit_Patient_Record()
{
   int Back_choice;
   int exit_flag = 0;
     while(exit_flag==0)
    {
        int ID,Index;
        //////////////////////////////
        printf("Welcom to Edit mode....\n");
        printf("please enter the ID..\n");
        fflush(stdin);
        scanf("%i",&ID);
        Index=Search_Patient(ID);
        //////////////////////////////
         if(Index>-1)
         {
             printf("Patient details....\n");
void Print_Patient_Data(int ID);//Rawda========================= works well
             Print_Patient_Data(Index);
            ////////////////////////////////////////////////////
             printf("what do you want to Edit...\n");
             printf("1. Name \n");
             printf("2. Age \n");
             printf("3. Gender \n");
             printf("4. Rservation \n");
             printf("5. All \n");
             printf("6. Exit \n");
             printf("your choice is : \n");
             int choice;
             fflush(stdin);
             scanf("%i",&choice);
            /////////////////////////////////////////////////
            switch(choice)
            {
            case 1:
                printf("New Name is:\n");
                getchar();
                fgets(patients[Index].name,50,stdin);
                printf("update Patient details....\n");
                Print_Patient_Data(Index);
                exit_flag = 1;
                break;
             //********************************************* //
            case 2:
                printf("New Age is:\n");
                fflush(stdin);
                scanf("%i",&patients[Index].age);

                printf("update Patient details....\n");
                Print_Patient_Data(Index);
                exit_flag = 1;
                break;
            //********************************************* //
            case 3:
                printf("New Gender is:\n");
                getchar();
                fgets(patients[Index].gender,10,stdin);


                printf("update Patient details....\n");
                Print_Patient_Data(Index);
                exit_flag = 1;
                break;
            //********************************************* //
            case 4:
                  printf("Editing main Reservation:\n");
                  Edit_Reserve(ID,Index);
                  exit_flag=1;
                  break;
            //******************************************* //
            case 5:
                printf("New Name is:\n");
                getchar();
                fgets(patients[Index].name,50,stdin);
           //////////////////////////////////////////
                printf("New Age is:\n");
                fflush(stdin);
                scanf("%i",&patients[Index].age);
           ////////////////////////////////////////
                printf("New Gender is:\n");
                getchar();
                fgets(patients[Index].gender,10,stdin);
                /////////////////////////////////////
                printf("Editing main Reservation:\n");
                Edit_Reserve(ID , Index );
          /////////////////////////////////////////////////////////
                exit_flag = 1;
                break;
          //********************************************* //
            case 6:
                printf("Exiting Edit Mode...\n");
                Admin_Menu();
                exit_flag = 1;
                break;
        //********************************************* //

            default:
                printf("invalid choice , Try again \n");
                continue;
            }


         }

            else
        {

                printf(" sorry , The ID is not exist \n");
                break;

        }


    }
//Mohamed
}

//=Eslam======================================================  Reserve a Slot ============================================================
//
void Reserve_Slot()
{
    if(patientCount<35)
    {
        if(slotCount<35)
        {
            int choice;
    do
    {
        printf("\n You want : \n");
        printf("1. Register as New patient\n");
        printf("2. Register as pre-existing patient\n");
        printf("3. Register as Emergency patient\n");
        printf("4. Back\n");

        printf("Enter your choice: ");
        fflush(stdin);
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: New_Patient();choice=4; break;
            case 2: Existing_Patient(); choice=4; break;
            case 3: Emergency_Patient(); choice=4; break;
            case 4: printf("back step\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while(choice != 4);
        }
    }

}
//=Amir======================================================  Cancel a Reservation ============================================================
void Delete_Patient_Data(int PatientLocation)
{
    patients[PatientLocation].age = 0;
    patients[PatientLocation].patientID= 0;
    strcpy(patients[PatientLocation].gender, "");
    strcpy(patients[PatientLocation].name, "");
    patientCount--;
}

void Cancel_Reservation()
{

    int ID;
    int PatientLocation;
    int flag = 0 ;
    printf(" Enter Your ID .\n");
    fflush(stdin);
    scanf("%d", &ID);
    PatientLocation = Search_Patient(ID);

    if (PatientLocation !=-1)
    {
      printf("User existed .\n");
      if(patients[PatientLocation].consult_flag==0)
      {
        for (int d = 0; d < DAYS_IN_WEEK; d++)
        {
          for (int s = 0; s < SLOTS_PER_DAY; s++)
          {

            if (busySlots[d][s]==ID)
            {
                 busySlots [d] [s] = 0;//
                 availableSlots[d][s] = 1;
                 slotCount--;
                 Delete_Patient_Data (PatientLocation);
                 printf(" We canceled your slot and deleted your data .\n");
            }
          }
        }
      }
      else
      {
        while(flag==0)
        {
            for (int d = 0; d < DAYS_IN_WEEK; d++)
            {
              for (int s = 0; s < SLOTS_PER_DAY; s++)
              {

                  if (busySlots[d][s]==ID)
                {
                    if(flag==0)
                    {
                        flag=1;
                    }
                    else
                    {
                        busySlots [d] [s] = 0;//
                        availableSlots[d][s] = 1;
                        slotCount--;
                        patients[PatientLocation].consult_flag=0;
                        printf(" We canceled your consultation .\n");
                    }
                }
              }
            }
         patients[PatientLocation].consult_flag=0;
        }
      }

      }

    else
    {
      printf("User not found");
    }

  }

//==Eslam====================================================== User mood  ============================================================
void User_Mood()
{

    int choice;
    do
    {
        printf("\n User  Menu\n");
        printf("1. view Patient Record \n");
        printf("2. view Reservations in day  \n");
        printf("3. view all Reservations in week \n");
        printf("4. view all Emergency slots in week \n");
        printf("5. Logout\n");

        printf("Enter your choice: ");
        fflush(stdin);
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: View_Patient_Data(); break;
            case 2: view_Day_Reservations(); break;
            case 3: Print_All_Slots_Week(); break;
            case 4: Print_All_Emergency_Slots_Week(); break;
            case 5: printf("Logging out...\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while(choice != 4);

}
//==Rawda====================================================== View Patient Record ============================================================
void View_Patient_Data()
{

    int patientID;
    printf("PLEASE ENTER YOUR ID: \n");
    fflush(stdin);
    scanf("%d",&patientID);

        int ID = Search_Patient(patientID);
        if (ID  == -1)
        {
            printf(" There is no any patient with this ID\n");
        }
        else
        {
            printf("The Basic Information Of The Patient`s IS : \n");
            Print_Patient_Data(ID);

        }
}
//==Rawda====================================================== view Reservations ============================================================
void view_Day_Reservations()
{
    int day;
    printf("Enter the day number : \n1 for Sat. \n2 for Sun. \n3 for Mon. \n4  for Tues.\n5 for Wed. \n6  for Thu. \n7 for Fri.): ");
    fflush(stdin);
    scanf("%d", &day);
    day--; 

    if (day < 0 || day > 6) 
        printf("Invalid day!\n");
    else   
          {  printf("Today's Reservations with patints ID and Time Slot :\n");
             printf("\nReservations for Day %d:\n", day + 1);
             printf("-------------------------------------------------\n");
             printf("|       Time Slot        |     Patient ID       |\n");
             printf("-------------------------------------------------\n"); 
        
             

            int flag = 0;  //<There is no Reservation if flag =0 >  < flag=1 Reservation >

  
        for (int slot = 0; slot < SLOTS_PER_DAY; slot++)
        {
            if (busySlots[day][slot] != 0) //<There is Reservation in Day>
                {
                    flag = 1;
                    printf("| ");
                    switch (slot)
                    {
                         case 0:  printf("Time: from 2:00 to 2:30  \t"); break;
                         case 1:  printf("Time: from 2:30 to 3:00  \t"); break;
                         case 2:  printf("Time: from 3:00 to 3:30  \t"); break;
                         case 3:  printf("Time: from 4:00 to 4:30  \t"); break;
                         case 4:  printf("Time: from 4:30 to 5:00  \t"); break;
                    }
                        printf("|        %d        |\n", busySlots[day][slot]);
                 }
        }
      if(!flag )
      {
                       printf("|     No reservations for today.               |\n");
        }
                       printf("-------------------------------------------------\n");
    }
}
//==Amir===========================================================check patient researve ====================================================

int Check_Patient_researve(int patientID)
{

  int PatientLocation;
  PatientLocation = Search_Patient(patientID);

  if (PatientLocation != -1)
  {
    printf("User existed .\n");
    for (int d = 0; d < DAYS_IN_WEEK; d++)
    {
      for (int s = 0; s < SLOTS_PER_DAY; s++)
      {
        if (busySlots[d][s] == patientID)
        {
          return 1;
        }
      }
    }
  }

  else
  {
    printf("User not found");
    return 0;
  }
  return 0 ;
}
//Omar======================================================new patient============================================================

void NewPatient()
{
    if(patientCount<35&&slotCount<35&&FirstEmptyIndex()!=-1)
    {
         int index=FirstEmptyIndex();
         int id;
         int flag = 0 ;

         do
         {
            printf("Entering new patient data:\n");
            printf("* Note that: \n1-ID must contain 4 numbers not started whith 0 \n 2-ID must be unique \n");
            printf(" Enter ID:\n");
            scanf("%i",&id);
            if(checkIDavailable(id)==1)
            {
              printf("Did user pay %i $?:\nif Yes, Enter 1 \n if No, press any thing else \n",price);
              int cost_flag=0;
              fflush(stdin);
              scanf("%i",&cost_flag);
              if(cost_flag==1)
              {
               printf("User paid %i $!!\n",price);
               patients[index].patientID=id;
               printf("Enter name:\n");
               getchar();
               fgets(patients[index].name,50,stdin);

               printf("Enter age:\n");
               scanf("%i",&patients[index].age);

               printf("Enter gender:\n");
               getchar();
               fgets(patients[index].gender,10,stdin);
               reserveingSlot(id);

               int edit_confirm;
               printf("Do yo want to edit any patient data?\n");
               printf("if yes>>press 1\n");
               printf("if no>>press any number\n");
               fflush(stdin);
               scanf("%i",&edit_confirm);

               if(edit_confirm==0)
               {
                   editPatientRecord();
               }
               printf("Patient data successfully added!!\n");
               patientCount++;

               flag=1;
              }
              else
              {
                  flag=1;
                  printf("No data added for this user!\n");
              }

            }
            else
            {
                printf(" Invalid ID \n");
                printf(" try another one \n");
            }
         } while (flag==0);

    }
    else
    {
        printf("Maximum weekly capacitance reached!!\n");
    }
}

int First_Empty_Index()
{
    int i;
    for (i = 0; i < MAX_PATIENTS; i++)
    {
        if (strcmp(patients[i].name, "") == 0 &&
            patients[i].age == 0 &&
            strcmp(patients[i].gender, "") == 0 &&
            patients[i].patientID == 0)
        {
            return i; // Return the first empty index found
        }
    }
    return -1; // Return -1 if no empty slot is found
}
//==Eslam============================================================Existing Patient ====================================================
void Existing_Patient()
{
  int ID ;
  int PatientLocation ;

  printf(" Enter Your ID .\n");
  fflush(stdin);
  scanf("%d",&ID);
  PatientLocation=Search_Patient(ID);//  PatientLocation=searchPatient(ID)-1;
  if(PatientLocation==-1)
  {
    printf(" We don't have this ID ");
  }
  else
  {
    if(patients[PatientLocation].consult_flag==1)
    {
    printf(" You already recorded slot and consultation ");
    }
    else
    {
        Choose_Slot(ID);
        patients[PatientLocation].consult_flag=1;
        printf("Consultation is for free!\n");
    }
  }
}
//============================================================== reserveing Slot ====================================================

void Choose_Slot(int ID )
{
    int day =0 , slot = 0 , counter =0 , flag =0  ;
    if(slotCount>=35)
     {
        printf(" NO slots available in this week ");
     }
    else
    {
        Print_All_Slots_Week();
        do
        {
                printf(" choose day : \n");
                printf(" 1-Saturday  \n");
                printf(" 2-Sunday : \n");
                printf(" 3-Monday : \n");
                printf(" 4-Tuesday : \n");
                printf(" 5-Wednesday : \n");
                printf(" 6-Thursday : \n");
                printf(" 7-Friday : \n");
                fflush(stdin);
                scanf("%d",&day);
                if (day < 1 || day > 7)
                {
                    printf("Invalid day! Please choose between 1 and 7.\n");
                    continue;
                }
                ////////////////////////////////////////////////////////////
                counter=0;
                printf(" Empty slots : \n");
                if(availableSlots[day-1][0]==1)
                                {printf(" 1- 2:00 to 2:30   \n");counter++;}
                if(availableSlots[day-1][1]==1)
                                {printf(" 2- 2:30 to 3:00   \n");counter++;}
                if(availableSlots[day-1][2]==1)
                                {printf(" 3- 3:00 to 3:30   \n");counter++;}
                if(availableSlots[day-1][3]==1)
                                {printf(" 4- 4:00 to 4:30   \n");counter++;}
                if(availableSlots[day-1][4]==1)
                                {printf(" 5- 4:30 to 5:00   \n"); counter++;}
                /////////////////////////////////////////////////////////////
                if (counter==0)
                    printf(" NO empty slots in this day \n please chooe another day");
                else
                {
                    printf(" choose one of these %i slots ",counter);
                    fflush(stdin);
                    scanf("%d",&slot);
                    if(slot>5||slot<1||availableSlots[day-1][slot - 1] == 0)
                    {
                        printf("invalid slot\n");
                    }
                    else
                    {
                        availableSlots[day-1][slot-1]=0;
                        busySlots[day-1][slot-1]=ID;
                        slotCount++;
                        flag=1;
                        if(patients[Search_Patient(ID)].consult_flag==1)
                        {
                          int bookFlag=0;
                        for(int day0 = 0 ; day0< DAYS_IN_WEEK;day0++)
                            {
                                for(int slot0=0 ; slot0 < SLOTS_PER_DAY ;slot0++ )
                                {
                                    if (bookFlag==1) continue;
                                    if(busySlots[day0][slot0]==busySlots[day-1][slot-1])
                                    {
                                        if(day-1>day0)
                                        // if((day-1>day0)||(day-1==day0&&slot-1>slot0)||!((day-1==day0&&slot-1==slot0)))
                                            printf(" your consultation booked ");
                                            flag=1;
                                    }
                                    else
                                    {
                                        busySlots[day-1][slot-1]=0;
                                        availableSlots[day-1][slot-1]=1;
                                        slotCount--;
                                        flag=0;
                                        printf(" you can't book consultation before your slot ");
                                        printf(" choose another slot ");
                                        bookFlag=1;
                                    }
                                }
                                }
                        }
                    }
                }

        } while(flag==0);
    }
}
//==Eslam============================================================ check ID available ====================================================

int Check_ID_Available(int ID)
{
    
if(ID>=1000&&ID<=9999)
{
    for(int i =0 ; i<patientCount;i++)
    {
        if(patients[i].patientID==ID)
            {
                return 0 ;
            }
    }
return 1 ;
}
return 0 ;
}
//============================================================== print patient data ====================================================
void Print_Patient_Data(ID)
{
    printf("\n----------------------------------------\n");
    printf("| Details           | Value            |\n");
    printf("----------------------------------------\n");
    printf("| ID               | %d              |\n", patients[ID].patientID);
    printf("| Name             | %-15s |\n", patients[ID].name);
    printf("| Age              | %d              |\n", patients[ID].age);
    printf("| Gender           | %-10s     |\n", patients[ID].gender);
    // printf("| Consultation     | %-10s     ", (patients[ID].consult_flag == 1) );
        if(patients[ID].consult_flag)
        printf(" %-10i |\n", patients[ID].consult_flag);
        else 
        {
            const char *str = NULL;
            printf("  %-14s|\n", str ? str : "(null)");
        }

    printf("----------------------------------------\n");
}
//============================================================== edit Reserve =============================================================
void Edit_Reserve(int ID, int Index)
 {
      for (int i = 0; i < DAYS_IN_WEEK; i++)
          {
                 for (int j = 0; j < SLOTS_PER_DAY; j++)
            {

          if (busySlots[i][j]==ID)
         {
            Choose_Slot(ID);
             availableSlots[i][j]=1;
             busySlots[i][j]=0;
             slotCount--;
             ////////////////////////
             printf("Patient details....\n");
             Print_Patient_Data(Index);
             printf("Reservation has  changed....\n");
             break;
         }

           }

          }

 }
//============================================================== Print_All_Slots_Week =============================================================
 void Print_All_Slots_Week()
 {
    printf("\n========================================================================================================================================\n");
    printf("\n|                                                             Weekly slots                                                             |\n");
    printf("\n========================================================================================================================================\n");
    printf("| Slot / Day     |     Saturday   |     Sunday     |     Monday     |    Tuesday     |    Wednesday   |     Thursday   | Friday         |\n");
    printf("|----------------|----------------|----------------|----------------|----------------|----------------|----------------|----------------|\n");
    const char timeSlots[5][13] = {"2:00 to 2:30", "2:30 to 3:00", "3:00 to 3:30", "4:00 to 4:30", "4:30 to 5:00"};
    
    for(int slot = 0 ; slot < 5 ; slot++ ) {
        printf("| %-14s |", timeSlots[slot]);
        for (int day = 0; day < 7 ; day++ ) 
        {
            if(busySlots[slot][day])
            printf(" %-14i |", busySlots[slot][day]);
            else 
            {
                const char *str = NULL;
                printf("  %-14s|\n", str ? str : "(null)");
            }


        }
        printf("\n|----------------|----------------|----------------|----------------|----------------|----------------|----------------|----------------|\n");
    }
}
//============================================================== Print_All_Emergency_Slots_Week =============================================================
void Print_All_Emergency_Slots_Week()
{
   printf("\n========================================================================================================================================\n");
   printf("\n|                                                             Emergency slots                                                           |\n");
   printf("\n========================================================================================================================================\n");
   printf("| Slot / Day     |     Saturday   |     Sunday     |     Monday     |    Tuesday     |    Wednesday   |     Thursday   | Friday         |\n");
   printf("|----------------|----------------|----------------|----------------|----------------|----------------|----------------|----------------|\n");
   const char timeSlots[2][13] = {"6:00 to 6:30", "6:30 to 7:00"};
   const char *str = NULL;
   for(int slot = 0 ; slot < Emergency_SLOTS_PER_DAY ; slot++ ) {

    printf("  %-14s|\n", str ? str : "(null)");
       for (int day = 0; day < 7 ; day++ ) 
       {
           if(busySlots[slot][day])
           printf(" %-14i |", EmergincySlots[slot][day]);
           else 
           {
            printf("  %-14s|\n", str ? str : "(null)");
           }


       }
       printf("\n|----------------|----------------|----------------|----------------|----------------|----------------|----------------|----------------|\n");
   }
}
//============================================================== choose emergency =============================================================
void Choose_Emergency_Slot(int ID )
{
    int day =0 , slot = 0 , counter =0 , flag =0  ;
    if(EmergencyCount>=MAX_EMERGENCY)
     {
        printf(" NO slots available in this week ");
     }
    else
    {
        Print_All_Emergency_Slots_Week();
        do
        {
                printf(" choose day : \n");
                printf(" 1-Saturday  \n");
                printf(" 2-Sunday : \n");
                printf(" 3-Monday : \n");
                printf(" 4-Tuesday : \n");
                printf(" 5-Wednesday : \n");
                printf(" 6-Thursday : \n");
                printf(" 7-Friday : \n");
                fflush(stdin);
                scanf("%d",&day);
                if (day < 1 || day > 7)
                {
                    printf("Invalid day! Please choose between 1 and 7.\n");
                    continue;
                }
                ////////////////////////////////////////////////////////////
                counter=0;
                printf(" Empty slots : \n");
                if(EmergincySlots[day-1][0]==0)
                                {printf(" 1- 6:00 to 6:30   \n");counter++;}
                if(EmergincySlots[day-1][1]==0)
                                {printf(" 2- 6:30 to 7:00   \n");counter++;}
                /////////////////////////////////////////////////////////////
                if (counter==0)
                    printf(" NO empty slots in this day \n please chooe another day");
                else
                {
                    printf(" choose one of these %i slots ",counter);
                    fflush(stdin);
                    scanf("%d",&slot);
                    if(slot>2||slot<1||EmergincySlots[day-1][slot-1] != 0)
                    {
                        printf("invalid slot\n");
                    }
                    else
                    {
                        EmergincySlots[day-1][slot-1]=ID;
                        EmergencyCount++;
                        flag=1;
                    }
                }
        }while(flag==0);
    }
} 



void Emergency_Patient()
{
    if(EmergencyCount<MAX_EMERGENCY)
    {
        int index=First_Empty_Index();

         printf("Entering new patient data:\n");

         printf("Enter name:\n");
         getchar();
         fgets(patients[index].name,50,stdin);

         printf("Enter age:\n");
         fflush(stdin);
         scanf("%i",&patients[index].age);

         printf("Enter gender:\n");
         getchar();
         fgets(patients[index].gender,10,stdin);

         int id;
         int flag = 0 ;
         do
         {
            printf("* Note that: \n1-ID must contain 4 numbers not started whith 0 \n 2-ID must be unique \n");
            printf(" Enter ID:\n");
            fflush(stdin);
            scanf("%i",&id);
            if(Check_ID_Available(id)==1)
            {

                printf("Did user pay %i $?:\nif Yes, Enter 1 \n if No, press any thing else \n",price);
                int cost_flag=0;
              fflush(stdin);
              scanf("%i",&cost_flag);
              if(cost_flag==1)
              {
               printf("User paid %i $!!\n",price);
               patients[index].patientID=id;
               Choose_Slot(id);
               printf("Patient data successfully added!!\n");
               patientCount++;
               flag++;
              }
              else
              {
                  flag=1;
                  printf("No data added for this user!\n");
              }

            }
            else
            {
                printf(" Invalid ID \n");
                printf(" try another one \n");
            }
         } while (flag==0);

    }
    else
    {
        printf("Maximum weekly capacitance reached!!\n");
    }

}
