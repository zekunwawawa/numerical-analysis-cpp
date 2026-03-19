## 📖 项目简介
本项目用于整理和实现数值分析课程中的经典算法，代码均为 C/C++ 编写，便于编译运行和算法理解。适合课程复习、算法复盘与编程练习。

## 📂 目录结构
```plaintext
numerical-analysis-cpp/
├── README.md                 # 项目说明文档
├── .gitignore                # Git 忽略文件配置
├── 线性方程组/                # 线性方程组求解算法
│   ├── gauss_elimination.cpp # 高斯消元法
│   └── lu_decomposition.cpp  # LU 分解法
├── 插值法/                    # 插值算法
│   ├── lagrange_interpolation.cpp # 拉格朗日插值
│   └── newton_interpolation.cpp   # 牛顿插值
├── 数值积分/                  # 数值积分算法
│   ├── trapezoidal_rule.cpp  # 梯形公式
│   └── simpson_rule.cpp      # 辛普森公式
└── 非线性方程/                # 非线性方程求解
    └── newton_raphson.cpp    # 牛顿-拉夫逊迭代法
```

## 🛠️ 编译与运行
### 环境依赖
- 编译器：`g++`（推荐使用 MSYS2 或 MinGW-w64）
- 构建工具：直接命令行编译即可

### 编译命令
以 `gauss_elimination.cpp` 为例：

```bash
g++ 线性方程组/gauss_elimination.cpp -o gauss_elimination.exe
```

---
### ✨ 目标实现算法

| 模块         | 算法名称           | 文件名                          |
|--------------|--------------------|---------------------------------|
| 线性方程组   | 高斯消元法         | `gauss_elimination.cpp`         |
| 线性方程组   | LU 分解法          | `lu_decomposition.cpp`          |
| 插值法       | 拉格朗日插值       | `lagrange_interpolation.cpp`    |
| 插值法       | 牛顿插值           | `newton_interpolation.cpp`      |
| 数值积分     | 梯形公式           | `trapezoidal_rule.cpp`          |
| 数值积分     | 辛普森公式         | `simpson_rule.cpp`              |
| 非线性方程   | 牛顿-拉夫逊迭代法  | `newton_raphson.cpp`            |

## 📝 更新日志

- **2026-03-19**：初始化项目

---

## 📧 联系方式

- GitHub：[zekunwawawa](https://github.com/zekunwawawa)
- 邮箱：`2847432767@qq.com`





