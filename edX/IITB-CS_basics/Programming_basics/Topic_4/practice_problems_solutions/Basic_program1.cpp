#include<iostream>
using namespace std;
int main()
{
    int width, length, area, perimeter;
    cout << "Enter the length of the Rectangle: ";
    cin >> length;
    cout << "Enter the width of the Rectangle: ";
    cin >> width;
    area = length * width;
    cout << "The area of Rectangle is (l x w) = " << area << endl;
    perimeter = 2 * (length + width);
    cout << "The perimeter of rectangle is 2(l + w) = " << perimeter << endl;
    return 0;
}
