#include<iostream>
#include <fstream>
#include<string>
using namespace std;
struct Record{
    int  id;
   char name[50];
};
using namespace std;
 int main() {

     Record r1 = {1, "Alice"};
     Record r2 = {2, "Bob"};
     Record r3 = {3, "Charlie"};

 fstream file("new.dat", ios :: out | ios :: binary );

 file.write(reinterpret_cast<char*>(&r1), sizeof(Record));
     file.write(reinterpret_cast<char*>(&r2), sizeof(Record));
     file.write(reinterpret_cast<char*>(&r3), sizeof(Record));


     file.close();

 fstream newfile("new.dat", ios::in | ios::binary);
 int index = 2;
 newfile.seekg(index * sizeof(Record), ios:: beg);


Record r;
     newfile.read(reinterpret_cast<char*>(&r), sizeof(Record));
if(newfile.gcount()== sizeof(Record)) {

    cout << "Record " << index << endl;
    cout << "ID: " << r.id << endl;
    cout << "Name: " << r.name << endl;


   newfile.close();
 }
return 0;
 }