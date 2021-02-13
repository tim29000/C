#include <stdio.h>
#include <stdlib.h>

int main()
{

    float driver_salary;                                                                           // contains driver's salary
    float cost_of_fuel;                                                                            // contains whole cost of fuel consumed during the trip
    char car_type;                                                                                 // contains A or B, depends on entered by user value
    double gallon = 4.54609;
    float unleaded = 1.50;
    float diesel = 1.30;
    float cost_fuel_per_litre;

    int Distance_in_buildup_area;
    int Distance_in_single_carriageways;
    int Distance_in_double_carriageways_or_motorways;

    int consumption_in_buildup_area;                                                               // contains value of miles per gallon in this area
    int consumption_in_single_carriageways;                                                        // contains value of miles per gallon in this area
    int consumption_in_double_carriageways_or_motorways;                                           // contains value of miles per gallon in this area

    float litres_consumpted;                                                                       // litres, consumed during all trip
    float litres_in_buildup_area;                                                                  // litres, consumed in this area
    float litres_in_single_carriageways;                                                           // litres, consumed in this area
    float litres_in_double_carriageways_or_motorways;                                              // litres, consumed in this area

    float salary_10;                                                                               // salary that driver receives for the first 10 pounds of fuel
    float salary_20;                                                                               // salary that driver receives for the next 20 pounds of fuel
    float salary_30;                                                                               // salary that driver receives for the next 30 pounds of fuel
    float salary_excess;                                                                           // salary that driver receives for the excess of 60 pounds of fuel

    printf("\tEnter the distance in built-up areas : ");
    scanf("%d", &Distance_in_buildup_area);
    printf("\tEnter the distance in single carriageways : ");
    scanf("%d", &Distance_in_single_carriageways);
    printf("\tEnter the distance in double carriageways/motorways : ");
    scanf("%d", &Distance_in_double_carriageways_or_motorways);

    printf("\tPlease choose your car type(A or B): ");
    scanf("%s", &car_type);
    if(car_type == 'A')
    {
        cost_fuel_per_litre = unleaded;
        consumption_in_buildup_area = 40;
        consumption_in_single_carriageways = 50;
        consumption_in_double_carriageways_or_motorways = 60;
    }
    if(car_type == 'B')
    {
        cost_fuel_per_litre = diesel;
        consumption_in_buildup_area = 45;
        consumption_in_single_carriageways = 55;
        consumption_in_double_carriageways_or_motorways = 65;
    }

    litres_in_buildup_area = (float)Distance_in_buildup_area/(float)consumption_in_buildup_area*gallon*Distance_in_buildup_area;
    litres_in_single_carriageways = (float)Distance_in_single_carriageways/(float)consumption_in_single_carriageways*gallon*Distance_in_single_carriageways;
    litres_in_double_carriageways_or_motorways = (float)Distance_in_double_carriageways_or_motorways/(float)consumption_in_double_carriageways_or_motorways*gallon*Distance_in_double_carriageways_or_motorways;
    litres_consumpted = litres_in_buildup_area + litres_in_single_carriageways + litres_in_double_carriageways_or_motorways;

    cost_of_fuel = cost_fuel_per_litre * litres_consumpted;

    if(cost_of_fuel >= 10)
    {
        salary_10 = 10;
        if(cost_of_fuel-10 >= 20)
        {
            salary_20 = 40;
            if(cost_of_fuel-30 >= 30)
            {
                salary_30 = 90;
                if(cost_of_fuel > 60)
                {
                    salary_excess = (cost_of_fuel-60)*5;
                    driver_salary = salary_10+salary_20+salary_30+salary_excess;
                }
                else
                {
                    driver_salary = salary_10+salary_20+salary_30;
                }

            }
            else
            {
                driver_salary = salary_10+salary_20+((cost_of_fuel-30)*3);
            }
        }
        else
        {
            driver_salary = salary_10 + ((cost_of_fuel-10)*2);
        }
    }
    else
    {
        driver_salary = cost_of_fuel;
    }
    printf("\n\tType of vehicle:                                 %c\n", car_type);
    printf("\tDistance in built-up areas:                      %d\n", Distance_in_buildup_area);
    printf("\tDistance in single carriageways:                 %d\n", Distance_in_single_carriageways);
    printf("\tDistance in double carriageways/motorways:       %d\n", Distance_in_double_carriageways_or_motorways);
    printf("\tFuel cost = %.2f  Driver's salary = %.2f  Total cost = %.2f", cost_of_fuel, driver_salary, cost_of_fuel+driver_salary);

    return 0;
}
