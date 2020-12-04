## DHAN模型

<p>原文：<a href="https://arxiv.org/pdf/2005.12981.pdf" style="text-decoration:none">Deep Interest with Hierachical Attention Network for Click-Through Rate Prediction</a></p>

#### 一、论文动机

DIN是对用户的行为序列中的兴趣进行建模，DHAN在此基础上提出了对多个维度（品种，价格区间，品牌）的兴趣层次（低层[具体的Item]到高层[对应的兴趣维度]）进行建模，在AUC上相比DIN提升了不少。

#### 二、模型结构

![image-20201114164643097](C:\Users\CXL\AppData\Roaming\Typora\typora-user-images\image-20201114164643097.png)

​               论文中着重介绍了一种简化版的DHAN模型，如下：

![image-20201114164836198](C:\Users\CXL\AppData\Roaming\Typora\typora-user-images\image-20201114164836198.png)

DHAN主要是从Item级别和属性级别去建模用户的兴趣

item-level:计算用户行为中物品的embedding和目标物品的embedding的相关性，把各自的权重相乘得到各物品融合了目标物品embedding的新的embedding；

![image-20201114165716324](C:\Users\CXL\AppData\Roaming\Typora\typora-user-images\image-20201114165716324.png)

attibute-level:根据某个具体的属性（比如品种）或者不同的属性组合将行为序列中的物品进行聚类，并通过组内向量加权求和的方式得到各个组别的向量表示，紧接着计算每一个组与目标物品的相关性权重，然后加权求和，得到针对属性级别上向量表示

![image-20201114165731762](C:\Users\CXL\AppData\Roaming\Typora\typora-user-images\image-20201114165731762.png)

最后，将item级别上的兴趣向量表示、属性级别上的兴趣向量表示和目标物品的向量表示三部分进行拼接，输入到MLP中，最终得到CTR预测结果

#### 三、模型效果

实验数据集：

![image-20201114170050817](C:\Users\CXL\AppData\Roaming\Typora\typora-user-images\image-20201114170050817.png)

实验指标AUC，和其他模型对比结果如下：

![image-20201114170200955](C:\Users\CXL\AppData\Roaming\Typora\typora-user-images\image-20201114170200955.png)

![image-20201114170214092](C:\Users\CXL\AppData\Roaming\Typora\typora-user-images\image-20201114170214092.png)

#### 四、总结

DHAN可以从多个维度和任意深度对用户的层次兴趣进行建模，从AUC指标上看，相比DIN提升12%-21%，相比DIEN提升1.0%-1.7%。未来的工作可以同时将用户的兴趣层级和演化进行建模，并且将预先定义好的兴趣维度替换成自动捕捉不同维度上的兴趣。