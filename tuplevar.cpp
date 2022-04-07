#include <utility>
#include <tuple>
#include <iostream>
#include <array>
#include <utility>
 
// 调试辅助
template <typename Tuple, typename Func, size_t ... N>
void func_call_tuple(const Tuple& t, Func&& func, std::index_sequence<N...>) {
    std::initializer_list<int>{(func(std::get<N>(t)), 0)...};
}

template <typename ... Args, typename Func>
void travel_tuple(const std::tuple<Args...>& t, Func&& func) {
    func_call_tuple(t, std::forward<Func>(func), std::make_index_sequence<sizeof...(Args)>{});
}

int main() {
    auto t = std::make_tuple(1, 4.56, "happen lee");
    travel_tuple(t, [](auto&& item) {
        std::cout << item << ",";
    });
    std::cout << std::endl;
}