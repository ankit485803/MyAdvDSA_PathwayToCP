


/*

https://www.hackerrank.com/contests/codequest-iitp/challenges/insert-a-node-at-a-specific-position-in-a-linked-list

https://www.hackerrank.com/contests/codequest-iitp/challenges/insert-a-node-at-a-specific-position-in-a-linked-list


Given a pointer to the head node of a linked list and an integer to insert at a certain position, create a new node with the given integer as its  attribute, insert this node at the desired position, and return the head node.

A position of 0 indicates the head, a position of 1 indicates one node away from the head, and so on. The head pointer given may be null, meaning that the initial list is empty.

Example
 refers to the first node in the list 


Insert a node at position  with . The new list is 

Function Description
Complete the function  with the following parameters:

: a reference to the head of the list
: an integer value to insert as data in the new node
: an integer position to insert the new node, zero-based indexing
Returns

: a reference to the head of the revised list
Input Format

The first line contains an integer , the number of elements in the linked list.
Each of the next  lines contains an integer SinglyLinkedListNode[i].data.
The next line contains an integer , the data of the node that is to be inserted.
The last line contains an integer .

Constraints

, where  is the  element of the linked list.
.
Sample Input

STDIN   Function
-----   --------
3       n = 3
16      llist = 16->13->7
13
7
1       data = 1
2       position = 2

*/






#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}

/*
 * Complete the 'insertNodeAtPosition' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts following parameters:
 *  1. INTEGER_SINGLY_LINKED_LIST llist
 *  2. INTEGER data
 *  3. INTEGER position
 */

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
    SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);
    
    if (position == 0) {
        newNode->next = llist;
        return newNode;
    }

    SinglyLinkedListNode* current = llist;
    for (int i = 0; i < position - 1 && current != nullptr; i++) {
        current = current->next;
    }

    if (current != nullptr) {
        newNode->next = current->next;
        current->next = newNode;
    }

    return llist;
        
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    SinglyLinkedList* llist = new SinglyLinkedList();

    string llist_count_temp;
    getline(cin, llist_count_temp);

    int llist_count = stoi(ltrim(rtrim(llist_count_temp)));

    for (int i = 0; i < llist_count; i++) {
        string llist_item_temp;
        getline(cin, llist_item_temp);

        int llist_item = stoi(ltrim(rtrim(llist_item_temp)));

        llist->insert_node(llist_item);
    }

    string data_temp;
    getline(cin, data_temp);

    int data = stoi(ltrim(rtrim(data_temp)));

    string position_temp;
    getline(cin, position_temp);

    int position = stoi(ltrim(rtrim(position_temp)));

    SinglyLinkedListNode* llist_head = insertNodeAtPosition(llist->head, data, position);

    print_singly_linked_list(llist_head, " ", fout);
    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
