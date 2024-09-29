class Node {
public:
    int freq;
    Node* prev;
    Node* next;
    unordered_set<string> keys;

    Node(int freq) : freq(freq), prev(nullptr), next(nullptr) {}
};

class AllOne {
private:
    Node* head;
    Node* tail;
    unordered_map<string, Node*> map;

    void removeNode(Node* node) {
        if (node == head) {
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
        } else if (node == tail) {
            tail = tail->prev;
            if (tail != nullptr) {
                tail->next = nullptr;
            }
        } else {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
        delete node;
    }

public:
    
    AllOne() : head(nullptr), tail(nullptr) {}

    
    void inc(string key) {
        if (map.find(key) != map.end()) {
            Node* node = map[key];
            int freq = node->freq;
            node->keys.erase(key);
            if (node->next == nullptr) {
                Node* newNode = new Node(freq + 1);
                node->next = newNode;
                newNode->prev = node;
                newNode->keys.insert(key);
                map[key] = newNode;
                tail = newNode;
            } else {
                Node* next = node->next;
                if (next->freq - freq > 1) {
                    Node* newNode = new Node(freq + 1);
                    newNode->keys.insert(key);
                    node->next = newNode;
                    newNode->prev = node;
                    newNode->next = next;
                    next->prev = newNode;
                    map[key] = newNode;
                } else {
                    next->keys.insert(key);
                    map[key] = next;
                }
            }

            if (node->keys.empty()) {
                removeNode(node);
            }

        } else { 
            if (head == nullptr) {
                head = new Node(1);
                head->keys.insert(key);
                tail = head;
            } else {
                if (head->freq == 1) {
                    head->keys.insert(key);
                } else {
                    Node* newNode = new Node(1);
                    newNode->keys.insert(key);
                    newNode->next = head;
                    head->prev = newNode;
                    head = newNode;
                }
            }
            map[key] = head;
        }
    }

    void dec(string key) {
        if (map.find(key) == map.end()) {
            return;
        }
        Node* node = map[key];
        node->keys.erase(key);
        int freq = node->freq;
        if (freq == 1) {
            map.erase(key);
        } else if (node == head) {
            Node* newNode = new Node(freq - 1);
            newNode->keys.insert(key);
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            map[key] = head;
        } else {
            Node* prev = node->prev;
            if (freq - prev->freq == 1) {
                prev->keys.insert(key);
                map[key] = prev;
            } else {
                Node* newNode = new Node(freq - 1);
                prev->next = newNode;
                newNode->prev = prev;
                newNode->next = node;
                node->prev = newNode;
                newNode->keys.insert(key);
                map[key] = newNode;
            }
        }

        if (node->keys.empty()) {
            removeNode(node);
        }
    }

    string getMaxKey() {
        if (head == nullptr) {
            return "";
        }
        return *tail->keys.begin();
    }

    string getMinKey() {
        if (head == nullptr) {
            return "";
        }
        return *head->keys.begin();
    }
};