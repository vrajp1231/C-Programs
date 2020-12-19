#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
/**
   The FeetInches class holds distances measured in
   feet and inches.

   Remove the feet and inches data members and replace them with 
   one data member named total_inches. Re-implement all the class
   methods so they have the same functionality as originally. This
   means that any program written using the public members of the
   new class must produce exactly the same results as the original
   implementation.
*/

class FeetInches
{
   private:
      int totalInches;

      void simplify(int f, int i)
      {
         totalInches = 12*f + i;
      }
      
   public:
      FeetInches() {
         totalInches = 0;
      }

      FeetInches(int f, int i) {
         simplify(f,i);
      }

      FeetInches (const FeetInches& object2) {
         totalInches = object2.totalInches;
      }

      void setFeet(int f) {
         totalInches += 12*f;
      }

      void setInches(int i) {
         totalInches += i;
      }

      int getFeet() {
         return totalInches/12;
      }

      int getInches() {
         return totalInches % 12;
      }

      void print() {
         cout << getFeet() << " feet  " << getInches() << " inches";
      }

      FeetInches add(const FeetInches& object2) {
         int Added_Feet, Added_Inches;
         Added_Feet = getFeet() + (object2.totalInches / 12);
         Added_Inches = getInches() + (object2.totalInches % 12);

         return FeetInches(Added_Feet, Added_Inches);
      }

      bool equals(FeetInches object2) {
         return totalInches == object2.totalInches;
      }

      FeetInches scale(int s) {
         return FeetInches(s*getFeet(), s*getInches());
      }
};

int main()
{
   FeetInches f(0, 30), g;
	int ft, in;
	
   cout << "Length 1 is = ";
   f.print();
   cout << endl;
	
   cout << "\nEnter the feet of Length 2: ";
   cin >> ft;
	
   cout << "Enter the inches of Length 2: ";
   cin >> in;

	g.setFeet(ft);
	g.setInches(in);
	
	cout << "\nLength 2 = "; g.print(); cout << endl;
	
   if (f.equals(g))
		cout << "\nThe lengths are the same.\n\n";
	else
		cout << "\nThe lengths are not the same.\n\n";
   
	FeetInches h = f.add(g);
	
   cout << "The sum of Length 1 and Length 2 = "; h.print(); cout << endl;
	cout << "2 * Length 1 = "; f.scale(2).print(); cout << endl;
	cout << "3 * Length 2 = "; g.scale(3).print(); cout << endl;
	
	system("pause");

   return 0;
}