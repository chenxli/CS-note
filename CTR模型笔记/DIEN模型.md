## DIEN模型

<p>原文:<a href="https://arxiv.org/pdf/1809.03672v1.pdf" style="text-decoration:none">Deep Interest Evolution Network for Click-Through Rate Prediction</a></p>

### 一、论文动机

在CTR预测任务中，对于用户潜在兴趣的挖掘和用户兴趣的动态演化建模是很重要的。此前的兴趣模型都是直接把行为的表征当成是用户兴趣，缺少对用户潜在兴趣的建模，也忽略了用户兴趣的动态变化，因而提出深度兴趣演化网络，即DIEN。

### 二、模型结构

模型主要包含四部分：嵌入层、兴趣提取层、兴趣演化层和MLP。嵌入层和MLP都跟base model一样，重点在于兴趣提取层和兴趣演化层的设计。

![image-20201122004535889](C:\Users\CXL\AppData\Roaming\Typora\typora-user-images\image-20201122004535889.png)

- 兴趣提取层

  使用GRU建模用户行为之间的依赖，其中GRU的公式为：

  ![image-20201122005721856](C:\Users\CXL\AppData\Roaming\Typora\typora-user-images\image-20201122005721856.png)

  对于GRU隐藏状态的输出设计了一个辅助损失函数（DMIN模型中也有），公式为：

  ![image-20201122005936347](C:\Users\CXL\AppData\Roaming\Typora\typora-user-images\image-20201122005936347.png)

  其中正样本为下一个时刻的物品embedding，负样本为除了下一个物品的其他所有物品的embedding。

  其好处有三：

  - 可以让GRU的隐藏状态更能体现用户兴趣所在；
  - 可以降低向后传播的难度；
  - 可以给予嵌入层的向量更多语义信息，产生更好的嵌入矩阵

- 兴趣演化层

  这一层的目标是利用注意力机制和设计的AUGRU学习出最终的兴趣表征。

  注意力机制的计算如下：

  ![image-20201122011520070](C:\Users\CXL\AppData\Roaming\Typora\typora-user-images\image-20201122011520070.png)

  接下来怎么利用这个权重呢？论文提出了三种使用方法：

  - AIGRU

  此做法是直接将权重与兴趣抽取层的隐藏状态向量相乘，然后   输入到当前这一层的GRU中。这种方法的缺点是即便是一个很小的向量也会对GRU的隐藏状态产生影响，因此相关性比较弱的兴趣也会对兴趣的演化学习产生影响。

  ![image-20201122012003152](C:\Users\CXL\AppData\Roaming\Typora\typora-user-images\image-20201122012003152.png)

  - AGRU

  此做法是将GRU中的update门直接用权重替换，隐藏状态的公式为：

  ![image-20201122012047765](C:\Users\CXL\AppData\Roaming\Typora\typora-user-images\image-20201122012047765.png)

  - AUGRU

  此做法是重新定义了GRU中更新门的计算，在原有的计算基础上加入了注意力机制的权重，具体公式为：

  ![image-20201122012331967](C:\Users\CXL\AppData\Roaming\Typora\typora-user-images\image-20201122012331967.png)

  损失函数：

  ![image-20201122012637295](C:\Users\CXL\AppData\Roaming\Typora\typora-user-images\image-20201122012637295.png)

### 三、模型效果

实验数据集：Amazaon数据集的两个子集：Books和Electronics、阿里巴巴自己的工业数据集。

![image-20201122012737808](C:\Users\CXL\AppData\Roaming\Typora\typora-user-images\image-20201122012737808.png)

实验指标：AUC

实验结果：

![image-20201122012757119](C:\Users\CXL\AppData\Roaming\Typora\typora-user-images\image-20201122012757119.png)

![image-20201122012845132](C:\Users\CXL\AppData\Roaming\Typora\typora-user-images\image-20201122012845132.png)

检验了AUGRU和辅助损失函数的有效性：

![image-20201122012944933](C:\Users\CXL\AppData\Roaming\Typora\typora-user-images\image-20201122012944933.png)

![image-20201122013042798](C:\Users\CXL\AppData\Roaming\Typora\typora-user-images\image-20201122013042798.png)

AB测试的结果：

![image-20201122013233199](C:\Users\CXL\AppData\Roaming\Typora\typora-user-images\image-20201122013233199.png)

可以看出DIEN模型提升非常明显。

### 四、结论

提出了DIEN模型，使用兴趣抽取层捕捉用户兴趣，并巧妙地设计除了辅助损失函数有助于更好的学习兴趣表征。兴趣演化层将注意力机制和GRU结合起来，设计出了AUGRU对用户对于目标物品的兴趣演化过程建模，减少了兴趣变动带来的扰动，从而提升了CTR预测的准确度。