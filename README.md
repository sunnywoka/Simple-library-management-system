# Simple-library-management-system

A simple library management system was developed using C++ and has fewer features compared to the Java version.

The library has three categories of items available for borrowing: books, journals, and movies. For each item, the library maintains a record of its type, ID, title, and year of publication. Additionally, the author and number of pages are recorded for books, the director for movies, and the volume and number for journals.

The text file looks like:

```
Movie,200,Remember The Alamo,1945,George Smith
Movie,203,Lord of the ring: the fellowship of the ring,2001,Pete Jackson
Movie,206,Lord of the ring: the two towers,2002,Peter Jackson
Movie,210,Going for the Touchdown,1984,Frank Madden
Movie,211,Martian Hairdresser,1992,Debbie Gold
Book,231,How to Make Money,1987,Phil Barton,324
Book,240,Garden Projects At Home,1998,Mary Freeman,164
Book,202,The Haunted House Mystery,1996,Bert Morgan,53
Journal,207,ACM,2009,6,8
Journal,212,ACM,2010,5,8
Journal,215,J of Logic,2008,23,14
Journal,281,J of AI,2009,35,1

```

The program looks like:

```
--------------------------------------
Type: Movie
Title: Remember The Alamo
ID: 200
Year: 1945
Director: George Smith

--------------------------------------
Type: Movie
Title: Lord of the ring: the fellowship of the ring
ID: 203
Year: 2001
Director: Pete Jackson

--------------------------------------
.
.
.
Enter 'q' to quit, enter 'i' to search by ID, or enter any other to search by phrase in title
i
Enter ID to start search, or enter 'b' to go back to choose search method
211
--------------------------------------
Type: Movie
Title: Martian Hairdresser
ID: 211
Year: 1992
Director: Debbie Gold

--------------------------------------
Enter ID to start search, or enter 'b' to go back to choose search method
b
--------------------------------------
Enter 'q' to quit, enter 'i' to search by ID, or enter any other to search by phrase in title
q
Program quit.
```
