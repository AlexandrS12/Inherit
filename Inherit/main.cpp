#include<iostream>
using namespace std;

class Person
{
protected:
    char* name;
    int age;
public:
    Person() = default;
    Person(const char* n, int a) :age(a)
    {
        name = new char[strlen(n) + 1];
        strcpy_s(name, strlen(n) + 1, n);
        //cout << "Person Constructor\n";
    }
    void Print()
    {
        cout << "Name: " << name << "\tAge: " << age << "\t";
    }
    void Input()
    {
        char buff[20];
        cout << "Enter Name: ";
        cin.getline(buff, 20);
        name = new char[strlen(buff) + 1];
        strcpy_s(name, strlen(buff) + 1, buff);
        cout << "Enter age: ";
        cin >> age;
    }
    ~Person()
    {
        delete[]name;
        //cout << "Person Destructor\n";
    }
};

class Student : public Person
{
    //char* name;
    //int age;
    char* university;
public:
    Student() = default;
    Student(const char* n, int a, const char* Univer) :Person(n, a) {
        university = new char[strlen(Univer) + 1];
        strcpy_s(university, strlen(Univer) + 1, Univer);
        //cout << "Person Constructor\n";
    }
    ~Student() {
        delete[] university;
        //cout << "Student Destructor\n";
    }

    void Input(const char* Univer)
    {
        delete[] university;
        university = new char[strlen(Univer) + 1];
        strcpy_s(university, strlen(Univer) + 1, Univer);

        Person::Input();
    }

    void Print()
    {
        //cout << "Name: " << name << "\tAge: " << age << "\t";
        Person::Print();
        cout << "University: " << university << endl;
    }

    const char* GetUniversity() const
    {
        return university;
    }

    void SetUniversity(const char* Univer)
    {
        delete[] university;
        university = new char[strlen(Univer) + 1];
        strcpy_s(university, strlen(Univer) + 1, Univer);
    }
};

class Teacher : public Person
{
    char* school;
    double salary;

public:
    Teacher() = default;
    Teacher(const char* n, int a, const char* s, double sal) : Person(n, a), salary(sal)
    {
        school = new char[strlen(s) + 1];
        strcpy_s(school, strlen(s) + 1, s);
    }

    ~Teacher()
    {
        delete[] school;
    }

    void Input(const char* s, double sal)
    {
        delete[] school;
        school = new char[strlen(s) + 1];
        strcpy_s(school, strlen(s) + 1, s);
        salary = sal;

        Person::Input();
    }

    void Print()
    {
        Person::Print();
        cout << "School: " << school << endl<< "Salary: " << salary << endl;
    }

    const char* GetSchool() const
    {
        return school;
    }

    void SetSchool(const char* s)
    {
        delete[] school;
        school = new char[strlen(s) + 1];
        strcpy_s(school, strlen(s) + 1, s);
    }

    double GetSalary() const
    {
        return salary;
    }

    void SetSalary(double sal)
    {
        salary = sal;
    }
};

class Doctor : public Person
{
    char* specialize;
    bool familyDoctor;
    int workXP;

public:
    Doctor() = default;
    Doctor(const char* n, int a, const char* spec, int exp, bool isFamilyDoctor)
        : Person(n, a), workXP(exp), familyDoctor(isFamilyDoctor)
    {
        specialize = new char[strlen(spec) + 1];
        strcpy_s(specialize, strlen(spec) + 1, spec);
    }

    ~Doctor()
    {
        delete[] specialize;
    }

    void Input(const char* spec, int xp, bool isFamilyDoctor)
    {
        delete[] specialize;
        specialize = new char[strlen(spec) + 1];
        strcpy_s(specialize, strlen(spec) + 1, spec);

        workXP = xp;
        familyDoctor = isFamilyDoctor;

        Person::Input();
    }

    void Print()
    {
        Person::Print();
        cout << "Specialization: " << specialize << endl<< "Work Experience: " << workXP;

        if (familyDoctor)
        {
            cout << "\tIs family doc!";
        }
        else
        {
            cout << "\tIS not Family doc!";
        }

        cout << endl;
    }

    const char* GetSpecialize() const
    {
        return specialize;
    }

    void SetSpecialize(const char* spec)
    {
        delete[] specialize;
        specialize = new char[strlen(spec) + 1];
        strcpy_s(specialize, strlen(spec) + 1, spec);
    }

    int GetWorkExperience() const
    {
        return workXP;
    }

    void SetWorkExperience(int xp)
    {
        workXP = xp;
    }

    bool IsFamilyDoctor() const
    {
        return familyDoctor;
    }

    void SetFamilyDoctor(bool isFamilyDoc)
    {
        familyDoctor = isFamilyDoc;
    }
};

class Driver : public Person
{
    char* Color;
    char* Number;
    char* Lecense;

public:
    Driver() = default;
    Driver(const char* n, int a, const char* color, const char* num, const char* license)
        : Person(n, a)
    {
        Color = new char[strlen(color) + 1];
        strcpy_s(Color, strlen(color) + 1, color);

        Number = new char[strlen(num) + 1];
        strcpy_s(Number, strlen(num) + 1, num);

        Lecense = new char[strlen(license) + 1];
        strcpy_s(Lecense, strlen(license) + 1, license);
    }

    ~Driver()
    {
        delete[] Color;
        delete[] Number;
        delete[] Lecense;
    }

    void Input(const char* color, const char* num, const char* license)
    {
        delete[] Color;
        Color = new char[strlen(color) + 1];
        strcpy_s(Color, strlen(color) + 1, color);

        delete[] Number;
        Number = new char[strlen(num) + 1];
        strcpy_s(Number, strlen(num) + 1, num);

        delete[] Lecense;
        Lecense = new char[strlen(license) + 1];
        strcpy_s(Lecense, strlen(license) + 1, license);

        Person::Input();
    }

    void Print()
    {
        Person::Print();
        cout << "Color: " << Color << endl<< "Number: " << Number << endl<<"License: " << Lecense << endl;
    }

    const char* GetColor() const
    {
        return Color;
    }

    void SetColor(const char* color)
    {
        delete[] Color;
        Color = new char[strlen(color) + 1];
        strcpy_s(Color, strlen(color) + 1, color);
    }

    const char* GetSerialNumber() const
    {
        return Number;
    }

    void SetSerialNumber(const char* serial)
    {
        delete[] Number;
        Number = new char[strlen(serial) + 1];
        strcpy_s(Number, strlen(serial) + 1, serial);
    }

    const char* GetDriverLicense() const
    {
        return Lecense;
    }

    void SetDriverLicense(const char* license)
    {
        delete[] Lecense;
        Lecense = new char[strlen(license) + 1];
        strcpy_s(Lecense, strlen(license) + 1, license);
    }
};

int main()
{
    Student student("Irina", 18, "ITStep");
    student.Print();
    cout << endl;
    Teacher teacher("Valeria", 30, "IT School", 35000);
    teacher.Print();
    cout << endl;
    Driver driver("Valera", 45, "Silver", "KN896123", "BO7787BA");
    driver.Print();
    cout << endl;
    Doctor doctor("Valik", 55, "FamilyDoc", 30, true);
    doctor.Print();
    cout << endl;

    student.SetUniversity("POLITEX");
    student.Print();
    cout << endl;

    teacher.SetSchool("Kulevchanska I-III");
    teacher.SetSalary(63000.0);
    teacher.Print();
    cout << endl;

    driver.SetColor("Carbon");
    driver.SetSerialNumber("Kn7732");
    driver.SetDriverLicense("BH1991HB");
    driver.Print();
    cout << endl;

    doctor.SetSpecialize("Dentist");
    doctor.SetWorkExperience(32);
    doctor.SetFamilyDoctor(false);
    doctor.Print();
    cout << endl;

}