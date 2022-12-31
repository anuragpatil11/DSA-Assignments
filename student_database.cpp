// -------------------------------   DSA ASSIGNMENT 1 --------------------------------------
#include <iostream>
#include <string.h>
const int num = 10;
using namespace std;

class student
{
public:
    char name[20];
    int roll_no;
    float sgpa;

public:
    void accept(student list[], int n);
    void display(student lsit[], int n);
    void bubblesort(student list[], int n);
    void linearSearch(student list[], int n);
    void insertionSort(student list[], int n);
    void quicksort(student list[], int l, int h);
    int binarysearch(student s[], int low, int high);
};
void student::accept(student list[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "enter roll no: " << endl;
        cin >> list[i].roll_no;

        cout << "Enter Name: " << endl;
        cin >> list[i].name;

        cout << "Enter SGPA: " << endl;
        cin >> list[i].sgpa;
    }
}
void student::display(student list[], int n)
{
    cout << "ROLL NO"
         << "\t"
         << "NAME"
         << "\t"
         << "SGPA" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << list[i].roll_no << "\t" << list[i].name << "\t" << list[i].sgpa << endl;
    }
}
void student::bubblesort(student list[], int n)
{
    student temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (list[j + 1].roll_no < list[j].roll_no)
            {
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}
void student::insertionSort(student list[], int n)
{
    student temp;
    // int i,j;
    for (int i = 1; i < n; i++)
    {
        temp = list[i];
        int j = i - 1;
        while (strcmp(list[j].name, temp.name) > 0 && j >= 0)
        {
            list[j + 1] = list[j];
            j--;
        }
        list[j + 1] = temp;
    }
}
void student::quicksort(student s[num], int first, int last)
{
    
    int pivot, i, j;
    student temp;
    if (first < last)
    {
        pivot = first;
        i = first;
        j = last;

        while (i < j)
        {
            while (s[i].sgpa >= s[pivot].sgpa && i < last)
                i++;
            while (s[j].sgpa < s[pivot].sgpa)
                j--;
            if (i < j)
            {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
        temp = s[pivot];
        s[pivot] = s[j];
        s[j] = temp;
        quicksort(s, first, j - 1);
        quicksort(s, j + 1, last);
    }
}
void student::linearSearch(student list[], int n)
{
    float search;
    cout << "Enter the searching sgpa: " << endl;
    cin >> search;
    for (int i = 0; i < n; i++)
    {
        if (list[i].sgpa == search)
        {
            cout << list[i].roll_no << "\t" << list[i].name << "\t" << list[i].sgpa << endl;
        }
    }
}
int student::binarysearch(student s[], int low, int high)
{
    int mid;
    char x[20];
    cout << "Enter name :- ";
    cin >> x;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (strcmp(x, s[mid].name) == 0)
        {
            return mid;
        }
        else if (strcmp(x, s[mid].name) < 0)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int n = 13; // 15
    student obj;
    student list[n];

    obj.accept(list, n);
    cout << "Displaying Student list: \n";
    obj.display(list, n);

    obj.bubblesort(list, n);
    cout << "Bubble Sort of ROLL NO: \n";
    obj.display(list, n);

    obj.insertionSort(list, n);
    cout << "Insertion sort of NAME: \n";
    obj.display(list, n);


    cout << "Quick sort of TOP 10 TOPPERS: \n";
    obj.quicksort(list, 0, num - 1);
    obj.display(list, num);

    cout << "Linear Search bu SGPA: \n";
    obj.linearSearch(list, n);

    cout << "Binary Search by NAME: \n";
     obj.insertionSort(list, n);
            int result = obj.binarysearch(list, 0, (n - 1));
            if (result == -1)
            {
                cout << "\nStudent name not present in our record \n";
            }
            else
            {
                cout <<list[result].name<<"\t"<<list[result].sgpa<<"\t"<<list[result].roll_no<<"\n";
            }

     return 0;
}
// test case
// 100 aditya 10.0 45 aman 9.9 23 uday 8.0 88 vansh 8.8 33 yash 9.1 55 shruti 1.1 27 om 7.4 70 raj 4.5 21 riya 8.7 11 sahil 7.9 90 arjun 9.5 50 ram 7.4 20 anant 6.6
