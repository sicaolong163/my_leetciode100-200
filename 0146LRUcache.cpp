class LRUCache {
private:
    int cap;
    list<pair<int,int>>recent;//双向链表，存放的是一个数对；key value;
    unordered_map<int,list<pair<int,int>>::iterator>map;//value是迭代器；firstkey，second 代表value；
public:
    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        if(map.find(key)!=map.end())
        {
            put(key,map[key]->second);
            return map[key]->second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(map.find(key)!=map.end())
        {
            recent.erase(map[key]);
        }
        else if(recent.size()>=cap)
        {
            map.erase(recent.back().first);//在hash表中删除链表尾部的key值；
            recent.pop_back();//链表删除尾部的节点；
        }
        recent.push_front({key,value});//将节点压入头部；
        map[key]=recent.begin();//hash表中的value值更新；
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
