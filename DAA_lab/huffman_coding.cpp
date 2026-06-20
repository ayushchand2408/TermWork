//data structure req. to make huffman coding
//1. map
//2. min heap -> priority queue
//3. Binary tree -> Struct node {
//                     char ch ;
//                     int freq ;
//                     struct node * left;
//                     struct node * right;
//                  };
#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

 struct Node{
    char ch;
    int freq;
    Node * left , *right;
};

Node* getNode(char ch , int freq , Node * left , Node * right){
    Node * node = new Node();
    node -> ch = ch;
    node -> freq = freq;
    node -> left = left;
    node -> right = right;
    return node;
}
 struct MinHeap{
    Node * heap[1000];
    int size;
    MinHeap(){ size = 0;}

    void heapify(int i){
        int smallest = i ;
        int left = 2*i;
        int right = 2*i+1;

        if(left <= size && heap[left]->freq < heap[smallest]->freq){
            smallest = left;
        }
        if(right <= size && heap[right] -> freq < heap[smallest] -> freq){
            smallest = right;
        }
        if(smallest != i){
            swap(heap[i],heap[smallest]);
            heapify(smallest);
        }
    }
    void insert(Node * node){
        size++;
        int i = size;
        heap[i] = node;
        while(i > 1 && heap[i]->freq < heap[i/2]->freq){
            swap(heap[i],heap[i/2]);
            i = i /2;
        }
    }
    Node * extractMin(){
        Node * minNode = heap[1];
        heap[1] = heap[size];
        size--;
        heapify(1);
        return minNode;
    }
};
void encode(Node * root, string str,unordered_map < char , string>& huffmanCode){
    if(!root)return;
    if(!root -> left && !root->right){
        huffmanCode[root->ch]=str;
    }
    encode(root->left , str+"0" , huffmanCode);
    encode(root->right , str+ "1",huffmanCode);
}
void decode(Node * root , int & index , string str){
    if(!root) return;
    if(!root -> left && !root->right){
        cout << root -> ch;
        return;    
    }
    index++;
    if(str[index] == '0'){
        decode(root->left , index , str);
    }else{
        decode(root->right , index , str);
    }
}

void huffman_code(string text){
    unordered_map<char,int> freq;
    for(char ch : text) freq[ch]++;
    MinHeap minHeap;
    for(auto pair : freq){
        minHeap.insert(getNode(pair.first,pair.second,nullptr,nullptr));
    }
    while(minHeap.size>1){
        Node * left = minHeap.extractMin();
        Node * right = minHeap.extractMin();
        Node * sumNode = getNode('\0',left->freq+right->freq,left,right);
        minHeap.insert(sumNode);
    }
    Node * root = minHeap.extractMin();
    unordered_map<char,string>huffmanCode;
    encode(root,"" ,huffmanCode);
    cout << " Huffman Codes:\n";
    for(auto pair : huffmanCode){ 
        cout << pair.first << " : " << pair.second<<'\n';
    }
    string encodedString="";
    for(char ch : text) encodedString +=huffmanCode[ch];
    int index = -1; 
    cout<<"\nDecoded String: ";
    while(index < (int)encodedString.size()-2){
        decode(root,index,encodedString);
    }
    cout << "\n";
}

int main(){
    string str;
    cin >> str;
    huffman_code(str);
}

