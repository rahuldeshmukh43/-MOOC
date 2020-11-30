#include <iostream>
using namespace std;
int main()
{
   int side_1, side_2, side_3, hypo_sq, rest_sq;

   cout << "Enter Length for Side 1: ";
   cin >> side_1;
   cout << "Enter Length for Side 2: ";
   cin >> side_2;
   cout << "Enter Length for Side 3: ";
   cin >> side_3;

   if( side_1 > side_2 && side_1 > side_3){
      hypo_sq = side_1*side_1;
      rest_sq = side_2*side_2 + side_3*side_3;
   }
   else if (side_2 > side_3){
      hypo_sq = side_2*side_2;
      rest_sq = side_1*side_1 + side_3*side_3;
   }
   else{
      hypo_sq = side_3*side_3;
      rest_sq = side_1*side_1 + side_2*side_2;  
   }
   if(hypo_sq == rest_sq)
      cout << "The given triangle is right angled" << endl;
   else
      cout << "The given triangle is not right angled" << endl;
   return 0;
}

