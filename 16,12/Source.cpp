//1
/*#include <iostream>
#include <vector>

using namespace std;

int sumDigits(const vector<int>& arr) 
{
    int sum = 0;
    for (int num : arr) 
    {
        while (num != 0) 
        {
            sum += num % 10;
            num /= 10;
        }
    }
    return sum;
}

int main() 
{
    vector<int> arr = { 12, 104, 81 };
    cout << "Сумма цифр массива: " << sumDigits(arr) << endl;
    return 0;
}*/

//2
/*#include <iostream>
#include <vector>

using namespace std;

double averagePositive(const vector<int>& arr) 
{
    double sum = 0;
    int count = 0;
    for (int num : arr)
    {
        if (num > 0) 
        {
            sum += num;
            count++;
        }
    }
    return count > 0 ? sum / count : 0;
}

int main() 
{
    vector<int> arr = {12, -104, 81, 0, 23};
    cout << "Среднее арифметическое положительных элементов: " << averagePositive(arr) << endl;
    return 0;
}
*/

//3
/*#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

void maxNegativeElement(const vector<int>& arr) 
{
    int maxNegative = INT_MIN;
    int position = -1;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < 0 && arr[i] > maxNegative) 
        {
            maxNegative = arr[i];
            position = i;
        }
    }
    if (position != -1) 
    {
        cout << "Максимальный отрицательный элемент: " << maxNegative << ", Позиция: " << position << endl;
    } 
    else
    {
        cout << "Отрицательные элементы отсутствуют" << endl;
    }
}

int main() 
{
    vector<int> arr = {12, -104, 81, -23, 0};
    maxNegativeElement(arr);
    return 0;
}
*/

//4
/*#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int mostFrequentElement(const vector<int>& arr)
{
    unordered_map<int, int> frequency;
    for (int num : arr) 
    {
        frequency[num]++;
    }

    int maxCount = 0;
    int mostFrequent = arr[0];
    for (const auto& pair : frequency) 
    {
        if (pair.second > maxCount)
        {
            maxCount = pair.second;
            mostFrequent = pair.first;
        }
    }
    return mostFrequent;
}

int main() 
{
    vector<int> arr = {12, 104, 81, 12, 23, 12};
    cout << "Число, чаще всего встречающееся в массиве: " << mostFrequentElement(arr) << endl;
    return 0;
}
*/

//5
/*#include <iostream>
#include <vector>

using namespace std;

int maxOddIndexDivByThree(const vector<int>& arr)
{
    int maxElement = INT_MIN;
    for (int i = 1; i < arr.size(); i += 2) 
    {
        if (arr[i] % 3 == 0 && arr[i] > maxElement) 
        {
            maxElement = arr[i];
        }
    }
    return maxElement == INT_MIN ? -1 : maxElement;
}

int main() 
{
    vector<int> arr = {12, 9, 81, 15, 23, 27};
    cout << "Наибольший элемент среди элементов с нечетными номерами, который делится на 3: " << maxOddIndexDivByThree(arr) << endl;
    return 0;
}
*/

//6
/*#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void swapMaxEvenMinOdd(vector<int>& arr) 
{
    int maxEven = INT_MIN, maxEvenIndex = -1;
    int minOdd = INT_MAX, minOddIndex = -1;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] % 2 == 0 && arr[i] > maxEven)
        {
            maxEven = arr[i];
            maxEvenIndex = i;
        }
        if (arr[i] % 2 != 0 && arr[i] < minOdd)
        {
            minOdd = arr[i];
            minOddIndex = i;
        }
    }

    if (maxEvenIndex != -1 && minOddIndex != -1) 
    {
        swap(arr[maxEvenIndex], arr[minOddIndex]);
    }
    else 
    {
        fill(arr.begin(), arr.end(), 0);
    }
}

int main()
{
    vector<int> arr = {12, 104, 81, 23, 0, 7};
    swapMaxEvenMinOdd(arr);
    cout << "Массив после замены: ";
    for (int num : arr) 
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
*/

//7
/*#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> elementsInBoth(const vector<int>& arr1, const vector<int>& arr2) 
{
    unordered_set<int> set1(arr1.begin(), arr1.end());
    unordered_set<int> result;
    for (int num : arr2)
    {
        if (set1.find(num) != set1.end())
        {
            result.insert(num);
        }
    }
    return vector<int>(result.begin(), result.end());
}

vector<int> elementsInOne(const vector<int>& arr1, const vector<int>& arr2) 
{
    unordered_set<int> set1(arr1.begin(), arr1.end());
    unordered_set<int> set2(arr2.begin(), arr2.end());
    vector<int> result;

    for (int num : arr1) 
    {
        if (set2.find(num) == set2.end()) 
        {
            result.push_back(num);
        }
    }
    for (int num : arr2) 
    {
        if (set1.find(num) == set1.end()) 
        {
            result.push_back(num);
        }
    }
    return result;
}

int main()
{
    vector<int> arr1 = {12, 104, 81, 23};
    vector<int> arr2 = {81, 23, 45, 67};

    vector<int> both = elementsInBoth(arr1, arr2);
    vector<int> one = elementsInOne(arr1, arr2);

    cout << "Элементы, присутствующие в обоих массивах: ";
    for (int num : both) 
    {
        cout << num << " ";
    }
    cout << endl;

    cout << "Элементы, присутствующие только в одном из массивов: ";
    for (int num : one)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
*/