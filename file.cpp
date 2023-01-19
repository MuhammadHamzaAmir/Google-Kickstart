#include <iostream>
#include <cstdio>

const int N = 105;

int a[N][N], b[N][N], c[N][N];

int n, m, p, q;

void add()
{
    if (n != p || m != q)
    {
        std::cout << "Addition not possible" << std::endl;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }

    std::cout << "Result of addition: " << std::endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cout << c[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void subtract()
{
    if (n != p || m != q)
    {
        std::cout << "Subtraction not possible" << std::endl;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            c[i][j] = a[i][j] - b[i][j];
        }
    }

    std::cout << "Result of subtraction: " << std::endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cout << c[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void multiply()
{
    if (m != p)
    {
        std::cout << "Multiplication not possible" << std::endl;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < q; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < m; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    std::cout << "Result of multiplication: " << std::endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < q; j++)
        {
            std::cout << c[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void transpose()
{
    int d[N][N];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            d[i][j] = a[j][i];
        }
    }

    std::cout << "Transpose of the matrix: " << std::endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cout << d[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int determinant(int f[N][N], int x)
{
    int pr, c[N][N], d = 0, k = 1;
    if (x == 2)
    {
        return ((f[0][0] * f[1][1]) - (f[1][0] * f[0][1]));
    }
    else
    {
        for (int i = 0; i < x; i++)
        {
            int c1 = 0;
            for (int j = 1; j < x; j++)
            {
                for (int k = 0; k < x; k++)
                {
                    if (k == i)
                    {
                        continue;
                    }
                    c[c1][j - 1] = f[j][k];
                }
                c1++;
            }
            d = d + (k * f[0][i] * determinant(c, x - 1));
            k = -1 * k;
        }
    }
    return d;
}
int main()
{
    std::cout << "Enter the number of rows and columns of the first matrix: ";
    std::cin >> n >> m;
    std::cout << "Enter the elements of the first matrix: " << std::endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cin >> a[i][j];
        }
    }

    std::cout << "Enter the number of rows and columns of the second matrix: ";
    std::cin >> p >> q;
    std::cout << "Enter the elements of the second matrix: " << std::endl;
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < q; j++)
        {
            std::cin >> b[i][j];
        }
    }

    add();
    subtract();
    multiply();
    transpose();
    std::cout << "Determinant of the matrix: " << determinant(a, n) << std::endl;
    return 0;
}
