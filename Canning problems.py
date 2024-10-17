# 这里导入了sympy库，简化为sp，用于符号计算。
import sympy as sp

# 定义符号变量
r, V = sp.symbols('r V')
"""
sp.symbols('r V')是SymPy库中的一个函数，用于创建符号变量。
在数学建模和符号计算中，符号变量是一种可以表示数学表达式的变量，可以用于进一步的代数操作，例如微分、积分、化简等。
在这段代码中，sp.symbols('r V')创建了两个符号变量r和V，它们可以被用来表示数学表达式中的未知量或者参数。
具体来说：
r表示罐的半径。
V表示罐的体积。
这些符号变量不同于普通的数值变量，它们是符号化的，这意味着它们可以被用作代数计算的对象，例如求导、解方程等。
"""
# 使用 pi 来表示圆周率，并定义了高度 h，它表示为体积 V 和半径 r 的函数。
# 这个公式是基于圆柱体的体积公式推导出来的。
pi = sp.pi
h = V / (pi * r**2)

# 表面积公式Area
Area = 2 * pi * r * h + 4 * pi * r ** 2

# 将h代入A
Area = Area.subs(h, V / (pi * r ** 2))
"""
Area = Area.subs(h, V / (pi * r**2)) 是SymPy库中的一个替换操作，用于将表达式中的某个符号变量用另一个表达式替换。
具体来说，Area是一个关于半径r和高度h的表面积公式，我们想要消除变量h，使得Area只用一个变量r来表示。
subs() 函数：subs()是SymPy中用于替换符号的函数，语法是Area.subs(旧变量, 新表达式)，它会将Area中的所有旧变量替换为新表达式。
"""
# 对Area关于r求导，得到dArea_dr，然后通过sp.solve(dArea_dr, r)求解导数等于0的r值，以找到表面积最小的最优半径optimal_r。
dArea_dr = sp.diff(Area, r)  # sp.diff(Area, r)是SymPy中用于求导的函数，表示对表面积Area关于变量r求导。
best_r = sp.solve(dArea_dr, r)[0]
# sp.solve(dArea_dr, r)是SymPy中的方程求解函数，表示要解dArea_dr = 0这个方程，以确定r的值。
# 通过求解这个方程，我们可以找到半径r的最优值，使得表面积A最小。
# [0]表示获取第一个解。在求解过程中，会得到多个解，但我们只取符合条件的正值。
# best_r是命名的变量，它代表了使得表面积最小化的最佳半径。

# 计算对应的h值
best_h = V / (pi * best_r**2)

# 计算高和直径的比值
h_D = best_h / (2 * best_r)

# 输出结果
print(f"最优半径 r: {best_r}")  # f"..."表示格式化字符串：f-string是一种格式化输出的方式。
print(f"最优高度 h: {best_h}")  # 允许你直接在字符串中嵌入变量的值，使用大括号 {} 表示需要插入的变量。
print(f"高和直径的比值 h/D: {h_D}")