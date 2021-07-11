#include <iostream>
#include <cstring>

using namespace std;

class fruit{
    protected:
        string abs_type="fruit";
        string type;
        float weight;
    public:
        float get_weight(){return this ->weight;}
        string get_type(){return type;}
        fruit():fruit(0){}//function delegation
        fruit(float w){
            weight=w;
            type="fruit";
        }
        fruit& operator+=(float amount){weight+=amount;return *this;}
        bool operator==(fruit f){if(this->get_type()==f.get_type()&&this->get_weight()==f.get_weight())return true; else return false;}
        virtual void print_information(){cout<<"Type is: \"fruit\" and Wight is: "<<weight<<"\n";}
};

class oval_shaped: public fruit{
    private:
    public:
        oval_shaped():oval_shaped(0){}//delegation
        oval_shaped(float w) {
            fruit::type=(fruit::type+","+"oval_shaped");
            fruit::weight=w;
        }
        void print_information(){cout<<"Type is: \"oval shaped\" and Wight is: "<<weight<<"\n";}
};

class avocado: public oval_shaped{
    private:
    public:
        avocado():avocado(0){}
        avocado(float w) {
            fruit::type=(fruit::type+","+"avocado");
            fruit::weight=w;
        }
        void print_information(){cout<<"Type is: \"avocado\" and Wight is: "<<weight<<"\n";}
};

class apple: public oval_shaped{
    private:
    public:
        apple():apple(0){}
        apple(float w) {
            fruit::type=(oval_shaped::get_type()+","+"apple");
            fruit::weight=w;
        }
        void print_information(){cout<<"Type is: \"apple\" and Wight is: "<<weight<<"\n";}
};

class large_fruit: public fruit{
    private:
    public:
        large_fruit():large_fruit(0){}
        large_fruit(float w) {
            fruit::type=(fruit::type+","+"large_fruit");
            fruit::weight=w;
        }
        void print_information(){cout<<"Type is: \"large fruit\" and Wight is: "<<weight<<"\n";}
};

class watermelon: public large_fruit{
    private:
    public:
        watermelon():watermelon(0){}
        watermelon(float w) {
            fruit::type=(fruit::type+","+"watermelon");
            fruit::weight=w;
        }
        void print_information(){cout<<"Type is: \"watermelon\" and Wight is: "<<weight<<"\n";}
};

class berry: virtual public fruit{
    private:
    public:
        berry():berry(0){}
        berry(float w) {
            fruit::type=(fruit::type+","+"berry");
            fruit::weight=w;
        }
        void print_information(){cout<<"Type is: \"berry\" and Wight is: "<<weight<<"\n";}
};

class tiny_fruit: virtual public fruit{
    private:
    public:
        tiny_fruit():tiny_fruit(0){}
        tiny_fruit(float w) {
            fruit::type=(fruit::type+","+"tiny_fruit");
            fruit::weight=w;
        }
        void print_information(){cout<<"Type is: \"tiny fruit\" and Wight is: "<<weight<<"\n";}
};

class black_berry: virtual public berry, virtual public tiny_fruit{
    private:
    public:
        black_berry():black_berry(0){}
        black_berry(float w) {
            fruit::type=(fruit::get_type()+","+"black_berry");
            fruit::weight=w;
        }
        void print_information(){cout<<"Type is: \"black berry\" and Wight is: "<<weight<<"\n";}
};

class grape: public tiny_fruit{
    private:
        string abs_type="grape";
    public:
        grape():grape(0){}
        grape(float w) {
            fruit::type=(tiny_fruit::get_type()+","+"grape");
            fruit::weight=w;
        }
        void print_information(){cout<<"Type is: \"grape\" and Wight is: "<<weight<<"\n";}
};

class guava: public fruit{
    private:
    public:
        guava():guava(0){}
        guava(float w) {
            fruit::type=(fruit::type+","+"guava");
            fruit::weight=w;
        }
        void print_information(){cout<<"Type is: \"guava\" and Wight is: "<<weight<<"\n";}
};

class banana: public fruit{
    private:
    public:
        banana():banana(0){}
        banana(float w) {
            fruit::type=(fruit::type+","+"banana");
            fruit::weight=w;
        }
        void print_information(){cout<<"Type is: \"banana\" and Wight is: "<<weight<<"\n";}
};

class BST
{
private:
    fruit fru;
    BST *left, *right, *root= NULL, *temp_root= NULL;
    BST* Insert(BST* root, fruit* value){
        if (!root){
            return new BST(value);
        }
        if (value->get_weight() > root->fru.get_weight()){
            // Insert in the right
            root->right = Insert(root->right, value);
        }
        else if(value->get_weight() < root->fru.get_weight()){
            // Insert in the left
            root->left = Insert(root->left, value);
        }
        else{
            //update the fruit
            root->fru=*value;
        }
        // Return 'root' node, after insertion.
        return root;
    }
    // Iterate traversal.
    void Iterate(BST* root){
        if (!root) {
            return;
        }
        Iterate(root->left);
        cout << "Type: "<<root->fru.get_type() <<" ,Weight: "<<root->fru.get_weight() << endl;
        Iterate(root->right);
    }
    bool match(char *first, char * second){
        if (*first == '\0' && *second == '\0'){
            return true;
        }
        else if (*first == '*' && *(first+1) != '\0' && *second == '\0'){
            return false;
        }
        else if (*first == '?' || *first == *second){
            return match(first+1, second+1);
        }
        else if (*first == '*'){
            return match(first+1, second) || match(first, second+1);
        }
        else{
            return false;
        }
    }
    void filterByType(string Type, BST* root){
        if (!root) {
            return;
        }
        filterByType(Type,root->left);
        string c1(""),c2("");
        c1+="*";
        c1+=Type;
        c1+="*";
        char a[c1.length()+1];
        strcpy(a, c1.c_str());
        c2+=root->fru.get_type();
        char b[c2.length()+1];
        strcpy(b, c2.c_str());
        if(match(a,b)==true)cout << "Type: "<<root->fru.get_type() <<" ,Weight: "<<root->fru.get_weight() << endl;
        //if(root->fru.get_type().find(Type)!=string::npos)cout << "Type: "<<root->fru.get_type() <<" ,Weight: "<<root->fru.get_weight() << endl;
        filterByType(Type,root->right);
    }
    void filterByWeight(float Weight, BST* root){
        if (!root) {
            return;
        }
        filterByWeight(Weight,root->left);
        if(root->fru.get_weight()==Weight)cout << "Type: "<<root->fru.get_type() <<" ,Weight: "<<root->fru.get_weight() << endl;
        filterByWeight(Weight,root->right);
    }
    void magnifyByTypeIterate(string Type, float Weight, BST* root){
        if (!root) {
            return;
        }
        magnifyByTypeIterate(Type,Weight,root->left);
        if(root->fru.get_type().find(Type)!=string::npos)root->fru+=Weight;
        magnifyByTypeIterate(Type,Weight,root->right);
    }
    // findHeaviest.
    fruit* findHeaviest(BST* root){
        if (!root) {
            return NULL;
        }
        if(root->right!=NULL){
            return findHeaviest(root->right);
        }
        else return &root->fru;
    }
    // findLightest.
    fruit* findLightest(BST* root){
        if (!root) {
            return NULL;
        }
        if(root->left!=NULL){
            return findLightest(root->left);
        }
        else return &root->fru;
    }
    // the size of the BST.
    int size(BST* root){
        if (!root) {
            return 0;
        }
        return size(root->left) + 1 + size(root->right);
    }
public:
    BST (): fru(0), left(NULL), right(NULL){}
    BST(fruit* value):BST(){
        fru = *value;
        left = right = NULL;
    }
    // Insert function.
    void Insert(fruit* value){
        root=Insert(root,value);
    }
    // Iterate traversal.
    void Iterate(){
        if (!root) {
            return;
        }
        Iterate(root->left);
        cout << "Type: "<<root->fru.get_type() <<" ,Weight: "<<root->fru.get_weight() << endl;
        Iterate(root->right);
        cout<<"\n"<<endl;
    }
    void filterByType(string Type){
        filterByType(Type,root);
        cout<<"\n"<<endl;
    }
    void filterByWeight(float Weight){
        filterByWeight(Weight,root);
        cout<<"\n"<<endl;
    }
    void magnifyByTypeIterate(string Type, float Weight){
        if (!root) {
            return;
        }
        magnifyByTypeIterate(Type,Weight,root->left);
        if(root->fru.get_type().find(Type)!=string::npos)root->fru+=Weight;
        magnifyByTypeIterate(Type,Weight,root->right);
    }
    // findHeaviest.
    fruit* findHeaviest(){
        if (!root) {
            return NULL;
        }
        if(root->right!=NULL){
            return findHeaviest(root->right);
        }
        else return &root->fru;
    }
    // findLightest.
    fruit* findLightest(){
        if (!root) {
            return NULL;
        }
        if(root->left!=NULL){
            return findLightest(root->left);
        }
        else return &root->fru;
    }
    // the size of the BST.
    int size(){
        if (!root) {
            return 0;
        }
        return size(root->left) + 1 + size(root->right);
    }

};

int main()
{
    fruit f(10);
    cout << f.get_weight()<< endl;
    cout << f.get_type() << endl;
    f.print_information();
    oval_shaped o(10);
    cout << o.get_weight() << endl;
    cout << o.get_type() << endl;
    o.print_information();
    oval_shaped m(20);
    cout << m.get_weight() << endl;
    cout << m.get_type() << endl;
    m.print_information();
    large_fruit l(50);
    cout << l.get_weight() << endl;
    cout << l.get_type() << endl;
    l.print_information();
    tiny_fruit t(5);
    cout << t.get_weight() << endl;
    cout << t.get_type() << endl;
    t.print_information();
    watermelon w(1000);
    cout << w.get_weight() << endl;
    cout << w.get_type() << endl;
    w.print_information();
    avocado v(100);
    cout << v.get_weight() << endl;
    cout << v.get_type() << endl;
    v.print_information();
    apple a(80);
    cout << a.get_weight() << endl;
    cout << a.get_type() << endl;
    a.print_information();
    grape g(8);
    cout << g.get_weight() << endl;
    cout << g.get_type() << endl;
    g.print_information();
    black_berry k(18);
    k+=10;
    cout << k.get_weight() << endl;
    cout << k.get_type() << endl;
    k.print_information();
    black_berry k1(180);
    k1+=10;
    cout << k1.get_weight() << endl;
    cout << k1.get_type() << endl;
    k1.print_information();

    BST b=BST();
    b.Insert(&k);
    b.Insert(&k);
    b.Insert(&f);
    b.Insert(&f);
    b.Insert(&a);
    b.Insert(&a);
    b.Insert(&a);
    b.Insert(&w);
    b.Insert(&w);
    b.Insert(&w);
    b.Insert(&w);
    b.Insert(&g);
    b.Insert(&g);
    b.Insert(&t);
    b.Insert(&t);
    b.Insert(&m);
    b.Insert(&l);
    b.Insert(&m);
    b.Insert(&t);
    b.Insert(&l);
    b.Insert(&l);
    b.Insert(&o);
    b.Insert(&k1);
    b.Iterate();
    cout << b.size() << endl;
    fruit heavy=*(b.findHeaviest());
    cout << heavy.get_type()<< heavy.get_weight()<< endl;
    heavy=*(b.findLightest());
    cout << heavy.get_type()<< heavy.get_weight()<< endl;
    b.magnifyByTypeIterate("fruit",20);
    b.Iterate();
    cout << b.size() << endl;
    b.filterByType("black_berry");
    b.filterByWeight(100);

    return 0;
}

