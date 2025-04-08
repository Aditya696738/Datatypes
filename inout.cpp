#include <iostream>
#include <string>
using namespace std;
int main(){
    string name_of_person;
    int no_of_tickets;
    const float price_of_ticket = 99.34;
    float total_cost;
    char currency = '$';

    cout << "Name of person" << "\n";
    getline(cin, name_of_person);

    cout << "how many tickets sir" << endl;
    cin >> no_of_tickets;

     total_cost = no_of_tickets * price_of_ticket;

    cout << "total cost is :- " << total_cost << currency << endl;
    cin >> total_cost;
    return 0;
}