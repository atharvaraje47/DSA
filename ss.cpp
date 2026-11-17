#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

struct Student
{
    int id;
    char name[50];
    float cgpa;
};

int main()
{
    Student *s = NULL;
    int n, i, j, min;

    cout << "Enter number of students: ";
    cin >> n;

    s = (Student*)malloc(n * sizeof(Student));

    for(i = 0; i < n; i++)
    {
        cout << "Enter ID, Name and CGPA: ";
        cin >> s[i].id >> s[i].name >> s[i].cgpa;
    }

    s = (Student*)realloc(s, (n+1) * sizeof(Student));

    cout << "Enter New Student ID, Name and CGPA: ";
    cin >> s[n].id >> s[n].name >> s[n].cgpa;
    n++;

    // Sort by Name
    for(i = 0; i < n-1; i++)
    {
        min = i;

        for(j = i+1; j < n; j++)
        {
            if(strcmp(s[j].name, s[min].name) < 0)
                min = j;
        }

        Student temp = s[i];
        s[i] = s[min];
        s[min] = temp;
    }

    cout << "\nSorted by Name:\n";
    for(i = 0; i < n; i++)
        cout << s[i].id << " " << s[i].name << " " << s[i].cgpa << endl;

    // CGPA Ascending
    for(i = 0; i < n-1; i++)
    {
        min = i;

        for(j = i+1; j < n; j++)
        {
            if(s[j].cgpa < s[min].cgpa)
                min = j;
        }

        Student temp = s[i];
        s[i] = s[min];
        s[min] = temp;
    }

    cout << "\nCGPA Ascending:\n";
    for(i = 0; i < n; i++)
        cout << s[i].id << " " << s[i].name << " " << s[i].cgpa << endl;

    // CGPA Descending
    for(i = 0; i < n-1; i++)
    {
        min = i;

        for(j = i+1; j < n; j++)
        {
            if(s[j].cgpa > s[min].cgpa)
                min = j;
        }

        Student temp = s[i];
        s[i] = s[min];
        s[min] = temp;
    }

    cout << "\nCGPA Descending:\n";
    for(i = 0; i < n; i++)
        cout << s[i].id << " " << s[i].name << " " << s[i].cgpa << endl;

    free(s);
    return 0;
}
