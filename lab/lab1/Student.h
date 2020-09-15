#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>
#include <vector>

class Class;

enum Degree {
    undergraduate,
    graduate
};

class Student {
    // TODO: implement class Student.
private:
    const std::string name;
    const std::string year;
    const Degree degree;
protected:
    std::vector<Class*> classes;
public:
    const std::string id;
    virtual double getGrade() = 0;
    void addClass(Class *c);
    std::string toString() const;
};

// TODO: implement class Graduate.
class Graduate: public Student {
private:
protected:
public:
    double getGrade() {
        double grade = 0;
        return grade;
    }
};

// TODO: implement class Undergraduate.

class StudentWrapper {
private:
    const Student &student;
    double score = 0.0;
public:
    const std::string id;
    // TODO: fix error
    /*StudentWrapper(const std::string &id, const Student &student) {
        this->id = id;
        this->student = student;
    }*/

    void setScore(double score)
    {
        if (score < 0 || score > 100)
            throw "Invalid Score!";
        this->score = score;
    }

    double getScore() const
    {
        return this->score;
    }

    std::string toString() const
    {
        return student.toString();
    }
};

#endif // STUDENT_H_
