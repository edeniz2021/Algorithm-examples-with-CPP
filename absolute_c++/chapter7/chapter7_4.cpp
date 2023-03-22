#include <iostream>
using namespace std;
class HotDogStand
{
public:
    HotDogStand(int id, int numberSold);
    HotDogStand();
    HotDogStand(int id);
    void justSold();
    void setHotDogID(int id);
    int getHotDogID();
    static int getTotalHotDogs();
    int getNumberOfHotDogsSold();

private:
    int hotDogID;
    int hotDogsSold;

    static int total;
};
int HotDogStand::total = 0;
HotDogStand::HotDogStand()
{
    hotDogID = 0;
    hotDogsSold = 0;
}
HotDogStand::HotDogStand(int id, int number)
{
    hotDogID = id;
    hotDogsSold = number;
}
HotDogStand::HotDogStand(int id)
{
    hotDogID = id;
}
void HotDogStand::setHotDogID(int id)
{
    hotDogID = id;
}
int HotDogStand::getHotDogID()
{
    return hotDogID;
}
void HotDogStand::justSold()
{
    hotDogsSold++;
    total++;
}
int HotDogStand::getNumberOfHotDogsSold()
{
    return hotDogsSold;
}
int HotDogStand::getTotalHotDogs()
{
    return total;
}
int main()
{
    HotDogStand h(4, 3);
    HotDogStand d;
    HotDogStand hd(13);
    h.justSold();
    h.justSold();
    cout << "H id number: " << h.getHotDogID() << " sold: " << h.getNumberOfHotDogsSold() << endl;
    cout << "D id number: " << d.getHotDogID() << " sold: " << d.getNumberOfHotDogsSold() << endl;
    cout << "D id number: " << hd.getHotDogID() << " sold: " << d.getNumberOfHotDogsSold() << endl;
    cout << "Total number of hot dogs sold: " << h.getTotalHotDogs() << endl;
    d.justSold();
    d.justSold();
    d.justSold();
    cout << "H id number: " << h.getHotDogID() << " sold: " << h.getNumberOfHotDogsSold() << endl;
    cout << "D id number: " << d.getHotDogID() << " sold: " << d.getNumberOfHotDogsSold() << endl;
    cout << "D id number: " << hd.getHotDogID() << " sold: " << d.getNumberOfHotDogsSold() << endl;
    cout << "Total number of hot dogs sold: " << h.getTotalHotDogs() << endl;
    hd.justSold();
    hd.justSold();
    hd.justSold();
    hd.justSold();
    hd.justSold();
    hd.justSold();
    cout << "H id number: " << h.getHotDogID() << " sold: " << h.getNumberOfHotDogsSold() << endl;
    cout << "D id number: " << d.getHotDogID() << " sold: " << d.getNumberOfHotDogsSold() << endl;
    cout << "D id number: " << hd.getHotDogID() << " sold: " << d.getNumberOfHotDogsSold() << endl;
    cout << "Total number of hot dogs sold: " << h.getTotalHotDogs() << endl;
    cout << endl;
}