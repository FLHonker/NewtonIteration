// Newton Iteration method for equation.
// Method1: original Newton's method.
#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

// example: 2*x^3 - 9*x^2 -25 = 0
// func: f(x) = 2*x^3 - 9*x -25
// dfunc: df(x) = 6*x^2 - 9
#define f(x)  2*x*x*x - 9*x -25
#define df(x)  6*x*x - 9
#define MAXI 50

// compute and return the function's value.
double func(double x)
{
    return f(x);
}

// compute and return the derivative function's value.
double dfunc(double x)
{
    return df(x);
}

int main(int argc, char** argv)
{
    double epsilon, x0, x1, fx0, dfx0, xret;
    long i;
    cout << "请输入精度要求:";
    cin >> epsilon;
    cout << "请输入迭代初值:";
    cin >> x1;
    cout << "请输入方程的真正根用于分析比较误差:";
    cin >> xret;
    cout << "最大迭代次数默认50." << endl;
    for(i = 0; i < MAXI; ++i)
    {
        x0 = x1;
        fx0 = func(x0);
        dfx0 = dfunc(x0);
        x1 = x0 - fx0/dfx0;
        cout << "step" << i << " 误差:" << x1 - xret << endl;
        if(fabs(x1-x0) <= epsilon)
            break;
    }
    if(i < MAXI)
        cout << "方程f(x)=0的根x=" << x1 << endl;
    else
        cout << "迭代次数已达上限." << endl;

    return 0;
}
