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
    int n, i, j;
    Student key;

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
    for(i = 1; i < n; i++)
    {
        key = s[i];
        j = i-1;

        while(j >= 0 && strcmp(s[j].name, key.name) > 0)
        {
            s[j+1] = s[j];
            j--;
        }
        s[j+1] = key;
    }

    cout << "\nSorted by Name:\n";
    for(i = 0; i < n; i++)
        cout << s[i].id << " " << s[i].name << " " << s[i].cgpa << endl;

    // CGPA Ascending
    for(i = 1; i < n; i++)
    {
        key = s[i];
        j = i-1;

        while(j >= 0 && s[j].cgpa > key.cgpa)
        {
            s[j+1] = s[j];
            j--;
        }
        s[j+1] = key;
    }

    cout << "\nCGPA Ascending:\n";
    for(i = 0; i < n; i++)
        cout << s[i].id << " " << s[i].name << " " << s[i].cgpa << endl;

    // CGPA Descending
    for(i = 1; i < n; i++)
    {
        key = s[i];
        j = i-1;

        while(j >= 0 && s[j].cgpa < key.cgpa)
        {
            s[j+1] = s[j];
            j--;
        }
        s[j+1] = key;
    }

    cout << "\nCGPA Descending:\n";
    for(i = 0; i < n; i++)
        cout << s[i].id << " " << s[i].name << " " << s[i].cgpa << endl;

    free(s);
    return 0;
}
