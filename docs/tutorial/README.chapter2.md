## 关系型数据库系统的基础理论

### 1. 前言
- [1.1 图解数据库](#article-1.1)

- [1.2 数据库的发展历史](#article-1.2)

- 1.3 数据库的4个基本概念

    - [1.3.1 数据](#article-1.3.1)
    - [1.3.2 数据库](#article-1.3.2)
    - [1.3.3 数据库管理系统](#article-1.3.3)
    - [1.3.4 数据库系统](#article-1.3.4)

### 2. 深入理解数据库系统

- 2.1 数据模型的概念

    - [2.1.1 什么是数据模型](#article-2.1.1)

    - 2.1.2 数据模型的组成 3 要素

        - [数据结构](#article-2.1.2.1)
        - [数据操作](#article-2.1.2.2)
        - [数据的完整性约束条件](#article-2.1.2.3)

    - 2.1.3 两类数据模型

        - [概念数据模型](#article-2.1.3.1)
        - [物理数据模型](#article-2.1.3.2)

    - 2.1.4 概念数据模型

        - [实体](#article-2.1.4.1)
        - [属性](#article-2.1.4.2)
        - [码](#article-2.1.4.3)
        - [实体型](#article-2.1.4.4)
        - [实体集](#article-2.1.4.5)
        - [联系](#article-2.1.4.6)

   - 2.1.5 三种重要的物理数据模型

        - [层次模型](#article-2.1.5.1)
        - [网状模型](#article-2.1.5.2)
        - [关系模型](#article-2.1.5.3)

- 2.2 基于不同物理数据模型的3种数据库系统
    - [2.2.1 层次数据库系统 - 基于层次模型](#article-2.2.1)
    - [2.2.2 网状数据库系统 - 基于网状模型](#article-2.2.2)
    - [2.2.3 关系数据库系统 - 基于关系模型](#article-chapter-4)

- 2.3 数据库系统的三级模式概述及结构
    - [2.3.1 概述](#article-2.3.1)
    - [2.3.2 外模式](#article-2.3.2)
    - [2.3.3 模式](#article-2.3.3)
    - [2.3.4 内模式](#article-2.3.4)

- 2.4 数据库系统的特点

- 2.5 常用的数据库系统分类
    - [2.5.1 关系型数据库](#article-2.5.1)
    - [2.5.2 非关系型数据库（NoSQL）](#article-2.5.2)


### 3. <span id="article-chapter-3">非关系型数据库系统简介</span>

- [3.1 概述](#article-3.1)
- [3.2 非关系型数据库的特点](#article-3.2)
- [3.3 常用的非关系型数据库](#article-3.3)
- [3.4 更多内容](#article-3.4)

### 4. <span id="article-chapter-4">深入理解关系型数据库系统</span>

- 4.1 关系的基础概念

    - [4.1.1 定义](#article-4.1.1)

    - [4.1.2 如何理解关系](#article-4.1.2)

    - 4.1.3 重要的三个组成

        - [关系数据结构](#article-4.1.3.1)
        - [关系操作集合](#article-4.1.3.2)
        - [关系完整性约束](#article-4.1.3.3)

    - 4.1.4 关系模式的数据理论

        - [什么是关系模式](#article-4.1.4.1)

        - 好的关系模式应具有的特点

            - [数据冗余少](#article-4.1.4.2.1)
            - [插入正常](#article-4.1.4.2.2)
            - [更新正常](#article-4.1.4.2.3)
            - [删除正常](#article-4.1.4.2.4)

        - 规范化（关系模式的模式分解）

            - [数据库规范化](#article-4.1.4.3.1)

            - [函数依赖](#article-4.1.4.3.2)

            - [码](#article-4.1.4.3.3)

            - [多值依赖](#article-4.1.4.3.4)

            - 数据库规范化（ 范式 ）分类

                - [第1范式](#article-4.1.4.3.5.1)
                - [第2范式](#article-4.1.4.3.5.2)
                - [第3范式](#article-4.1.4.3.5.3)
                - [第4范式](#article-4.1.4.3.5.4)
                - [第5范式](#article-4.1.4.3.5.5)
                - [第6范式](#article-4.1.4.3.5.6)
                - [BC范式](#article-4.1.4.3.5.7)
                - [DK范式](#article-4.1.4.3.5.8)   
                - [BCNF范式](#article-4.1.4.3.5.9)   
                - [反范式](#article-4.1.4.3.5.10)

    - 4.1.5 关系键

        - [概述](#article-4.1.5.1)

        - 关系键的分类

            - [主键](#article-4.1.5.2.1)
            - [外键](#article-4.1.5.2.2)
            - [超键](#article-4.1.5.2.3)
            - [候选键](#article-4.1.5.2.4)
            - [代理键](#article-4.1.5.2.5)
            - [自然键](#article-4.1.5.2.6)



- 4.2 关系的完整性
    - [4.2.1 概述](#article-4.2.1)
    - [4.2.2 实体完整性](#article-4.2.2)
    - [4.2.3 参照完整性](#article-4.2.3)
    - 4.2.4 自定义完整性

        - [4.2.4.1 属性上的约束](#article-4.2.4.1)

        - [4.2.4.2 元组上的约束](#article-4.2.4.2)

    - [4.2.5 域完整性](#article-4.2.5)

- 4.3 关系的代数运算
    - [4.3.1 集合运算](#article-4.3.1)

    - 4.3.2 关系运算
        - [选择](#article-4.3.2.1)
        - [投影](#article-4.3.2.2)
        - [连接](#article-4.3.2.3)
        - [除](#article-4.3.2.4)



### 5. 关系型数据库系统的理论架构

- #### 5.1 完整性

    - [5.1.1 概述](#article-5.1.1)
    - [5.1.2 实体完整性](#article-5.1.2)
    - [5.1.3 参照完整性](#article-5.1.3)
    - [5.1.4 自定义完整性](#article-5.1.4)
    - [5.1.5 断言（Assertion）](#article-5.1.5)
    - [5.1.6 触发器（Trigger）](#article-5.1.6)

- #### 5.2 数据存储

    - [5.2.1 概述](#article-5.2.1)
    - [5.2.2 磁盘存储](#article-5.2.2)
    - 5.2.3 内存缓存

        - [缓存池](#article-5.2.3.1)

- #### 5.3 数据索引

    - [5.3.1 概述](#article-5.3.1)
    - 5.3.2 索引的分类

        - 5.3.2.1 从逻辑角度

            - [主键索引](#article-5.3.2.1.1)

            - [唯一索引或者非唯一索引](#article-5.3.2.1.2)

            - [多列索引（复合索引）](#article-5.3.2.1.3)

            - [普通索引或者单列索引](#article-5.3.2.1.4)

            - [空间索引](#article-5.3.2.1.5)

        - 5.3.2.2 从物理角度

            - [聚集索引（clustered index）](#article-5.3.2.2.1)

            - [非聚集索引（non-clustered index）](#article-5.3.2.2.2)

        - 5.3.2.3 从数据结构角度

            - [B+树索引](#article-5.3.2.3.1)

            - [Hash索引](#article-5.3.2.3.2)

            - [FULLTEXT索引](#article-5.3.2.3.3)

            - [R-Tree索引（Spatial 索引，即空间索引）](#article-5.3.2.3.4)

    - [5.3.3 索引的创建](#article-5.3.3)


- #### 5.4 查询处理

    - [5.4.1 概述](#article-5.4.1)

    - 5.4.2 查询步骤

        - [查询分析](#article-5.4.2.1)
        - [查询检查](#article-5.4.2.2)
        - [查询优化](#article-5.4.2.3)
        - [查询执行](#article-5.4.2.4)

    - [5.4.3 理解查询计划](#article-5.4.3)

    - 5.4.4 理解查询优化

        - [查询优化概述](#article-5.4.4.1)
        - [实例讲解](#article-5.4.4.2)
        - [优化方法](#article-5.4.4.3)

    - 5.4.5 参数化查询

- #### 5.5 日志系统

- #### 5.6 事务处理

    - ##### 5.6.1 事务

        - [概述](#article-5.6.1.1)
        - [图解事务](#article-5.6.1.2)
        - 事务的 ACID 特性

            - [原子性 ( Atomicity )](#article-5.6.1.3.1)
            - [一致性 ( Consistency )](#article-5.6.1.3.2)
            - [隔离性 ( Isolation )](#article-5.6.1.3.3)
            - [持久性 ( Durability )](#article-5.6.1.3.4)

        - [事务的自动提交](#article-5.6.1.4)

        - [实例讲解](#article-5.6.1.5)

    - ##### 5.6.2 并发控制

        - [概述](#article-5.6.2.1)
        - [封锁及其协议](#article-5.6.2.2)
        - [封锁的粒度](#article-5.6.2.3)
        - [活锁和死锁](#article-5.6.2.4)
        - [多版本并发控制](#article-5.6.2.5)

    - ##### 5.6.3 恢复技术

        - [概述](#article-5.6.3.1)
        - [数据转储](#article-5.6.3.2)
        - [登记日志文件](#article-5.6.3.3)
        - [检查点恢复技术](#article-5.6.3.4)

- #### 5.7 安全性保护

    - [5.7.1 概述](#article-5.7.1)
    - [5.7.2 视图](#article-5.7.2)
    - [5.7.3 审计](#article-5.7.3)

    - 5.7.4 安全控制
        - [用户身份鉴别](#article-5.7.4.1)
        - [存取控制](#article-5.7.4.2)
        - [授权：授予（GRANT）与收回（REVOKE）](#article-5.7.4.3)

    - 5.7.5 数据加密
        - [存储加密](#article-5.7.5.1)
        - [传输加密](#article-5.7.5.2)

- #### 5.8 [数据库的引擎](#article-5.8)

- #### 5.9 数据库的会话连接

    - [5.9.1 概述](#article-5.9.1)

    - [5.9.2 Socket讲解](#article-5.9.2)

    - [5.9.3 会话连接原理](#article-5.9.3)

    - [5.9.4 会话保持原理](#article-5.9.4)

    - [5.9.5 为什么数据库的会话连接非常昂贵（ 耗时 ）？](#article-5.9.5)

- #### 5.10 数据库中的多线程处理

    - [5.10.1 概述](#article-5.10.1)

- #### 5.11 数据库分区（Partition）

    - [5.11.1 概述](#article-5.11.1)

- #### 5.12 数据字典

- #### 杂项

    - ##### 1. [存储过程](#miscellaneous-1)


---

# 正文

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

- ### <span id="article-3.4">3.4 更多内容</span>
    更多详细关于非关系型数据库的理论讲解请看 [《非关系型数据库系统的基础理论》](https://github.com/Lvsi-China/CSTheory/blob/master/docs/nosql.md)

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

            - <span id="article-4.1.4.3.1">数据库规范化</span>
            - <span id="article-4.1.4.3.2">函数依赖</span>
            - <span id="article-4.1.4.3.3">码</span>
            - <span id="article-4.1.4.3.4">多值依赖</span>

            - ###### 数据库规范化（ 范式 ）分类

                - <span id="article-4.1.4.3.5.1">第1范式</span>
                - <span id="article-4.1.4.3.5.2">第2范式</span>
                - <span id="article-4.1.4.3.5.3">第3范式</span>
                - <span id="article-4.1.4.3.5.4">第4范式</span>
                - <span id="article-4.1.4.3.5.5">第5范式</span>
                - <span id="article-4.1.4.3.5.6">第6范式</span>
                - <span id="article-4.1.4.3.5.7">BC范式</span>
                - <span id="article-4.1.4.3.5.8">DK范式</span>
                - <span id="article-4.1.4.3.5.9">BCNF范式</span>
                - <span id="article-4.1.4.3.5.10">反范式</span>

    - #### 4.1.5 关系键

        - ##### 概述
            关系键是关系数据库的重要组成部分。关系键是一个表中的一个或几个属性，用来标识该表的每一行或与另一个表产生联系。

        - ##### 关系键的分类

            - ###### 主键

                主键，又称主码（英语：primary key或unique key）。数据库表中对储存数据对象予以唯一和完整标识的数据列或属性的组合。一个数据表只能有一个主键，且主键的取值不能缺失，即不能为空值（Null）。

                从技术的角度来看，primary key和unique key有很多相似之处。但还是有以下区别：

                作为primary key的域／域组不能为Null。而unique key可以。
                在一个表中只能有一个primary key，而多个unique key可以同时存在。
                更大的区别在逻辑设计上。primary key一般在逻辑设计中用作记录标识，这也是设置primary key的本来用意。而unique key只是为了保证域／域组的唯一性。

            - ###### 外键

                外键（英语：foreign key，台湾译外来键，又称外部键）。
                其实在关系数据库中，每个数据表都是由关系来连系彼此的关系，父数据表（Parent Entity）的主键（primary key）会放在另一个数据表，当做属性以创建彼此的关系，而这个属性就是外键。

                比如，学生跟老师之间是教学的关系，学生数据表会有个属性叫指导老师（FK），而这个值就是对应到老师数据表的老师代号（PK），学生的指导老师就是外键。

            - ###### 超键
            - ###### 候选键
            - ###### 代理键
            - ###### 自然键


- ### 4.2 关系的完整性

    - #### <span id="article-4.2.1">4.2.1 概述</sapn>
    - #### <span id="article-4.2.2">4.2.2 实体完整性</span>
    - #### <span id="article-4.2.3">4.2.3 参照完整性</span>
    - #### <span id="article-4.2.4">4.2.4 自定义完整性</span>

        - ##### <span id="article-4.2.4.1">4.2.4.1 属性上的约束</span>

        - ##### <span id="article-4.2.4.2">4.2.4.2 元组上的约束</span>

    - #### <span id="article-4.2.5">4.2.5 域完整性</span>

- ### 4.3 关系的代数运算

    - #### <span id="article-4.3.1">4.3.1 集合运算</span>

        并运算（∪）、差运算（－）、交运算（∩）、笛卡尔积（×）

    - #### 4.3.2 关系运算

        - ##### <span id="article-4.3.2.1">选择</span>
        - ##### <span id="article-4.3.2.2">投影</span>
        - ##### <span id="article-4.3.2.3">连接</span>
        - ##### <span id="article-4.3.2.4">除</span>

- ### 4.4 SQL

    - #### <span id="article-4.4.1">概述</span>
        SQL 是一种结构化查询语言，是一种特定目的编程语言，用于管理关系数据库管理系统（RDBMS），或在关系流数据管理系统（RDSMS）中进行流处理。

        SQL基于关系代数和元组关系演算，包括一个数据定义语言和数据操纵语言。SQL的范围包括数据插入、查询、更新和删除，数据库模式创建和修改，以及数据访问控制。尽管SQL经常被描述为，而且很大程度上是一种声明式编程（4GL），但是其也含有过程式编程的元素。

    - #### SQL结构化查询语言的分类

        - #### <span id="article-4.4.2.1">数据查询语言（DQL）</span>
            数据查询语言（Data Query Language, DQL）是SQL语言中，负责进行数据查询而不会对数据本身进行修改的语句，这是最基本的SQL语句。DQL的主要功能是查询数据，本身核心指令为SELECT，为了进行精细的查询，加入了各类辅助指令。
            [具体见维基百科定义](https://zh.wikipedia.org/wiki/%E6%95%B0%E6%8D%AE%E6%9F%A5%E8%AF%A2%E8%AF%AD%E8%A8%80)

        - #### <span id="article-4.4.2.2">数据定义语言（DDL） </span>
            数据定义语言（Data Definition Language，DDL）是SQL语言集中负责数据结构定义与数据库对象定义的语言，由CREATE、ALTER与DROP三个语法所组成，最早是由Codasyl（Conference on Data Systems Languages）数据模型开始，现在被纳入SQL指令中作为其中一个子集。
            [具体见维基百科定义](https://zh.wikipedia.org/wiki/%E8%B3%87%E6%96%99%E5%AE%9A%E7%BE%A9%E8%AA%9E%E8%A8%80)

        - #### <span id="article-4.4.2.3">数据操纵语言（DML）</span>
            数据操纵语言（Data Manipulation Language, DML）是用于数据库操作，对数据库其中的对象和数据运行访问工作的编程语句，通常是数据库专用编程语言之中的一个子集，例如在信息软件产业通行标准的SQL语言中，以INSERT、UPDATE、DELETE三种指令为核心，分别代表插入(意指新增或创建)、更新(修改)与删除(销毁)。在使用数据库的系统开发过程中，其中应用程序必然会使用的指令；而加上 SQL的SELECT语句，欧美地区的开发人员把这四种指令，以“CRUD”(分别为 Create, Read, Update, Delete英文四前缀字母缩略的术语)来称呼；而亚洲地区使用汉语的开发人员，或可能以四个汉字：增 查 改 删 来略称。

            DML 的主要功能即是访问数据，因此其语法都是以读取与写入数据库为主，除了INSERT以外，其他指令都可能需搭配WHERE指令来过滤数据范围，或是不加WHERE指令来访问全部的数据。[具体见维基百科定义](https://zh.wikipedia.org/wiki/%E8%B3%87%E6%96%99%E5%AE%9A%E7%BE%A9%E8%AA%9E%E8%A8%80)
<br/>


## 5. 关系型数据库系统的理论架构

- #### 5.1 完整性

    - ##### <span id="article-5.1.1">5.1.1 概述</span>
        完整性是通过约束来实现的 。<br/>
        数据库完整性（Database Integrity）是指数据库中数据在逻辑上的一致性、正确性、有效性和相容性。数据库完整性由各种各样的```完整性约束```来保证，因此可以说数据库完整性设计就是数据库完整性约束的设计。数据库完整性约束可以通过DBMS或应用程序来实现，基于DBMS的完整性约束作为模式的一部分存入数据库中。通过DBMS实现的数据库完整性按照数据库设计步骤进行设计，而由应用软件实现的数据库完整性则纳入应用软件设计。

    - ##### <span id="article-5.1.2">5.1.2 实体完整性</span>
        实体完整性指表中行的完整性。主要用于保证操作的数据（记录）非空、唯一且不重复。即实体完整性要求每个关系（表）有且仅有一个主键，每一个主键值必须唯一，而且不允许为“空”（NULL）或重复。

    - ##### <span id="article-5.1.3">5.1.3 参照完整性</span>

        - ###### 概述
            属于表间规则。对于永久关系的相关表，在更新、插入或删除记录时，如果只改其一，就会影响数据的完整性。如删除父表的某记录后，子表的相应记录未删除，致使这些记录称为孤立记录。对于更新、插入或删除表间数据的完整性，统称为参照完整性。通常，在客观现实中的实体之间存在一定联系，在关系模型中实体及实体间的联系都是以关系进行描述，因此，操作时就可能存在着关系与关系间的关联和引用。
            在关系数据库中，关系之间的联系是通过公共属性实现的。这个公共属性经常是一个表的主键，同时是另一个表的外键。参照完整性体现在两个方面：实现了表与表之间的联系，外键的取值必须是另一个表的主键的有效值，或是“空”值。

        - ###### 参照完整性检车和违约处理
            参照完整性将两个表中的相应元组联系起来了。因此，对被参照表和参照表进行增删改操作时有可能破坏参照完整性，必须进行检查以保证这两个表的相容性。

            当不一致发生时，系统可以参与以下策略加以处理。
            * 拒绝（No Action）执行
            不允许该操作执行。该操作一般设置为默认策略。

            * 级联（Cascade）操作
            当删除或修改被参照表的一个元组导致与参照表的不一致时，删除或修改参照表中的所有导致不一致的元组。

            * 设置为空值
            当删除或修改被参照表的一个元组是造成了不一致，则将参照表中的所有造成不一致的元组的对应属性设置为空值。

    - ##### <span id="article-5.1.4">5.1.4 自定义完整性</span>

        - ###### 概述
            用户定义的完整性就是针对某一具体应用的数据必须满足的语义要求。

        - ###### 属性上的约束条件和违约处理
            当往表中插入元组或修改属性的值时，关系数据库管理系统将检查元组上的约束条件是否被满足，如果不满足则操作被拒绝执行。

        - ###### 元组上的约束条件和违约处理
            当往表中插入元组或修改属性的值时，关系数据库管理系统将检查元组上的约束条件是否被满足，如果不满足则操作被拒绝执行。

    - ##### <span id="article-5.1.5">5.1.5 断言（Assertion）</span>
        断言创建以后，任何对断言中所涉及关系的操作都会触发关系数据库系统对断言的检查，任何使断言不为真值的操作都会被拒绝执行。

    - ##### <span id="article-5.1.5">5.1.6 触发器（Trigger）</span>
        实现数据库完整性的一个重要方法是触发器，触发器（Trigger）是用户定义在关系表上的一类由事件驱动的特殊过程。一旦定义，触发器将被保存在数据库服务器中。任何用户对表的```增删改```操作均由服务器自动激活相应的触发器，在关系数据库管理系统核心层进行集中的完整性控制。触发器类似于约束，但是比约束更灵活，可以试试更复杂的检查和操作，具有更精细和更强大的数据控制能力。

- #### 5.2 数据存储

    - ##### <span id="article-5.2.1">5.2.1 概述</span>

    - ##### 5.2.2 磁盘存储

        - ###### <span id="article-5.2.2.1">内存缓存</span>
        - ###### <span id="article-5.2.2.2">缓存池</span>

- #### 5.3 数据索引

    - ##### 5.3.1 <span id="article-5.3.1">概述</span>
        数据库索引（Database Index），本质上是一种数据结构，一种排序的数据结构。只不过这种数据结构可以快速定位数据，而无需在每次访问数据库表时搜索数据库表中的每一行，以协助快速查询、更新数据库表中数据。可以在数据表的一列或多列上创建索引。

        > * 索引是在存储引擎（Storage Engine）层面实现的，而不是server层面。因此==不是所有的存储引擎都支持所有的索引类型。==
        > * 即使多个存储引擎支持某一索引类型，它们的实现和行为也可能有所差别。

        索引原理可查看此文章[MySQL索引背后的数据结构及算法原理](http://blog.codinglabs.org/articles/theory-of-mysql-index.html)

         <img height="150px" src="https://github.com/Lvsi-China/Sherk/raw/master/extra/image/chapter2/mysql-index-theory.png">

    - ##### 5.3.2 <span id="article-5.3.2">索引的分类</span>

        - ###### <span id="article-5.3.2.1">5.3.2.1 从逻辑角度</span>

            - ###### <span id="article-5.3.2.1.1">主键索引</span>
                主键索引是一种特殊的唯一索引，不允许有空值

            - ###### <span id="article-5.3.2.1.2">唯一索引或者非唯一索引</span>

            - ###### <span id="article-5.3.2.1.3">多列索引（复合索引）</span>
                复合索引指多个字段上创建的索引，只有在查询条件中使用了创建索引时的第一个字段，索引才会被使用。使用复合索引时遵循最左前缀集合

            - ###### <span id="article-5.3.2.1.4">普通索引或者单列索引</span>

            - ###### <span id="article-5.3.2.1.5">空间索引（用于对GIS数据类型创建SPATIAL索引）</span>
                空间索引是对空间数据类型的字段建立的索引，MYSQL中的空间数据类型有4种，分别是GEOMETRY、POINT、LINESTRING、POLYGON。
                MYSQL使用SPATIAL关键字进行扩展，使得能够用于创建正规索引类型的语法创建空间索引。创建空间索引的列，必须将其声明为NOT NULL，空间索引只能在存储引擎为MYISAM的表中创建

        - ###### <span id="article-5.3.2.2">5.3.2.2 从物理角度</span>

            - ###### <span id="article-5.3.2.2.1">聚集索引（clustered index）</span>

                一种索引，该索引中键值的逻辑顺序决定了表中相应行的物理顺序。
                聚集索引确定表中数据的物理顺序。聚集索引类似于电话簿，后者按姓氏排列数据。由于聚集索引规定数据在表中的物理存储顺序，因此一个表只能包含一个聚集索引。但该索引可以包含多个列（组合索引），就像电话簿按姓氏和名字进行组织一样。

                聚集索引对于那些经常要搜索范围值的列特别有效。使用聚集索引找到包含第一个值的行后，便可以确保包含后续索引值的行在物理相邻。例如，如果应用程序执行 的一个查询经常检索某一日期范围内的记录，则使用聚集索引可以迅速找到包含开始日期的行，然后检索表中所有相邻的行，直到到达结束日期。这样有助于提高此 类查询的性能。同样，如果对从表中检索的数据进行排序时经常要用到某一列，则可以将该表在该列上聚集（物理排序），避免每次查询该列时都进行排序，从而节 省成本。
                　　　　
                当索引值唯一时，使用聚集索引查找特定的行也很有效率。例如，使用唯一雇员 ID 列 emp_id 查找特定雇员的最快速的方法，是在 emp_id 列上创建聚集索引或 PRIMARY KEY 约束。

                 <img height="500px" src="https://github.com/Lvsi-China/Sherk/raw/master/extra/image/chapter2/clustered-index.JPG">

            - ###### <span id="article-5.3.2.2.2">非聚集索引（non-clustered index）</span>

                一种索引，该索引中索引的逻辑顺序与磁盘上行的物理存储顺序不同。

                索引是通过二叉树的数据结构来描述的，我们可以这么理解聚簇索引：索引的叶节点就是数据节点。而非聚簇索引的叶节点仍然是索引节点，只不过有一个指针指向对应的数据块。如下图：

                 <img height="500px" src="https://github.com/Lvsi-China/Sherk/raw/master/extra/image/chapter2/non-clustered-index.JPG">

        - ###### <span id="article-5.3.2.3">5.3.2.3 从数据结构角度</span>

            - ###### <span id="article-5.3.2.3.1">B+树索引 [ O(log(n)) ] </span>\
                关于B+树索引，参考 [MySQL索引背后的数据结构及算法原理](http://blog.codinglabs.org/articles/theory-of-mysql-index.html)

            - ###### <span id="article-5.3.2.3.2">Hash索引</span>
                * 仅仅能满足"=","IN"和"<=>"查询，不能使用范围查询
                * 其检索效率非常高，索引的检索可以一次定位，不像B-Tree 索引需要从根节点到枝节点，最后才能访问到页节点这样多次的IO访问，所以 Hash 索引的查询效率要远高于B-Tree 索引
                * 只有Memory存储引擎显示支持hash索引

            - ###### <span id="article-5.3.2.3.3">FULLTEXT索引（全文索引）</span>
                主要用来查找文本中的关键字，而不是直接与索引中的值相比较。Full-text索引跟其它索引大不相同，它更像是一个搜索引擎，而不是简单的WHERE语句的参数匹配。你可以对某列分别进行full-text索引和B-Tree索引，两者互不冲突。Full-text索引配合MATCH AGAINST操作使用，而不是一般的WHERE语句加LIKE。

            - ###### <span id="article-5.3.2.3.4">R-Tree索引（Spatial 索引，即空间索引）</span>

                用于对GIS数据类型创建SPATIAL索引 ，但是只有MyISAM引擎支持，并且支持的不好。可以忽略。

    - ##### 5.3.3 <span id="article-5.3.3">索引的创建</span>

        ```
        CREATE TABLE table_name[col_name data type]
        [unique|fulltext|spatial][index|key][index_name](col_name[length])[asc|desc]
        ```

        1、unique|fulltext|spatial为可选参数，分别表示唯一索引、全文索引和空间索引；

        2、index和key为同义词，两者作用相同，用来指定创建索引

        3、col_name为需要创建索引的字段列，该列必须从数据表中该定义的多个列中选择；

        4、index_name指定索引的名称，为可选参数，如果不指定，MYSQL默认col_name为索引值；

        5、length为可选参数，表示索引的长度，只有字符串类型的字段才能指定索引长度；

        6、asc或desc指定升序或降序的索引值存储

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

    - ##### 5.4.5 参数化查询
        参数化查询（Parameterized Query或Parameterized Statement）是指在设计与数据库链接并访问数据时，在需要填入数值或数据的地方，使用参数（Parameter）来给值，这个方法目前已被视为最有效可预防SQL注入攻击的攻击手法的防御方式。

        除了安全因素，相比起拼接字符串的SQL语句，参数化的查询往往有性能优势。因为参数化的查询能让不同的数据通过参数到达数据库，从而公用同一条SQL语句。大多数数据库会缓存解释SQL语句产生的字节码而省下重复解析的开销。如果采取拼接字符串的SQL语句，则会由于操作数据是SQL语句的一部分而非参数的一部分，而反复大量解释SQL语句产生不必要的开销。

        ```原理```：在使用参数化查询的情况下，数据库服务器不会将参数的内容视为SQL指令的一部分来处理，而是在数据库完成SQL指令的编译后，才套用参数运行，因此就算参数中含有具破坏性的指令，也不会被数据库所运行。

- #### 5.5 日志系统

- #### 5.6 事务处理

    - ##### 5.6.1 事务

        - ##### <span id="article-5.6.1.1">概述</span>
            事务是应用程序中一系列严密的操作，所有操作必须成功完成，否则在每个操作中所作的所有更改都会被撤消。也就是事务具有原子性，一个事务中的一系列的操作要么全部成功，要么一个都不做。
            事务的结束有两种，当事务中的所以步骤全部成功执行时，事务提交。如果其中一个步骤失败，将发生回滚操作，撤消撤消之前到事务开始时的所以操作。

        - ##### <span id="article-5.6.1.2">图解事务</span>

        - ##### <span id="article-5.6.1.3">事务的 ACID 特性</span>

            - ###### <span id="article-5.6.1.3.1">原子性 ( Atomicity )</span>
                是指一个事务中包含的所有操作，要么全做，要么全不做。

            - ###### <span id="article-5.6.1.3.2">一致性 ( Consistency )</span>
                数据一致性是指数据的可用性，指数据库从一个一致性状态转移到另一个一致性状态，只包含已提交的事务，如果某些事务尚未完成被迫中断，而该事务对数据库的修改已经写入物理数据库，此时数据库处于一个不正确的状态。 保证数据一致性是对数据库的最基本的要求，也是数据库事务的最基本要求。

                - ###### 常见的不一致性
                    1.更新丢失（丢失修改） 2.不可重复读 3.脏读 4.幻读<br>
                    如：比如A向B转账，不可能A扣了钱，B却没收到。   

            - ###### <span id="article-5.6.1.3.3">隔离性 ( Isolation )</span>

                隔离性是指各个事务的执行不能其它事务干扰。即一个事务内部的操作及使用的数据对其它并发事务是隔离的。

                隔离级别是指一个事务必须与由其他事务进行的资源或数据更改相隔离的程度。

                > 常见的4种隔离级别：
                >
                > ① Read uncommitted（读未提交）
                >
                > ② Read Committed（读取提交内容）
                >
                > ③ Repeatable Read（可重读）
                >
                > ④ Serializable（可串行化）
                >

                事务并发会引起数据的不一致性，故使用不同的隔离级别以保证事务并发下的数据一致性。因此数据的一致性和不同的隔离级别有关，大致如下图。<br>

                <img height="300px" src="https://github.com/Lvsi-China/Sherk/raw/master/extra/image/chapter2/isolationLevel-1.jpeg">

            - ###### <span id="article-5.6.1.3.4">持久性 ( Durability )</span>

                在事务完成以后，该事务对数据库所作的更改便持久的保存在数据库之中，并不会被回滚。

        - ##### <span id="article-5.6.1.4">事务的自动提交</span>
            mysql默认采用```AutoCommit```模式，也就是说```每个sql都是一个事务，每个事务会被自动提交，并不需要我们去显示的执行事务。```
            如果autoCommit关闭，则每个sql都默认开启一个事务，而且只有当我们显式的执行```commit```后这个事务才会被提交。

            ```
            show variables like "autocommit";

            set autocommit=0; // 0表示关闭AutoCommit
            set autocommit=1; // 1表示开启AutoCommit
            ```

        - ##### <span id="article-5.6.1.5">实例讲解</span>

    - ##### 5.6.2 并发控制

        - ##### <span id="article-5.6.2.1">概述</span>

            - ###### 数据库并发
                原子操作或者事务操作对数据库进行并发操作，如果使用不正当的并发处理，数据就会出现严重的不一致性问题。

            - ###### 数据库并发的分类和特点
                数据库的并发操作只有两种：① 并发的原子操作  ② 并发的事务操作 <br>
                这两个不同的并发的操作的特点是：① 原子操作需要我们自己手动封锁
                ② 事务操作则不需要我们手动封锁

        - ##### <span id="article-5.6.2.2">封锁及其协议</span>

            - ###### 封锁
                封锁是实现并发控制的一个非常重要的技术 。基本的封锁类型有2种：① 排他锁（Exclusive），又称为写锁 ② 共享锁（Share），又称为读锁

            - ###### 封锁协议
                在运用 X 锁和 S 锁这两种基本封锁对数据对象加锁时，还需要约定一些规则，例如，何时申请 X 锁 或 S 锁、持续时间、何时释放等。这些规则就称为封锁协议（Locking Protocol）。

                - 一级封锁协议：
                  事务T在修改数据R之前必须先对其加X锁，知道事务结束才释放。事务结束包括正常结束（Commit）和非正常结束（RollBack）

                - 二级封锁协议：
                  在一级封锁协议的基础上上增加事务T在读取数据R之前必须先对其加S锁，读完后即可释放 S 锁 。

                - 三级封锁协议：
                  在一级封锁协议的基础上增加事务T在读取数据R之前必须先对其加S锁，直到事务结束才释放。  

                  <table align="center">
                    <tr>
                        <td rowspan="2" ></td>
                        <td colspan="2" >X 锁</td>
                        <td colspan="2" >S 锁</td>
                        <td colspan="3" >一致性保证</td>
                    </tr>
                    <tr>
                        <td>操作结束释放</td>
                        <td>事务结束释放</td>
                        <td>操作结束释放</td>
                        <td>事务结束释放</td>
                        <td>不丢失修改</td>
                        <td>不读脏数据</td>
                        <td>可重复读</td>
                    </tr>
                    <tr align="center">
                     <td>一级封锁协议</td>
                     <td></td>
                     <td>√</td>
                     <td></td>
                     <td></td>
                     <td>√</td>
                     <td></td>
                     <td></td>
                    </tr>
                    <tr align="center">
                     <td>二级封锁协议</td>
                     <td></td>
                     <td>√</td>
                     <td>√</td>
                     <td></td>
                     <td>√</td>
                     <td>√</td>
                     <td></td>
                    </tr>
                    <tr align="center">
                      <td>三级封锁协议</td>
                      <td></td>
                      <td>√</td>
                      <td></td>
                      <td>√</td>
                      <td>√</td>
                      <td>√</td>
                      <td>√</td>
                    </tr>
                  </table>表格来自《数据库系统概论》第5版 - 王珊

                    上述三级协议的主要区别在于什么操作需要申请封锁，以及何时封锁（即持锁时间）。不同的封锁协议是为了保证数据的一致性。

        - ##### <span id="article-5.6.2.3">封锁的粒度</span>

            封锁对象的大小称为封锁粒度（Granularity），主要有行级锁，表级锁。

            封锁的对象可以是逻辑单元，也可以是物理单元。以关系数据库为例子，封锁对象可以是这样一些逻辑单元：属性值、属性值的集合、元组、关系、索引项、整个索引项直至整个数据库；也可以是这样的一些物理单元：页（数据页或索引页）、物理记录等。

        - ##### <span id="article-5.6.2.4">排他锁和共享锁</span>
            ```排他锁```：又称为写锁、独占锁、X锁，是一种基本的锁类型。一个事务对一个表(行)进行加锁之后，那么其他事务就不能加上任何的锁。

            若事务T对数据对象A加上X锁，则只允许T读取和修改A，其他任何事务都不能再对A加任何类型的锁，直到T释放A上的锁。这就保证了其他事务在T释放A上的锁之前不能再读取和修改A。

            ```共享锁```：又称为读锁、S锁，可以查看但无法修改和删除的一种数据锁。当一个事务执行时对表(行)进行操作时加锁，其它事务也可对此表(行)进行加锁。

            若事务T对数据对象A加上S锁，则事务T只能读A；其他事务只能再对A加S锁，而不能加X锁，直到T释放A上的S锁。这就保证了其他事务可以读A， 但在T释放A上的S锁之前不能对A做任何修改。

            ```区别```
            1. 共享锁（S锁）：如果事务T对数据A加上共享锁后，则其他事务只能对A再加共享锁，不能加排他锁。获准共享锁的事务只能读数据，不能修改 据。
            排他锁（X锁）：如果事务T对数据A加上排他锁后，则其他事务不能再对A加任任何类型的封锁。获准排他锁的事务既能读数据，又能修改数据。
            2. 共享锁下其它用户可以并发读取，查询数据。但不能修改，增加，删除数据。

        - ##### <span id="article-5.6.2.4">活锁和死锁</span>
            活锁：一直处于等待（一直在做无用功）。
            避免或所的简单方法是采用先来先服务的策略。

            死锁：都处于阻塞状态，都在等待对方释放锁。
        - ##### <span id="article-5.6.2.5">多版本并发控制（MultiVersion Concurrency Control，MVCC）</span>
            是指在数据库中通过维护数据对象的多个版本信息来实现高效并发控制的一种策略。

            版本（Version）是指数据库中数据对象的一个快照，记录了数据对象某个时刻的状态。

    - ##### 5.6.3 恢复技术

        - ###### <span id="article-5.6.3.1">概述</span>
            具有把数据库从错误状态恢复到某一已知的正确状态（亦成为一致状态或完整状态）的功能，这就是数据库的恢复。

        - ###### <span id="article-5.6.3.2">数据转储</span>
            数据转储是数据库恢复中采用的基本技术。所谓转储是指定期地将整个数据库复制到磁带、磁盘或其他存储介质上保存起来的过程

        - ###### <span id="article-5.6.3.3">登记日志文件</span>

        - ###### <span id="article-5.6.3.4">检查点恢复技术</span>

- #### 5.7 安全性保护

    - ##### <span id="article-5.7.1">5.7.1 概述</span>
        数据库的安全性是指保护数据库以防止不合法使用所造成的的数据泄露、更改或破坏。

    - ##### <span id="article-5.7.2">5.7.2 视图</span>
        ```概述```<br/>
        视图（View）是在关系数据库中，将一组查询指令构成的结果集，组合成可查询的数据表的一种数据库对象。与数据表不同的是，数据表是一种实体结构(Physical Structure)，但视图是一种虚拟结构(Virtual Structure)，在实体数据表中的改变都可以立刻反映在视图中，不过部分数据库管理系统也支持具更新能力的视图(Updatable View)。   视图可视为数据表，具有 JOIN 的能力。
        数据库中只需要存储定义，无须存储数据。

        ```视图优势```<br/>
        可以将实体数据表隐藏起来，让外部程序的设计师无法得知实际的数据结构，降低数据库被攻击的风险。
        在多数的情况下，视图是只读的，外部程序无法直接透过视图修改数据(具更新能力的视图除外)。
        简化查询，数据库管理员可以将高度复杂的查询，包装在视图中，外部程序只需要直接访问该视图即可取出需要的数据。
        在视图中先行运行运算。

    - ##### <span id="article-5.7.3">5.7.3 审计</span>
        审计功能把用户对数据库的所有操作自动记录下来放入审计日志中。审计员可以利用审计日志监控数据库中的各种行为，重视导致数据库现有状况的一系列事件，找出非法存取数据的人、时间和内容等。

    - ##### 5.7.4 安全控制
        - ###### <span id="article-5.7.4.1">用户身份鉴别]</span>
        - ###### <span id="article-5.7.4.2">存取控制]</span>
        - ###### <span id="article-5.7.4.3">授权：授予（GRANT）与收回（REVOKE）</span>

    - ##### 5.7.5 数据加密
        - ###### <span id="article-5.7.5.1">存储加密</span>
        - ###### <span id="article-5.7.5.2">传输加密</span>

- #### <span id="article-5.8">5.8 数据库的引擎</span>

    面对用户对数据的不同需求，通常构建不同的数据库引擎以供用户的自由选择。
    数据库引擎是用于存储、处理和保护数据的核心服务。利用数据库引擎可控制访问权限并快速处理事务，从而满足企业内大多数需要处理大量数据的应用程序的要求。 使用数据库引擎创建用于联机事务处理或联机分析处理数据的关系数据库。这包括创建用于存储数据的表和用于查看、管理和保护数据安全的数据库对象（如索引、视图和存储过程）。

    ```Oracle没有数据库引擎的概念```<br/>
    oracle中不存在引擎的概念，数据处理大致可以分成两大类：联机事务处理OLTP（on-line transaction processing）、联机分析处理OLAP（On-Line Analytical Processing）。OLTP是传统的关系型数据库的主要应用，主要是基本的、日常的事务处理，例如银行交易。OLAP是数据仓库系统的主要应用，支持复杂的分析操作，侧重决策支持，并且提供直观易懂的查询结果。

    OLTP 系统强调数据库内存效率，强调内存各种指标的命令率，强调绑定变量，强调并发操作；
    OLAP 系统则强调数据分析，强调SQL执行市场，强调磁盘I/O，强调分区等。

    ```Mysql常见的数据库引擎```
    * MYISAM

    * InnoDB


- #### 5.9 与数据库的会话连接

    - ##### <span id="article-5.9.1">5.9.1 概述</span>

    - ##### <span id="article-5.9.2">5.9.2 Socket讲解</span>
        Socket（插座）即网络套接字，也就是网络接口

    - ##### <span id="article-5.9.3">5.9.3 会话连接原理</span>

    - ##### <span id="article-5.9.4">5.9.4 会话保持原理</span>

    - ##### <span id="article-5.9.5">5.9.5 为什么数据库的会话连接非常昂贵（ 耗时 ）？</span>

        内容来自 [为什么数据库连接很“昂贵"](https://github.com/onlyliuxin/coding2017/issues/451#issuecomment-310850287)
        >
        > # 数据库连接
        > 我们都知道数据库连接创建的开销很大，但是数据库连接的原理是什么呢？到底是哪个环节导致了开销的出现？我还有点懵逼，所以搞懂数据库连接是个重要的问题。
        > 一个数据库连接的流程是这样的：
        >
        > 1. 应用程序的数据访问层请求DataSource来获取一个数据库连接。
        > 2. DataSource使用数据库驱动来打开一个数据库连接。
        > 3. 创建数据库连接，同时打开了一个TCP socket。
        > 4. 应用程序进行数据库的读写。
        > 5. 连接已经不再需要了，因此关闭它。
        > 6. 关闭socket。
        >
        > 我们有一个示意图可以看：
        > ![](https://camo.githubusercontent.com/9ca33c7bdedd18cc7c8e2f483389291c3a9dda1c/687474703a2f2f696e63646e312e62302e7570616979756e2e636f6d2f323031342f30352f32313431343637333462623963306535373566643232333261363331373732342e706e67)
        >
        > # 开销分析
        > ## 连接层面
        > 从前面的示意图可以看出，基本步骤只有6个，而且我们知道，一些基本的步骤之下往往有很多的基础操作作支撑，每一个都可能成为开销的来源，尤其是在建立TCP连接的时候，需要经过多层的网络协议进行协助，此外还需要：
        >
        > 1. 校验用户的身份证书
        > 2. 在数据库驱动期望的代码页设置和数据库可用的代码页设置之间进行协商
        > 3. 获取数据库版本信息
        > 4. 确定用于通信的最理想的数据库协议包大小
        > 5. 设置会话设置
        >
        > 这些额外的流程其实是在保证数据库最重要的两个点：**安全** 和 **稳定**。如果我们需要一个安全的数据库，那么首先我们就要校验操作对象的身份，是否拥有数据库的操作权限，然后在连接中保持用户的状态权限，这就需要操作服务器的session，然后和发起连接的主机进行数据传递参数的适配，以保证返回正确的数据。
        >
        > ## 存储层面
        > 第一点是我们知道即使是一个连接的操作，数据库也是要访问相应的表来确定访问对象的，这就涉及到了查表的操作，而大型数据库的表往往不会完全存在缓存里，这就需要到存储结构中区查询，也就是会产生I/O操作，而I/O操作也是拉慢速度的一大根源。
        > 第二点是当我们数据库的连接比较多的时候，存在缓存中的页就会很有限，从而使数据库连接的访问呢发生不命中，这时候数据库往往需要到磁盘上去把对应的数据调度出来，供连接使用，I/O操作的缓慢就很明显了。
        >
        > # 总结
        > 数据库连接的开销在于多层的调用，以及一些耗时操作（I/O，TCP连接），为了保证数据库的安全，各种校验方式也在不同程度上带来了开销，所以说数据库连接的花费相当“昂贵”。
        > 从另一个方面想，我们把线程池和数据库连接池放在一起对比的时候，常常会误认为线程和连接会是同一个形式的东西，但是事实上并不是这样，线程是由计算机硬件来实现的分时调度的一个逻辑概念，是接近系统底层的，而数据库连接是基于TCP连接的一个应用层的由数据库应用实现的一个协议，或者说是一个功能，和我们寻常的网络传输，比如聊QQ，是同样性质的东西，所以其中建立一个数据库连接是要设计OSI应用层以下各个层次的配合才能实现的，网络传输的建立和磁盘I/O的速率限制相加，再加上数据库应用本身的身份校验和数据校验，就让一个数据库连接变得十分消耗。

        在实践中，通常使用[数据库连接池](https://baike.baidu.com/item/%E6%95%B0%E6%8D%AE%E5%BA%93%E8%BF%9E%E6%8E%A5%E6%B1%A0)技术来解决数据库连接开销大的问题 。

        <img height="200px" src="https://github.com/Lvsi-China/Sherk/raw/master/extra/image/chapter2/connection-pool.jpg">

- #### <span id="article-5.10">5.10 数据库中的多线程处理</span>

    - #### <span id="article-5.10.1">5.10.1 概述</span>
        程序的模型可以采用单进程多线程模型和多进程单线程模型 。

- #### 5.11 数据库分区（Partition）

    - 5.11.1 <span id="article-5.10">概述</span>span>
       数据库分区是一种物理数据库设计技术，DBA和数据库建模人员对其相当熟悉。虽然分区技术可以实现很多效果，但其主要目的是为了在特定的SQL操作中减少数据读写的总量以缩减响应时间。

       简单点说：在扫描操作中，如果数据库系统知道哪个分区中才包含特定查询中需要的数据，它就能直接去扫描那些特定分区中的数据，而不用浪费很多时间扫描不需要的地方了。

       举例子：有一个百万行的表划分为10个分区，每个分区就包含十万行数据，那么查询分区需要的时间仅仅是全表扫描的十分之一了，很明显的对比。同时对十万行的表建立索引的速度也会比百万行的快得多得多。如果你能把这些分区建立在不同的磁盘上，这时候的I/O读写速度就“不堪设想”（没用错词，真的太快了，理论上100倍的速度提升啊，这是多么快的响应速度啊，所以有点不堪设想了）了。

       分区技术可以让DBA对数据的管理能力提升。通过优良的分区，DBA可以简化特定数据操作的执行方式。例如：DBA在对某些分区的内容进行删除的同时能保证余下的分区的数据完整性(这是跟对表的数据删除这种大动作做比较的)。
       此外分区是由MySQL系统直接管理的，DBA不需要手工的去划分和维护。如果你是DBA，只要你划分了分区，那么之后你就几乎不需要维护分区了。

       > 其实，分区和分表的目的都是一样的，都是为了优化提升数据库的查询响应速度。
       > 当然，分区是由数据库自动完成的，分表则是需要我们自己手动完成操作的。

- #### 5.12 数据字典

- #### 杂项

    - ##### 1. 存储过程

        储存程序 (Stored Procedure)，又可称预储程序或者存储过程，是一种在数据库中存储复杂程序，以便外部程序调用的一种数据库对象，它可以视为数据库中的一种函数或子程序。

        ```优点```<br>
        预存程序可封装，并隐藏复杂的商业逻辑。
        预存程序可以回传值，并可以接受参数。
        预存程序无法使用 SELECT 指令来运行，因为它是子程序，与视图，数据表或用户定义函数不同。
        预存程序可以用在数据检验，强制实行商业逻辑等。

        ```缺点```<br>
        预存程序，往往定制于特定的数据库上，因为支持的编程语言不同。当切换到其他厂商的数据库系统时，需要重写原有的预存程序。预存程序的性能调校与撰写，受限于各种数据库系统。