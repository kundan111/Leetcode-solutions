public class LRUCache {


    class Node{
    
        int key;
        int value;
        Node prev;
        Node next;

        Node(int k, int v)
        {
            this.key = k;
            this.value = v;
        }
    }

    int capacity;
    HashMap<Integer,Node> hm = new HashMap<>();
    Node dummyStart; 
    Node dummyEnd; 

    void remove(Node node)
    {
        hm.remove(node.key);
        Node prevNode = node.prev;
        Node nextNode = node.next;

        prevNode.next = nextNode;
        nextNode.prev = prevNode;
    }

    void insert(Node node)
    {
        hm.put(node.key, node);
        Node headNext = dummyStart.next;
        
        node.prev = dummyStart;
        node.next = headNext;

        headNext.prev = node;
        dummyStart.next = node;


    }

    public LRUCache(int capacity) {
        
        this.capacity =capacity;
        this.dummyStart = new Node(-1, -1);
        this.dummyEnd = new Node(-1, -1);

        this.dummyStart.next = this.dummyEnd;
        this.dummyEnd.prev = this.dummyStart;

    }
    
    public int get(int key) {
        if(!hm.containsKey(key))
        {
            return -1;
        }
        Node node = hm.get(key);
        remove(node);
        insert(node);

        return node.value;
    }
    
    public void put(int key, int value) {

        // key already present
        if(hm.containsKey(key))
        {
            // update its value
            remove(hm.get(key));
        }

        if(hm.size() == this.capacity)
        {
            // add the node
            remove(dummyEnd.prev);
        }

        // remove the LRU
        insert(new Node(key, value));



    }
    
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */