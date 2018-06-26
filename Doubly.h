#ifndef DOUBLY_H_INCLUDED
#define DOUBLY_H_INCLUDED

#include <iostream>
using namespace std;

class Doubly
{
private:
    struct Node
    {
        int i;
        Node *next;
        Node *prev;
    };
public:
    Node *p;
    Node *q;

    Doubly()
    {
        p = NULL;
        q = NULL;
    }
/////////////////////////////////////////////////////////////////////
    Doubly(const Doubly &d)
    {
        p = NULL;
        q = p;
        operator=(d);
    }
/////////////////////////////////////////////////////////////////////
    ~Doubly()
    {
            Node *position = p;
            while(position !=0)
            {
                Node *newly;
                newly = position->next;
                delete position;
                position = newly;
            }
            p = NULL;
            delete p;
            q = NULL;
            delete q;
    }
/////////////////////////////////////////////////////////////////////
 void clear()
 {
     Node *position = p;
     while(position != 0)
     {
         Node*newly;
         newly = position->next;
         delete position;
         position = newly;
     }
     p = NULL;
     q = NULL;
 }
/////////////////////////////////////////////////////////////////////
bool find(int i) const
{
    Node *nodeptr;
    nodeptr = p;
    if(!p)
    {
        return 0;
    }
    if(p->i == i)
    {
        return 1;
    }
    while(nodeptr)
    {
        if(nodeptr->i == i)
        {
            return 1;
        }
        nodeptr = nodeptr->next;
    }
    return 0;
}
/////////////////////////////////////////////////////////////////////
bool isFull() const
{
    if(!p && !q)
    {
        return 0;
    }
    if(p || q)
    {
        return 1;
    }
}
/////////////////////////////////////////////////////////////////////
bool isEmpty() const
{
    if(!p && !q)
    {
        return 1;
    }
    if(p || q)
    {
        return 0;
    }
}
/////////////////////////////////////////////////////////////////////
bool find(int i)
{
    Node *nodeptr;
    if(!p)
    {
        return 0;
    }
    if(p)
    {
        nodeptr = p;
        if(nodeptr->i == i)
        {
            return 1;
        }
        if(nodeptr->i != i)
        {
            while(nodeptr)
            {
                if(nodeptr->i == i)
                {
                    return 1;
                }
                nodeptr= nodeptr->next;
            }
            return 0;
        }
    }
}
/////////////////////////////////////////////////////////////////////
void print()
{
    if(p)
    {
        Node *nodeptr;
        nodeptr = p;
        while(nodeptr)
        {
            cout << nodeptr->i << " ";
            nodeptr = nodeptr->next;
        }
    }
    if(!p)
    {
        cout << "/n" << endl;
    }
}
/////////////////////////////////////////////////////////////////////
void reverse() const
{
    if(!q)
    {
        cout << "\n"<< endl;
    }
    if(q)
    {
        Node *nodeptr;
        nodeptr = q;
        int a = 0;
        while(nodeptr)
        {
            cout << nodeptr->i << " ";
            nodeptr = nodeptr->prev;
            if(a++ == 10)
            {
                break;
            }
        }
    }
}
/////////////////////////////////////////////////////////////////////
int insert(int i)
{
    Node *nodeptr;
    Node *newone;
    newone = new Node;
    newone->i = i;
    newone->next = NULL;
    if(!p)
    {
        p = newone;
        p->next = NULL;
        p->prev = NULL;
    }
    if(p)
    {
        nodeptr = p;
        int counter = 0;
        while(nodeptr)
        {
            counter++;
            nodeptr = nodeptr->next;
        }
        nodeptr->next = newone;
        int *a;
        a = new int[counter];
        nodeptr = p;
        for (int x = 0; x < counter;x++)
        {
            a[x] = nodeptr->i;
            nodeptr = nodeptr->next;
        }
        int f;
        for (int x = 0 ; x< counter;x++)
        {
            for (int w = 0; w < counter; w++)
            {
                if(a[x]>=a[w])
                    {
                        f = a[x];
                        a[x] = a[w];
                        a[w] = f;
                    }
            }
        }
        for(int x = 0; x < counter; x++)
        {
            nodeptr->i = a[x];
            nodeptr = nodeptr->next;
        }
        nodeptr = p;
        Node *holder;
        while(nodeptr)
        {
            holder = nodeptr;
            nodeptr = nodeptr->next;
            nodeptr ->prev = holder;
            return 0;
        }
    }

}
/////////////////////////////////////////////////////////////////////
    int remove(int i)
    {
        Node *nodeptr;
        if(!p)
        {
            return -1;
        }
        if(p)
        {
            if(p->i == i)
            {
                nodeptr = p;
                 nodeptr->prev = NULL;
                 delete p;
                 p = nodeptr;
                 return 0;
            }
            if(q->i == i)
            {
                nodeptr = q->prev;
                nodeptr->next = NULL;
                delete q;
                q = nodeptr;
            }
            nodeptr = p;
            while(nodeptr!=NULL)
            {
                if(nodeptr->i == i)
                {
                    nodeptr->prev->next = nodeptr->next;
                    nodeptr->next->prev = nodeptr->prev;
                    delete nodeptr;
                    nodeptr = NULL;
                    return 0;
                }
                nodeptr = nodeptr->next;
            }
            return -1;
        }
        return -1;
    }
/////////////////////////////////////////////////////////////////////
bool operator=(const Doubly &d)
{
    Node *nodeptr;
    if(!d.p)
    {
        return 0;
    }
    nodeptr = d.p;
    while(nodeptr)
    {
        insert(nodeptr->i);
        nodeptr = nodeptr->next;
        if(!nodeptr)
        {
            return 1;
        }
    }
    return 0;
}
bool operator ==(const Doubly &d)
{
    if(!d.p&&!p)
    {
        return 1;
    }
    if(!d.p && p||!p && d.p)
    {
        return 0;
    }
    Node *nodeptr;
    nodeptr = d.p;
    int counter[2] = {0,0};
    while(nodeptr)
    {
        counter[0]++;
    nodeptr = nodeptr->next;
    }
    nodeptr = NULL;
    nodeptr = p;
    while(nodeptr)
    {
        counter[1]++;
        nodeptr = nodeptr->next;
    }
    if(counter[0] == counter[1])
    {
        return 1;
    }
    if(counter[0]!= counter[1])
    {
        return 0;
    }
}
bool operator < (const Doubly &d)
{
    Node *nodeptr;
    if((d.p) && (p) || d.p && !p)
    {
        return 0;
    }
    if(!d.p && p)
    {
        return 1;
    }
    nodeptr = d.p;
    int counter[2] = {0,0};
    while(nodeptr)
    {
        counter[0]++;
        nodeptr = nodeptr->next;
    }
    nodeptr = NULL;
    nodeptr = p;
    while(nodeptr)
    {
        counter[1];
        nodeptr = nodeptr->next;
    }
    if(counter[0]<counter[1])
    {
        return 1;
    }
    if(counter[1]< counter[0])
    {
        return 0;
    }
}

};



#endif // DOUBLY_H_INCLUDED
