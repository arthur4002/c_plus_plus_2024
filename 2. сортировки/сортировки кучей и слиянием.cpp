#include <iostream>

//вспомогательная функция для просеивания элемента вниз в куче
void heapify(int* arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

//сортировка кучей
void heapSort(int* arr, int n) {
    //построение максимальной кучи
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    //извлечение элементов из кучи по одному
    for (int i = n - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

//вспомогательная функция для слияния двух отсортированных подмассивов
void merge(int* arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

//рекурсивная функция сортировки слиянием
void mergeSortRecursive(int* arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSortRecursive(arr, left, mid);
        mergeSortRecursive(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

//функция сортировки, которая будет вызываться извне
void my_sort(int n, int* array) {

    //heapSort(array, n);
    mergeSortRecursive(array, 0, n - 1);
}

//функция для вывода массива
void printArray(int* arr, int n) {
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}


int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Исходный массив: ";
    printArray(arr, n);

    my_sort(n, arr);

    std::cout << "Отсортированный массив: ";
    printArray(arr, n);

    return 0;
} 
