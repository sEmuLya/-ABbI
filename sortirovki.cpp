#include <iostream>
#include <iomanip>
#include <chrono>
#include <string>
typedef std::chrono::high_resolution_clock Time;
typedef std::chrono::microseconds ms;
typedef std::chrono::duration <float> fsec;
using namespace std;

int Hcmps = 0;
int const n = 200;
int const N = 200;
int Hswps = 0;
int Qcmps = 0;
int Qswps = 0;

void print(string text, int swps, int cmps, double ms) {
	int text_len = 28, num_len = 7;
	cout << text;
	for (int i = text.length(); i < text_len; i++) {
		cout << " ";
	}
	cout << "| " << swps;
	for (int i = to_string(swps).length(); i < num_len; i++) {
		cout << " ";
	}
	cout << "| " << cmps;
	for (int i = to_string(cmps).length(); i < num_len; i++) {
		cout << " ";
	}
	cout << "| " << to_string(ms).substr(0, 6) << " ms |" << endl;
}

int SelectionSort(int mass[], int n) {
	auto t0 = Time::now();
	int mass1[N] = { 0 };
	memcpy(mass1, mass, sizeof(int) * N);
	int index, swps1, cmps1;
	swps1 = 0;
	cmps1 = 0;
	for (int i = 0; i < n; i++) {
		index = i;
		for (int j = i + 1; j < n; j++) {
			cmps1++;
			if (mass1[j] < mass1[index]) {

				index = j;
			}

		}
		if (index != i) {
			swap(mass1[i], mass1[index]);
			swps1++;
		}
	}
	auto t1 = Time::now();
	fsec t_ms = t1 - t0;
	ms d = std::chrono::duration_cast<ms>(t_ms);
	//cout << "Сортировка простым выбором  |" << swps1 << "\t" << cmps1 << "\t" << t_ms.count() * 1000 << " ms" << endl;
	print("Сортировка простым выбором", swps1, cmps1, t_ms.count() * 1000);
	return 0;

}
int InsertionSort(int mass[], int n) {
	auto t0 = Time::now();
	int mass1[N] = { 0 };
	memcpy(mass1, mass, sizeof(int) * n);
	int temp, i, j, swps2, cmps2;
	swps2 = 0;
	cmps2 = 0;
	for (int i = 1; i < n; i++) {
		j = i;
		temp = mass1[i];
		while (j > 0 && temp < mass1[j - 1]) {
			swps2++;
			mass1[j] = mass1[j - 1];
			j--;
			cmps2++;
		}
		cmps2++;

		if (j != i) {
			mass1[j] = temp;
		}
	}
	auto t1 = Time::now();
	fsec t_ms = t1 - t0;
	ms d = std::chrono::duration_cast<ms>(t_ms);
	//cout << "Сортировка простой вставкой |" << swps2 << "\t        |" << cmps2 << "\t" << t_ms.count() * 1000 << " ms" << endl;
	print("Сортировка простой вставкой", swps2, cmps2, t_ms.count() * 1000);
	return 0;
}
int BubbleSort(int mass[], int n) {
	auto t0 = Time::now();
	int mass1[N] = { 0 };
	memcpy(mass1, mass, sizeof(int) * N);
	int i, j, swps3, cmps3;
	swps3 = 0;
	cmps3 = 0;
	for (i = 0; i < n - 1; i++) {
		cmps3++;
		for (j = n - 1; j > i; j--) {
			cmps3++;
			if (mass1[j - 1] > mass1[j]) {
				swap(mass1[j - 1], mass1[j]);
				swps3++;
			}
		}
	}
	auto t1 = Time::now();
	fsec t_ms = t1 - t0;
	ms d = std::chrono::duration_cast<ms>(t_ms);
	//cout << "Сортировка пузырьком        |" << swps3 << "\t" << cmps3 << "\t" << t_ms.count() * 1000 << " ms" << endl;
	print("Сортировка пузырьком", swps3, cmps3, t_ms.count() * 1000);
	return 0;
}
int BinarySort(int mass[], int n) {
	auto t0 = Time::now();
	int mass1[N] = { 0 };
	memcpy(mass1, mass, sizeof(int) * N);
	int x, left, right, sred;
	int cmps4 = 0;
	int cmpsS4 = 0;
	int swps4 = 0;
	for (int i = 1; i < n; i++) {
		cmpsS4++;
		if (mass1[i - 1] > mass1[i]) {
			cmps4++;
			x = mass1[i];
			left = 0;
			right = i - 1;
			do {
				sred = (left + right) / 2;
				if (mass1[sred] < x) {
					left = sred + 1;
					cmps4++;
				}
				else {
					right = sred - 1;
					cmps4++;
				}

			} while (left <= right);
			for (int j = i - 1; j >= left; j--) {
				swps4++;
				mass1[j + 1] = mass1[j];
			}
			mass1[left] = x;
		}
	}
	cmps4 = abs(cmps4 - cmpsS4);
	auto t1 = Time::now();
	fsec t_ms = t1 - t0;
	ms d = std::chrono::duration_cast<ms>(t_ms);
	//cout << "Бинарная сортировка         |" << "\t" << swps4 << "\t" << cmps4 << "\t" << t_ms.count() * 1000 << " ms" << endl;
	print("Бинарная сортировка", swps4, cmps4, t_ms.count() * 1000);
	return 0;
}
int shaker(int mass[], int n) {
	auto t0 = Time::now();
	int mass1[N] = { 0 };
	memcpy(mass1, mass, sizeof(int) * N);
	int swps = 0, cons = 0, lpt = 0, rpt = n - 1;
	int j, i;
	while (lpt != rpt) {
		int j = lpt;
		for (int i = lpt; i < rpt; i++) {
			cons++;
			if (mass1[i] > mass1[i + 1]) {
				swap(mass1[i], mass1[i + 1]);
				swps++;
				j = i;
			}
		}
		rpt = j;
		for (int i = rpt; i > lpt; i--) {
			cons++;
			if (mass1[i - 1] > mass1[i]) {
				swap(mass1[i - 1], mass1[i]);
				swps++;
				j = i;
			}
		}
		lpt = j;
	}
	auto t1 = Time::now();
	fsec t_ms = t1 - t0;
	ms d = std::chrono::duration_cast<ms>(t_ms);
	//cout << "Шейкер сортировка           |" << "\t" << swps << "\t" << cons << "\t" << t_ms.count() * 1000 << " ms" << endl;
	print("Шейкер сортировка", swps, cons, t_ms.count() * 1000);
	return 0;
}
int ShellSort(int mass[], int n) {
	auto t0 = Time::now();
	int mass1[N] = { 0 };
	memcpy(mass1, mass, sizeof(int) * N);
	int temp, swps6, cmps6, j, i, k;
	swps6 = 0;
	cmps6 = 0;
	int h = 0;
	while (h <= n / 3)
		h = 3 * h + 1;
	for (k = h; k > 0; k = (k - 1) / 3)
		for (i = k; i < n; i++) {
			temp = mass1[i];
			for (j = i; j >= k; j -= k) {
				cmps6++;
				if (temp < mass1[j - k]) {
					mass1[j] = mass1[j - k];
					swps6++;
				}
				else
					break;
			}
			mass1[j] = temp;
		}
	auto t1 = Time::now();
	fsec t_ms = t1 - t0;
	ms d = std::chrono::duration_cast<ms>(t_ms);
	//cout << "Сортировка Шелла            |" << swps6 << "\t" << cmps6 << "\t" << t_ms.count() * 1000 << " ms" << endl;
	print("Сортировка Шелла", swps6, cmps6, t_ms.count() * 1000);
	return 0;
}

void sift(int numbers[], int root, int bottom) {
	int maxChild;
	int done = 0;
	while ((root * 2 <= bottom) && (!done)) {
		Hcmps++;
		if (root * 2 == bottom) {
			maxChild = root * 2;

		}
		else if (numbers[root * 2] > numbers[root * 2 + 1]) {
			maxChild = root * 2;
		}
		else {
			maxChild = root * 2 + 1;
		}
		if (numbers[root] < numbers[maxChild]) {
			swap(numbers[root], numbers[maxChild]);
			root = maxChild;
			Hswps++;
		}
		else
			done = 1;
	}
}
void heapsort(int mass[], int n) {
	int numbers[200] = { 0 };
	memcpy(numbers, mass, sizeof(int) * 200);
	for (int i = (n / 2); i >= 0; i--) {
		Hcmps--;
		Hswps--;
		sift(numbers, i, n - 1);
	}
	for (int i = n - 1; i >= 1; i--) {
		swap(numbers[0], numbers[i]);
		sift(numbers, 0, i - 1);
	}
}

void quicksort(int numbers[], int left, int right) {
	int pivot;
	int l_hold = left;
	int r_hold = right;
	pivot = numbers[left];
	while (left < right) {
		while ((numbers[right] >= pivot) && (left < right)) {
			right--;
			Qcmps++;
		}
		if (left != right) {
			numbers[left] = numbers[right];
			left++;
			Qswps++;
		}
		while ((numbers[left] <= pivot) && (left < right)) {
			left++;
			Qcmps++;
		}
		if (left != right) {
			numbers[right] = numbers[left];
			right--;
			Qswps++;
		}
	}
	numbers[left] = pivot;
	pivot = left;
	left = l_hold;
	right = r_hold;
	if (left < pivot)
		quicksort(numbers, left, pivot - 1);
	if (right > pivot)
		quicksort(numbers, pivot + 1, right);
}

int main() {
	int mA = 2;
	int proba1[4] = { 1,2,3,4 };
	int proba2[4] = { 4,3,2,1 };
	setlocale(LC_ALL, "RUS");
	int i, j, swps, cmps;
	int A[n], B[n], C[n];
	int first;
	int last;
	for (int i = 0; i < n; i++) {
		A[i] = i + 1;
	}
	for (int i = 0; i < n; i++) {
		B[i] = n - i;
	}
	for (int i = 0; i < n; i++) {
		C[i] = rand() % 100 - 50;
	}
	cout << "Сортировка" << "\t            | Обмены:" << "| Сравн: " << "| Время:    |" << endl;
	InsertionSort(A, n);
	InsertionSort(B, n);
	InsertionSort(C, n);
	SelectionSort(A, n);
	SelectionSort(B, n);
	SelectionSort(C, n);
	BubbleSort(A, n);
	BubbleSort(B, n);
	BubbleSort(C, n);
	BinarySort(A, n);
	BinarySort(B, n);
	BinarySort(C, n);
	shaker(A, n);
	shaker(B, n);
	shaker(C, n);
	ShellSort(A, n);
	ShellSort(B, n);
	ShellSort(C, n);

	auto t0 = Time::now();
	heapsort(A, n);
	auto t1 = Time::now();
	fsec t_ms0 = t1 - t0;
	ms d0 = std::chrono::duration_cast<ms>(t_ms0);
	//cout << "Пирамидальная сортировка    |" << Hswps << "\t" << Hcmps << "\t" << t_ms0.count() * 1000 << " ms" << endl;
	print("Пирамидальная сортировка", Hswps, Hcmps, t_ms0.count() * 1000);
	Hcmps = 0;
	Hswps = 0;

	auto t2 = Time::now();
	heapsort(B, n);
	auto t3 = Time::now();
	fsec t_ms1 = t1 - t0;
	ms d1 = std::chrono::duration_cast<ms>(t_ms1);
	//cout << "Пирамидальная сортировка    |" << Hswps << "\t" << Hcmps << "\t" << t_ms1.count() * 1000 << " ms" << endl;
	print("Пирамидальная сортировка", Hswps, Hcmps, t_ms1.count() * 1000);
	Hcmps = 0;
	Hswps = 0;

	auto t4 = Time::now();
	heapsort(C, n);
	auto t5 = Time::now();
	fsec t_ms2 = t1 - t0;
	ms d2 = std::chrono::duration_cast<ms>(t_ms2);
	//cout << "Пирамидальная сортировка    |" << Hswps << "\t" << Hcmps << "\t" << t_ms2.count() * 1000 << " ms" << endl;
	print("Пирамидальная сортировка", Hswps, Hcmps, t_ms2.count() * 1000);

	int mass1[N] = { 0 };
	memcpy(mass1, A, sizeof(int) * N);
	int mass2[N] = { 0 };
	memcpy(mass2, B, sizeof(int) * N);
	int mass3[N] = { 0 };
	memcpy(mass3, C, sizeof(int) * N);
	first = 0;
	last = n - 1;

	auto t6 = Time::now();
	quicksort(mass1, first, last);
	auto t7 = Time::now();
	fsec t_ms3 = t1 - t0;
	ms d3 = std::chrono::duration_cast<ms>(t_ms3);
	//cout << "Быстрая сортировка          |" << Qswps << "\t" << Qcmps << "\t" << t_ms3.count() * 1000 << " ms" << endl;
	print("Быстрая сортировка", Qswps, Qcmps, t_ms3.count() * 1000);
	Qcmps = 0;
	Qswps = 0;
	first = 0;
	last = n - 1;

	auto t8 = Time::now();
	quicksort(mass2, first, last);
	auto t9 = Time::now();
	fsec t_ms4 = t1 - t0;
	ms d4 = std::chrono::duration_cast<ms>(t_ms4);
	//cout << "Быстрая сортировка          |" << Qswps << "\t" << Qcmps << "\t" << t_ms4.count() * 1000 << " ms" << endl;
	print("Быстрая сортировка", Qswps, Qcmps, t_ms4.count() * 1000);
	first = 0;
	last = n - 1;
	Qcmps = 0;
	Qswps = 0;

	auto t10 = Time::now();
	quicksort(mass3, first, last);
	auto t11 = Time::now();
	fsec t_ms5 = t1 - t0;
	ms d5 = std::chrono::duration_cast<ms>(t_ms5);
	//cout << "Быстрая сортировка          |" << Qswps << "\t" << Qcmps << "\t" << t_ms5.count() * 1000 << " ms" << endl;
	print("Быстрая сортировка", Qswps, Qcmps, t_ms5.count() * 1000);
}