class MyCircularDeque {

    private:
    int head,tail,size,cap;
    vector<int>q;
public:
    MyCircularDeque(int k) {
        head=0;
        tail=0;
        size=0;
        cap=k;
        for(int i=0;i<k;i++){
            q.push_back(0);
        }
    }
    
    bool insertFront(int value) {
        if(isFull()){
            return false;
        }
        head=head==0?cap-1:head-1;
        q[head]=value;
        size++;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()){
            return false;
        }
        q[tail++]=value;
        tail%=cap;
        size++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()){
            return false;
        }
        head=(head+1)%cap;
        size--;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()){
            return false;
        }
        tail=tail==0?cap-1:tail-1;
        size--;
        return true;
    }
    
    int getFront() {
        return isEmpty()?-1:q[head];
    }
    
    int getRear() {
        return isEmpty()?-1:tail==0 ? q[cap-1]:q[tail-1];
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    bool isFull() {
        return size==cap;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */