
/*

Question 2 : Enter cost of 3 items from the user (using float data type)- a pencil, a
pen and an eraser. You have to output the total cost of the items back to the user as
their bill.
(Add on : You can also try adding 18% GST tax to the items in the bill as an advanced
problem)


Final Total = Original Total × 1.18
*/


#include <iostream>
using namespace std;


int main() {
    float pencil, pen, eraser;  //define 3 items

    cout << "Enter pencil cost: ";
    cin >> pencil;
    cout << "Enter pen cost: ";
    cin >> pen;
    cout << "Enter eraser cost: ";
    cin >> eraser;

    float total = pencil + pen + eraser;   //cost
    //adding 18% GPT tax
    //total = total + 0.18*total;
    total = total*(1.18);

    cout << "Total cost of items including GST = " << total << endl;

    return 0;
}



#include <iostream>
using namespace std;

int main() {
    float pencil, pen, eraser;

    cout << "Enter pencil cost: ";
    cin >> pencil;

    cout << "Enter pen cost: ";
    cin >> pen;

    cout << "Enter eraser cost: ";
    cin >> eraser;

    float subtotal = pencil + pen + eraser;
    float gst = 0.18 * subtotal;
    float total = subtotal + gst;

    cout << "\nSubtotal = " << subtotal << endl;
    cout << "GST (18%) = " << gst << endl;
    cout << "Total Bill = " << total << endl;

    return 0;
}



// 💡 Bonus Tip (Formatting Output to 2 Decimal Places)
// If you want proper money formatting:
#include <iomanip>
cout << fixed << setprecision(2);

