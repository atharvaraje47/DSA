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

    cout << "Enter number of students: ";
    cin >> n;

    s = (Student*)malloc(n * sizeof(Student));

    for(i = 0; i < n; i++)
    {
        cout << "\nEnter ID, Name and CGPA: ";
        cin >> s[i].id >> s[i].name >> s[i].cgpa;
    }

    // Expand memory using realloc()
    s = (Student*)realloc(s, (n + 1) * sizeof(Student));

    cout << "\nEnter New Student ID, Name and CGPA: ";
    cin >> s[n].id >> s[n].name >> s[n].cgpa;
    n++;

    // Bubble Sort by Name
    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(strcmp(s[j].name, s[j+1].name) > 0)
            {
                Student temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
            }
        }
    }

    cout << "\nStudents Sorted by Name:\n";

    for(i = 0; i < n; i++)
    {
        cout << s[i].id << " " << s[i].name << " " << s[i].cgpa << endl;
    }

    // Bubble Sort by CGPA Ascending
    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(s[j].cgpa > s[j+1].cgpa)
            {
                Student temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
            }
        }
    }

    cout << "\nCGPA in Ascending Order:\n";

    for(i = 0; i < n; i++)
    {
        cout << s[i].id << " " << s[i].name << " " << s[i].cgpa << endl;
    }

    // Bubble Sort by CGPA Descending
    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(s[j].cgpa < s[j+1].cgpa)
            {
                Student temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
            }
        }
    }

    cout << "\nCGPA in Descending Order:\n";

    for(i = 0; i < n; i++)
    {
        cout << s[i].id << " " << s[i].name << " " << s[i].cgpa << endl;
    }

    free(s);

    return 0;
}
