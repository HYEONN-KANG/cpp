#include <iostream>
#include <string>

using namespace std;

class Node
{
    int elem;
    Node *next;

    friend class S_LinkedList;
};

class S_LinkedList
{
public:
    S_LinkedList();
    int List_size();
    bool Empty();
    void Print();
    void Append(int elem);
    int Delete(int idx);
    void Insert(int idx, int elem);
    void Min();

private:
    Node *head;
    Node *tail;
};

S_LinkedList::S_LinkedList()
{
    head = new Node;
    tail = new Node;

    head = NULL;
    tail = NULL;
}

bool S_LinkedList::Empty()
{
    return (head == NULL && tail == NULL); // 비어있으면 1 아니면 0을 return
}

int S_LinkedList::List_size()
{
    int list_size = 0;
    if (Empty())
    { // if empty
        return list_size;
    }

    else
    {
        Node *cur_node = head;
        while (cur_node->next != NULL)
        { // not include tail
            list_size++;
            cur_node = cur_node->next;
        }
        list_size++;
        return list_size;
    }
}

void S_LinkedList::Print()
{
    if (Empty())
    {
        cout << "empty" << endl;
    }
    else
    {
        Node *cur_node = head;
        while (cur_node->next != NULL)
        {
            cout << cur_node->elem << ' ';
            cur_node = cur_node->next;
        }
        cout << cur_node->elem << endl;
    }
}

void S_LinkedList::Append(int elem)
{
    Node *new_node = new Node;
    new_node->elem = elem;
    new_node->next = NULL;

    if (Empty())
    {
        head = new_node;
        tail = new_node;
    }
    else
    {
        tail->next = new_node;
        tail = tail->next;
    }
    Print();
}
int S_LinkedList::Delete(int idx) // 보류
{
    int removeNum = 0;
    int cnt = 0;
    Node *cur_node;
    Node *pre_node;

    if (Empty() || List_size() <= idx)
    {
        removeNum = -1;
    }
    else if (idx == 0)
    {
        if (List_size() == 1)
        {
            removeNum = head->elem;
            tail = NULL;
            head = NULL;
        }
        else
        {
            cur_node = head;
            removeNum = cur_node->elem;
            head = cur_node->next;
        }
    }
    else
    {
        pre_node = cur_node = head;
        while (cnt != idx)
        {
            pre_node = cur_node;
            cur_node = cur_node->next;
            cnt++;
        }
        removeNum = cur_node->elem;
        pre_node->next = cur_node->next;

        if (cur_node == tail)
        {
            tail = pre_node;
        }
    }

    return removeNum;
}
void S_LinkedList::Insert(int idx, int elem)
{
    Node *new_node = new Node;
    new_node->elem = elem;

    Node *pre_node;
    Node *cur_node;
    int cur_idx = 0;

    if (idx == 0)
    {
        if (Empty())
        {
            head = new_node;
            tail = new_node;
        }
        else
        {
            new_node->next = head;
            head = new_node;
        }
        Print();
    }
    else if (idx < 0 || idx > List_size())
    {
        cout << "Index Error" << endl;
    }
    else if (idx == List_size())
    {
        Append(elem);
    }
    else
    {
        pre_node = cur_node = head;
        while (cur_idx != idx)
        {
            pre_node = cur_node;
            cur_node = cur_node->next;
            cur_idx++;
        }
        pre_node->next = new_node;
        new_node->next = cur_node;
        Print();
    }
}
void S_LinkedList::Min()
{
    Node *min_node = new Node;
    int min_elem = 10001;
    if (Empty())
    {
        cout << "empty" << endl;
    }
    else if (List_size() == 1)
    {
        min_node = head;
        min_elem = min_node->elem;
        cout << min_elem << endl;
    }
    else
    {
        min_node = head;
        min_elem = min_node->elem;
        while (min_node->next != NULL)
        {
            min_node = min_node->next;
            if (min_node->elem < min_elem)
            {
                min_elem = min_node->elem;
            }
            else
            {
                continue;
            }
        }
        if (min_node->elem < min_elem)
        {
            min_elem = min_node->elem;
        }
        cout << min_elem << endl;
    }
}

int main()
{
    S_LinkedList SList;
    int M = 0, fir = 0, sec = 0;
    cin >> M;
    string s = "";

    for (int i = 0; i < M; i++)
    {
        cin >> s;
        if (s == "Print")
        {
            SList.Print();
        }
        else if (s == "Append")
        {
            cin >> fir;
            SList.Append(fir);
        }
        else if (s == "Delete")
        {
            cin >> fir;
            cout << SList.Delete(fir) << endl;
        }
        else if (s == "Insert")
        {
            cin >> fir >> sec;
            SList.Insert(fir, sec);
        }
        else if (s == "Min")
        {
            SList.Min();
        }
        s = "";
    }
}