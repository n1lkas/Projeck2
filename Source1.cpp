#include <iostream>
#include <chrono>
using namespace std;

const int N = 100;
void zadania(int N) {
    cout << "1. Создает целочисленный массив размерности N = 100. Элементы массивы должны принимать случайное значение в диапазоне от -99 до 99." << endl;
    cout << "2. Отсортировать заданный в пункте 1 массив […] сортировкой (от меньшего к большему). Определить время, затраченное на сортировку, используя библиотеку chrono." << endl;
    cout << "3. Найти максимальный и минимальный элемент массива. Подсчитайте время поиска этих элементов в отсортированном массиве и неотсортированном, используя библиотеку chrono." << endl;
    cout << "4.Выводит среднее значение (если необходимо, число нужно округлить) максимального и минимального значения в отсортированном и неотсортированном. Выводит индексы всех элементов, которые равны этому значению, и их количество. Подсчитайте время поиска." << endl;
    cout << "5. Выводит количество элементов в отсортированном массиве, которые меньше числа a, которое инициализируется пользователем." << endl;
    cout << "6. Выводит количество элементов в отсортированном массиве, которые больше числа b, которое инициализируется пользователем." << endl;
    cout << "7.  Выводит информацию о том, есть ли введенное пользователем число в отсортированном массиве. Реализуйте алгоритм бинарного поиска." << endl;
    cout << "8.  Меняет местами элементы массива, индексы которых вводит пользователь. Выведите скорость обмена, используя библиотеку chrono." << endl;
    cout << "9. Idz 4" << endl;
}
//1
void main1(int arr[], int sort_arr[]) {
	setlocale(0, "");
	for (int i = 0; i < N; i++)
	{
		int start = -99;
		int end = 99;
		arr[i] = rand() % (end - start + 1) + start;
		sort_arr[i] = arr[i];
	}
	cout << endl; 
}

//1.1
void bubble_sort(int bub[]) {
    
    auto start_time = chrono::high_resolution_clock::now();
    for (int i = 0; i < N; i++) {
        bool flag = true;
        for (int j = 0; j < N - (i + 1); j++) {
            if (bub[j] > bub[j + 1]) {
                flag = false;
                swap(bub[j], bub[j + 1]);
            }
        }
        if (flag) {
            break;
        }
    }
    auto end_time = chrono::high_resolution_clock::now();
    
    auto result = chrono::duration_cast<chrono::microseconds>(end_time - start_time);
    cout << "Отсортированный массив в порядке возрастания: " << endl;
    for (int i = 0; i < N; i++) {
        cout << "["<<bub[i]<<"]" << " "; 
    }
    cout << endl;
    cout << "Время сортировки: " << result.count() << " микросекунд" << endl;
}
//1.2
void shaker_sort(int sh[]) {
    
    bool sort_or_not = true;
    int right = N - 1; 
    int left = 1;
    auto start_time = chrono::high_resolution_clock::now();
    do {
        bool sort_or_not = true;
        for (int i = left; i <= right; i++) {
            if (sh[i - 1] > sh[i]) {
                swap(sh[i - 1], sh[i]);
                sort_or_not = false;
            }
        }
        right--;
        for (int i = right; i >= left; i--) {
            if (sh[i] < sh[i - 1]) {
                swap(sh[i], sh[i - 1]);
                sort_or_not = false;
            }
        }
        left++;
    } while (sort_or_not == false);
    auto end_time = chrono::high_resolution_clock::now();
   
    
    auto result = chrono::duration_cast<chrono::microseconds>(end_time - start_time);
    cout << "Отсортированный массив в порядке возрастания: " << endl;
    for (int i = 0; i < N; i++) {
        cout << "[" << sh[i] << "]" << " ";
    }
    cout << endl;
    cout << "Время сортировки: " << result.count() << " микросекунд" << endl;
}
//1.3
int getNextGap(int gap)
{
    gap = (gap * 10) / 13;
    if (gap < 1)
        return 1;
    return gap;
}
void comb_sort(int cm[]) {
    
    int gap = N;
    bool swapped = true;
    auto start_time = chrono::high_resolution_clock::now();
    while (gap != 1 || swapped == true)
    {
        gap = getNextGap(gap);
        swapped = false;
        for (int i = 0; i < N - gap; i++)
        {
            if (cm[i] > cm[i + gap])
            {
                swap(cm[i], cm[i + gap]);
                swapped = true;
            }
        }
    }
    auto end_time = chrono::high_resolution_clock::now();

    auto result = chrono::duration_cast<chrono::microseconds>(end_time - start_time);
    cout << "Отсортированный массив в порядке возрастания: " << endl;
    for (int i = 0; i < N; i++) {
        cout << "[" << cm[i] << "]" << " ";
    }
    cout << endl;
    cout << "Время сортировки: " << result.count() << " микросекунд" << endl;
}
//1.4
void insert_sort(int is[]) {
    
    int i, key, j;
    auto start_time = chrono::high_resolution_clock::now();
    for (i = 1; i < N; i++) {
        key = is[i];
        j = i - 1;
        
        while (j >= 0 && is[j] > key) {
            is[j + 1] = is[j];
            j = j - 1;
        }
        is[j + 1] = key;
    }
    auto end_time = chrono::high_resolution_clock::now();
    auto result = chrono::duration_cast<chrono::microseconds>(end_time - start_time);
    cout << "Отсортированный массив в порядке возрастания: " << endl;
    for (int i = 0; i < N; i++) {
        cout << "[" << is[i] << "]" << " ";
    }
    cout << endl;
    cout << "Время сортировки: " << result.count() << " микросекунд" << endl;
}
//1.5
int part(int gu[], int start, int end)
{
    int pivot = gu[start];
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (gu[i] <= pivot)
            count++;
    }
    int pivotIndex = start + count;
    swap(gu[pivotIndex], gu[start]);
    int i = start, j = end;
    while (i < pivotIndex && j > pivotIndex) {
        while (gu[i] <= pivot) {
            i++;
        }
        while (gu[j] > pivot) {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex) {
            swap(gu[i++], gu[j--]);
        }
    }
    return pivotIndex;
}

void quickSort(int arr1[], int start, int end)
{
    srand(time(0));
    if (start >= end)
        return;
    int p = part(arr1, start, end);
    quickSort(arr1, start, p - 1);
    quickSort(arr1, p + 1, end);
}


//idz
void idz(int sh[]) {
    cout << "Сортировка Шелла" << endl;

    auto start_time = chrono::high_resolution_clock::now();
    for (int gap = N / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < N; i += 1) {
            int temp = sh[i];
            int j;
            for (j = i; j >= gap && sh[j - gap] > temp; j -= gap)
                sh[j] = sh[j - gap];
            sh[j] = temp;
        }
    }
    auto end_time = chrono::high_resolution_clock::now();
    auto result = chrono::duration_cast<chrono::microseconds>(end_time - start_time);
    cout << "Отсортированный массив в порядке возрастания: " << endl;
    for (int i = 0; i < N; i++) {
        cout << "[" << sh[i] << "]" << " ";
    }
    cout << endl;
    cout << "Время сортировки: " << result.count() << " микросекунд" << endl;
}


//2
void sort_m() {
    cout << "Варианты сортировок: " << endl;
    cout << "1.Bubble sort (пузырьковая сортировка)" << endl;
    cout << "2.Shaker sort (шейкер-сортировка)" << endl;
    cout << "3.Comb sort (сортировка расчёской)" << endl;
    cout << "4.Insert sort (сортировка вставками)" << endl;
    cout << "5.Quick sort (быстрая сортировка)" << endl;
}
void sort(int a[]) {
    cout << "Отсортировать заданный в пункте 1 массив сортировкой (от меньшего к большему). Определить время, затраченное на сортировку, используя библиотеку chrono." << endl;
    sort_m();
    int b;
    cout << "Выберите номер сортировки" << endl;
    cin >> b;
    switch (b) {
    case 1:
        bubble_sort(a);
        break;
    case 2:
        shaker_sort(a);
        break;
    case 3:
        comb_sort(a);
        break;
    case 4:
        insert_sort(a);
        break;
    case 5:
        auto start_time = chrono::high_resolution_clock::now();
        quickSort(a, 0, N - 1);
        cout << "Отсортированный массив в порядке возрастания: " << endl;
        for (int i = 0; i < N; i++) {
            cout << "[" << a[i] << "]" << " ";
        }
        auto end_time = chrono::high_resolution_clock::now();
        auto result = chrono::duration_cast<chrono::microseconds>(end_time - start_time);
        cout << endl;
        cout << "Время сортировки: " << result.count() << " микросекунд" << endl;
        break;
    }
}
//3
void max1(int arr[], int sort_arr[]) {
    
    int min, max;
    max = arr[0];
    min = arr[0];
    auto start_time1 = chrono::high_resolution_clock::now();
    for (int i = 1; i < N; i++)
    {
        if (max < arr[i]) max = arr[i];
        if (min > arr[i]) min = arr[i];
    }
    auto end_time1 = chrono::high_resolution_clock::now();

    auto start_time = chrono::high_resolution_clock::now();
    bubble_sort(sort_arr);
    int minik, maxik;
    minik = sort_arr[0],
    maxik = sort_arr[99];
    cout << "Минимальный элемент массива: " << minik << endl;
    cout << "Максимальный элемент массива: " << maxik << endl;
    auto end_time = chrono::high_resolution_clock::now();
    auto result = chrono::duration_cast<chrono::microseconds>(end_time1 - start_time1);

    cout << "Поиск в неотсортированном массиве: " << result.count() << " микросекунд" << endl;
    auto result1 = chrono::duration_cast<chrono::microseconds>(end_time - start_time);
    cout << "Поиск в отсортированном массиве: " << result1.count() << " микросекунд" << endl;
}
//4
void sr_zn(int arr[])
{
    
    for (int i = 0; i < N; i++)
    {
        int start = -99;
        int end = 99;
        arr[i] = rand() % (end - start + 1) + start;
        
    }
    for (int i = 0; i < N; i++) {
        cout << "[" << arr[i] << "]" << " ";

    }
    cout << endl;
    int b = (arr[0] + arr[N - 1]) / 2;
    cout << "Среднее значение максимального и минимального значения в неотсортированном массиве:" << endl;
    cout << b << endl;

    bubble_sort(arr);

    int a = (arr[0] + arr[N - 1]) / 2;
    cout << "Среднее значение максимального и минимального значения в отсортированном массиве:" << endl;
    cout << a << endl;

    int i = N - 1;
    while (arr[i] > a) {
        i /= 2;
    }
    int k = 0;
    cout << "Индексы всех элементов, которые равны этому значению: " << endl;
    auto start_time = chrono::high_resolution_clock::now();
    for (int i = 0; i < N; i++) {
        if (arr[i] == a) {
            cout << i << " ";
            k++;
        }
    }
   
    auto end_time = chrono::high_resolution_clock::now();
    auto result = chrono::duration_cast<chrono::microseconds>(end_time - start_time);
    if (k == 0) cout << "Значения не найдены" << endl;
    cout << "Количество элементов: " << k << endl;
    cout << "Время поиска: " << result.count() << " микросекунд" << endl;
}
//5
void mense(int arr[]) {
    bubble_sort(arr);
    int a;
    cout << "Введите число а:" << endl;
    cin >> a;
    int count = 0;
    
    for (int i = 0; i < N; i++) {
        if (arr[i] < a) {
            count++;
        }
    }
    cout << "Количество элементов меньше " << a << ": " << count << endl;
}
//6
void bolse(int arr[]) {
    bubble_sort(arr);
    int b;
    cout << "Введите число b:" << endl;
    cin >> b;
    int count = 0;
    for (int i = 0; i < N; ++i) {
        if (arr[i] > b) {
            ++count;
        }
    }
    cout << "Количество элементов больше " << b << ": " << count << endl;
}
//7
int Search_Binary(int arr[], int left, int right, int key)
{
    int midd = 0;
    while (1)
    {
        midd = (left + right) / 2;

        if (key < arr[midd])       
            right = midd - 1;      
        else if (key > arr[midd])  
            left = midd + 1;    
        else                      
            return midd;           

        if (left > right)          
            return -1;
    }
}
void poisk(int arr[])
{
    bubble_sort(arr);
    
    setlocale(LC_ALL, "rus");
    const int SIZE = N;
    int array[SIZE] = {};
    int key;
    int index = 0; 

    cout << "\n\nВведите любое число: ";
    cin >> key;
    
    index = Search_Binary(arr, 0, SIZE, key);
    
    if (index >= 0)
        cout << "Указанное число находится в ячейке с индексом: " << index << endl;
    else
        cout << "В массиве нет такого числа!";
    cout << endl;
}

//8
void mesta(int arr[]) {

    bubble_sort(arr);
    cout << "Введите индексы элементов для обмена: " << endl;
    int i1, i2;
    cin >> i1 >> i2;
    int temp = arr[i1];
    arr[i1] = arr[i2];
    arr[i2] = temp;
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < N; i++) {
        temp = arr[i1];
        arr[i1] = arr[i2];
        arr[i2] = temp;
    }
    auto end = chrono::high_resolution_clock::now();
    auto result = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Скорость обмена: " << 100000.0 / result.count() << " обменов в секунду" << endl;
    cout << "Отсортированный массив: " << endl;
    for (int i = 0; i < N; i++) {
        cout << "[" << arr[i] << "]" << " ";
    }
    cout << endl;
}

int main() {
    setlocale(0, "");
    int choice;
    bool p = true;
    int arr[N], sort_arr[N];
    main1(arr, sort_arr);
    while (p) {
        zadania(N);
        cout << "Выберите номер задания:" << endl;
        cin >> choice;
        system("cls");
        switch (choice) {
        case 1:
            main1(arr, sort_arr);
            for (int i = 0; i < N; i++) {
                cout << "[" << arr[i] << "]" << " ";
            }
            break;
        case 2:
            sort(sort_arr);
            break;
        case 3:
            max1(arr, sort_arr);
            break;
        case 4:
            sr_zn(arr);
            break;
        case 5:
            mense(arr);
            break;
        case 6:
            bolse(arr);
            break;
        case 7:
            poisk(arr);
            break;
        case 8:
            mesta(arr);
            break;
        case 9:
            idz(arr);
            break;
        }
        for (int i = 0; i < N; i++) {
            sort_arr[i] = arr[i];
        }
        system("pause");
        system("cls");
    }
}