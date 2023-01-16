#include <iostream>
#include <cstdarg>
#include <tuple>
using namespace std;
typedef tuple<size_t, void*> ARGS;
void Func(tuple<size_t, void*> args...)
{
    va_list args_list;
    va_start(args_list, 0);
    va_arg(args_list, ARGS);
    va_arg(args_list, ARGS);
    va_arg(args_list, ARGS);
    va_end(args_list);

}
int main()
{
    int a = 10;
    double d = 10.0;
    const char* p = "Hello";

    Func(make_tuple(sizeof(int), &a), make_tuple(sizeof(double), &d), make_tuple(strlen(p), &p));
    // Types : int, int, int
    // args : 1, 2, 3
}