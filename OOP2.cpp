#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

class Point {
private:
    double x, y, z;

public:
    Point() : x(0), y(0), z(0) {}
    Point(double x, double y, double z) : x(x), y(y), z(z) {}

    inline void setCoordinates(double x, double y, double z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    inline void print() const {
        cout << "Point(" << x << ", " << y << ", " << z << ")" << endl;
    }

    inline double getX() const {
        return x; 
    }
    inline double getY() const {
        return y; 
    }
    inline double getZ() const {
        return z; 
    }

    void saveToFile(const char* filename) const {
        ofstream out(filename);
        if (out.is_open()) {
            out << x << " " << y << " " << z << endl;
            out.close();
        }
    }

    void loadFromFile(const char* filename) {
        ifstream in(filename);
        if (in.is_open()) {
            in >> x >> y >> z;
            in.close();
        }
    }
};

class Fraction {
private:
    int numerator, denominator;

public:
    Fraction() : numerator(0), denominator(1) {}
    Fraction(int n, int d) : numerator(n), denominator(d == 0 ? 1 : d) {}

    inline void setFraction(int n, int d) {
        numerator = n;
        denominator = (d == 0) ? 1 : d;
    }

    inline void print() const {
        cout << numerator << "/" << denominator << endl;
    }

    inline int getNumerator() const { return numerator; }
    inline int getDenominator() const { return denominator; }
};

class Student {
private:
    char* fullName;
    char* birthDate;
    char* phone;
    char* city;
    char* country;
    char* universityName;
    char* universityCity;
    char* universityCountry;
    char* groupNumber;

public:
    Student(const char* fullName, const char* birthDate, const char* phone, const char* city,
        const char* country, const char* universityName, const char* universityCity,
        const char* universityCountry, const char* groupNumber)
    {
        this->fullName = new char[strlen(fullName) + 1];
        strcpy_s(this->fullName, strlen(fullName) + 1, fullName);

        this->birthDate = new char[strlen(birthDate) + 1];
        strcpy_s(this->birthDate, strlen(birthDate) + 1, birthDate);

        this->phone = new char[strlen(phone) + 1];
        strcpy_s(this->phone, strlen(phone) + 1, phone);

        this->city = new char[strlen(city) + 1];
        strcpy_s(this->city, strlen(city) + 1, city);

        this->country = new char[strlen(country) + 1];
        strcpy_s(this->country, strlen(country) + 1, country);

        this->universityName = new char[strlen(universityName) + 1];
        strcpy_s(this->universityName, strlen(universityName) + 1, universityName);

        this->universityCity = new char[strlen(universityCity) + 1];
        strcpy_s(this->universityCity, strlen(universityCity) + 1, universityCity);

        this->universityCountry = new char[strlen(universityCountry) + 1];
        strcpy_s(this->universityCountry, strlen(universityCountry) + 1, universityCountry);

        this->groupNumber = new char[strlen(groupNumber) + 1];
        strcpy_s(this->groupNumber, strlen(groupNumber) + 1, groupNumber);
    }

    ~Student() {
        delete[] fullName;
        delete[] birthDate;
        delete[] phone;
        delete[] city;
        delete[] country;
        delete[] universityName;
        delete[] universityCity;
        delete[] universityCountry;
        delete[] groupNumber;
    }

    void print() const {
        cout << "Student: " << fullName << endl;
        cout << "Date of Birth: " << birthDate << endl;
        cout << "Phone: " << phone << endl;
        cout << "City: " << city << endl;
        cout << "Country: " << country << endl;
        cout << "University: " << universityName << " (" << universityCity << ", " << universityCountry << ")" << endl;
        cout << "Group: " << groupNumber << endl;
    }

    inline const char* getFullName() const {
        return fullName; 
    }
    inline const char* getBirthDate() const {
        return birthDate; 
    }
    inline const char* getPhone() const {
        return phone; 
    }
};

int main() {
    Point p1(1.0, 2.0, 3.0);
    p1.saveToFile("point.txt");
    Point p2;
    p2.loadFromFile("point.txt");
    p2.print();

    Fraction f1;
    f1.print();
    Fraction f2(3, 4);
    f2.print();

    Student student("JULFY", "01 01 2000", "0 800 212 800", "Rivne", "Ukraine",
        "RTFK", "Rivne", "Ukraine", "EM");
    student.print();

    return 0;
}
