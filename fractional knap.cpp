#include <stdio.h>

#define MAX 100

int n;
float capacity;

float value[MAX];
float weight[MAX];
float ratio[MAX];
float quantity[MAX];
float selectedValue[MAX];

void enterDetails()
{
    int i;

    printf("\nEnter number of packages: ");
    scanf("%d", &n);

    printf("Enter vehicle capacity: ");
    scanf("%f", &capacity);

    for (i = 0; i < n; i++)
    {
        printf("\nEnter value of package %d: ", i + 1);
        scanf("%f", &value[i]);

        printf("Enter weight of package %d: ", i + 1);
        scanf("%f", &weight[i]);

        ratio[i] = 0;
        quantity[i] = 0;
        selectedValue[i] = 0;
    }

    printf("\nPackage details entered successfully!\n");
}

void displayDetails()
{
    int i;
    printf("Package\tValue\tWeight\tRatio\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%.2f\t%.2f\t%.2f\n",
               i + 1, value[i], weight[i], ratio[i]);
    }
    printf("Vehicle Capacity = %.2f\n", capacity);
}

void calculateRatio()
{
    int i;

    for (i = 0; i < n; i++)
    {
        ratio[i] = value[i] / weight[i];
    }

    printf("\nValue/Weight ratios calculated successfully!\n");
    printf("Package\tValue\tWeight\tRatio\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%.2f\t%.2f\t%.2f\n",
               i + 1, value[i], weight[i], ratio[i]);
    }

    printf("\n");
}

void sortPackages()
{
    int i, j;

    float temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (ratio[j] < ratio[j + 1])
            {
             
                temp = ratio[j];
                ratio[j] = ratio[j + 1];
                ratio[j + 1] = temp;

                temp = value[j];
                value[j] = value[j + 1];
                value[j + 1] = temp;

                temp = weight[j];
                weight[j] = weight[j + 1];
                weight[j + 1] = temp;
            }
        }
    }

    printf("\nPackages sorted by decreasing Value/Weight ratio!\n");
    printf("Package\tValue\tWeight\tRatio\n");

    for (i = 0; i < n; i++)
    {
        printf("%d\t%.2f\t%.2f\t%.2f\n",
               i + 1, value[i], weight[i], ratio[i]);
    }

}

void findMaximumValue()
{
    int i;
    float remainingCapacity;
    float totalValue = 0;
    float totalWeight = 0;

    remainingCapacity = capacity;

    for (i = 0; i < n; i++)
    {
        quantity[i] = 0;
        selectedValue[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        if (remainingCapacity == 0)
            break;

        if (weight[i] <= remainingCapacity)
        {
            quantity[i] = 1;
            selectedValue[i] = value[i];

            remainingCapacity = remainingCapacity - weight[i];

            totalWeight = totalWeight + weight[i];
            totalValue = totalValue + value[i];
        }

        else
        {
            quantity[i] = remainingCapacity / weight[i];

            selectedValue[i] = quantity[i] * value[i];

            totalWeight = totalWeight + remainingCapacity;
            totalValue = totalValue + selectedValue[i];

            remainingCapacity = 0;
        }
    }

    printf("FRACTIONAL KNAPSACK RESULT\n");
    printf("Total Weight Used = %.2f\n", totalWeight);
    printf("Maximum Value     = %.2f\n", totalValue);

}


void displaySelectedPackages()
{
    int i;
	printf("Package\tWeight\tQuantity\tSelected Value\n");
    for (i = 0; i < n; i++)
    {
        if (quantity[i] > 0)
        {
            printf("%d\t%.2f\t%.2f\t\t%.2f\n",
                   i + 1,
                   weight[i],
                   quantity[i],
                   selectedValue[i]);
        }
    }
}

int main()
{
    int choice;

    do
    {
        printf("MENU\n");
        printf("1. Enter Package Details\n");
        printf("2. Display Package Details\n");
        printf("3. Calculate Value/Weight Ratio\n");
        printf("4. Sort Packages by Ratio\n");
        printf("5. Find Maximum Value\n");
        printf("6. Display Selected Packages\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                enterDetails();
                break;

            case 2:
                displayDetails();
                break;

            case 3:
                calculateRatio();
                break;

            case 4:
                sortPackages();
                break;

            case 5:
                findMaximumValue();
                break;

            case 6:
                displaySelectedPackages();
                break;

            case 7:
                printf("\nProgram terminated successfully.\n");
                break;

            default:
                printf("\nInvalid choice! Please enter 1-7.\n");
        }

    } while (choice != 7);

    return 0;
}


