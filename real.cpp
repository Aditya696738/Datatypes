#include <iostream>
#include <string>
using namespace std;
int main(){
    int items = 50;
    float cost_of_item = 99.94;
    double total_cost_of_item = items * cost_of_item;
    char currency = '$';

    cout << "no. of items: " << items << endl << "\n";
    cout << "cost of items: " << cost_of_item << currency << endl << "\n";
    cout << "total cost of items: " << total_cost_of_item << currency << endl ;
    return 0;
}