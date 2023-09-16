 Node *find(const K &key) {
        Node *cur = this->_root;
        while (cur) {
            if (key > cur->_kv.first) {
                cur = cur->_right;
            } else if (key < cur->_kv.first) {
                cur = cur->_left;
            } else {
                return cur;
            }
        }
        return nullptr;
    }