#include <iostream>
using namespace std;

template <class T>
class linked_list;


template <class T>
class node
{
	private:
		T dato;
		node<T> * p_next;

	public:
		node(const T & d, node<T> * n = NULL)
		{
			dato = d;
			p_next = n;
		}
		virtual ~node()
		{
            if(p_next) delete p_next;
		}
		void print()
		{
			cout<<dato<<" -> ";
		}

	friend class linked_list<T>;
};


template <class T>
class linked_list
{
	private:
		node<T> * p_head;
		node<T> * p_last;

	public:
		linked_list()
		{
			p_head=NULL;
			p_last=NULL;
		}

		virtual ~linked_list()
		{
            delete p_head;
		}

		void insert_front(const T & d)
		{
			 p_head = new node<T>(d,p_head);
			 if(!p_last) p_last = p_head;
		}

		void insert_back(const T & d)
		{
			if(!p_head)
			{
				insert_front(d);
				return;
			}
			node<T> * new_node = new node<T>(d);
			p_last->p_next = new_node;
			p_last = new_node;
		}

		void insert_sort(const T & d)
		{
		    node<T> * new_node = new node<T>(d);
		    node<T> * temp = p_head;
		    if(!p_head)
            {
                insert_front(d);
                return;
            }
            else
            {
                if(p_head->dato > d)
                {
                    new_node->p_next = p_head;
                    p_head = new_node;
                }
                else
                {
                    while((temp->p_next != NULL)&&(temp->p_next->dato < d))
                    {
                        temp = temp->p_next;
                    }
                    new_node->p_next = temp->p_next;
                    temp->p_next = new_node;
                }
            }
		}

		void remove_front()
		{
			if(!p_head) return;
			node<T> * del = p_head;
			p_head = p_head->p_next;
			del->p_next = NULL;
			delete del;
		}

		void remove_back()
		{
			if(!p_last) return;
            if(p_head == p_last)
            {
                remove_front();
                return;
            }
			node<T> * del = p_head;

			while(del->p_next!=p_last){
				del = del->p_next;
			}
			del->p_next = NULL;
			delete p_last;
			p_last = del;
		}

		void reverse(){
            if(!p_head) return;
            node<T> * p_previous = NULL;
            node<T> * aux = NULL;
            node<T> * temp = p_head;
            while(temp){
                aux = temp->p_next;
                temp->p_next = p_previous;
                p_previous = temp;
                temp = aux;
            }
            p_head = p_previous;
		}

        T getFirstDato()
		{
		    if(p_head) return p_head->dato;

		}

		T getLastDato()
		{
		    if(p_head) return p_last->dato;
		}

		void print(){
			node<T> * aux = p_head;
			while(aux)
			{
				aux->print();
				aux = aux->p_next;
			}
		}
};

template<class T>
class stack
{
	private:
		linked_list<T> list;

	public:
		stack(){};
		~stack(){};

		void push(T dato)
		{
		    list.insert_front(dato);
		}
		void pop()
		{
		    list.remove_front();
		}

		T top()
		{
		    list.getFirstDato();
		}
		void print()
		{
		    list.print();
		}

};

/*int main()
{
	//linked_list<int> list_int;
	stack<int> stack_int;
	stack_int.push(2);
	stack_int.pop();
	stack_int.push(4);
	stack_int.top();
	stack_int.print();

	return 0;
}*/
