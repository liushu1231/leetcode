class LRUCache{
public:

struct CacheNode{
    CacheNode* pre;
    CacheNode* next;
    int key;
    int value;
    CacheNode(int x,int y):key(x),value(y),next(NULL),pre(NULL){}
};

map<int,CacheNode*> m_cacheMap;
CacheNode* m_cacheListHead;
CacheNode* m_cacheListTail;
int m_capacity;

    LRUCache(int capacity) {
        m_cacheListHead = new CacheNode(0,0);
        m_capacity = capacity;
        m_cacheListTail = m_cacheListHead;
        m_cacheListTail->next = m_cacheListHead;
        m_cacheListTail->pre = m_cacheListHead;
    }
    
    int get(int key) {
        map<int,CacheNode*>::iterator it = m_cacheMap.find(key);
        if (it != m_cacheMap.end())
        {
            CacheNode* temp = it->second;
            
            if(temp == m_cacheListHead)//考虑为头结点的时候特殊处理
				return m_cacheListHead->value;
            
            temp->next->pre = temp->pre;
            temp->pre->next = temp->next;
            
            temp->next = m_cacheListHead;
            temp->pre = m_cacheListHead->pre;
            m_cacheListHead->pre->next = temp;
            m_cacheListHead->pre = temp;
            m_cacheListHead = temp;
			m_cacheListTail = temp->pre;//考虑移动的时候头尾都需要改变
            
            return temp->value;
        }
        else
            return -1;
    }
    
    void set(int key, int value) {
        map<int,CacheNode*>::iterator it = m_cacheMap.find(key);
        if (it != m_cacheMap.end())
        {
            CacheNode* temp = it->second;
            
            if(temp == m_cacheListHead)
			{
				m_cacheListHead->value = value;
				return;
			}
            
            temp->value = value;
            
            temp->next->pre = temp->pre;
            temp->pre->next = temp->next;
            
            temp->next = m_cacheListHead;
            temp->pre = m_cacheListHead->pre;
            m_cacheListHead->pre->next = temp;
            m_cacheListHead->pre = temp;
            m_cacheListHead = temp;
			m_cacheListTail = m_cacheListHead->pre;
        }
        else
        {
            if(m_cacheMap.size() == m_capacity)
            {
                m_cacheMap.erase(m_cacheMap.find(m_cacheListTail->key));
                m_cacheListTail->key = key;
                m_cacheListTail->value = value;
                m_cacheListHead = m_cacheListTail;
                m_cacheMap[key] = m_cacheListHead;
                m_cacheListTail = m_cacheListTail->pre;
            }
            else
            {
                if(m_cacheMap.size() == 0)
                {
                    m_cacheListHead->key = key;
                    m_cacheListHead->value = value;
                    m_cacheMap[key] = m_cacheListHead;
                }
                else
                {
                    CacheNode* temp = new CacheNode(key,value);
                    temp->next = m_cacheListHead;
                    temp->pre = m_cacheListTail;
                    m_cacheListHead->pre = temp;
                    m_cacheListTail->next = temp;
                    m_cacheListHead = temp;
                    m_cacheMap[key] = m_cacheListHead;
					m_cacheListTail = m_cacheListHead->pre;
                }
            }
        }
    }
};