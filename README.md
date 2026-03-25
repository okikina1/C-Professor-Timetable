## Professor & Timetable Management System

## Description

This is a C++ program that allows professors to create and manage their records and timetables.
Users can input professor details such as name, age, and subject, and then create timetables associated with each professor.

## Features

* Create professor records
* Create timetables
* View all professors
* View all timetables
* View a specific timetable by ID

## Menu Options

When you run the program, the following menu appears:

1 - Create Professor
2 - Create Timetable
3 - Print Professors
4 - Print Timetables
5 - Print Timetable {ID}
6 - Quit

## How to Run

Compile the program:
g++ cpp-professor-timetable.cpp -o program

Run the program:
./program

## Files

- cpp-professor-timetable.cpp → main program file
- professors.txt → stores professor records (name, age, subject)  
- timetables.txt → stores timetable data for professors (subject, start time, end time, date, hall number)

## Notes

Make sure all text files are in the same directory as the program when running it.
