#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip> // Reserve this many character spaces before printing the next thing.
using namespace std;

// first i am creating the student details using struct
struct student
{
    int school_id;
    string Name;
    int roll_no;
    int subjects;
    int grade[5];
    float Total_Marks = 0;
    float percentage;
    bool failed = false;
};

// int &count in Add_New_Student() is used because 'count' is modifing
void Add_New_Student(student students[], int &count)
{
    cout << "\n---Enter your Details---\n";

    // Details of the student
    cout << "NAME : ";
    cin.ignore(1000, '\n'); // it clears the whole remaining line.
    getline(cin, students[count].Name);
    // getline() is used so it can take the Full name of student
    // if only cin is used and Name - Virat Kohli is given then only Virat will be stored

    cout << "School_id : ";
    cin >> students[count].school_id;
    cout << "Roll_No : ";
    cin >> students[count].roll_no;

    // Preventing Duplicate Information
    for (int i = 0; i < count; i++)
    {
        if (students[i].school_id == students[count].school_id)
        {
            cout << "\nid already exist !\n";
            return;
        }
        else if (students[i].roll_no == students[count].roll_no)
        {
            cout << "\nRoll_no already exist !\n";
            return;
        }
    }

    cout << "No of Subjects : ";
    cin >> students[count].subjects;

    // Maximum Subjects is upto 5 only
    if (students[count].subjects > 5 || students[count].subjects <= 0)
    {
        cout << "Enter valid Number of subjects(upto 5)\n";
        return;
    }
    else
    {
        for (int i = 0; i < students[count].subjects; i++)
        {
            cout << "Enter grade of subject " << i + 1 << " : ";
            cin >> students[count].grade[i];
            if (students[count].grade[i] < 1 || students[count].grade[i] > 100)
            {
                cout << "Enter Valid Marks(1-100)\n";
                return;
            }
        }
        float TotalMarks = 0;
        for (int i = 0; i < students[count].subjects; i++)
        {
            if (students[count].grade[i] < 40)
            {
                cout << "Student Failed in subject " << i + 1 << endl;
                students[count].failed = true;
            }
            TotalMarks += students[count].grade[i];
        }
        int Total_subjects = students[count].subjects;
        float Average_Makrs = TotalMarks / Total_subjects;
        float Maximum_Marks = Total_subjects * 100;
        float percentage_of_student = (TotalMarks / Maximum_Marks) * 100;
        students[count].percentage = percentage_of_student;
        students[count].Total_Marks = TotalMarks;

        cout << "Average Marks = " << Average_Makrs << endl;
        cout << "Total Marks = " << TotalMarks << " out of " << (Total_subjects * 100) << endl;
        cout << "Percentage = " << percentage_of_student << " % " << endl;
        count++;
    }
    cout << "\nStudent Added Successfully !\n";
}

// you can see that in Add_New_Student() "int &count" is used
// but here in Display_List() "int count" is used
// reason is in Add_New_Student() count is modifing but in Display_List it not
// that's why only int count is used
// this is not a bug ,it is just better code
void Display_List(student students[], int count)
{
    if (count == 0)
    {
        cout << "\nStudent list Empty !\n";
        return;
    }
    else
    {
        cout << "\n\n______Students Deatils______\n\n";

        for (int i = 0; i < count; i++)
        {
            cout << left << endl;
            cout << setw(5) << "Student " << i + 1 << "\n\n";
            cout << "|" << "Name -> " << students[i].Name << " | ";
            cout << setw(10) << "School ID -> " << students[i].school_id << " | ";
            cout << setw(10) << "Roll No -> " << students[i].roll_no << " | ";

            cout << "\n\n* Grade of " << students[i].Name << " * \n";
            for (int j = 0; j < students[i].subjects; j++)
            {
                cout << setw(15) << "Mark in Subject " << j + 1 << " -> " << students[i].grade[j] << " | ";
            }
            cout << "\n\n";
            cout << setw(15) << "Total Marks -> " << students[i].Total_Marks << "/" << students[i].subjects * 100 << " | ";
            cout << setw(15) << "Percentage -> " << students[i].percentage << "%" << " | ";

            cout << "PASS/FAIL -> ";
            if (students[i].failed)
            {
                cout << "Failed" << endl;
            }
            else
            {
                cout << "Pass" << endl;
            }
            cout << "_________________________________________________________________________________________________________________________________" << endl;
            cout << "\n";
        }
    }
}

void Search_student(student students[], int count)
{
    if (count == 0)
    {
        cout << "Record is Empty !" << endl;
        return;
    }
    else
    {
        int Search_id;
        cout << "Enter school_id of the student : ";
        cin >> Search_id;

        bool student_found = false;

        for (int i = 0; i < count; i++)
        {
            if (Search_id == students[i].school_id)
            {
                student_found = true;
                cout << "\n__Student found__" << endl;
                cout << left << endl;
                cout << "Name -> " << students[i].Name << setw(3) << " | ";
                cout << setw(15) << "Roll Number -> " << students[i].roll_no;
                cout << "\n\n* Grade of " << students[i].Name << " * \n";

                for (int j = 0; j < students[i].subjects; j++)
                {
                    cout << setw(15) << "Mark in Subject " << j + 1 << " -> " << students[i].grade[j] << " | ";
                }
                cout << "\n\n";
                cout << setw(15) << "Total Marks -> " << students[i].Total_Marks << "/" << students[i].subjects * 100 << " | ";
                cout << setw(15) << "Percentage -> " << students[i].percentage << "%" << " | ";

                cout << "PASS/FAIL -> ";
                if (students[i].failed)
                {
                    cout << "Failed" << endl;
                }
                else
                {
                    cout << "Pass" << endl;
                }
                break;
            }
        }
        if (!student_found)
        {
            cout << "Student Not Found !" << endl;
        }
    }
}

void update_student_record(student students[], int count)
{
    if (count == 0)
    {
        cout << "Record is Empty !" << endl;
        return;
    }
    int search_id;
    cout << "Enter your School Id -> ";
    cin >> search_id;

    bool found_student = false;

    for (int i = 0; i < count; i++)
    {
        if (search_id == students[i].school_id)
        {
            found_student = true;
            cout << "\n*** Check details very carefully ***\n";
            cout << left << endl;
            cout << "Name -> " << students[i].Name << " | ";
            cout << setw(10)
                 << "Roll Number -> " << students[i].roll_no << " | ";
            cout << "\n\n GRADE OF " << students[i].Name << endl;
            for (int j = 0; j < students[i].subjects; j++)
            {
                cout << setw(15) << "Mark in Subject " << j + 1 << " -> " << students[i].grade[j] << " | ";
            }
            cout << "\n\n";
            cout << setw(15) << "Total Marks -> " << students[i].Total_Marks << "/" << students[i].subjects * 100 << " | ";
            cout << setw(15) << "Percentage -> " << students[i].percentage << "%" << " | ";

            cout << "PASS/FAIL -> ";
            if (students[i].failed)
            {
                cout << "Failed" << endl;
            }
            else
            {
                cout << "Pass" << endl;
            }

            // Now i will ask the user if the details of the student is correct or not
            string details;
            cout << "Is student details is wrong ??(Yes/No) -> ";
            cin >> details;
            transform(details.begin(), details.end(), details.begin(), ::tolower);
            if (details == "no")
            {
                return;
            }
            else if (details == "yes")
            {
                // Updating the details of the student
                cout << "Fill the deatils \n\n";

                cout << "NAME : ";
                cin.ignore(1000, '\n'); // it clears the whole remaining line.
                getline(cin, students[i].Name);

                cout << "updated Roll_no -> ";
                cin >> students[i].roll_no;

                cout << "Update Number of subject -> ";
                cin >> students[i].subjects;
                if(students[i].subjects > 5 || students[i].subjects <= 0)
                {
                    cout << "Invalid number of subjects!\n";
                    return;
                }

                cout << "\n\n<-----Upate your Grades----->\n\n";

                float New_Marks = 0;
                for (int k = 0; k < students[i].subjects; k++)
                {
                    cout << "Mark in Subject " << k+1 << " : ";
                    cin >> students[i].grade[k];

                    if(students[i].grade[k] < 1 || students[i].grade[k] > 100)
                    {
                        cout << "Invalid Marks!\n";
                        return;
                    }
                    New_Marks += students[i].grade[k];
                }
                students[i].Total_Marks = New_Marks;

                float Maximum_Marks = students[i].subjects * 100;
                students[i].percentage = (students[i].Total_Marks / Maximum_Marks) * 100;

                students[i].failed = false;  // reset before checking
                for (int m = 0; m < students[i].subjects; m++)
                {
                    if (students[i].grade[m] < 40)
                    {
                        cout << "Student Failed in subject " << m + 1 << endl;
                        students[i].failed = true;
                    }
                }
                
                cout << "Student details updated successfully";
                cout << "\n\n";
            }
        }
    }
    if(!found_student)
    {
        cout << "Student Not Found!" << endl;
    }
}

void Average_of_class(student students[], int count)
{
    if (count == 0)
    {
        cout << "Record is Empty !" << endl;
        return;
    }
    else
    {
        float avg_class = 0;
        for (int i = 0; i < count; i++)
        {
            avg_class += students[i].percentage;
        }
        cout << "\nAverage of the class -> " << avg_class / count << "%" << endl;
    }
}

void Rank_List(student students[], int count)
{
    if (count == 0)
    {
        cout << "\nStudent list Empty !\n";
        return;
    }
    else
    {
        // using selection sort to sort the percentage of the students
        for (int i = 0; i < count - 1; i++)
        {
            int Rank1 = i;
            for (int j = i; j <= count - 1; j++)
            {
                if (students[j].percentage > students[Rank1].percentage)
                {
                    Rank1 = j;
                }
            }
            swap(students[Rank1], students[i]);
        }

        cout << "\n---* RANK LIST *---\n";

        cout << left
             << setw(7) << "Rank"
             << "| " << setw(20) << "Name"
             << "| " << setw(15) << "Roll_no"
             << "| " << setw(15) << "Percentage"
             << endl;

        for (int i = 0; i < count; i++)
        {
            cout << left
                 << setw(7) << i + 1
                 << "| " << setw(20) << students[i].Name
                 << "| " << setw(15) << students[i].roll_no
                 << "| " << setw(15) << students[i].percentage
                 << endl;
        }
    }
}

int main()
{
    // student here has become a data type now
    student students[1000];
    int student_count = 0;

    int choice;
    while (true)
    {
        cout << "\n<-----Student Record Management System----->\n\n";
        cout << "*****Choose your options*****\n\n";
        cout << "1>. Add Student Record\n";
        cout << "2>. Display Students Details\n";
        cout << "3>. Search Student in the Record\n";
        cout << "4>. Update Details\n";
        cout << "5>. Calculate Average of students\n";
        cout << "6>. Rank List\n";
        cout << "7>. ---EXIT---\n";
        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Add New Student details\n";
            Add_New_Student(students, student_count);
            break;

        case 2:
            cout << "DIASPLAY THE LIST\n";
            Display_List(students, student_count);
            break;

        case 3:
            cout << "Search the Student\n";
            Search_student(students, student_count);
            break;

        case 4:
            cout << "Update details\n";
            update_student_record(students, student_count);
            break;

        case 5:
            cout << "Average of the class\n";
            Average_of_class(students, student_count);
            break;

        case 6:
            cout << "Rank List\n"
                 << endl;
            Rank_List(students, student_count);
            break;

        case 7:
            cout << "---Exit---" << endl;
            return 0;
            break;

        default:
            cout << "Select Valid choice(1-7) !\n";
            break;
        }
    }
    return 0;
}
