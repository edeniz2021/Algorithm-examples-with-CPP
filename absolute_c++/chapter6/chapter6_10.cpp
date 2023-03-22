/*. Create a Temperature class that internally stores a temperature in degrees Kelvin. 
Create functions named setTempKelvin, setTempFahrenheit, and setTempCelsius that take an input temperature in the specified temperature scale, convert the temperature to Kelvin, and store that temperature in the class member variable.
Also, create functions that return the stored temperature in degrees Kelvin, Fahrenheit, or Celsius. Write a main function to test your class. Use the equations shown next to convert between the three temperature scales:
Kelvin = Celsius + 273.15
Celsius = (5.0/9) * (Fahrenheit - 32)*/
#include <iostream>
#include <cmath>

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

int main()
{
    return 0;
}


