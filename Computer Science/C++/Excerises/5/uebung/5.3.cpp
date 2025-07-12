#include <iostream>
#include <vector>

class IntArrayWrapper
{
private:
    int *array;
    mutable int constAccesses;
    int nonConstAccesses;

public:
    int size;
    IntArrayWrapper(int s);
    ~IntArrayWrapper();
    int &get(int index) const;
    int &get(int index);
    int sum() const;
    int nConstAccesses() const;
    int nNonConstAccesses() const;
};

IntArrayWrapper::IntArrayWrapper(int s) : size(s), constAccesses(0), nonConstAccesses(0)
{
    array = new int[size];
}

IntArrayWrapper::~IntArrayWrapper()
{
    delete[] array;
}

int &IntArrayWrapper::get(int index) const
{
    std::cout << "Accessing Index: " << index << " of array." << std::endl;
    std::cout << "Mode: const" << std::endl;
    constAccesses++;
    return array[index];
}

int &IntArrayWrapper::get(int index)
{
    std::cout << "Accessing Index: " << index << " of array." << std::endl;
    std::cout << "Mode: non const" << std::endl;
    nonConstAccesses++;
    return array[index];
}

int IntArrayWrapper::nConstAccesses() const
{
    return constAccesses;
}

int IntArrayWrapper::nNonConstAccesses() const
{
    return nonConstAccesses;
}

int IntArrayWrapper::sum() const
{
    int sum(0);
    for (int i = 0; i < size; i++)
    {
        sum += array[i];
    }
    return sum;
}
int main()
{
    IntArrayWrapper iw(10);
    std::cout << iw.size << std::endl;

    int &i3 = iw.get(4); // non-const accessing index 4
    i3 = 4;
    int i4 = iw.get(6); // non-const accessing index 6
    i4 = 6;
    const IntArrayWrapper &iwc = iw;
    const int &i1 = iwc.get(1);                                                  // const accessing index 1
    const int &i2 = iwc.get(3);                                                  // const accessing index 3
    int i7 = iwc.get(7);                                                         // const accessing index 7
    std::cout << "sum: " << iwc.sum() << std::endl;                              // 4
    std::cout << "const accesses: " << iwc.nConstAccesses() << std::endl;        // 3
    std::cout << "non-const accesses: " << iwc.nNonConstAccesses() << std::endl; // 2
    return 0;
}
