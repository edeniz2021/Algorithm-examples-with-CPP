/*. Create a Temperature class that internally stores a temperature in degrees Kelvin. 
Create functions named setTempKelvin, setTempFahrenheit, and setTempCelsius that take an input temperature in the specified temperature scale, convert the temperature to Kelvin, and store that temperature in the class member variable.
Also, create functions that return the stored temperature in degrees Kelvin, Fahrenheit, or Celsius. Write a main function to test your class. Use the equations shown next to convert between the three temperature scales:
Kelvin = Celsius + 273.15
Celsius = (5.0/9) * (Fahrenheit - 32)*/
#include <iostream>
#include <cmath>
using namespace std;
class Temperature
{
    public:
    Temperature();
    void convert_temperature();
    void setTempKelvin(double temp);
    void setTempCelsius(double temp);
    void setTempFahrenheit(double temp);
    double getTempKelvin()const;
    double getTempCelsius()const;
    double getTempFahrenheit()const;
    private:
    double degree;

};
Temperature::Temperature()
{
    degree = 0.0;
}
void Temperature::setTempKelvin(double temp)
{
    degree = temp;
}
void Temperature::setTempCelsius(double temp)
{
   degree = temp + 273.15;
}
void Temperature::setTempFahrenheit(double temp)
{
     degree = (5.0/9) * (temp -32)+273.15;
}
double Temperature::getTempKelvin()const
{
    return degree;
}
double Temperature::getTempCelsius()const
{
    return degree - 273.15;;
}
double Temperature::getTempFahrenheit()const
{
    return  (degree - 273.15)* (9/5.0)+32;
}
int main()
{
    Temperature temp;

    temp.setTempKelvin(300);
    cout << "Temperature in Kelvin: " << temp.getTempKelvin() << endl;
    cout << "Temperature in Celsius: " << temp.getTempCelsius() << endl;
    cout << "Temperature in Fahrenheit: " << temp.getTempFahrenheit() << endl;

    temp.setTempFahrenheit(68);
    cout << "Temperature in Kelvin: " << temp.getTempKelvin() << endl;
    cout << "Temperature in Celsius: " << temp.getTempCelsius() << endl;
    cout << "Temperature in Fahrenheit: " << temp.getTempFahrenheit() << endl;

    temp.setTempCelsius(25);
    cout << "Temperature in Kelvin: " << temp.getTempKelvin() << endl;
    cout << "Temperature in Celsius: " << temp.getTempCelsius() << endl;
    cout << "Temperature in Fahrenheit: " << temp.getTempFahrenheit() << endl;

    return 0;
}


