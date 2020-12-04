## DSIN模型

<p>原文：<a href="https://arxiv.org/pdf/1905.06482v1.pdf" style="text-decoration:none">Deep Session Interest Network for Click-Through Rate Prediction</a></p>

### 一、论文动机

此前大部分的研究都忽略了用户行为序列是由多个session构成的，同个session内行为是高度相似的，不同session则是不同的。作者提出深度会话兴趣网络模型，即DSIN模型。

### 二、模型结构

传统的base model主要是embedding层、各个特征embedding拼接在一起，然后输入到MLP中。DSIN在base model的基础上，在MLP层之前增加了四个部分：会话分割层、会话兴趣提取层、会话兴趣交互层和会话兴趣激活层。

![image-20201124001319666](C:\Users\CXL\AppData\Roaming\Typora\typora-user-images\image-20201124001319666.png)

- 会话分割层：

  每30分钟间隔为一个会话。

- 会话兴趣抽取层

  使用多头自注意力机制，得到每个session的兴趣表示。

  首先是bias encoding的计算，记为$BE\in\R^{K\times T\times d_{model}}$。要得到这个三维矩阵涉及到三个向量的计算，分别是会话偏移向量$w^K\in\R^K$，会话内的位置偏移向量$w^T\in R^T$，行为嵌入的单元位置的偏移向量$w^C\in\R^{d_{model}}$。公式为：

  ![image-20201124002945936](C:\Users\CXL\AppData\Roaming\Typora\typora-user-images\image-20201124002945936.png)

  加上偏移编码后，用户行为会话$Q$更新为：

  ![image-20201124003045032](C:\Users\CXL\AppData\Roaming\Typora\typora-user-images\image-20201124003045032.png)

  多头自注意力计算：

  ![image-20201124003425931](C:\Users\CXL\AppData\Roaming\Typora\typora-user-images\image-20201124003425931.png)

  一个session有H个头，其中第$h$个头的hidden size为$d_h=\frac{1}{h}d_{model}$，第$h$个头的输出：

  ![image-20201124003647526](C:\Users\CXL\AppData\Roaming\Typora\typora-user-images\image-20201124003647526.png)

  再将H个头拼接起来，送到前馈网路中得到一个矩阵。

  ![image-20201124003903160](C:\Users\CXL\AppData\Roaming\Typora\typora-user-images\image-20201124003903160.png)

  再进行average pooling，最终一个session用一个向量表示。

  ![image-20201124004044273](C:\Users\CXL\AppData\Roaming\Typora\typora-user-images\image-20201124004044273.png)

- 会话兴趣交互层

  使用的是双向LSTM，对会话兴趣之间的序列关系进行建模。

  ![image-20201124004215714](C:\Users\CXL\AppData\Roaming\Typora\typora-user-images\image-20201124004215714.png)

  将前向和后向的hidden state拼接，得到这一层的输出$H$。

  ![image-20201124004304174](C:\Users\CXL\AppData\Roaming\Typora\typora-user-images\image-20201124004304174.png)

- 会话兴趣激活层

  将第二层和第三层得到的兴趣矩阵分别与目标物品embedding使用注意力计算权重，再得到加权和。

  ![image-20201124004732127](C:\Users\CXL\AppData\Roaming\Typora\typora-user-images\image-20201124004732127.png)

  ![image-20201124004745429](C:\Users\CXL\AppData\Roaming\Typora\typora-user-images\image-20201124004745429.png)

  最后将用户向量和目标物品向量，以及$U^I$和$U^H$拼接在一起，然后输入MLP，得到CTR预测结果。

### 三、模型效果

数据集：阿里妈妈的广告数据集和阿里巴巴的推荐系统数据集

实验指标：AUC

![image-20201124005215943](C:\Users\CXL\AppData\Roaming\Typora\typora-user-images\image-20201124005215943.png)

实验结果：

![image-20201124005233747](C:\Users\CXL\AppData\Roaming\Typora\typora-user-images\image-20201124005233747.png)

结果可视化：

![image-20201124005307592](C:\Users\CXL\AppData\Roaming\Typora\typora-user-images\image-20201124005307592.png)

### 四、结论

对用户行为的会话兴趣进行建模，模型使用自注意力机制得到会话兴趣，通过Bi-LSTM得到会话兴趣的序列特征，在两个工业数据集上取得了比其他模型要好的效果。未来将引入知识图谱作为先验知识，为用户历史行为做出更好的解释。