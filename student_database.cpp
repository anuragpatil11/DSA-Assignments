/*-------------------------------------- DSA ASSIGNMENT :- 1 --------------------------------------------------

Consider a student database of SEIT class (at least 15 records). Database contains different fields of
every student like Roll No, Name and SGPA.(array of structure)
a) Design a roll call list, arrange list of students according to roll numbers in ascending order (Use
Bubble Sort)
b) Arrange list of students alphabetically. (Use Insertion sort)
c) Arrange list of students to find out first ten toppers from a class. (Use Quick sort)
d) Search students according to SGPA. If more than one student having same SGPA, then print list
of all students having same SGPA.
e) Search a particular student according to name using binary search without recursion. (all the
student records having the presence of search key should be displayed)
(Note: Implement either Bubble sort or Insertion Sort.)
*/
#include <iostream>
#include <string.h>
using namespace std;

int const size = 13;

struct studdb // Structure is used for collection of all data type and storing different information
{
    int roll_no;
    char name[20];
    float SGPA;
};

void accept(struct studdb list[size]);        // accept() function accept the students data
void display(struct studdb list[15],int size);         // display() function display all the informatin or data of student
void bubbleSort(struct studdb list[size]);    // bubbleSort() sort the list of students according to their roll_no
void insertionSort(struct studdb list[size]); // insertionSort() sort the list of students alphabatically
void search(struct studdb list[size]);        // search() search the student according to their SGPA.
void binarySearch(struct studdb list[size]);  // binarySearch() search the student according the name.

void accept(struct studdb list[size])
{
    for (int i = 0; i < size; i++)
    {
        cout << "Enter Roll no: " << endl;
        cin >> list[i].roll_no;

        cout << "Enter Name: " << endl;
        cin >> list[i].name;

        cout << "Enter SGPA: " << endl;
        cin >> list[i].SGPA;
    }
};
void display(struct studdb list[80],int size)
{
    cout << "Roll No."
         << "\t"
         << "Name"
         << "\t"
         << "SGPA" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << list[i].roll_no << "\t" << list[i].name << "\t" << list[i].SGPA << endl;
    }
};
void bubbleSort(struct studdb list[size]) // Sorting according to their roll no.
{
    struct studdb temp;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (list[j].roll_no > list[j + 1].roll_no)
            {
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}
void insertionSort(struct studdb list[size])
{
    int j;
    struct studdb temp;
    for (int k = 1; k < size; k++) // complete student name in list
    {
        temp = list[k]; // store first name(one by one) in list in temp variable.
        j = k - 1;      // for backword comparision i.e k-1 then j=0

        while (strcmp(list[j].name, temp.name) > 0 && j >= 0) // compare first name in list with name in temp list
        {
            list[j + 1] = list[j]; // store backword in list all name alphabatically
            j--;                   // insertion sort compare in backword way
        }
        list[j + 1] = temp; // finally all name stored in temp shift into list of array.
    }
}

void QuickSort(struct studdb list[size], int first, int last)
{
    // last=10;
    int pivot, i, j;
    studdb temp;
    if (first < last)
    {
        pivot = first;
        i = first;
        j = last;

        while (i < j)
        {
            while (list[i].SGPA >= list[pivot].SGPA && i < last)
                i++;
            while (list[j].SGPA < list[pivot].SGPA)
                j--;
            if (i < j)
            {
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
        temp = list[j];
        list[j] = list[pivot] ;
        list[pivot] = temp;
        QuickSort(list, first, j - 1);
        QuickSort(list, j + 1, last);
    }
}

void search(struct studdb list[size])
{
    float sgpa; // declare sgpa as float
    cout << "enter sgpa: " << endl;
    cin >> sgpa; // taking searching sgpa as a input from user
    bool var = true;
    if (var == true)
    {
        for (int i = 0; i < size; i++) // searching complete SGPA in array
        {
            if (list[i].SGPA == sgpa) // if given sgpa is equal to list array of SGPA
            {
                cout << list[i].roll_no << "\t" << list[i].name << "\t" << list[i].SGPA << endl; // print complete details of that sgpa of students
                // var = true;
            }
            else if (var == false)
            {
                // var=false;
                cout << " Student's not found.." << endl;
            }
        }
    }
    // else if(var==false)
    // {
    //     //var=false;
    //     cout<<" Student's not found.."<<endl;
    // }

    // for (int i = 0; i < size; i++) // searching complete SGPA in array
    // {
    //     if (list[i].SGPA == sgpa) // if given sgpa is equal to list array of SGPA
    //     {
    //         cout << list[i].roll_no << "\t" << list[i].name << "\t" << list[i].SGPA << endl; // print complete details of that sgpa of students
    //         var = true;
    //     }
    // }
}

void binarySearch(struct studdb list[size])
{
    char search[15];
    cout << "Enter the name of Searching student : ";
    cin >> search;

    int lower, upper, mid;

    lower = 0;
    upper = size - 1; // Binary Search logic
    

    while (lower <= upper)
    {
        mid = (lower + upper) / 2;
        if (strcmp( search,list[mid].name) == 0)
        {
            cout << list[mid].roll_no << "\t" << list[mid].name << "\t" << list[mid].SGPA << endl;
            // return mid;
            break;
        }
        else if (strcmp( search,list[mid].name) < 0) // compare list of mid char with searching char
        {
            upper = mid - 1; // if searching char is greater than mid char
        }
        else
        { // if searching char is lower than mid char in list
            lower=mid+1;
            //mid = (lower + upper) / 2;
        }
    }
    if (lower > upper)
    { // if searching char not found in the list
        cout << search << "not found in the list" << endl;
    }
}

int main()
{
    int ch;
    struct studdb data[15];
    accept(data);
    display(data,size);
    do
    {
        cout << "1.Bubble Sort: " << endl;
        cout << "2.Insertion Sort: " << endl;
        cout << "3.quicksort: " << endl;
        cout << "4.Searching: " << endl;
        cout << "5.Binary Searching: " << endl;
        cout << "6.Exit: " << endl;
        cin >> ch;

        switch (ch)
        {
        case 1:
            bubbleSort(data); // calling function bubblesort()
            display(data,size);
            break;

        case 2:
            insertionSort(data); // calling function insertionsort()
            display(data,size);
            break;

        case 3:
            QuickSort(data, 0, size - 1);
            display(data,size-3);
            break;

        case 4:
            search(data); //  calling function search()
            break;

        case 5:
            insertionSort(data);

            binarySearch(data); // calling function binarSearch()
            break;
        default:
            break;
        }
    } while (ch != 5);
// test case
// 100 aditya 10.0 45 aman 9.9 23 uday 8.0 88 vansh 8.8 33 yash 9.1 55 shruti 1.1 27 om 7.4 70 raj 4.5 21 riya 8.7 11 sahil 7.9 90 arjun 9.5 50 ram 7.4 20 anant 6.6
    return 0;
}
/*
Enter Roll no: 
100 aditya 10.0 45 aman 9.9 23 uday 8.0 88 vansh 8.8 33 yash 9.1 55 shruti 1.1 27 om 7.4 70 raj 4.5 21 riya 8.7 11 sahil 7.9 90 arjun 9.5 50 ram 7.4 20 anant 6.6
Enter Name: 
Enter SGPA: 
Enter Roll no: 
Enter Name: 
Enter SGPA: 
Enter Roll no: 
Enter Name: 
Enter SGPA: 
Enter Roll no: 
Enter Name: 
Enter SGPA: 
Enter Roll no: 
Enter Name: 
Enter SGPA: 
Enter Roll no: 
Enter Name: 
Enter SGPA:
Enter Roll no:
Enter Name:
Enter SGPA:
Enter Roll no:
Enter Name:
Enter SGPA:
Enter Roll no:
Enter Name:
Enter SGPA:
Enter Roll no:
Enter Name:
Enter SGPA:
Enter Roll no:
Enter Name:
Enter SGPA:
Enter Roll no:
Enter Name:
Enter SGPA:
Enter Roll no:
Enter Name:
Enter SGPA:
Roll No.        Name    SGPA
100     aditya  10
45      aman    9.9
23      uday    8
88      vansh   8.8
33      yash    9.1
55      shruti  1.1
27      om      7.4
70      raj     4.5
21      riya    8.7
11      sahil   7.9
90      arjun   9.5
50      ram     7.4
20      anant   6.6
1.Bubble Sort:
2.Insertion Sort:
3.quicksort:
4.Searching:
5.Binary Searching:
6.Exit:
1
Roll No.        Name    SGPA
11      sahil   7.9
20      anant   6.6
21      riya    8.7
23      uday    8
27      om      7.4
33      yash    9.1
45      aman    9.9
50      ram     7.4
55      shruti  1.1
70      raj     4.5
88      vansh   8.8
90      arjun   9.5
100     aditya  10
1.Bubble Sort:
2.Insertion Sort:
3.quicksort:
4.Searching:
5.Binary Searching:
6.Exit:
2
Roll No.        Name    SGPA
100     aditya  10
45      aman    9.9
20      anant   6.6
90      arjun   9.5
27      om      7.4
70      raj     4.5
50      ram     7.4
21      riya    8.7
11      sahil   7.9
55      shruti  1.1
23      uday    8
88      vansh   8.8
33      yash    9.1
1.Bubble Sort:
2.Insertion Sort:
3.quicksort:
4.Searching:
5.Binary Searching:
6.Exit:
3
Roll No.        Name    SGPA
100     aditya  10
45      aman    9.9
90      arjun   9.5
33      yash    9.1
88      vansh   8.8
21      riya    8.7
23      uday    8
11      sahil   7.9
27      om      7.4
50      ram     7.4
1.Bubble Sort:
2.Insertion Sort:
3.quicksort:
4.Searching:
5.Binary Searching:
6.Exit:
4
enter sgpa:
9.9
45      aman    9.9
1.Bubble Sort:
2.Insertion Sort:
3.quicksort:
4.Searching:
5.Binary Searching:
6.Exit:
5
Enter the name of Searching student : ram
50      ram     7.4
*/
