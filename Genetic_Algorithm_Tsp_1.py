import random
import numpy as np
import math

# 参数设置
num_city = 30  # 城市总数
num_total = 100  # 随机生成的初始解总数
copy_num = 70  # 选择后保留的解的数量
cross_num = 20  # 交叉生成的新解数量
var_num = 10  # 变异生成的新解数量

# 从文件中加载城市位置
location = np.loadtxt('city_location.txt')


# 随机生成初始解
def generate_initial():
    initial = []
    city = list(range(num_city))
    for i in range(num_total):
        random.shuffle(city)  # 打乱城市顺序以生成随机解
        p = city.copy()  # 复制打乱后的城市列表
        while p in initial:  # 确保没有重复的解被添加
            random.shuffle(city)  # 如果发现重复则重新打乱
            p = city.copy()
        initial.append(p)  # 将唯一的解添加到初始解列表中
    return initial


# 计算城市之间的距离矩阵
def distance_p2p_mat():
    dis_mat = []
    for i in range(num_city):
        dis_mat_each = []
        for j in range(num_city):
            dis = math.sqrt(
                pow(location[i][0] - location[j][0], 2) + pow(location[i][1] - location[j][1], 2))  # 计算欧几里得距离
            dis_mat_each.append(dis)  # 将城市i到城市j的距离添加到列表中
        dis_mat.append(dis_mat_each)  # 将城市i到所有其他城市的距离列表添加到距离矩阵中
    return dis_mat


# 计算每个解的适应度
def dis_adp_total(dis_mat, initial):
    dis_adp = []  # 存储适应度的列表
    for i in range(num_total):
        dis = 0
        for j in range(num_city - 1):
            dis += dis_mat[initial[i][j]][initial[i][j + 1]]  # 累加相邻城市之间的距离
        dis += dis_mat[initial[i][num_city - 1]][initial[i][0]]  # 添加从最后一个城市回到第一个城市的距离
        dis_adp_each = 10000.0 / dis  # 适应度与路径距离成反比
        dis_adp.append(dis_adp_each)  # 将适应度添加到列表中
    return dis_adp


# 基于适应度选择解
def choose_fromlast(dis_adp, answer_source):
    mid_adp = []  # 用于选择的累积适应度列表
    mid_adp_each = 0
    for i in range(num_total):
        mid_adp_each += dis_adp[i]  # 计算累积适应度
        mid_adp.append(mid_adp_each)

    copy_ans = []
    for p in range(copy_num):
        rand = random.uniform(0, mid_adp[-1])  # 在0到总累积适应度之间生成随机数
        for j in range(num_total):
            if rand < mid_adp[j]:  # 选择与随机数对应的解
                copy_ans.append(answer_source[j])
                break
    return copy_ans


# 对选择的解进行交叉操作
def cross_pronew(copy_ans):
    for i in range(cross_num):
        which = random.randint(0, copy_num - 1)  # 随机选择一个解进行交叉
        cross_list = copy_ans[which].copy()
        while cross_list in copy_ans:  # 确保新解是唯一的
            p, q = random.sample(range(num_city), 2)  # 随机选择两个城市进行交换
            cross_list[p], cross_list[q] = cross_list[q], cross_list[p]  # 交换两个城市的位置
        copy_ans.append(cross_list)  # 将新解添加到列表中
    return copy_ans


# 对解进行变异操作
def var_pronew(cross_ans):
    for i in range(var_num):
        which = random.randint(0, copy_num + cross_num - 1)  # 随机选择一个解进行变异
        var_list = cross_ans[which].copy()
        while var_list in cross_ans:  # 确保变异后的解是唯一的
            p, q = random.sample(range(num_city), 2)  # 随机选择两个城市进行交换
            var_list[p], var_list[q] = var_list[q], var_list[p]  # 交换两个城市的位置
        cross_ans.append(var_list)  # 将变异后的解添加到列表中
    return cross_ans


# 主过程
answer_source = generate_initial()  # 生成初始解

dis_mat = distance_p2p_mat()  # 计算距离矩阵

dis_adp = dis_adp_total(dis_mat, answer_source)  # 计算初始解的适应度

# 检查是否找到满意的解
adp_max_new = max(dis_adp)
if adp_max_new > 10000 / 700:
    print('找到的最近距离是：', 10000 / adp_max_new)  # 输出找到的最短距离
else:
    print('哎呀没找到，我再找找~')  # 如果没有找到满意的解则继续搜索
    answer_new = answer_source
    dis_adp_new = dis_adp
    while adp_max_new <= 10000 / 700:
        copy_answer = choose_fromlast(dis_adp_new, answer_new)  # 选择解
        cross_answer = cross_pronew(copy_answer)  # 进行交叉操作
        var_answer = var_pronew(cross_answer)  # 进行变异操作
        answer_new = var_answer.copy()  # 更新当前的解集
        dis_adp_new = dis_adp_total(dis_mat, answer_new)  # 重新计算适应度
        adp_max_new = max(dis_adp_new)  # 更新最佳适应度

    dis_min = 10000 / adp_max_new  # 计算最短距离
    print('终于找到你啦：', dis_min)  # 输出找到的最短距离
