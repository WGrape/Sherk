# 《 第一章 - 理论学习 》正文

- [↻ 回到目录](https://github.com/Lvsi-China/Sherk/blob/master/docs/README.section1.index.md) &nbsp; [☝ 回到首页](https://github.com/Lvsi-China/Sherk)
- [《第二章 - 代码实现》](https://github.com/Lvsi-China/Sherk/blob/master/docs/README.section2.index.md)
- [《第三章 - 完结讨论》](https://github.com/Lvsi-China/Sherk/blob/master/docs/README.section3.index.md)
<br/><br/>


## 1. 前言

- ### <span id="article-1.1">1.1 图解数据库</span>

- ### <span id="article-1.2">1.2 数据库的发展历史</span>

- ### 1.3 数据库的4个基本概念

    - #### <span id="article-1.3.1">1.3.1 数据</span><br/>
        数据是数据库中存储的基本对象。

    - #### <span id="article-1.3.2">1.3.2 数据库</span><br/>
        数据库即是存放数据的仓库。

    - #### <span id="article-1.3.3">1.3.3 数据库管理系统</span><br/>
        数据库管理系统是位于用户与操作系统之间的一层数据管理软件

    - #### <span id="article-1.3.4">1.3.4 数据库系统</span><br/>
        数据库系统是由数据库、数据库管理系统、应用程序和数据库管理员组成的存储、管理、处理和维护数据的系统。

<br/>

## 2. 数据库系统的理解

- ### 2.1 数据模型的概述及分类

    - #### <span id="article-2.1.1">2.1.1 概述</span>
        现有的数据库系统均基于某种数据模型的，数据模型是数据库系统的核心和基础。数据模型是一种模型，是对现实世界数据特征的抽象。也就是说数据模型是用来描述数据，组织数据和对数据进行操作的。<br/>
        在数据模型中有 型（type） 和 值（value）的概念。

    - #### <span id="article-2.1.2">2.1.2 概念模型</span>

    - #### <span id="article-2.1.3">2.1.3 物理模型</span>


- ### 2.2 数据库系统的概述及分类

    - #### <span id="article-2.2.1">2.2.1 层次数据库系统 - 基于层次模型</span><br/>

    - #### <span id="article-2.2.2">2.2.2 网状数据库系统 - 基于网状模型</span>


- ### 2.3 数据库系统的三级模式结构

    - #### <span id="article-2.3.1">2.3.1 概述</span><br/>
        数据库系统的三级模式结构是指数据库系统是由外模式、模式、内模式三级构成的。

    - #### <span id="article-2.3.2">2.3.2 外模式</span><br/>
        外模式也称为子模式（subschema）或用户模式、它是数据库用户能够看见和使用的局部数据的逻辑结构域和特征的描述，是数据库用户的数据视图，是与某一应用有关的数据的逻辑表示

    - #### <span id="article-2.3.3">2.3.3 模式</span><br/>
        模式也称为逻辑模式，是数据库中全体数据的逻辑结构和特征的描述，是所有用户的公共数据视图。

    - #### <span id="article-2.3.4">2.3.4 内模式</span><br/>
        内模式也称为存储模式（storage schema），一个数据库只有一个内模式。它是数据物理结构和存储方式的描述，是数据在数据库内部的组织方式。

- ### 2.4 数据库系统的特点

<br/>

## 3. 非关系型数据库系统（NoSQL）

- ### <span id="article-3.1">3.1 概述</span>

    NoSQL，泛指非关系型的数据库。随着互联网web2.0网站的兴起，传统的关系数据库在应付web2.0网站，特别是超大规模和高并发的SNS类型的web2.0纯动态网站已经显得力不从心，暴露了很多难以克服的问题，而非关系型的数据库则由于其本身的特点得到了非常迅速的发展。NoSQL数据库的产生就是为了解决大规模数据集合多重数据种类带来的挑战，尤其是大数据应用难题。

- ### <span id="article-3.2">3.2 非关系型数据库的特点</span>

    1.&nbsp;不需要预定义模式<br/>
    2.&nbsp;无共享架构<br/>
    3.&nbsp;弹性可扩展<br/>
    4.&nbsp;分区<br/>
    5.&nbsp;异步复制<br/>

- ### <span id="article-3.3">3.3 常用的非关系型数据库</span>

<br/>


## 4. 深入理解关系型数据库系统

- ### 4.1 基础概念

    - #### <span id="article-4.1.1">4.1.1 定义</span>

        关系型数据库系统的定义如此。

    - #### <span id="article-4.1.2">4.1.2 如何理解关系</span>
        关系：现实世界的实体以及实体间的各种联系均用单一的结构类型，即关系来表示。

    - #### 4.1.3 关系模型的三个组成

        - ##### <span id="article-4.1.3.1">关系数据结构</span>
            关系模型的数据结构非常简单

        - ##### <span id="article-4.1.3.2">关系操作集合</span>
            查询（query）、插入（insert）、删除（delete）、修改（update）

        - ##### <span id="article-4.1.3.3">关系完整性约束</span>
            实体完整性、参照完整性、自定义完整性

    - #### 4.1.4 关系模式的数据理论

        - ##### <span id="article-4.1.4.1">什么是关系模式</span>
            在数据库中要区分型和值。在关系数库中，关系模式是型，关系是值。关系模式是对关系的描述 。

        - ##### <span id="article-4.1.4.2">好的关系模式应具有的特点</span>
            - <span id="article-4.1.4.2.1">数据冗余少</span>
            - <span id="article-4.1.4.2.2">插入正常</span>
            - <span id="article-4.1.4.2.3">更新正常</span>
            - <span id="article-4.1.4.2.4">删除正常</span>

        - ##### <span id="article-4.1.4.3">规范化（关系模式的模式分解）</span>
            - <span id="article-4.1.4.3.1">函数依赖</span>
            - <span id="article-4.1.4.3.2">码</span>
            - <span id="article-4.1.4.3.3">范式</span>
            - <span id="article-4.1.4.3.4">2NF</span>
            - <span id="article-4.1.4.3.5">3NF</span>
            - <span id="article-4.1.4.3.6">BCNF</span>
            - <span id="article-4.1.4.3.7">多值依赖</span>
            - <span id="article-4.1.4.3.8">4NF</span>

- ### 4.2 关系的完整性

    - #### <span id="article-4.2.1">4.2.1 概述</sapn>
    - #### <span id="article-4.2.2">4.2.2 实体完整性</span>
    - #### <span id="article-4.2.3">4.2.3 参照完整性</span>
    - #### <span id="article-4.2.4">4.2.4 自定义完整性</span>

- ### 4.3 关系的代数运算

    - #### <span id="article-4.3.1">4.3.1 集合运算</span>

        并运算（∪）、差运算（－）、交运算（∩）、笛卡尔积（×）

    - #### 4.3.2 关系运算

        - ##### <span id="article-4.3.2.1">选择</span>
        - ##### <span id="article-4.3.2.2">投影</span>
        - ##### <span id="article-4.3.2.3">连接</span>
        - ##### <span id="article-4.3.2.4">除</span>


<br/>


## 5. 关系型数据库系统的理论架构

- #### 5.1 完整性
-
    - ##### <span id="article-5.1.1">5.1.1 概述</span>
    - ##### <span id="article-5.1.2">5.1.2 实体完整性</span>
    - ##### <span id="article-5.1.3">5.1.3 参照完整性</span>
    - ##### <span id="article-5.1.4">5.1.4 自定义完整性</span>
    - ##### <span id="article-5.1.5">5.1.5 断言（Assertion）</span>

- #### 5.2 数据存储

    - ##### <span id="article-5.2.1">5.2.1 概述</span>

    - ##### 5.2.2 磁盘存储

        - ###### <span id="article-5.2.2.1">内存缓存</span>
        - ###### <span id="article-5.2.2.2">缓存池</span>

- #### 5.3 数据索引

    - ##### 5.3.1 <span id="article-5.3.1">概述</span>
    - ##### 5.3.2 <span id="article-5.3.2">索引的分类</span>

    - ##### - 5.3.3 索引的实现原理
        - ###### <span id="article-5.3.3.1">B 树索引</span>
        - ###### <span id="article-5.3.3.2">B+ 树索引</span>
        - ###### <span id="article-5.3.3.3">Hash 索引</span>

- #### 5.4 查询处理

    - ##### <span id="article-5.4.1">5.4.1 概述</span>

    - ##### 5.4.2 查询步骤
        - ###### <span id="article-5.4.2.1">查询分析</span>
        - ###### <span id="article-5.4.2.2">查询检查</span>
        - ###### <span id="article-5.4.2.3">查询优化</span>
        - ###### <span id="article-5.4.2.4">查询执行</span>

    - ##### <span id="article-5.4.3">5.4.3 理解查询计划

    - ##### 5.4.4 理解查询优化
        - ###### <span id="article-5.4.4.1">查询优化概述</span>
        - ###### <span id="article-5.4.4.2">实例讲解</span>
        - ###### <span id="article-5.4.4.3">优化方法</span>

- #### 5.5 日志系统

- #### 5.6 事务处理

    - ##### 5.6.1 事务

        - ##### <span id="article-5.6.1.1">概述</span>

        - ##### <span id="article-5.6.1.2">图解事务</span>

        - ##### 事务的 ACID 特性
            - ###### <span id="article-5.6.1.3.1">原子性 ( Atomicity )</span>
            - ###### <span id="article-5.6.1.3.2">一致性 ( Consistency )</span>
            - ###### <span id="article-5.6.1.3.3">隔离性 ( Isolation )</span>
            - ###### <span id="article-5.6.1.3.4">持久性 ( Durability )</span>

        - <span id="article-5.6.1.4">实例讲解</span>

    - ##### 5.6.2 并发控制

        - ##### <span id="article-5.6.2.1">概述</span>
        - ##### <span id="article-5.6.2.2">封锁及其协议</span>
        - ##### <span id="article-5.6.2.3">封锁的粒度</span>
        - ##### <span id="article-5.6.2.4">活锁和死锁</span>
        - ##### <span id="article-5.6.2.5">多版本并发控制</span>

    - ##### 5.6.3 恢复技术

        - ###### <span id="article-5.6.3.1">概述</span>
        - ###### <span id="article-5.6.3.2">数据转储</span>
        - ###### <span id="article-5.6.3.3">登记日志文件</span>
        - ###### <span id="article-5.6.3.4">检查点恢复技术</span>

- #### 5.7 安全性

    - ##### <span id="article-5.7.1">5.7.1 概述</span>
    - ##### <span id="article-5.7.2">5.7.2 视图</span>
    - ##### <span id="article-5.7.3">5.7.3 审计</span>

    - ##### 5.7.4 安全控制
        - ###### <span id="article-5.7.4.1">用户身份鉴别]</span>
        - ###### <span id="article-5.7.4.2">存取控制]</span>
        - ###### <span id="article-5.7.4.3">授权：授予（GRANT）与收回（REVOKE）</span>

    - ##### 5.7.5 数据加密
        - ###### <span id="article-5.7.5.1">存储加密</span>
        - ###### <span id="article-5.7.5.2">传输加密</span>

