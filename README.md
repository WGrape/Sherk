
<div align="center">

<img width="220px" src="https://github.com/Lvsi-China/Sherk/raw/master/extra/image/logo/sherk.jpeg">

<br/>

<img width="90px" src="https://github.com/Lvsi-China/Sherk/raw/master/extra/image/logo/1.jpg">

</div>

<br/>

<div align="center">
<img height="40px" src="https://github.com/Lvsi-China/Sherk/raw/master/extra/image/logo/2.jpg">
<p><font size=2>A Relational Database System Implementation Based on C Language</font></p>
</div>

<br>

#### 介绍
第 6 章才开始代码的实现，你可以选择 [直接看代码](https://note.youdao.com/)
<br>

<br>

> ### 1. 前言
> - [1.1 项目介绍](https://note.youdao.com/)
> - [1.2 图解数据库](https://note.youdao.com/)
> - [1.3 数据库的4个基本概念](https://note.youdao.com/)
>
> ### 2. 数据库系统的理解
>
> - [2.1 数据模型的分类](https://note.youdao.com/)
> - [2.2 数据库系统分类](https://note.youdao.com/)
> - [2.3 数据库系统的特点](https://note.youdao.com/)
>
> ### 3. 非关系型数据库系统
>
> - [3.1 概述](https://note.youdao.com/)
> - [3.2 非关系型数据库的特点](https://note.youdao.com/)
> - [3.3 常见的非关系型数据库](https://note.youdao.com/)
>
> ### 4. 关系型数据库系统的理解
>
> - [4.1 关系数据结构](https://note.youdao.com/)
> - [4.2 关系的完整性](https://note.youdao.com/)
>
> - 4.3 关系的代数运算
>     - [4.3.1 集合运算](https://note.youdao.com/)
>
>     - 4.3.2 关系运算
>         - [选择](https://note.youdao.com/)
>         - [投影](https://note.youdao.com/)
>         - [连接](https://note.youdao.com/)
>         - [除](https://note.youdao.com/)
>
> - [4.4 关系模式的数据理论](https://note.youdao.com/)
>
>
> ### 5. 关系型数据库系统的理论架构
>
> - #### 5.1 完整性
>
>     - [5.1.1 概述](https://note.youdao.com/)
>     - [5.1.2 实体完整性](https://note.youdao.com/)
>     - [5.1.3 参照完整性](https://note.youdao.com/)
>     - [5.1.4 自定义完整性](https://note.youdao.com/)
>     - [5.1.5 断言](https://note.youdao.com/)
>
> - #### 5.2 数据存储
>
>     - [5.2.1 概述](https://note.youdao.com/)
>     - [5.2.2 磁盘存储](https://note.youdao.com/)
>     - 5.2.3 内存缓存
>         - [缓存池](https://note.youdao.com/)
>
> - #### 5.3 数据索引
>
>     - [5.3.1 概述](https://note.youdao.com/)
>     - [5.3.2 索引的分类](https://note.youdao.com/)
>
>     - 5.3.3 索引的实现原理
>
>         - [B 树索引](https://note.youdao.com/)
>         - [B+ 树索引](https://note.youdao.com/)
>         - [Hash 索引](https://note.youdao.com/)
>
> - #### 5.4 查询处理
>
>     - [5.4.1 概述](https://note.youdao.com/)
>
>     - 5.4.2 查询步骤
>
>         - [查询分析](https://note.youdao.com/)
>         - [查询检查](https://note.youdao.com/)
>         - [查询优化](https://note.youdao.com/)
>         - [查询执行](https://note.youdao.com/)
>
>     - [5.4.3 理解查询计划](https://note.youdao.com/)
>
>     - 5.4.4 理解查询优化
>
>         - [查询优化概述](https://note.youdao.com/)
>         - [实例讲解](https://note.youdao.com/)
>         - [优化方法](https://note.youdao.com/)
>
> - #### 5.5 日志系统
>
> - #### 5.6 事务处理
>
>     - ##### 5.6.1 事务
>
>         - [概述](https://note.youdao.com/)
>         - [图解事务](https://note.youdao.com/)
>         - 事务的 ACID 特性
>
>             - [原子性 ( Atomicity )](https://note.youdao.com/)
>             - [一致性 ( Consistency )](https://note.youdao.com/)
>             - [隔离性 ( Isolation )](https://note.youdao.com/)
>             - [持久性 ( Durability )](https://note.youdao.com/)
>
>         - [实例讲解](https://note.youdao.com/)
>
>     - ##### 5.6.2 并发控制
>
>         - [概述](https://note.youdao.com/)
>         - [封锁及其协议](https://note.youdao.com/)
>         - [封锁的粒度](https://note.youdao.com/)
>         - [活锁和死锁](https://note.youdao.com/)
>         - [多版本并发控制](https://note.youdao.com/)
>
>     - ##### 5.6.3 恢复技术
>
>         - [概述](https://note.youdao.com/)
>         - [数据转储](https://note.youdao.com/)
>         - [登记日志文件](https://note.youdao.com/)
>         - [检查点恢复技术](https://note.youdao.com/)
>
> - #### 5.7 安全性
>
>     - [5.7.1 概述](https://note.youdao.com/)
>     - [5.7.2 视图](https://note.youdao.com/)
>     - [5.7.3 审计](https://note.youdao.com/)
>     - [5.7.4 安全控制](https://note.youdao.com/)
>     - [5.7.5 数据加密](https://note.youdao.com/)
>     - [5.7.6 其他](https://note.youdao.com/)
>
> ### 6. 关系型数据库系统的代码实现
>
> - ##### 6.1 介绍
>
>     - [6.1.1 目录结构](https://note.youdao.com/)
>
> - #### 6.2 客户端
>
> - #### 6.3 服务端
>
>
>
> ### 7. 完结
> - [7.1 总结](https://note.youdao.com/)
> - [7.2 思考](https://note.youdao.com/)
> - 7.3 附录
>     - 7.3.1 [参考资料及文献](#article-7.3.1)


### 7. 完结

- 7.1 总结 <br/>
在信息化社会，充分有效地管理和利用各类信息资源，是进行科学研究和决策管理的前提条件。数据库技术是管理信息系统、办公自动化系统、决策支持系统等各类信息系统的核心部分，是进行科学研究和决策管理的重要技术手段。

- 7.2 思考 <br/>
随着信息管理内容的不断扩展，出现了丰富多样的数据模型（层次模型，网状模型，关系模型，面向对象模型，半结构化模型等），新技术也层出不穷（数据流，Web数据管理，数据挖掘等）。每隔几年，国际上一些资深的数据库专家就会聚集一堂，探讨数据库研究现状，存在的问题和未来需要关注的新技术焦点。

- 7.3 附录 <br/>
    - 7.3.1 <span id="article-7.3.1">参考资料及文献</span>
    <br/>
    > 参考资料及文献有： <br>
    > 1.《数据库系统概论》 王珊 <br/>
    > 2.[如何自己实现一个关系型数据库？](https://www.zhihu.com/question/38870156)



