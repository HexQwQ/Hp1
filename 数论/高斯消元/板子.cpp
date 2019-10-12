#include <iostream>
#include <string>
#include <cmath>
using namespace std;

const int maxn = 105;

int equ, var; 
int a[maxn][maxn];
int x[maxn];
bool free_x[maxn]; 
int free_num;

void Debug(){
    int i, j;
    for (i = 0; i < equ; i++)
    {
        for (j = 0; j < var + 1; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

inline int gcd(int a, int b){
    int t;
    while (b != 0)
    {
        t = b;
        b = a % b;
        a = t;
    }
    return a;
}

inline int lcm(int a, int b){
    return a * b / gcd(a, b);
}

int Gauss(){
    int i, j, k;
    int max_r; 
	int col; 
    int ta, tb;
    int LCM;
    int temp;
    int free_x_num;
    int free_index;
    col = 0; 
    for (k = 0; k < equ && col < var; k++, col++)
    {
		max_r = k;
        for (i = k + 1; i < equ; i++)
        {
            if (abs(a[i][col]) > abs(a[max_r][col])) max_r = i;
        }
        if (max_r != k)
        {
            for (j = k; j < var + 1; j++) swap(a[k][j], a[max_r][j]);
        }
        if (a[k][col] == 0)
        {
            k--; continue;
        }
        for (i = k + 1; i < equ; i++)
        {
            if (a[i][col] != 0)
    		{
                LCM = lcm(abs(a[i][col]), abs(a[k][col]));
                ta = LCM / abs(a[i][col]), tb = LCM / abs(a[k][col]);
                if (a[i][col] * a[k][col] < 0) tb = -tb; 
                for (j = col; j < var + 1; j++)
                {
                    a[i][j] = a[i][j] * ta - a[k][j] * tb;
                }
    		}
        }
    }
    Debug();
    for (i = k; i < equ; i++)
    { 
        if (a[i][col] != 0) return -1;
    }
    if (k < var)
    {
        for (i = k - 1; i >= 0; i--)
        {
            free_x_num = 0; 
            for (j = 0; j < var; j++)
            {
                if (a[i][j] != 0 && free_x[j]) free_x_num++, free_index = j;
            }
            if (free_x_num > 1) continue; 
            temp = a[i][var];
            for (j = 0; j < var; j++)
            {
                if (a[i][j] != 0 && j != free_index) temp -= a[i][j] * x[j];
            }
            x[free_index] = temp / a[i][free_index]; 
            free_x[free_index] = 0; 
        }
        return var - k;
    for (i = var - 1; i >= 0; i--)
    {
        temp = a[i][var];
        for (j = i + 1; j < var; j++)
        {
            if (a[i][j] != 0) temp -= a[i][j] * x[j];
        }
        if (temp % a[i][i] != 0) return -2; 
        x[i] = temp / a[i][i];
    }
	return 0;
}

int main(){
    int i, j;
    while (scanf("%d %d", &equ, &var) != EOF)
    {
        memset(a, 0, sizeof(a));
   		memset(x, 0, sizeof(x));
  		memset(free_x, 1, sizeof(free_x)); 
        for (i = 0; i < equ; i++)
        {
            for (j = 0; j < var + 1; j++)
            {
                scanf("%d", &a[i][j]);
            }
        }
        free_num = Gauss();
        if (free_num == -1) printf("无解!\n");
   		else if (free_num == -2) printf("有浮点数解，无整数解!\n");
        else if (free_num > 0)
        {
            printf("无穷多解! 自由变元个数为%d\n", free_num);
            for (i = 0; i < var; i++)
            {
                if (free_x[i]) printf("x%d 是不确定的\n", i + 1);
                else printf("x%d: %d\n", i + 1, x[i]);
            }
        }
        else
        {
            for (i = 0; i < var; i++)
            {
                printf("x%d: %d\n", i + 1, x[i]);
            }
        }
        printf("\n");
    }
    return 0;
}
