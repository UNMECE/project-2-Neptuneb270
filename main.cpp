#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Student {
   private:
      string name; //"first last"
      string gpa;
      string grad_info; //"sem year"
      string enroll_info; //"sem year"
      string degree_sought;
   public:
      //init and destructor
      Student(): name("First Last"), gpa("0.00") {}
      Student(string name, string gpa, string grad_info,string enroll_info, string degree_sought) {
         this->name = name; this->gpa = gpa; this->grad_info = grad_info;
            this->enroll_info = enroll_info; this->degree_sought = degree_sought;
      }
      //getters
      string getName() {return name;}
      string getGpa() {return gpa;}
      string getGradInfo() {return grad_info;}
      string getEnrollInfo() {return enroll_info;}
      string getDegreeSought() {return degree_sought;}
      //setters
      void setName(string fn, string ln) {name = fn + " " + ln;}
      void setGpa(string gpa) {this->gpa = gpa;}
      void setGradInfo(string sem, string year) {grad_info = sem + " " + year;}
      void setEnrollInfo(string sem, string year) {enroll_info = sem + " " + year;}
      void setDegreeSought(string degree_sought) {this->degree_sought = degree_sought;}
};

class Art_Student: public Student {
   private:
      string emphasis;
   public:
         //init and destructor
         Art_Student(): Student() {}
         Art_Student(string name, string gpa, string grad_info,string enroll_info, string degree_sought, string emphasis): Student(name, gpa, grad_info, enroll_info, degree_sought) {
            this->emphasis = emphasis;
         }
         ~Art_Student() {}
         //getters
         string getEmphasis() {return emphasis;}
         //setters
         void setEmphasis(string emphasis) {
            if (emphasis != "Art Studio" &&
                emphasis != "Art History" &&
                emphasis != "Art Education") cout << "Cannot set emphasis to " << emphasis << endl;
            else this->emphasis = emphasis;
         }
};

class Physics_Student: public Student {
   private:
      string concentration;
   public:
         //init and destructor
         Physics_Student(): Student() {}
         Physics_Student(string name, string gpa, string grad_info,string enroll_info, string degree_sought, string concentration): Student(name, gpa, grad_info, enroll_info, degree_sought) {
            this->concentration = concentration;
         }
         ~Physics_Student() {}
         //getters
         string getConcentration() {return concentration;}
         //setters
         void setConcentration(string concentration) {
            if (concentration != "Biophysics" &&
                concentration != "Earth and Planetary Sciences") cout <<"Cannot set concentration to " << concentration << endl;
            else this->concentration = concentration;
         }
};


int main() {
   //values
   vector<string> name_list = {"Sally Begay", "Neptune Barton", "Mya Tsosie", "John Yazzie", "Brooke Smith"};
   vector<string> gpa_list = {"3.85", "3.78", "4.00", "3.67", "3.61", "3.00"};
   vector<string> grad_list = {"Fall 2029", "Spring 2029", "Summer 2028", "Spring 2021", "Fall 2027"};
   vector<string> degree_list = {"Bachelor", "Master", "PhD", "Associates", "Bachelor"};
   
   vector<string> emphasis_list = {"Art History", "Art Studio", "Art Education", "Art Studio", "Art History"};
   vector<string> concentration_list = {"Biophysics", "Biophysics", "Earth and Planetary Sciences", "Earth and Planetary Sciences", "Biophysics"};
   //init art students
   vector<Art_Student*> art_students; 
   vector<Physics_Student*> physics_students;
   for (int i = 0; i < 5; i++) {
      art_students.push_back(new Art_Student(name_list[i], gpa_list[i], grad_list[i], "Spring 2026", degree_list[i], emphasis_list[i]));
      physics_students.push_back(new Physics_Student(name_list[i],gpa_list[i], grad_list[i], "Spring 2026", degree_list[i], concentration_list[i]));
   }
   
   ofstream out_file;
   out_file.open("student_info.dat", std::ios::out);
   if (out_file.is_open()) {
      //write art students
      out_file << "Art Students" << endl;
      for (Art_Student* student : art_students) {
         out_file << student->getName() << "," << student->getGpa() << "," << student->getGradInfo() << ","
                  << "Spring 2026," << student->getDegreeSought() << "," << student->getEmphasis() << endl;
      }
      //write physics students
      out_file << "Physics Students" << endl;
      for (Physics_Student* student : physics_students) {
         out_file << student->getName() << "," << student->getGpa() << "," << student->getGradInfo() << ","
                  << "Spring 2026," << student->getDegreeSought() << "," << student->getConcentration() << endl;
      }
      out_file.close();
   } else cout << "Could not open file" << endl;

   return 0;
}
