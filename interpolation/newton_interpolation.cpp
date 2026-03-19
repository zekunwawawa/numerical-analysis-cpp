// newton_interpolation.cpp
// 功能：实现牛顿插值法，支持任意数量离散点的插值计算，输出差商表和插值结果
#include <iostream>
#include <vector>
#include <iomanip>

// 计算差商表（核心：牛顿插值的关键）
// 参数：x_i: 已知点x坐标, y_i: 已知点y坐标, F: 存储差商的二维数组（输出）
void calculateDividedDifference(const std::vector<double>& x_i, 
                                const std::vector<double>& y_i,
                                std::vector<std::vector<double>>& F) {
    int n = x_i.size();
    // 初始化差商表：第一列是y_i（零阶差商）
    F.resize(n, std::vector<double>(n, 0.0));
    for (int i = 0; i < n; ++i) {
        F[i][0] = y_i[i];
    }

    // 计算各阶差商：F[i][j] 表示 j阶差商，对应点x_i, x_{i+1}, ..., x_{i+j}
    for (int j = 1; j < n; ++j) { // j: 差商阶数（1阶到n-1阶）
        for (int i = 0; i < n - j; ++i) { // i: 差商起始点
            F[i][j] = (F[i+1][j-1] - F[i][j-1]) / (x_i[i+j] - x_i[i]);
        }
    }
}

// 牛顿插值核心计算
// 参数：x_i: 已知点x坐标, F: 差商表, x: 待插值的x值
double newtonInterpolation(const std::vector<double>& x_i, 
                           const std::vector<std::vector<double>>& F, 
                           double x) {
    int n = x_i.size();
    double result = F[0][0]; // 初始值：零阶差商F[0][0]
    double term = 1.0;       // 累乘项：(x-x0)(x-x1)...(x-x_{k-1})

    // 牛顿插值公式：N(x) = F[0][0] + F[0][1](x-x0) + F[0][2](x-x0)(x-x1) + ...
    for (int k = 1; k < n; ++k) {
        term *= (x - x_i[k-1]); // 累乘(x - x_{k-1})
        result += F[0][k] * term;
    }
    return result;
}

// 打印差商表（辅助理解，可选）
void printDividedDifferenceTable(const std::vector<double>& x_i, 
                                 const std::vector<std::vector<double>>& F) {
    int n = x_i.size();
    std::cout << "\n===== 差商表 =====" << std::endl;
    std::cout << "x_i\t";
    for (int j = 0; j < n; ++j) {
        std::cout << j << "阶差商\t";
    }
    std::cout << std::endl;

    for (int i = 0; i < n; ++i) {
        std::cout << x_i[i] << "\t";
        for (int j = 0; j < n - i; ++j) {
            std::cout << std::fixed << std::setprecision(4) << F[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::cout << "===== 牛顿插值法计算程序 =====" << std::endl;

    // 1. 输入已知离散点数量
    int n;
    std::cout << "请输入已知离散点的数量：";
    std::cin >> n;
    if (n < 2) {
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

    // 3. 计算差商表
    std::vector<std::vector<double>> F;
    calculateDividedDifference(x_i, y_i, F);

    // 4. 打印差商表（辅助分析）
    printDividedDifferenceTable(x_i, F);

    // 5. 输入待插值的x值
    double x;
    std::cout << "\n请输入需要插值的x值：";
    std::cin >> x;

    // 6. 计算插值结果
    double y = newtonInterpolation(x_i, F, x);

    // 7. 输出最终结果
    std::cout << "\n===== 插值结果 =====" << std::endl;
    std::cout << "待插值x值：" << x << std::endl;
    std::cout << "牛顿插值结果y值：" << std::fixed << std::setprecision(4) << y << std::endl;

    return 0;
}