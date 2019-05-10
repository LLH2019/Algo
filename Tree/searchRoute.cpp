/*
    首先初始化条件 
    一个空栈、一个二叉树根节点、给定需要搜索值
    整个解题思路：  先遍历左子树、判断该路径上有无给定节点值，接着进行出栈处理，接着再遍历右子树
    注意点： 栈中保存的节点一定不为null，在对哪些节点需要出栈时，其中都是取栈中元素
*/
void searchRoute(BiTNode* bt, TElemType data) {
    stack<BiTree> s;
    // 当栈不为空且遍历节点不为null时才继续循环
    while(bt != nullptr || !s.empty()) {
        // 遍历左子树
        while(bt != nullptr && bt->data != data) {
            s.push(bt);
            bt->tag = 0;
            bt = bt->lchild;
        }
        // 如果找到节点
        if(bt->data == data) {
            // 出栈得到路径
            while(!s.empty()) {
                BiTree p = s.top();
                cout << p->data << " ";
                s.pop();
            }
        }
        // 对栈中的节点进行出栈处理， 注意是栈中节点
        while(!s.empty() && s.top()->tag==1) {
            s.pop();
        }
        // 将栈顶元素的右节点赋值给bt
        // 并且将栈顶元素节点设置为已访问过
        if(!s.empty()) {
            s.top()->tag = 1;
            bt = s.top()->rchild;
        }

    }

}
