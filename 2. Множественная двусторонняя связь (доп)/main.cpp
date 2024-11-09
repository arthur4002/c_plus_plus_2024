#include <iostream>
#include <vector>
#include <string>

class Lesson;
class Student;

class Student {
private:
    std::string name;
    std::vector<Lesson*> lessons;

public:
    Student(const std::string& studentName) : name(studentName) {}

    void addLesson(Lesson* lesson) {
        lessons.push_back(lesson);
    }

    void removeLesson(Lesson* lesson) {
        lessons.erase(std::remove(lessons.begin(), lessons.end(), lesson), lessons.end());
    }

    void printLessons() const;

    std::string getName() const { return name; }
};

class Lesson {
private:
    std::string name;
    std::vector<Student*> students;

public:
    Lesson(const std::string& lessonName) : name(lessonName) {}

    void addStudent(Student* student) {
        students.push_back(student);
        student->addLesson(this);
    }

    void removeStudent(Student* student) {
        students.erase(std::remove(students.begin(), students.end(), student), students.end());
        student->removeLesson(this);
    }   

    void printStudents() const {
        std::cout << "Студенты на занятии " << name << ":" << std::endl;
        for (const auto& student : students) {
            std::cout << "- " << student->getName() << std::endl;
        }
    }

    std::string getName() const { return name; }
};

//реализация метода printLessons в классе Student
void Student::printLessons() const {
    std::cout << "Занятия студента " << name << ":" << std::endl;
    for (const auto& lesson : lessons) {
        std::cout << "- " << lesson->getName() << std::endl;
    }
}

int main() {
    Student alice("Алиса");
    Student bob("Боб");
    Student charlie("Чарли");
 
    Lesson math("Математика");
    Lesson physics("Физика");
    Lesson programming("Программирование");

    //связывание студентов и занятий
    math.addStudent(&alice);
    math.addStudent(&bob);
    physics.addStudent(&bob);
    physics.addStudent(&charlie);
    programming.addStudent(&alice);
    programming.addStudent(&charlie);

    //вывод информации
    alice.printLessons();
    std::cout << std::endl;
    bob.printLessons();
    std::cout << std::endl;
    charlie.printLessons();
    std::cout << std::endl;

    math.printStudents();
    std::cout << std::endl;
    physics.printStudents();
    std::cout << std::endl;
    programming.printStudents();

    return 0;
} 
