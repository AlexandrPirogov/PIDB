class Node
{
   public:
       Node ();
       Node (char* value);
       ~Node();
       void setValue(char* value);
       char* getValue();
   protected:
   private:
       Node* left = nullptr;
       Node* right = nullptr;
       Node* parent = nullptr;
       char* value;
};
