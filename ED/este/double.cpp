#include <iostream>
using namespace std;

template <class T>
class doubly_linked_list;

template <class T>
class node
{
	private:
		T dato;
		node<T> * p_next;
		node<T> * p_previous;

	public:
		node(const T & d, node<T> * n = NULL, node<T> * p = NULL )
		{
			dato = d;
			p_next = n;
			//cout<<d<<"->"<<endl;
			p_previous = p;
		}
		virtual ~node()
		{
            if(p_next) delete p_next;
		}
		void print()
		{
			cout<< dato<<" -> ";
		}

	friend class doubly_linked_list<T>;
};


template <class T>
class doubly_linked_list
{
	private:
		node<T> * p_head;
		node<T> * p_last;

	public:
		doubly_linked_list()
		{
			p_head=NULL;
			p_last=NULL;
		}

		virtual ~doubly_linked_list()
		{
            delete p_head;
		}

		void insert_front(const T & d)
		{
            node<T> * new_node = new node<T>(d);

            new_node->p_next = p_head;
            new_node->p_previous = NULL;
            if(p_head) p_head->p_previous = new_node;
            p_head = new_node;
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
			new_node->p_next = NULL;
			p_last->p_next = new_node;
			new_node->p_previous = p_last;
			p_last = new_node;


		}
		void remove_front()
		{
			if(!p_head) return;
			if(p_head == p_last)
            {
                node<T> * del = p_head;
                p_head = NULL;
                p_last = NULL;
                delete del;
                return;
            }
			node<T> * del = p_head;
			p_head = p_head->p_next;
			p_head->p_previous=NULL;
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
			delete p_last;
			p_last = del;
			del->p_next = NULL;
		}

		void reverse(){
            if(!p_head) return;
            node<T> * aux = p_head;
            node<T> * temp = NULL;
            while(aux){
                temp = aux->p_previous;
                aux->p_previous = aux->p_next;
                aux->p_next = temp;
                aux = aux->p_previous;
            }
            if(temp)
            {
                p_last = p_head;
                p_head = temp->p_previous;
            }
		}

		void print(){
			node<T> * aux = p_head;
			while(aux)
			{
				aux->print();
				aux = aux->p_next;
			}
		}

        void print_p()
        {
            node<T> * aux2 = p_last;
			while(aux2)
            {
                aux2->print();
                aux2 = aux2->p_previous;
            }
        }
};

int main()
{
	doubly_linked_list<int> list_int;
	for (int i=0; i<10; i++){
		list_int.insert_front(i);
		list_int.print();
		cout<<endl;
	}
	cout<<endl;
	for (int i=0; i<10; i++){
		list_int.remove_back();
		list_int.print();
		cout<<endl;
	}

	


	return 0;
}