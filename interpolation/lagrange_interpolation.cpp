// lagrange_interpolation.cpp
// 功能：实现拉格朗日插值法，根据已知离散点计算任意x对应的插值结果
#include <iostream>
#include <vector>
#include <iomanip> // 格式化输出

// 拉格朗日基函数计算
// 参数：x_i: 已知点的x坐标数组, i: 基函数索引, x: 待插值的x值
double lagrangeBasis(const std::vector<double>& x_i, int i, double x) {
    double basis = 1.0;
    int n = x_i.size();
    for (int j = 0; j < n; ++j) {
        if (j != i) { // 跳过当前索引i
            basis *= (x - x_i[j]) / (x_i[i] - x_i[j]);
        }
    }
    return basis;
}

// 拉格朗日插值核心函数
// 参数：x_i: 已知点x坐标, y_i: 已知点y坐标, x: 待插值的x值
double lagrangeInterpolation(const std::vector<double>& x_i, 
                             const std::vector<double>& y_i, 
                             double x) {
    // 检查输入合法性：x和y数组长度必须一致
    if (x_i.size() != y_i.size() || x_i.empty()) {
        std::cerr << "错误：已知点的x和y坐标数量不匹配，或为空！" << std::endl;
        return 0.0;
    }

    double result = 0.0;
    int n = x_i.size();
    // 拉格朗日插值公式：L(x) = Σ(y_i * l_i(x))
    for (int i = 0; i < n; ++i) {
        result += y_i[i] * lagrangeBasis(x_i, i, x);
    }
    return result;
}

int main() {
    std::cout << "===== 拉格朗日插值法计算程序 =====" << std::endl;
    
    // 1. 输入已知离散点数量
    int n;
    std::cout << "请输入已知离散点的数量：";
    std::cin >> n;
    if (n < 2) { // 至少需要2个点才能插值
        std::cerr << "错误：已知点数量至少为2！" << std::endl;
        return 1;
    }

    // 2. 输入已知点的x和y坐标
    std::vector<double> x_i(n), y_i(n);
    std::cout << "请依次输入" << n << "个已知点的x和y坐标（格式：x y，每行一个）：" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << "第" << i+1 << "个点：";
        std::cin >> x_i[i] >> y_i[i];
    }

    // 3. 输入待插值的x值
    double x;
    std::cout << "\n请输入需要插值的x值：";
    std::cin >> x;

    // 4. 计算插值结果
    double y = lagrangeInterpolation(x_i, y_i, x);

    // 5. 格式化输出结果
    std::cout << "\n===== 插值结果 =====" << std::endl;
    std::cout << "已知离散点：" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << "(" << x_i[i] << ", " << y_i[i] << ")" << std::endl;
    }
    std::cout << "待插值x值：" << x << std::endl;
    std::cout << "插值结果y值：" << std::fixed << std::setprecision(4) << y << std::endl;

    return 0;
}