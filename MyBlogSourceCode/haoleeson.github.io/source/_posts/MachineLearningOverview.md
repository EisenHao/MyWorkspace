layout: post
title: 机器学习概述（简单了解）
date: 2019/11/23 22:30:45
updated: 2019/11/23 22:10:45
comments: true
tags: 
- 机器学习
categories:
- 算法

---

本文记录机器学习基础与框架的简单介绍

# 1. 机器学习是什么
- 机器从数据中学习
- 机器学习（≈ 寻找一个函数）

<!-- more -->

f( 一段语音 ) = 语义

f( 一张图片 ) = 识别对象

f( 棋局 ) = 最优解

f( 语义 ) = 反馈语义

# 2. 机器学习的三种分类
- **监督学习（有标签）**

任务驱动：识别、分类、回归

- **非监督学习（无标签）**

数据驱动：聚类

- **强化学习**

与环境互动

# 3. 理解机器学习的框架
以图像识别为例，讲解监督学习框架的四个步骤：

- 收集数据
- 选择模型。模型：函数的集合（无穷个）
- 调整参数。定义模型中函数的好坏
- 找到最优（函数 f*）

# 4. 机器学习应用实例与方法
- 线性回归。房价预测
- 梯度下降
- 判决树
- 逻辑回归
- 神经网络
- 支持向量机
- 朴素贝叶斯
- 聚类