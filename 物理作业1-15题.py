import matplotlib.pyplot as plot  # 导入matplotlib库中的pyplot，用于绘制图像
import numpy as np  # 导入numpy库，用于进行数值计算


# 定义常量和初始量
mass = 75  # 定义物体质量，单位为kg
velocity: np.ndarray = np.array([80.0, 0.0, 0.0])  # 初始速度数组，X方向速度为80m/s，Y方向速度为0
drag_coefficient = 0.375  # 阻力系数
initial_height = 2000  # 初始高度，单位为米
gravity = 10  # 重力加速度，单位为m/s^2
total_time = 4  # 模拟的总时间，单位为秒
time_step = 0.0001  # 时间步长，每次迭代所增加的时间，单位为秒

# 生成时间序列速度和列表(用于存储)`
time_list = np.linspace(0, total_time, int(total_time / time_step))
# 使用numpy的linspace函数生成从0到total_time的时间点，共有total_time/time_step个点

vX_list = np.zeros(len(time_list))  # 创建一个与时间序列长度相同的数组，用于存储X方向速度
vY_list = np.zeros(len(time_list))  # 创建一个与时间序列长度相同的数组，用于存储Y方向速度

# 初始化变量
index = 0  # 迭代索引，用于访问不同的时间点

# 模拟物体下落的运动
while True:  # 开始循环，直到满足条件跳出循环
    vX_list[index] = velocity[0]  # 存储当前时刻X方向的速度
    vY_list[index] = velocity[1]  # 存储当前时刻Y方向的速度

    # 更新Y方向速度  Vy = gravity * time
    velocity[1] += gravity * time_step

    # 计算当前速度的模，即速度的大小，考虑空气阻力的影响
    speed_norm = np.linalg.norm(velocity)  # numpy的linalg.norm函数用于计算向量的length
    velocity -= drag_coefficient * velocity * speed_norm * time_step  # 根据公式更新速度

    # 更新索引并检查是否超过total_time
    index += 1  # 每次循环索引加1
    if index >= len(time_list):  # 如果索引达到或超过时间列表的长度，跳出循环
        break  # 停止模拟，结束循环

# 创建图像，分别绘制Vx, Vy和总速度V
plot.figure(figsize=(10, 8))  # 创建一个大小为10x8英寸的画布

# 绘制X方向速度随时间的变化
plot.subplot(2, 2, 1)  # 创建2行2列的子图，并激活第一个子图
plot.title("Velocity X over Time")  # 设置子图的标题
plot.xlabel("Time (s)")  # 设置X轴的标签，单位为秒
plot.ylabel("Velocity X (m/s)")  # 设置Y轴的标签，单位为米/秒
plot.plot(time_list, vX_list)  # 绘制时间与X方向速度的关系曲线

# 绘制Y方向速度随时间的变化
plot.subplot(2, 2, 2)  # 激活第二个子图
plot.title("Velocity Y over Time")  # 设置子图的标题
plot.xlabel("Time (s)")  # 设置X轴的标签，单位为秒
plot.ylabel("Velocity Y (m/s)")  # 设置Y轴的标签，单位为米/秒
plot.plot(time_list, vY_list)  # 绘制时间与Y方向速度的关系曲线

# 计算总速度并绘制
v_total_list = np.sqrt(vX_list ** 2 + vY_list ** 2)
# 通过X方向和Y方向速度的平方和开方，计算每个时间点上的总速度

min_speed = np.min(v_total_list)  # 计算总速度的最小值
min_speed_index = np.argmin(v_total_list)  # 找到总速度最小值对应的时间点索引

plot.subplot(2, 2, 3)  # 激活第三个子图
plot.title("Total Speed over Time")  # 设置子图的标题
plot.xlabel("Time (s)")  # 设置X轴的标签，单位为秒
plot.ylabel("Speed (m/s)")  # 设置Y轴的标签，单位为米/秒
plot.plot(time_list, v_total_list)  # 绘制时间与总速度的关系曲线

# 在总速度图中标出最小速度点
plot.plot(time_list[min_speed_index], min_speed, 'go', scalex=0.5, scaley=0.5)
# 在总速度最小值点处绘制一个绿色的圆点

plot.text(x=time_list[min_speed_index] + 0.04,
          y=min_speed + 1.18,
          s=f'({time_list[min_speed_index]:.4f}, {min_speed:.4f})')
# 在最小速度点旁边标注时间和最小速度的坐标，格式化输出坐标为小数点后四位

# 显示所有图像
plot.tight_layout()  # 调整图像布局，防止子图重叠
plot.show()  # 显示绘制的图像