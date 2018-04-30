template<typename T>
class LinkedList;

template<typename T>
class Node {
    friend class LinkedList<T>;

private:
    T data;
    Node<T>* next;

    Node(T data) {
        this->data = data;
        this->next = nullptr;
    }
};

template<typename T>
class LinkedList {
private:
    Node<T>* node;
    size_t size;

    /**
    * Recursive method to delete all children
    */
    void deleteChildren(Node<T>* n) {
        // First delete the children
        if (n->next != nullptr) {
            deleteChildren(n->next);
        }

        // Now delete this element
        delete n;
    }

public:
    LinkedList() {
        node = nullptr;
        size = 0;
    }

    ~LinkedList() {
        if (!isEmpty()) {
            deleteChildren(node);
        }
    }

    bool isEmpty() {
        return (node == nullptr);
    }

    void addNode(T data) {
        // Increase size
        size++;

        // Add data
        Node<T>* new_node = new Node<T>(data);

        if (isEmpty()) {

            // First node when empty
            node = new_node;
        } else {

            // Find the last node
            Node<T>* current_node = node;
            while (current_node->next != nullptr) {
                current_node = current_node->next;
            }
            current_node->next = new_node;
        }
    }

    T get(int pos) {
        Node<T>* current_node = node;
        for (int i = 0; i < pos && current_node != nullptr; i++) {
            current_node = current_node->next;
        }
        if ( current_node != nullptr ) {
            return current_node->data;
        }
        throw "Not found";
    }

    T remove(int pos) {
        if (isEmpty()) {
            throw "Empty";
        }

        Node<T>* last_node = nullptr;
        Node<T>* current_node = node;
        for (int i = 0; i < pos && current_node != nullptr; i++) {
            last_node = current_node;
            current_node = current_node->next;
        }

        // Node found?
        if (current_node == nullptr) {
            throw "Not found";
        }

        T data = current_node->data;

        // Remove the current node from the list
        if (last_node == nullptr) {
            // First node will be removed
            node = current_node->next;
        } else {
            last_node->next = current_node->next;
        }

        // Decrease size
        size--;

        delete current_node;
        return data;
    }

    T getSize() {
        return size;
    }

};


