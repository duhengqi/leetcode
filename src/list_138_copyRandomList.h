/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 随机链表的复制
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution_138 {
public:
    Node* copyRandomList(Node* head) {
        Node * nNode = nullptr;
        Node newListNode(0);
        Node *nHead = nullptr;
        map<Node*,unsigned int> oMap;
        map<unsigned int,Node*> nMap;

        nNode = head;
        nHead = &newListNode;
        unsigned int index = 0;
        while (nNode!= nullptr){
            nHead->next = new Node(nNode->val);
            nHead = nHead->next;
            // oMap[index] = nNode;
            oMap.insert(make_pair(nNode,index));
            nMap[index] = nHead;
            index++;
    
            nNode = nNode->next;
        }

        nNode = head;
        nHead = newListNode.next;
        while (nNode != nullptr) {
            if (nNode->random != nullptr) {
                map<Node*,unsigned int>::iterator iter = oMap.find(nNode->random);
                if (iter != oMap.end()) {
                    nHead->random = nMap[iter->second];
                }
            }
            nNode = nNode->next;
            nHead = nHead->next;
        }

        return newListNode.next;
    }
};

// @lc code=end

