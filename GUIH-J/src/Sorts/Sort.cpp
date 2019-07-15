//
// Created by pda on 16.06.19.
//

#include "Sort.h"

int swp = 0; //кол-во свапов
int eql = 0; //кол-во сравнений



// Функция "просеивания" через кучу - формирование кучи
void Heapsort::siftDown(int *numbers, int root, int bottom) {
    int maxChild; // индекс максимального потомка
    int done = 0; // флаг того, что куча сформирована

    // Пока не дошли до последнего ряда
    while ((root * 2 + 1 <= bottom) && (!done)) {
        if (root * 2 + 1 == bottom) { // если мы в последнем ряду,
            maxChild = root * 2 + 1;
            eql++;
        } // запоминаем левый потомок
            // иначе запоминаем больший потомок из двух
        else if (numbers[root * 2 + 1] > numbers[root * 2 + 2])
            maxChild = root * 2 + 1;
        else
            maxChild = root * 2 + 2;
        // если элемент вершины меньше максимального потомка
        eql = eql + 2;
        if (numbers[root] < numbers[maxChild]) {
            swp++;                    //тут
            int temp = numbers[root]; // меняем их местами
            numbers[root] = numbers[maxChild];
            numbers[maxChild] = temp;
            root = maxChild;
        } else      // иначе
            done = 1; // пирамида сформирована
    }
}

Resultdata *Heapsort::sorting(int *numbers, unsigned int array_size) {
    swp = 0;
    eql = 0;

    clock_t start = clock();

    //строим сортирующее дерево
    for (int i = array_size / 2 - 1; i >= 0; i--) { siftDown(numbers, i, array_size - 1); }
    // Просеиваем через пирамиду остальные элементы
    for (int i = array_size - 1; i > 0; i--) {
        int temp = numbers[0];
        numbers[0] = numbers[i];
        numbers[i] = temp;
        swp++; //тут
        siftDown(numbers, 0, i - 1);
    }

    clock_t end = clock();

    Resultdata *resultdata = new Resultdata;
    resultdata->set_swp(swp);
    resultdata->set_eql(eql);
    resultdata->set_time((double) (end - start) / CLOCKS_PER_SEC);

    return resultdata;

}

//*************************************************


void reheap(int *a, int length, int i) {

    //С этим родителем ещё не разобрались
    bool done = false;

    //Запоминаем отдельно родителя
    //и смотрим на его потомка слева
    int T = a[i];
    int parent = i;
    int child = 2 * (i + 1) - 1;

    //Просматриваем потомков, а также потомков потомков
    //и сравниваем их с родителем (если что - передвигаем потомков влево)
    //Цикл продолжается пока не выпадем за пределы массива
    //или пока не обменяем какого-нибудь потомка на родителя.
    while ((child < length) && (!done)) {

        //Если правый потомок в пределах массива
        if (child < length - 1) {
            eql++;
            //То из левого и правого потомка выбираем наименьшего
            if (a[child] >= a[child + 1]) {
                child += 1;
            }
        }

        //Родитель меньше потомков?
        eql++;
        if (T < a[child]) {

            //Тогда с этим родителем и его потомками разобрались
            done = true;

            //Родитель НЕ меньше чем наименьший из его потомков.
            //Перемещаем потомка на место родителя
            //и с родителем в цикле сравниваем уже потомков этого потомка
        } else {
            swp++;
            a[parent] = a[child];
            parent = child;
            child = 2 * (parent + 1) - 1;

        }
    }

    //Родитель, с которого всё начиналось
    //передвигается ближе к концу массива
    //(или остаётся на месте если не повезло)
    swp++;
    a[parent] = T;

}

void invreheap(int *a, int length, int i) {

    //С этим родителем ещё не разобрались
    bool done = false;

    //Запоминаем отдельно родителя
    //и смотрим на его потомка слева
    int T = a[length - 1 - i];
    int parent = i;
    int child = 2 * (i + 1) - 1;

    //Просматриваем потомков, а также потомков потомков
    //и сравниваем их с родителем (если что - передвигаем потомков)
    //Цикл продолжается пока не выпадем за пределы массива
    //или пока не обменяем какого-нибудь потомка на родителя.
    while ((child < length) && (!done)) {

        //Если левый потомок в пределах массива
        if (child < length - 1) {
            eql++;
            //То из левого и правого потомка выбираем наибольшего
            if (a[length - 1 - child] <= a[length - 1 - (child + 1)]) {
                child += 1;
            }

        }

        //Родитель больше потомков?
        eql++;
        if (T > a[length - 1 - child]) {

            //Тогда с этим родителем и его потомками разобрались
            done = true;

        } else {

            //Родитель НЕ больше чем наибольший из его потомков.
            //Перемещаем потомка на место родителя
            //и с родителем в цикле сравниваем уже потомков этого потомка
            swp++;
            a[length - 1 - parent] = a[length - 1 - child];
            parent = child;
            child = 2 * (parent + 1) - 1;

        }
    }

    //Родитель, с которого всё начиналось
    //передвигается ближе к началу массива
    //(или остаётся на месте если не повезло)
    swp++;
    a[length - 1 - parent] = T;

}

Resultdata *Jsort::sorting(int *mass, unsigned int N) {

    swp = 0;
    eql = 0;

    clock_t start = clock();

//Строим неубывающую кучу
    //Большие элементы из начала массива
    //закидываем поближе к концу
    for (int i = N - 1; i >= 0; i--)
        reheap(mass, N, i);

    //Строим невозрастающую кучу   
    //Меньшие элементы из конца массива
    //закидываем поближе к началу
    for (int i = N - 1; i >= 0; i--)
        invreheap(mass, N, i);

    //Массив ПОЧТИ упорядочен
    //Досортировываем вставками
    for (int j = 1; j < N; j++) {
        int T = mass[j];
        int i = j - 1;
        eql++;
        while (i >= 0 && mass[i] > T) {
            mass[i + 1] = mass[i];
            i -= 1;
            eql++;
            swp++;
        }
        mass[i + 1] = T;
    }
    clock_t end = clock();

    Resultdata *resultdata = new Resultdata;
    resultdata->set_swp(swp);
    resultdata->set_eql(eql);
    resultdata->set_time((double) (end - start) / CLOCKS_PER_SEC);

    return resultdata;

}


void Resultdata::set_time(double t) {
    time = t;
}

void Resultdata::set_eql(int e) {
    eql = e;
}

void Resultdata::set_swp(int s) {
    swp = s;
}

int Resultdata::get_eql() {
    return eql;
}

int Resultdata::get_swp() {
    return swp;
}

double Resultdata::get_time() {
    return time;
}