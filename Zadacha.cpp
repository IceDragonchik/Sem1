1 задание
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> containers(n);

    // Считываем объемы концентрата
    for (int i = 0; i < n; ++i) {
        cin >> containers[i];
    }

    // Находим общее количество концентрата
    long long total = accumulate(containers.begin(), containers.end(), 0LL);

    // Проверяем, делится ли общее количество концентрата на количество чаном
    if (total % n != 0) {
        cout << -1 << endl;
        return 0;
    }

    long long target = total / n; // Идеальный уровень концентрата в каждом чанe
    long long operations = 0;

    // Считаем количество операций
    for (int i = 0; i < n - 1; ++i) {
        if (containers[i] < target) {
            // Если текущий чан нуждается в добавлении концентрата
            operations += (target - containers[i]);
            containers[i + 1] += (target - containers[i]);
        }
    }

    // Проверяем, достигли ли мы целевого уровня в последнем чанe
    if (containers[n - 1] != target) {
        cout << -1 << endl;
    }
    else {
        cout << operations << endl;
    }

    return 0;
}
