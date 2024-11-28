#include <iostream>
#include <fstream>
using namespace std;

class bus
{
    string bus_no, bus_driver_name, arrival_time, departure_time, to, from;
    int bus_seats;

public:
    void menu();
    void install_bus();
    void display_bus();
    void delete_bus();
    void bus_seats_details();
    void reservation();
    void update_booking();
    void del_booking();
    void show_booking();
};

void decorate(char c)
{
    for(int i=0;i<150;i++)
        cout<<c;
    cout<<endl;
}

void bus::menu()
{

    while (1)
    {
        int choice;
        cout<<endl;
        decorate('-');
        cout << "\n\t\t SRM BUS RESERVATION SYSTEM    \n";
        decorate('-');

        cout << "\n\n **MAIN MENU**";
        cout << "\n\n 1. INSTALL BUS DETAILS";
        cout << "\n 2. DELETE BUS DETAILS";
        cout << "\n 3. DISPLAY BUSES";
        cout << "\n 4. AVAIABLE SEATS DETAILS ";
        cout << "\n 5. RESERVATION";
        cout << "\n 6. UPDATE BOOKING RECORD";
        cout << "\n 7. DELETE BOOKING RECORD";
        cout << "\n 8. SHOW ALL BOOKING RECORD";
        cout << "\n 9. EXIT";
        cout << "\n\n ENTER YOUR CHOICE : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            install_bus();
            break;
        case 2:
            delete_bus();
            break;
        case 3:
            display_bus();
            break;
        case 4:
            bus_seats_details();
            break;
        case 5:
            reservation();
            break;
        case 6:
            update_booking();
            break;
        case 7:
            del_booking();
            break;
        case 8:
            show_booking();
            break;
        case 9:
            exit(0);

        default:
            cout << "Invalid choice";
        }
    }
}

void bus::install_bus()
{
here:

    fstream file;
    string test_no, test_bus_name, test_driver_name;
    string test_arrival_time, test_departure_time,test_to,test_from; // These variables are for to check whether same variables exist or not
    int test_seats;
    int found = 0; // When no record or file found then found=0

    cout << "\n\n Enter the bus number :";
    cin >> bus_no;

    cout << "\n\n Enter the Driver name : ";
    cin >> bus_driver_name;

    cout << "\n\n Enter the arrival time : ";
    cin >> arrival_time;

    cout << "\n\n Enter the departure time : ";
    cin >> departure_time;

    cout<<"\n\n From :  ";
    cin>>from;

    cout<<"\n\n To : ";
    cin>>to;

    cout << "\n\n Enter the total Seats : ";
    cin >> bus_seats;


    file.open("bus.txt", ios::in); // To read whether there exisit or not to avoid duplicate of same bus information

    if (!file) // No file exist-->Creating new file
    {
        file.open("bus.txt", ios::app | ios::out);

        file << bus_no << " " << bus_driver_name<<" "<< arrival_time << " " << departure_time << " " << from <<" "<<to<<" "<< bus_seats<<" "<< endl;

        file.close();
    }
    else // File exists->Check whether same information is there or not
    {
        file >> test_no>>test_driver_name>>test_arrival_time>>test_departure_time>>test_from>>test_to>>bus_seats;
        
        while (!file.eof())
        {
            if (bus_no == test_no)
            {
                found++;
            }
            file >> test_no>>test_driver_name>>test_arrival_time>>test_departure_time>>test_from>>test_to>>bus_seats;
            
        }
        file.close();

        if (found == 0) // record no exist(same) -->then copy inside record
        {
            file.open("bus.txt", ios::app | ios::out);

            file << bus_no << " " << bus_driver_name << " "<< arrival_time << " " << departure_time << " " << from <<" "<<to<<" "<< bus_seats<<" "<< endl;

            file.close();
        }

        else
        {
            cout << "\n\n Duplicate Record found";
            goto here;
        }
    }
    cout << "\n\nBus installed successfully";
}


void bus::display_bus()
{
    fstream file;
   

    file.open("bus.txt", ios::in);

    if (!file) // No file created
    {
        cout << "\n\nFile openeing Error";
    }

    else
    {
        cout << "\n\n BUS NO.\tDRIVER NAME\tARRIVAL TIME\tDEPARTURE TIME\tFROM\t\tTO\t\tNO. OF SEATS";

        file>>bus_no>>bus_driver_name>>arrival_time>>departure_time>>from>>to>>bus_seats;


        while (!file.eof())
        {

            cout<<"\n"<<bus_no<<"\t\t"<<bus_driver_name<<"\t\t"<<arrival_time<<"\t\t"<<departure_time<<"\t\t"<<from<<"\t\t"<<to<<"\t\t"<<bus_seats<<endl;

            file>>bus_no>>bus_driver_name>>arrival_time>>departure_time>>from>>to>>bus_seats;

        }
    }
    file.close();
}


void bus::delete_bus()
{
    fstream file,file1;

    string test_num;
    int found = 0;

    file.open("bus.txt",ios::in);

    if(!file)
    {
        cout<<"\n\n File not found.";
    }
    else
    {
        cout<<"\n\n Enter the bus number to be deleted : ";
        cin>>test_num;

        file1.open("bus1.txt",ios::app|ios::out);
        file>>bus_no>>bus_driver_name>>arrival_time>>departure_time>>from>>to>>bus_seats;

        while(!file.eof())
        {
            if(test_num == bus_no)
            {
                cout<<"\n\n\n Bus has been deleted.";
                found++;
            }
            else{
                file1 << bus_no << " " << bus_driver_name << " "<< arrival_time << " " << departure_time << " " << from <<" "<<to<<" "<< bus_seats<<" "<< endl;
            }

            file>>bus_no>>bus_driver_name>>arrival_time>>departure_time>>from>>to>>bus_seats;
        }

        file.close();
        file1.close();
        remove("bus.txt");
        rename("bus1.txt","bus.txt");
        if(found == 0)
        {
            cout<<"\n\nBus number is Invalid";
        }

    }
}


void bus::bus_seats_details()
{
    fstream file,file1; // file --> bus details , file1 -->seats details
    file.open("bus.txt",ios::in);
    file1.open("seat.txt",ios::in);//will come when reservation is used

    string test_no,seats_bus_num,seats_num;
    int count=0; //for reserved seats
    int found=0;

    if(!file || !file1) // File was not found
    {
        cout<<"\n\nFile not found.. !! ";
    }
    else{
        cout<<"\n\n Enter the Bus Number : ";
        cin>>test_no;
        file1>>seats_bus_num>>seats_num;
        while(!file1.eof())
        {
            if(test_no == seats_bus_num)
            {
                count++;
            }
            file1>>seats_bus_num>>seats_num;
        }
        file1.close();

        file>>bus_no>>bus_driver_name>>arrival_time>>departure_time>>from>>to>>bus_seats;
        while(!file.eof())
        {
            if(test_no == bus_no)
            {
                cout<<"\n\n Total number of seats : "<<bus_seats;
                cout<<"\n\n Reserved number of seats : "<<count;
                cout<<"\n\n Empty number of seats : "<<bus_seats-count;

                found++;
                cout<<endl<<endl;
            }
            file>>bus_no>>bus_driver_name>>arrival_time>>departure_time>>from>>to>>bus_seats;

        }
        file.close();

        if(found == 0)
        {
            cout<<"\n\n Bus number is invalid ";
        }
    }
}

void bus:: reservation()
{
    p:

    fstream file;
    file.open("bus.txt",ios::in);
    string t_no,s_b_no,student_name,phone;
    int found =0,s_no,seats,count=0,s_s_no; //s_no selected seat no to book, seats -> total no of seats , count-> To check all seats are reserved or not.
    if(!file)
    {
        cout<<"\n\n File Opening error";
        cin>>t_no;
        
    }
    else
    {
        cout<<"\n\n Enter the bus number : " ;
        cin>>t_no;

        file.close();
        file.open("seat.txt",ios::in);

        if(file) // File exists
        {
            file>>s_b_no>>s_s_no;

            while(!file.eof())
            {
                if(t_no == s_b_no)
                    count++;

                file>>s_b_no>>s_s_no;
            }

            file.close();
        }

        file.open("bus.txt",ios::in);

        file>>bus_no>>bus_driver_name>>arrival_time>>departure_time>>from>>to>>bus_seats;    
        while(!file.eof())
        {
            if(t_no == bus_no)
            {
                seats = bus_seats;
                found++;
            }

            file>>bus_no>>bus_driver_name>>arrival_time>>departure_time>>from>>to>>bus_seats;
        }

        file.close();

        if(seats - count == 0)
            cout<<"\n\n All seats are reserved";

        else if(found == 1)
        {
            h:

            cout<<"\n\n Enter the Seat number : ";
            cin>>s_no;

            if(s_no > seats)
            {
                cout<<"\n\n Seat number is Invalid.";
                goto h;
            }
            file.open("seat.txt",ios::in);

            if(!file) //new file ->all seats empty
            {
                file.open("seat.txt",ios::app | ios:: out);

                file<<t_no<<" "<<s_no<<"\n";

                file.close();
            }
            else // File exist ->To check if the seat is reserveed or not
            {
                file>>s_b_no>>s_s_no;
                while(!file.eof())
                {
                    if(t_no == s_b_no && s_no == s_s_no) // bus no and seat no matches
                    {
                        cout<<"\n\n This seat is already reserved";
                        goto h;
                    }

                    file>>s_b_no>>s_s_no;
                }
                file.close();

                file.open("seat.txt",ios::app | ios:: out);

                file<<t_no<<" "<<s_no<<"\n";
                
                file.close();
                
            }

            cout<<"\n\n Enter your name : ";
            cin>>student_name;

            cout<<"\n\n Enter your phone number : ";
            cin>>phone;

            file.open("student.txt",ios::app | ios::in);

            file<<student_name<<" "<<t_no<< " "<<phone<<endl;

            file.close();

            decorate('*');
            cout<<"\n\n Booking Information \n";
            decorate('*');

            cout<<"\n\n Student Name :          "<<student_name;
            cout<<"\n\n Phone Number :           "<<phone;
            cout<<"\n\n Seat number :            "<<s_no;
            cout<<"\n\n Booking Succesful";

        }
        else{
            cout<<"\n\n Bus number is Invalid";
            goto p;
        }
    }
}

void bus:: update_booking()
{
    fstream file,file1;
    int t_seats,found = 0,del_seats,i=0;
    string name,no,phone,t_name,t_phone,del_no;//no-bus no


    file.open("student.txt",ios::in);

    if(!file)
    {
        cout<<"\n\n File not found";
    }
    else
    {
        cout<<"\n\n Enter your phone number : ";
        cin>>t_phone;

        file>>name>>no>>phone>>t_seats;

        while(!file.eof())
        {
            if(t_phone == phone)
            {
                file.close();
                file.open("student.txt",ios::in);
                file1.open("student1.txt",ios::app|ios::out);
                file>>name>>no>>phone>>t_seats;

                while(!file.eof())
                {
                    if(t_phone == phone) // To clear previous seats which were reserved in the previous bookings
                    {
                        del_no = no;
                        del_seats = t_seats;
                    }

                    if(t_phone != phone)
                    {
                        file1<<name<<" "<<no<<" "<<phone<<" "<<t_seats<<endl;
                    }
                    file>>name>>no>>phone>>t_seats;
                }
                file.close();
                file1.close();

                remove("student.txt");
                rename("student1.txt","student.txt");

                file.open("seat.txt",ios::in);
                file1.open("seat1.txt",ios::app | ios:: out);
                file>>no>>t_seats;
                while(!file.eof())
                {
                    if(!(del_no == no && i<del_seats))
                    {
                        file1<<no<<" "<<t_seats<<endl;
                    }
                    file>>no>>t_seats;
                }
                file.close();
                file1.close();

                remove("seat.txt");
                rename("seat1.txt","seat.txt");

                reservation();
                cout<<"\n\n Updated Reserved Seats";

                found++;
                goto h;
            }
            file>>name>>no>>phone>>t_seats;
        }
        file.close();

        h:
        if(found == 0)
        {
            cout<<"\n\n Phone number is Invalid.";
        }
    }
    
}

void bus:: del_booking()
{
    fstream file,file1;
    int t_seats,found = 0,del_seats,i=0;
    string name,no,phone,t_name,t_phone,del_no;//no-bus no


    file.open("student.txt",ios::in);

    if(!file)
    {
        cout<<"\n\n File not found";
    }
    else
    {
        cout<<"\n\n Enter your phone number : ";
        cin>>t_phone;

        file>>name>>no>>phone>>t_seats;

        while(file.eof())
        {
            if(t_phone == phone)
            {
                file.close();
                file.open("student.txt",ios::in);
                file1.open("student1.txt",ios::app|ios::out);
                file>>name>>no>>phone>>t_seats;

                while(!file.eof())
                {
                    if(t_phone == phone) // To clear previous seats which were reserved in the previous bookings
                    {
                        del_no = no;
                        del_seats = t_seats;
                    }

                    if(t_phone != phone)
                    {
                        file1<<name<<" "<<no<<" "<<phone<<" "<<t_seats<<endl;
                    }
                    file>>name>>no>>phone>>t_seats;
                }
                file.close();
                file1.close();

                remove("student.txt");
                rename("student1.txt","student.txt");

                file.open("seat.txt",ios::in);
                file1.open("seat1.txt",ios::app | ios:: out);
                file>>no>>t_seats;
                while(!file.eof())
                {
                    if(!(del_no == no && i<del_seats))
                    {
                        file1<<no<<" "<<t_seats<<endl;
                    }
                    file>>no>>t_seats;
                }
                file.close();
                file1.close();

                remove("seat.txt");
                rename("seat1.txt","seat.txt");
                cout<<"\n\n Deleted Reserved Seats.";

                found++;
                goto h;
            }
            file>>name>>no>>phone>>t_seats;
        }
        file.close();

        h:
        if(found == 0)
        {
            cout<<"\n\n Phone number is Invalid.";
        }
    }    
}

void bus:: show_booking()
{
    fstream file;
    int t_seats,found=0;
    string name,no,phone;

    file.open("student.txt",ios::in);

    if(!file)
    {
        cout<<"\n\nFile Opening Error";
    }
    else
    {
        file>>name>>no>>phone>>t_seats;
        while(!file.eof())
        {
            cout<<"\n\n\n Student Name : "<<name;
            cout<<"\n\n Bus Number : "<<no;
            cout<<"\n\n Phone Number : "<<phone;
            cout<<"\n\n Reserved Seats : "<<t_seats;
            found++;

            file>>name>>no>>phone>>t_seats;
        }
        file.close();

        if(found == 0)
            cout<<"\n\n No Booking Record Found.";
    }
}

int main()
{
    bus b;
    b.menu();
}
