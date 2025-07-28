



/* very imp for design prob

25th Feb 2025 (Tuesday - Maha Shiva Ratari - IIRS IRSRO Dehradun)

LecNo 76 Apna college

LRU = Least Recently Used
qno 146  https://leetcode.com/problems/lru-cache/description/


*/


class LRUCache {
public:
    class Node {
    public:
        int key, val;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            val = v;
            prev = next = NULL;
        }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    unordered_map<int, Node*> m;
    int limit;

    void addNode(Node* newNode) {  // O(1)
        Node* oldNext = head->next;

        head->next = newNode;
        oldNext->prev = newNode;

        newNode->next = oldNext;
        newNode->prev = head;
    }

    void delNode(Node* oldNode) {  // O(1)
        Node* oldPrev = oldNode->prev;
        Node* oldNext = oldNode->next;

        oldPrev->next = oldNext;
        oldNext->prev = oldPrev;
    }

    LRUCache(int capacity) {
        limit = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {  // O(1)
        if (m.find(key) == m.end()) {
            return -1;
        }

        Node* ansNode = m[key];
        int ans = ansNode->val;

        // Remove the node and re-add it to the front (since it's recently accessed)
        m.erase(key);
        delNode(ansNode);
        addNode(ansNode);

        m[key] = ansNode;

        return ans;
    }
    
    void put(int key, int value) {  // O(1)
        if (m.find(key) != m.end()) {  // Check if the key is already in the cache
            Node* oldNode = m[key];
            delNode(oldNode);  // Remove the old node
            m.erase(key);
        }

        if (m.size() == limit) {
            // Delete the least recently used (LRU) node
            m.erase(tail->prev->key);
            delNode(tail->prev);
        }

        // Insert the new node at the front of the list (most recently used)
        Node* newNode = new Node(key, value);
        addNode(newNode);
        m[key] = newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */