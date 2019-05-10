void searchRoute(BiTNode* bt, TElemType data) {
    stack<BiTree> s;
    while(bt != nullptr || !s.empty()) {
        while(bt != nullptr && bt->data != data) {
            s.push(bt);
            bt->tag = 0;
            bt = bt->lchild;
        }
        if(bt->data == data) {
            // 出栈得到路径
            while(!s.empty()) {
                BiTree p = s.top();
                cout << p->data << " ";
                s.pop();
            }
        }
        while(!s.empty() && s.top()->tag==1) {
            s.pop();
        }
        if(!s.empty()) {
            s.top()->tag = 1;
            bt = s.top()->rchild;
        }

    }

}
