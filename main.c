#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define ROW 3
#define COL 3

int matrix1[ROW][COL];
int matrix2[ROW][COL];

// Print two matrices
void print_matrices()
{
    printf("\nMatrix 1:\n");
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            printf("%3d ", matrix1[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix 2:\n");
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            printf("%3d ", matrix2[i][j]);
        }
        printf("\n");
    }
}

// 1. Matrix multiplication (element-wise)
void multiply_matrices()
{
    int product[ROW][COL];

    printf("\nMatrix Multiplication (Element-wise):\n");
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            product[i][j] = matrix1[i][j] * matrix2[i][j];
            printf("%3d ", product[i][j]);
        }
        printf("\n");
    }
}

// 2. Max and min element position
void max_min_element(int matrix[ROW][COL], char* name)
{
    int max = matrix[0][0], min = matrix[0][0];
    int row_max = 0, col_max = 0;
    int row_min = 0, col_min = 0;

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (matrix[i][j] > max)
            {
                max = matrix[i][j];
                row_max = i;
                col_max = j;
            }
            if (matrix[i][j] < min)
            {
                min = matrix[i][j];
                row_min = i;
                col_min = j;
            }
        }
    }

    printf("\n%s:\n", name);
    printf("Max element: %d -> Position: row %d, col %d\n", max, row_max, col_max);
    printf("Min element: %d -> Position: row %d, col %d\n", min, row_min, col_min);
}
// 3. Row closest to average
void row_closest_to_avg(int matrix[ROW][COL], char* name)
{
    int total = 0;
    double avg = 0;
    double row_totals[ROW];
    double diff, min_diff;
    int closest_row = 0;

    for (int i = 0; i < ROW; i++)
    {
        int row_total = 0;
        for (int j = 0; j < COL; j++)
        {
            row_total += matrix[i][j];
        }
        row_totals[i] = row_total;
        total += row_total;
    }

    avg = (double)total / (ROW * COL);

    min_diff = fabs(row_totals[0] - avg);
    for (int i = 1; i < ROW; i++)
    {
        diff = fabs(row_totals[i] - avg);
        if (diff < min_diff)
        {
            min_diff = diff;
            closest_row = i;
        }
    }

    printf("\n%s:\n", name);
    printf("Row closest to average: Row %d -> ", closest_row + 1);
    for (int j = 0; j < COL; j++)
    {
        printf("%d ", matrix[closest_row][j]);
    }
    printf("\nMatrix average: %.2lf\n", avg);
}


// 4. Diagonal sums
void diagonal_sums(int matrix[ROW][COL], char* name)
{
    int sum1 = 0, sum2 = 0;

    for (int i = 0; i < ROW; i++)
    {
        sum1 += matrix[i][i];              // Top-left to bottom-right
        sum2 += matrix[i][COL - 1 - i];    // Top-right to bottom-left
    }

    printf("\n%s:\n", name);
    printf("1st Diagonal Sum: %d\n", sum1);
    printf("2nd Diagonal Sum: %d\n", sum2);
}


// 5. Row and column sums (printed separately)
void row_col_sums(int matrix[ROW][COL], char* name)
{
    printf("\n%s:\n", name);

    // Row sums
    for (int i = 0; i < ROW; i++)
    {
        int row_sum = 0;
        for (int j = 0; j < COL; j++)
        {
            row_sum += matrix[i][j];
        }
        printf("Sum of row %d: %d\n", i + 1, row_sum);
    }

    // Column sums
    for (int j = 0; j < COL; j++)
    {
        int col_sum = 0;
        for (int i = 0; i < ROW; i++)
        {
            col_sum += matrix[i][j];
        }
        printf("Sum of column %d: %d\n", j + 1, col_sum);
    }
}

int main()
{
    int choice;

    srand(time(NULL)); // For random numbers

    // Fill matrices with random numbers between 1 and 10
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            matrix1[i][j] = rand() % 10 + 1;
            matrix2[i][j] = rand() % 10 + 1;
        }
    }

    print_matrices();

    while (1)
    {
        printf("\nSelect Operation:\n");
        printf("1 - Multiply Two Matrices (element-wise)\n");
        printf("2 - Max and Min Element Indices\n");
        printf("3 - Find Row Closest to Average\n");
        printf("4 - Diagonal Sums\n");
        printf("5 - Row and Column Sums\n");
        printf("6 - Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        print_matrices();

        switch (choice)
        {
        case 1:
            multiply_matrices();
            break;
        case 2:
            max_min_element(matrix1, "Matrix 1");
            max_min_element(matrix2, "Matrix 2");
            break;
        case 3:
            row_closest_to_avg(matrix1, "Matrix 1");
            row_closest_to_avg(matrix2, "Matrix 2");
            break;
        case 4:
            diagonal_sums(matrix1, "Matrix 1");
            diagonal_sums(matrix2, "Matrix 2");
            break;
        case 5:
            row_col_sums(matrix1, "Matrix 1");
            row_col_sums(matrix2, "Matrix 2");
            break;
        case 6:
            printf("Exiting program...\n");
            return 0;
        default:
            printf("Invalid selection!\n");
            break;
        }
    }

    return 0;
}
