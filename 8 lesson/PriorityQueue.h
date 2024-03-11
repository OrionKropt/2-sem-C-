#include <iostream>

class PriorityQueue
{
    static const int Msize = 100; // максимальный размер очереди
    struct Elem
    {
        int val, priori; // значение элемента и его приоритет
        Elem(int v = 0, int p = 0)
        {
            val = v;
            priori = p;
        }
    };
    Elem a[Msize];        // массив для хранения элементов
    int size;           // текущий размер очереди 
    void up(int i) { // операция "просеивания вверх"
        while (i != 0 && a[i].priori > a[(i - 1) / 2].priori)
        {
            std::swap(a[i], a[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }
    void down(int i) {
        while (i <= size / 2) {
            int maxI = i;
            if (2 * i + 1 <= size && a[2 * i + 1].priori < a[maxI].priori)
                maxI = 2 * i + 1;
            if (2 * i + 2 <= size && a[2 * i + 2].priori < a[maxI].priori)
                maxI = 2 * i + 2;
            if (a[i].priori <= a[maxI].priori) return;
            std::swap(a[i], a[maxI]);
            i = maxI;
        }
    }

public:
    PriorityQueue() { size = 0; }
    void enqueue(int val, int prior)
    {
        a[size++] = Elem(val, prior);
        up(size - 1);
    }
    int dequeue()
    {
        std::swap(a[0], a[size--]);
        down(0);
        return a[size].val;
    } 

};

   



    

