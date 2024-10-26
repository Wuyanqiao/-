# Author: WYQ
# Description: 模拟空降兵从飞机跳出后的运动，考虑重力和空气阻力的影响。通过数值积分计算运动随时间的变化，使用机器学习对速度数据进行拟合，以优化收尾速度的估计，并绘制相关的速度和高度变化曲线。

import numpy as np
import matplotlib.pyplot as plt
from sklearn.linear_model import LinearRegression
from sklearn.preprocessing import PolynomialFeatures

# 使用机器学习优化速度数据

def simulate_motion(m, k, g, v_initial_y, v_initial_x, dt, t_max):
    # 初始化参数
    t = 0  # 初始时间 (s)
    y = 2000  # 初始高度 (m)
    v_y = v_initial_y  # 初始垂直速度 (m/s)
    v_x = v_initial_x  # 初始水平速度 (m/s)
    t_values = [t]  # 记录时间的列表
    y_values = [y]  # 记录高度的列表
    v_y_values = [v_y]  # 记录垂直速度的列表
    v_x_values = [v_x]  # 记录水平速度的列表
    v_total_values = [np.sqrt(v_x ** 2 + v_y ** 2)]  # 记录总速度的列表

    # 数值积分计算速度随时间变化
    while t < t_max and y > 0:
        # 计算总速度
        v_total = np.sqrt(v_x ** 2 + v_y ** 2)  # 当前总速度 (m/s)

        # 计算加速度，考虑重力和阻力
        a_y = -g - (k / m) * v_total * v_y  # 垂直方向的加速度 (m/s^2)
        a_x = -(k / m) * v_total * v_x  # 水平方向的加速度 (m/s^2)

        # 更新速度和位置
        v_y = v_y + a_y * dt  # 更新垂直速度 (m/s)
        v_x = v_x + a_x * dt  # 更新水平速度 (m/s)
        y = y + v_y * dt  # 更新高度 (m)
        t = t + dt  # 更新时间 (s)

        # 记录时间、速度和高度
        t_values.append(t)
        y_values.append(y)
        v_y_values.append(v_y)
        v_x_values.append(v_x)
        v_total_values.append(np.sqrt(v_x ** 2 + v_y ** 2))

    return t_values, y_values, v_y_values, v_x_values, v_total_values

# 模型参数
m = 75  # 空降兵质量 (kg)
k = 0.375  # 阻力系数 (kg/m)
g = 9.8  # 重力加速度 (m/s^2)
v_initial_y = 0  # 初始垂直速度 (m/s)
v_initial_x = -80  # 初始水平速度 (m/s), 负号表示向x轴负方向

dt = 0.01  # 时间步长 (s)
t_max = 300  # 最大模拟时间 (s)

# 模拟运动
t_values, y_values, v_y_values, v_x_values, v_total_values = simulate_motion(m, k, g, v_initial_y, v_initial_x, dt, t_max)

# 使用机器学习对速度数据进行拟合，以优化收尾速度估计
poly = PolynomialFeatures(degree=3)  # 创建三次多项式特征
# 将时间值转换为numpy数组并进行多项式特征转换
t_values_np = np.array(t_values).reshape(-1, 1)
v_total_values_np = np.array(v_total_values).reshape(-1, 1)
t_poly = poly.fit_transform(t_values_np)

# 使用线性回归模型对数据进行拟合
model = LinearRegression()
model.fit(t_poly, v_total_values_np)
v_total_pred = model.predict(t_poly)  # 预测总速度值

# 确定开伞的最佳时间（垂直速度达到最小值时）
v_min = min(v_y_values)  # 找到垂直速度的最小值
v_min_index = v_y_values.index(v_min)  # 最小值对应的索引
t_best = t_values[v_min_index]  # 开伞的最佳时间

# 确定最佳收尾速率
v_terminal = v_total_pred[-1][0]  # 最佳收尾速度，取预测速度的最后一个值

# 绘制垂直速度、水平速度和总速度 v-t 曲线
plt.figure(figsize=(12, 8))
plt.plot(t_values, v_y_values, label='Vertical Velocity (v_y-t)', color='b')  # 绘制垂直速度随时间变化曲线
plt.plot(t_values, v_x_values, label='Horizontal Velocity (v_x-t)', color='orange')  # 绘制水平速度随时间变化曲线
plt.plot(t_values, v_total_values, label='Total Velocity (v_total-t)', color='purple', linestyle=':')  # 绘制总速度随时间变化曲线
plt.plot(t_values, v_total_pred, label='Predicted Total Velocity (v_total-t)', color='green')  # 绘制预测的总速度曲线
plt.axvline(t_best, linestyle='--', color='r', label=f'Open parachute at t={t_best:.2f}s')  # 标注开伞的最佳时间
plt.xlabel('Time (s)')
plt.ylabel('Velocity (m/s)')
plt.title('Velocity vs Time for Paratrooper Descent')  # 图表标题
plt.legend()  # 图例
plt.grid()  # 网格线
plt.show()

# 绘制高度 y-t 曲线
plt.figure(figsize=(10, 6))
plt.plot(t_values, y_values, label='Height (y-t)', color='g')  # 绘制高度随时间变化曲线
plt.xlabel('Time (s)')
plt.ylabel('Height (m)')
plt.title('Height vs Time for Paratrooper Descent')  # 图表标题
plt.legend()  # 图例
plt.grid()  # 网格线
plt.show()

# 打印开伞的最佳时间和最佳收尾速度
print(f'最佳开伞时间: {t_best:.2f} s')  # 输出最佳开伞时间
print(f'最佳收尾速率 (predicted): {v_terminal:.2f} m/s')  # 输出最佳收尾速度（预测）
