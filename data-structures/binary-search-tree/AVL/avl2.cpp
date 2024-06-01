#include <iostream>
#include <stack>
#include <fstream>
using namespace std;
//ifstream f("abce.in.txt");
//ofstream g("abce.out.txt");
ifstream f("abce.in");
ofstream g("abce.out");
//////
const int MAX_LIMIT = 2147483647;
const int MIN_LIMIT = -2147483648;
///
class Node
{
public:
    int value;
    Node* left;
    Node* right;
    unsigned height;
public:
    Node() = delete;
    Node(const int value) : value(value), left(NULL), right(NULL), height(1) {}
    Node(const Node& node)
    {
        *this = node;
    }
    Node& operator=(const Node& node)
    {
        this->value = node.value;
        this->left = node.left;
        this->right = node.right;
        this->height = node.height;
        return *this;
    }
    ~Node() = default;
};
///
class AVL_Tree
{
private:
    unsigned size;
    Node* root;
public:
    AVL_Tree() : size(0), root(NULL) {}
    ~AVL_Tree()
    {
        delete_all_nodes_(this->root);
    }
//////  
private:
    void delete_all_nodes_(Node* init)
    {
        if (init == NULL)
            return;
        delete_all_nodes_(init->left);
        delete_all_nodes_(init->right);
        delete init;
    }
    bool is_balanced_(Node* init)
    {
        if (init == NULL)
            return true;
        int Bf = balance_factor_(init);
        if (Bf < -1 || 1 < Bf)
            return false;
        bool l = is_balanced_(init->left);
        bool r = is_balanced_(init->right);
        return (l && r);
    }
    unsigned height_(Node* init)
    {
        if (init == NULL)
            return 0;
        return init->height;
    }
    void swap_int_val_(int& a, int& b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    unsigned max_unsigned_val_(const unsigned a, const unsigned b)
    {
        if (a > b)
            return a;
        return b;
    }
    int balance_factor_(Node* init)
    {
        if (init == NULL)
            return 0;
        return height_(init->left) - height_(init->right);
    }
    Node* min_node_()
    {
        if (this->root == NULL)
            return NULL;
        Node* p = this->root;
        while (p->left != NULL)
        {
            p = p->left;
        }
        return p;
    }
    Node* max_node_()
    {
        if (this->root == NULL)
            return NULL;
        Node* p = this->root;
        while (p->right != NULL)
        {
            p = p->right;
        }
        return p;
    }
    Node* search_(const int val)
    {
        Node* p = this->root;
        while (p != NULL)
        {
            if (p->value == val)
                return p;
            if (val < p->value)
                p = p->left;
            else
                p = p->right;
        }
        return p;
    }
    void in_order_(Node* init)
    {
        if (init == NULL)
            return;
        in_order_(init->left);
        cout << init->value << " ( " << init->height << " )\n";
        in_order_(init->right);
    }
    void pre_order_(Node* init)
    {
        if (init == NULL)
            return;
        cout << init->value << " ( " << init->height << " )\n";
        pre_order_(init->left);
        pre_order_(init->right);
    }
    void sorted_sequence_(Node* init, const int x, const int y)
    {
        if (init == NULL)
            return;
        if (x < init->value)
            sorted_sequence_(init->left, x, y);
        if (x <= init->value && init->value <= y)
            g << init->value << " ";
        if (init->value < y)
            sorted_sequence_(init->right, x, y);
    }
    Node* find_ancestor_below_(const int val)
    {
        stack<Node*> st;
        Node* p = this->root;
        while (p != NULL)
        {
            st.push(p);
            if (p->value == val)
                break;
            else if (val < p->value)
                p = p->left;
            else
                p = p->right;
        }
        while (!st.empty())
        {
            if (st.top()->value < val)
            {
                Node* q = st.top();
                while (!st.empty())
                {
                    st.pop();
                }
                return q;
            }
            st.pop();
        }
        return NULL;
    }
    Node* find_ancestor_above_(const int val)
    {
        stack<Node*> st;
        Node* p = this->root;
        while (p != NULL)
        {
            st.push(p);
            if (p->value == val)
                break;
            else if (val < p->value)
                p = p->left;
            else
                p = p->right;
        }
        while (!st.empty())
        {
            if (val < st.top()->value)
            {
                Node* q = st.top();
                while (!st.empty())
                {
                    st.pop();
                }
                return q;
            }
            st.pop();
        }
        return NULL;
    }
    Node* closest_below_(const int val)
    {
        Node* p = search_(val);
        if (p != NULL)
            return p;
        p = find_ancestor_below_(val);
        return p;
    }
    Node* closest_above_(const int val)
    {
        Node* p = search_(val);
        if (p != NULL)
            return p;
        p = find_ancestor_above_(val);
        return p;
    }
    Node* predecessor_(const int val)
    {
        Node* p = search_(val);
        if (p != NULL && p->left != NULL)
        {
            p = p->left;
            while (p->right != NULL)
            {
                p = p->right;
            }
            return p;
        }
        p = find_ancestor_below_(val);
        return p;
    }
    Node* successor_(const int val)
    {
        Node* p = search_(val);
        if (p != NULL && p->right != NULL)
        {
            p = p->right;
            while (p->left != NULL)
            {
                p = p->left;
            }
            return p;
        }
        p = find_ancestor_above_(val);
        return p;
    }
////
    Node* left_rotation_(Node* x)
    {
        Node* y = x->right;
        Node* T2 = y->left;
        y->left = x;
        x->right = T2;
        x->height = 1 + max_unsigned_val_(height_(x->left), height_(x->right));
        y->height = 1 + max_unsigned_val_(height_(y->left), height_(y->right));
        return y;
    }
    Node* right_rotation_(Node* y)
    {
        Node* x = y->left;
        Node* T2 = x->right;
        x->right = y;
        y->left = T2;
        y->height = 1 + max_unsigned_val_(height_(y->left), height_(y->right));
        x->height = 1 + max_unsigned_val_(height_(x->left), height_(x->right));
        return x;
    }
    Node* insert_(Node* init, const int val)
    {
        if (init == NULL)
            return new Node(val);
        if (init->value == val)
            return init;
        else if (val < init->value)
            init->left = insert_(init->left, val);
        else
            init->right = insert_(init->right, val);
        init->height = 1 + max_unsigned_val_(height_(init->left), height_(init->right));
        int Bf = balance_factor_(init);
        if (1 < Bf && val < init->left->value) // 'LL' Rotation Case
        {
            init = right_rotation_(init);
        }
        else if (1 < Bf && init->left->value < val) // 'LR' Rotation Case
        {
            init->left = left_rotation_(init->left);
            init = right_rotation_(init);
        }
        else if (Bf < -1 && init->right->value < val) // 'RR' Rotation Case
        {
            init = left_rotation_(init);
        }
        else if (Bf < -1 && val < init->right->value) // 'RL' Rotation Case
        {
            init->right = right_rotation_(init->right);
            init = left_rotation_(init);
        }
        return init;
    }
    Node* delete_(Node* init, const int val)
    {
        if (init == NULL)
            return init;
        if (val < init->value)
            init->left = delete_(init->left, val);
        else if (val > init->value)
            init->right = delete_(init->right, val);
        else
        {
            Node* t;
            if (init->left == NULL || init->right == NULL)
            {
                if (init->left != NULL)
                    t = init->left;
                else
                    t = init->right;
                if (t == NULL)
                {
                    t = init;
                    init = NULL;
                }
                else
                    *init = *t;
                delete t;
            }
            else
            {
                // Get predecessor
                t = init->left;
                while (t->right != NULL)
                {
                    t = t->right;
                }
                //
                init->value = t->value;
                init->left = delete_(init->left, t->value); // DELETING the predecessor node
            }
        }
        if (init == NULL)
            return init; // If the AVL TREE had initially only 1 node that was deleted now
        init->height = 1 + max_unsigned_val_(height_(init->left), height_(init->right));
        int Bf = balance_factor_(init);
        if (1 < Bf &&  0 <= balance_factor_(init->left)) // 'LL' Rotation Case
        {
            init = right_rotation_(init);
        }
        else if (1 < Bf && balance_factor_(init->left) < 0) // 'LR' Rotation Case
        {
            init->left = left_rotation_(init->left);
            init = right_rotation_(init);
        }
        else if (Bf < -1 && balance_factor_(init->right) <= 0) // 'RR' Rotation Case
        {
            init = left_rotation_(init);
        }
        else if (Bf < -1 && 0 < balance_factor_(init->right)) // 'RL' Rotation Case
        {
            init->right = right_rotation_(init->right);
            init = left_rotation_(init);
        }
        return init;
    }
//////
public:
    unsigned get_size() const
    {
        return this->size;
    }
    Node* get_root_node() const
    {
        return this->root;
    }
    void balanced_tree() 
    {
        cout << "Is Tree balanced: ";
        bool b = is_balanced_(this->root);
        if (b)
            cout << "YES!\n\n";
        else
            cout << "NO!\n\n";
    }
    int get_min_value()
    {
        Node* p = min_node_();
        if (p == NULL)
        {
            cout << "AVL Tree is empty!\n\n";
            return MIN_LIMIT;
        }   
        return p->value;
    }
    int get_max_value()
    {
        Node* p = max_node_();
        if (p == NULL)
        {
            cout << "AVL Tree is empty!\n\n";
            return MAX_LIMIT;
        }    
        return p->value;
    }
    void Print_tree_in_order()
    {
        if (this->root == NULL)
        {
            cout << "The AVL Tree is empty!\n\n";
            return;
        }
        cout << "AVL Tree - IN ORDER: value (height)\n\n";
        in_order_(this->root);
        cout << "\n\n";
    }
    void Print_tree_pre_order()
    {
        if (this->root == NULL)
        {
            cout << "The AVL Tree is empty!\n\n";
            return;
        }
        cout << "AVL Tree - PRE ORDER: value (height)\n\n";
        pre_order_(this->root);
        cout << "\n\n";
    }
    int get_predecessor(const int val)
    {
        Node* p = predecessor_(val);
        if (p != NULL)
            return p->value;
        return MIN_LIMIT;
    }
    int get_successor(const int val)
    {
        Node* p = successor_(val);
        if (p != NULL)
            return p->value;
        return MAX_LIMIT;
    }
    void delete_min_val()
    {
        if (this->root == NULL)
            return;
        int minimum = get_min_value();
        Delete(minimum);
    }
    void delete_max_val()
    {
        if (this->root == NULL)
            return;
        int maximum = get_max_value();
        Delete(maximum);
    }
////// Questions 1-6:
    void Insert(const int val)
    {
        Node* p = search_(val);
        if (p != NULL)
            return;
        this->root = insert_(this->root, val);
        this->size++;
    }
    void Delete(const int val)
    {
        Node* p = search_(val);
        if (p == NULL)
            return;
        this->root = delete_(this->root, val);
        if (this->size > 0)
            this->size--;
    }
    bool value_found(const int val)
    {
        Node* p = search_(val);
        if (p == NULL)
            return false;
        return true;
    }
    int get_closest_below(const int val)
    {
        Node* p = closest_below_(val);
        if (p != NULL)
            return p->value;
        return MIN_LIMIT;
    }
    int get_closest_above(const int val)
    {
        Node* p = closest_above_(val);
        if (p != NULL)
            return p->value;
        return MAX_LIMIT;
    }
    void Print_sorted_sequence(const int x, const int y)
    {
        if (this->root == NULL)
            return;
        sorted_sequence_(this->root, x, y);
        g << "\n";
    }
};
int main()
{
    AVL_Tree t;
    int Q;
    f >> Q;
    for (int i = 0; i < Q; i++)
    {
        unsigned short question;
        int x;
        f >> question >> x;

        switch (question)
        {
        case 1:
            t.Insert(x);

            /*
            ////
            cout << "\n\nRoot value: " << t.get_root_node()->value << "\tSize: " << t.get_size() << "\n\n";
            t.balanced_tree();
            cout << "Min: " << t.get_min_value() << "\n\n";
            cout << "Max: " << t.get_max_value() << "\n\n";
            t.Print_tree_in_order();
            t.Print_tree_pre_order();
            ////
            */

            break;
        case 2:
            t.Delete(x);
            break;
        case 3:
            g << t.value_found(x) << "\n";
            break;
        case 4:
            g << t.get_closest_below(x) << "\n";
            break;
        case 5:
            g << t.get_closest_above(x) << "\n";
            break;
        case 6:
            int y;
            f >> y;
            t.Print_sorted_sequence(x, y);
            break;
        default:
            break;
        }
    }
    f.close();
    g.close();

    /*
    ////
    cout << "\n\nRoot value: " << t.get_root_node()->value << "\tSize: " << t.get_size() << "\n\n";
    t.balanced_tree();
    cout << "Min: " << t.get_min_value() << "\n\n";
    cout << "Max: " << t.get_max_value() << "\n\n";
    t.Print_tree_in_order();
    t.Print_tree_pre_order();
    ///
    cout << "------MIN value - operations:------\n\n";
    cout << "Pred: " << t.get_predecessor(t.get_min_value()) << "\n\n";
    cout << "Succ: " << t.get_successor(t.get_min_value()) << "\n\n";
    cout << endl;
    cout << "Closest_below: " << t.get_closest_below(t.get_min_value()) << "\n\n";
    cout << "Closest_above: " << t.get_closest_above(t.get_min_value()) << "\n\n";
    cout << endl << endl;
    ///
    cout << "------MAX value - operations:------\n\n";
    cout << "Pred: " << t.get_predecessor(t.get_max_value()) << "\n\n";
    cout << "Succ: " << t.get_successor(t.get_max_value()) << "\n\n";
    cout << endl;
    cout << "Closest_below: " << t.get_closest_below(t.get_max_value()) << "\n\n";
    cout << "Closest_above: " << t.get_closest_above(t.get_max_value()) << "\n\n";
    cout << endl << endl;
    ///
    cout << "------'6' value - operations:------\n\n";
    cout << "Pred: " << t.get_predecessor(6) << "\n\n";
    cout << "Succ: " << t.get_successor(6) << "\n\n";
    cout << endl;
    cout << "Closest_below: " << t.get_closest_below(6) << "\n\n";
    cout << "Closest_above: " << t.get_closest_above(6) << "\n\n";
    cout << endl << endl;
    ///
    cout << "------'8' value - operations:------\n\n";
    cout << "Pred: " << t.get_predecessor(8) << "\n\n";
    cout << "Succ: " << t.get_successor(8) << "\n\n";
    cout << endl;
    cout << "Closest_below: " << t.get_closest_below(8) << "\n\n";
    cout << "Closest_above: " << t.get_closest_above(8) << "\n\n";
    cout << endl << endl;
    ///
    cout << "------ROOT value - operations:------\n\n";
    cout << "Pred: " << t.get_predecessor(t.get_root_node()->value) << "\n\n";
    cout << "Succ: " << t.get_successor(t.get_root_node()->value) << "\n\n";
    cout << endl;
    cout << "Closest_below: " << t.get_closest_below(t.get_root_node()->value) << "\n\n";
    cout << "Closest_above: " << t.get_closest_above(t.get_root_node()->value) << "\n\n";
    cout << endl << endl;
    ///
    cout << "------'-1' value - operations:------\n\n";
    cout << "Pred: " << t.get_predecessor(-1) << "\n\n";
    cout << "Succ: " << t.get_successor(-1) << "\n\n";
    cout << endl;
    cout << "Closest_below: " << t.get_closest_below(-1) << "\n\n";
    cout << "Closest_above: " << t.get_closest_above(-1) << "\n\n";
    cout << endl << endl;
    ///
    cout << "------'12' value - operations:------\n\n";
    cout << "Pred: " << t.get_predecessor(12) << "\n\n";
    cout << "Succ: " << t.get_successor(12) << "\n\n";
    cout << endl;
    cout << "Closest_below: " << t.get_closest_below(12) << "\n\n";
    cout << "Closest_above: " << t.get_closest_above(12) << "\n\n";
    cout << endl << endl;
    ////
    */

    // cout << t.get_size() << endl;
    // t.Print_tree_in_order();
    // t.Print_tree_pre_order();
    return 0;
}
