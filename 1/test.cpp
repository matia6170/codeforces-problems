#include <iostream>

int main() {
    int Ta, Ts;  // Number of items to add and subtract
    while (std::cin >> Ta >> Ts ) {
        if (Ta == 0 && Ts == 0 || (Ta == EOF || Ts == EOF)) {
            break;  // Exit when both Ta and Ts are zero
        }

        int sum_add = 0;
        for (int i = 0; i < Ta; ++i) {
            int a;
            std::cin >> a;
            sum_add += a;
        }

        int sum_subtract = 0;
        for (int i = 0; i < Ts; ++i) {
            int b;
            std::cin >> b;
            sum_subtract += b;
        }

        int result = sum_add - sum_subtract;
        std::cout << result << std::endl;
    }
}