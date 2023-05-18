#include <iostream>
#include <vector>

using namespace std;


int* Numbers;
int Size;
int Capacity;


void pop_back()
{
    if (Size != 0)
        --Size;
}

void push_back(int _value)
{
    if (Size == Capacity)
    {
        int Length = int(Capacity * 0.5f);
        Capacity += Length < 1 ? 1 : Length;
    }
    
    int* temp = new int[Capacity];

    for (int i = 0; i < Size; ++i)
        temp[i] = Numbers[i];

    delete Numbers;
    Numbers = nullptr;

    Numbers = temp;

    Numbers[Size] = _value;

    ++Size;
}

void insert(int _where, int _value)
{
    if (_where > Size)
        return;

    if (Size == Capacity)
    {
        int Length = int(Capacity * 0.5f);
        Capacity += Length < 1 ? 1 : Length;
    }

    _where -= 1;

    for (int i = Size; _where <= i; --i)
    {
        Numbers[i + 1] = Numbers[i];
    }

    Numbers[_where] = _value;
    
    ++Size;

    /*int* temp = new int[Capacity];

    for (int i = 0; i < _where; ++i)
        temp[i] = Numbers[i];

    temp[_where] = _value;

    for (int i = Size; i > _where; --i)
        temp[i] = Numbers[i - 1];

    delete Numbers;
    Numbers = nullptr;

    Numbers = temp;

    ++Size;*/
}

void erase(int _where)
{
    if (_where > Size || _where <= 0)
        return;

    if (Size != 0)
        --Size;

    _where -= 1;
    for (int i = _where; i < Size; ++i)
        Numbers[i] = Numbers[i + 1];
}

int main(void)
{
    for (int i = 0; i < 10; ++i)
    {
        push_back(i * 10 + 10);
        cout << "size : " << Size << endl;
        cout << "capacity : " << Capacity << endl << endl; 
    }

    //insert(5, 111);
    erase(7);

    for (int i = 0; i < Size; ++i)
        cout << Numbers[i] << endl;

    cout << "size : " << Size << endl;
    cout << "capacity : " << Capacity << endl << endl;



    /*vector<int> vec;

    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);

    for (int i = 0; i < vec.size(); ++i)
        cout << vec[i] << endl;

    vec.insert(vec.begin() + 1, 5);
    cout << endl;

    for (int i = 0; i < vec.size(); ++i)
        cout << vec[i] << endl;*/

    return 0;
}