#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main () {
    int id1,id2,age,age1;
    string choice;
    string name,surname,subject,name1,surname1,subject1,subject2;
    string line,line1,lastline,starttime,endtime,date,hallnumber,starttime1,endtime1,date1,hallnumber1;
    bool found_inprof, allowed, found_tt;
    ifstream pfile_in,tfile_in;
    ofstream pfile_out,tfile_out;
    choice = "1";
    while (choice != "6") {
    cout << "Menu: " << endl;
    cout << "1 - Create Professor" << endl;
    cout << "2 - Create Timetable" << endl;
    cout << "3 - Print Professors" << endl;
    cout << "4 - Print Timetables" << endl;
    cout << "5 - Print Timetable {ID}" << endl;
    cout << "6 - Quit" << endl;
    cout << "Please choose one of the above tasks: ";
    cin >> choice;
    cout << endl;
    if(choice=="1") {
            pfile_in.open ("professor.txt");
            pfile_out.open("professor.txt",ios::app);
            cout << "Enter professor's name: "; cin >> name;
            cout << "Enter professor's surname: "; cin >> surname;
            cout << "Enter professor's age: "; cin >> age;
            cout << "Enter subject: "; cin >> subject;
            cout << endl;
            id1 = 0;
            found_inprof=false;
            while(getline(pfile_in, line) && found_inprof==false) {
                stringstream records(line);
                records >> id1 >> name1 >> surname1 >> age1 >> subject1;
                if(subject==subject1) found_inprof=true;
            }
            if(found_inprof==false) {
                if (id1 > 0) pfile_out << endl;
                pfile_out << id1+1 << " " << name << " " << surname << " " << age << " " << subject;
                cout << "Successfully added professor to data file." << endl << endl;
            }
            else cout << "Sorry you cannot add the same subject!" << endl << endl;

            pfile_in.close();
            pfile_out.close();

            }
    else if (choice=="3"){
        pfile_in.open ("professor.txt");
        while (!pfile_in.eof()) {
                pfile_in >> id1 >> name >> surname >> age >> subject;
                cout << id1 << " " << name << " " << surname << " " << age << " " << subject << endl;
        }
        cout << endl;
        pfile_in.close();
    }
    else if(choice=="2") {
        tfile_in.open("timetable.txt");
        tfile_out.open("timetable.txt",ios::app);
        cout << "Enter subject: "; cin >> subject;
        pfile_in.open("professor.txt");
        found_inprof=false;
        while(getline(pfile_in, line) && found_inprof==false) {
            stringstream records(line);
            records >> id1 >> name1 >> surname1 >> age1 >> subject1;
            if(subject==subject1) found_inprof=true;
        }
        if(found_inprof==false) cout << endl << "This record cannot be added because this subject is not taught by any professor!" << endl << endl;
        else {
                cout << "Enter start time (hh:mm): "; cin >> starttime;
                cout << "Enter end time (hh:mm): "; cin >> endtime;
                cout << "Enter date (dd/mm/yyyy): "; cin >> date;
                cout << "Enter hall number: "; cin >> hallnumber;
                cout << endl;
                subject1="";
                allowed=true; //allowed = true means the record can be added
                while(getline(tfile_in,line) && allowed) {
                    stringstream records(line);
                    records >> subject1 >> starttime1 >> endtime1 >> date1 >> hallnumber1;
                    if(subject==subject1 && date==date1 && ((starttime>=starttime1 && starttime<endtime1)||(endtime>starttime1&&endtime<=endtime1)))
                    {
                        allowed=false;
                        cout <<"This record cannot be added because there is already another one with the same subject and the same time!" << endl << endl;
                    }
                    if(hallnumber==hallnumber1 && date==date1 && ((starttime>=starttime1 && starttime<endtime1)||(endtime>starttime1&&endtime<=endtime1)))
                    {
                        allowed=false;
                        cout <<"This record cannot be added because there is already another one with the same hall number and the same time!" << endl << endl;
                    }

                }
                if(allowed) {
                    if (subject1 != "") tfile_out << endl;
                    tfile_out << subject << " " << starttime << " " << endtime << " " << date << " " << hallnumber;
                    cout << "Successfully added timetable to data file." << endl << 
                    endl;}
                }
        tfile_in.close();
        tfile_out.close();
        pfile_in.close();

    }
    else if(choice=="4") {
        tfile_in.open("timetable.txt");
        string s;
        while(getline(tfile_in,s)) {
        cout << s << endl;
        }
        cout << endl;
        tfile_in.close();
    }
    else if(choice=="5") {
        cout << "Enter professor's id: "; cin >> id1;
        cout << endl;
        pfile_in.open("professor.txt");
        found_inprof=false;
        while(getline(pfile_in,line) && found_inprof==false) {
            stringstream profrecords(line);
            profrecords >> id2 >> name1 >> surname1 >> age1 >> subject1;
            if(id1==id2) found_inprof=true;
        }
        if(found_inprof==true) {
            cout << "Professor: " << name1 << " " << surname1 << endl;
            tfile_in.open("timetable.txt");
            found_tt=false;
            while(getline(tfile_in,line1)) {
                stringstream ttrecords(line1);
                ttrecords >> subject2 >> starttime1 >> endtime1 >> date1 >> hallnumber1;
                if(subject1==subject2) {
                    found_tt=true;
                    cout << subject2 << " " << starttime1 << " " << endtime1 << " " << date1 << " " << hallnumber1 << endl;
                }
            }
            if(found_tt==false) cout << "This professor doesn't have any timetable records!" << endl;

            cout << endl;
            tfile_in.close();
        }
        else cout << "This professor is not in professor's file!" << endl << endl;
        pfile_in.close();
    }
    else if (choice!="6") cout << "Please enter a valid number!" << endl << endl;
    }


    return 0;
}