#include <iostream>
using namespace std;

double average(int* arr, int n);
int min(const int a[], int left, int  right);
int max(const int a[], int left, int  right);

int main() {
	int n = 0;
	cout << " Vvedit rozmir masiva "; cin >> n;
	int* Arr = new int[n];



	for (int i = 0; i <= n - 1; i++)
	{
		cout << " Vvedit " << i << " Element masiva : ";
		cin >> Arr[i];
	}
	
	cout << "Average sum = " << average(Arr,n) << endl;
	cout << "Min = " << min(Arr,0,n-1) << endl;
	cout << "Max = " << max(Arr, 0, n - 1) << endl;
	return 0;
}

double average(int* arr, int n) {
	if (n == 1)
		return arr[n - 1];
	return ((n - 1) * average(arr, n - 1) + arr[n - 1]) / n;
}
int min(const int a[], int left, int  right)
{
	int x, y, m, center;
	// Точка повернення з рекурсії
	if (left == right) return a[left];
	// Обходимо проблему "биття" рекурсії
	if ((left - right) == 1 || (right - left) == 1)
	{
		return a[left] < a[right] ? a[left] : a[right];
	}
	// Вичисляємо середину
	m = (left + right) / 2;

	// Мінімум зліва і справа від середини
	x = min(a, left, m);
	y = min(a, m, right);

	// Вибираємо мінінімальний з результатів
	if (x < y) return x;
	else return y;
}
int max(const int a[], int left, int  right)
{
	int x, y, m, center;
	if (left == right) return a[left];
	if ((left - right) == 1 || (right - left) == 1)
	{
		return a[left] > a[right] ? a[left] : a[right];
	}
	m = (left + right) / 2;

	x = max(a, left, m);
	y = max(a, m, right);

	if (x > y) return x;
	else return y;
}
