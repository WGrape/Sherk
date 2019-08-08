#include <stdio.h>

// 角色: 事务持有者

// 负责: 事务的并发控制

// 使用: locksmith (锁匠)


// 设置事务隔离级别

// Start Transaction
// Rollback Transaction
// Commit Transaction

// 我之前的这种想法是错误的, 只要Start事务, 则每个SQL都必须实时执行, 不能等到Commit的时候再去执行 。
// 因为比如在PHP里面, insert之后, PHP代码要判断新增的数据是否正确, 如果不正确的话就回滚,
/*--------------------------------*/
// 只有接受到Commit Transaction的时候，才去把每个SQL都执行, 这样, 也不用物理执行回滚之类的了 。


